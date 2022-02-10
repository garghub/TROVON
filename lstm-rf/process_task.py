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
import classifier
import util

def save_metrics(dir_metrics, strLstmName, resultMetrics):
    for turn in [[config.fileMetrics, resultMetrics]]:
        fileName = turn[0]
        result = turn[1]
        metrics_path = dir_metrics + fileName.replace("lstm", strLstmName)
        print("\n--------------writing ", metrics_path, " started--------------")
        with open(metrics_path, 'w') as csvfile:
            for key in result.keys():
                csvfile.write("%s, %s\n" % (key, result[key]))
        print("\n--------------writing ", metrics_path, " finished--------------")

def calculate_metrics(yPreds, yLabels):
    ySeries = Series(yPreds)
    yPredicts = ySeries.apply(lambda x: 1 if x >= 0.5 else 0)
            
    yPredicts.reset_index(drop=True, inplace=True)
    returnMetrics = {"Accuracy": metrics.accuracy_score(y_true=yLabels, y_pred=yPredicts),
                     "Precision": metrics.precision_score(y_true=yLabels, y_pred=yPredicts),
                     "Recall": metrics.recall_score(y_true=yLabels, y_pred=yPredicts),
                     "F-measure": metrics.f1_score(y_true=yLabels, y_pred=yPredicts),
                     "Precision-Recall AUC": metrics.average_precision_score(y_true=yLabels, y_score=yPredicts),
                     "AUC": metrics.roc_auc_score(y_true=yLabels, y_score=yPredicts),
                     "MCC": metrics.matthews_corrcoef(y_true=yLabels, y_pred=yPredicts)}
    print(returnMetrics)
    return returnMetrics

def test_model(model, X, y):
    # evaluate model
    print("\n--------------prediction started--------------")
    yPred = model.predict(X, verbose=0)
    yPred_1 = np.argmax(yPred,axis=1)
    yPred_2 = np.squeeze(yPred_1)
    return yPred_2

def save_model(model, fileModel):
    print("Saving model at", fileModel)
    model.save(fileModel)

def train_model(model, numEpochs, X, y):
    print("\n--------------training started--------------")
    loss = list()
    for i in range(numEpochs):
        hist = model.fit(X, y, epochs=1, batch_size=config.num_batch_size, verbose=0)
        loss.append(hist.history['loss'][0])
        print(str(i + 1) + "/" + str(numEpochs) + " epochs")
    return loss, model

def load_model(fileModel):
    print("loading model from", fileModel)
    loaded_model = models.load_model(fileModel)
    return loaded_model

def get_lstm_model(n_timesteps, backwards, num_LSTM_units, vocab_size):
    model = Sequential()
    model.add(Embedding(input_dim=vocab_size, output_dim=config.embedding_vector_length, input_length=num_LSTM_units))
    model.add(LSTM(num_LSTM_units, return_sequences=True, go_backwards=backwards, dropout=0.5))
    model.add(TimeDistributed(Dense(1, activation='sigmoid')))
    opt = RMSprop(name="RMSprop", learning_rate=0.02, rho=0.99, epsilon=1e-07)
    model.compile(loss='sparse_categorical_crossentropy', optimizer=opt)
    print(model.summary())
    return model

def process_task(numItems, XTrain, yTrain, XTest, yTest, dir_metrics, num_LSTM_units, vocab_size,
                str_proj, str_train_rel, str_train_tech, bool_RF):
    results = DataFrame()
    for mainTechnique in ['lstm']:
        if mainTechnique == 'lstm':
            arrTechnique = [False]
        for technique in arrTechnique:
            if technique is False:
                techName = "forwards"

            if mainTechnique == 'lstm':
                model = get_lstm_model(numItems, technique, num_LSTM_units, vocab_size)
            
            dir_model = config.dir_main + str_proj + "_" + str_train_rel + "_" + str_train_tech + config.folderModel
            strLstmName = mainTechnique + '_' + techName
            fileModel = dir_model + strLstmName + ".h5"
            print("\nprocessing for " + strLstmName)
            
            shouldProcess = True
            if path.exists(fileModel):
                shouldProcess = False
                if config.shouldReTrain and (bool_RF is False):
                    shouldProcess = True
                    print("\n-------------- trained model exists but re-training from scratch --------------")
                
            if shouldProcess is False:
                print("\n-------------- loading trained model --------------")
                trained_model = load_model(fileModel)
                results[strLstmName] = list()
            else:
                results[strLstmName], trained_model = train_model(model, config.numEpochs, XTrain, yTrain)
                print("\n--------------training finished--------------")
                #print(results[strLstmName])
                save_model(trained_model, fileModel)
            
            if bool_RF is False:
                yPred = test_model(trained_model, XTest, yTest)
            else:
                strLstmName = mainTechnique + '_' + "rf"
                fileModel = dir_model + strLstmName + ".pkl"
                XBoth = np.concatenate((XTrain, XTest), axis=0)
                yBoth = yTrain
                yBoth = yBoth.append(yTest)
                yTest, yPred = classifier.get_random_forest_predictions(trained_model, XBoth, yBoth, fileModel)  
            
            print("\n--------------prediction finished--------------")
            print("\n--------------yPred.shape = ", yPred.shape, "--------------")
            print("\n--------------yTest.shape = ", yTest.shape, "--------------")
            arrPred = util.return_np_array(yPred)
            arrLabel = util.return_np_array(yTest)  
            returnMetrics = calculate_metrics(arrPred, arrLabel)
            save_metrics(dir_metrics, strLstmName, returnMetrics)

    results.plot()
    pyplot.show()