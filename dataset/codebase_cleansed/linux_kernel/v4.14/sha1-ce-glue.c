static int sha1_ce_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha1_ce_state *sctx = shash_desc_ctx(desc);
if (!may_use_simd())
return crypto_sha1_update(desc, data, len);
sctx->finalize = 0;
kernel_neon_begin();
sha1_base_do_update(desc, data, len,
(sha1_block_fn *)sha1_ce_transform);
kernel_neon_end();
return 0;
}
static int sha1_ce_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
struct sha1_ce_state *sctx = shash_desc_ctx(desc);
bool finalize = !sctx->sst.count && !(len % SHA1_BLOCK_SIZE);
if (!may_use_simd())
return crypto_sha1_finup(desc, data, len, out);
sctx->finalize = finalize;
kernel_neon_begin();
sha1_base_do_update(desc, data, len,
(sha1_block_fn *)sha1_ce_transform);
if (!finalize)
sha1_base_do_finalize(desc, (sha1_block_fn *)sha1_ce_transform);
kernel_neon_end();
return sha1_base_finish(desc, out);
}
static int sha1_ce_final(struct shash_desc *desc, u8 *out)
{
struct sha1_ce_state *sctx = shash_desc_ctx(desc);
if (!may_use_simd())
return crypto_sha1_finup(desc, NULL, 0, out);
sctx->finalize = 0;
kernel_neon_begin();
sha1_base_do_finalize(desc, (sha1_block_fn *)sha1_ce_transform);
kernel_neon_end();
return sha1_base_finish(desc, out);
}
static int __init sha1_ce_mod_init(void)
{
return crypto_register_shash(&alg);
}
static void __exit sha1_ce_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
