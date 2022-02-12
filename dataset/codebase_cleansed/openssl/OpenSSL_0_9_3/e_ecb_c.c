EVP_CIPHER *EVP_cast5_ecb(void)
{
return(&cast5_ecb_cipher);
}
static void cast_ecb_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
if (key != NULL)
CAST_set_key(&(ctx->c.cast_ks),EVP_CAST5_KEY_SIZE,key);
}
static void cast_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
unsigned int i;
if (inl < 8) return;
inl-=8;
for (i=0; i<=inl; i+=8)
{
CAST_ecb_encrypt(
&(in[i]),&(out[i]),
&(ctx->c.cast_ks),ctx->encrypt);
}
}
