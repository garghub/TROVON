static void aes_encrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
struct crypto_aes_ctx *ctx = crypto_tfm_ctx(tfm);
int rounds = 6 + ctx->key_length / 4;
__aes_arm_encrypt(ctx->key_enc, rounds, in, out);
}
static void aes_decrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
struct crypto_aes_ctx *ctx = crypto_tfm_ctx(tfm);
int rounds = 6 + ctx->key_length / 4;
__aes_arm_decrypt(ctx->key_dec, rounds, in, out);
}
static int __init aes_init(void)
{
return crypto_register_alg(&aes_alg);
}
static void __exit aes_fini(void)
{
crypto_unregister_alg(&aes_alg);
}
