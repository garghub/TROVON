# *Learning from What We Know: How to Perform Vulnerability Prediction using Noisy Historical Data*

This repository contains the source code and dataset for the paper _Learning from What We Know: How to Perform Vulnerability Prediction using Noisy Historical Data_, submitted in _Empirical Software Engineering (EMSE)_, and is under review.

In addition to the source code of our proposed approach _**TROVON**_, we also implement existing approaches due to unavailable authors' implementation. Our implementations of the existing approaches which we compare _TROVON_ with, are also available in this repository. Please refer to the details below. 

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
