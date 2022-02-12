static inline u8 byte(const u32 x, const unsigned n)
{
return x >> (n << 3);
}
int crypto_aes_expand_key(struct crypto_aes_ctx *ctx, const u8 *in_key,
unsigned int key_len)
{
u32 i, t, u, v, w, j;
if (key_len != AES_KEYSIZE_128 && key_len != AES_KEYSIZE_192 &&
key_len != AES_KEYSIZE_256)
return -EINVAL;
ctx->key_length = key_len;
ctx->key_enc[0] = get_unaligned_le32(in_key);
ctx->key_enc[1] = get_unaligned_le32(in_key + 4);
ctx->key_enc[2] = get_unaligned_le32(in_key + 8);
ctx->key_enc[3] = get_unaligned_le32(in_key + 12);
ctx->key_dec[key_len + 24] = ctx->key_enc[0];
ctx->key_dec[key_len + 25] = ctx->key_enc[1];
ctx->key_dec[key_len + 26] = ctx->key_enc[2];
ctx->key_dec[key_len + 27] = ctx->key_enc[3];
switch (key_len) {
case AES_KEYSIZE_128:
t = ctx->key_enc[3];
for (i = 0; i < 10; ++i)
loop4(i);
break;
case AES_KEYSIZE_192:
ctx->key_enc[4] = get_unaligned_le32(in_key + 16);
t = ctx->key_enc[5] = get_unaligned_le32(in_key + 20);
for (i = 0; i < 8; ++i)
loop6(i);
break;
case AES_KEYSIZE_256:
ctx->key_enc[4] = get_unaligned_le32(in_key + 16);
ctx->key_enc[5] = get_unaligned_le32(in_key + 20);
ctx->key_enc[6] = get_unaligned_le32(in_key + 24);
t = ctx->key_enc[7] = get_unaligned_le32(in_key + 28);
for (i = 0; i < 6; ++i)
loop8(i);
loop8tophalf(i);
break;
}
ctx->key_dec[0] = ctx->key_enc[key_len + 24];
ctx->key_dec[1] = ctx->key_enc[key_len + 25];
ctx->key_dec[2] = ctx->key_enc[key_len + 26];
ctx->key_dec[3] = ctx->key_enc[key_len + 27];
for (i = 4; i < key_len + 24; ++i) {
j = key_len + 24 - (i & ~3) + (i & 3);
imix_col(ctx->key_dec[j], ctx->key_enc[i]);
}
return 0;
}
int crypto_aes_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct crypto_aes_ctx *ctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
int ret;
ret = crypto_aes_expand_key(ctx, in_key, key_len);
if (!ret)
return 0;
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
static void aes_encrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
const struct crypto_aes_ctx *ctx = crypto_tfm_ctx(tfm);
u32 b0[4], b1[4];
const u32 *kp = ctx->key_enc + 4;
const int key_len = ctx->key_length;
b0[0] = ctx->key_enc[0] ^ get_unaligned_le32(in);
b0[1] = ctx->key_enc[1] ^ get_unaligned_le32(in + 4);
b0[2] = ctx->key_enc[2] ^ get_unaligned_le32(in + 8);
b0[3] = ctx->key_enc[3] ^ get_unaligned_le32(in + 12);
if (key_len > 24) {
f_nround(b1, b0, kp);
f_nround(b0, b1, kp);
}
if (key_len > 16) {
f_nround(b1, b0, kp);
f_nround(b0, b1, kp);
}
f_nround(b1, b0, kp);
f_nround(b0, b1, kp);
f_nround(b1, b0, kp);
f_nround(b0, b1, kp);
f_nround(b1, b0, kp);
f_nround(b0, b1, kp);
f_nround(b1, b0, kp);
f_nround(b0, b1, kp);
f_nround(b1, b0, kp);
f_lround(b0, b1, kp);
put_unaligned_le32(b0[0], out);
put_unaligned_le32(b0[1], out + 4);
put_unaligned_le32(b0[2], out + 8);
put_unaligned_le32(b0[3], out + 12);
}
static void aes_decrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
const struct crypto_aes_ctx *ctx = crypto_tfm_ctx(tfm);
u32 b0[4], b1[4];
const int key_len = ctx->key_length;
const u32 *kp = ctx->key_dec + 4;
b0[0] = ctx->key_dec[0] ^ get_unaligned_le32(in);
b0[1] = ctx->key_dec[1] ^ get_unaligned_le32(in + 4);
b0[2] = ctx->key_dec[2] ^ get_unaligned_le32(in + 8);
b0[3] = ctx->key_dec[3] ^ get_unaligned_le32(in + 12);
if (key_len > 24) {
i_nround(b1, b0, kp);
i_nround(b0, b1, kp);
}
if (key_len > 16) {
i_nround(b1, b0, kp);
i_nround(b0, b1, kp);
}
i_nround(b1, b0, kp);
i_nround(b0, b1, kp);
i_nround(b1, b0, kp);
i_nround(b0, b1, kp);
i_nround(b1, b0, kp);
i_nround(b0, b1, kp);
i_nround(b1, b0, kp);
i_nround(b0, b1, kp);
i_nround(b1, b0, kp);
i_lround(b0, b1, kp);
put_unaligned_le32(b0[0], out);
put_unaligned_le32(b0[1], out + 4);
put_unaligned_le32(b0[2], out + 8);
put_unaligned_le32(b0[3], out + 12);
}
static int __init aes_init(void)
{
return crypto_register_alg(&aes_alg);
}
static void __exit aes_fini(void)
{
crypto_unregister_alg(&aes_alg);
}
