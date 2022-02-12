const EVP_CIPHER *EVP_desx_cbc(void)
{
return (&d_xcbc_cipher);
}
static int desx_cbc_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
DES_cblock *deskey = (DES_cblock *)key;
DES_set_key_unchecked(deskey, &data(ctx)->ks);
memcpy(&data(ctx)->inw[0], &key[8], 8);
memcpy(&data(ctx)->outw[0], &key[16], 8);
return 1;
}
static int desx_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
while (inl >= EVP_MAXCHUNK) {
DES_xcbc_encrypt(in, out, (long)EVP_MAXCHUNK, &data(ctx)->ks,
(DES_cblock *)&(ctx->iv[0]),
&data(ctx)->inw, &data(ctx)->outw, ctx->encrypt);
inl -= EVP_MAXCHUNK;
in += EVP_MAXCHUNK;
out += EVP_MAXCHUNK;
}
if (inl)
DES_xcbc_encrypt(in, out, (long)inl, &data(ctx)->ks,
(DES_cblock *)&(ctx->iv[0]),
&data(ctx)->inw, &data(ctx)->outw, ctx->encrypt);
return 1;
}
