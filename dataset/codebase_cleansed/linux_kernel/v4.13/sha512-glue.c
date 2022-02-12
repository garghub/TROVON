int sha512_arm_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha512_base_do_update(desc, data, len,
(sha512_block_fn *)sha512_block_data_order);
}
int sha512_arm_final(struct shash_desc *desc, u8 *out)
{
sha512_base_do_finalize(desc,
(sha512_block_fn *)sha512_block_data_order);
return sha512_base_finish(desc, out);
}
int sha512_arm_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
sha512_base_do_update(desc, data, len,
(sha512_block_fn *)sha512_block_data_order);
return sha512_arm_final(desc, out);
}
static int __init sha512_arm_mod_init(void)
{
int err;
err = crypto_register_shashes(sha512_arm_algs,
ARRAY_SIZE(sha512_arm_algs));
if (err)
return err;
if (IS_ENABLED(CONFIG_KERNEL_MODE_NEON) && cpu_has_neon()) {
err = crypto_register_shashes(sha512_neon_algs,
ARRAY_SIZE(sha512_neon_algs));
if (err)
goto err_unregister;
}
return 0;
err_unregister:
crypto_unregister_shashes(sha512_arm_algs,
ARRAY_SIZE(sha512_arm_algs));
return err;
}
static void __exit sha512_arm_mod_fini(void)
{
crypto_unregister_shashes(sha512_arm_algs,
ARRAY_SIZE(sha512_arm_algs));
if (IS_ENABLED(CONFIG_KERNEL_MODE_NEON) && cpu_has_neon())
crypto_unregister_shashes(sha512_neon_algs,
ARRAY_SIZE(sha512_neon_algs));
}
