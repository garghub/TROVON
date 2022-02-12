static int aes_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
int ret;
if ((ctx->cipher->flags & EVP_CIPH_MODE) == EVP_CIPH_CFB_MODE
|| (ctx->cipher->flags & EVP_CIPH_MODE) == EVP_CIPH_OFB_MODE
|| enc)
ret=AES_set_encrypt_key(key, ctx->key_len * 8, ctx->cipher_data);
else
ret=AES_set_decrypt_key(key, ctx->key_len * 8, ctx->cipher_data);
if(ret < 0)
{
EVPerr(EVP_F_AES_INIT_KEY,EVP_R_AES_KEY_SETUP_FAILED);
return 0;
}
return 1;
}
