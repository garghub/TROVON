EVP_CIPHER *EVP_bf_ecb(void)
{
return(&bfish_ecb_cipher);
}
static void bf_ecb_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
if (key != NULL)
BF_set_key(&(ctx->c.bf_ks),EVP_BLOWFISH_KEY_SIZE,key);
}
static void bf_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
unsigned int i;
if (inl < 8) return;
inl-=8;
for (i=0; i<=inl; i+=8)
{
BF_ecb_encrypt(
&(in[i]),&(out[i]),
&(ctx->c.bf_ks),ctx->encrypt);
}
}
