static inline u32 Ch(u32 x, u32 y, u32 z)
{
return z ^ (x & (y ^ z));
}
static inline u32 Maj(u32 x, u32 y, u32 z)
{
return (x & y) | (z & (x | y));
}
static inline void LOAD_OP(int I, u32 *W, const u8 *input)
{
W[I] = __be32_to_cpu( ((__be32*)(input))[I] );
}
static inline void BLEND_OP(int I, u32 *W)
{
W[I] = s1(W[I-2]) + W[I-7] + s0(W[I-15]) + W[I-16];
}
static void sha256_transform(u32 *state, const u8 *input)
{
u32 a, b, c, d, e, f, g, h, t1, t2;
u32 W[64];
int i;
for (i = 0; i < 16; i++)
LOAD_OP(i, W, input);
for (i = 16; i < 64; i++)
BLEND_OP(i, W);
a=state[0]; b=state[1]; c=state[2]; d=state[3];
e=state[4]; f=state[5]; g=state[6]; h=state[7];
t1 = h + e1(e) + Ch(e,f,g) + 0x428a2f98 + W[ 0];
t2 = e0(a) + Maj(a,b,c); d+=t1; h=t1+t2;
t1 = g + e1(d) + Ch(d,e,f) + 0x71374491 + W[ 1];
t2 = e0(h) + Maj(h,a,b); c+=t1; g=t1+t2;
t1 = f + e1(c) + Ch(c,d,e) + 0xb5c0fbcf + W[ 2];
t2 = e0(g) + Maj(g,h,a); b+=t1; f=t1+t2;
t1 = e + e1(b) + Ch(b,c,d) + 0xe9b5dba5 + W[ 3];
t2 = e0(f) + Maj(f,g,h); a+=t1; e=t1+t2;
t1 = d + e1(a) + Ch(a,b,c) + 0x3956c25b + W[ 4];
t2 = e0(e) + Maj(e,f,g); h+=t1; d=t1+t2;
t1 = c + e1(h) + Ch(h,a,b) + 0x59f111f1 + W[ 5];
t2 = e0(d) + Maj(d,e,f); g+=t1; c=t1+t2;
t1 = b + e1(g) + Ch(g,h,a) + 0x923f82a4 + W[ 6];
t2 = e0(c) + Maj(c,d,e); f+=t1; b=t1+t2;
t1 = a + e1(f) + Ch(f,g,h) + 0xab1c5ed5 + W[ 7];
t2 = e0(b) + Maj(b,c,d); e+=t1; a=t1+t2;
t1 = h + e1(e) + Ch(e,f,g) + 0xd807aa98 + W[ 8];
t2 = e0(a) + Maj(a,b,c); d+=t1; h=t1+t2;
t1 = g + e1(d) + Ch(d,e,f) + 0x12835b01 + W[ 9];
t2 = e0(h) + Maj(h,a,b); c+=t1; g=t1+t2;
t1 = f + e1(c) + Ch(c,d,e) + 0x243185be + W[10];
t2 = e0(g) + Maj(g,h,a); b+=t1; f=t1+t2;
t1 = e + e1(b) + Ch(b,c,d) + 0x550c7dc3 + W[11];
t2 = e0(f) + Maj(f,g,h); a+=t1; e=t1+t2;
t1 = d + e1(a) + Ch(a,b,c) + 0x72be5d74 + W[12];
t2 = e0(e) + Maj(e,f,g); h+=t1; d=t1+t2;
t1 = c + e1(h) + Ch(h,a,b) + 0x80deb1fe + W[13];
t2 = e0(d) + Maj(d,e,f); g+=t1; c=t1+t2;
t1 = b + e1(g) + Ch(g,h,a) + 0x9bdc06a7 + W[14];
t2 = e0(c) + Maj(c,d,e); f+=t1; b=t1+t2;
t1 = a + e1(f) + Ch(f,g,h) + 0xc19bf174 + W[15];
t2 = e0(b) + Maj(b,c,d); e+=t1; a=t1+t2;
t1 = h + e1(e) + Ch(e,f,g) + 0xe49b69c1 + W[16];
t2 = e0(a) + Maj(a,b,c); d+=t1; h=t1+t2;
t1 = g + e1(d) + Ch(d,e,f) + 0xefbe4786 + W[17];
t2 = e0(h) + Maj(h,a,b); c+=t1; g=t1+t2;
t1 = f + e1(c) + Ch(c,d,e) + 0x0fc19dc6 + W[18];
t2 = e0(g) + Maj(g,h,a); b+=t1; f=t1+t2;
t1 = e + e1(b) + Ch(b,c,d) + 0x240ca1cc + W[19];
t2 = e0(f) + Maj(f,g,h); a+=t1; e=t1+t2;
t1 = d + e1(a) + Ch(a,b,c) + 0x2de92c6f + W[20];
t2 = e0(e) + Maj(e,f,g); h+=t1; d=t1+t2;
t1 = c + e1(h) + Ch(h,a,b) + 0x4a7484aa + W[21];
t2 = e0(d) + Maj(d,e,f); g+=t1; c=t1+t2;
t1 = b + e1(g) + Ch(g,h,a) + 0x5cb0a9dc + W[22];
t2 = e0(c) + Maj(c,d,e); f+=t1; b=t1+t2;
t1 = a + e1(f) + Ch(f,g,h) + 0x76f988da + W[23];
t2 = e0(b) + Maj(b,c,d); e+=t1; a=t1+t2;
t1 = h + e1(e) + Ch(e,f,g) + 0x983e5152 + W[24];
t2 = e0(a) + Maj(a,b,c); d+=t1; h=t1+t2;
t1 = g + e1(d) + Ch(d,e,f) + 0xa831c66d + W[25];
t2 = e0(h) + Maj(h,a,b); c+=t1; g=t1+t2;
t1 = f + e1(c) + Ch(c,d,e) + 0xb00327c8 + W[26];
t2 = e0(g) + Maj(g,h,a); b+=t1; f=t1+t2;
t1 = e + e1(b) + Ch(b,c,d) + 0xbf597fc7 + W[27];
t2 = e0(f) + Maj(f,g,h); a+=t1; e=t1+t2;
t1 = d + e1(a) + Ch(a,b,c) + 0xc6e00bf3 + W[28];
t2 = e0(e) + Maj(e,f,g); h+=t1; d=t1+t2;
t1 = c + e1(h) + Ch(h,a,b) + 0xd5a79147 + W[29];
t2 = e0(d) + Maj(d,e,f); g+=t1; c=t1+t2;
t1 = b + e1(g) + Ch(g,h,a) + 0x06ca6351 + W[30];
t2 = e0(c) + Maj(c,d,e); f+=t1; b=t1+t2;
t1 = a + e1(f) + Ch(f,g,h) + 0x14292967 + W[31];
t2 = e0(b) + Maj(b,c,d); e+=t1; a=t1+t2;
t1 = h + e1(e) + Ch(e,f,g) + 0x27b70a85 + W[32];
t2 = e0(a) + Maj(a,b,c); d+=t1; h=t1+t2;
t1 = g + e1(d) + Ch(d,e,f) + 0x2e1b2138 + W[33];
t2 = e0(h) + Maj(h,a,b); c+=t1; g=t1+t2;
t1 = f + e1(c) + Ch(c,d,e) + 0x4d2c6dfc + W[34];
t2 = e0(g) + Maj(g,h,a); b+=t1; f=t1+t2;
t1 = e + e1(b) + Ch(b,c,d) + 0x53380d13 + W[35];
t2 = e0(f) + Maj(f,g,h); a+=t1; e=t1+t2;
t1 = d + e1(a) + Ch(a,b,c) + 0x650a7354 + W[36];
t2 = e0(e) + Maj(e,f,g); h+=t1; d=t1+t2;
t1 = c + e1(h) + Ch(h,a,b) + 0x766a0abb + W[37];
t2 = e0(d) + Maj(d,e,f); g+=t1; c=t1+t2;
t1 = b + e1(g) + Ch(g,h,a) + 0x81c2c92e + W[38];
t2 = e0(c) + Maj(c,d,e); f+=t1; b=t1+t2;
t1 = a + e1(f) + Ch(f,g,h) + 0x92722c85 + W[39];
t2 = e0(b) + Maj(b,c,d); e+=t1; a=t1+t2;
t1 = h + e1(e) + Ch(e,f,g) + 0xa2bfe8a1 + W[40];
t2 = e0(a) + Maj(a,b,c); d+=t1; h=t1+t2;
t1 = g + e1(d) + Ch(d,e,f) + 0xa81a664b + W[41];
t2 = e0(h) + Maj(h,a,b); c+=t1; g=t1+t2;
t1 = f + e1(c) + Ch(c,d,e) + 0xc24b8b70 + W[42];
t2 = e0(g) + Maj(g,h,a); b+=t1; f=t1+t2;
t1 = e + e1(b) + Ch(b,c,d) + 0xc76c51a3 + W[43];
t2 = e0(f) + Maj(f,g,h); a+=t1; e=t1+t2;
t1 = d + e1(a) + Ch(a,b,c) + 0xd192e819 + W[44];
t2 = e0(e) + Maj(e,f,g); h+=t1; d=t1+t2;
t1 = c + e1(h) + Ch(h,a,b) + 0xd6990624 + W[45];
t2 = e0(d) + Maj(d,e,f); g+=t1; c=t1+t2;
t1 = b + e1(g) + Ch(g,h,a) + 0xf40e3585 + W[46];
t2 = e0(c) + Maj(c,d,e); f+=t1; b=t1+t2;
t1 = a + e1(f) + Ch(f,g,h) + 0x106aa070 + W[47];
t2 = e0(b) + Maj(b,c,d); e+=t1; a=t1+t2;
t1 = h + e1(e) + Ch(e,f,g) + 0x19a4c116 + W[48];
t2 = e0(a) + Maj(a,b,c); d+=t1; h=t1+t2;
t1 = g + e1(d) + Ch(d,e,f) + 0x1e376c08 + W[49];
t2 = e0(h) + Maj(h,a,b); c+=t1; g=t1+t2;
t1 = f + e1(c) + Ch(c,d,e) + 0x2748774c + W[50];
t2 = e0(g) + Maj(g,h,a); b+=t1; f=t1+t2;
t1 = e + e1(b) + Ch(b,c,d) + 0x34b0bcb5 + W[51];
t2 = e0(f) + Maj(f,g,h); a+=t1; e=t1+t2;
t1 = d + e1(a) + Ch(a,b,c) + 0x391c0cb3 + W[52];
t2 = e0(e) + Maj(e,f,g); h+=t1; d=t1+t2;
t1 = c + e1(h) + Ch(h,a,b) + 0x4ed8aa4a + W[53];
t2 = e0(d) + Maj(d,e,f); g+=t1; c=t1+t2;
t1 = b + e1(g) + Ch(g,h,a) + 0x5b9cca4f + W[54];
t2 = e0(c) + Maj(c,d,e); f+=t1; b=t1+t2;
t1 = a + e1(f) + Ch(f,g,h) + 0x682e6ff3 + W[55];
t2 = e0(b) + Maj(b,c,d); e+=t1; a=t1+t2;
t1 = h + e1(e) + Ch(e,f,g) + 0x748f82ee + W[56];
t2 = e0(a) + Maj(a,b,c); d+=t1; h=t1+t2;
t1 = g + e1(d) + Ch(d,e,f) + 0x78a5636f + W[57];
t2 = e0(h) + Maj(h,a,b); c+=t1; g=t1+t2;
t1 = f + e1(c) + Ch(c,d,e) + 0x84c87814 + W[58];
t2 = e0(g) + Maj(g,h,a); b+=t1; f=t1+t2;
t1 = e + e1(b) + Ch(b,c,d) + 0x8cc70208 + W[59];
t2 = e0(f) + Maj(f,g,h); a+=t1; e=t1+t2;
t1 = d + e1(a) + Ch(a,b,c) + 0x90befffa + W[60];
t2 = e0(e) + Maj(e,f,g); h+=t1; d=t1+t2;
t1 = c + e1(h) + Ch(h,a,b) + 0xa4506ceb + W[61];
t2 = e0(d) + Maj(d,e,f); g+=t1; c=t1+t2;
t1 = b + e1(g) + Ch(g,h,a) + 0xbef9a3f7 + W[62];
t2 = e0(c) + Maj(c,d,e); f+=t1; b=t1+t2;
t1 = a + e1(f) + Ch(f,g,h) + 0xc67178f2 + W[63];
t2 = e0(b) + Maj(b,c,d); e+=t1; a=t1+t2;
state[0] += a; state[1] += b; state[2] += c; state[3] += d;
state[4] += e; state[5] += f; state[6] += g; state[7] += h;
a = b = c = d = e = f = g = h = t1 = t2 = 0;
memset(W, 0, 64 * sizeof(u32));
}
static int sha224_init(struct shash_desc *desc)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA224_H0;
sctx->state[1] = SHA224_H1;
sctx->state[2] = SHA224_H2;
sctx->state[3] = SHA224_H3;
sctx->state[4] = SHA224_H4;
sctx->state[5] = SHA224_H5;
sctx->state[6] = SHA224_H6;
sctx->state[7] = SHA224_H7;
sctx->count = 0;
return 0;
}
static int sha256_init(struct shash_desc *desc)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA256_H0;
sctx->state[1] = SHA256_H1;
sctx->state[2] = SHA256_H2;
sctx->state[3] = SHA256_H3;
sctx->state[4] = SHA256_H4;
sctx->state[5] = SHA256_H5;
sctx->state[6] = SHA256_H6;
sctx->state[7] = SHA256_H7;
sctx->count = 0;
return 0;
}
static int sha256_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
unsigned int partial, done;
const u8 *src;
partial = sctx->count & 0x3f;
sctx->count += len;
done = 0;
src = data;
if ((partial + len) > 63) {
if (partial) {
done = -partial;
memcpy(sctx->buf + partial, data, done + 64);
src = sctx->buf;
}
do {
sha256_transform(sctx->state, src);
done += 64;
src = data + done;
} while (done + 63 < len);
partial = 0;
}
memcpy(sctx->buf + partial, src, len - done);
return 0;
}
static int sha256_final(struct shash_desc *desc, u8 *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
__be32 *dst = (__be32 *)out;
__be64 bits;
unsigned int index, pad_len;
int i;
static const u8 padding[64] = { 0x80, };
bits = cpu_to_be64(sctx->count << 3);
index = sctx->count & 0x3f;
pad_len = (index < 56) ? (56 - index) : ((64+56) - index);
sha256_update(desc, padding, pad_len);
sha256_update(desc, (const u8 *)&bits, sizeof(bits));
for (i = 0; i < 8; i++)
dst[i] = cpu_to_be32(sctx->state[i]);
memset(sctx, 0, sizeof(*sctx));
return 0;
}
static int sha224_final(struct shash_desc *desc, u8 *hash)
{
u8 D[SHA256_DIGEST_SIZE];
sha256_final(desc, D);
memcpy(hash, D, SHA224_DIGEST_SIZE);
memset(D, 0, SHA256_DIGEST_SIZE);
return 0;
}
static int sha256_export(struct shash_desc *desc, void *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int sha256_import(struct shash_desc *desc, const void *in)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int __init sha256_generic_mod_init(void)
{
int ret = 0;
ret = crypto_register_shash(&sha224);
if (ret < 0)
return ret;
ret = crypto_register_shash(&sha256);
if (ret < 0)
crypto_unregister_shash(&sha224);
return ret;
}
static void __exit sha256_generic_mod_fini(void)
{
crypto_unregister_shash(&sha224);
crypto_unregister_shash(&sha256);
}
