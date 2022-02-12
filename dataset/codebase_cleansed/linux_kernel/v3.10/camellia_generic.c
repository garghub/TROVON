static void camellia_setup_tail(u32 *subkey, u32 *subL, u32 *subR, int max)
{
u32 dw, tl, tr;
u32 kw4l, kw4r;
subL[3] ^= subL[1]; subR[3] ^= subR[1];
subL[5] ^= subL[1]; subR[5] ^= subR[1];
subL[7] ^= subL[1]; subR[7] ^= subR[1];
subL[1] ^= subR[1] & ~subR[9];
dw = subL[1] & subL[9],
subR[1] ^= rol32(dw, 1);
subL[11] ^= subL[1]; subR[11] ^= subR[1];
subL[13] ^= subL[1]; subR[13] ^= subR[1];
subL[15] ^= subL[1]; subR[15] ^= subR[1];
subL[1] ^= subR[1] & ~subR[17];
dw = subL[1] & subL[17],
subR[1] ^= rol32(dw, 1);
subL[19] ^= subL[1]; subR[19] ^= subR[1];
subL[21] ^= subL[1]; subR[21] ^= subR[1];
subL[23] ^= subL[1]; subR[23] ^= subR[1];
if (max == 24) {
subL[24] ^= subL[1]; subR[24] ^= subR[1];
kw4l = subL[25]; kw4r = subR[25];
} else {
subL[1] ^= subR[1] & ~subR[25];
dw = subL[1] & subL[25],
subR[1] ^= rol32(dw, 1);
subL[27] ^= subL[1]; subR[27] ^= subR[1];
subL[29] ^= subL[1]; subR[29] ^= subR[1];
subL[31] ^= subL[1]; subR[31] ^= subR[1];
subL[32] ^= subL[1]; subR[32] ^= subR[1];
kw4l = subL[33]; kw4r = subR[33];
subL[30] ^= kw4l; subR[30] ^= kw4r;
subL[28] ^= kw4l; subR[28] ^= kw4r;
subL[26] ^= kw4l; subR[26] ^= kw4r;
kw4l ^= kw4r & ~subR[24];
dw = kw4l & subL[24],
kw4r ^= rol32(dw, 1);
}
subL[22] ^= kw4l; subR[22] ^= kw4r;
subL[20] ^= kw4l; subR[20] ^= kw4r;
subL[18] ^= kw4l; subR[18] ^= kw4r;
kw4l ^= kw4r & ~subR[16];
dw = kw4l & subL[16],
kw4r ^= rol32(dw, 1);
subL[14] ^= kw4l; subR[14] ^= kw4r;
subL[12] ^= kw4l; subR[12] ^= kw4r;
subL[10] ^= kw4l; subR[10] ^= kw4r;
kw4l ^= kw4r & ~subR[8];
dw = kw4l & subL[8],
kw4r ^= rol32(dw, 1);
subL[6] ^= kw4l; subR[6] ^= kw4r;
subL[4] ^= kw4l; subR[4] ^= kw4r;
subL[2] ^= kw4l; subR[2] ^= kw4r;
subL[0] ^= kw4l; subR[0] ^= kw4r;
SUBKEY_L(0) = subL[0] ^ subL[2];
SUBKEY_R(0) = subR[0] ^ subR[2];
SUBKEY_L(2) = subL[3];
SUBKEY_R(2) = subR[3];
SUBKEY_L(3) = subL[2] ^ subL[4];
SUBKEY_R(3) = subR[2] ^ subR[4];
SUBKEY_L(4) = subL[3] ^ subL[5];
SUBKEY_R(4) = subR[3] ^ subR[5];
SUBKEY_L(5) = subL[4] ^ subL[6];
SUBKEY_R(5) = subR[4] ^ subR[6];
SUBKEY_L(6) = subL[5] ^ subL[7];
SUBKEY_R(6) = subR[5] ^ subR[7];
tl = subL[10] ^ (subR[10] & ~subR[8]);
dw = tl & subL[8],
tr = subR[10] ^ rol32(dw, 1);
SUBKEY_L(7) = subL[6] ^ tl;
SUBKEY_R(7) = subR[6] ^ tr;
SUBKEY_L(8) = subL[8];
SUBKEY_R(8) = subR[8];
SUBKEY_L(9) = subL[9];
SUBKEY_R(9) = subR[9];
tl = subL[7] ^ (subR[7] & ~subR[9]);
dw = tl & subL[9],
tr = subR[7] ^ rol32(dw, 1);
SUBKEY_L(10) = tl ^ subL[11];
SUBKEY_R(10) = tr ^ subR[11];
SUBKEY_L(11) = subL[10] ^ subL[12];
SUBKEY_R(11) = subR[10] ^ subR[12];
SUBKEY_L(12) = subL[11] ^ subL[13];
SUBKEY_R(12) = subR[11] ^ subR[13];
SUBKEY_L(13) = subL[12] ^ subL[14];
SUBKEY_R(13) = subR[12] ^ subR[14];
SUBKEY_L(14) = subL[13] ^ subL[15];
SUBKEY_R(14) = subR[13] ^ subR[15];
tl = subL[18] ^ (subR[18] & ~subR[16]);
dw = tl & subL[16],
tr = subR[18] ^ rol32(dw, 1);
SUBKEY_L(15) = subL[14] ^ tl;
SUBKEY_R(15) = subR[14] ^ tr;
SUBKEY_L(16) = subL[16];
SUBKEY_R(16) = subR[16];
SUBKEY_L(17) = subL[17];
SUBKEY_R(17) = subR[17];
tl = subL[15] ^ (subR[15] & ~subR[17]);
dw = tl & subL[17],
tr = subR[15] ^ rol32(dw, 1);
SUBKEY_L(18) = tl ^ subL[19];
SUBKEY_R(18) = tr ^ subR[19];
SUBKEY_L(19) = subL[18] ^ subL[20];
SUBKEY_R(19) = subR[18] ^ subR[20];
SUBKEY_L(20) = subL[19] ^ subL[21];
SUBKEY_R(20) = subR[19] ^ subR[21];
SUBKEY_L(21) = subL[20] ^ subL[22];
SUBKEY_R(21) = subR[20] ^ subR[22];
SUBKEY_L(22) = subL[21] ^ subL[23];
SUBKEY_R(22) = subR[21] ^ subR[23];
if (max == 24) {
SUBKEY_L(23) = subL[22];
SUBKEY_R(23) = subR[22];
SUBKEY_L(24) = subL[24] ^ subL[23];
SUBKEY_R(24) = subR[24] ^ subR[23];
} else {
tl = subL[26] ^ (subR[26] & ~subR[24]);
dw = tl & subL[24],
tr = subR[26] ^ rol32(dw, 1);
SUBKEY_L(23) = subL[22] ^ tl;
SUBKEY_R(23) = subR[22] ^ tr;
SUBKEY_L(24) = subL[24];
SUBKEY_R(24) = subR[24];
SUBKEY_L(25) = subL[25];
SUBKEY_R(25) = subR[25];
tl = subL[23] ^ (subR[23] & ~subR[25]);
dw = tl & subL[25],
tr = subR[23] ^ rol32(dw, 1);
SUBKEY_L(26) = tl ^ subL[27];
SUBKEY_R(26) = tr ^ subR[27];
SUBKEY_L(27) = subL[26] ^ subL[28];
SUBKEY_R(27) = subR[26] ^ subR[28];
SUBKEY_L(28) = subL[27] ^ subL[29];
SUBKEY_R(28) = subR[27] ^ subR[29];
SUBKEY_L(29) = subL[28] ^ subL[30];
SUBKEY_R(29) = subR[28] ^ subR[30];
SUBKEY_L(30) = subL[29] ^ subL[31];
SUBKEY_R(30) = subR[29] ^ subR[31];
SUBKEY_L(31) = subL[30];
SUBKEY_R(31) = subR[30];
SUBKEY_L(32) = subL[32] ^ subL[31];
SUBKEY_R(32) = subR[32] ^ subR[31];
}
}
static void camellia_setup128(const unsigned char *key, u32 *subkey)
{
u32 kll, klr, krl, krr;
u32 il, ir, t0, t1, w0, w1;
u32 subL[26];
u32 subR[26];
kll = get_unaligned_be32(key);
klr = get_unaligned_be32(key + 4);
krl = get_unaligned_be32(key + 8);
krr = get_unaligned_be32(key + 12);
subL[0] = kll; subR[0] = klr;
subL[1] = krl; subR[1] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 15);
subL[4] = kll; subR[4] = klr;
subL[5] = krl; subR[5] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 30);
subL[10] = kll; subR[10] = klr;
subL[11] = krl; subR[11] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 15);
subL[13] = krl; subR[13] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 17);
subL[16] = kll; subR[16] = klr;
subL[17] = krl; subR[17] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 17);
subL[18] = kll; subR[18] = klr;
subL[19] = krl; subR[19] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 17);
subL[22] = kll; subR[22] = klr;
subL[23] = krl; subR[23] = krr;
kll = subL[0]; klr = subR[0];
krl = subL[1]; krr = subR[1];
CAMELLIA_F(kll, klr,
CAMELLIA_SIGMA1L, CAMELLIA_SIGMA1R,
w0, w1, il, ir, t0, t1);
krl ^= w0; krr ^= w1;
CAMELLIA_F(krl, krr,
CAMELLIA_SIGMA2L, CAMELLIA_SIGMA2R,
kll, klr, il, ir, t0, t1);
CAMELLIA_F(kll, klr,
CAMELLIA_SIGMA3L, CAMELLIA_SIGMA3R,
krl, krr, il, ir, t0, t1);
krl ^= w0; krr ^= w1;
CAMELLIA_F(krl, krr,
CAMELLIA_SIGMA4L, CAMELLIA_SIGMA4R,
w0, w1, il, ir, t0, t1);
kll ^= w0; klr ^= w1;
subL[2] = kll; subR[2] = klr;
subL[3] = krl; subR[3] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 15);
subL[6] = kll; subR[6] = klr;
subL[7] = krl; subR[7] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 15);
subL[8] = kll; subR[8] = klr;
subL[9] = krl; subR[9] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 15);
subL[12] = kll; subR[12] = klr;
ROLDQ(kll, klr, krl, krr, w0, w1, 15);
subL[14] = kll; subR[14] = klr;
subL[15] = krl; subR[15] = krr;
ROLDQo32(kll, klr, krl, krr, w0, w1, 34);
subL[20] = kll; subR[20] = klr;
subL[21] = krl; subR[21] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 17);
subL[24] = kll; subR[24] = klr;
subL[25] = krl; subR[25] = krr;
camellia_setup_tail(subkey, subL, subR, 24);
}
static void camellia_setup256(const unsigned char *key, u32 *subkey)
{
u32 kll, klr, krl, krr;
u32 krll, krlr, krrl, krrr;
u32 il, ir, t0, t1, w0, w1;
u32 subL[34];
u32 subR[34];
kll = get_unaligned_be32(key);
klr = get_unaligned_be32(key + 4);
krl = get_unaligned_be32(key + 8);
krr = get_unaligned_be32(key + 12);
krll = get_unaligned_be32(key + 16);
krlr = get_unaligned_be32(key + 20);
krrl = get_unaligned_be32(key + 24);
krrr = get_unaligned_be32(key + 28);
subL[0] = kll; subR[0] = klr;
subL[1] = krl; subR[1] = krr;
ROLDQo32(kll, klr, krl, krr, w0, w1, 45);
subL[12] = kll; subR[12] = klr;
subL[13] = krl; subR[13] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 15);
subL[16] = kll; subR[16] = klr;
subL[17] = krl; subR[17] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 17);
subL[22] = kll; subR[22] = klr;
subL[23] = krl; subR[23] = krr;
ROLDQo32(kll, klr, krl, krr, w0, w1, 34);
subL[30] = kll; subR[30] = klr;
subL[31] = krl; subR[31] = krr;
ROLDQ(krll, krlr, krrl, krrr, w0, w1, 15);
subL[4] = krll; subR[4] = krlr;
subL[5] = krrl; subR[5] = krrr;
ROLDQ(krll, krlr, krrl, krrr, w0, w1, 15);
subL[8] = krll; subR[8] = krlr;
subL[9] = krrl; subR[9] = krrr;
ROLDQ(krll, krlr, krrl, krrr, w0, w1, 30);
subL[18] = krll; subR[18] = krlr;
subL[19] = krrl; subR[19] = krrr;
ROLDQo32(krll, krlr, krrl, krrr, w0, w1, 34);
subL[26] = krll; subR[26] = krlr;
subL[27] = krrl; subR[27] = krrr;
ROLDQo32(krll, krlr, krrl, krrr, w0, w1, 34);
kll = subL[0] ^ krll; klr = subR[0] ^ krlr;
krl = subL[1] ^ krrl; krr = subR[1] ^ krrr;
CAMELLIA_F(kll, klr,
CAMELLIA_SIGMA1L, CAMELLIA_SIGMA1R,
w0, w1, il, ir, t0, t1);
krl ^= w0; krr ^= w1;
CAMELLIA_F(krl, krr,
CAMELLIA_SIGMA2L, CAMELLIA_SIGMA2R,
kll, klr, il, ir, t0, t1);
kll ^= krll; klr ^= krlr;
CAMELLIA_F(kll, klr,
CAMELLIA_SIGMA3L, CAMELLIA_SIGMA3R,
krl, krr, il, ir, t0, t1);
krl ^= w0 ^ krrl; krr ^= w1 ^ krrr;
CAMELLIA_F(krl, krr,
CAMELLIA_SIGMA4L, CAMELLIA_SIGMA4R,
w0, w1, il, ir, t0, t1);
kll ^= w0; klr ^= w1;
krll ^= kll; krlr ^= klr;
krrl ^= krl; krrr ^= krr;
CAMELLIA_F(krll, krlr,
CAMELLIA_SIGMA5L, CAMELLIA_SIGMA5R,
w0, w1, il, ir, t0, t1);
krrl ^= w0; krrr ^= w1;
CAMELLIA_F(krrl, krrr,
CAMELLIA_SIGMA6L, CAMELLIA_SIGMA6R,
w0, w1, il, ir, t0, t1);
krll ^= w0; krlr ^= w1;
ROLDQ(kll, klr, krl, krr, w0, w1, 15);
subL[6] = kll; subR[6] = klr;
subL[7] = krl; subR[7] = krr;
ROLDQ(kll, klr, krl, krr, w0, w1, 30);
subL[14] = kll; subR[14] = klr;
subL[15] = krl; subR[15] = krr;
subL[24] = klr; subR[24] = krl;
subL[25] = krr; subR[25] = kll;
ROLDQo32(kll, klr, krl, krr, w0, w1, 49);
subL[28] = kll; subR[28] = klr;
subL[29] = krl; subR[29] = krr;
subL[2] = krll; subR[2] = krlr;
subL[3] = krrl; subR[3] = krrr;
ROLDQ(krll, krlr, krrl, krrr, w0, w1, 30);
subL[10] = krll; subR[10] = krlr;
subL[11] = krrl; subR[11] = krrr;
ROLDQ(krll, krlr, krrl, krrr, w0, w1, 30);
subL[20] = krll; subR[20] = krlr;
subL[21] = krrl; subR[21] = krrr;
ROLDQo32(krll, krlr, krrl, krrr, w0, w1, 51);
subL[32] = krll; subR[32] = krlr;
subL[33] = krrl; subR[33] = krrr;
camellia_setup_tail(subkey, subL, subR, 32);
}
static void camellia_setup192(const unsigned char *key, u32 *subkey)
{
unsigned char kk[32];
u32 krll, krlr, krrl, krrr;
memcpy(kk, key, 24);
memcpy((unsigned char *)&krll, key+16, 4);
memcpy((unsigned char *)&krlr, key+20, 4);
krrl = ~krll;
krrr = ~krlr;
memcpy(kk+24, (unsigned char *)&krrl, 4);
memcpy(kk+28, (unsigned char *)&krrr, 4);
camellia_setup256(kk, subkey);
}
static void camellia_do_encrypt(const u32 *subkey, u32 *io, unsigned max)
{
u32 il, ir, t0, t1;
io[0] ^= SUBKEY_L(0);
io[1] ^= SUBKEY_R(0);
#define ROUNDS(i) ({ \
CAMELLIA_ROUNDSM(io[0], io[1], \
SUBKEY_L(i + 2), SUBKEY_R(i + 2), \
io[2], io[3], il, ir); \
CAMELLIA_ROUNDSM(io[2], io[3], \
SUBKEY_L(i + 3), SUBKEY_R(i + 3), \
io[0], io[1], il, ir); \
CAMELLIA_ROUNDSM(io[0], io[1], \
SUBKEY_L(i + 4), SUBKEY_R(i + 4), \
io[2], io[3], il, ir); \
CAMELLIA_ROUNDSM(io[2], io[3], \
SUBKEY_L(i + 5), SUBKEY_R(i + 5), \
io[0], io[1], il, ir); \
CAMELLIA_ROUNDSM(io[0], io[1], \
SUBKEY_L(i + 6), SUBKEY_R(i + 6), \
io[2], io[3], il, ir); \
CAMELLIA_ROUNDSM(io[2], io[3], \
SUBKEY_L(i + 7), SUBKEY_R(i + 7), \
io[0], io[1], il, ir); \
})
#define FLS(i) ({ \
CAMELLIA_FLS(io[0], io[1], io[2], io[3], \
SUBKEY_L(i + 0), SUBKEY_R(i + 0), \
SUBKEY_L(i + 1), SUBKEY_R(i + 1), \
t0, t1, il, ir); \
})
ROUNDS(0);
FLS(8);
ROUNDS(8);
FLS(16);
ROUNDS(16);
if (max == 32) {
FLS(24);
ROUNDS(24);
}
#undef ROUNDS
#undef FLS
io[2] ^= SUBKEY_L(max);
io[3] ^= SUBKEY_R(max);
}
static void camellia_do_decrypt(const u32 *subkey, u32 *io, unsigned i)
{
u32 il, ir, t0, t1;
io[0] ^= SUBKEY_L(i);
io[1] ^= SUBKEY_R(i);
#define ROUNDS(i) ({ \
CAMELLIA_ROUNDSM(io[0], io[1], \
SUBKEY_L(i + 7), SUBKEY_R(i + 7), \
io[2], io[3], il, ir); \
CAMELLIA_ROUNDSM(io[2], io[3], \
SUBKEY_L(i + 6), SUBKEY_R(i + 6), \
io[0], io[1], il, ir); \
CAMELLIA_ROUNDSM(io[0], io[1], \
SUBKEY_L(i + 5), SUBKEY_R(i + 5), \
io[2], io[3], il, ir); \
CAMELLIA_ROUNDSM(io[2], io[3], \
SUBKEY_L(i + 4), SUBKEY_R(i + 4), \
io[0], io[1], il, ir); \
CAMELLIA_ROUNDSM(io[0], io[1], \
SUBKEY_L(i + 3), SUBKEY_R(i + 3), \
io[2], io[3], il, ir); \
CAMELLIA_ROUNDSM(io[2], io[3], \
SUBKEY_L(i + 2), SUBKEY_R(i + 2), \
io[0], io[1], il, ir); \
})
#define FLS(i) ({ \
CAMELLIA_FLS(io[0], io[1], io[2], io[3], \
SUBKEY_L(i + 1), SUBKEY_R(i + 1), \
SUBKEY_L(i + 0), SUBKEY_R(i + 0), \
t0, t1, il, ir); \
})
if (i == 32) {
ROUNDS(24);
FLS(24);
}
ROUNDS(16);
FLS(16);
ROUNDS(8);
FLS(8);
ROUNDS(0);
#undef ROUNDS
#undef FLS
io[2] ^= SUBKEY_L(0);
io[3] ^= SUBKEY_R(0);
}
static int
camellia_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct camellia_ctx *cctx = crypto_tfm_ctx(tfm);
const unsigned char *key = (const unsigned char *)in_key;
u32 *flags = &tfm->crt_flags;
if (key_len != 16 && key_len != 24 && key_len != 32) {
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
cctx->key_length = key_len;
switch (key_len) {
case 16:
camellia_setup128(key, cctx->key_table);
break;
case 24:
camellia_setup192(key, cctx->key_table);
break;
case 32:
camellia_setup256(key, cctx->key_table);
break;
}
return 0;
}
static void camellia_encrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
const struct camellia_ctx *cctx = crypto_tfm_ctx(tfm);
const __be32 *src = (const __be32 *)in;
__be32 *dst = (__be32 *)out;
unsigned int max;
u32 tmp[4];
tmp[0] = be32_to_cpu(src[0]);
tmp[1] = be32_to_cpu(src[1]);
tmp[2] = be32_to_cpu(src[2]);
tmp[3] = be32_to_cpu(src[3]);
if (cctx->key_length == 16)
max = 24;
else
max = 32;
camellia_do_encrypt(cctx->key_table, tmp, max);
dst[0] = cpu_to_be32(tmp[2]);
dst[1] = cpu_to_be32(tmp[3]);
dst[2] = cpu_to_be32(tmp[0]);
dst[3] = cpu_to_be32(tmp[1]);
}
static void camellia_decrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
const struct camellia_ctx *cctx = crypto_tfm_ctx(tfm);
const __be32 *src = (const __be32 *)in;
__be32 *dst = (__be32 *)out;
unsigned int max;
u32 tmp[4];
tmp[0] = be32_to_cpu(src[0]);
tmp[1] = be32_to_cpu(src[1]);
tmp[2] = be32_to_cpu(src[2]);
tmp[3] = be32_to_cpu(src[3]);
if (cctx->key_length == 16)
max = 24;
else
max = 32;
camellia_do_decrypt(cctx->key_table, tmp, max);
dst[0] = cpu_to_be32(tmp[2]);
dst[1] = cpu_to_be32(tmp[3]);
dst[2] = cpu_to_be32(tmp[0]);
dst[3] = cpu_to_be32(tmp[1]);
}
static int __init camellia_init(void)
{
return crypto_register_alg(&camellia_alg);
}
static void __exit camellia_fini(void)
{
crypto_unregister_alg(&camellia_alg);
}
