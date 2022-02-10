import json
import re
import subprocess
import os.path
import os
import time
from .cpg_client_wrapper import CPGClientWrapper
#from ..data import datamanager as data


def funcs_to_graphs(funcs_path):
    client = CPGClientWrapper()
    # query the cpg for the dataset
    print(f"Creating CPG.")
    graphs_string = client(funcs_path)
    # removes unnecessary namespace for object references
    graphs_string = re.sub(r"io\.shiftleft\.codepropertygraph\.generated\.", '', graphs_string)
    graphs_json = json.loads(graphs_string)

    return graphs_json["functions"]


def graph_indexing(graph):
    idx = int(graph["file"].split(".c")[0].split("/")[-1])
    del graph["file"]
    return idx, {"functions": [graph]}


def joern_parse(joern_path, input_path, output_path, file_name):
    out_file = file_name + ".bin"
    print("\n--------------Subprocess started", ["./" + joern_path + "joern-parse", input_path, "--out", output_path + out_file], "--------------");
    joern_parse_call = subprocess.run(["./" + joern_path + "joern-parse", input_path, "--out", output_path + out_file],
                                      stdout=subprocess.PIPE, text=True, check=True)
    print("\n--------------Subprocess finished ", ["./" + joern_path + "joern-parse", input_path, "--out", output_path + out_file], "--------------");
    print(str(joern_parse_call))
    return out_file


def joern_create(joern_path, in_path, out_path, cpg_files):
    print("\n--------------Executing joern_create with below parameters started--------------");
    print("\n--------------joern_path: ", joern_path, "--------------");
    print("\n--------------in_path: ", in_path, "--------------");
    print("\n--------------out_path: ", out_path, "--------------");
    print("\n--------------cpg_files: ", cpg_files, "--------------");
    print("\n--------------Subprocess started", ["./" + joern_path + "joern"], "--------------");
    joern_process = subprocess.Popen(["./" + joern_path + "joern"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    json_files = []
    for cpg_file in cpg_files:
        json_file_name = f"{cpg_file.split('.')[0]}.json"
        json_files.append(json_file_name)

        print(in_path+cpg_file)
        if os.path.exists(in_path+cpg_file):
            print("\n--------------", in_path+cpg_file, "exists--------------");
            json_out = f"{os.path.abspath(out_path)}/{json_file_name}"
            print("\n--------------json_out: ", json_out, "--------------");
            import_cpg_cmd = f"importCpg(\"{os.path.abspath(in_path)}/{cpg_file}\")\r".encode()
            print("\n--------------import_cpg_cmd: ", import_cpg_cmd, "--------------");
            script_path = f"{os.path.dirname(os.path.abspath(joern_path))}/graph-for-funcs.sc"
            print("\n--------------script_path: ", script_path, "--------------");
            run_script_cmd = f"cpg.runScript(\"{script_path}\").toString() |> \"{json_out}\"\r".encode()
            print("\n--------------run_script_cmd: ", run_script_cmd, "--------------");
            print("\n--------------sending command to joern: ", import_cpg_cmd, "--------------");
            joern_process.stdin.write(import_cpg_cmd)
            print(joern_process.stdout.readline().decode())
            print("\n--------------sending command to joern: ", run_script_cmd, "--------------");
            joern_process.stdin.write(run_script_cmd)
            print(joern_process.stdout.readline().decode())
            print("\n--------------sending command to joern: ", "delete\r".encode(), "--------------");
            joern_process.stdin.write("delete\r".encode())
            print(joern_process.stdout.readline().decode())
            
        else:
            print("\n--------------", in_path+cpg_file, "does not exist--------------");
    try:
        outs, errs = joern_process.communicate(timeout=60)
    except subprocess.TimeoutExpired:
        joern_process.kill()
        outs, errs = joern_process.communicate()
    if outs is not None:
        print("\n--------------Output recieved from joern started--------------");
        print(f"Outs: {outs.decode()}")
        print("\n--------------Output recieved from joern finished--------------");
    if errs is not None:
        print("\n--------------Errors recieved from joern started--------------");
        print(f"Errs: {errs.decode()}")
        print("\n--------------Errors recieved from joern finished--------------");
    print("\n--------------Executing joern_create with below parameters finished--------------");
    return json_files


def json_process(in_path, json_file):
    if os.path.exists(in_path+json_file):
        with open(in_path+json_file) as jf:
            cpg_string = jf.read()
            cpg_string = re.sub(r"io\.shiftleft\.codepropertygraph\.generated\.", '', cpg_string)
            cpg_json = json.loads(cpg_string)
            container = [graph_indexing(graph) for graph in cpg_json["functions"] if graph["file"] != "N/A"]
            return container
    return None

'''
def generate(dataset, funcs_path):
    dataset_size = len(dataset)
    print("Size: ", dataset_size)
    graphs = funcs_to_graphs(funcs_path[2:])
    print(f"Processing CPG.")
    container = [graph_indexing(graph) for graph in graphs["functions"] if graph["file"] != "N/A"]
    graph_dataset = data.create_with_index(container, ["Index", "cpg"])
    print(f"Dataset processed.")

    return data.inner_join_by_index(dataset, graph_dataset)
'''

# client = CPGClientWrapper()
# client.create_cpg("../../data/joern/")
# joern_parse("../../joern/joern-cli/", "../../data/joern/", "../../joern/joern-cli/", "gen_test")
# print(funcs_to_graphs("/data/joern/"))
"""
while True:
    raw = input("query: ")
    response = client.query(raw)
    print(response)
"""