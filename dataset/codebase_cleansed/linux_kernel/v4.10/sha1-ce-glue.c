static int sha1_ce_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
if (!may_use_simd() ||
(sctx->count % SHA1_BLOCK_SIZE) + len < SHA1_BLOCK_SIZE)
return sha1_update_arm(desc, data, len);
kernel_neon_begin();
sha1_base_do_update(desc, data, len, sha1_ce_transform);
kernel_neon_end();
return 0;
}
static int sha1_ce_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
if (!may_use_simd())
return sha1_finup_arm(desc, data, len, out);
kernel_neon_begin();
if (len)
sha1_base_do_update(desc, data, len, sha1_ce_transform);
sha1_base_do_finalize(desc, sha1_ce_transform);
kernel_neon_end();
return sha1_base_finish(desc, out);
}
static int sha1_ce_final(struct shash_desc *desc, u8 *out)
{
return sha1_ce_finup(desc, NULL, 0, out);
}
static int __init sha1_ce_mod_init(void)
{
if (!(elf_hwcap2 & HWCAP2_SHA1))
return -ENODEV;
return crypto_register_shash(&alg);
}
static void __exit sha1_ce_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
