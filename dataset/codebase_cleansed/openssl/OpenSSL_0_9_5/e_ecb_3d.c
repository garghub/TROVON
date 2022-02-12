EVP_CIPHER *EVP_des_ede(void)
{
return(&d_ede_cipher2);
}
EVP_CIPHER *EVP_des_ede3(void)
{
return(&d_ede3_cipher3);
}
static void des_ede_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
des_cblock *deskey = (des_cblock *)key;
if (deskey != NULL)
{
des_set_key_unchecked(&deskey[0],ctx->c.des_ede.ks1);
des_set_key_unchecked(&deskey[1],ctx->c.des_ede.ks2);
memcpy( (char *)ctx->c.des_ede.ks3,
(char *)ctx->c.des_ede.ks1,
sizeof(ctx->c.des_ede.ks1));
}
}
static void des_ede3_init_key(EVP_CIPHER_CTX *ctx, unsigned char *key,
unsigned char *iv, int enc)
{
des_cblock *deskey = (des_cblock *)key;
if (deskey != NULL)
{
des_set_key_unchecked(&deskey[0],ctx->c.des_ede.ks1);
des_set_key_unchecked(&deskey[1],ctx->c.des_ede.ks2);
des_set_key_unchecked(&deskey[2],ctx->c.des_ede.ks3);
}
}
static void des_ede_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
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
des_ecb3_encrypt(input,output,
ctx->c.des_ede.ks1,
ctx->c.des_ede.ks2,
ctx->c.des_ede.ks3,
ctx->encrypt);
}
}
