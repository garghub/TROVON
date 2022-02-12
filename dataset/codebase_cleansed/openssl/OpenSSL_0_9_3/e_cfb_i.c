EVP_CIPHER *EVP_idea_cfb(void)
{
return(&i_cfb_cipher);
}
static void idea_cfb_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
ctx->num=0;
if (iv != NULL)
memcpy(&(ctx->oiv[0]),iv,8);
memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),8);
if (key != NULL)
idea_set_encrypt_key(key,&(ctx->c.idea_ks));
}
static void idea_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
idea_cfb64_encrypt(
in,out,(long)inl,
&(ctx->c.idea_ks),&(ctx->iv[0]),
&ctx->num,ctx->encrypt);
}
