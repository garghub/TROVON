__u16 crc_t10dif_update(__u16 crc, const unsigned char *buffer, size_t len)
{
struct {
struct shash_desc shash;
char ctx[2];
} desc;
int err;
if (static_key_false(&crct10dif_fallback))
return crc_t10dif_generic(crc, buffer, len);
desc.shash.tfm = crct10dif_tfm;
desc.shash.flags = 0;
*(__u16 *)desc.ctx = crc;
err = crypto_shash_update(&desc.shash, buffer, len);
BUG_ON(err);
return *(__u16 *)desc.ctx;
}
__u16 crc_t10dif(const unsigned char *buffer, size_t len)
{
return crc_t10dif_update(0, buffer, len);
}
static int __init crc_t10dif_mod_init(void)
{
crct10dif_tfm = crypto_alloc_shash("crct10dif", 0, 0);
if (IS_ERR(crct10dif_tfm)) {
static_key_slow_inc(&crct10dif_fallback);
crct10dif_tfm = NULL;
}
return 0;
}
static void __exit crc_t10dif_mod_fini(void)
{
crypto_free_shash(crct10dif_tfm);
}
