static int sha256_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_block_data_order);
}
static int sha256_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
if (len)
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_block_data_order);
sha256_base_do_finalize(desc,
(sha256_block_fn *)sha256_block_data_order);
return sha256_base_finish(desc, out);
}
static int sha256_final(struct shash_desc *desc, u8 *out)
{
return sha256_finup(desc, NULL, 0, out);
}
static int sha256_update_neon(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
if (!may_use_simd())
return sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_block_data_order);
kernel_neon_begin();
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_block_neon);
kernel_neon_end();
return 0;
}
static int sha256_finup_neon(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
if (!may_use_simd()) {
if (len)
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_block_data_order);
sha256_base_do_finalize(desc,
(sha256_block_fn *)sha256_block_data_order);
} else {
kernel_neon_begin();
if (len)
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_block_neon);
sha256_base_do_finalize(desc,
(sha256_block_fn *)sha256_block_neon);
kernel_neon_end();
}
return sha256_base_finish(desc, out);
}
static int sha256_final_neon(struct shash_desc *desc, u8 *out)
{
return sha256_finup_neon(desc, NULL, 0, out);
}
static int __init sha256_mod_init(void)
{
int ret = crypto_register_shashes(algs, ARRAY_SIZE(algs));
if (ret)
return ret;
if (elf_hwcap & HWCAP_ASIMD) {
ret = crypto_register_shashes(neon_algs, ARRAY_SIZE(neon_algs));
if (ret)
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
}
return ret;
}
static void __exit sha256_mod_fini(void)
{
if (elf_hwcap & HWCAP_ASIMD)
crypto_unregister_shashes(neon_algs, ARRAY_SIZE(neon_algs));
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
}
