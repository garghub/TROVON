EVP_CIPHER *EVP_bf_cbc(void)
{
return(&bfish_cbc_cipher);
}
static void bf_cbc_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
if (iv != NULL)
memcpy(&(ctx->oiv[0]),iv,8);
memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),8);
if (key != NULL)
BF_set_key(&(ctx->c.bf_ks),EVP_BLOWFISH_KEY_SIZE,key);
}
static void bf_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
BF_cbc_encrypt(
in,out,(long)inl,
&(ctx->c.bf_ks),&(ctx->iv[0]),
ctx->encrypt);
}
