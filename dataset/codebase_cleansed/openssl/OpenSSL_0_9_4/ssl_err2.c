void SSL_load_error_strings(void)\r\n{\r\n#ifndef NO_ERR\r\nERR_load_crypto_strings();\r\nERR_load_SSL_strings();\r\n#endif\r\n}
