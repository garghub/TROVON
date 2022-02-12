static int sha256_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
if (!may_use_simd() ||
(sctx->count % SHA256_BLOCK_SIZE) + len < SHA256_BLOCK_SIZE)
return crypto_sha256_arm_update(desc, data, len);
kernel_neon_begin();
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_block_data_order_neon);
kernel_neon_end();
return 0;
}
static int sha256_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
if (!may_use_simd())
return crypto_sha256_arm_finup(desc, data, len, out);
kernel_neon_begin();
if (len)
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_block_data_order_neon);
sha256_base_do_finalize(desc,
(sha256_block_fn *)sha256_block_data_order_neon);
kernel_neon_end();
return sha256_base_finish(desc, out);
}
static int sha256_final(struct shash_desc *desc, u8 *out)
{
return sha256_finup(desc, NULL, 0, out);
}
