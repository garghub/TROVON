EVP_CIPHER *EVP_des_cbc(void)
{
return(&d_cbc_cipher);
}
static void des_cbc_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
des_cblock *deskey = (des_cblock *)key;
if (iv != NULL)
memcpy(&(ctx->oiv[0]),iv,8);
memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),8);
if (deskey != NULL)
des_set_key(deskey,ctx->c.des_ks);
}
static void des_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
des_ncbc_encrypt(in,out,inl,ctx->c.des_ks,
(des_cblock *)&(ctx->iv[0]),
ctx->encrypt);
}
