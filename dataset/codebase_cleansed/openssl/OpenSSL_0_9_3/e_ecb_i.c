EVP_CIPHER *EVP_idea_ecb(void)
{
return(&i_ecb_cipher);
}
static void idea_ecb_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
if (key != NULL)
{
if (enc)
idea_set_encrypt_key(key,&(ctx->c.idea_ks));
else
{
IDEA_KEY_SCHEDULE tmp;
idea_set_encrypt_key(key,&tmp);
idea_set_decrypt_key(&tmp, &(ctx->c.idea_ks));
memset((unsigned char *)&tmp,0,
sizeof(IDEA_KEY_SCHEDULE));
}
}
}
static void idea_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
unsigned int i;
if (inl < 8) return;
inl-=8;
for (i=0; i<=inl; i+=8)
{
idea_ecb_encrypt(
&(in[i]),&(out[i]),&(ctx->c.idea_ks));
}
}
