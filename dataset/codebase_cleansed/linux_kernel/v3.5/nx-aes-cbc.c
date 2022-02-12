static int cbc_aes_nx_set_key(struct crypto_tfm *tfm,
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
csbcpb->cpb.hdr.mode = NX_MODE_AES_CBC;
memcpy(csbcpb->cpb.aes_cbc.key, in_key, key_len);
return 0;
}
static int cbc_aes_nx_crypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src,
unsigned int nbytes,
int enc)
{
struct nx_crypto_ctx *nx_ctx = crypto_blkcipher_ctx(desc->tfm);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
int rc;
if (nbytes > nx_ctx->ap->databytelen)
return -EINVAL;
if (enc)
NX_CPB_FDM(csbcpb) |= NX_FDM_ENDE_ENCRYPT;
else
NX_CPB_FDM(csbcpb) &= ~NX_FDM_ENDE_ENCRYPT;
rc = nx_build_sg_lists(nx_ctx, desc, dst, src, nbytes,
csbcpb->cpb.aes_cbc.iv);
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
atomic_inc(&(nx_ctx->stats->aes_ops));
atomic64_add(csbcpb->csb.processed_byte_count,
&(nx_ctx->stats->aes_bytes));
out:
return rc;
}
static int cbc_aes_nx_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src,
unsigned int nbytes)
{
return cbc_aes_nx_crypt(desc, dst, src, nbytes, 1);
}
static int cbc_aes_nx_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src,
unsigned int nbytes)
{
return cbc_aes_nx_crypt(desc, dst, src, nbytes, 0);
}
