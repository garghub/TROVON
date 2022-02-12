void OPENSSL_add_all_algorithms_conf(void)\r\n{\r\nOPENSSL_add_all_algorithms_noconf();\r\nOPENSSL_config(NULL);\r\n}
