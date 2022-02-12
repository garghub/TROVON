static u32 mul_by_x(u32 w)
{
u32 x = w & 0x7f7f7f7f;
u32 y = w & 0x80808080;
return (x << 1) ^ (y >> 7) * 0x1b;
}
static u32 mul_by_x2(u32 w)
{
u32 x = w & 0x3f3f3f3f;
u32 y = w & 0x80808080;
u32 z = w & 0x40404040;
return (x << 2) ^ (y >> 7) * 0x36 ^ (z >> 6) * 0x1b;
}
static u32 mix_columns(u32 x)
{
u32 y = mul_by_x(x) ^ ror32(x, 16);
return y ^ ror32(x ^ y, 8);
}
static u32 inv_mix_columns(u32 x)
{
u32 y = mul_by_x2(x);
return mix_columns(x ^ y ^ ror32(y, 16));
}
static __always_inline u32 subshift(u32 in[], int pos)
{
return (__aesti_sbox[in[pos] & 0xff]) ^
(__aesti_sbox[(in[(pos + 1) % 4] >> 8) & 0xff] << 8) ^
(__aesti_sbox[(in[(pos + 2) % 4] >> 16) & 0xff] << 16) ^
(__aesti_sbox[(in[(pos + 3) % 4] >> 24) & 0xff] << 24);
}
static __always_inline u32 inv_subshift(u32 in[], int pos)
{
return (__aesti_inv_sbox[in[pos] & 0xff]) ^
(__aesti_inv_sbox[(in[(pos + 3) % 4] >> 8) & 0xff] << 8) ^
(__aesti_inv_sbox[(in[(pos + 2) % 4] >> 16) & 0xff] << 16) ^
(__aesti_inv_sbox[(in[(pos + 1) % 4] >> 24) & 0xff] << 24);
}
static u32 subw(u32 in)
{
return (__aesti_sbox[in & 0xff]) ^
(__aesti_sbox[(in >> 8) & 0xff] << 8) ^
(__aesti_sbox[(in >> 16) & 0xff] << 16) ^
(__aesti_sbox[(in >> 24) & 0xff] << 24);
}
static int aesti_expand_key(struct crypto_aes_ctx *ctx, const u8 *in_key,
unsigned int key_len)
{
u32 kwords = key_len / sizeof(u32);
u32 rc, i, j;
if (key_len != AES_KEYSIZE_128 &&
key_len != AES_KEYSIZE_192 &&
key_len != AES_KEYSIZE_256)
return -EINVAL;
ctx->key_length = key_len;
for (i = 0; i < kwords; i++)
ctx->key_enc[i] = get_unaligned_le32(in_key + i * sizeof(u32));
for (i = 0, rc = 1; i < 10; i++, rc = mul_by_x(rc)) {
u32 *rki = ctx->key_enc + (i * kwords);
u32 *rko = rki + kwords;
rko[0] = ror32(subw(rki[kwords - 1]), 8) ^ rc ^ rki[0];
rko[1] = rko[0] ^ rki[1];
rko[2] = rko[1] ^ rki[2];
rko[3] = rko[2] ^ rki[3];
if (key_len == 24) {
if (i >= 7)
break;
rko[4] = rko[3] ^ rki[4];
rko[5] = rko[4] ^ rki[5];
} else if (key_len == 32) {
if (i >= 6)
break;
rko[4] = subw(rko[3]) ^ rki[4];
rko[5] = rko[4] ^ rki[5];
rko[6] = rko[5] ^ rki[6];
rko[7] = rko[6] ^ rki[7];
}
}
ctx->key_dec[0] = ctx->key_enc[key_len + 24];
ctx->key_dec[1] = ctx->key_enc[key_len + 25];
ctx->key_dec[2] = ctx->key_enc[key_len + 26];
ctx->key_dec[3] = ctx->key_enc[key_len + 27];
for (i = 4, j = key_len + 20; j > 0; i += 4, j -= 4) {
ctx->key_dec[i] = inv_mix_columns(ctx->key_enc[j]);
ctx->key_dec[i + 1] = inv_mix_columns(ctx->key_enc[j + 1]);
ctx->key_dec[i + 2] = inv_mix_columns(ctx->key_enc[j + 2]);
ctx->key_dec[i + 3] = inv_mix_columns(ctx->key_enc[j + 3]);
}
ctx->key_dec[i] = ctx->key_enc[0];
ctx->key_dec[i + 1] = ctx->key_enc[1];
ctx->key_dec[i + 2] = ctx->key_enc[2];
ctx->key_dec[i + 3] = ctx->key_enc[3];
return 0;
}
static int aesti_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct crypto_aes_ctx *ctx = crypto_tfm_ctx(tfm);
int err;
err = aesti_expand_key(ctx, in_key, key_len);
if (err)
return err;
ctx->key_enc[0] ^= __aesti_sbox[ 0] ^ __aesti_sbox[128];
ctx->key_enc[1] ^= __aesti_sbox[32] ^ __aesti_sbox[160];
ctx->key_enc[2] ^= __aesti_sbox[64] ^ __aesti_sbox[192];
ctx->key_enc[3] ^= __aesti_sbox[96] ^ __aesti_sbox[224];
ctx->key_dec[0] ^= __aesti_inv_sbox[ 0] ^ __aesti_inv_sbox[128];
ctx->key_dec[1] ^= __aesti_inv_sbox[32] ^ __aesti_inv_sbox[160];
ctx->key_dec[2] ^= __aesti_inv_sbox[64] ^ __aesti_inv_sbox[192];
ctx->key_dec[3] ^= __aesti_inv_sbox[96] ^ __aesti_inv_sbox[224];
return 0;
}
static void aesti_encrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
const struct crypto_aes_ctx *ctx = crypto_tfm_ctx(tfm);
const u32 *rkp = ctx->key_enc + 4;
int rounds = 6 + ctx->key_length / 4;
u32 st0[4], st1[4];
int round;
st0[0] = ctx->key_enc[0] ^ get_unaligned_le32(in);
st0[1] = ctx->key_enc[1] ^ get_unaligned_le32(in + 4);
st0[2] = ctx->key_enc[2] ^ get_unaligned_le32(in + 8);
st0[3] = ctx->key_enc[3] ^ get_unaligned_le32(in + 12);
st0[0] ^= __aesti_sbox[ 0] ^ __aesti_sbox[128];
st0[1] ^= __aesti_sbox[32] ^ __aesti_sbox[160];
st0[2] ^= __aesti_sbox[64] ^ __aesti_sbox[192];
st0[3] ^= __aesti_sbox[96] ^ __aesti_sbox[224];
for (round = 0;; round += 2, rkp += 8) {
st1[0] = mix_columns(subshift(st0, 0)) ^ rkp[0];
st1[1] = mix_columns(subshift(st0, 1)) ^ rkp[1];
st1[2] = mix_columns(subshift(st0, 2)) ^ rkp[2];
st1[3] = mix_columns(subshift(st0, 3)) ^ rkp[3];
if (round == rounds - 2)
break;
st0[0] = mix_columns(subshift(st1, 0)) ^ rkp[4];
st0[1] = mix_columns(subshift(st1, 1)) ^ rkp[5];
st0[2] = mix_columns(subshift(st1, 2)) ^ rkp[6];
st0[3] = mix_columns(subshift(st1, 3)) ^ rkp[7];
}
put_unaligned_le32(subshift(st1, 0) ^ rkp[4], out);
put_unaligned_le32(subshift(st1, 1) ^ rkp[5], out + 4);
put_unaligned_le32(subshift(st1, 2) ^ rkp[6], out + 8);
put_unaligned_le32(subshift(st1, 3) ^ rkp[7], out + 12);
}
static void aesti_decrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
const struct crypto_aes_ctx *ctx = crypto_tfm_ctx(tfm);
const u32 *rkp = ctx->key_dec + 4;
int rounds = 6 + ctx->key_length / 4;
u32 st0[4], st1[4];
int round;
st0[0] = ctx->key_dec[0] ^ get_unaligned_le32(in);
st0[1] = ctx->key_dec[1] ^ get_unaligned_le32(in + 4);
st0[2] = ctx->key_dec[2] ^ get_unaligned_le32(in + 8);
st0[3] = ctx->key_dec[3] ^ get_unaligned_le32(in + 12);
st0[0] ^= __aesti_inv_sbox[ 0] ^ __aesti_inv_sbox[128];
st0[1] ^= __aesti_inv_sbox[32] ^ __aesti_inv_sbox[160];
st0[2] ^= __aesti_inv_sbox[64] ^ __aesti_inv_sbox[192];
st0[3] ^= __aesti_inv_sbox[96] ^ __aesti_inv_sbox[224];
for (round = 0;; round += 2, rkp += 8) {
st1[0] = inv_mix_columns(inv_subshift(st0, 0)) ^ rkp[0];
st1[1] = inv_mix_columns(inv_subshift(st0, 1)) ^ rkp[1];
st1[2] = inv_mix_columns(inv_subshift(st0, 2)) ^ rkp[2];
st1[3] = inv_mix_columns(inv_subshift(st0, 3)) ^ rkp[3];
if (round == rounds - 2)
break;
st0[0] = inv_mix_columns(inv_subshift(st1, 0)) ^ rkp[4];
st0[1] = inv_mix_columns(inv_subshift(st1, 1)) ^ rkp[5];
st0[2] = inv_mix_columns(inv_subshift(st1, 2)) ^ rkp[6];
st0[3] = inv_mix_columns(inv_subshift(st1, 3)) ^ rkp[7];
}
put_unaligned_le32(inv_subshift(st1, 0) ^ rkp[4], out);
put_unaligned_le32(inv_subshift(st1, 1) ^ rkp[5], out + 4);
put_unaligned_le32(inv_subshift(st1, 2) ^ rkp[6], out + 8);
put_unaligned_le32(inv_subshift(st1, 3) ^ rkp[7], out + 12);
}
static int __init aes_init(void)
{
return crypto_register_alg(&aes_alg);
}
static void __exit aes_fini(void)
{
crypto_unregister_alg(&aes_alg);
}
