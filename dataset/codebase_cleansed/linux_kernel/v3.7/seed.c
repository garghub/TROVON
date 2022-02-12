static inline u8
byte(const u32 x, const unsigned n)
{
return x >> (n << 3);
}
static int seed_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct seed_ctx *ctx = crypto_tfm_ctx(tfm);
u32 *keyout = ctx->keysched;
const __be32 *key = (const __be32 *)in_key;
u32 i, t0, t1, x1, x2, x3, x4;
x1 = be32_to_cpu(key[0]);
x2 = be32_to_cpu(key[1]);
x3 = be32_to_cpu(key[2]);
x4 = be32_to_cpu(key[3]);
for (i = 0; i < SEED_NUM_KCONSTANTS; i++) {
t0 = x1 + x3 - KC[i];
t1 = x2 + KC[i] - x4;
*(keyout++) = SS0[byte(t0, 0)] ^ SS1[byte(t0, 1)] ^
SS2[byte(t0, 2)] ^ SS3[byte(t0, 3)];
*(keyout++) = SS0[byte(t1, 0)] ^ SS1[byte(t1, 1)] ^
SS2[byte(t1, 2)] ^ SS3[byte(t1, 3)];
if (i % 2 == 0) {
t0 = x1;
x1 = (x1 >> 8) ^ (x2 << 24);
x2 = (x2 >> 8) ^ (t0 << 24);
} else {
t0 = x3;
x3 = (x3 << 8) ^ (x4 >> 24);
x4 = (x4 << 8) ^ (t0 >> 24);
}
}
return 0;
}
static void seed_encrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
const struct seed_ctx *ctx = crypto_tfm_ctx(tfm);
const __be32 *src = (const __be32 *)in;
__be32 *dst = (__be32 *)out;
u32 x1, x2, x3, x4, t0, t1;
const u32 *ks = ctx->keysched;
x1 = be32_to_cpu(src[0]);
x2 = be32_to_cpu(src[1]);
x3 = be32_to_cpu(src[2]);
x4 = be32_to_cpu(src[3]);
OP(x1, x2, x3, x4, 0);
OP(x3, x4, x1, x2, 2);
OP(x1, x2, x3, x4, 4);
OP(x3, x4, x1, x2, 6);
OP(x1, x2, x3, x4, 8);
OP(x3, x4, x1, x2, 10);
OP(x1, x2, x3, x4, 12);
OP(x3, x4, x1, x2, 14);
OP(x1, x2, x3, x4, 16);
OP(x3, x4, x1, x2, 18);
OP(x1, x2, x3, x4, 20);
OP(x3, x4, x1, x2, 22);
OP(x1, x2, x3, x4, 24);
OP(x3, x4, x1, x2, 26);
OP(x1, x2, x3, x4, 28);
OP(x3, x4, x1, x2, 30);
dst[0] = cpu_to_be32(x3);
dst[1] = cpu_to_be32(x4);
dst[2] = cpu_to_be32(x1);
dst[3] = cpu_to_be32(x2);
}
static void seed_decrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
const struct seed_ctx *ctx = crypto_tfm_ctx(tfm);
const __be32 *src = (const __be32 *)in;
__be32 *dst = (__be32 *)out;
u32 x1, x2, x3, x4, t0, t1;
const u32 *ks = ctx->keysched;
x1 = be32_to_cpu(src[0]);
x2 = be32_to_cpu(src[1]);
x3 = be32_to_cpu(src[2]);
x4 = be32_to_cpu(src[3]);
OP(x1, x2, x3, x4, 30);
OP(x3, x4, x1, x2, 28);
OP(x1, x2, x3, x4, 26);
OP(x3, x4, x1, x2, 24);
OP(x1, x2, x3, x4, 22);
OP(x3, x4, x1, x2, 20);
OP(x1, x2, x3, x4, 18);
OP(x3, x4, x1, x2, 16);
OP(x1, x2, x3, x4, 14);
OP(x3, x4, x1, x2, 12);
OP(x1, x2, x3, x4, 10);
OP(x3, x4, x1, x2, 8);
OP(x1, x2, x3, x4, 6);
OP(x3, x4, x1, x2, 4);
OP(x1, x2, x3, x4, 2);
OP(x3, x4, x1, x2, 0);
dst[0] = cpu_to_be32(x3);
dst[1] = cpu_to_be32(x4);
dst[2] = cpu_to_be32(x1);
dst[3] = cpu_to_be32(x2);
}
static int __init seed_init(void)
{
return crypto_register_alg(&seed_alg);
}
static void __exit seed_fini(void)
{
crypto_unregister_alg(&seed_alg);
}
