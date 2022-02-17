# Our implementation of _Devign_

Paper: 
[_Devign: Effective Vulnerability Identification by Learning Comprehensive Program Semantics via Graph Neural Networks_](https://arxiv.org/abs/1909.03496)

Paper Authors:
_Yaqin Zhou, Shangqing Liu, Jingkai Siow, Xiaoning Du, Yang Liu_

---

Prerequisites

Joern (https://joern.io/docs/)
Python (=>3.6)(https://www.python.org/)

Python Libraries:
Pandas (>=1.0.1) (https://pandas.pydata.org/)
scikit-learn (>=0.22.2) (https://scikit-learn.org/stable/)
PyTorch (>=1.4.0) (https://pytorch.org/)
PyTorch Geometric (>=1.4.2) (https://pytorch-geometric.readthedocs.io/en/latest/notes/installation.html)
Gensim (>=3.8.1) (https://radimrehurek.com/gensim/)
cpgclientlib (>=0.11.111) (https://pypi.org/project/cpgclientlib/)

---

Terminal commands to execute before executing below command: 
python3 main.py openssl OpenSSL_0_9_6 clean
1) sudo apt install python3-pip
2) pip install gensim==3.8.1
3) pip install torch torchvision torchaudio
   or for cpu
   pip install torch==1.10.1+cpu torchvision==0.11.2+cpu torchaudio==0.10.1+cpu -f https://download.pytorch.org/whl/cpu/torch_stable.html
   OR for GPU
   pip install torch==1.10.0+cu113 torchvision==0.11.1+cu113 torchaudio==0.10.0+cu113 -f https://download.pytorch.org/whl/cu113/torch_stable.html
3.a) to verify - 	python3 -c "import torch; print(torch.version.cuda)"
					OR
					python3
					import torch
					x = torch.rand(5, 3)
					print(x)
					torch.cuda.is_available()
					True
					torch.cuda.current_device()
					0
					torch.cuda.device(0)
					<torch.cuda.device object at 0x7fc520ca9280>
					torch.cuda.device_count()
					1
					torch.cuda.get_device_name(0)
					'NVIDIA GeForce RTX 3080'
					exit()
4) pip install --upgrade pandas
5) 	for cpu
	pip install torch-scatter torch-sparse torch-geometric -f https://data.pyg.org/whl/torch-1.10.0+cpu.html
	for gpu
    pip install torch-scatter torch-sparse torch-geometric -f https://data.pyg.org/whl/torch-1.10.0+cu113.html
6) pip install cpgclientlib
6.a) to verify - 	python3
					from cpgclient.CpgClient import CpgClient
					exit()

---

Below files are also executables, please provide permissions accordingly:
1) TROVON/devign/joern/joern-cli/joern-parse
2) TROVON/devign/joern/joern-cli/joern
3) TROVON/devign/joern/joern-cli/bin/joern-parse
4) TROVON/devign/joern/joern-cli/bin/ammonite-bridge

---

Execute with:

- python3 main.py [linux_kernel/openssl/wireshark] [v3_15/OpenSSL_0_9_6/v2_0_0] [clean/noisy]

for all releases of all projects with both settings ( 1. clean data training setting, 2. realistic training setting ), sequentially -

- python3 main.py

for all releases of linux_kernel project  with both settings ( 1. clean data training setting, 2. realistic training setting ), sequentially -

- python3 main.py linux_kernel

for release v3.15 of linux_kernel project  with both settings ( 1. clean data training setting, 2. realistic training setting ), sequentially -

- python3 main.py linux_kernel v3_15

for release v3.15 of linux_kernel project with only realistic training setting -

- python3 main.py linux_kernel v3_15 noisy
 
---

Parameters used:

"learning_rate" : 1e-4

"weight_decay" : 1.3e-6

"loss_lambda" : 1.3e-6

"epochs" : 100

"patience" : 10

"batch_size" : 8

"dataset_ratio" : 0.5

"shuffle" : false
