static int des_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
BLOCK_CIPHER_ecb_loop()
DES_ecb_encrypt((DES_cblock *)(in + i), (DES_cblock *)(out + i), ctx->cipher_data, ctx->encrypt);
return 1;
}
static int des_ofb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
DES_ofb64_encrypt(in, out, (long)inl, ctx->cipher_data, (DES_cblock *)ctx->iv, &ctx->num);
return 1;
}
static int des_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
DES_ncbc_encrypt(in, out, (long)inl, ctx->cipher_data,
(DES_cblock *)ctx->iv, ctx->encrypt);
return 1;
}
static int des_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
DES_cfb64_encrypt(in, out, (long)inl, ctx->cipher_data,
(DES_cblock *)ctx->iv, &ctx->num, ctx->encrypt);
return 1;
}
static int des_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
DES_cblock *deskey = (DES_cblock *)key;
DES_set_key_unchecked(deskey,ctx->cipher_data);
return 1;
}
