static void twofish_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
twofish_enc_blk(crypto_tfm_ctx(tfm), dst, src);
}
static void twofish_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
twofish_dec_blk(crypto_tfm_ctx(tfm), dst, src);
}
static int __init init(void)
{
return crypto_register_alg(&alg);
}
static void __exit fini(void)
{
crypto_unregister_alg(&alg);
}
