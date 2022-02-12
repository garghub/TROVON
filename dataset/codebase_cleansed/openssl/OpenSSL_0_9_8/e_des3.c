static int des_ede_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
BLOCK_CIPHER_ecb_loop()
DES_ecb3_encrypt((const_DES_cblock *)(in + i),
(DES_cblock *)(out + i),
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
static int des_ede_cfb64_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
DES_ede3_cfb64_encrypt(in, out, (long)inl,
&data(ctx)->ks1, &data(ctx)->ks2, &data(ctx)->ks3,
(DES_cblock *)ctx->iv, &ctx->num, ctx->encrypt);
return 1;
}
static int des_ede3_cfb1_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
unsigned int n;
unsigned char c[1],d[1];
for(n=0 ; n < inl ; ++n)
{
c[0]=(in[n/8]&(1 << (7-n%8))) ? 0x80 : 0;
DES_ede3_cfb_encrypt(c,d,1,1,
&data(ctx)->ks1,&data(ctx)->ks2,&data(ctx)->ks3,
(DES_cblock *)ctx->iv,ctx->encrypt);
out[n/8]=(out[n/8]&~(0x80 >> (n%8)))|((d[0]&0x80) >> (n%8));
}
return 1;
}
static int des_ede3_cfb8_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
DES_ede3_cfb_encrypt(in,out,8,inl,
&data(ctx)->ks1,&data(ctx)->ks2,&data(ctx)->ks3,
(DES_cblock *)ctx->iv,ctx->encrypt);
return 1;
}
static int des_ede_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
DES_cblock *deskey = (DES_cblock *)key;
#ifdef EVP_CHECK_DES_KEY
if (DES_set_key_checked(&deskey[0],&data(ctx)->ks1)
!! DES_set_key_checked(&deskey[1],&data(ctx)->ks2))
return 0;
#else
DES_set_key_unchecked(&deskey[0],&data(ctx)->ks1);
DES_set_key_unchecked(&deskey[1],&data(ctx)->ks2);
#endif
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
#ifdef EVP_CHECK_DES_KEY
if (DES_set_key_checked(&deskey[0],&data(ctx)->ks1)
|| DES_set_key_checked(&deskey[1],&data(ctx)->ks2)
|| DES_set_key_checked(&deskey[2],&data(ctx)->ks3))
return 0;
#else
DES_set_key_unchecked(&deskey[0],&data(ctx)->ks1);
DES_set_key_unchecked(&deskey[1],&data(ctx)->ks2);
DES_set_key_unchecked(&deskey[2],&data(ctx)->ks3);
#endif
return 1;
}
static int des3_ctrl(EVP_CIPHER_CTX *c, int type, int arg, void *ptr)
{
DES_cblock *deskey = ptr;
switch(type)
{
case EVP_CTRL_RAND_KEY:
if (RAND_bytes(ptr, c->key_len) <= 0)
return 0;
DES_set_odd_parity(deskey);
if (c->key_len >= 16)
DES_set_odd_parity(deskey + 1);
if (c->key_len >= 24)
DES_set_odd_parity(deskey + 2);
return 1;
default:
return -1;
}
}
const EVP_CIPHER *EVP_des_ede(void)
{
return &des_ede_ecb;
}
const EVP_CIPHER *EVP_des_ede3(void)
{
return &des_ede3_ecb;
}
