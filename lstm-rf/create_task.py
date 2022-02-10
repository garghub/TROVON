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
import util

def select(dataset, str_proj, str_train_rel, str_test_rel):
    print("\n--------------len(dataset): ", len(dataset) ," --------------")
    result_init = dataset.loc[dataset['project'] == str_proj]
    result_train = result_init[result_init['commit_id'].str.contains(str_train_rel)]
    result_test = result_init[result_init['commit_id'].str.contains(str_test_rel)]
    result_train_head = result_train
    result = result_train_head
    result_test_head = result_test
    result = result.append(result_test_head, ignore_index=True)
    return result

def create_task(dir_raw, str_proj, str_train_rel, str_test_rel):
    raw = pd.read_json(dir_raw + config.fileRaw)
    filtered = select(raw, str_proj, str_train_rel, str_test_rel)
    for key in ["commit_id", "project"]:
        del filtered[key]
    X = filtered["func"]
    y = filtered["target"]
    max_length, X = util.get_upd_X(X)
    print("\n--------------printing first few items: ", X.head(), "--------------")
    num_LSTM_units = max_length
    return X, y, num_LSTM_units