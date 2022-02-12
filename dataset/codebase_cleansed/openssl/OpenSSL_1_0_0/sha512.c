int SHA384_Init (SHA512_CTX *c)
{
#if defined(SHA512_ASM) && (defined(__arm__) || defined(__arm))
unsigned int *h = (unsigned int *)c->h;
h[0] = 0xcbbb9d5d; h[1] = 0xc1059ed8;
h[2] = 0x629a292a; h[3] = 0x367cd507;
h[4] = 0x9159015a; h[5] = 0x3070dd17;
h[6] = 0x152fecd8; h[7] = 0xf70e5939;
h[8] = 0x67332667; h[9] = 0xffc00b31;
h[10] = 0x8eb44a87; h[11] = 0x68581511;
h[12] = 0xdb0c2e0d; h[13] = 0x64f98fa7;
h[14] = 0x47b5481d; h[15] = 0xbefa4fa4;
#else
c->h[0]=U64(0xcbbb9d5dc1059ed8);
c->h[1]=U64(0x629a292a367cd507);
c->h[2]=U64(0x9159015a3070dd17);
c->h[3]=U64(0x152fecd8f70e5939);
c->h[4]=U64(0x67332667ffc00b31);
c->h[5]=U64(0x8eb44a8768581511);
c->h[6]=U64(0xdb0c2e0d64f98fa7);
c->h[7]=U64(0x47b5481dbefa4fa4);
#endif
c->Nl=0; c->Nh=0;
c->num=0; c->md_len=SHA384_DIGEST_LENGTH;
return 1;
}
int SHA512_Init (SHA512_CTX *c)
{
#if defined(SHA512_ASM) && (defined(__arm__) || defined(__arm))
unsigned int *h = (unsigned int *)c->h;
h[0] = 0x6a09e667; h[1] = 0xf3bcc908;
h[2] = 0xbb67ae85; h[3] = 0x84caa73b;
h[4] = 0x3c6ef372; h[5] = 0xfe94f82b;
h[6] = 0xa54ff53a; h[7] = 0x5f1d36f1;
h[8] = 0x510e527f; h[9] = 0xade682d1;
h[10] = 0x9b05688c; h[11] = 0x2b3e6c1f;
h[12] = 0x1f83d9ab; h[13] = 0xfb41bd6b;
h[14] = 0x5be0cd19; h[15] = 0x137e2179;
#else
c->h[0]=U64(0x6a09e667f3bcc908);
c->h[1]=U64(0xbb67ae8584caa73b);
c->h[2]=U64(0x3c6ef372fe94f82b);
c->h[3]=U64(0xa54ff53a5f1d36f1);
c->h[4]=U64(0x510e527fade682d1);
c->h[5]=U64(0x9b05688c2b3e6c1f);
c->h[6]=U64(0x1f83d9abfb41bd6b);
c->h[7]=U64(0x5be0cd19137e2179);
#endif
c->Nl=0; c->Nh=0;
c->num=0; c->md_len=SHA512_DIGEST_LENGTH;
return 1;
}
int SHA512_Final (unsigned char *md, SHA512_CTX *c)
{
unsigned char *p=(unsigned char *)c->u.p;
size_t n=c->num;
p[n]=0x80;
n++;
if (n > (sizeof(c->u)-16))
memset (p+n,0,sizeof(c->u)-n), n=0,
sha512_block_data_order (c,p,1);
memset (p+n,0,sizeof(c->u)-16-n);
#ifdef B_ENDIAN
c->u.d[SHA_LBLOCK-2] = c->Nh;
c->u.d[SHA_LBLOCK-1] = c->Nl;
#else
p[sizeof(c->u)-1] = (unsigned char)(c->Nl);
p[sizeof(c->u)-2] = (unsigned char)(c->Nl>>8);
p[sizeof(c->u)-3] = (unsigned char)(c->Nl>>16);
p[sizeof(c->u)-4] = (unsigned char)(c->Nl>>24);
p[sizeof(c->u)-5] = (unsigned char)(c->Nl>>32);
p[sizeof(c->u)-6] = (unsigned char)(c->Nl>>40);
p[sizeof(c->u)-7] = (unsigned char)(c->Nl>>48);
p[sizeof(c->u)-8] = (unsigned char)(c->Nl>>56);
p[sizeof(c->u)-9] = (unsigned char)(c->Nh);
p[sizeof(c->u)-10] = (unsigned char)(c->Nh>>8);
p[sizeof(c->u)-11] = (unsigned char)(c->Nh>>16);
p[sizeof(c->u)-12] = (unsigned char)(c->Nh>>24);
p[sizeof(c->u)-13] = (unsigned char)(c->Nh>>32);
p[sizeof(c->u)-14] = (unsigned char)(c->Nh>>40);
p[sizeof(c->u)-15] = (unsigned char)(c->Nh>>48);
p[sizeof(c->u)-16] = (unsigned char)(c->Nh>>56);
#endif
sha512_block_data_order (c,p,1);
if (md==0) return 0;
#if defined(SHA512_ASM) && (defined(__arm__) || defined(__arm))
n = c->md_len;
if (n == SHA384_DIGEST_LENGTH || n == SHA512_DIGEST_LENGTH)
{
unsigned int *h = (unsigned int *)c->h, t;
for (n/=4;n;n--)
{
t = *(h++);
*(md++) = (unsigned char)(t>>24);
*(md++) = (unsigned char)(t>>16);
*(md++) = (unsigned char)(t>>8);
*(md++) = (unsigned char)(t);
}
}
else return 0;
#else
switch (c->md_len)
{
case SHA384_DIGEST_LENGTH:
for (n=0;n<SHA384_DIGEST_LENGTH/8;n++)
{
SHA_LONG64 t = c->h[n];
*(md++) = (unsigned char)(t>>56);
*(md++) = (unsigned char)(t>>48);
*(md++) = (unsigned char)(t>>40);
*(md++) = (unsigned char)(t>>32);
*(md++) = (unsigned char)(t>>24);
*(md++) = (unsigned char)(t>>16);
*(md++) = (unsigned char)(t>>8);
*(md++) = (unsigned char)(t);
}
break;
case SHA512_DIGEST_LENGTH:
for (n=0;n<SHA512_DIGEST_LENGTH/8;n++)
{
SHA_LONG64 t = c->h[n];
*(md++) = (unsigned char)(t>>56);
*(md++) = (unsigned char)(t>>48);
*(md++) = (unsigned char)(t>>40);
*(md++) = (unsigned char)(t>>32);
*(md++) = (unsigned char)(t>>24);
*(md++) = (unsigned char)(t>>16);
*(md++) = (unsigned char)(t>>8);
*(md++) = (unsigned char)(t);
}
break;
default: return 0;
}
#endif
return 1;
}
int SHA384_Final (unsigned char *md,SHA512_CTX *c)
{ return SHA512_Final (md,c); }
int SHA512_Update (SHA512_CTX *c, const void *_data, size_t len)
{
SHA_LONG64 l;
unsigned char *p=c->u.p;
const unsigned char *data=(const unsigned char *)_data;
if (len==0) return 1;
l = (c->Nl+(((SHA_LONG64)len)<<3))&U64(0xffffffffffffffff);
if (l < c->Nl) c->Nh++;
if (sizeof(len)>=8) c->Nh+=(((SHA_LONG64)len)>>61);
c->Nl=l;
if (c->num != 0)
{
size_t n = sizeof(c->u) - c->num;
if (len < n)
{
memcpy (p+c->num,data,len), c->num += (unsigned int)len;
return 1;
}
else {
memcpy (p+c->num,data,n), c->num = 0;
len-=n, data+=n;
sha512_block_data_order (c,p,1);
}
}
if (len >= sizeof(c->u))
{
#ifndef SHA512_BLOCK_CAN_MANAGE_UNALIGNED_DATA
if ((size_t)data%sizeof(c->u.d[0]) != 0)
while (len >= sizeof(c->u))
memcpy (p,data,sizeof(c->u)),
sha512_block_data_order (c,p,1),
len -= sizeof(c->u),
data += sizeof(c->u);
else
#endif
sha512_block_data_order (c,data,len/sizeof(c->u)),
data += len,
len %= sizeof(c->u),
data -= len;
}
if (len != 0) memcpy (p,data,len), c->num = (int)len;
return 1;
}
int SHA384_Update (SHA512_CTX *c, const void *data, size_t len)
{ return SHA512_Update (c,data,len); }
void SHA512_Transform (SHA512_CTX *c, const unsigned char *data)
{ sha512_block_data_order (c,data,1); }
unsigned char *SHA384(const unsigned char *d, size_t n, unsigned char *md)
{
SHA512_CTX c;
static unsigned char m[SHA384_DIGEST_LENGTH];
if (md == NULL) md=m;
SHA384_Init(&c);
SHA512_Update(&c,d,n);
SHA512_Final(md,&c);
OPENSSL_cleanse(&c,sizeof(c));
return(md);
}
unsigned char *SHA512(const unsigned char *d, size_t n, unsigned char *md)
{
SHA512_CTX c;
static unsigned char m[SHA512_DIGEST_LENGTH];
if (md == NULL) md=m;
SHA512_Init(&c);
SHA512_Update(&c,d,n);
SHA512_Final(md,&c);
OPENSSL_cleanse(&c,sizeof(c));
return(md);
}
static SHA_LONG64 __fastcall __pull64be(const void *x)
{ _asm mov edx, [ecx + 0]
_asm mov eax, [ecx + 4]
_asm xchg dh,dl
_asm xchg ah,al
_asm rol edx,16
_asm rol eax,16
_asm xchg dh,dl
_asm xchg ah,al
}
static SHA_LONG64 __fastcall __pull64be(const void *x)
{ _asm mov edx, [ecx + 0]
_asm mov eax, [ecx + 4]
_asm bswap edx
_asm bswap eax
}
static void sha512_block_data_order (SHA512_CTX *ctx, const void *in, size_t num)
{
const SHA_LONG64 *W=in;
SHA_LONG64 A,E,T;
SHA_LONG64 X[9+80],*F;
int i;
while (num--) {
F = X+80;
A = ctx->h[0]; F[1] = ctx->h[1];
F[2] = ctx->h[2]; F[3] = ctx->h[3];
E = ctx->h[4]; F[5] = ctx->h[5];
F[6] = ctx->h[6]; F[7] = ctx->h[7];
for (i=0;i<16;i++,F--)
{
#ifdef B_ENDIAN
T = W[i];
#else
T = PULL64(W[i]);
#endif
F[0] = A;
F[4] = E;
F[8] = T;
T += F[7] + Sigma1(E) + Ch(E,F[5],F[6]) + K512[i];
E = F[3] + T;
A = T + Sigma0(A) + Maj(A,F[1],F[2]);
}
for (;i<80;i++,F--)
{
T = sigma0(F[8+16-1]);
T += sigma1(F[8+16-14]);
T += F[8+16] + F[8+16-9];
F[0] = A;
F[4] = E;
F[8] = T;
T += F[7] + Sigma1(E) + Ch(E,F[5],F[6]) + K512[i];
E = F[3] + T;
A = T + Sigma0(A) + Maj(A,F[1],F[2]);
}
ctx->h[0] += A; ctx->h[1] += F[1];
ctx->h[2] += F[2]; ctx->h[3] += F[3];
ctx->h[4] += E; ctx->h[5] += F[5];
ctx->h[6] += F[6]; ctx->h[7] += F[7];
W+=SHA_LBLOCK;
}
}
static void sha512_block_data_order (SHA512_CTX *ctx, const void *in, size_t num)
{
const SHA_LONG64 *W=in;
SHA_LONG64 a,b,c,d,e,f,g,h,s0,s1,T1,T2;
SHA_LONG64 X[16];
int i;
while (num--) {
a = ctx->h[0]; b = ctx->h[1]; c = ctx->h[2]; d = ctx->h[3];
e = ctx->h[4]; f = ctx->h[5]; g = ctx->h[6]; h = ctx->h[7];
for (i=0;i<16;i++)
{
#ifdef B_ENDIAN
T1 = X[i] = W[i];
#else
T1 = X[i] = PULL64(W[i]);
#endif
T1 += h + Sigma1(e) + Ch(e,f,g) + K512[i];
T2 = Sigma0(a) + Maj(a,b,c);
h = g; g = f; f = e; e = d + T1;
d = c; c = b; b = a; a = T1 + T2;
}
for (;i<80;i++)
{
s0 = X[(i+1)&0x0f]; s0 = sigma0(s0);
s1 = X[(i+14)&0x0f]; s1 = sigma1(s1);
T1 = X[i&0xf] += s0 + s1 + X[(i+9)&0xf];
T1 += h + Sigma1(e) + Ch(e,f,g) + K512[i];
T2 = Sigma0(a) + Maj(a,b,c);
h = g; g = f; f = e; e = d + T1;
d = c; c = b; b = a; a = T1 + T2;
}
ctx->h[0] += a; ctx->h[1] += b; ctx->h[2] += c; ctx->h[3] += d;
ctx->h[4] += e; ctx->h[5] += f; ctx->h[6] += g; ctx->h[7] += h;
W+=SHA_LBLOCK;
}
}
static void sha512_block_data_order (SHA512_CTX *ctx, const void *in, size_t num)
{
const SHA_LONG64 *W=in;
SHA_LONG64 a,b,c,d,e,f,g,h,s0,s1,T1;
SHA_LONG64 X[16];
int i;
while (num--) {
a = ctx->h[0]; b = ctx->h[1]; c = ctx->h[2]; d = ctx->h[3];
e = ctx->h[4]; f = ctx->h[5]; g = ctx->h[6]; h = ctx->h[7];
#ifdef B_ENDIAN
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
#else
T1 = X[0] = PULL64(W[0]); ROUND_00_15(0,a,b,c,d,e,f,g,h);
T1 = X[1] = PULL64(W[1]); ROUND_00_15(1,h,a,b,c,d,e,f,g);
T1 = X[2] = PULL64(W[2]); ROUND_00_15(2,g,h,a,b,c,d,e,f);
T1 = X[3] = PULL64(W[3]); ROUND_00_15(3,f,g,h,a,b,c,d,e);
T1 = X[4] = PULL64(W[4]); ROUND_00_15(4,e,f,g,h,a,b,c,d);
T1 = X[5] = PULL64(W[5]); ROUND_00_15(5,d,e,f,g,h,a,b,c);
T1 = X[6] = PULL64(W[6]); ROUND_00_15(6,c,d,e,f,g,h,a,b);
T1 = X[7] = PULL64(W[7]); ROUND_00_15(7,b,c,d,e,f,g,h,a);
T1 = X[8] = PULL64(W[8]); ROUND_00_15(8,a,b,c,d,e,f,g,h);
T1 = X[9] = PULL64(W[9]); ROUND_00_15(9,h,a,b,c,d,e,f,g);
T1 = X[10] = PULL64(W[10]); ROUND_00_15(10,g,h,a,b,c,d,e,f);
T1 = X[11] = PULL64(W[11]); ROUND_00_15(11,f,g,h,a,b,c,d,e);
T1 = X[12] = PULL64(W[12]); ROUND_00_15(12,e,f,g,h,a,b,c,d);
T1 = X[13] = PULL64(W[13]); ROUND_00_15(13,d,e,f,g,h,a,b,c);
T1 = X[14] = PULL64(W[14]); ROUND_00_15(14,c,d,e,f,g,h,a,b);
T1 = X[15] = PULL64(W[15]); ROUND_00_15(15,b,c,d,e,f,g,h,a);
#endif
for (i=16;i<80;i+=16)
{
ROUND_16_80(i, 0,a,b,c,d,e,f,g,h,X);
ROUND_16_80(i, 1,h,a,b,c,d,e,f,g,X);
ROUND_16_80(i, 2,g,h,a,b,c,d,e,f,X);
ROUND_16_80(i, 3,f,g,h,a,b,c,d,e,X);
ROUND_16_80(i, 4,e,f,g,h,a,b,c,d,X);
ROUND_16_80(i, 5,d,e,f,g,h,a,b,c,X);
ROUND_16_80(i, 6,c,d,e,f,g,h,a,b,X);
ROUND_16_80(i, 7,b,c,d,e,f,g,h,a,X);
ROUND_16_80(i, 8,a,b,c,d,e,f,g,h,X);
ROUND_16_80(i, 9,h,a,b,c,d,e,f,g,X);
ROUND_16_80(i,10,g,h,a,b,c,d,e,f,X);
ROUND_16_80(i,11,f,g,h,a,b,c,d,e,X);
ROUND_16_80(i,12,e,f,g,h,a,b,c,d,X);
ROUND_16_80(i,13,d,e,f,g,h,a,b,c,X);
ROUND_16_80(i,14,c,d,e,f,g,h,a,b,X);
ROUND_16_80(i,15,b,c,d,e,f,g,h,a,X);
}
ctx->h[0] += a; ctx->h[1] += b; ctx->h[2] += c; ctx->h[3] += d;
ctx->h[4] += e; ctx->h[5] += f; ctx->h[6] += g; ctx->h[7] += h;
W+=SHA_LBLOCK;
}
}
