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
import create_task
import embed_task
import process_task

def start(dir_metrics, dir_raw, str_proj, str_train_rel, str_test_rel, str_train_tech):
    print("\n-------------- checking if result metrics already exists --------------")
    arr_metrics_paths = [dir_metrics + config.fileMetrics.replace("lstm", "lstm_forwards")
                         , dir_metrics + config.fileMetrics.replace("lstm", "lstm_rf")]
    for metrics_path in arr_metrics_paths:
        shouldProcess = True
        if path.exists(metrics_path):
            shouldProcess = False
            if config.shouldOverwrite:
                shouldProcess = True
                print("\n-------------- ", metrics_path, " already exists but re-processing and will overwrite for", str_train_rel, " --------------")
            
        if shouldProcess is False:
            print("\n-------------- ", metrics_path, " already exists, skipping processing for", str_train_rel, " --------------")
        else:
            print("\n--------------create task started--------------")
            X, y, num_LSTM_units = create_task.create_task(dir_raw, str_proj, str_train_rel, str_test_rel)
            print("\n--------------create task finished--------------")

            print("\n--------------embed task started--------------")
            XTrain, yTrain, numTrainItems, XTest, yTest, num_LSTM_units, vocab_size = embed_task.embed_task(X, y, num_LSTM_units)
            print("\n--------------embed task finished--------------")

            print("\n--------------process task started--------------")
            bool_RF = False
            if "lstm_rf" in metrics_path:
                bool_RF = True
            process_task.process_task(numTrainItems, XTrain, yTrain, XTest, yTest, dir_metrics, num_LSTM_units, vocab_size,
                        str_proj, str_train_rel, str_train_tech, bool_RF)
            print("\n--------------process task finished--------------")
                    