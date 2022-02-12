void _ossl_096_des_random_seed(DES_cblock *key)\r\n{\r\nRAND_seed(key, sizeof(DES_cblock));\r\n}
