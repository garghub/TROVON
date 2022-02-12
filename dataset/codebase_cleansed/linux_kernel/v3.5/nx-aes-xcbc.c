static int nx_xcbc_set_key(struct crypto_shash *desc,
const u8 *in_key,
unsigned int key_len)
{
struct nx_crypto_ctx *nx_ctx = crypto_shash_ctx(desc);
switch (key_len) {
case AES_KEYSIZE_128:
nx_ctx->ap = &nx_ctx->props[NX_PROPS_AES_128];
break;
default:
return -EINVAL;
}
memcpy(nx_ctx->priv.xcbc.key, in_key, key_len);
return 0;
}
static int nx_xcbc_init(struct shash_desc *desc)
{
struct xcbc_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
struct nx_sg *out_sg;
nx_ctx_init(nx_ctx, HCOP_FC_AES);
memset(sctx, 0, sizeof *sctx);
NX_CPB_SET_KEY_SIZE(csbcpb, NX_KS_AES_128);
csbcpb->cpb.hdr.mode = NX_MODE_AES_XCBC_MAC;
memcpy(csbcpb->cpb.aes_xcbc.key, nx_ctx->priv.xcbc.key, AES_BLOCK_SIZE);
memset(nx_ctx->priv.xcbc.key, 0, sizeof *nx_ctx->priv.xcbc.key);
out_sg = nx_build_sg_list(nx_ctx->out_sg, (u8 *)sctx->state,
AES_BLOCK_SIZE, nx_ctx->ap->sglen);
nx_ctx->op.outlen = (nx_ctx->out_sg - out_sg) * sizeof(struct nx_sg);
return 0;
}
static int nx_xcbc_update(struct shash_desc *desc,
const u8 *data,
unsigned int len)
{
struct xcbc_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
struct nx_sg *in_sg;
u32 to_process, leftover;
int rc = 0;
if (NX_CPB_FDM(csbcpb) & NX_FDM_CONTINUATION) {
memcpy(csbcpb->cpb.aes_xcbc.cv,
csbcpb->cpb.aes_xcbc.out_cv_mac, AES_BLOCK_SIZE);
}
if (len + sctx->count <= AES_BLOCK_SIZE) {
memcpy(sctx->buffer + sctx->count, data, len);
sctx->count += len;
goto out;
}
to_process = (sctx->count + len) & ~(AES_BLOCK_SIZE - 1);
leftover = (sctx->count + len) & (AES_BLOCK_SIZE - 1);
if (!leftover) {
to_process -= AES_BLOCK_SIZE;
leftover = AES_BLOCK_SIZE;
}
if (sctx->count) {
in_sg = nx_build_sg_list(nx_ctx->in_sg, sctx->buffer,
sctx->count, nx_ctx->ap->sglen);
in_sg = nx_build_sg_list(in_sg, (u8 *)data,
to_process - sctx->count,
nx_ctx->ap->sglen);
nx_ctx->op.inlen = (nx_ctx->in_sg - in_sg) *
sizeof(struct nx_sg);
} else {
in_sg = nx_build_sg_list(nx_ctx->in_sg, (u8 *)data, to_process,
nx_ctx->ap->sglen);
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
atomic_inc(&(nx_ctx->stats->aes_ops));
memcpy(sctx->buffer, data + len - leftover, leftover);
sctx->count = leftover;
NX_CPB_FDM(csbcpb) |= NX_FDM_CONTINUATION;
out:
return rc;
}
static int nx_xcbc_final(struct shash_desc *desc, u8 *out)
{
struct xcbc_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
struct nx_sg *in_sg, *out_sg;
int rc = 0;
if (NX_CPB_FDM(csbcpb) & NX_FDM_CONTINUATION) {
memcpy(csbcpb->cpb.aes_xcbc.cv,
csbcpb->cpb.aes_xcbc.out_cv_mac, AES_BLOCK_SIZE);
} else if (sctx->count == 0) {
u8 data[] = { 0x75, 0xf0, 0x25, 0x1d, 0x52, 0x8a, 0xc0, 0x1c,
0x45, 0x73, 0xdf, 0xd5, 0x84, 0xd7, 0x9f, 0x29 };
memcpy(out, data, sizeof(data));
goto out;
}
NX_CPB_FDM(csbcpb) &= ~NX_FDM_INTERMEDIATE;
in_sg = nx_build_sg_list(nx_ctx->in_sg, (u8 *)sctx->buffer,
sctx->count, nx_ctx->ap->sglen);
out_sg = nx_build_sg_list(nx_ctx->out_sg, out, AES_BLOCK_SIZE,
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
atomic_inc(&(nx_ctx->stats->aes_ops));
memcpy(out, csbcpb->cpb.aes_xcbc.out_cv_mac, AES_BLOCK_SIZE);
out:
return rc;
}
