EVP_CIPHER *EVP_cast5_cbc(void)
{
return(&cast5_cbc_cipher);
}
static void cast_cbc_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
if (iv != NULL)
memcpy(&(ctx->oiv[0]),iv,8);
memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),8);
if (key != NULL)
CAST_set_key(&(ctx->c.cast_ks),EVP_CAST5_KEY_SIZE,key);
}
static void cast_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
CAST_cbc_encrypt(
in,out,(long)inl,
&(ctx->c.cast_ks),&(ctx->iv[0]),
ctx->encrypt);
}
