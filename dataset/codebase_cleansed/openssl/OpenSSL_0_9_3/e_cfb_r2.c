EVP_CIPHER *EVP_rc2_cfb(void)
{
return(&r2_cfb_cipher);
}
static void rc2_cfb_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
ctx->num=0;
if (iv != NULL)
memcpy(&(ctx->oiv[0]),iv,8);
memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),8);
if (key != NULL)
RC2_set_key(&(ctx->c.rc2_ks),EVP_CIPHER_CTX_key_length(ctx),
key,EVP_CIPHER_CTX_key_length(ctx)*8);
}
static void rc2_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
RC2_cfb64_encrypt(
in,out,
(long)inl, &(ctx->c.rc2_ks),
&(ctx->iv[0]),
&ctx->num,ctx->encrypt);
}
