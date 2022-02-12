u32 crc32c(u32 crc, const void *address, unsigned int length)
{
SHASH_DESC_ON_STACK(shash, tfm);
u32 ret, *ctx = (u32 *)shash_desc_ctx(shash);
int err;
shash->tfm = tfm;
shash->flags = 0;
*ctx = crc;
err = crypto_shash_update(shash, address, length);
BUG_ON(err);
ret = *ctx;
barrier_data(ctx);
return ret;
}
static int __init libcrc32c_mod_init(void)
{
tfm = crypto_alloc_shash("crc32c", 0, 0);
return PTR_ERR_OR_ZERO(tfm);
}
static void __exit libcrc32c_mod_fini(void)
{
crypto_free_shash(tfm);
}
