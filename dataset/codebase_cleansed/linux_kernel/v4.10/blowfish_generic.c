static void bf_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct bf_ctx *ctx = crypto_tfm_ctx(tfm);
const __be32 *in_blk = (const __be32 *)src;
__be32 *const out_blk = (__be32 *)dst;
const u32 *P = ctx->p;
const u32 *S = ctx->s;
u32 yl = be32_to_cpu(in_blk[0]);
u32 yr = be32_to_cpu(in_blk[1]);
ROUND(yr, yl, 0);
ROUND(yl, yr, 1);
ROUND(yr, yl, 2);
ROUND(yl, yr, 3);
ROUND(yr, yl, 4);
ROUND(yl, yr, 5);
ROUND(yr, yl, 6);
ROUND(yl, yr, 7);
ROUND(yr, yl, 8);
ROUND(yl, yr, 9);
ROUND(yr, yl, 10);
ROUND(yl, yr, 11);
ROUND(yr, yl, 12);
ROUND(yl, yr, 13);
ROUND(yr, yl, 14);
ROUND(yl, yr, 15);
yl ^= P[16];
yr ^= P[17];
out_blk[0] = cpu_to_be32(yr);
out_blk[1] = cpu_to_be32(yl);
}
static void bf_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct bf_ctx *ctx = crypto_tfm_ctx(tfm);
const __be32 *in_blk = (const __be32 *)src;
__be32 *const out_blk = (__be32 *)dst;
const u32 *P = ctx->p;
const u32 *S = ctx->s;
u32 yl = be32_to_cpu(in_blk[0]);
u32 yr = be32_to_cpu(in_blk[1]);
ROUND(yr, yl, 17);
ROUND(yl, yr, 16);
ROUND(yr, yl, 15);
ROUND(yl, yr, 14);
ROUND(yr, yl, 13);
ROUND(yl, yr, 12);
ROUND(yr, yl, 11);
ROUND(yl, yr, 10);
ROUND(yr, yl, 9);
ROUND(yl, yr, 8);
ROUND(yr, yl, 7);
ROUND(yl, yr, 6);
ROUND(yr, yl, 5);
ROUND(yl, yr, 4);
ROUND(yr, yl, 3);
ROUND(yl, yr, 2);
yl ^= P[1];
yr ^= P[0];
out_blk[0] = cpu_to_be32(yr);
out_blk[1] = cpu_to_be32(yl);
}
static int __init blowfish_mod_init(void)
{
return crypto_register_alg(&alg);
}
static void __exit blowfish_mod_fini(void)
{
crypto_unregister_alg(&alg);
}
