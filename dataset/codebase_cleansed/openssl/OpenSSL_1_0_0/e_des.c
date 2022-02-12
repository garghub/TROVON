static int des_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
BLOCK_CIPHER_ecb_loop()
DES_ecb_encrypt((DES_cblock *)(in + i), (DES_cblock *)(out + i), ctx->cipher_data, ctx->encrypt);
return 1;
}
static int des_ofb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
while(inl>=EVP_MAXCHUNK)
{
DES_ofb64_encrypt(in, out, (long)EVP_MAXCHUNK, ctx->cipher_data,
(DES_cblock *)ctx->iv, &ctx->num);
inl-=EVP_MAXCHUNK;
in +=EVP_MAXCHUNK;
out+=EVP_MAXCHUNK;
}
if (inl)
DES_ofb64_encrypt(in, out, (long)inl, ctx->cipher_data,
(DES_cblock *)ctx->iv, &ctx->num);
return 1;
}
static int des_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
while(inl>=EVP_MAXCHUNK)
{
DES_ncbc_encrypt(in, out, (long)EVP_MAXCHUNK, ctx->cipher_data,
(DES_cblock *)ctx->iv, ctx->encrypt);
inl-=EVP_MAXCHUNK;
in +=EVP_MAXCHUNK;
out+=EVP_MAXCHUNK;
}
if (inl)
DES_ncbc_encrypt(in, out, (long)inl, ctx->cipher_data,
(DES_cblock *)ctx->iv, ctx->encrypt);
return 1;
}
static int des_cfb64_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
while(inl>=EVP_MAXCHUNK)
{
DES_cfb64_encrypt(in,out, (long)EVP_MAXCHUNK, ctx->cipher_data,
(DES_cblock *)ctx->iv, &ctx->num, ctx->encrypt);
inl-=EVP_MAXCHUNK;
in +=EVP_MAXCHUNK;
out+=EVP_MAXCHUNK;
}
if (inl)
DES_cfb64_encrypt(in, out, (long)inl, ctx->cipher_data,
(DES_cblock *)ctx->iv, &ctx->num, ctx->encrypt);
return 1;
}
static int des_cfb1_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
size_t n,chunk=EVP_MAXCHUNK/8;
unsigned char c[1],d[1];
if (inl<chunk) chunk=inl;
while (inl && inl>=chunk)
{
for(n=0 ; n < chunk*8; ++n)
{
c[0]=(in[n/8]&(1 << (7-n%8))) ? 0x80 : 0;
DES_cfb_encrypt(c,d,1,1,ctx->cipher_data,(DES_cblock *)ctx->iv,
ctx->encrypt);
out[n/8]=(out[n/8]&~(0x80 >> (unsigned int)(n%8))) |
((d[0]&0x80) >> (unsigned int)(n%8));
}
inl-=chunk;
in +=chunk;
out+=chunk;
if (inl<chunk) chunk=inl;
}
return 1;
}
static int des_cfb8_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
while (inl>=EVP_MAXCHUNK)
{
DES_cfb_encrypt(in,out,8,(long)EVP_MAXCHUNK,ctx->cipher_data,
(DES_cblock *)ctx->iv,ctx->encrypt);
inl-=EVP_MAXCHUNK;
in +=EVP_MAXCHUNK;
out+=EVP_MAXCHUNK;
}
if (inl)
DES_cfb_encrypt(in,out,8,(long)inl,ctx->cipher_data,
(DES_cblock *)ctx->iv,ctx->encrypt);
return 1;
}
static int des_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
DES_cblock *deskey = (DES_cblock *)key;
#ifdef EVP_CHECK_DES_KEY
if(DES_set_key_checked(deskey,ctx->cipher_data) != 0)
return 0;
#else
DES_set_key_unchecked(deskey,ctx->cipher_data);
#endif
return 1;
}
static int des_ctrl(EVP_CIPHER_CTX *c, int type, int arg, void *ptr)
{
switch(type)
{
case EVP_CTRL_RAND_KEY:
if (RAND_bytes(ptr, 8) <= 0)
return 0;
DES_set_odd_parity((DES_cblock *)ptr);
return 1;
default:
return -1;
}
}
