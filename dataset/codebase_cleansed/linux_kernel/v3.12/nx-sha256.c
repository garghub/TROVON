static int nx_sha256_init(struct shash_desc *desc)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_sg *out_sg;
nx_ctx_init(nx_ctx, HCOP_FC_SHA);
memset(sctx, 0, sizeof *sctx);
nx_ctx->ap = &nx_ctx->props[NX_PROPS_SHA256];
NX_CPB_SET_DIGEST_SIZE(nx_ctx->csbcpb, NX_DS_SHA256);
out_sg = nx_build_sg_list(nx_ctx->out_sg, (u8 *)sctx->state,
SHA256_DIGEST_SIZE, nx_ctx->ap->sglen);
nx_ctx->op.outlen = (nx_ctx->out_sg - out_sg) * sizeof(struct nx_sg);
return 0;
}
static int nx_sha256_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = (struct nx_csbcpb *)nx_ctx->csbcpb;
struct nx_sg *in_sg;
u64 to_process, leftover, total;
u32 max_sg_len;
unsigned long irq_flags;
int rc = 0;
spin_lock_irqsave(&nx_ctx->lock, irq_flags);
total = sctx->count + len;
if (total < SHA256_BLOCK_SIZE) {
memcpy(sctx->buf + sctx->count, data, len);
sctx->count += len;
goto out;
}
in_sg = nx_ctx->in_sg;
max_sg_len = min_t(u32, nx_driver.of.max_sg_len/sizeof(struct nx_sg),
nx_ctx->ap->sglen);
do {
to_process = min_t(u64, total, nx_ctx->ap->databytelen);
to_process = min_t(u64, to_process,
NX_PAGE_SIZE * (max_sg_len - 1));
to_process = to_process & ~(SHA256_BLOCK_SIZE - 1);
leftover = total - to_process;
if (sctx->count) {
in_sg = nx_build_sg_list(nx_ctx->in_sg,
(u8 *) sctx->buf,
sctx->count, max_sg_len);
}
in_sg = nx_build_sg_list(in_sg, (u8 *) data,
to_process - sctx->count,
max_sg_len);
nx_ctx->op.inlen = (nx_ctx->in_sg - in_sg) *
sizeof(struct nx_sg);
if (NX_CPB_FDM(csbcpb) & NX_FDM_CONTINUATION) {
memcpy(csbcpb->cpb.sha256.input_partial_digest,
csbcpb->cpb.sha256.message_digest,
SHA256_DIGEST_SIZE);
}
NX_CPB_FDM(csbcpb) |= NX_FDM_INTERMEDIATE;
if (!nx_ctx->op.inlen || !nx_ctx->op.outlen) {
rc = -EINVAL;
goto out;
}
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
desc->flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
atomic_inc(&(nx_ctx->stats->sha256_ops));
csbcpb->cpb.sha256.message_bit_length += (u64)
(csbcpb->cpb.sha256.spbc * 8);
NX_CPB_FDM(csbcpb) |= NX_FDM_CONTINUATION;
total -= to_process;
data += to_process - sctx->count;
sctx->count = 0;
in_sg = nx_ctx->in_sg;
} while (leftover >= SHA256_BLOCK_SIZE);
if (leftover)
memcpy(sctx->buf, data, leftover);
sctx->count = leftover;
out:
spin_unlock_irqrestore(&nx_ctx->lock, irq_flags);
return rc;
}
static int nx_sha256_final(struct shash_desc *desc, u8 *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = (struct nx_csbcpb *)nx_ctx->csbcpb;
struct nx_sg *in_sg, *out_sg;
u32 max_sg_len;
unsigned long irq_flags;
int rc;
spin_lock_irqsave(&nx_ctx->lock, irq_flags);
max_sg_len = min_t(u32, nx_driver.of.max_sg_len, nx_ctx->ap->sglen);
if (NX_CPB_FDM(csbcpb) & NX_FDM_CONTINUATION) {
memcpy(csbcpb->cpb.sha256.input_partial_digest,
csbcpb->cpb.sha256.message_digest, SHA256_DIGEST_SIZE);
}
NX_CPB_FDM(csbcpb) &= ~NX_FDM_INTERMEDIATE;
csbcpb->cpb.sha256.message_bit_length += (u64)(sctx->count * 8);
in_sg = nx_build_sg_list(nx_ctx->in_sg, (u8 *)sctx->buf,
sctx->count, max_sg_len);
out_sg = nx_build_sg_list(nx_ctx->out_sg, out, SHA256_DIGEST_SIZE,
max_sg_len);
nx_ctx->op.inlen = (nx_ctx->in_sg - in_sg) * sizeof(struct nx_sg);
nx_ctx->op.outlen = (nx_ctx->out_sg - out_sg) * sizeof(struct nx_sg);
if (!nx_ctx->op.outlen) {
rc = -EINVAL;
goto out;
}
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
desc->flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
atomic_inc(&(nx_ctx->stats->sha256_ops));
atomic64_add(csbcpb->cpb.sha256.message_bit_length / 8,
&(nx_ctx->stats->sha256_bytes));
memcpy(out, csbcpb->cpb.sha256.message_digest, SHA256_DIGEST_SIZE);
out:
spin_unlock_irqrestore(&nx_ctx->lock, irq_flags);
return rc;
}
static int nx_sha256_export(struct shash_desc *desc, void *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = (struct nx_csbcpb *)nx_ctx->csbcpb;
struct sha256_state *octx = out;
unsigned long irq_flags;
spin_lock_irqsave(&nx_ctx->lock, irq_flags);
octx->count = sctx->count +
(csbcpb->cpb.sha256.message_bit_length / 8);
memcpy(octx->buf, sctx->buf, sizeof(octx->buf));
if (csbcpb->cpb.sha256.message_bit_length)
memcpy(octx->state, csbcpb->cpb.sha256.message_digest,
SHA256_DIGEST_SIZE);
else {
octx->state[0] = SHA256_H0;
octx->state[1] = SHA256_H1;
octx->state[2] = SHA256_H2;
octx->state[3] = SHA256_H3;
octx->state[4] = SHA256_H4;
octx->state[5] = SHA256_H5;
octx->state[6] = SHA256_H6;
octx->state[7] = SHA256_H7;
}
spin_unlock_irqrestore(&nx_ctx->lock, irq_flags);
return 0;
}
static int nx_sha256_import(struct shash_desc *desc, const void *in)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = (struct nx_csbcpb *)nx_ctx->csbcpb;
const struct sha256_state *ictx = in;
unsigned long irq_flags;
spin_lock_irqsave(&nx_ctx->lock, irq_flags);
memcpy(sctx->buf, ictx->buf, sizeof(ictx->buf));
sctx->count = ictx->count & 0x3f;
csbcpb->cpb.sha256.message_bit_length = (ictx->count & ~0x3f) * 8;
if (csbcpb->cpb.sha256.message_bit_length) {
memcpy(csbcpb->cpb.sha256.message_digest, ictx->state,
SHA256_DIGEST_SIZE);
NX_CPB_FDM(csbcpb) |= NX_FDM_CONTINUATION;
NX_CPB_FDM(csbcpb) |= NX_FDM_INTERMEDIATE;
}
spin_unlock_irqrestore(&nx_ctx->lock, irq_flags);
return 0;
}
