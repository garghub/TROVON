static int nx_sha256_init(struct shash_desc *desc)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
int len;
int rc;
nx_ctx_init(nx_ctx, HCOP_FC_SHA);
memset(sctx, 0, sizeof *sctx);
nx_ctx->ap = &nx_ctx->props[NX_PROPS_SHA256];
NX_CPB_SET_DIGEST_SIZE(nx_ctx->csbcpb, NX_DS_SHA256);
len = SHA256_DIGEST_SIZE;
rc = nx_sha_build_sg_list(nx_ctx, nx_ctx->out_sg,
&nx_ctx->op.outlen,
&len,
(u8 *) sctx->state,
NX_DS_SHA256);
if (rc)
goto out;
sctx->state[0] = __cpu_to_be32(SHA256_H0);
sctx->state[1] = __cpu_to_be32(SHA256_H1);
sctx->state[2] = __cpu_to_be32(SHA256_H2);
sctx->state[3] = __cpu_to_be32(SHA256_H3);
sctx->state[4] = __cpu_to_be32(SHA256_H4);
sctx->state[5] = __cpu_to_be32(SHA256_H5);
sctx->state[6] = __cpu_to_be32(SHA256_H6);
sctx->state[7] = __cpu_to_be32(SHA256_H7);
sctx->count = 0;
out:
return 0;
}
static int nx_sha256_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = (struct nx_csbcpb *)nx_ctx->csbcpb;
u64 to_process = 0, leftover, total;
unsigned long irq_flags;
int rc = 0;
int data_len;
u64 buf_len = (sctx->count % SHA256_BLOCK_SIZE);
spin_lock_irqsave(&nx_ctx->lock, irq_flags);
total = (sctx->count % SHA256_BLOCK_SIZE) + len;
if (total < SHA256_BLOCK_SIZE) {
memcpy(sctx->buf + buf_len, data, len);
sctx->count += len;
goto out;
}
memcpy(csbcpb->cpb.sha256.message_digest, sctx->state, SHA256_DIGEST_SIZE);
NX_CPB_FDM(csbcpb) |= NX_FDM_INTERMEDIATE;
NX_CPB_FDM(csbcpb) |= NX_FDM_CONTINUATION;
do {
to_process = total - to_process;
to_process = to_process & ~(SHA256_BLOCK_SIZE - 1);
if (buf_len) {
data_len = buf_len;
rc = nx_sha_build_sg_list(nx_ctx, nx_ctx->in_sg,
&nx_ctx->op.inlen,
&data_len,
(u8 *) sctx->buf,
NX_DS_SHA256);
if (rc || data_len != buf_len)
goto out;
}
data_len = to_process - buf_len;
rc = nx_sha_build_sg_list(nx_ctx, nx_ctx->in_sg,
&nx_ctx->op.inlen,
&data_len,
(u8 *) data,
NX_DS_SHA256);
if (rc)
goto out;
to_process = (data_len + buf_len);
leftover = total - to_process;
memcpy(csbcpb->cpb.sha256.input_partial_digest,
csbcpb->cpb.sha256.message_digest,
SHA256_DIGEST_SIZE);
if (!nx_ctx->op.inlen || !nx_ctx->op.outlen) {
rc = -EINVAL;
goto out;
}
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
desc->flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
atomic_inc(&(nx_ctx->stats->sha256_ops));
total -= to_process;
data += to_process - buf_len;
buf_len = 0;
} while (leftover >= SHA256_BLOCK_SIZE);
if (leftover)
memcpy(sctx->buf, data, leftover);
sctx->count += len;
memcpy(sctx->state, csbcpb->cpb.sha256.message_digest, SHA256_DIGEST_SIZE);
out:
spin_unlock_irqrestore(&nx_ctx->lock, irq_flags);
return rc;
}
static int nx_sha256_final(struct shash_desc *desc, u8 *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = (struct nx_csbcpb *)nx_ctx->csbcpb;
unsigned long irq_flags;
int rc;
int len;
spin_lock_irqsave(&nx_ctx->lock, irq_flags);
if (sctx->count >= SHA256_BLOCK_SIZE) {
memcpy(csbcpb->cpb.sha256.input_partial_digest, sctx->state, SHA256_DIGEST_SIZE);
NX_CPB_FDM(csbcpb) &= ~NX_FDM_INTERMEDIATE;
NX_CPB_FDM(csbcpb) |= NX_FDM_CONTINUATION;
} else {
NX_CPB_FDM(csbcpb) &= ~NX_FDM_INTERMEDIATE;
NX_CPB_FDM(csbcpb) &= ~NX_FDM_CONTINUATION;
}
csbcpb->cpb.sha256.message_bit_length = (u64) (sctx->count * 8);
len = sctx->count & (SHA256_BLOCK_SIZE - 1);
rc = nx_sha_build_sg_list(nx_ctx, nx_ctx->in_sg,
&nx_ctx->op.inlen,
&len,
(u8 *) sctx->buf,
NX_DS_SHA256);
if (rc || len != (sctx->count & (SHA256_BLOCK_SIZE - 1)))
goto out;
len = SHA256_DIGEST_SIZE;
rc = nx_sha_build_sg_list(nx_ctx, nx_ctx->out_sg,
&nx_ctx->op.outlen,
&len,
out,
NX_DS_SHA256);
if (rc || len != SHA256_DIGEST_SIZE)
goto out;
if (!nx_ctx->op.outlen) {
rc = -EINVAL;
goto out;
}
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
desc->flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
atomic_inc(&(nx_ctx->stats->sha256_ops));
atomic64_add(sctx->count, &(nx_ctx->stats->sha256_bytes));
memcpy(out, csbcpb->cpb.sha256.message_digest, SHA256_DIGEST_SIZE);
out:
spin_unlock_irqrestore(&nx_ctx->lock, irq_flags);
return rc;
}
static int nx_sha256_export(struct shash_desc *desc, void *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int nx_sha256_import(struct shash_desc *desc, const void *in)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
