static int cast_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,\r\nconst unsigned char *iv, int enc)\r\n{\r\nCAST_set_key(&data(ctx)->ks,EVP_CIPHER_CTX_key_length(ctx),key);\r\nreturn 1;\r\n}
