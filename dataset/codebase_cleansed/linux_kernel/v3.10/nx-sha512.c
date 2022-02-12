static int nx_sha512_init(struct shash_desc *desc)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_sg *out_sg;
nx_ctx_init(nx_ctx, HCOP_FC_SHA);
memset(sctx, 0, sizeof *sctx);
nx_ctx->ap = &nx_ctx->props[NX_PROPS_SHA512];
NX_CPB_SET_DIGEST_SIZE(nx_ctx->csbcpb, NX_DS_SHA512);
out_sg = nx_build_sg_list(nx_ctx->out_sg, (u8 *)sctx->state,
SHA512_DIGEST_SIZE, nx_ctx->ap->sglen);
nx_ctx->op.outlen = (nx_ctx->out_sg - out_sg) * sizeof(struct nx_sg);
return 0;
}
static int nx_sha512_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = (struct nx_csbcpb *)nx_ctx->csbcpb;
struct nx_sg *in_sg;
u64 to_process, leftover, spbc_bits;
int rc = 0;
if (NX_CPB_FDM(csbcpb) & NX_FDM_CONTINUATION) {
memcpy(csbcpb->cpb.sha512.input_partial_digest,
csbcpb->cpb.sha512.message_digest, SHA512_DIGEST_SIZE);
}
if ((u64)len + sctx->count[0] < SHA512_BLOCK_SIZE) {
memcpy(sctx->buf + sctx->count[0], data, len);
sctx->count[0] += len;
goto out;
}
to_process = (sctx->count[0] + len) & ~(SHA512_BLOCK_SIZE - 1);
leftover = (sctx->count[0] + len) & (SHA512_BLOCK_SIZE - 1);
if (sctx->count[0]) {
in_sg = nx_build_sg_list(nx_ctx->in_sg, (u8 *)sctx->buf,
sctx->count[0], nx_ctx->ap->sglen);
in_sg = nx_build_sg_list(in_sg, (u8 *)data,
to_process - sctx->count[0],
nx_ctx->ap->sglen);
nx_ctx->op.inlen = (nx_ctx->in_sg - in_sg) *
sizeof(struct nx_sg);
} else {
in_sg = nx_build_sg_list(nx_ctx->in_sg, (u8 *)data,
to_process, nx_ctx->ap->sglen);
nx_ctx->op.inlen = (nx_ctx->in_sg - in_sg) *
sizeof(struct nx_sg);
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
atomic_inc(&(nx_ctx->stats->sha512_ops));
if (leftover)
memcpy(sctx->buf, data + len - leftover, leftover);
sctx->count[0] = leftover;
spbc_bits = csbcpb->cpb.sha512.spbc * 8;
csbcpb->cpb.sha512.message_bit_length_lo += spbc_bits;
if (csbcpb->cpb.sha512.message_bit_length_lo < spbc_bits)
csbcpb->cpb.sha512.message_bit_length_hi++;
NX_CPB_FDM(csbcpb) |= NX_FDM_CONTINUATION;
out:
return rc;
}
static int nx_sha512_final(struct shash_desc *desc, u8 *out)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = (struct nx_csbcpb *)nx_ctx->csbcpb;
struct nx_sg *in_sg, *out_sg;
u64 count0;
int rc;
if (NX_CPB_FDM(csbcpb) & NX_FDM_CONTINUATION) {
memcpy(csbcpb->cpb.sha512.input_partial_digest,
csbcpb->cpb.sha512.message_digest, SHA512_DIGEST_SIZE);
}
NX_CPB_FDM(csbcpb) &= ~NX_FDM_INTERMEDIATE;
count0 = sctx->count[0] * 8;
csbcpb->cpb.sha512.message_bit_length_lo += count0;
if (csbcpb->cpb.sha512.message_bit_length_lo < count0)
csbcpb->cpb.sha512.message_bit_length_hi++;
in_sg = nx_build_sg_list(nx_ctx->in_sg, sctx->buf, sctx->count[0],
nx_ctx->ap->sglen);
out_sg = nx_build_sg_list(nx_ctx->out_sg, out, SHA512_DIGEST_SIZE,
nx_ctx->ap->sglen);
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
atomic_inc(&(nx_ctx->stats->sha512_ops));
atomic64_add(csbcpb->cpb.sha512.message_bit_length_lo / 8,
&(nx_ctx->stats->sha512_bytes));
memcpy(out, csbcpb->cpb.sha512.message_digest, SHA512_DIGEST_SIZE);
out:
return rc;
}
static int nx_sha512_export(struct shash_desc *desc, void *out)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = (struct nx_csbcpb *)nx_ctx->csbcpb;
struct sha512_state *octx = out;
octx->count[0] = csbcpb->cpb.sha512.message_bit_length_lo >> 3 |
((csbcpb->cpb.sha512.message_bit_length_hi & 7) << 61);
octx->count[1] = csbcpb->cpb.sha512.message_bit_length_hi >> 3;
octx->count[0] += sctx->count[0];
if (octx->count[0] < sctx->count[0])
octx->count[1]++;
memcpy(octx->buf, sctx->buf, sizeof(octx->buf));
if (csbcpb->cpb.sha512.message_bit_length_hi ||
csbcpb->cpb.sha512.message_bit_length_lo)
memcpy(octx->state, csbcpb->cpb.sha512.message_digest,
SHA512_DIGEST_SIZE);
else {
octx->state[0] = SHA512_H0;
octx->state[1] = SHA512_H1;
octx->state[2] = SHA512_H2;
octx->state[3] = SHA512_H3;
octx->state[4] = SHA512_H4;
octx->state[5] = SHA512_H5;
octx->state[6] = SHA512_H6;
octx->state[7] = SHA512_H7;
}
return 0;
}
static int nx_sha512_import(struct shash_desc *desc, const void *in)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = (struct nx_csbcpb *)nx_ctx->csbcpb;
const struct sha512_state *ictx = in;
memcpy(sctx->buf, ictx->buf, sizeof(ictx->buf));
sctx->count[0] = ictx->count[0] & 0x3f;
csbcpb->cpb.sha512.message_bit_length_lo = (ictx->count[0] & ~0x3f)
<< 3;
csbcpb->cpb.sha512.message_bit_length_hi = ictx->count[1] << 3 |
ictx->count[0] >> 61;
if (csbcpb->cpb.sha512.message_bit_length_hi ||
csbcpb->cpb.sha512.message_bit_length_lo) {
memcpy(csbcpb->cpb.sha512.message_digest, ictx->state,
SHA512_DIGEST_SIZE);
NX_CPB_FDM(csbcpb) |= NX_FDM_CONTINUATION;
NX_CPB_FDM(csbcpb) |= NX_FDM_INTERMEDIATE;
}
return 0;
}
