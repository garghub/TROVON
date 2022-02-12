static const SSL_METHOD *dtls1_get_method(int ver)\r\n{\r\nif (ver == DTLS1_VERSION)\r\nreturn(DTLSv1_method());\r\nelse\r\nreturn(NULL);\r\n}
