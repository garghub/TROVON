static int sha256_init(struct shash_desc *desc)
{
struct s390_sha_ctx *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA256_H0;
sctx->state[1] = SHA256_H1;
sctx->state[2] = SHA256_H2;
sctx->state[3] = SHA256_H3;
sctx->state[4] = SHA256_H4;
sctx->state[5] = SHA256_H5;
sctx->state[6] = SHA256_H6;
sctx->state[7] = SHA256_H7;
sctx->count = 0;
sctx->func = KIMD_SHA_256;
return 0;
}
static int sha256_export(struct shash_desc *desc, void *out)
{
struct s390_sha_ctx *sctx = shash_desc_ctx(desc);
struct sha256_state *octx = out;
octx->count = sctx->count;
memcpy(octx->state, sctx->state, sizeof(octx->state));
memcpy(octx->buf, sctx->buf, sizeof(octx->buf));
return 0;
}
static int sha256_import(struct shash_desc *desc, const void *in)
{
struct s390_sha_ctx *sctx = shash_desc_ctx(desc);
const struct sha256_state *ictx = in;
sctx->count = ictx->count;
memcpy(sctx->state, ictx->state, sizeof(ictx->state));
memcpy(sctx->buf, ictx->buf, sizeof(ictx->buf));
sctx->func = KIMD_SHA_256;
return 0;
}
static int sha256_s390_init(void)
{
if (!crypt_s390_func_available(KIMD_SHA_256, CRYPT_S390_MSA))
return -EOPNOTSUPP;
return crypto_register_shash(&alg);
}
static void __exit sha256_s390_fini(void)
{
crypto_unregister_shash(&alg);
}
