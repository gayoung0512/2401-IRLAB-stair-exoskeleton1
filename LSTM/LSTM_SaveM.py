#python main.py --data_path data_div_p1 --gpu 0
from __future__ import print_function

import os
import serial
import csv
import time
import pandas as pd
import numpy as np
import torch
import matplotlib.pyplot as plt

from torch.utils.data import DataLoader
from model import LSTM
from dataloader import dataloader


def main():
    batch_size = 16 #수정해볼 것!!!
    epochs = 1000
    seq_length = 30
    hidden_len = 128
    files = os.listdir('./Data')
    print ("file_list: {}".format(files))
    x_train = []
    y_train = []

    for cur_file in files:
        if 'csv' not in cur_file:
            continue

        data_tr = np.loadtxt(cur_file, delimiter = ',', dtype=np.float32)

        xtr = data_tr[:,0:60]
        ytr_data = data_tr[:,60]
        ytr = np.zeros((data_tr.shape[0],1))
        for i in range(data_tr.shape[0]):
            ytr[i,0] = ytr_data[i]
        # print(xtr.shape)
        # print(xtr)
        # print(ytr)
        # exit(1)
        
        seq = 0

        while True:
            if seq + seq_length > xtr.shape[0]:
                break

            x_train.append(xtr[seq:seq+seq_length,:]) #전체 데이터를 seq_length 길이만큼 쪼개서 저장
            y_train.append(ytr[seq:seq+seq_length])
            seq += seq_length



    x_train = np.array(x_train)
    y_train = np.array(y_train)
    # print(x_train)
    # print(y_train)
    # exit(1)


    train_loader = DataLoader(dataloader(x_train, y_train), batch_size = batch_size, shuffle = True, num_workers = 0)

    model = LSTM(x_train.shape[-1], hidden_len, batch_size, 5, num_layers = 1)
    model = model.cuda()
    model = torch.nn.DataParallel(model, device_ids=(0,)).cuda()
    
    msec = torch.nn.MSELoss()
    criterion = torch.nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(model.parameters(), lr=0.0001)

    y = []
    y_real = []
    y_pred = []
    for epoch in range(0, epochs):

        total_loss_tr = 0
        total_rmse_tr = 0
        model.train()
        
        for i_batch, (sample_batched) in enumerate(train_loader): #enumerate : 받아온 데이터를 순서대로 접근

            # print(sample_batched['input'])
            y_pred_tr = model(sample_batched['input'].float().cuda())              
            y_data_tr = sample_batched['output'][:,-1,0].long().cuda()
            # print(y_pred_tr)
            # exit(1)
            # y_data_tr = y_data_tr[:,-1,0]

            # loss_tr = msec(y_pred_tr.squeeze(), y_data_tr)
            # rmse_tr = torch.sqrt(loss_tr)
            # total_rmse_tr += rmse_tr.item()
            loss_tr = criterion(y_pred_tr, y_data_tr)
            # print(loss_tr)
            optimizer.zero_grad()
            loss_tr.backward()
            optimizer.step()
            total_loss_tr += loss_tr.item()
            # print(i_batch)
            # exit(1)

        print('[Epoch %d] Train loss: %.6f' %( epoch + 1 , total_loss_tr/i_batch))
        # exit(1)
    torch.save(model.state_dict(), 'KISA_model_weights.pth')


if __name__ == '__main__':
    main()
