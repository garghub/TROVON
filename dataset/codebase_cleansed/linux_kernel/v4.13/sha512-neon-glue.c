static int sha512_neon_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
if (!may_use_simd() ||
(sctx->count[0] % SHA512_BLOCK_SIZE) + len < SHA512_BLOCK_SIZE)
return sha512_arm_update(desc, data, len);
kernel_neon_begin();
sha512_base_do_update(desc, data, len,
(sha512_block_fn *)sha512_block_data_order_neon);
kernel_neon_end();
return 0;
}
static int sha512_neon_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
if (!may_use_simd())
return sha512_arm_finup(desc, data, len, out);
kernel_neon_begin();
if (len)
sha512_base_do_update(desc, data, len,
(sha512_block_fn *)sha512_block_data_order_neon);
sha512_base_do_finalize(desc,
(sha512_block_fn *)sha512_block_data_order_neon);
kernel_neon_end();
return sha512_base_finish(desc, out);
}
static int sha512_neon_final(struct shash_desc *desc, u8 *out)
{
return sha512_neon_finup(desc, NULL, 0, out);
}
