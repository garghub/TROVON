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

def evaluate(model: Model, nodes_to_evaluate, x, y=None):
    symb_inputs = (model._feed_inputs)
    f = K.function(symb_inputs, nodes_to_evaluate)
    x_ = x
    return f(x_)

def get_activations_single_layer(model, x, layer_name=None):
    nodes = [layer.output for layer in model.layers if layer.name == layer_name or layer_name is None]
    input_layer_outputs, layer_outputs = [], []
    [input_layer_outputs.append(node) if 'input_' in node.name else layer_outputs.append(node) for node in nodes]
    activations = evaluate(model, layer_outputs, x, y=None)
    activations_dict = dict(zip([output.name for output in layer_outputs], activations))
    activations_inputs_dict = dict(zip([output.name for output in input_layer_outputs], x))
    result = activations_inputs_dict.copy()
    result.update(activations_dict)
    return np.squeeze(list(result.values())[0])

def layerName(model, layer):
    layerNames = [layer.name for layer in model.layers]
    return layerNames[layer]

def hard_sigmoid(x):
    return np.maximum(0, np.minimum(1, 0.2*x+0.5))

def cal_hidden_state(model, test):
    lenTest = len(test)
    print("\n-------------- test recieved of shape: ", test.shape, "--------------")
    acx = get_activations_single_layer(model, test, layerName(model, 0))
    units = int(int(model.layers[1].trainable_weights[0].shape[1]) / 4)
    W = model.layers[1].get_weights()[0]
    U = model.layers[1].get_weights()[1]
    b = model.layers[1].get_weights()[2]

    W_i = W[:, :units]
    W_f = W[:, units: units * 2]
    W_c = W[:, units * 2: units * 3]
    W_o = W[:, units * 3:]

    U_i = U[:, :units]
    U_f = U[:, units: units * 2]
    U_c = U[:, units * 2: units * 3]
    U_o = U[:, units * 3:]

    b_i = b[:units]
    b_f = b[units: units * 2]
    b_c = b[units * 2: units * 3]
    b_o = b[units * 3:]

    h_t = np.zeros((lenTest, units))
    c_t = np.zeros((lenTest, units))
    f_t = np.zeros((lenTest, units))
    h_t0 = np.zeros((1, units))
    c_t0 = np.zeros((1, units))

    for i in range(0, lenTest):
        f_gate = hard_sigmoid(np.dot(acx[i, :], W_f) + np.dot(h_t0, U_f) + b_f)
        i_gate = hard_sigmoid(np.dot(acx[i, :], W_i) + np.dot(h_t0, U_i) + b_i)
        o_gate = hard_sigmoid(np.dot(acx[i, :], W_o) + np.dot(h_t0, U_o) + b_o)
        new_C = np.tanh(np.dot(acx[i, :], W_c) + np.dot(h_t0, U_c) + b_c)
        c_t0 = f_gate * c_t0 + i_gate * new_C
        h_t0 = o_gate * np.tanh(c_t0)
        c_t[i, :] = c_t0.mean(axis=0)
        h_t[i, :] = h_t0.mean(axis=0)
        f_t[i, :] = f_gate.mean(axis=0)

    return [h_t, c_t, f_t]
    
def get_random_forest_predictions(model, xBoth, yBoth, fileModel):
    h_t, c_t, f_t = cal_hidden_state(model, xBoth)
    print("\n-------------- output: f_t of shape", f_t.shape, "--------------")
    XTrain, XTest, yTrain, yTest = train_test_split(f_t, yBoth, test_size=0.5, shuffle=False)
    shouldProcess = True
    if path.exists(fileModel):
        shouldProcess = False
        if config.shouldReTrain:
            shouldProcess = True
            print("\n-------------- trained classifier exists but re-training from the scratch --------------")
    if shouldProcess is False:
        print("\n-------------- loading trained classifier --------------")
        with open(fileModel, 'rb') as f:
            clf = pickle.load(f)
    else:
        clf = RandomForestClassifier()
        print("\n-------------- Classifer training started --------------")
        clf.fit(XTrain, yTrain)
        print("\n-------------- Classifer training finished, saving as file --------------")
        with open(fileModel, 'wb') as f:
            pickle.dump(clf, f)
    print("\n--------------prediction started--------------")
    yPredProb = clf.predict_proba(XTest)[:,1]
    return yTest, yPredProb