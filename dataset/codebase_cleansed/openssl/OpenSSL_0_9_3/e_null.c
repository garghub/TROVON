EVP_CIPHER *EVP_enc_null(void)
{
return(&n_cipher);
}
static void null_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
memset(&(ctx->c),0,sizeof(ctx->c));
}
static void null_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
if (in != out)
memcpy((char *)out,(char *)in,(int)inl);
}
