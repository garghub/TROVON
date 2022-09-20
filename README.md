# *Learning from What We Know: How to Perform Vulnerability Prediction using Noisy Historical Data*

This repository contains the source code and dataset for the paper _Learning from What We Know: How to Perform Vulnerability Prediction using Noisy Historical Data_, accepted in _Empirical Software Engineering (EMSE)_ (July 02, 2022). 

The paper is available here: [![Paper](https://img.shields.io/badge/Paper-Springer-blue)](https://link.springer.com/article/10.1007/s10664-022-10197-4)

The bib entry for citing the paper is available here: [![Cite](https://img.shields.io/badge/Cite-BibTex-green.svg)](trovon.bib)

In addition to the source code of our proposed approach _**TROVON**_, we also implement _**existing**_ approaches due to unavailable authors' implementation. Our implementations of the existing approaches which we compare _TROVON_ with, are also available in this repository. Please refer to the details below. 

---

**Dataset**

The dataset is composed of the following:

1) We gathered vulnerabilities, (i.e., the vulnerable and the corresponding fixed components) of the _36_ releases of [_Linux Kernel_](https://www.kernel.org), _10_ releases of [_Openssl_](https://www.openssl.org), and _10_ releases of [_Wireshark_](https://www.wireshark.org). For this task, we use [_VulData7_](https://github.com/electricalwind/data7) which is a vulnerability patch gathering tool that used commit IDs provided by [_National Vulnerability Database (NVD)_](https://nvd.nist.gov) to gather the aforementioned. These are available in the [vulnerabilities](dataset/vulnerabilities) directory.

2) We also gathered _codebase_ for the aforementioned releases. For this task, we use [_FrameVPM_](https://dl.acm.org/doi/10.1145/3338906.3338941) which is a framework built to evaluate and compare vulnerability prediction models. The framework is available [here](https://github.com/electricalwind/framevpm).

---

**Source code**

The source code of the vulnerability prediction approaches - _TROVON_ and the existing (that we compared _TROVON_ with) are available as below mentioned:

1) Source code of our proposed approach [_TROVON_](https://github.com/garghub/TROVON) is available in the [code](code) directory.

2) Source code to replicate the following approaches - [Software Metrics](https://ieeexplore.ieee.org/abstract/document/5560680), [Text Mining](https://ieeexplore.ieee.org/abstract/document/6860243), [Imports, and Function Calls](https://dl.acm.org/doi/abs/10.1145/1315245.1315311), is available in the [_FrameVPM_](https://github.com/electricalwind/framevpm) repository.

3) Source code of our implementation of the approach [Devign](https://arxiv.org/abs/1909.03496) is available in the [devign](devign) directory.

4) Source code of our implementation of the approaches [LSTM and LSTM-RF](https://ieeexplore.ieee.org/document/8540022) is available in the [lstm-rf](lstm-rf) directory.

---

**Tools required/dependencies to be taken care of**

1) [Apache Maven](https://maven.apache.org/download.cgi)
2) [srcML](https://www.srcml.org/)
3) [seq2seq](https://google.github.io/seq2seq/getting_started/#download-setup)
4) [Tkinter](https://docs.python.org/3.8/library/tkinter.html)
5) [TensorFlow](https://www.tensorflow.org/install/pip)
6) [PyYAML](https://pyyaml.org/wiki/LibYAML)
7) [Perl](https://www.cpan.org/modules/INSTALL.html)

---

**Model training**

Please refer to the script [train.sh](seq2seq/train.sh)

./train.sh [dirpath] [training-samples-num * epoch-num] [dirpath]/model [config] 1 [training-samples-num] [training-samples-num] 0

For model configuration, please refer [length_50-l-1-2.yml](seq2seq/configs/length_50-l-1-2.yml). It is configured to train on sequences of length 50, which can be changed based on your requirement.

-----------------------------------------------------------------------------------------------------------------------------

**Model testing**

Please refer to the script [test.sh](seq2seq/test.sh)

./test.sh [dirpath]/test [dirpath]/model [desired-generated-sequences-file-name]
