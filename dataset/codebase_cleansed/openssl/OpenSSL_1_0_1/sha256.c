unsigned char *SHA224(const unsigned char *d, size_t n, unsigned char *md)
{
SHA256_CTX c;
static unsigned char m[SHA224_DIGEST_LENGTH];
if (md == NULL) md=m;
SHA224_Init(&c);
SHA256_Update(&c,d,n);
SHA256_Final(md,&c);
OPENSSL_cleanse(&c,sizeof(c));
return(md);
}
unsigned char *SHA256(const unsigned char *d, size_t n, unsigned char *md)
{
SHA256_CTX c;
static unsigned char m[SHA256_DIGEST_LENGTH];
if (md == NULL) md=m;
SHA256_Init(&c);
SHA256_Update(&c,d,n);
SHA256_Final(md,&c);
OPENSSL_cleanse(&c,sizeof(c));
return(md);
}
int SHA224_Update(SHA256_CTX *c, const void *data, size_t len)
{ return SHA256_Update (c,data,len); }
int SHA224_Final (unsigned char *md, SHA256_CTX *c)
{ return SHA256_Final (md,c); }
static void sha256_block_data_order (SHA256_CTX *ctx, const void *in, size_t num)
{
unsigned MD32_REG_T a,b,c,d,e,f,g,h,s0,s1,T1,T2;
SHA_LONG X[16],l;
int i;
const unsigned char *data=in;
while (num--) {
a = ctx->h[0]; b = ctx->h[1]; c = ctx->h[2]; d = ctx->h[3];
e = ctx->h[4]; f = ctx->h[5]; g = ctx->h[6]; h = ctx->h[7];
for (i=0;i<16;i++)
{
HOST_c2l(data,l); T1 = X[i] = l;
T1 += h + Sigma1(e) + Ch(e,f,g) + K256[i];
T2 = Sigma0(a) + Maj(a,b,c);
h = g; g = f; f = e; e = d + T1;
d = c; c = b; b = a; a = T1 + T2;
}
for (;i<64;i++)
{
s0 = X[(i+1)&0x0f]; s0 = sigma0(s0);
s1 = X[(i+14)&0x0f]; s1 = sigma1(s1);
T1 = X[i&0xf] += s0 + s1 + X[(i+9)&0xf];
T1 += h + Sigma1(e) + Ch(e,f,g) + K256[i];
T2 = Sigma0(a) + Maj(a,b,c);
h = g; g = f; f = e; e = d + T1;
d = c; c = b; b = a; a = T1 + T2;
}
ctx->h[0] += a; ctx->h[1] += b; ctx->h[2] += c; ctx->h[3] += d;
ctx->h[4] += e; ctx->h[5] += f; ctx->h[6] += g; ctx->h[7] += h;
}
}
static void sha256_block_data_order (SHA256_CTX *ctx, const void *in, size_t num)
{
unsigned MD32_REG_T a,b,c,d,e,f,g,h,s0,s1,T1;
SHA_LONG X[16];
int i;
const unsigned char *data=in;
const union { long one; char little; } is_endian = {1};
while (num--) {
a = ctx->h[0]; b = ctx->h[1]; c = ctx->h[2]; d = ctx->h[3];
e = ctx->h[4]; f = ctx->h[5]; g = ctx->h[6]; h = ctx->h[7];
if (!is_endian.little && sizeof(SHA_LONG)==4 && ((size_t)in%4)==0)
{
const SHA_LONG *W=(const SHA_LONG *)data;
T1 = X[0] = W[0]; ROUND_00_15(0,a,b,c,d,e,f,g,h);
T1 = X[1] = W[1]; ROUND_00_15(1,h,a,b,c,d,e,f,g);
T1 = X[2] = W[2]; ROUND_00_15(2,g,h,a,b,c,d,e,f);
T1 = X[3] = W[3]; ROUND_00_15(3,f,g,h,a,b,c,d,e);
T1 = X[4] = W[4]; ROUND_00_15(4,e,f,g,h,a,b,c,d);
T1 = X[5] = W[5]; ROUND_00_15(5,d,e,f,g,h,a,b,c);
T1 = X[6] = W[6]; ROUND_00_15(6,c,d,e,f,g,h,a,b);
T1 = X[7] = W[7]; ROUND_00_15(7,b,c,d,e,f,g,h,a);
T1 = X[8] = W[8]; ROUND_00_15(8,a,b,c,d,e,f,g,h);
T1 = X[9] = W[9]; ROUND_00_15(9,h,a,b,c,d,e,f,g);
T1 = X[10] = W[10]; ROUND_00_15(10,g,h,a,b,c,d,e,f);
T1 = X[11] = W[11]; ROUND_00_15(11,f,g,h,a,b,c,d,e);
T1 = X[12] = W[12]; ROUND_00_15(12,e,f,g,h,a,b,c,d);
T1 = X[13] = W[13]; ROUND_00_15(13,d,e,f,g,h,a,b,c);
T1 = X[14] = W[14]; ROUND_00_15(14,c,d,e,f,g,h,a,b);
T1 = X[15] = W[15]; ROUND_00_15(15,b,c,d,e,f,g,h,a);
data += SHA256_CBLOCK;
}
else
{
SHA_LONG l;
HOST_c2l(data,l); T1 = X[0] = l; ROUND_00_15(0,a,b,c,d,e,f,g,h);
HOST_c2l(data,l); T1 = X[1] = l; ROUND_00_15(1,h,a,b,c,d,e,f,g);
HOST_c2l(data,l); T1 = X[2] = l; ROUND_00_15(2,g,h,a,b,c,d,e,f);
HOST_c2l(data,l); T1 = X[3] = l; ROUND_00_15(3,f,g,h,a,b,c,d,e);
HOST_c2l(data,l); T1 = X[4] = l; ROUND_00_15(4,e,f,g,h,a,b,c,d);
HOST_c2l(data,l); T1 = X[5] = l; ROUND_00_15(5,d,e,f,g,h,a,b,c);
HOST_c2l(data,l); T1 = X[6] = l; ROUND_00_15(6,c,d,e,f,g,h,a,b);
HOST_c2l(data,l); T1 = X[7] = l; ROUND_00_15(7,b,c,d,e,f,g,h,a);
HOST_c2l(data,l); T1 = X[8] = l; ROUND_00_15(8,a,b,c,d,e,f,g,h);
HOST_c2l(data,l); T1 = X[9] = l; ROUND_00_15(9,h,a,b,c,d,e,f,g);
HOST_c2l(data,l); T1 = X[10] = l; ROUND_00_15(10,g,h,a,b,c,d,e,f);
HOST_c2l(data,l); T1 = X[11] = l; ROUND_00_15(11,f,g,h,a,b,c,d,e);
HOST_c2l(data,l); T1 = X[12] = l; ROUND_00_15(12,e,f,g,h,a,b,c,d);
HOST_c2l(data,l); T1 = X[13] = l; ROUND_00_15(13,d,e,f,g,h,a,b,c);
HOST_c2l(data,l); T1 = X[14] = l; ROUND_00_15(14,c,d,e,f,g,h,a,b);
HOST_c2l(data,l); T1 = X[15] = l; ROUND_00_15(15,b,c,d,e,f,g,h,a);
}
for (i=16;i<64;i+=8)
{
ROUND_16_63(i+0,a,b,c,d,e,f,g,h,X);
ROUND_16_63(i+1,h,a,b,c,d,e,f,g,X);
ROUND_16_63(i+2,g,h,a,b,c,d,e,f,X);
ROUND_16_63(i+3,f,g,h,a,b,c,d,e,X);
ROUND_16_63(i+4,e,f,g,h,a,b,c,d,X);
ROUND_16_63(i+5,d,e,f,g,h,a,b,c,X);
ROUND_16_63(i+6,c,d,e,f,g,h,a,b,X);
ROUND_16_63(i+7,b,c,d,e,f,g,h,a,X);
}
ctx->h[0] += a; ctx->h[1] += b; ctx->h[2] += c; ctx->h[3] += d;
ctx->h[4] += e; ctx->h[5] += f; ctx->h[6] += g; ctx->h[7] += h;
}
}
