static int des_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
BLOCK_CIPHER_ecb_loop()
des_ecb_encrypt((des_cblock *)(in + i), (des_cblock *)(out + i), ctx->c.des_ks, ctx->encrypt);
return 1;
}
static int des_ofb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
des_ofb64_encrypt(in, out, (long)inl, ctx->c.des_ks, (des_cblock *)ctx->iv, &ctx->num);
return 1;
}
static int des_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
des_ncbc_encrypt(in, out, (long)inl, ctx->c.des_ks,
(des_cblock *)ctx->iv, ctx->encrypt);
return 1;
}
static int des_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
des_cfb64_encrypt(in, out, (long)inl, ctx->c.des_ks,
(des_cblock *)ctx->iv, &ctx->num, ctx->encrypt);
return 1;
}
static int des_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
des_cblock *deskey = (des_cblock *)key;
des_set_key_unchecked(deskey,ctx->c.des_ks);
return 1;
}
