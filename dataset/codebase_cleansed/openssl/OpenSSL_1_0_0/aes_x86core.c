static void prefetch256(const void *table)
{
volatile unsigned long *t=(void *)table,ret;
unsigned long sum;
int i;
for (sum=0,i=0;i<256/sizeof(t[0]);i+=32/sizeof(t[0])) sum ^= t[i];
ret = sum;
}
int AES_set_encrypt_key(const unsigned char *userKey, const int bits,
AES_KEY *key) {
u32 *rk;
int i = 0;
u32 temp;
if (!userKey || !key)
return -1;
if (bits != 128 && bits != 192 && bits != 256)
return -2;
rk = key->rd_key;
if (bits==128)
key->rounds = 10;
else if (bits==192)
key->rounds = 12;
else
key->rounds = 14;
rk[0] = GETU32(userKey );
rk[1] = GETU32(userKey + 4);
rk[2] = GETU32(userKey + 8);
rk[3] = GETU32(userKey + 12);
if (bits == 128) {
while (1) {
temp = rk[3];
rk[4] = rk[0] ^
(Te4[(temp >> 8) & 0xff] ) ^
(Te4[(temp >> 16) & 0xff] << 8) ^
(Te4[(temp >> 24) ] << 16) ^
(Te4[(temp ) & 0xff] << 24) ^
rcon[i];
rk[5] = rk[1] ^ rk[4];
rk[6] = rk[2] ^ rk[5];
rk[7] = rk[3] ^ rk[6];
if (++i == 10) {
return 0;
}
rk += 4;
}
}
rk[4] = GETU32(userKey + 16);
rk[5] = GETU32(userKey + 20);
if (bits == 192) {
while (1) {
temp = rk[ 5];
rk[ 6] = rk[ 0] ^
(Te4[(temp >> 8) & 0xff] ) ^
(Te4[(temp >> 16) & 0xff] << 8) ^
(Te4[(temp >> 24) ] << 16) ^
(Te4[(temp ) & 0xff] << 24) ^
rcon[i];
rk[ 7] = rk[ 1] ^ rk[ 6];
rk[ 8] = rk[ 2] ^ rk[ 7];
rk[ 9] = rk[ 3] ^ rk[ 8];
if (++i == 8) {
return 0;
}
rk[10] = rk[ 4] ^ rk[ 9];
rk[11] = rk[ 5] ^ rk[10];
rk += 6;
}
}
rk[6] = GETU32(userKey + 24);
rk[7] = GETU32(userKey + 28);
if (bits == 256) {
while (1) {
temp = rk[ 7];
rk[ 8] = rk[ 0] ^
(Te4[(temp >> 8) & 0xff] ) ^
(Te4[(temp >> 16) & 0xff] << 8) ^
(Te4[(temp >> 24) ] << 16) ^
(Te4[(temp ) & 0xff] << 24) ^
rcon[i];
rk[ 9] = rk[ 1] ^ rk[ 8];
rk[10] = rk[ 2] ^ rk[ 9];
rk[11] = rk[ 3] ^ rk[10];
if (++i == 7) {
return 0;
}
temp = rk[11];
rk[12] = rk[ 4] ^
(Te4[(temp ) & 0xff] ) ^
(Te4[(temp >> 8) & 0xff] << 8) ^
(Te4[(temp >> 16) & 0xff] << 16) ^
(Te4[(temp >> 24) ] << 24);
rk[13] = rk[ 5] ^ rk[12];
rk[14] = rk[ 6] ^ rk[13];
rk[15] = rk[ 7] ^ rk[14];
rk += 8;
}
}
return 0;
}
int AES_set_decrypt_key(const unsigned char *userKey, const int bits,
AES_KEY *key) {
u32 *rk;
int i, j, status;
u32 temp;
status = AES_set_encrypt_key(userKey, bits, key);
if (status < 0)
return status;
rk = key->rd_key;
for (i = 0, j = 4*(key->rounds); i < j; i += 4, j -= 4) {
temp = rk[i ]; rk[i ] = rk[j ]; rk[j ] = temp;
temp = rk[i + 1]; rk[i + 1] = rk[j + 1]; rk[j + 1] = temp;
temp = rk[i + 2]; rk[i + 2] = rk[j + 2]; rk[j + 2] = temp;
temp = rk[i + 3]; rk[i + 3] = rk[j + 3]; rk[j + 3] = temp;
}
for (i = 1; i < (key->rounds); i++) {
rk += 4;
#if 1
for (j = 0; j < 4; j++) {
u32 tp1, tp2, tp4, tp8, tp9, tpb, tpd, tpe, m;
tp1 = rk[j];
m = tp1 & 0x80808080;
tp2 = ((tp1 & 0x7f7f7f7f) << 1) ^
((m - (m >> 7)) & 0x1b1b1b1b);
m = tp2 & 0x80808080;
tp4 = ((tp2 & 0x7f7f7f7f) << 1) ^
((m - (m >> 7)) & 0x1b1b1b1b);
m = tp4 & 0x80808080;
tp8 = ((tp4 & 0x7f7f7f7f) << 1) ^
((m - (m >> 7)) & 0x1b1b1b1b);
tp9 = tp8 ^ tp1;
tpb = tp9 ^ tp2;
tpd = tp9 ^ tp4;
tpe = tp8 ^ tp4 ^ tp2;
#if defined(ROTATE)
rk[j] = tpe ^ ROTATE(tpd,16) ^
ROTATE(tp9,8) ^ ROTATE(tpb,24);
#else
rk[j] = tpe ^ (tpd >> 16) ^ (tpd << 16) ^
(tp9 >> 24) ^ (tp9 << 8) ^
(tpb >> 8) ^ (tpb << 24);
#endif
}
#else
rk[0] =
Td0[Te2[(rk[0] ) & 0xff] & 0xff] ^
Td1[Te2[(rk[0] >> 8) & 0xff] & 0xff] ^
Td2[Te2[(rk[0] >> 16) & 0xff] & 0xff] ^
Td3[Te2[(rk[0] >> 24) ] & 0xff];
rk[1] =
Td0[Te2[(rk[1] ) & 0xff] & 0xff] ^
Td1[Te2[(rk[1] >> 8) & 0xff] & 0xff] ^
Td2[Te2[(rk[1] >> 16) & 0xff] & 0xff] ^
Td3[Te2[(rk[1] >> 24) ] & 0xff];
rk[2] =
Td0[Te2[(rk[2] ) & 0xff] & 0xff] ^
Td1[Te2[(rk[2] >> 8) & 0xff] & 0xff] ^
Td2[Te2[(rk[2] >> 16) & 0xff] & 0xff] ^
Td3[Te2[(rk[2] >> 24) ] & 0xff];
rk[3] =
Td0[Te2[(rk[3] ) & 0xff] & 0xff] ^
Td1[Te2[(rk[3] >> 8) & 0xff] & 0xff] ^
Td2[Te2[(rk[3] >> 16) & 0xff] & 0xff] ^
Td3[Te2[(rk[3] >> 24) ] & 0xff];
#endif
}
return 0;
}
void AES_encrypt(const unsigned char *in, unsigned char *out,
const AES_KEY *key) {
const u32 *rk;
u32 s0, s1, s2, s3, t[4];
int r;
assert(in && out && key);
rk = key->rd_key;
s0 = GETU32(in ) ^ rk[0];
s1 = GETU32(in + 4) ^ rk[1];
s2 = GETU32(in + 8) ^ rk[2];
s3 = GETU32(in + 12) ^ rk[3];
#if defined(AES_COMPACT_IN_OUTER_ROUNDS)
prefetch256(Te4);
t[0] = Te4[(s0 ) & 0xff] ^
Te4[(s1 >> 8) & 0xff] << 8 ^
Te4[(s2 >> 16) & 0xff] << 16 ^
Te4[(s3 >> 24) ] << 24;
t[1] = Te4[(s1 ) & 0xff] ^
Te4[(s2 >> 8) & 0xff] << 8 ^
Te4[(s3 >> 16) & 0xff] << 16 ^
Te4[(s0 >> 24) ] << 24;
t[2] = Te4[(s2 ) & 0xff] ^
Te4[(s3 >> 8) & 0xff] << 8 ^
Te4[(s0 >> 16) & 0xff] << 16 ^
Te4[(s1 >> 24) ] << 24;
t[3] = Te4[(s3 ) & 0xff] ^
Te4[(s0 >> 8) & 0xff] << 8 ^
Te4[(s1 >> 16) & 0xff] << 16 ^
Te4[(s2 >> 24) ] << 24;
{ int i;
u32 r0, r1, r2;
for (i = 0; i < 4; i++) {
r0 = t[i];
r1 = r0 & 0x80808080;
r2 = ((r0 & 0x7f7f7f7f) << 1) ^
((r1 - (r1 >> 7)) & 0x1b1b1b1b);
#if defined(ROTATE)
t[i] = r2 ^ ROTATE(r2,24) ^ ROTATE(r0,24) ^
ROTATE(r0,16) ^ ROTATE(r0,8);
#else
t[i] = r2 ^ ((r2 ^ r0) << 24) ^ ((r2 ^ r0) >> 8) ^
(r0 << 16) ^ (r0 >> 16) ^
(r0 << 8) ^ (r0 >> 24);
#endif
t[i] ^= rk[4+i];
}
}
#else
t[0] = Te0[(s0 ) & 0xff] ^
Te1[(s1 >> 8) & 0xff] ^
Te2[(s2 >> 16) & 0xff] ^
Te3[(s3 >> 24) ] ^
rk[4];
t[1] = Te0[(s1 ) & 0xff] ^
Te1[(s2 >> 8) & 0xff] ^
Te2[(s3 >> 16) & 0xff] ^
Te3[(s0 >> 24) ] ^
rk[5];
t[2] = Te0[(s2 ) & 0xff] ^
Te1[(s3 >> 8) & 0xff] ^
Te2[(s0 >> 16) & 0xff] ^
Te3[(s1 >> 24) ] ^
rk[6];
t[3] = Te0[(s3 ) & 0xff] ^
Te1[(s0 >> 8) & 0xff] ^
Te2[(s1 >> 16) & 0xff] ^
Te3[(s2 >> 24) ] ^
rk[7];
#endif
s0 = t[0]; s1 = t[1]; s2 = t[2]; s3 = t[3];
for (rk+=8,r=key->rounds-2; r>0; rk+=4,r--) {
#if defined(AES_COMPACT_IN_INNER_ROUNDS)
t[0] = Te4[(s0 ) & 0xff] ^
Te4[(s1 >> 8) & 0xff] << 8 ^
Te4[(s2 >> 16) & 0xff] << 16 ^
Te4[(s3 >> 24) ] << 24;
t[1] = Te4[(s1 ) & 0xff] ^
Te4[(s2 >> 8) & 0xff] << 8 ^
Te4[(s3 >> 16) & 0xff] << 16 ^
Te4[(s0 >> 24) ] << 24;
t[2] = Te4[(s2 ) & 0xff] ^
Te4[(s3 >> 8) & 0xff] << 8 ^
Te4[(s0 >> 16) & 0xff] << 16 ^
Te4[(s1 >> 24) ] << 24;
t[3] = Te4[(s3 ) & 0xff] ^
Te4[(s0 >> 8) & 0xff] << 8 ^
Te4[(s1 >> 16) & 0xff] << 16 ^
Te4[(s2 >> 24) ] << 24;
{ int i;
u32 r0, r1, r2;
for (i = 0; i < 4; i++) {
r0 = t[i];
r1 = r0 & 0x80808080;
r2 = ((r0 & 0x7f7f7f7f) << 1) ^
((r1 - (r1 >> 7)) & 0x1b1b1b1b);
#if defined(ROTATE)
t[i] = r2 ^ ROTATE(r2,24) ^ ROTATE(r0,24) ^
ROTATE(r0,16) ^ ROTATE(r0,8);
#else
t[i] = r2 ^ ((r2 ^ r0) << 24) ^ ((r2 ^ r0) >> 8) ^
(r0 << 16) ^ (r0 >> 16) ^
(r0 << 8) ^ (r0 >> 24);
#endif
t[i] ^= rk[i];
}
}
#else
t[0] = Te0[(s0 ) & 0xff] ^
Te1[(s1 >> 8) & 0xff] ^
Te2[(s2 >> 16) & 0xff] ^
Te3[(s3 >> 24) ] ^
rk[0];
t[1] = Te0[(s1 ) & 0xff] ^
Te1[(s2 >> 8) & 0xff] ^
Te2[(s3 >> 16) & 0xff] ^
Te3[(s0 >> 24) ] ^
rk[1];
t[2] = Te0[(s2 ) & 0xff] ^
Te1[(s3 >> 8) & 0xff] ^
Te2[(s0 >> 16) & 0xff] ^
Te3[(s1 >> 24) ] ^
rk[2];
t[3] = Te0[(s3 ) & 0xff] ^
Te1[(s0 >> 8) & 0xff] ^
Te2[(s1 >> 16) & 0xff] ^
Te3[(s2 >> 24) ] ^
rk[3];
#endif
s0 = t[0]; s1 = t[1]; s2 = t[2]; s3 = t[3];
}
#if defined(AES_COMPACT_IN_OUTER_ROUNDS)
prefetch256(Te4);
*(u32*)(out+0) =
Te4[(s0 ) & 0xff] ^
Te4[(s1 >> 8) & 0xff] << 8 ^
Te4[(s2 >> 16) & 0xff] << 16 ^
Te4[(s3 >> 24) ] << 24 ^
rk[0];
*(u32*)(out+4) =
Te4[(s1 ) & 0xff] ^
Te4[(s2 >> 8) & 0xff] << 8 ^
Te4[(s3 >> 16) & 0xff] << 16 ^
Te4[(s0 >> 24) ] << 24 ^
rk[1];
*(u32*)(out+8) =
Te4[(s2 ) & 0xff] ^
Te4[(s3 >> 8) & 0xff] << 8 ^
Te4[(s0 >> 16) & 0xff] << 16 ^
Te4[(s1 >> 24) ] << 24 ^
rk[2];
*(u32*)(out+12) =
Te4[(s3 ) & 0xff] ^
Te4[(s0 >> 8) & 0xff] << 8 ^
Te4[(s1 >> 16) & 0xff] << 16 ^
Te4[(s2 >> 24) ] << 24 ^
rk[3];
#else
*(u32*)(out+0) =
(Te2[(s0 ) & 0xff] & 0x000000ffU) ^
(Te3[(s1 >> 8) & 0xff] & 0x0000ff00U) ^
(Te0[(s2 >> 16) & 0xff] & 0x00ff0000U) ^
(Te1[(s3 >> 24) ] & 0xff000000U) ^
rk[0];
*(u32*)(out+4) =
(Te2[(s1 ) & 0xff] & 0x000000ffU) ^
(Te3[(s2 >> 8) & 0xff] & 0x0000ff00U) ^
(Te0[(s3 >> 16) & 0xff] & 0x00ff0000U) ^
(Te1[(s0 >> 24) ] & 0xff000000U) ^
rk[1];
*(u32*)(out+8) =
(Te2[(s2 ) & 0xff] & 0x000000ffU) ^
(Te3[(s3 >> 8) & 0xff] & 0x0000ff00U) ^
(Te0[(s0 >> 16) & 0xff] & 0x00ff0000U) ^
(Te1[(s1 >> 24) ] & 0xff000000U) ^
rk[2];
*(u32*)(out+12) =
(Te2[(s3 ) & 0xff] & 0x000000ffU) ^
(Te3[(s0 >> 8) & 0xff] & 0x0000ff00U) ^
(Te0[(s1 >> 16) & 0xff] & 0x00ff0000U) ^
(Te1[(s2 >> 24) ] & 0xff000000U) ^
rk[3];
#endif
}
void AES_decrypt(const unsigned char *in, unsigned char *out,
const AES_KEY *key) {
const u32 *rk;
u32 s0, s1, s2, s3, t[4];
int r;
assert(in && out && key);
rk = key->rd_key;
s0 = GETU32(in ) ^ rk[0];
s1 = GETU32(in + 4) ^ rk[1];
s2 = GETU32(in + 8) ^ rk[2];
s3 = GETU32(in + 12) ^ rk[3];
#if defined(AES_COMPACT_IN_OUTER_ROUNDS)
prefetch256(Td4);
t[0] = Td4[(s0 ) & 0xff] ^
Td4[(s3 >> 8) & 0xff] << 8 ^
Td4[(s2 >> 16) & 0xff] << 16 ^
Td4[(s1 >> 24) ] << 24;
t[1] = Td4[(s1 ) & 0xff] ^
Td4[(s0 >> 8) & 0xff] << 8 ^
Td4[(s3 >> 16) & 0xff] << 16 ^
Td4[(s2 >> 24) ] << 24;
t[2] = Td4[(s2 ) & 0xff] ^
Td4[(s1 >> 8) & 0xff] << 8 ^
Td4[(s0 >> 16) & 0xff] << 16 ^
Td4[(s3 >> 24) ] << 24;
t[3] = Td4[(s3 ) & 0xff] ^
Td4[(s2 >> 8) & 0xff] << 8 ^
Td4[(s1 >> 16) & 0xff] << 16 ^
Td4[(s0 >> 24) ] << 24;
{ int i;
u32 tp1, tp2, tp4, tp8, tp9, tpb, tpd, tpe, m;
for (i = 0; i < 4; i++) {
tp1 = t[i];
m = tp1 & 0x80808080;
tp2 = ((tp1 & 0x7f7f7f7f) << 1) ^
((m - (m >> 7)) & 0x1b1b1b1b);
m = tp2 & 0x80808080;
tp4 = ((tp2 & 0x7f7f7f7f) << 1) ^
((m - (m >> 7)) & 0x1b1b1b1b);
m = tp4 & 0x80808080;
tp8 = ((tp4 & 0x7f7f7f7f) << 1) ^
((m - (m >> 7)) & 0x1b1b1b1b);
tp9 = tp8 ^ tp1;
tpb = tp9 ^ tp2;
tpd = tp9 ^ tp4;
tpe = tp8 ^ tp4 ^ tp2;
#if defined(ROTATE)
t[i] = tpe ^ ROTATE(tpd,16) ^
ROTATE(tp9,8) ^ ROTATE(tpb,24);
#else
t[i] = tpe ^ (tpd >> 16) ^ (tpd << 16) ^
(tp9 >> 24) ^ (tp9 << 8) ^
(tpb >> 8) ^ (tpb << 24);
#endif
t[i] ^= rk[4+i];
}
}
#else
t[0] = Td0[(s0 ) & 0xff] ^
Td1[(s3 >> 8) & 0xff] ^
Td2[(s2 >> 16) & 0xff] ^
Td3[(s1 >> 24) ] ^
rk[4];
t[1] = Td0[(s1 ) & 0xff] ^
Td1[(s0 >> 8) & 0xff] ^
Td2[(s3 >> 16) & 0xff] ^
Td3[(s2 >> 24) ] ^
rk[5];
t[2] = Td0[(s2 ) & 0xff] ^
Td1[(s1 >> 8) & 0xff] ^
Td2[(s0 >> 16) & 0xff] ^
Td3[(s3 >> 24) ] ^
rk[6];
t[3] = Td0[(s3 ) & 0xff] ^
Td1[(s2 >> 8) & 0xff] ^
Td2[(s1 >> 16) & 0xff] ^
Td3[(s0 >> 24) ] ^
rk[7];
#endif
s0 = t[0]; s1 = t[1]; s2 = t[2]; s3 = t[3];
for (rk+=8,r=key->rounds-2; r>0; rk+=4,r--) {
#if defined(AES_COMPACT_IN_INNER_ROUNDS)
t[0] = Td4[(s0 ) & 0xff] ^
Td4[(s3 >> 8) & 0xff] << 8 ^
Td4[(s2 >> 16) & 0xff] << 16 ^
Td4[(s1 >> 24) ] << 24;
t[1] = Td4[(s1 ) & 0xff] ^
Td4[(s0 >> 8) & 0xff] << 8 ^
Td4[(s3 >> 16) & 0xff] << 16 ^
Td4[(s2 >> 24) ] << 24;
t[2] = Td4[(s2 ) & 0xff] ^
Td4[(s1 >> 8) & 0xff] << 8 ^
Td4[(s0 >> 16) & 0xff] << 16 ^
Td4[(s3 >> 24) ] << 24;
t[3] = Td4[(s3 ) & 0xff] ^
Td4[(s2 >> 8) & 0xff] << 8 ^
Td4[(s1 >> 16) & 0xff] << 16 ^
Td4[(s0 >> 24) ] << 24;
{ int i;
u32 tp1, tp2, tp4, tp8, tp9, tpb, tpd, tpe, m;
for (i = 0; i < 4; i++) {
tp1 = t[i];
m = tp1 & 0x80808080;
tp2 = ((tp1 & 0x7f7f7f7f) << 1) ^
((m - (m >> 7)) & 0x1b1b1b1b);
m = tp2 & 0x80808080;
tp4 = ((tp2 & 0x7f7f7f7f) << 1) ^
((m - (m >> 7)) & 0x1b1b1b1b);
m = tp4 & 0x80808080;
tp8 = ((tp4 & 0x7f7f7f7f) << 1) ^
((m - (m >> 7)) & 0x1b1b1b1b);
tp9 = tp8 ^ tp1;
tpb = tp9 ^ tp2;
tpd = tp9 ^ tp4;
tpe = tp8 ^ tp4 ^ tp2;
#if defined(ROTATE)
t[i] = tpe ^ ROTATE(tpd,16) ^
ROTATE(tp9,8) ^ ROTATE(tpb,24);
#else
t[i] = tpe ^ (tpd >> 16) ^ (tpd << 16) ^
(tp9 >> 24) ^ (tp9 << 8) ^
(tpb >> 8) ^ (tpb << 24);
#endif
t[i] ^= rk[i];
}
}
#else
t[0] = Td0[(s0 ) & 0xff] ^
Td1[(s3 >> 8) & 0xff] ^
Td2[(s2 >> 16) & 0xff] ^
Td3[(s1 >> 24) ] ^
rk[0];
t[1] = Td0[(s1 ) & 0xff] ^
Td1[(s0 >> 8) & 0xff] ^
Td2[(s3 >> 16) & 0xff] ^
Td3[(s2 >> 24) ] ^
rk[1];
t[2] = Td0[(s2 ) & 0xff] ^
Td1[(s1 >> 8) & 0xff] ^
Td2[(s0 >> 16) & 0xff] ^
Td3[(s3 >> 24) ] ^
rk[2];
t[3] = Td0[(s3 ) & 0xff] ^
Td1[(s2 >> 8) & 0xff] ^
Td2[(s1 >> 16) & 0xff] ^
Td3[(s0 >> 24) ] ^
rk[3];
#endif
s0 = t[0]; s1 = t[1]; s2 = t[2]; s3 = t[3];
}
prefetch256(Td4);
*(u32*)(out+0) =
(Td4[(s0 ) & 0xff]) ^
(Td4[(s3 >> 8) & 0xff] << 8) ^
(Td4[(s2 >> 16) & 0xff] << 16) ^
(Td4[(s1 >> 24) ] << 24) ^
rk[0];
*(u32*)(out+4) =
(Td4[(s1 ) & 0xff]) ^
(Td4[(s0 >> 8) & 0xff] << 8) ^
(Td4[(s3 >> 16) & 0xff] << 16) ^
(Td4[(s2 >> 24) ] << 24) ^
rk[1];
*(u32*)(out+8) =
(Td4[(s2 ) & 0xff]) ^
(Td4[(s1 >> 8) & 0xff] << 8) ^
(Td4[(s0 >> 16) & 0xff] << 16) ^
(Td4[(s3 >> 24) ] << 24) ^
rk[2];
*(u32*)(out+12) =
(Td4[(s3 ) & 0xff]) ^
(Td4[(s2 >> 8) & 0xff] << 8) ^
(Td4[(s1 >> 16) & 0xff] << 16) ^
(Td4[(s0 >> 24) ] << 24) ^
rk[3];
}
