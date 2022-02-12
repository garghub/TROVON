const EVP_CIPHER *EVP_rc4(void)
{
return(&r4_cipher);
}
const EVP_CIPHER *EVP_rc4_40(void)
{
return(&r4_40_cipher);
}
static int rc4_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
RC4_set_key(&data(ctx)->ks,EVP_CIPHER_CTX_key_length(ctx),
key);
return 1;
}
static int rc4_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
RC4(&data(ctx)->ks,inl,in,out);
return 1;
}
