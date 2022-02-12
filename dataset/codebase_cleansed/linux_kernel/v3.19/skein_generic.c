static int skein256_init(struct shash_desc *desc)
{
return skein_256_init((struct skein_256_ctx *) shash_desc_ctx(desc),
SKEIN256_DIGEST_BIT_SIZE);
}
static int skein256_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return skein_256_update((struct skein_256_ctx *)shash_desc_ctx(desc),
data, len);
}
static int skein256_final(struct shash_desc *desc, u8 *out)
{
return skein_256_final((struct skein_256_ctx *)shash_desc_ctx(desc),
out);
}
static int skein256_export(struct shash_desc *desc, void *out)
{
struct skein_256_ctx *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int skein256_import(struct shash_desc *desc, const void *in)
{
struct skein_256_ctx *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int skein512_init(struct shash_desc *desc)
{
return skein_512_init((struct skein_512_ctx *)shash_desc_ctx(desc),
SKEIN512_DIGEST_BIT_SIZE);
}
static int skein512_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return skein_512_update((struct skein_512_ctx *)shash_desc_ctx(desc),
data, len);
}
static int skein512_final(struct shash_desc *desc, u8 *out)
{
return skein_512_final((struct skein_512_ctx *)shash_desc_ctx(desc),
out);
}
static int skein512_export(struct shash_desc *desc, void *out)
{
struct skein_512_ctx *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int skein512_import(struct shash_desc *desc, const void *in)
{
struct skein_512_ctx *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int skein1024_init(struct shash_desc *desc)
{
return skein_1024_init((struct skein_1024_ctx *)shash_desc_ctx(desc),
SKEIN1024_DIGEST_BIT_SIZE);
}
static int skein1024_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return skein_1024_update((struct skein_1024_ctx *)shash_desc_ctx(desc),
data, len);
}
static int skein1024_final(struct shash_desc *desc, u8 *out)
{
return skein_1024_final((struct skein_1024_ctx *)shash_desc_ctx(desc),
out);
}
static int skein1024_export(struct shash_desc *desc, void *out)
{
struct skein_1024_ctx *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int skein1024_import(struct shash_desc *desc, const void *in)
{
struct skein_1024_ctx *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int __init skein_generic_init(void)
{
if (crypto_register_shash(&alg256))
goto out;
if (crypto_register_shash(&alg512))
goto unreg256;
if (crypto_register_shash(&alg1024))
goto unreg512;
return 0;
unreg512:
crypto_unregister_shash(&alg512);
unreg256:
crypto_unregister_shash(&alg256);
out:
return -1;
}
static void __exit skein_generic_fini(void)
{
crypto_unregister_shash(&alg256);
crypto_unregister_shash(&alg512);
crypto_unregister_shash(&alg1024);
}
