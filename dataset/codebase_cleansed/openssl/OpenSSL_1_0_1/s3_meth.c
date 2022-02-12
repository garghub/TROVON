static const SSL_METHOD *ssl3_get_method(int ver)\r\n{\r\nif (ver == SSL3_VERSION)\r\nreturn(SSLv3_method());\r\nelse\r\nreturn(NULL);\r\n}
