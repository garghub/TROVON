EVP_CIPHER *EVP_rc4(void)
{
return(&r4_cipher);
}
EVP_CIPHER *EVP_rc4_40(void)
{
return(&r4_40_cipher);
}
static int rc4_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
memcpy(&(ctx->c.rc4.key[0]),key,EVP_CIPHER_CTX_key_length(ctx));
RC4_set_key(&(ctx->c.rc4.ks),EVP_CIPHER_CTX_key_length(ctx),
ctx->c.rc4.key);
return 1;
}
static int rc4_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
RC4(&(ctx->c.rc4.ks),inl,in,out);
return 1;
}
