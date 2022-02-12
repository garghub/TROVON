EVP_CIPHER *EVP_rc2_ecb(void)
{
return(&r2_ecb_cipher);
}
static void rc2_ecb_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
if (key != NULL)
RC2_set_key(&(ctx->c.rc2_ks),EVP_CIPHER_CTX_key_length(ctx),
key,EVP_CIPHER_CTX_key_length(ctx)*8);
}
static void rc2_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
unsigned int i;
if (inl < 8) return;
inl-=8;
for (i=0; i<=inl; i+=8)
{
RC2_ecb_encrypt(
&(in[i]),&(out[i]),
&(ctx->c.rc2_ks),ctx->encrypt);
}
}
