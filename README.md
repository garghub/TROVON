# TROVON

# *Learning from What We Know: How to Perform Vulnerability Prediction using Noisy Historical Data*

This repo contains the source-code and data set for the paper _Learning from What We Know: How to Perform Vulnerability Prediction using Noisy Historical Data_, submitted in _Empirical Software Engineering (EMSE)_.

Additionally, our implementation of the exisitng approaches (due to lack of original source-code) that we compared with, is also available in this repo. Please refer to the details below. 

---

The dataset is composed of the following:

1) _Vulnerabilities_ reported in [_National Vulnerability Database (NVD)_](https://nvd.nist.gov) and

2) _Codebase_ gathered for the _36_ releases of [_Linux Kernel_](https://www.kernel.org) project, _10_ releases of [_Openssl_](https://www.openssl.org) project, and _10_ releases of [_Wireshark_](https://www.wireshark.org) project.

---

The source-code of vulnerability prediction approaches are available as below mentioned:

1) Source-code of our proposed approach [_TROVON_](https://github.com/garghub/TROVON) is available in the [code](code) directory.

2) Source-code of our implementation of approach [_Devign: Effective Vulnerability Identification by Learning Comprehensive Program Semantics via Graph Neural Networks_](https://arxiv.org/abs/1909.03496) is available in the [devign](devign) directory.

3) Source-code of our implementation of approach [_Automatic Feature Learning for Predicting Vulnerable Software Components_](https://ieeexplore.ieee.org/document/8540022) is available in the [lstm-rf](lstm-rf) directory.
