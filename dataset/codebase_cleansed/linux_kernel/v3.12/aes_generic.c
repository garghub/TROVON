static inline u8 byte(const u32 x, const unsigned n)
{
return x >> (n << 3);
}
int crypto_aes_expand_key(struct crypto_aes_ctx *ctx, const u8 *in_key,
unsigned int key_len)
{
const __le32 *key = (const __le32 *)in_key;
u32 i, t, u, v, w, j;
if (key_len != AES_KEYSIZE_128 && key_len != AES_KEYSIZE_192 &&
key_len != AES_KEYSIZE_256)
return -EINVAL;
ctx->key_length = key_len;
ctx->key_dec[key_len + 24] = ctx->key_enc[0] = le32_to_cpu(key[0]);
ctx->key_dec[key_len + 25] = ctx->key_enc[1] = le32_to_cpu(key[1]);
ctx->key_dec[key_len + 26] = ctx->key_enc[2] = le32_to_cpu(key[2]);
ctx->key_dec[key_len + 27] = ctx->key_enc[3] = le32_to_cpu(key[3]);
switch (key_len) {
case AES_KEYSIZE_128:
t = ctx->key_enc[3];
for (i = 0; i < 10; ++i)
loop4(i);
break;
case AES_KEYSIZE_192:
ctx->key_enc[4] = le32_to_cpu(key[4]);
t = ctx->key_enc[5] = le32_to_cpu(key[5]);
for (i = 0; i < 8; ++i)
loop6(i);
break;
case AES_KEYSIZE_256:
ctx->key_enc[4] = le32_to_cpu(key[4]);
ctx->key_enc[5] = le32_to_cpu(key[5]);
ctx->key_enc[6] = le32_to_cpu(key[6]);
t = ctx->key_enc[7] = le32_to_cpu(key[7]);
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
const __le32 *src = (const __le32 *)in;
__le32 *dst = (__le32 *)out;
u32 b0[4], b1[4];
const u32 *kp = ctx->key_enc + 4;
const int key_len = ctx->key_length;
b0[0] = le32_to_cpu(src[0]) ^ ctx->key_enc[0];
b0[1] = le32_to_cpu(src[1]) ^ ctx->key_enc[1];
b0[2] = le32_to_cpu(src[2]) ^ ctx->key_enc[2];
b0[3] = le32_to_cpu(src[3]) ^ ctx->key_enc[3];
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
dst[0] = cpu_to_le32(b0[0]);
dst[1] = cpu_to_le32(b0[1]);
dst[2] = cpu_to_le32(b0[2]);
dst[3] = cpu_to_le32(b0[3]);
}
static void aes_decrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
const struct crypto_aes_ctx *ctx = crypto_tfm_ctx(tfm);
const __le32 *src = (const __le32 *)in;
__le32 *dst = (__le32 *)out;
u32 b0[4], b1[4];
const int key_len = ctx->key_length;
const u32 *kp = ctx->key_dec + 4;
b0[0] = le32_to_cpu(src[0]) ^ ctx->key_dec[0];
b0[1] = le32_to_cpu(src[1]) ^ ctx->key_dec[1];
b0[2] = le32_to_cpu(src[2]) ^ ctx->key_dec[2];
b0[3] = le32_to_cpu(src[3]) ^ ctx->key_dec[3];
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
dst[0] = cpu_to_le32(b0[0]);
dst[1] = cpu_to_le32(b0[1]);
dst[2] = cpu_to_le32(b0[2]);
dst[3] = cpu_to_le32(b0[3]);
}
static int __init aes_init(void)
{
return crypto_register_alg(&aes_alg);
}
static void __exit aes_fini(void)
{
crypto_unregister_alg(&aes_alg);
}
