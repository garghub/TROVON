static int ctr_aes_nx_set_key(struct crypto_tfm *tfm,
const u8 *in_key,
unsigned int key_len)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(tfm);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
nx_ctx_init(nx_ctx, HCOP_FC_AES);
switch (key_len) {
case AES_KEYSIZE_128:
NX_CPB_SET_KEY_SIZE(csbcpb, NX_KS_AES_128);
nx_ctx->ap = &nx_ctx->props[NX_PROPS_AES_128];
break;
case AES_KEYSIZE_192:
NX_CPB_SET_KEY_SIZE(csbcpb, NX_KS_AES_192);
nx_ctx->ap = &nx_ctx->props[NX_PROPS_AES_192];
break;
case AES_KEYSIZE_256:
NX_CPB_SET_KEY_SIZE(csbcpb, NX_KS_AES_256);
nx_ctx->ap = &nx_ctx->props[NX_PROPS_AES_256];
break;
default:
return -EINVAL;
}
csbcpb->cpb.hdr.mode = NX_MODE_AES_CTR;
memcpy(csbcpb->cpb.aes_ctr.key, in_key, key_len);
return 0;
}
static int ctr3686_aes_nx_set_key(struct crypto_tfm *tfm,
const u8 *in_key,
unsigned int key_len)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(tfm);
if (key_len < CTR_RFC3686_NONCE_SIZE)
return -EINVAL;
memcpy(nx_ctx->priv.ctr.iv,
in_key + key_len - CTR_RFC3686_NONCE_SIZE,
CTR_RFC3686_NONCE_SIZE);
key_len -= CTR_RFC3686_NONCE_SIZE;
return ctr_aes_nx_set_key(tfm, in_key, key_len);
}
static int ctr_aes_nx_crypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src,
unsigned int nbytes)
{
struct nx_crypto_ctx *nx_ctx = crypto_blkcipher_ctx(desc->tfm);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
unsigned long irq_flags;
unsigned int processed = 0, to_process;
int rc;
spin_lock_irqsave(&nx_ctx->lock, irq_flags);
do {
to_process = nbytes - processed;
rc = nx_build_sg_lists(nx_ctx, desc, dst, src, &to_process,
processed, csbcpb->cpb.aes_ctr.iv);
if (rc)
goto out;
if (!nx_ctx->op.inlen || !nx_ctx->op.outlen) {
rc = -EINVAL;
goto out;
}
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
desc->flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
memcpy(desc->info, csbcpb->cpb.aes_cbc.cv, AES_BLOCK_SIZE);
atomic_inc(&(nx_ctx->stats->aes_ops));
atomic64_add(csbcpb->csb.processed_byte_count,
&(nx_ctx->stats->aes_bytes));
processed += to_process;
} while (processed < nbytes);
out:
spin_unlock_irqrestore(&nx_ctx->lock, irq_flags);
return rc;
}
static int ctr3686_aes_nx_crypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src,
unsigned int nbytes)
{
struct nx_crypto_ctx *nx_ctx = crypto_blkcipher_ctx(desc->tfm);
u8 *iv = nx_ctx->priv.ctr.iv;
memcpy(iv + CTR_RFC3686_NONCE_SIZE,
desc->info, CTR_RFC3686_IV_SIZE);
iv[12] = iv[13] = iv[14] = 0;
iv[15] = 1;
desc->info = nx_ctx->priv.ctr.iv;
return ctr_aes_nx_crypt(desc, dst, src, nbytes);
}
