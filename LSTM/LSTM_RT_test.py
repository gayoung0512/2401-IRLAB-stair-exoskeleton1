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



    model = LSTM(x_train.shape[-1], hidden_len, batch_size, 5, num_layers = 1) #x_train 수정할 것
    model = model.cuda()
    model = torch.nn.DataParallel(model, device_ids=(0,)).cuda()
    
    msec = torch.nn.MSELoss()
    criterion = torch.nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(model.parameters(), lr=0.0001)

    weights = torch.load('model_wights.pth')
    model.load_state_dict(weights)


    model.eval()
    with torch.no_grad():
            
            #여기서 y_pred_val 코드를 선언한 배열로 잘 바꿔야 됨.
            y_pred_val = model(sample_batched['input'].float().cuda())              

            softmax = torch.nn.Softmax(dim = 1)
            probabilities = softmax(y_pred_val) #여기도 당연히 y_pred_val 대신 위에서 선언한 변수 대
            _, predictions = torch.max(probabilities, dim=1)

            # print(predictions)
            # print(y_data_val)
            # exit(1)





if __name__ == '__main__':
    main()
