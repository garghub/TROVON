EVP_CIPHER *EVP_desx_cbc(void)
{
return(&d_xcbc_cipher);
}
static void desx_cbc_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
des_cblock *deskey = (des_cblock *)key;
if (iv != NULL)
memcpy(&(ctx->oiv[0]),iv,8);
memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),8);
if (deskey != NULL)
{
des_set_key_unchecked(deskey,ctx->c.desx_cbc.ks);
memcpy(&(ctx->c.desx_cbc.inw[0]),&(key[8]),8);
memcpy(&(ctx->c.desx_cbc.outw[0]),&(key[16]),8);
}
}
static void desx_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
des_xcbc_encrypt(in,out,inl,ctx->c.desx_cbc.ks,
(des_cblock *)&(ctx->iv[0]),
&ctx->c.desx_cbc.inw,
&ctx->c.desx_cbc.outw,
ctx->encrypt);
}
