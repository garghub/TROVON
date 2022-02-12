static int camellia_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
int ret;
ret=Camellia_set_key(key, ctx->key_len * 8, ctx->cipher_data);
if(ret < 0)
{
EVPerr(EVP_F_CAMELLIA_INIT_KEY,EVP_R_CAMELLIA_KEY_SETUP_FAILED);
return 0;
}
return 1;
}
