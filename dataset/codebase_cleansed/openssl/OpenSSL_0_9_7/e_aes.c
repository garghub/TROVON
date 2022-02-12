static int aes_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc) {
if ((ctx->cipher->flags & EVP_CIPH_MODE) == EVP_CIPH_CFB_MODE
|| (ctx->cipher->flags & EVP_CIPH_MODE) == EVP_CIPH_OFB_MODE
|| enc)
AES_set_encrypt_key(key, ctx->key_len * 8, ctx->cipher_data);
else
AES_set_decrypt_key(key, ctx->key_len * 8, ctx->cipher_data);
return 1;
}
