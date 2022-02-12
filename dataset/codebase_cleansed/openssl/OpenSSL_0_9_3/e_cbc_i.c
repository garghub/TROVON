EVP_CIPHER *EVP_idea_cbc(void)
{
return(&i_cbc_cipher);
}
static void idea_cbc_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
if (iv != NULL)
memcpy(&(ctx->oiv[0]),iv,8);
memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),8);
if (key != NULL)
{
if (enc)
idea_set_encrypt_key(key,&(ctx->c.idea_ks));
else
{
IDEA_KEY_SCHEDULE tmp;
idea_set_encrypt_key(key,&tmp);
idea_set_decrypt_key(&tmp,&(ctx->c.idea_ks));
memset((unsigned char *)&tmp,0,
sizeof(IDEA_KEY_SCHEDULE));
}
}
}
static void idea_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
idea_cbc_encrypt(
in,out,(long)inl,
&(ctx->c.idea_ks),&(ctx->iv[0]),
ctx->encrypt);
}
