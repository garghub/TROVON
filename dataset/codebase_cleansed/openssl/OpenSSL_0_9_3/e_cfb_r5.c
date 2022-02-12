EVP_CIPHER *EVP_rc5_32_12_16_cfb(void)
{
return(&rc5_cfb_cipher);
}
static void rc5_32_12_16_cfb_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
ctx->num=0;
if (iv != NULL)
memcpy(&(ctx->oiv[0]),iv,8);
memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),8);
if (key != NULL)
RC5_32_set_key(&(ctx->c.rc5_ks),EVP_RC5_32_12_16_KEY_SIZE,key,
RC5_12_ROUNDS);
}
static void rc5_32_12_16_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
RC5_32_cfb64_encrypt(
in,out,
(long)inl, &(ctx->c.rc5_ks),
&(ctx->iv[0]),
&ctx->num,ctx->encrypt);
}
