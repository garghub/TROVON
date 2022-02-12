EVP_CIPHER *EVP_rc5_32_12_16_ecb(void)
{
return(&rc5_ecb_cipher);
}
static void rc5_32_12_16_ecb_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
if (key != NULL)
RC5_32_set_key(&(ctx->c.rc5_ks),EVP_RC5_32_12_16_KEY_SIZE,key,
RC5_12_ROUNDS);
}
static void rc5_32_12_16_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
unsigned int i;
if (inl < 8) return;
inl-=8;
for (i=0; i<=inl; i+=8)
{
RC5_32_ecb_encrypt(
&(in[i]),&(out[i]),
&(ctx->c.rc5_ks),ctx->encrypt);
}
}
