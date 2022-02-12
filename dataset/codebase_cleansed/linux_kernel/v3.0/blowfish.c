static void encrypt_block(struct bf_ctx *bctx, u32 *dst, u32 *src)
{
const u32 *P = bctx->p;
const u32 *S = bctx->s;
u32 yl = src[0];
u32 yr = src[1];
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
dst[0] = yr;
dst[1] = yl;
}
static void bf_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
const __be32 *in_blk = (const __be32 *)src;
__be32 *const out_blk = (__be32 *)dst;
u32 in32[2], out32[2];
in32[0] = be32_to_cpu(in_blk[0]);
in32[1] = be32_to_cpu(in_blk[1]);
encrypt_block(crypto_tfm_ctx(tfm), out32, in32);
out_blk[0] = cpu_to_be32(out32[0]);
out_blk[1] = cpu_to_be32(out32[1]);
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
static int bf_setkey(struct crypto_tfm *tfm, const u8 *key, unsigned int keylen)
{
struct bf_ctx *ctx = crypto_tfm_ctx(tfm);
u32 *P = ctx->p;
u32 *S = ctx->s;
short i, j, count;
u32 data[2], temp;
for (i = 0, count = 0; i < 256; i++)
for (j = 0; j < 4; j++, count++)
S[count] = bf_sbox[count];
for (i = 0; i < 16 + 2; i++)
P[i] = bf_pbox[i];
for (j = 0, i = 0; i < 16 + 2; i++) {
temp = (((u32)key[j] << 24) |
((u32)key[(j + 1) % keylen] << 16) |
((u32)key[(j + 2) % keylen] << 8) |
((u32)key[(j + 3) % keylen]));
P[i] = P[i] ^ temp;
j = (j + 4) % keylen;
}
data[0] = 0x00000000;
data[1] = 0x00000000;
for (i = 0; i < 16 + 2; i += 2) {
encrypt_block((struct bf_ctx *)ctx, data, data);
P[i] = data[0];
P[i + 1] = data[1];
}
for (i = 0; i < 4; i++) {
for (j = 0, count = i * 256; j < 256; j += 2, count += 2) {
encrypt_block((struct bf_ctx *)ctx, data, data);
S[count] = data[0];
S[count + 1] = data[1];
}
}
return 0;
}
static int __init blowfish_mod_init(void)
{
return crypto_register_alg(&alg);
}
static void __exit blowfish_mod_fini(void)
{
crypto_unregister_alg(&alg);
}
