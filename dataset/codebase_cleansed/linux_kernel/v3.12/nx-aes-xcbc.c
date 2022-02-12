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
static int nx_xcbc_empty(struct shash_desc *desc, u8 *out)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
struct nx_sg *in_sg, *out_sg;
u8 keys[2][AES_BLOCK_SIZE];
u8 key[32];
int rc = 0;
csbcpb->cpb.hdr.mode = NX_MODE_AES_ECB;
memcpy(key, csbcpb->cpb.aes_xcbc.key, AES_BLOCK_SIZE);
memcpy(csbcpb->cpb.aes_ecb.key, key, AES_BLOCK_SIZE);
NX_CPB_FDM(csbcpb) |= NX_FDM_ENDE_ENCRYPT;
memset(keys[0], 0x01, sizeof(keys[0]));
memset(keys[1], 0x03, sizeof(keys[1]));
in_sg = nx_build_sg_list(nx_ctx->in_sg, (u8 *) keys, sizeof(keys),
nx_ctx->ap->sglen);
out_sg = nx_build_sg_list(nx_ctx->out_sg, (u8 *) keys, sizeof(keys),
nx_ctx->ap->sglen);
nx_ctx->op.inlen = (nx_ctx->in_sg - in_sg) * sizeof(struct nx_sg);
nx_ctx->op.outlen = (nx_ctx->out_sg - out_sg) * sizeof(struct nx_sg);
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
desc->flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
atomic_inc(&(nx_ctx->stats->aes_ops));
keys[1][0] ^= 0x80;
memcpy(csbcpb->cpb.aes_ecb.key, keys[0], AES_BLOCK_SIZE);
in_sg = nx_build_sg_list(nx_ctx->in_sg, (u8 *) keys[1], sizeof(keys[1]),
nx_ctx->ap->sglen);
out_sg = nx_build_sg_list(nx_ctx->out_sg, out, AES_BLOCK_SIZE,
nx_ctx->ap->sglen);
nx_ctx->op.inlen = (nx_ctx->in_sg - in_sg) * sizeof(struct nx_sg);
nx_ctx->op.outlen = (nx_ctx->out_sg - out_sg) * sizeof(struct nx_sg);
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
desc->flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
atomic_inc(&(nx_ctx->stats->aes_ops));
out:
csbcpb->cpb.hdr.mode = NX_MODE_AES_XCBC_MAC;
memcpy(csbcpb->cpb.aes_xcbc.key, key, AES_BLOCK_SIZE);
NX_CPB_FDM(csbcpb) &= ~NX_FDM_ENDE_ENCRYPT;
return rc;
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
u32 to_process, leftover, total;
u32 max_sg_len;
unsigned long irq_flags;
int rc = 0;
spin_lock_irqsave(&nx_ctx->lock, irq_flags);
total = sctx->count + len;
if (total <= AES_BLOCK_SIZE) {
memcpy(sctx->buffer + sctx->count, data, len);
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
to_process = to_process & ~(AES_BLOCK_SIZE - 1);
leftover = total - to_process;
if (!leftover) {
to_process -= AES_BLOCK_SIZE;
leftover = AES_BLOCK_SIZE;
}
if (sctx->count) {
in_sg = nx_build_sg_list(nx_ctx->in_sg,
(u8 *) sctx->buffer,
sctx->count,
max_sg_len);
}
in_sg = nx_build_sg_list(in_sg,
(u8 *) data,
to_process - sctx->count,
max_sg_len);
nx_ctx->op.inlen = (nx_ctx->in_sg - in_sg) *
sizeof(struct nx_sg);
if (NX_CPB_FDM(csbcpb) & NX_FDM_CONTINUATION) {
memcpy(csbcpb->cpb.aes_xcbc.cv,
csbcpb->cpb.aes_xcbc.out_cv_mac,
AES_BLOCK_SIZE);
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
NX_CPB_FDM(csbcpb) |= NX_FDM_CONTINUATION;
total -= to_process;
data += to_process - sctx->count;
sctx->count = 0;
in_sg = nx_ctx->in_sg;
} while (leftover > AES_BLOCK_SIZE);
memcpy(sctx->buffer, data, leftover);
sctx->count = leftover;
out:
spin_unlock_irqrestore(&nx_ctx->lock, irq_flags);
return rc;
}
static int nx_xcbc_final(struct shash_desc *desc, u8 *out)
{
struct xcbc_state *sctx = shash_desc_ctx(desc);
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&desc->tfm->base);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
struct nx_sg *in_sg, *out_sg;
unsigned long irq_flags;
int rc = 0;
spin_lock_irqsave(&nx_ctx->lock, irq_flags);
if (NX_CPB_FDM(csbcpb) & NX_FDM_CONTINUATION) {
memcpy(csbcpb->cpb.aes_xcbc.cv,
csbcpb->cpb.aes_xcbc.out_cv_mac, AES_BLOCK_SIZE);
} else if (sctx->count == 0) {
rc = nx_xcbc_empty(desc, out);
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
spin_unlock_irqrestore(&nx_ctx->lock, irq_flags);
return rc;
}
