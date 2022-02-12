static void sha1_generic_block_fn(struct sha1_state *sst, u8 const *src,
int blocks)
{
u32 temp[SHA_WORKSPACE_WORDS];
while (blocks--) {
sha_transform(sst->state, src, temp);
src += SHA1_BLOCK_SIZE;
}
memzero_explicit(temp, sizeof(temp));
}
int crypto_sha1_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha1_base_do_update(desc, data, len, sha1_generic_block_fn);
}
static int sha1_final(struct shash_desc *desc, u8 *out)
{
sha1_base_do_finalize(desc, sha1_generic_block_fn);
return sha1_base_finish(desc, out);
}
int crypto_sha1_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
sha1_base_do_update(desc, data, len, sha1_generic_block_fn);
return sha1_final(desc, out);
}
static int __init sha1_generic_mod_init(void)
{
return crypto_register_shash(&alg);
}
static void __exit sha1_generic_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
