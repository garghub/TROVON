static void rmd128_transform(u32 *state, const __le32 *in)
{
u32 aa, bb, cc, dd, aaa, bbb, ccc, ddd;
aa = state[0];
bb = state[1];
cc = state[2];
dd = state[3];
aaa = state[0];
bbb = state[1];
ccc = state[2];
ddd = state[3];
ROUND(aa, bb, cc, dd, F1, K1, in[0], 11);
ROUND(dd, aa, bb, cc, F1, K1, in[1], 14);
ROUND(cc, dd, aa, bb, F1, K1, in[2], 15);
ROUND(bb, cc, dd, aa, F1, K1, in[3], 12);
ROUND(aa, bb, cc, dd, F1, K1, in[4], 5);
ROUND(dd, aa, bb, cc, F1, K1, in[5], 8);
ROUND(cc, dd, aa, bb, F1, K1, in[6], 7);
ROUND(bb, cc, dd, aa, F1, K1, in[7], 9);
ROUND(aa, bb, cc, dd, F1, K1, in[8], 11);
ROUND(dd, aa, bb, cc, F1, K1, in[9], 13);
ROUND(cc, dd, aa, bb, F1, K1, in[10], 14);
ROUND(bb, cc, dd, aa, F1, K1, in[11], 15);
ROUND(aa, bb, cc, dd, F1, K1, in[12], 6);
ROUND(dd, aa, bb, cc, F1, K1, in[13], 7);
ROUND(cc, dd, aa, bb, F1, K1, in[14], 9);
ROUND(bb, cc, dd, aa, F1, K1, in[15], 8);
ROUND(aa, bb, cc, dd, F2, K2, in[7], 7);
ROUND(dd, aa, bb, cc, F2, K2, in[4], 6);
ROUND(cc, dd, aa, bb, F2, K2, in[13], 8);
ROUND(bb, cc, dd, aa, F2, K2, in[1], 13);
ROUND(aa, bb, cc, dd, F2, K2, in[10], 11);
ROUND(dd, aa, bb, cc, F2, K2, in[6], 9);
ROUND(cc, dd, aa, bb, F2, K2, in[15], 7);
ROUND(bb, cc, dd, aa, F2, K2, in[3], 15);
ROUND(aa, bb, cc, dd, F2, K2, in[12], 7);
ROUND(dd, aa, bb, cc, F2, K2, in[0], 12);
ROUND(cc, dd, aa, bb, F2, K2, in[9], 15);
ROUND(bb, cc, dd, aa, F2, K2, in[5], 9);
ROUND(aa, bb, cc, dd, F2, K2, in[2], 11);
ROUND(dd, aa, bb, cc, F2, K2, in[14], 7);
ROUND(cc, dd, aa, bb, F2, K2, in[11], 13);
ROUND(bb, cc, dd, aa, F2, K2, in[8], 12);
ROUND(aa, bb, cc, dd, F3, K3, in[3], 11);
ROUND(dd, aa, bb, cc, F3, K3, in[10], 13);
ROUND(cc, dd, aa, bb, F3, K3, in[14], 6);
ROUND(bb, cc, dd, aa, F3, K3, in[4], 7);
ROUND(aa, bb, cc, dd, F3, K3, in[9], 14);
ROUND(dd, aa, bb, cc, F3, K3, in[15], 9);
ROUND(cc, dd, aa, bb, F3, K3, in[8], 13);
ROUND(bb, cc, dd, aa, F3, K3, in[1], 15);
ROUND(aa, bb, cc, dd, F3, K3, in[2], 14);
ROUND(dd, aa, bb, cc, F3, K3, in[7], 8);
ROUND(cc, dd, aa, bb, F3, K3, in[0], 13);
ROUND(bb, cc, dd, aa, F3, K3, in[6], 6);
ROUND(aa, bb, cc, dd, F3, K3, in[13], 5);
ROUND(dd, aa, bb, cc, F3, K3, in[11], 12);
ROUND(cc, dd, aa, bb, F3, K3, in[5], 7);
ROUND(bb, cc, dd, aa, F3, K3, in[12], 5);
ROUND(aa, bb, cc, dd, F4, K4, in[1], 11);
ROUND(dd, aa, bb, cc, F4, K4, in[9], 12);
ROUND(cc, dd, aa, bb, F4, K4, in[11], 14);
ROUND(bb, cc, dd, aa, F4, K4, in[10], 15);
ROUND(aa, bb, cc, dd, F4, K4, in[0], 14);
ROUND(dd, aa, bb, cc, F4, K4, in[8], 15);
ROUND(cc, dd, aa, bb, F4, K4, in[12], 9);
ROUND(bb, cc, dd, aa, F4, K4, in[4], 8);
ROUND(aa, bb, cc, dd, F4, K4, in[13], 9);
ROUND(dd, aa, bb, cc, F4, K4, in[3], 14);
ROUND(cc, dd, aa, bb, F4, K4, in[7], 5);
ROUND(bb, cc, dd, aa, F4, K4, in[15], 6);
ROUND(aa, bb, cc, dd, F4, K4, in[14], 8);
ROUND(dd, aa, bb, cc, F4, K4, in[5], 6);
ROUND(cc, dd, aa, bb, F4, K4, in[6], 5);
ROUND(bb, cc, dd, aa, F4, K4, in[2], 12);
ROUND(aaa, bbb, ccc, ddd, F4, KK1, in[5], 8);
ROUND(ddd, aaa, bbb, ccc, F4, KK1, in[14], 9);
ROUND(ccc, ddd, aaa, bbb, F4, KK1, in[7], 9);
ROUND(bbb, ccc, ddd, aaa, F4, KK1, in[0], 11);
ROUND(aaa, bbb, ccc, ddd, F4, KK1, in[9], 13);
ROUND(ddd, aaa, bbb, ccc, F4, KK1, in[2], 15);
ROUND(ccc, ddd, aaa, bbb, F4, KK1, in[11], 15);
ROUND(bbb, ccc, ddd, aaa, F4, KK1, in[4], 5);
ROUND(aaa, bbb, ccc, ddd, F4, KK1, in[13], 7);
ROUND(ddd, aaa, bbb, ccc, F4, KK1, in[6], 7);
ROUND(ccc, ddd, aaa, bbb, F4, KK1, in[15], 8);
ROUND(bbb, ccc, ddd, aaa, F4, KK1, in[8], 11);
ROUND(aaa, bbb, ccc, ddd, F4, KK1, in[1], 14);
ROUND(ddd, aaa, bbb, ccc, F4, KK1, in[10], 14);
ROUND(ccc, ddd, aaa, bbb, F4, KK1, in[3], 12);
ROUND(bbb, ccc, ddd, aaa, F4, KK1, in[12], 6);
ROUND(aaa, bbb, ccc, ddd, F3, KK2, in[6], 9);
ROUND(ddd, aaa, bbb, ccc, F3, KK2, in[11], 13);
ROUND(ccc, ddd, aaa, bbb, F3, KK2, in[3], 15);
ROUND(bbb, ccc, ddd, aaa, F3, KK2, in[7], 7);
ROUND(aaa, bbb, ccc, ddd, F3, KK2, in[0], 12);
ROUND(ddd, aaa, bbb, ccc, F3, KK2, in[13], 8);
ROUND(ccc, ddd, aaa, bbb, F3, KK2, in[5], 9);
ROUND(bbb, ccc, ddd, aaa, F3, KK2, in[10], 11);
ROUND(aaa, bbb, ccc, ddd, F3, KK2, in[14], 7);
ROUND(ddd, aaa, bbb, ccc, F3, KK2, in[15], 7);
ROUND(ccc, ddd, aaa, bbb, F3, KK2, in[8], 12);
ROUND(bbb, ccc, ddd, aaa, F3, KK2, in[12], 7);
ROUND(aaa, bbb, ccc, ddd, F3, KK2, in[4], 6);
ROUND(ddd, aaa, bbb, ccc, F3, KK2, in[9], 15);
ROUND(ccc, ddd, aaa, bbb, F3, KK2, in[1], 13);
ROUND(bbb, ccc, ddd, aaa, F3, KK2, in[2], 11);
ROUND(aaa, bbb, ccc, ddd, F2, KK3, in[15], 9);
ROUND(ddd, aaa, bbb, ccc, F2, KK3, in[5], 7);
ROUND(ccc, ddd, aaa, bbb, F2, KK3, in[1], 15);
ROUND(bbb, ccc, ddd, aaa, F2, KK3, in[3], 11);
ROUND(aaa, bbb, ccc, ddd, F2, KK3, in[7], 8);
ROUND(ddd, aaa, bbb, ccc, F2, KK3, in[14], 6);
ROUND(ccc, ddd, aaa, bbb, F2, KK3, in[6], 6);
ROUND(bbb, ccc, ddd, aaa, F2, KK3, in[9], 14);
ROUND(aaa, bbb, ccc, ddd, F2, KK3, in[11], 12);
ROUND(ddd, aaa, bbb, ccc, F2, KK3, in[8], 13);
ROUND(ccc, ddd, aaa, bbb, F2, KK3, in[12], 5);
ROUND(bbb, ccc, ddd, aaa, F2, KK3, in[2], 14);
ROUND(aaa, bbb, ccc, ddd, F2, KK3, in[10], 13);
ROUND(ddd, aaa, bbb, ccc, F2, KK3, in[0], 13);
ROUND(ccc, ddd, aaa, bbb, F2, KK3, in[4], 7);
ROUND(bbb, ccc, ddd, aaa, F2, KK3, in[13], 5);
ROUND(aaa, bbb, ccc, ddd, F1, KK4, in[8], 15);
ROUND(ddd, aaa, bbb, ccc, F1, KK4, in[6], 5);
ROUND(ccc, ddd, aaa, bbb, F1, KK4, in[4], 8);
ROUND(bbb, ccc, ddd, aaa, F1, KK4, in[1], 11);
ROUND(aaa, bbb, ccc, ddd, F1, KK4, in[3], 14);
ROUND(ddd, aaa, bbb, ccc, F1, KK4, in[11], 14);
ROUND(ccc, ddd, aaa, bbb, F1, KK4, in[15], 6);
ROUND(bbb, ccc, ddd, aaa, F1, KK4, in[0], 14);
ROUND(aaa, bbb, ccc, ddd, F1, KK4, in[5], 6);
ROUND(ddd, aaa, bbb, ccc, F1, KK4, in[12], 9);
ROUND(ccc, ddd, aaa, bbb, F1, KK4, in[2], 12);
ROUND(bbb, ccc, ddd, aaa, F1, KK4, in[13], 9);
ROUND(aaa, bbb, ccc, ddd, F1, KK4, in[9], 12);
ROUND(ddd, aaa, bbb, ccc, F1, KK4, in[7], 5);
ROUND(ccc, ddd, aaa, bbb, F1, KK4, in[10], 15);
ROUND(bbb, ccc, ddd, aaa, F1, KK4, in[14], 8);
ddd += cc + state[1];
state[1] = state[2] + dd + aaa;
state[2] = state[3] + aa + bbb;
state[3] = state[0] + bb + ccc;
state[0] = ddd;
return;
}
static int rmd128_init(struct shash_desc *desc)
{
struct rmd128_ctx *rctx = shash_desc_ctx(desc);
rctx->byte_count = 0;
rctx->state[0] = RMD_H0;
rctx->state[1] = RMD_H1;
rctx->state[2] = RMD_H2;
rctx->state[3] = RMD_H3;
memset(rctx->buffer, 0, sizeof(rctx->buffer));
return 0;
}
static int rmd128_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct rmd128_ctx *rctx = shash_desc_ctx(desc);
const u32 avail = sizeof(rctx->buffer) - (rctx->byte_count & 0x3f);
rctx->byte_count += len;
if (avail > len) {
memcpy((char *)rctx->buffer + (sizeof(rctx->buffer) - avail),
data, len);
goto out;
}
memcpy((char *)rctx->buffer + (sizeof(rctx->buffer) - avail),
data, avail);
rmd128_transform(rctx->state, rctx->buffer);
data += avail;
len -= avail;
while (len >= sizeof(rctx->buffer)) {
memcpy(rctx->buffer, data, sizeof(rctx->buffer));
rmd128_transform(rctx->state, rctx->buffer);
data += sizeof(rctx->buffer);
len -= sizeof(rctx->buffer);
}
memcpy(rctx->buffer, data, len);
out:
return 0;
}
static int rmd128_final(struct shash_desc *desc, u8 *out)
{
struct rmd128_ctx *rctx = shash_desc_ctx(desc);
u32 i, index, padlen;
__le64 bits;
__le32 *dst = (__le32 *)out;
static const u8 padding[64] = { 0x80, };
bits = cpu_to_le64(rctx->byte_count << 3);
index = rctx->byte_count & 0x3f;
padlen = (index < 56) ? (56 - index) : ((64+56) - index);
rmd128_update(desc, padding, padlen);
rmd128_update(desc, (const u8 *)&bits, sizeof(bits));
for (i = 0; i < 4; i++)
dst[i] = cpu_to_le32p(&rctx->state[i]);
memset(rctx, 0, sizeof(*rctx));
return 0;
}
static int __init rmd128_mod_init(void)
{
return crypto_register_shash(&alg);
}
static void __exit rmd128_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
