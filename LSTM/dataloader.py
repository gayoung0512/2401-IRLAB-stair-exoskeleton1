import numpy as np
import torch
class dataloader(object):
    def __init__(self, xdata, ydata):
        self.xdata = xdata
        self.ydata = ydata

    def __getitem__(self, index):
        input = self.xdata[index, :, :]
        output = self.ydata[index]

        cur_sample = {'input': input, 'output': output}

        return cur_sample

    def __len__(self):
        return self.xdata.shape[0]
