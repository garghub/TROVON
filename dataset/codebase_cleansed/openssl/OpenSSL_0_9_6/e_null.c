EVP_CIPHER *EVP_enc_null(void)
{
return(&n_cipher);
}
static int null_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
memset(&(ctx->c),0,sizeof(ctx->c));
return 1;
}
static int null_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
if (in != out)
memcpy((char *)out,(char *)in,(int)inl);
return 1;
}
