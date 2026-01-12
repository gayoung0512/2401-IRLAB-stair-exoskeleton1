import torch
import torch.nn as nn


class LSTM(nn.Module):
    def __init__(self, input_dim, hidden_dim, batch_size, output_dim, num_layers=1):
        super(LSTM, self).__init__()
        self.input_dim = input_dim
        self.hidden_dim = hidden_dim
        self.batch_size = batch_size
        self.num_layers = num_layers
        self.time_length = input_dim

        self.lstm = nn.LSTM(self.input_dim, self.hidden_dim, self.num_layers, batch_first = True)
        #self.lstm2 = nn.LSTM(self.hidden_dim, self.hidden_dim, self.num_layers, batch_first = True)
        self.linear = nn.Linear(self.hidden_dim, output_dim) #Fully Connected Layer 생성

    def forward(self, input):
        lstm_out, self.hidden = self.lstm(input)
        #lstm_out, self.hidden = self.lstm2(lstm_out)
        #lstm_out, self.hidden = self.lstm2(lstm_out)

        y_pred = self.linear(lstm_out[:, -1, :])

        return y_pred


