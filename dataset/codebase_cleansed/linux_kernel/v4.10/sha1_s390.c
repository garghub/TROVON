static int sha1_init(struct shash_desc *desc)
{
struct s390_sha_ctx *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA1_H0;
sctx->state[1] = SHA1_H1;
sctx->state[2] = SHA1_H2;
sctx->state[3] = SHA1_H3;
sctx->state[4] = SHA1_H4;
sctx->count = 0;
sctx->func = CPACF_KIMD_SHA_1;
return 0;
}
static int sha1_export(struct shash_desc *desc, void *out)
{
struct s390_sha_ctx *sctx = shash_desc_ctx(desc);
struct sha1_state *octx = out;
octx->count = sctx->count;
memcpy(octx->state, sctx->state, sizeof(octx->state));
memcpy(octx->buffer, sctx->buf, sizeof(octx->buffer));
return 0;
}
static int sha1_import(struct shash_desc *desc, const void *in)
{
struct s390_sha_ctx *sctx = shash_desc_ctx(desc);
const struct sha1_state *ictx = in;
sctx->count = ictx->count;
memcpy(sctx->state, ictx->state, sizeof(ictx->state));
memcpy(sctx->buf, ictx->buffer, sizeof(ictx->buffer));
sctx->func = CPACF_KIMD_SHA_1;
return 0;
}
static int __init sha1_s390_init(void)
{
if (!cpacf_query_func(CPACF_KIMD, CPACF_KIMD_SHA_1))
return -EOPNOTSUPP;
return crypto_register_shash(&alg);
}
static void __exit sha1_s390_fini(void)
{
crypto_unregister_shash(&alg);
}
