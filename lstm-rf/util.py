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

def return_np_array(data):
    retData = None
    for item in data:
        if retData is None:
            retData = array(item)
        else:
            retData = np.append(retData, item)
    return retData

def get_upd_X(X):
    upd_X = pd.Series()
    max_length = 0
    for itemX in X:
        itemX = itemX.replace("\\r\\n", " ")
        arrX = itemX.split(" ")
        itemX = None
        apprLength = config.sequence_length if len(arrX) > config.sequence_length else len(arrX)
        for i in range(apprLength):
            if itemX is None:
                itemX = str(arrX[i])
            else:
                itemX = itemX + " " + str(arrX[i])
        lengthItemX = len(itemX.split(" "))
        if lengthItemX > max_length:
            max_length = lengthItemX
        upd_X = upd_X.append(pd.Series([itemX]), ignore_index=True)
    print("\n-------------- sequence maximum length: ", max_length, " --------------")
    return max_length, upd_X