EVP_CIPHER *EVP_des_ede_cfb(void)
{
return(&d_ede_cfb_cipher2);
}
EVP_CIPHER *EVP_des_ede3_cfb(void)
{
return(&d_ede3_cfb_cipher3);
}
static void des_ede_cfb_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
des_cblock *deskey = (des_cblock *)key;
ctx->num=0;
if (iv != NULL)
memcpy(&(ctx->oiv[0]),iv,8);
memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),8);
if (deskey != NULL)
{
des_set_key_unchecked(&deskey[0],ctx->c.des_ede.ks1);
des_set_key_unchecked(&deskey[1],ctx->c.des_ede.ks2);
memcpy( (char *)ctx->c.des_ede.ks3,
(char *)ctx->c.des_ede.ks1,
sizeof(ctx->c.des_ede.ks1));
}
}
static void des_ede3_cfb_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
des_cblock *deskey = (des_cblock *)key;
ctx->num=0;
if (iv != NULL)
memcpy(&(ctx->oiv[0]),iv,8);
memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),8);
if (deskey != NULL)
{
des_set_key_unchecked(&deskey[0],ctx->c.des_ede.ks1);
des_set_key_unchecked(&deskey[1],ctx->c.des_ede.ks2);
des_set_key_unchecked(&deskey[2],ctx->c.des_ede.ks3);
}
}
static void des_ede_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
des_ede3_cfb64_encrypt(in,out,(long)inl,
ctx->c.des_ede.ks1,
ctx->c.des_ede.ks2,
ctx->c.des_ede.ks3,
(des_cblock*)&(ctx->iv[0]),
&ctx->num,ctx->encrypt);
}
