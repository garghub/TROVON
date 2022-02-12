static int num_rounds(struct crypto_aes_ctx *ctx)
{
return 6 + ctx->key_length / 4;
}
static void aes_cipher_encrypt(struct crypto_tfm *tfm, u8 dst[], u8 const src[])
{
struct crypto_aes_ctx *ctx = crypto_tfm_ctx(tfm);
struct aes_block *out = (struct aes_block *)dst;
struct aes_block const *in = (struct aes_block *)src;
void *dummy0;
int dummy1;
kernel_neon_begin_partial(4);
__asm__(" ld1 {v0.16b}, %[in] ;"
" ld1 {v1.2d}, [%[key]], #16 ;"
" cmp %w[rounds], #10 ;"
" bmi 0f ;"
" bne 3f ;"
" mov v3.16b, v1.16b ;"
" b 2f ;"
"0: mov v2.16b, v1.16b ;"
" ld1 {v3.2d}, [%[key]], #16 ;"
"1: aese v0.16b, v2.16b ;"
" aesmc v0.16b, v0.16b ;"
"2: ld1 {v1.2d}, [%[key]], #16 ;"
" aese v0.16b, v3.16b ;"
" aesmc v0.16b, v0.16b ;"
"3: ld1 {v2.2d}, [%[key]], #16 ;"
" subs %w[rounds], %w[rounds], #3 ;"
" aese v0.16b, v1.16b ;"
" aesmc v0.16b, v0.16b ;"
" ld1 {v3.2d}, [%[key]], #16 ;"
" bpl 1b ;"
" aese v0.16b, v2.16b ;"
" eor v0.16b, v0.16b, v3.16b ;"
" st1 {v0.16b}, %[out] ;"
: [out] "=Q"(*out),
[key] "=r"(dummy0),
[rounds] "=r"(dummy1)
: [in] "Q"(*in),
"1"(ctx->key_enc),
"2"(num_rounds(ctx) - 2)
: "cc");
kernel_neon_end();
}
static void aes_cipher_decrypt(struct crypto_tfm *tfm, u8 dst[], u8 const src[])
{
struct crypto_aes_ctx *ctx = crypto_tfm_ctx(tfm);
struct aes_block *out = (struct aes_block *)dst;
struct aes_block const *in = (struct aes_block *)src;
void *dummy0;
int dummy1;
kernel_neon_begin_partial(4);
__asm__(" ld1 {v0.16b}, %[in] ;"
" ld1 {v1.2d}, [%[key]], #16 ;"
" cmp %w[rounds], #10 ;"
" bmi 0f ;"
" bne 3f ;"
" mov v3.16b, v1.16b ;"
" b 2f ;"
"0: mov v2.16b, v1.16b ;"
" ld1 {v3.2d}, [%[key]], #16 ;"
"1: aesd v0.16b, v2.16b ;"
" aesimc v0.16b, v0.16b ;"
"2: ld1 {v1.2d}, [%[key]], #16 ;"
" aesd v0.16b, v3.16b ;"
" aesimc v0.16b, v0.16b ;"
"3: ld1 {v2.2d}, [%[key]], #16 ;"
" subs %w[rounds], %w[rounds], #3 ;"
" aesd v0.16b, v1.16b ;"
" aesimc v0.16b, v0.16b ;"
" ld1 {v3.2d}, [%[key]], #16 ;"
" bpl 1b ;"
" aesd v0.16b, v2.16b ;"
" eor v0.16b, v0.16b, v3.16b ;"
" st1 {v0.16b}, %[out] ;"
: [out] "=Q"(*out),
[key] "=r"(dummy0),
[rounds] "=r"(dummy1)
: [in] "Q"(*in),
"1"(ctx->key_dec),
"2"(num_rounds(ctx) - 2)
: "cc");
kernel_neon_end();
}
static int __init aes_mod_init(void)
{
return crypto_register_alg(&aes_alg);
}
static void __exit aes_mod_exit(void)
{
crypto_unregister_alg(&aes_alg);
}
