void crypto_aes_encrypt_x86(struct crypto_aes_ctx *ctx, u8 *dst, const u8 *src)
{
aes_enc_blk(ctx, dst, src);
}
void crypto_aes_decrypt_x86(struct crypto_aes_ctx *ctx, u8 *dst, const u8 *src)
{
aes_dec_blk(ctx, dst, src);
}
static void aes_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
aes_enc_blk(crypto_tfm_ctx(tfm), dst, src);
}
static void aes_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
aes_dec_blk(crypto_tfm_ctx(tfm), dst, src);
}
static int __init aes_init(void)
{
return crypto_register_alg(&aes_alg);
}
static void __exit aes_fini(void)
{
crypto_unregister_alg(&aes_alg);
}
