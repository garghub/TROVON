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
import preprocess
import start

def main(str_proj, str_train_rel, str_train_tech):
    if str_train_tech == "":
        arr_train_tech = []
    else:
        arr_train_tech = [str_train_tech]
    
    if str_train_rel == "":
        arr_train_rel = []
    else:
        arr_train_rel = [str_train_rel]
    
    if str_proj == "":
        arr_proj = config.arr_proj
    else:
        arr_proj = [str_proj]
    
    for str_proj in arr_proj:
        if len(arr_train_rel) <= 0:
            if str_proj == config.linux:
                arr_train_rel = config.map_rel_linux
            elif str_proj == config.openssl:
                arr_train_rel = config.map_rel_openssl
            elif str_proj == config.wireshark:
                arr_train_rel = config.map_rel_wireshark
        for str_train_rel in arr_train_rel:
            if len(arr_train_tech) <= 0:
                arr_train_tech = config.arr_train_tech
            for str_train_tech in arr_train_tech:
                print("\n--------------Project: " + str_proj + "--------------")
                print("\n--------------Training release: " + str_train_rel + "--------------")
                print("\n--------------Training technique: " + str_train_tech + "--------------")
                bool_preprocessing_successful, dir_raw, dir_metrics, str_test_rel = preprocess.preprocess(str_proj, str_train_rel, str_train_tech)
                if bool_preprocessing_successful:
                    start.start(dir_metrics, dir_raw, str_proj, str_train_rel, str_test_rel, str_train_tech)
        arr_train_rel = []

str_proj = ""
str_train_rel = ""
str_train_tech = ""
if len(sys.argv) > 1:
    str_proj = sys.argv[1]
if len(sys.argv) > 2:
    str_train_rel = sys.argv[2]
if len(sys.argv) > 3:
    str_train_tech = sys.argv[3]

main(str_proj, str_train_rel, str_train_tech)