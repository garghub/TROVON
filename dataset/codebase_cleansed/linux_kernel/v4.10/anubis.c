static int anubis_setkey(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct anubis_ctx *ctx = crypto_tfm_ctx(tfm);
const __be32 *key = (const __be32 *)in_key;
u32 *flags = &tfm->crt_flags;
int N, R, i, r;
u32 kappa[ANUBIS_MAX_N];
u32 inter[ANUBIS_MAX_N];
switch (key_len) {
case 16: case 20: case 24: case 28:
case 32: case 36: case 40:
break;
default:
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
ctx->key_len = key_len * 8;
N = ctx->key_len >> 5;
ctx->R = R = 8 + N;
for (i = 0; i < N; i++)
kappa[i] = be32_to_cpu(key[i]);
for (r = 0; r <= R; r++) {
u32 K0, K1, K2, K3;
K0 = T4[(kappa[N - 1] >> 24) ];
K1 = T4[(kappa[N - 1] >> 16) & 0xff];
K2 = T4[(kappa[N - 1] >> 8) & 0xff];
K3 = T4[(kappa[N - 1] ) & 0xff];
for (i = N - 2; i >= 0; i--) {
K0 = T4[(kappa[i] >> 24) ] ^
(T5[(K0 >> 24) ] & 0xff000000U) ^
(T5[(K0 >> 16) & 0xff] & 0x00ff0000U) ^
(T5[(K0 >> 8) & 0xff] & 0x0000ff00U) ^
(T5[(K0 ) & 0xff] & 0x000000ffU);
K1 = T4[(kappa[i] >> 16) & 0xff] ^
(T5[(K1 >> 24) ] & 0xff000000U) ^
(T5[(K1 >> 16) & 0xff] & 0x00ff0000U) ^
(T5[(K1 >> 8) & 0xff] & 0x0000ff00U) ^
(T5[(K1 ) & 0xff] & 0x000000ffU);
K2 = T4[(kappa[i] >> 8) & 0xff] ^
(T5[(K2 >> 24) ] & 0xff000000U) ^
(T5[(K2 >> 16) & 0xff] & 0x00ff0000U) ^
(T5[(K2 >> 8) & 0xff] & 0x0000ff00U) ^
(T5[(K2 ) & 0xff] & 0x000000ffU);
K3 = T4[(kappa[i] ) & 0xff] ^
(T5[(K3 >> 24) ] & 0xff000000U) ^
(T5[(K3 >> 16) & 0xff] & 0x00ff0000U) ^
(T5[(K3 >> 8) & 0xff] & 0x0000ff00U) ^
(T5[(K3 ) & 0xff] & 0x000000ffU);
}
ctx->E[r][0] = K0;
ctx->E[r][1] = K1;
ctx->E[r][2] = K2;
ctx->E[r][3] = K3;
if (r == R)
break;
for (i = 0; i < N; i++) {
int j = i;
inter[i] = T0[(kappa[j--] >> 24) ];
if (j < 0)
j = N - 1;
inter[i] ^= T1[(kappa[j--] >> 16) & 0xff];
if (j < 0)
j = N - 1;
inter[i] ^= T2[(kappa[j--] >> 8) & 0xff];
if (j < 0)
j = N - 1;
inter[i] ^= T3[(kappa[j ] ) & 0xff];
}
kappa[0] = inter[0] ^ rc[r];
for (i = 1; i < N; i++)
kappa[i] = inter[i];
}
for (i = 0; i < 4; i++) {
ctx->D[0][i] = ctx->E[R][i];
ctx->D[R][i] = ctx->E[0][i];
}
for (r = 1; r < R; r++) {
for (i = 0; i < 4; i++) {
u32 v = ctx->E[R - r][i];
ctx->D[r][i] =
T0[T4[(v >> 24) ] & 0xff] ^
T1[T4[(v >> 16) & 0xff] & 0xff] ^
T2[T4[(v >> 8) & 0xff] & 0xff] ^
T3[T4[(v ) & 0xff] & 0xff];
}
}
return 0;
}
static void anubis_crypt(u32 roundKey[ANUBIS_MAX_ROUNDS + 1][4],
u8 *ciphertext, const u8 *plaintext, const int R)
{
const __be32 *src = (const __be32 *)plaintext;
__be32 *dst = (__be32 *)ciphertext;
int i, r;
u32 state[4];
u32 inter[4];
for (i = 0; i < 4; i++)
state[i] = be32_to_cpu(src[i]) ^ roundKey[0][i];
for (r = 1; r < R; r++) {
inter[0] =
T0[(state[0] >> 24) ] ^
T1[(state[1] >> 24) ] ^
T2[(state[2] >> 24) ] ^
T3[(state[3] >> 24) ] ^
roundKey[r][0];
inter[1] =
T0[(state[0] >> 16) & 0xff] ^
T1[(state[1] >> 16) & 0xff] ^
T2[(state[2] >> 16) & 0xff] ^
T3[(state[3] >> 16) & 0xff] ^
roundKey[r][1];
inter[2] =
T0[(state[0] >> 8) & 0xff] ^
T1[(state[1] >> 8) & 0xff] ^
T2[(state[2] >> 8) & 0xff] ^
T3[(state[3] >> 8) & 0xff] ^
roundKey[r][2];
inter[3] =
T0[(state[0] ) & 0xff] ^
T1[(state[1] ) & 0xff] ^
T2[(state[2] ) & 0xff] ^
T3[(state[3] ) & 0xff] ^
roundKey[r][3];
state[0] = inter[0];
state[1] = inter[1];
state[2] = inter[2];
state[3] = inter[3];
}
inter[0] =
(T0[(state[0] >> 24) ] & 0xff000000U) ^
(T1[(state[1] >> 24) ] & 0x00ff0000U) ^
(T2[(state[2] >> 24) ] & 0x0000ff00U) ^
(T3[(state[3] >> 24) ] & 0x000000ffU) ^
roundKey[R][0];
inter[1] =
(T0[(state[0] >> 16) & 0xff] & 0xff000000U) ^
(T1[(state[1] >> 16) & 0xff] & 0x00ff0000U) ^
(T2[(state[2] >> 16) & 0xff] & 0x0000ff00U) ^
(T3[(state[3] >> 16) & 0xff] & 0x000000ffU) ^
roundKey[R][1];
inter[2] =
(T0[(state[0] >> 8) & 0xff] & 0xff000000U) ^
(T1[(state[1] >> 8) & 0xff] & 0x00ff0000U) ^
(T2[(state[2] >> 8) & 0xff] & 0x0000ff00U) ^
(T3[(state[3] >> 8) & 0xff] & 0x000000ffU) ^
roundKey[R][2];
inter[3] =
(T0[(state[0] ) & 0xff] & 0xff000000U) ^
(T1[(state[1] ) & 0xff] & 0x00ff0000U) ^
(T2[(state[2] ) & 0xff] & 0x0000ff00U) ^
(T3[(state[3] ) & 0xff] & 0x000000ffU) ^
roundKey[R][3];
for (i = 0; i < 4; i++)
dst[i] = cpu_to_be32(inter[i]);
}
static void anubis_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct anubis_ctx *ctx = crypto_tfm_ctx(tfm);
anubis_crypt(ctx->E, dst, src, ctx->R);
}
static void anubis_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct anubis_ctx *ctx = crypto_tfm_ctx(tfm);
anubis_crypt(ctx->D, dst, src, ctx->R);
}
static int __init anubis_mod_init(void)
{
int ret = 0;
ret = crypto_register_alg(&anubis_alg);
return ret;
}
static void __exit anubis_mod_fini(void)
{
crypto_unregister_alg(&anubis_alg);
}
