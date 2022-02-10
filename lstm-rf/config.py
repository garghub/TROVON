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

linux = "linux_kernel"
openssl = "openssl"
wireshark = "wireshark"
arr_proj = [linux, openssl, wireshark]
arr_train_tech = ["clean", "noisy"]
map_rel_linux = {"v3_0" : "v3_1", "v3_1" : "v3_2", "v3_2" : "v3_3", "v3_3" : "v3_4", "v3_4" : "v3_5", "v3_5" : "v3_6", "v3_6" : "v3_7", "v3_7" : "v3_8", "v3_8" : "v3_9"
                , "v3_9" : "v3_10", "v3_10" : "v3_11", "v3_11" : "v3_12", "v3_12" : "v3_13", "v3_13" : "v3_14", "v3_14" : "v3_15", "v3_15" : "v3_16", "v3_16" : "v3_17"
                , "v3_17" : "v3_18", "v3_18" : "v3_19", "v3_19" : "v4_0", "v4_0" : "v4_1", "v4_1" : "v4_2", "v4_2" : "v4_3", "v4_3" : "v4_4", "v4_4" : "v4_5"
                , "v4_5" : "v4_6", "v4_6" : "v4_7", "v4_7" : "v4_8", "v4_8" : "v4_9", "v4_9" : "v4_10", "v4_10" : "v4_11", "v4_11" : "v4_12", "v4_12" : "v4_13"
                , "v4_13" : "v4_14"}
map_rel_openssl = {"OpenSSL_0_9_3" : "OpenSSL_0_9_4", "OpenSSL_0_9_4" : "OpenSSL_0_9_5", "OpenSSL_0_9_5" : "OpenSSL_0_9_6", "OpenSSL_0_9_6" : "OpenSSL_0_9_7"
                  , "OpenSSL_0_9_7" : "OpenSSL_0_9_8", "OpenSSL_0_9_8" : "OpenSSL_1_0_0", "OpenSSL_1_0_0" : "OpenSSL_1_0_1", "OpenSSL_1_0_1" : "OpenSSL_1_0_2"}
map_rel_wireshark = {"wireshark-1_8_0" : "wireshark-1_10_0", "wireshark-1_10_0" : "v1_11_0", "v1_11_0" : "v1_12_0", "v1_12_0" : "v1_99_0", "v1_99_0" : "v2_0_0"
                    , "v2_0_0" : "v2_1_0", "v2_1_0" : "v2_2_0", "v2_2_0" : "v2_3_0"}
fileMetrics = "metrics_lstm.csv"
fileRaw = "dataset.json"
dir_main = "../dataset/jsonset/"
folderModel = "/model/"
numEpochs = 100
embedding_vector_length = 32
num_batch_size = 50
raw = "/raw/"
strMetrics = "/metrics/"
sequence_length = 100
shouldOverwrite = True
shouldReTrain = True