unsigned long des_ekey(u32 *pe, const u8 *k)
{
unsigned long a, b, c, d, w;
const u32 *pt = pc2;
d = k[4]; d &= 0x0e; d <<= 4; d |= k[0] & 0x1e; d = pc1[d];
c = k[5]; c &= 0x0e; c <<= 4; c |= k[1] & 0x1e; c = pc1[c];
b = k[6]; b &= 0x0e; b <<= 4; b |= k[2] & 0x1e; b = pc1[b];
a = k[7]; a &= 0x0e; a <<= 4; a |= k[3] & 0x1e; a = pc1[a];
pe[15 * 2 + 0] = DES_PC2(a, b, c, d); d = rs[d];
pe[14 * 2 + 0] = DES_PC2(d, a, b, c); c = rs[c]; b = rs[b];
pe[13 * 2 + 0] = DES_PC2(b, c, d, a); a = rs[a]; d = rs[d];
pe[12 * 2 + 0] = DES_PC2(d, a, b, c); c = rs[c]; b = rs[b];
pe[11 * 2 + 0] = DES_PC2(b, c, d, a); a = rs[a]; d = rs[d];
pe[10 * 2 + 0] = DES_PC2(d, a, b, c); c = rs[c]; b = rs[b];
pe[ 9 * 2 + 0] = DES_PC2(b, c, d, a); a = rs[a]; d = rs[d];
pe[ 8 * 2 + 0] = DES_PC2(d, a, b, c); c = rs[c];
pe[ 7 * 2 + 0] = DES_PC2(c, d, a, b); b = rs[b]; a = rs[a];
pe[ 6 * 2 + 0] = DES_PC2(a, b, c, d); d = rs[d]; c = rs[c];
pe[ 5 * 2 + 0] = DES_PC2(c, d, a, b); b = rs[b]; a = rs[a];
pe[ 4 * 2 + 0] = DES_PC2(a, b, c, d); d = rs[d]; c = rs[c];
pe[ 3 * 2 + 0] = DES_PC2(c, d, a, b); b = rs[b]; a = rs[a];
pe[ 2 * 2 + 0] = DES_PC2(a, b, c, d); d = rs[d]; c = rs[c];
pe[ 1 * 2 + 0] = DES_PC2(c, d, a, b); b = rs[b];
pe[ 0 * 2 + 0] = DES_PC2(b, c, d, a);
w = (a ^ c) | (b ^ d) | (rs[a] ^ c) | (b ^ rs[d]);
pt += 512;
d = k[0]; d &= 0xe0; d >>= 4; d |= k[4] & 0xf0; d = pc1[d + 1];
c = k[1]; c &= 0xe0; c >>= 4; c |= k[5] & 0xf0; c = pc1[c + 1];
b = k[2]; b &= 0xe0; b >>= 4; b |= k[6] & 0xf0; b = pc1[b + 1];
a = k[3]; a &= 0xe0; a >>= 4; a |= k[7] & 0xf0; a = pc1[a + 1];
w |= (a ^ c) | (b ^ d) | (rs[a] ^ c) | (b ^ rs[d]);
pe[15 * 2 + 1] = DES_PC2(a, b, c, d); d = rs[d];
pe[14 * 2 + 1] = DES_PC2(d, a, b, c); c = rs[c]; b = rs[b];
pe[13 * 2 + 1] = DES_PC2(b, c, d, a); a = rs[a]; d = rs[d];
pe[12 * 2 + 1] = DES_PC2(d, a, b, c); c = rs[c]; b = rs[b];
pe[11 * 2 + 1] = DES_PC2(b, c, d, a); a = rs[a]; d = rs[d];
pe[10 * 2 + 1] = DES_PC2(d, a, b, c); c = rs[c]; b = rs[b];
pe[ 9 * 2 + 1] = DES_PC2(b, c, d, a); a = rs[a]; d = rs[d];
pe[ 8 * 2 + 1] = DES_PC2(d, a, b, c); c = rs[c];
pe[ 7 * 2 + 1] = DES_PC2(c, d, a, b); b = rs[b]; a = rs[a];
pe[ 6 * 2 + 1] = DES_PC2(a, b, c, d); d = rs[d]; c = rs[c];
pe[ 5 * 2 + 1] = DES_PC2(c, d, a, b); b = rs[b]; a = rs[a];
pe[ 4 * 2 + 1] = DES_PC2(a, b, c, d); d = rs[d]; c = rs[c];
pe[ 3 * 2 + 1] = DES_PC2(c, d, a, b); b = rs[b]; a = rs[a];
pe[ 2 * 2 + 1] = DES_PC2(a, b, c, d); d = rs[d]; c = rs[c];
pe[ 1 * 2 + 1] = DES_PC2(c, d, a, b); b = rs[b];
pe[ 0 * 2 + 1] = DES_PC2(b, c, d, a);
for (d = 0; d < 16; ++d) {
a = pe[2 * d];
b = pe[2 * d + 1];
c = a ^ b;
c &= 0xffff0000;
a ^= c;
b ^= c;
ROL(b, 18);
pe[2 * d] = a;
pe[2 * d + 1] = b;
}
return w;
}
static void dkey(u32 *pe, const u8 *k)
{
unsigned long a, b, c, d;
const u32 *pt = pc2;
d = k[4]; d &= 0x0e; d <<= 4; d |= k[0] & 0x1e; d = pc1[d];
c = k[5]; c &= 0x0e; c <<= 4; c |= k[1] & 0x1e; c = pc1[c];
b = k[6]; b &= 0x0e; b <<= 4; b |= k[2] & 0x1e; b = pc1[b];
a = k[7]; a &= 0x0e; a <<= 4; a |= k[3] & 0x1e; a = pc1[a];
pe[ 0 * 2] = DES_PC2(a, b, c, d); d = rs[d];
pe[ 1 * 2] = DES_PC2(d, a, b, c); c = rs[c]; b = rs[b];
pe[ 2 * 2] = DES_PC2(b, c, d, a); a = rs[a]; d = rs[d];
pe[ 3 * 2] = DES_PC2(d, a, b, c); c = rs[c]; b = rs[b];
pe[ 4 * 2] = DES_PC2(b, c, d, a); a = rs[a]; d = rs[d];
pe[ 5 * 2] = DES_PC2(d, a, b, c); c = rs[c]; b = rs[b];
pe[ 6 * 2] = DES_PC2(b, c, d, a); a = rs[a]; d = rs[d];
pe[ 7 * 2] = DES_PC2(d, a, b, c); c = rs[c];
pe[ 8 * 2] = DES_PC2(c, d, a, b); b = rs[b]; a = rs[a];
pe[ 9 * 2] = DES_PC2(a, b, c, d); d = rs[d]; c = rs[c];
pe[10 * 2] = DES_PC2(c, d, a, b); b = rs[b]; a = rs[a];
pe[11 * 2] = DES_PC2(a, b, c, d); d = rs[d]; c = rs[c];
pe[12 * 2] = DES_PC2(c, d, a, b); b = rs[b]; a = rs[a];
pe[13 * 2] = DES_PC2(a, b, c, d); d = rs[d]; c = rs[c];
pe[14 * 2] = DES_PC2(c, d, a, b); b = rs[b];
pe[15 * 2] = DES_PC2(b, c, d, a);
pt += 512;
d = k[0]; d &= 0xe0; d >>= 4; d |= k[4] & 0xf0; d = pc1[d + 1];
c = k[1]; c &= 0xe0; c >>= 4; c |= k[5] & 0xf0; c = pc1[c + 1];
b = k[2]; b &= 0xe0; b >>= 4; b |= k[6] & 0xf0; b = pc1[b + 1];
a = k[3]; a &= 0xe0; a >>= 4; a |= k[7] & 0xf0; a = pc1[a + 1];
pe[ 0 * 2 + 1] = DES_PC2(a, b, c, d); d = rs[d];
pe[ 1 * 2 + 1] = DES_PC2(d, a, b, c); c = rs[c]; b = rs[b];
pe[ 2 * 2 + 1] = DES_PC2(b, c, d, a); a = rs[a]; d = rs[d];
pe[ 3 * 2 + 1] = DES_PC2(d, a, b, c); c = rs[c]; b = rs[b];
pe[ 4 * 2 + 1] = DES_PC2(b, c, d, a); a = rs[a]; d = rs[d];
pe[ 5 * 2 + 1] = DES_PC2(d, a, b, c); c = rs[c]; b = rs[b];
pe[ 6 * 2 + 1] = DES_PC2(b, c, d, a); a = rs[a]; d = rs[d];
pe[ 7 * 2 + 1] = DES_PC2(d, a, b, c); c = rs[c];
pe[ 8 * 2 + 1] = DES_PC2(c, d, a, b); b = rs[b]; a = rs[a];
pe[ 9 * 2 + 1] = DES_PC2(a, b, c, d); d = rs[d]; c = rs[c];
pe[10 * 2 + 1] = DES_PC2(c, d, a, b); b = rs[b]; a = rs[a];
pe[11 * 2 + 1] = DES_PC2(a, b, c, d); d = rs[d]; c = rs[c];
pe[12 * 2 + 1] = DES_PC2(c, d, a, b); b = rs[b]; a = rs[a];
pe[13 * 2 + 1] = DES_PC2(a, b, c, d); d = rs[d]; c = rs[c];
pe[14 * 2 + 1] = DES_PC2(c, d, a, b); b = rs[b];
pe[15 * 2 + 1] = DES_PC2(b, c, d, a);
for (d = 0; d < 16; ++d) {
a = pe[2 * d];
b = pe[2 * d + 1];
c = a ^ b;
c &= 0xffff0000;
a ^= c;
b ^= c;
ROL(b, 18);
pe[2 * d] = a;
pe[2 * d + 1] = b;
}
}
static int des_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct des_ctx *dctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
u32 tmp[DES_EXPKEY_WORDS];
int ret;
ret = des_ekey(tmp, key);
if (unlikely(ret == 0) && (*flags & CRYPTO_TFM_REQ_WEAK_KEY)) {
*flags |= CRYPTO_TFM_RES_WEAK_KEY;
return -EINVAL;
}
memcpy(dctx->expkey, tmp, sizeof(dctx->expkey));
return 0;
}
static void des_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct des_ctx *ctx = crypto_tfm_ctx(tfm);
const u32 *K = ctx->expkey;
const __le32 *s = (const __le32 *)src;
__le32 *d = (__le32 *)dst;
u32 L, R, A, B;
int i;
L = le32_to_cpu(s[0]);
R = le32_to_cpu(s[1]);
IP(L, R, A);
for (i = 0; i < 8; i++) {
ROUND(L, R, A, B, K, 2);
ROUND(R, L, A, B, K, 2);
}
FP(R, L, A);
d[0] = cpu_to_le32(R);
d[1] = cpu_to_le32(L);
}
static void des_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct des_ctx *ctx = crypto_tfm_ctx(tfm);
const u32 *K = ctx->expkey + DES_EXPKEY_WORDS - 2;
const __le32 *s = (const __le32 *)src;
__le32 *d = (__le32 *)dst;
u32 L, R, A, B;
int i;
L = le32_to_cpu(s[0]);
R = le32_to_cpu(s[1]);
IP(L, R, A);
for (i = 0; i < 8; i++) {
ROUND(L, R, A, B, K, -2);
ROUND(R, L, A, B, K, -2);
}
FP(R, L, A);
d[0] = cpu_to_le32(R);
d[1] = cpu_to_le32(L);
}
int __des3_ede_setkey(u32 *expkey, u32 *flags, const u8 *key,
unsigned int keylen)
{
const u32 *K = (const u32 *)key;
if (unlikely(!((K[0] ^ K[2]) | (K[1] ^ K[3])) ||
!((K[2] ^ K[4]) | (K[3] ^ K[5]))) &&
(*flags & CRYPTO_TFM_REQ_WEAK_KEY)) {
*flags |= CRYPTO_TFM_RES_WEAK_KEY;
return -EINVAL;
}
des_ekey(expkey, key); expkey += DES_EXPKEY_WORDS; key += DES_KEY_SIZE;
dkey(expkey, key); expkey += DES_EXPKEY_WORDS; key += DES_KEY_SIZE;
des_ekey(expkey, key);
return 0;
}
static int des3_ede_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct des3_ede_ctx *dctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
u32 *expkey = dctx->expkey;
return __des3_ede_setkey(expkey, flags, key, keylen);
}
static void des3_ede_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct des3_ede_ctx *dctx = crypto_tfm_ctx(tfm);
const u32 *K = dctx->expkey;
const __le32 *s = (const __le32 *)src;
__le32 *d = (__le32 *)dst;
u32 L, R, A, B;
int i;
L = le32_to_cpu(s[0]);
R = le32_to_cpu(s[1]);
IP(L, R, A);
for (i = 0; i < 8; i++) {
ROUND(L, R, A, B, K, 2);
ROUND(R, L, A, B, K, 2);
}
for (i = 0; i < 8; i++) {
ROUND(R, L, A, B, K, 2);
ROUND(L, R, A, B, K, 2);
}
for (i = 0; i < 8; i++) {
ROUND(L, R, A, B, K, 2);
ROUND(R, L, A, B, K, 2);
}
FP(R, L, A);
d[0] = cpu_to_le32(R);
d[1] = cpu_to_le32(L);
}
static void des3_ede_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct des3_ede_ctx *dctx = crypto_tfm_ctx(tfm);
const u32 *K = dctx->expkey + DES3_EDE_EXPKEY_WORDS - 2;
const __le32 *s = (const __le32 *)src;
__le32 *d = (__le32 *)dst;
u32 L, R, A, B;
int i;
L = le32_to_cpu(s[0]);
R = le32_to_cpu(s[1]);
IP(L, R, A);
for (i = 0; i < 8; i++) {
ROUND(L, R, A, B, K, -2);
ROUND(R, L, A, B, K, -2);
}
for (i = 0; i < 8; i++) {
ROUND(R, L, A, B, K, -2);
ROUND(L, R, A, B, K, -2);
}
for (i = 0; i < 8; i++) {
ROUND(L, R, A, B, K, -2);
ROUND(R, L, A, B, K, -2);
}
FP(R, L, A);
d[0] = cpu_to_le32(R);
d[1] = cpu_to_le32(L);
}
static int __init des_generic_mod_init(void)
{
return crypto_register_algs(des_algs, ARRAY_SIZE(des_algs));
}
static void __exit des_generic_mod_fini(void)
{
crypto_unregister_algs(des_algs, ARRAY_SIZE(des_algs));
}
