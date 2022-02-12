static int idea_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
BLOCK_CIPHER_ecb_loop()
idea_ecb_encrypt(in + i, out + i, ctx->cipher_data);
return 1;
}
static int idea_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
if(!enc) {
if (EVP_CIPHER_CTX_mode(ctx) == EVP_CIPH_OFB_MODE) enc = 1;
else if (EVP_CIPHER_CTX_mode(ctx) == EVP_CIPH_CFB_MODE) enc = 1;
}
if (enc) idea_set_encrypt_key(key,ctx->cipher_data);
else
{
IDEA_KEY_SCHEDULE tmp;
idea_set_encrypt_key(key,&tmp);
idea_set_decrypt_key(&tmp,ctx->cipher_data);
OPENSSL_cleanse((unsigned char *)&tmp,
sizeof(IDEA_KEY_SCHEDULE));
}
return 1;
}
