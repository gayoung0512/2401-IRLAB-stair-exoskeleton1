#python main.py --data_path data_div_p1 --gpu 0
#from __future__ import print_function

import os
import csv
import time
import pandas as pd
import numpy as np
import torch
import matplotlib.pyplot as plt

from torch.utils.data import DataLoader #dataset을 batch 기반의 deeplearning model 학습을 위해 mini-batch 형태로 만들어 input shape 만들어줌
from dataloader import dataloader #dataloader 통해 dataset의 전체 데이터가 batch_size로 slice되어 공급
from model import LSTM


def main():
    batch_size = 16 #more than five
    epochs = 1000
    seq_length = 20 #time step: 20 fps for 1 seconds
    hidden_len = 128 #64, 128, 256...etc

    #경로 설정
    files = os.listdir('./Data') #data 경로
    #print ("file_list: {}".format(files))

    #train dataset과 validation dataset을 저장하기 위한 array
    x_train = []
    y_train = []
    x_val = []
    y_val = []

    for cur_file in files: #csv 파일 읽어와 data 처리
        if 'csv' not in cur_file:
            continue
        if 'Train' in cur_file: #Train이 포함되어 있다면 해당 CSV 파일 추출
            data_tr = np.loadtxt(cur_file, delimiter = ',', dtype=np.float32)

            xtr = data_tr[:,0:seq_length]#0번째부터 seq_length번째 열까지의 data 가져와 2D NumPy 배열로 저장 -> feature
            ytr_data = data_tr[:,seq_length]#0번째부터 seq_length번째 열까지의 data 가져와 1D NumPy 배열로 저장
            #[data tranpose]
            ytr = np.zeros((data_tr.shape[0],1))
            for i in range(data_tr.shape[0]):
                ytr[i,0] = ytr_data[i]

            print('x_train의 shape: ', xtr.shape) #(column, time_step)
            print('y_train의 shape: ', ytr.shape) #(column)
            
            seq = 0
            while True:
                if seq + seq_length > xtr.shape[0]:
                    break

                x_train.append(xtr[seq:seq+seq_length,:]) #전체 데이터를 seq_length 길이만큼 쪼개서 저장
                y_train.append(ytr[seq:seq+seq_length])
                seq += seq_length

        else: #valid dataset pre-processing / 위 코드와 유사
            data_val = np.loadtxt(cur_file, delimiter = ',', dtype=np.float32)
            # data = data[1:,:].astype(np.float) #라벨 빼고 전체 저장

            xval = data_val[:,0:seq_length]
            yval_data = data_val[:,seq_length]
            yval = np.zeros((data_val.shape[0],1))
            for i in range(data_val.shape[0]):
                yval[i,0] = yval_data[i]
            print('x_valid의 shape: ', xval.shape) #(column, time_step)
            print('y_valid의 shape: ', yval.shape) #(column)

            seq = 0

            while True:
                if seq + seq_length > xval.shape[0]:
                    break

                x_val.append(xval[seq:seq+seq_length,:]) #전체 데이터를 seq_length 길이만큼 쪼개서 저장
                y_val.append(yval[seq:seq+seq_length])
                seq += seq_length


    x_train = np.array(x_train)
    y_train = np.array(y_train)
    x_val = np.array(x_val)
    y_val = np.array(y_val)
    print('train_dataset (X):', x_train.shape) #(data 개수, time_step, feature)
    print('train_dataset (Y):', y_train.shape) #(data 개수, time_step, feature)
    print('valid_dataset (X):', x_val.shape) #(data 개수, time_step, feature)
    print('valid_dataset (Y):', y_val.shape) #(data 개수, time_step, feature)


    train_loader = DataLoader(dataloader(x_train, y_train), batch_size = batch_size, shuffle = True, num_workers = 0)
    val_loader = DataLoader(dataloader(x_val, y_val), batch_size = 1, shuffle = False, num_workers = 0)
    model = LSTM(x_train.shape[-1], hidden_len, batch_size, 7, num_layers = 1)
    model = model.cuda()
    model = torch.nn.DataParallel(model, device_ids=(0,)).cuda() #여러 gpu device에 복사하고 입력 배치에 gpu별 쪼개 각 gpu별로 forward/backward 연산 수행
    
    msec = torch.nn.MSELoss()
    criterion = torch.nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(model.parameters(), lr=0.001)

    y = []
    y_true = []
    y_pred = []
    for epoch in range(0, epochs):

        total_loss_tr = 0
        #total_rmse_tr = 0
        model.train()
        
        for i_batch, (sample_batched) in enumerate(train_loader): #DataLoader로부터 mini-batch 순회하는 반복문/ i_batch: mini-batch index, sample_batched: 해당 mini-batch data

            #print(sample_batched['input'].shape) #torch.Size([batch_size, time_step, feature])
            y_pred_tr = model(sample_batched['input'].float().cuda()) #torch.Size([batch_size, output_dim])
            y_data_tr = sample_batched['output'][:,-1,0].long().cuda() #torch.Size([batch_size])
            # y_data_tr = y_data_tr[:,-1,0]
            '''
            #[RMSE]
            loss_tr = msec(y_pred_tr.squeeze(), y_data_tr)
            rmse_tr = torch.sqrt(loss_tr)
            total_rmse_tr += rmse_tr.item()'''

            loss_tr = criterion(y_pred_tr, y_data_tr)
            optimizer.zero_grad() #현재까지 누적된 경사를 0으로 초기화
            loss_tr.backward() #backpropagation 수행
            optimizer.step() #최적화 도구 사용해 모델 가중치 업데이트
            total_loss_tr += loss_tr.item()#전체 데이터셋에 대한 손실 추적
        print('[Epoch %d] Train loss: %.6f' %( epoch + 1 , total_loss_tr/i_batch))
        # exit(1)
        torch.save(model.state_dict(), 'model_weights.pth')
    model.eval()
    with torch.no_grad():
        loss = 0
        for i_batch, (sample_batched) in enumerate(val_loader):

            y_pred_val = model(sample_batched['input'].float().cuda())
            y_data_val = sample_batched['output'][:,-1,0].long().cuda()
            # exit(1)

            # loss_val = msec(y_pred_val.squeeze(0), y_data_val)  
            # rmse_val = torch.sqrt(loss_val)           
            # loss += loss_val

            loss_val = criterion(y_pred_val, y_data_val)
            loss += loss_val
            softmax = torch.nn.Softmax(dim = 1)
            probabilities = softmax(y_pred_val)
            _, predictions = torch.max(probabilities, dim=1)

            # print(predictions)
            # print(y_data_val)
            # exit(1)
            y.append(y_data_val.cpu().numpy())
            y.append(predictions.cpu().numpy())
            y_true.append(y_data_val.cpu().numpy())
            y_pred.append(predictions.cpu().numpy())

        print('[Epoch %d] Val loss: %.6f' % (epoch + 1, loss_val))

    y = np.array(y).reshape(-1,2)
    y_true = np.array(y_true).reshape(-1,1)
    y_pred = np.array(y_pred).reshape(-1,1)
    y = pd.DataFrame(y)
    y.to_csv('result.csv',index = False) #저장된 csv파일의 맷 윗 줄은 인덱스
    print('clear')

    from sklearn.metrics import mean_squared_error
    from sklearn.metrics import mean_absolute_error
    from sklearn.metrics import mean_absolute_percentage_error
    from sklearn.metrics import accuracy_score
    def MAPE(y, pred):
        return np.mean(abs(y-pred)/y * 100)
    mae = mean_absolute_error(y_true, y_pred)
    mse = mean_squared_error(y_true, y_pred, squared=True)
    rmse = mean_squared_error(y_true, y_pred, squared=False)
    mape = MAPE(y_true, y_pred)
    accuracy = accuracy_score(y_true, y_pred)

    print("mae: %f" %mae)
    print("mse: %f" %mse)
    print("rmse: %f" %rmse)
    print("mape: %f" %mape)
    print("Accuracy: {:.2f}%".format(accuracy * 100))


if __name__ == '__main__':
    main()
