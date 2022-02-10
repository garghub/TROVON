# -*- coding: utf-8 -*-
"""
    This module is intended to join all the pipeline in separated tasks
    to be executed individually or in a flow by using command-line options

    Example:
    Dataset embedding and processing:
        $ python taskflows.py -e -pS
"""

import argparse
import gc
import shutil
import sys
from argparse import ArgumentParser

from gensim.models.word2vec import Word2Vec

import configs
import src.data as data
import src.prepare as prepare
import src.process as process
import src.utils.functions.cpg as cpg
import csv

import os
import os.path
from os import path
import time

str_proj = ""
str_train_rel = ""
str_train_tech = ""
str_test_rel = ""
dir_cpg = ""
dir_joern = ""
dir_raw = ""
dir_input = ""
dir_model = ""
dir_tokens = ""
dir_w2v = ""
dir_metrics = ""
bool_preprocessing_successful = False

CREATE = configs.Create()
PATHS = configs.Paths()
FILES = configs.Files()
DEVICE = FILES.get_device()

def select(dataset):
    global str_proj, str_train_rel, str_test_rel, CREATE
    print("\n--------------len(dataset): ", len(dataset) ," --------------")
    context = CREATE
    result_init = dataset.loc[dataset['project'] == str_proj]
    result_train = result_init[result_init['commit_id'].str.contains(str_train_rel)]
    result_test = result_init[result_init['commit_id'].str.contains(str_test_rel)]
    result = None
    result_train_head = result_train
    result = result_train_head
    result_test_head = result_test
    result = result.append(result_test_head, ignore_index=True)
    print("\n--------------len(result) (selected dataset): ", len(result), " --------------")
    return result

def create_task():
    global dir_cpg, dir_joern, dir_raw, dir_input, dir_model, dir_tokens, dir_w2v, dir_metrics
    context = configs.Create()
    raw = data.read(dir_raw, FILES.raw)
    filtered = data.apply_filter(raw, select)
    filtered = data.clean(filtered)
    data.drop(filtered, ["commit_id", "project"])
    print("\n--------------context.slice_size--------------")
    print(context.slice_size)
    slices = data.slice_frame(filtered, context.slice_size)
    slices = [(s, slice.apply(lambda x: x)) for s, slice in slices]
    print("\n--------------variable initialization finished--------------")

    cpg_files = []
    # Create CPG binary files
    print("\n--------------Create CPG binary files started--------------")
    for s, slice in slices:
        print("\n--------------slice--------------")
        print(slice)
        print("\n--------------dir_joern--------------")
        print(dir_joern)
        data.to_files(slice, dir_joern)
        print("\n--------------context.joern_cli_dir--------------")
        print(context.joern_cli_dir)
        print("\n--------------dir_cpg--------------")
        print(dir_cpg)
        print("\n--------------{s}_{FILES.cpg}--------------")
        print(f"{s}_{FILES.cpg}")
        cpg_file = prepare.joern_parse(context.joern_cli_dir, dir_joern, dir_cpg, f"{s}_{FILES.cpg}")
        print("\n--------------cpg_file--------------")
        print(cpg_file)
        cpg_files.append(cpg_file)
        print(f"Dataset {s} to cpg.")
        shutil.rmtree(dir_joern)
    print("\n--------------Create CPG binary files finished--------------")
    # Create CPG with graphs json files
    print("\n--------------Create CPG with graphs json files started--------------")
    json_files = prepare.joern_create(context.joern_cli_dir, dir_cpg, dir_cpg, cpg_files)
    print("\n--------------Possible result of joern_create process (json_files object): ", json_files, "--------------")
    for (s, slice), json_file in zip(slices, json_files):
        graphs = prepare.json_process(dir_cpg, json_file)
        if graphs is None:
            print(f"Dataset chunk {s} not processed.")
            continue
        dataset = data.create_with_index(graphs, ["Index", "cpg"])
        dataset = data.inner_join_by_index(slice, dataset)
        print(f"Writing cpg dataset chunk {s}.")
        data.write(dataset, dir_cpg, f"{s}_{FILES.cpg}.pkl")
        del dataset
        gc.collect()


def embed_task():
    global dir_cpg, dir_joern, dir_raw, dir_input, dir_model, dir_tokens, dir_w2v, dir_metrics
    context = configs.Embed()
    # Tokenize source code into tokens
    dataset_files = data.get_directory_files(dir_cpg)
    print("\n--------------dataset_files: ", dataset_files, "--------------")
    w2vmodel = Word2Vec(**context.w2v_args)
    print("\n--------------w2vmodel: ", w2vmodel, "--------------")
    w2v_init = True
    for pkl_file in dataset_files:
        file_name = pkl_file.split(".")[0]
        cpg_dataset = data.load(dir_cpg, pkl_file)
        print("\n--------------cpg_dataset--------------")
        print(cpg_dataset)
        tokens_dataset = data.tokenize(cpg_dataset)
        print("\n--------------tokens_dataset--------------")
        print(tokens_dataset)
        print("\n--------------writing tokens_dataset to ", dir_tokens, f"{file_name}_{FILES.tokens}", "--------------")
        data.write(tokens_dataset, dir_tokens, f"{file_name}_{FILES.tokens}")
        # word2vec used to learn the initial embedding of each token
        print("\n--------------building vocab started--------------")
        #w2vmodel.build_vocab(sentences=tokens_dataset.tokens, update=not w2v_init)
        w2vmodel.build_vocab(tokens_dataset.tokens, update=not w2v_init)
        print("\n--------------building vocab finished--------------")
        print("\n--------------training w2vmodel started--------------")
        w2vmodel.train(tokens_dataset.tokens, total_examples=w2vmodel.corpus_count, epochs=1)
        print("\n--------------training w2vmodel finished--------------")
        if w2v_init:
            w2v_init = False
        # Embed cpg to node representation and pass to graph data structure
        cpg_dataset["nodes"] = cpg_dataset.apply(lambda row: cpg.parse_to_nodes(row.cpg, context.nodes_dim), axis=1)
        print("\n--------------cpg_dataset[""nodes""]--------------")
        print(cpg_dataset["nodes"])
        # remove rows with no nodes
        cpg_dataset = cpg_dataset.loc[cpg_dataset.nodes.map(len) > 0]
        print("\n--------------after removing rows with no nodes, len(cpg_dataset): ", len(cpg_dataset), "--------------")
        cpg_dataset["input"] = cpg_dataset.apply(lambda row: prepare.nodes_to_input(row.nodes, row.target, context.nodes_dim,
                                                                                    w2vmodel.wv, context.edge_type), axis=1)
        data.drop(cpg_dataset, ["nodes"])
        print(f"Saving input dataset {file_name} with size {len(cpg_dataset)}.")
        data.write(cpg_dataset[["input", "target"]], dir_input, f"{file_name}_{FILES.input}")
        del cpg_dataset
        gc.collect()
    print("Saving w2vmodel.")
    print("\n--------------Saving w2vmodel at", f"{dir_w2v}/{FILES.w2v}", "--------------")
    w2vmodel.save(f"{dir_w2v}/{FILES.w2v}")


def process_task():
    global dir_cpg, dir_joern, dir_raw, dir_input, dir_model, dir_tokens, dir_w2v, dir_metrics
    context = configs.Process()
    devign = configs.Devign()
    model_path = dir_model + FILES.model
    print("\n--------------process.Devign task with below parameters started--------------")
    print("\n--------------path=model_path; model_path: ", model_path, "--------------")
    print("\n--------------device=DEVICE; DEVICE: ", DEVICE, "--------------")
    print("\n--------------model=devign.model; devign.model: ", devign.model, "--------------")
    print("\n--------------learning_rate=devign.learning_rate; devign.learning_rate: ", devign.learning_rate, "--------------")
    print("\n--------------weight_decay=devign.weight_decay; devign.weight_decay: ", devign.weight_decay, "--------------")
    print("\n--------------loss_lambda=devign.loss_lambda; devign.loss_lambda: ", devign.loss_lambda, "--------------")
    model = process.Devign(path=model_path, device=DEVICE, model=devign.model, learning_rate=devign.learning_rate,
                           weight_decay=devign.weight_decay,
                           loss_lambda=devign.loss_lambda)
    print("\n--------------process.Devign task with result model: ", model, " finished--------------")
    print("\n--------------process.Train task of model for context.epochs: ", context.epochs, " started--------------")
    train = process.Train(model, context.epochs)
    print("\n--------------process.Train task with train: ", train, " finished--------------")
    print("\n--------------dir_input: ", dir_input, " --------------")
    input_dataset = data.loads(dir_input)
    print("\n--------------input_dataset: ", input_dataset, "--------------")
    # split the dataset and pass to DataLoader with batch size
    print("\n--------------context.batch_size: ", context.batch_size, "--------------")
    print("\n--------------shuffle=context.shuffle, context.shuffle: ", context.shuffle, "--------------")
    train_loader, val_loader, test_loader = list(
        map(lambda x: x.get_loader(context.batch_size, shuffle=context.shuffle),
            data.train_val_test_split(input_dataset, shuffle=context.shuffle)))
    print("\n--------------train_loader: ", train_loader, "--------------")
    print("\n--------------val_loader: ", val_loader, "--------------")
    print("\n--------------test_loader: ", test_loader, "--------------")
    train_loader_step = process.LoaderStep("Train", train_loader, DEVICE)
    print("\n--------------train_loader_step: ", train_loader_step, "--------------")
    val_loader_step = process.LoaderStep("Validation", val_loader, DEVICE)
    print("\n--------------val_loader_step: ", val_loader_step, "--------------")
    test_loader_step = process.LoaderStep("Test", test_loader, DEVICE)
    print("\n--------------test_loader_step: ", test_loader_step, "--------------")

    print("\n--------------process train started--------------")
    train(train_loader_step, val_loader_step)
    print("\n--------------process train finished--------------")
    print("\n--------------model.save() started--------------")
    model.save()
    print("\n--------------model.save() finished--------------")

    print("\n--------------process.predict started--------------")
    metrics = process.predict(model, test_loader_step)
    print("\n--------------process.predict finished--------------")
    print("\n--------------metrics: ", metrics, "--------------")
    metrics_path = dir_metrics + FILES.metrics
    print("\n--------------writing ",metrics_path, " started--------------")
    with open(metrics_path, 'w') as csvfile:
        for key in metrics.keys():
            csvfile.write("%s, %s\n" % (key, metrics[key]))
    print("\n--------------writing ",metrics_path, " finished--------------")

def preprocess():
    global str_proj, str_train_rel, str_test_rel, str_train_tech, CREATE, bool_preprocessing_successful
    global dir_cpg, dir_joern, dir_raw, dir_input, dir_model, dir_tokens, dir_w2v, dir_metrics
    if str_proj == "linux_kernel":
        map_rel = CREATE.map_rel_linux
    elif str_proj == "openssl":
        map_rel = CREATE.map_rel_openssl
    elif str_proj == "wireshark":
        map_rel = CREATE.map_rel_wireshark
    else:
        map_rel = None

    if map_rel is None:
        print("\nproject options: linux_kernel / openssl / wireshark")
        print("\nplease try again")
    else:
        if str_train_rel not in map_rel:
            str_train_rel = None
            print("\nplease enter a valid release name and try again")
        else:
            str_test_rel = map_rel[str_train_rel]
            print("\n--------------Testing release: " + str_test_rel + "--------------")
    
            if str_train_tech not in ["clean", "noisy"]:
                str_train_tech = None
                print("\ntraining technique options: clean / noisy")
                print("\nplease try again")
            else:
                dir_cpg = PATHS.dir_main + str_proj + "_" + str_train_rel + "_" + str_train_tech + PATHS.cpg
                print("CPG directory: " + dir_cpg)
                dir_joern = PATHS.dir_main + str_proj + "_" + str_train_rel + "_" + str_train_tech + PATHS.joern
                print("Joern directory: " + dir_joern)
                dir_raw = PATHS.dir_main + str_proj + "_" + str_train_rel + "_" + str_train_tech + PATHS.raw
                print("Raw directory: " + dir_raw)
                dir_input = PATHS.dir_main + str_proj + "_" + str_train_rel + "_" + str_train_tech + PATHS.input
                print("Input directory: " + dir_input)
                dir_model = PATHS.dir_main + str_proj + "_" + str_train_rel + "_" + str_train_tech + PATHS.model
                print("Model directory: " + dir_model)
                dir_tokens = PATHS.dir_main + str_proj + "_" + str_train_rel + "_" + str_train_tech + PATHS.tokens
                print("Tokens directory: " + dir_tokens)
                dir_w2v = PATHS.dir_main + str_proj + "_" + str_train_rel + "_" + str_train_tech + PATHS.w2v
                print("W2V directory: " + dir_w2v)
                dir_metrics = PATHS.dir_main + str_proj + "_" + str_train_rel + "_" + str_train_tech + PATHS.metrics
                print("Metrics directory: " + dir_metrics)
                
                bool_preprocessing_successful = True

def start():
    global bool_preprocessing_successful
    
    
    if bool_preprocessing_successful:
        print("\n-------------- checking if result metrics already exists --------------")
        metrics_path = dir_metrics + FILES.metrics
        if path.exists(metrics_path):
            print("\n-------------- ", metrics_path, " already exists, skipping the entire processing. --------------")
        else:
            print("\n-------------- checking if pkl file already exists --------------")
            dir_pkl = dir_cpg + "0_cpg.pkl"
            if path.exists(dir_pkl):
                print("\n-------------- ", dir_pkl, " already exists, skipping create task. --------------")
            else:
                print("\n--------------create task started--------------")
                create_task()
                print("\n--------------create task finished--------------")
            
            print("\n-------------- checking if w2v model file already exists --------------")
            dir_w2vmodel = dir_w2v + FILES.w2v
            if path.exists(dir_w2vmodel):
                print("\n-------------- ", dir_w2vmodel, " already exists, skipping embed task. --------------")
            else:
                print("\n--------------embed task started--------------")
                embed_task()
                print("\n--------------embed task finished--------------")
            
            print("\n-------------- checking if any other model is being trained --------------")
            dir_a_model_is_being_trained = PATHS.dir_main + FILES.a_model_is_being_trained
            # dir_a_model_is_being_trained = ../TROVON/dataset/jsonset/a_model_is_being_trained.txt
            boolFreeForTraining = False
            
            while boolFreeForTraining is False:
                if path.exists(dir_a_model_is_being_trained):
                    print("\n-------------- ", dir_a_model_is_being_trained, " already exists, waiting for the model to finish training. --------------")
                    print("\n-------------- sleeping for 10 minutes. --------------")
                    time.sleep(600)
                    print("\n-------------- waking up and re-checking. --------------")
                else:
                    f = open(dir_a_model_is_being_trained, "w")
                    f.write("Please delete this file if more than one model needs to be trained.")
                    f.close()
                    print("\n--------------process task started--------------")
                    process_task()
                    print("\n--------------process task finished--------------")
                    os.remove(dir_a_model_is_being_trained)
                    boolFreeForTraining = True
                

def main():
    global str_proj, str_train_rel, str_train_tech, CREATE
    if len(sys.argv) > 1:
        str_proj = sys.argv[1]
    if len(sys.argv) > 2:
        str_train_rel = sys.argv[2]
    if len(sys.argv) > 3:
        str_train_tech = sys.argv[3]
        
    if str_train_tech == "":
        arr_train_tech = []
    else:
        arr_train_tech = [str_train_tech]
    
    if str_train_rel == "":
        arr_train_rel = []
    else:
        arr_train_rel = [str_train_rel]
    
    if str_proj == "":
        arr_proj = ["linux_kernel", "openssl", "wireshark"]
    else:
        arr_proj = [str_proj]
    
    for str_proj in arr_proj:
        if len(arr_train_rel) <= 0:
            if str_proj == "linux_kernel":
                arr_train_rel = CREATE.map_rel_linux
            elif str_proj == "openssl":
                arr_train_rel = CREATE.map_rel_openssl
            elif str_proj == "wireshark":
                arr_train_rel = CREATE.map_rel_wireshark
        for str_train_rel in arr_train_rel:
            if len(arr_train_tech) <= 0:
                arr_train_tech = ["clean", "noisy"]
            for str_train_tech in arr_train_tech:
                print("\n--------------Project: " + str_proj + "--------------")
                print("\n--------------Training release: " + str_train_rel + "--------------")
                print("\n--------------Training technique: " + str_train_tech + "--------------")
                preprocess()
                start()

if __name__ == "__main__":
    main()
