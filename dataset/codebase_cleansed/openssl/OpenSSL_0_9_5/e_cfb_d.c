EVP_CIPHER *EVP_des_cfb(void)
{
return(&d_cfb_cipher);
}
static void des_cfb_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
des_cblock *deskey = (des_cblock *)key;
ctx->num=0;
if (iv != NULL)
memcpy(&(ctx->oiv[0]),iv,8);
memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),8);
if (deskey != NULL)
des_set_key_unchecked(deskey,ctx->c.des_ks);
}
static void des_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
des_cfb64_encrypt(
in,out,
(long)inl, ctx->c.des_ks,
(des_cblock *)&(ctx->iv[0]),
&ctx->num,ctx->encrypt);
}
