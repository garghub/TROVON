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

def preprocess(str_proj, str_train_rel, str_train_tech):
    bool_preprocessing_successful = False
    dir_raw = None
    dir_metrics = None
    str_test_rel = None
    if str_proj == config.linux:
        map_rel = config.map_rel_linux
    elif str_proj == config.openssl:
        map_rel = config.map_rel_openssl
    elif str_proj == config.wireshark:
        map_rel = config.map_rel_wireshark
    else:
        map_rel = None

    if map_rel is None:
        print("\nproject options: "+config.linux+" / "+config.openssl+" / "+config.wireshark+"")
        print("\nplease try again")
    else:
        if str_train_rel not in map_rel:
            str_train_rel = None
            print("\nplease enter a valid release name and try again")
        else:
            str_test_rel = map_rel[str_train_rel]
            print("\n--------------Testing release: " + str_test_rel + "--------------")
    
            if str_train_tech not in config.arr_train_tech:
                str_train_tech = None
                print("\ntraining technique options: clean / noisy")
                print("\nplease try again")
            else:
                dir_raw = config.dir_main + str_proj + "_" + str_train_rel + "_" + str_train_tech + config.raw
                print("Raw directory: " + dir_raw)
                dir_metrics = config.dir_main + str_proj + "_" + str_train_rel + "_" + str_train_tech + config.strMetrics
                print("Metrics directory: " + dir_metrics)
                bool_preprocessing_successful = True
    return bool_preprocessing_successful, dir_raw, dir_metrics, str_test_rel
    