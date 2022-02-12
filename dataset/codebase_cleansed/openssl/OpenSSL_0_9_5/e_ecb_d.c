EVP_CIPHER *EVP_des_ecb(void)
{
return(&d_ecb_cipher);
}
static void des_ecb_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
des_cblock *deskey = (des_cblock *)key;
if (deskey != NULL)
des_set_key_unchecked(deskey,ctx->c.des_ks);
}
static void des_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
unsigned char *in, unsigned int inl)
{
unsigned int i;
des_cblock *output ;
des_cblock *input ;
if (inl < 8) return;
inl-=8;
for (i=0; i<=inl; i+=8)
{
output = (des_cblock *)(out + i);
input = (des_cblock *)(in + i);
des_ecb_encrypt(input,output,ctx->c.des_ks,ctx->encrypt);
}
}
