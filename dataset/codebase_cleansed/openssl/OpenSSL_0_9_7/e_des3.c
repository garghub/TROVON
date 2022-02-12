static int des_ede_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
BLOCK_CIPHER_ecb_loop()
DES_ecb3_encrypt((DES_cblock *)(in + i), (DES_cblock *)(out + i),
&data(ctx)->ks1, &data(ctx)->ks2,
&data(ctx)->ks3,
ctx->encrypt);
return 1;
}
static int des_ede_ofb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
DES_ede3_ofb64_encrypt(in, out, (long)inl,
&data(ctx)->ks1, &data(ctx)->ks2, &data(ctx)->ks3,
(DES_cblock *)ctx->iv, &ctx->num);
return 1;
}
static int des_ede_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
#ifdef KSSL_DEBUG
{
int i;
char *cp;
printf("des_ede_cbc_cipher(ctx=%lx, buflen=%d)\n", ctx, ctx->buf_len);
printf("\t iv= ");
for(i=0;i<8;i++)
printf("%02X",ctx->iv[i]);
printf("\n");
}
#endif
DES_ede3_cbc_encrypt(in, out, (long)inl,
&data(ctx)->ks1, &data(ctx)->ks2, &data(ctx)->ks3,
(DES_cblock *)ctx->iv, ctx->encrypt);
return 1;
}
static int des_ede_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
DES_ede3_cfb64_encrypt(in, out, (long)inl,
&data(ctx)->ks1, &data(ctx)->ks2, &data(ctx)->ks3,
(DES_cblock *)ctx->iv, &ctx->num, ctx->encrypt);
return 1;
}
static int des_ede_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
DES_cblock *deskey = (DES_cblock *)key;
DES_set_key_unchecked(&deskey[0],&data(ctx)->ks1);
DES_set_key_unchecked(&deskey[1],&data(ctx)->ks2);
memcpy(&data(ctx)->ks3,&data(ctx)->ks1,
sizeof(data(ctx)->ks1));
return 1;
}
static int des_ede3_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
DES_cblock *deskey = (DES_cblock *)key;
#ifdef KSSL_DEBUG
{
int i;
printf("des_ede3_init_key(ctx=%lx)\n", ctx);
printf("\tKEY= ");
for(i=0;i<24;i++) printf("%02X",key[i]); printf("\n");
printf("\t IV= ");
for(i=0;i<8;i++) printf("%02X",iv[i]); printf("\n");
}
#endif
DES_set_key_unchecked(&deskey[0],&data(ctx)->ks1);
DES_set_key_unchecked(&deskey[1],&data(ctx)->ks2);
DES_set_key_unchecked(&deskey[2],&data(ctx)->ks3);
return 1;
}
const EVP_CIPHER *EVP_des_ede(void)
{
return &des_ede_ecb;
}
const EVP_CIPHER *EVP_des_ede3(void)
{
return &des_ede3_ecb;
}
