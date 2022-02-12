static const SSL_METHOD *ssl2_get_method(int ver)\r\n{\r\nif (ver == SSL2_VERSION)\r\nreturn(SSLv2_method());\r\nelse\r\nreturn(NULL);\r\n}
