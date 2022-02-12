static int sha256_ce_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha256_ce_state *sctx = shash_desc_ctx(desc);
if (!may_use_simd())
return sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_block_data_order);
sctx->finalize = 0;
kernel_neon_begin();
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha2_ce_transform);
kernel_neon_end();
return 0;
}
static int sha256_ce_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
struct sha256_ce_state *sctx = shash_desc_ctx(desc);
bool finalize = !sctx->sst.count && !(len % SHA256_BLOCK_SIZE);
if (!may_use_simd()) {
if (len)
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_block_data_order);
sha256_base_do_finalize(desc,
(sha256_block_fn *)sha256_block_data_order);
return sha256_base_finish(desc, out);
}
sctx->finalize = finalize;
kernel_neon_begin();
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha2_ce_transform);
if (!finalize)
sha256_base_do_finalize(desc,
(sha256_block_fn *)sha2_ce_transform);
kernel_neon_end();
return sha256_base_finish(desc, out);
}
static int sha256_ce_final(struct shash_desc *desc, u8 *out)
{
struct sha256_ce_state *sctx = shash_desc_ctx(desc);
if (!may_use_simd()) {
sha256_base_do_finalize(desc,
(sha256_block_fn *)sha256_block_data_order);
return sha256_base_finish(desc, out);
}
sctx->finalize = 0;
kernel_neon_begin();
sha256_base_do_finalize(desc, (sha256_block_fn *)sha2_ce_transform);
kernel_neon_end();
return sha256_base_finish(desc, out);
}
static int __init sha2_ce_mod_init(void)
{
return crypto_register_shashes(algs, ARRAY_SIZE(algs));
}
static void __exit sha2_ce_mod_fini(void)
{
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
}
