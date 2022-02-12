static int khazad_setkey(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct khazad_ctx *ctx = crypto_tfm_ctx(tfm);
const __be32 *key = (const __be32 *)in_key;
int r;
const u64 *S = T7;
u64 K2, K1;
K2 = ((u64)be32_to_cpu(key[0]) << 32) | be32_to_cpu(key[1]);
K1 = ((u64)be32_to_cpu(key[2]) << 32) | be32_to_cpu(key[3]);
for (r = 0; r <= KHAZAD_ROUNDS; r++) {
ctx->E[r] = T0[(int)(K1 >> 56) ] ^
T1[(int)(K1 >> 48) & 0xff] ^
T2[(int)(K1 >> 40) & 0xff] ^
T3[(int)(K1 >> 32) & 0xff] ^
T4[(int)(K1 >> 24) & 0xff] ^
T5[(int)(K1 >> 16) & 0xff] ^
T6[(int)(K1 >> 8) & 0xff] ^
T7[(int)(K1 ) & 0xff] ^
c[r] ^ K2;
K2 = K1;
K1 = ctx->E[r];
}
ctx->D[0] = ctx->E[KHAZAD_ROUNDS];
for (r = 1; r < KHAZAD_ROUNDS; r++) {
K1 = ctx->E[KHAZAD_ROUNDS - r];
ctx->D[r] = T0[(int)S[(int)(K1 >> 56) ] & 0xff] ^
T1[(int)S[(int)(K1 >> 48) & 0xff] & 0xff] ^
T2[(int)S[(int)(K1 >> 40) & 0xff] & 0xff] ^
T3[(int)S[(int)(K1 >> 32) & 0xff] & 0xff] ^
T4[(int)S[(int)(K1 >> 24) & 0xff] & 0xff] ^
T5[(int)S[(int)(K1 >> 16) & 0xff] & 0xff] ^
T6[(int)S[(int)(K1 >> 8) & 0xff] & 0xff] ^
T7[(int)S[(int)(K1 ) & 0xff] & 0xff];
}
ctx->D[KHAZAD_ROUNDS] = ctx->E[0];
return 0;
}
static void khazad_crypt(const u64 roundKey[KHAZAD_ROUNDS + 1],
u8 *ciphertext, const u8 *plaintext)
{
const __be64 *src = (const __be64 *)plaintext;
__be64 *dst = (__be64 *)ciphertext;
int r;
u64 state;
state = be64_to_cpu(*src) ^ roundKey[0];
for (r = 1; r < KHAZAD_ROUNDS; r++) {
state = T0[(int)(state >> 56) ] ^
T1[(int)(state >> 48) & 0xff] ^
T2[(int)(state >> 40) & 0xff] ^
T3[(int)(state >> 32) & 0xff] ^
T4[(int)(state >> 24) & 0xff] ^
T5[(int)(state >> 16) & 0xff] ^
T6[(int)(state >> 8) & 0xff] ^
T7[(int)(state ) & 0xff] ^
roundKey[r];
}
state = (T0[(int)(state >> 56) ] & 0xff00000000000000ULL) ^
(T1[(int)(state >> 48) & 0xff] & 0x00ff000000000000ULL) ^
(T2[(int)(state >> 40) & 0xff] & 0x0000ff0000000000ULL) ^
(T3[(int)(state >> 32) & 0xff] & 0x000000ff00000000ULL) ^
(T4[(int)(state >> 24) & 0xff] & 0x00000000ff000000ULL) ^
(T5[(int)(state >> 16) & 0xff] & 0x0000000000ff0000ULL) ^
(T6[(int)(state >> 8) & 0xff] & 0x000000000000ff00ULL) ^
(T7[(int)(state ) & 0xff] & 0x00000000000000ffULL) ^
roundKey[KHAZAD_ROUNDS];
*dst = cpu_to_be64(state);
}
static void khazad_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct khazad_ctx *ctx = crypto_tfm_ctx(tfm);
khazad_crypt(ctx->E, dst, src);
}
static void khazad_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct khazad_ctx *ctx = crypto_tfm_ctx(tfm);
khazad_crypt(ctx->D, dst, src);
}
static int __init khazad_mod_init(void)
{
int ret = 0;
ret = crypto_register_alg(&khazad_alg);
return ret;
}
static void __exit khazad_mod_fini(void)
{
crypto_unregister_alg(&khazad_alg);
}
