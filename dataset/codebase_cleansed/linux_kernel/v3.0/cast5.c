static void cast5_encrypt(struct crypto_tfm *tfm, u8 *outbuf, const u8 *inbuf)
{
struct cast5_ctx *c = crypto_tfm_ctx(tfm);
const __be32 *src = (const __be32 *)inbuf;
__be32 *dst = (__be32 *)outbuf;
u32 l, r, t;
u32 I;
u32 *Km;
u8 *Kr;
Km = c->Km;
Kr = c->Kr;
l = be32_to_cpu(src[0]);
r = be32_to_cpu(src[1]);
t = l; l = r; r = t ^ F1(r, Km[0], Kr[0]);
t = l; l = r; r = t ^ F2(r, Km[1], Kr[1]);
t = l; l = r; r = t ^ F3(r, Km[2], Kr[2]);
t = l; l = r; r = t ^ F1(r, Km[3], Kr[3]);
t = l; l = r; r = t ^ F2(r, Km[4], Kr[4]);
t = l; l = r; r = t ^ F3(r, Km[5], Kr[5]);
t = l; l = r; r = t ^ F1(r, Km[6], Kr[6]);
t = l; l = r; r = t ^ F2(r, Km[7], Kr[7]);
t = l; l = r; r = t ^ F3(r, Km[8], Kr[8]);
t = l; l = r; r = t ^ F1(r, Km[9], Kr[9]);
t = l; l = r; r = t ^ F2(r, Km[10], Kr[10]);
t = l; l = r; r = t ^ F3(r, Km[11], Kr[11]);
if (!(c->rr)) {
t = l; l = r; r = t ^ F1(r, Km[12], Kr[12]);
t = l; l = r; r = t ^ F2(r, Km[13], Kr[13]);
t = l; l = r; r = t ^ F3(r, Km[14], Kr[14]);
t = l; l = r; r = t ^ F1(r, Km[15], Kr[15]);
}
dst[0] = cpu_to_be32(r);
dst[1] = cpu_to_be32(l);
}
static void cast5_decrypt(struct crypto_tfm *tfm, u8 *outbuf, const u8 *inbuf)
{
struct cast5_ctx *c = crypto_tfm_ctx(tfm);
const __be32 *src = (const __be32 *)inbuf;
__be32 *dst = (__be32 *)outbuf;
u32 l, r, t;
u32 I;
u32 *Km;
u8 *Kr;
Km = c->Km;
Kr = c->Kr;
l = be32_to_cpu(src[0]);
r = be32_to_cpu(src[1]);
if (!(c->rr)) {
t = l; l = r; r = t ^ F1(r, Km[15], Kr[15]);
t = l; l = r; r = t ^ F3(r, Km[14], Kr[14]);
t = l; l = r; r = t ^ F2(r, Km[13], Kr[13]);
t = l; l = r; r = t ^ F1(r, Km[12], Kr[12]);
}
t = l; l = r; r = t ^ F3(r, Km[11], Kr[11]);
t = l; l = r; r = t ^ F2(r, Km[10], Kr[10]);
t = l; l = r; r = t ^ F1(r, Km[9], Kr[9]);
t = l; l = r; r = t ^ F3(r, Km[8], Kr[8]);
t = l; l = r; r = t ^ F2(r, Km[7], Kr[7]);
t = l; l = r; r = t ^ F1(r, Km[6], Kr[6]);
t = l; l = r; r = t ^ F3(r, Km[5], Kr[5]);
t = l; l = r; r = t ^ F2(r, Km[4], Kr[4]);
t = l; l = r; r = t ^ F1(r, Km[3], Kr[3]);
t = l; l = r; r = t ^ F3(r, Km[2], Kr[2]);
t = l; l = r; r = t ^ F2(r, Km[1], Kr[1]);
t = l; l = r; r = t ^ F1(r, Km[0], Kr[0]);
dst[0] = cpu_to_be32(r);
dst[1] = cpu_to_be32(l);
}
static void key_schedule(u32 *x, u32 *z, u32 *k)
{
#define xi(i) ((x[(i)/4] >> (8*(3-((i)%4)))) & 0xff)
#define zi(i) ((z[(i)/4] >> (8*(3-((i)%4)))) & 0xff)
z[0] = x[0] ^ s5[xi(13)] ^ s6[xi(15)] ^ s7[xi(12)] ^ sb8[xi(14)] ^
s7[xi(8)];
z[1] = x[2] ^ s5[zi(0)] ^ s6[zi(2)] ^ s7[zi(1)] ^ sb8[zi(3)] ^
sb8[xi(10)];
z[2] = x[3] ^ s5[zi(7)] ^ s6[zi(6)] ^ s7[zi(5)] ^ sb8[zi(4)] ^
s5[xi(9)];
z[3] = x[1] ^ s5[zi(10)] ^ s6[zi(9)] ^ s7[zi(11)] ^ sb8[zi(8)] ^
s6[xi(11)];
k[0] = s5[zi(8)] ^ s6[zi(9)] ^ s7[zi(7)] ^ sb8[zi(6)] ^ s5[zi(2)];
k[1] = s5[zi(10)] ^ s6[zi(11)] ^ s7[zi(5)] ^ sb8[zi(4)] ^
s6[zi(6)];
k[2] = s5[zi(12)] ^ s6[zi(13)] ^ s7[zi(3)] ^ sb8[zi(2)] ^
s7[zi(9)];
k[3] = s5[zi(14)] ^ s6[zi(15)] ^ s7[zi(1)] ^ sb8[zi(0)] ^
sb8[zi(12)];
x[0] = z[2] ^ s5[zi(5)] ^ s6[zi(7)] ^ s7[zi(4)] ^ sb8[zi(6)] ^
s7[zi(0)];
x[1] = z[0] ^ s5[xi(0)] ^ s6[xi(2)] ^ s7[xi(1)] ^ sb8[xi(3)] ^
sb8[zi(2)];
x[2] = z[1] ^ s5[xi(7)] ^ s6[xi(6)] ^ s7[xi(5)] ^ sb8[xi(4)] ^
s5[zi(1)];
x[3] = z[3] ^ s5[xi(10)] ^ s6[xi(9)] ^ s7[xi(11)] ^ sb8[xi(8)] ^
s6[zi(3)];
k[4] = s5[xi(3)] ^ s6[xi(2)] ^ s7[xi(12)] ^ sb8[xi(13)] ^
s5[xi(8)];
k[5] = s5[xi(1)] ^ s6[xi(0)] ^ s7[xi(14)] ^ sb8[xi(15)] ^
s6[xi(13)];
k[6] = s5[xi(7)] ^ s6[xi(6)] ^ s7[xi(8)] ^ sb8[xi(9)] ^ s7[xi(3)];
k[7] = s5[xi(5)] ^ s6[xi(4)] ^ s7[xi(10)] ^ sb8[xi(11)] ^
sb8[xi(7)];
z[0] = x[0] ^ s5[xi(13)] ^ s6[xi(15)] ^ s7[xi(12)] ^ sb8[xi(14)] ^
s7[xi(8)];
z[1] = x[2] ^ s5[zi(0)] ^ s6[zi(2)] ^ s7[zi(1)] ^ sb8[zi(3)] ^
sb8[xi(10)];
z[2] = x[3] ^ s5[zi(7)] ^ s6[zi(6)] ^ s7[zi(5)] ^ sb8[zi(4)] ^
s5[xi(9)];
z[3] = x[1] ^ s5[zi(10)] ^ s6[zi(9)] ^ s7[zi(11)] ^ sb8[zi(8)] ^
s6[xi(11)];
k[8] = s5[zi(3)] ^ s6[zi(2)] ^ s7[zi(12)] ^ sb8[zi(13)] ^
s5[zi(9)];
k[9] = s5[zi(1)] ^ s6[zi(0)] ^ s7[zi(14)] ^ sb8[zi(15)] ^
s6[zi(12)];
k[10] = s5[zi(7)] ^ s6[zi(6)] ^ s7[zi(8)] ^ sb8[zi(9)] ^ s7[zi(2)];
k[11] = s5[zi(5)] ^ s6[zi(4)] ^ s7[zi(10)] ^ sb8[zi(11)] ^
sb8[zi(6)];
x[0] = z[2] ^ s5[zi(5)] ^ s6[zi(7)] ^ s7[zi(4)] ^ sb8[zi(6)] ^
s7[zi(0)];
x[1] = z[0] ^ s5[xi(0)] ^ s6[xi(2)] ^ s7[xi(1)] ^ sb8[xi(3)] ^
sb8[zi(2)];
x[2] = z[1] ^ s5[xi(7)] ^ s6[xi(6)] ^ s7[xi(5)] ^ sb8[xi(4)] ^
s5[zi(1)];
x[3] = z[3] ^ s5[xi(10)] ^ s6[xi(9)] ^ s7[xi(11)] ^ sb8[xi(8)] ^
s6[zi(3)];
k[12] = s5[xi(8)] ^ s6[xi(9)] ^ s7[xi(7)] ^ sb8[xi(6)] ^ s5[xi(3)];
k[13] = s5[xi(10)] ^ s6[xi(11)] ^ s7[xi(5)] ^ sb8[xi(4)] ^
s6[xi(7)];
k[14] = s5[xi(12)] ^ s6[xi(13)] ^ s7[xi(3)] ^ sb8[xi(2)] ^
s7[xi(8)];
k[15] = s5[xi(14)] ^ s6[xi(15)] ^ s7[xi(1)] ^ sb8[xi(0)] ^
sb8[xi(13)];
#undef xi
#undef zi
}
static int cast5_setkey(struct crypto_tfm *tfm, const u8 *key, unsigned key_len)
{
struct cast5_ctx *c = crypto_tfm_ctx(tfm);
int i;
u32 x[4];
u32 z[4];
u32 k[16];
__be32 p_key[4];
c->rr = key_len <= 10 ? 1 : 0;
memset(p_key, 0, 16);
memcpy(p_key, key, key_len);
x[0] = be32_to_cpu(p_key[0]);
x[1] = be32_to_cpu(p_key[1]);
x[2] = be32_to_cpu(p_key[2]);
x[3] = be32_to_cpu(p_key[3]);
key_schedule(x, z, k);
for (i = 0; i < 16; i++)
c->Km[i] = k[i];
key_schedule(x, z, k);
for (i = 0; i < 16; i++)
c->Kr[i] = k[i] & 0x1f;
return 0;
}
static int __init cast5_mod_init(void)
{
return crypto_register_alg(&alg);
}
static void __exit cast5_mod_fini(void)
{
crypto_unregister_alg(&alg);
}
