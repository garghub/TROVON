static int seed_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,\r\nconst unsigned char *iv, int enc)\r\n{\r\nSEED_set_key(key, ctx->cipher_data);\r\nreturn 1;\r\n}
