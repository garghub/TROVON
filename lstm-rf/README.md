# Our implementation of _LSTM_ and _LSTM-RF_ 

Paper:
[_Automatic Feature Learning for Predicting Vulnerable Software Components_](https://ieeexplore.ieee.org/document/8540022)

Paper Authors:
_Hoa Khanh Dam, Truyen Tran, Trang Pham, Shien Wee Ng, John Grundy, Aditya Ghose_

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

Fixed Parameters used:

Embedding layer -

-  "output_dim" : 32
  
-  "input_length" : 100

LSTM layer - 

-  "units" : 100
  
-  "return_sequences" : True
  
-  "dropout" : 0.5

TimeDistributed - Dense layer - 

-  "activation" : "sigmoid"

Optimizer -

-  "name" : "RMSprop"
  
-  "learning_rate" : 0.02
  
-  "rho" : 0.99
  
-  "epsilon" : 1e-07

"epochs" : 100

"test_size" : 0.5

"shuffle" : False
