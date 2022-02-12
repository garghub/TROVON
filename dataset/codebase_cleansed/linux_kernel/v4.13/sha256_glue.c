int crypto_sha256_arm_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
BUILD_BUG_ON(offsetof(struct sha256_state, state) != 0);
return sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_block_data_order);
}
static int sha256_final(struct shash_desc *desc, u8 *out)
{
sha256_base_do_finalize(desc,
(sha256_block_fn *)sha256_block_data_order);
return sha256_base_finish(desc, out);
}
int crypto_sha256_arm_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_block_data_order);
return sha256_final(desc, out);
}
static int __init sha256_mod_init(void)
{
int res = crypto_register_shashes(algs, ARRAY_SIZE(algs));
if (res < 0)
return res;
if (IS_ENABLED(CONFIG_KERNEL_MODE_NEON) && cpu_has_neon()) {
res = crypto_register_shashes(sha256_neon_algs,
ARRAY_SIZE(sha256_neon_algs));
if (res < 0)
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
}
return res;
}
static void __exit sha256_mod_fini(void)
{
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
if (IS_ENABLED(CONFIG_KERNEL_MODE_NEON) && cpu_has_neon())
crypto_unregister_shashes(sha256_neon_algs,
ARRAY_SIZE(sha256_neon_algs));
}
