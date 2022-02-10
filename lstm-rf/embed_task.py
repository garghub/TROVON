from random import random
from numpy import array
from numpy import cumsum
from matplotlib import pyplot
from pandas import DataFrame
from pandas import Series
import tensorflow
from tensorflow import keras
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import LSTM, Bidirectional, Dense, TimeDistributed
from tensorflow.keras.optimizers import RMSprop
from sklearn import preprocessing
from tensorflow.keras.preprocessing.text import one_hot
from tensorflow.keras.preprocessing.sequence import pad_sequences
from sklearn import metrics
from sklearn.metrics import confusion_matrix
import numpy as np
import math
import os
from os import path
import pandas as pd
from tensorflow.keras.preprocessing.text import Tokenizer
from sklearn.model_selection import train_test_split
from tensorflow.keras.layers import Embedding
from tensorflow.keras.models import model_from_json
from tensorflow.keras import models
import tensorflow.keras.backend as K
from tensorflow.keras.models import Model
from sklearn.ensemble import RandomForestClassifier
import pickle
import itertools
import config

def get_tokenized_X(X, num_LSTM_units):
    print("\n--------------process tokenizing and padding started--------------")
    tokenizer = Tokenizer()
    tokenizer.fit_on_texts(X)
    vocab_size = len(tokenizer.word_index) + 1
    num_LSTM_units_upd = num_LSTM_units
    input_sequences = []
    for line in X:
        token_list = tokenizer.texts_to_sequences([line])[0]
        n_gram_sequence = array(token_list)
        n_gram_sequence = n_gram_sequence[:num_LSTM_units] if len(n_gram_sequence) > num_LSTM_units else n_gram_sequence
        num_LSTM_units_upd = len(n_gram_sequence) if len(n_gram_sequence) > num_LSTM_units_upd else num_LSTM_units_upd
        input_sequences.append(n_gram_sequence)
    input_sequences = np.array(pad_sequences(input_sequences, maxlen=num_LSTM_units_upd, padding='post'))
    print("\n--------------vocab_size : ", vocab_size, "--------------")
    print("\n--------------process tokenizing and padding finished--------------")
    print("\n--------------sequence length increased from ", num_LSTM_units, " to ", num_LSTM_units_upd, "--------------")
    return input_sequences, num_LSTM_units_upd, vocab_size

def embed_task(X, y, num_LSTM_units):
    X, num_LSTM_units, vocab_size = get_tokenized_X(X, num_LSTM_units)
    XTrain, XTest, yTrain, yTest = train_test_split(X, y, test_size=0.5, shuffle=False)
    numTrainItems = len(XTrain)
    return XTrain, yTrain, numTrainItems, XTest, yTest, num_LSTM_units, vocab_size