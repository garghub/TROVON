static int ccm_aes_nx_set_key(struct crypto_aead *tfm,
const u8 *in_key,
unsigned int key_len)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&tfm->base);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
struct nx_csbcpb *csbcpb_aead = nx_ctx->csbcpb_aead;
nx_ctx_init(nx_ctx, HCOP_FC_AES);
switch (key_len) {
case AES_KEYSIZE_128:
NX_CPB_SET_KEY_SIZE(csbcpb, NX_KS_AES_128);
NX_CPB_SET_KEY_SIZE(csbcpb_aead, NX_KS_AES_128);
nx_ctx->ap = &nx_ctx->props[NX_PROPS_AES_128];
break;
default:
return -EINVAL;
}
csbcpb->cpb.hdr.mode = NX_MODE_AES_CCM;
memcpy(csbcpb->cpb.aes_ccm.key, in_key, key_len);
csbcpb_aead->cpb.hdr.mode = NX_MODE_AES_CCA;
memcpy(csbcpb_aead->cpb.aes_cca.key, in_key, key_len);
return 0;
}
static int ccm4309_aes_nx_set_key(struct crypto_aead *tfm,
const u8 *in_key,
unsigned int key_len)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&tfm->base);
if (key_len < 3)
return -EINVAL;
key_len -= 3;
memcpy(nx_ctx->priv.ccm.nonce, in_key + key_len, 3);
return ccm_aes_nx_set_key(tfm, in_key, key_len);
}
static int ccm_aes_nx_setauthsize(struct crypto_aead *tfm,
unsigned int authsize)
{
switch (authsize) {
case 4:
case 6:
case 8:
case 10:
case 12:
case 14:
case 16:
break;
default:
return -EINVAL;
}
crypto_aead_crt(tfm)->authsize = authsize;
return 0;
}
static int ccm4309_aes_nx_setauthsize(struct crypto_aead *tfm,
unsigned int authsize)
{
switch (authsize) {
case 8:
case 12:
case 16:
break;
default:
return -EINVAL;
}
crypto_aead_crt(tfm)->authsize = authsize;
return 0;
}
static int set_msg_len(u8 *block, unsigned int msglen, int csize)
{
__be32 data;
memset(block, 0, csize);
block += csize;
if (csize >= 4)
csize = 4;
else if (msglen > (unsigned int)(1 << (8 * csize)))
return -EOVERFLOW;
data = cpu_to_be32(msglen);
memcpy(block - csize, (u8 *)&data + 4 - csize, csize);
return 0;
}
static inline int crypto_ccm_check_iv(const u8 *iv)
{
if (1 > iv[0] || iv[0] > 7)
return -EINVAL;
return 0;
}
static int generate_b0(u8 *iv, unsigned int assoclen, unsigned int authsize,
unsigned int cryptlen, u8 *b0)
{
unsigned int l, lp, m = authsize;
int rc;
memcpy(b0, iv, 16);
lp = b0[0];
l = lp + 1;
*b0 |= (8 * ((m - 2) / 2));
if (assoclen)
*b0 |= 64;
rc = set_msg_len(b0 + 16 - l, cryptlen, l);
return rc;
}
static int generate_pat(u8 *iv,
struct aead_request *req,
struct nx_crypto_ctx *nx_ctx,
unsigned int authsize,
unsigned int nbytes,
u8 *out)
{
struct nx_sg *nx_insg = nx_ctx->in_sg;
struct nx_sg *nx_outsg = nx_ctx->out_sg;
unsigned int iauth_len = 0;
struct vio_pfo_op *op = NULL;
u8 tmp[16], *b1 = NULL, *b0 = NULL, *result = NULL;
int rc;
memset(iv + 15 - iv[0], 0, iv[0] + 1);
if (!req->assoclen) {
b0 = nx_ctx->csbcpb->cpb.aes_ccm.in_pat_or_b0;
} else if (req->assoclen <= 14) {
b0 = nx_ctx->csbcpb->cpb.aes_ccm.in_pat_or_b0;
b1 = nx_ctx->priv.ccm.iauth_tag;
iauth_len = req->assoclen;
nx_insg = nx_build_sg_list(nx_insg, b1, 16, nx_ctx->ap->sglen);
nx_outsg = nx_build_sg_list(nx_outsg, tmp, 16,
nx_ctx->ap->sglen);
nx_ctx->op.inlen = (nx_ctx->in_sg - nx_insg) *
sizeof(struct nx_sg);
nx_ctx->op.outlen = (nx_ctx->out_sg - nx_outsg) *
sizeof(struct nx_sg);
NX_CPB_FDM(nx_ctx->csbcpb) |= NX_FDM_ENDE_ENCRYPT;
NX_CPB_FDM(nx_ctx->csbcpb) |= NX_FDM_INTERMEDIATE;
op = &nx_ctx->op;
result = nx_ctx->csbcpb->cpb.aes_ccm.out_pat_or_mac;
} else if (req->assoclen <= 65280) {
b0 = nx_ctx->csbcpb_aead->cpb.aes_cca.b0;
b1 = nx_ctx->csbcpb_aead->cpb.aes_cca.b1;
iauth_len = 14;
nx_insg = nx_walk_and_build(nx_insg, nx_ctx->ap->sglen,
req->assoc, iauth_len,
req->assoclen - iauth_len);
nx_ctx->op_aead.inlen = (nx_ctx->in_sg - nx_insg) *
sizeof(struct nx_sg);
op = &nx_ctx->op_aead;
result = nx_ctx->csbcpb_aead->cpb.aes_cca.out_pat_or_b0;
} else {
pr_err("associated data len is %u bytes (returning -EINVAL)\n",
req->assoclen);
rc = -EINVAL;
}
rc = generate_b0(iv, req->assoclen, authsize, nbytes, b0);
if (rc)
goto done;
if (b1) {
memset(b1, 0, 16);
*(u16 *)b1 = (u16)req->assoclen;
scatterwalk_map_and_copy(b1 + 2, req->assoc, 0,
iauth_len, SCATTERWALK_FROM_SG);
rc = nx_hcall_sync(nx_ctx, op,
req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto done;
atomic_inc(&(nx_ctx->stats->aes_ops));
atomic64_add(req->assoclen, &(nx_ctx->stats->aes_bytes));
memcpy(out, result, AES_BLOCK_SIZE);
}
done:
return rc;
}
static int ccm_nx_decrypt(struct aead_request *req,
struct blkcipher_desc *desc)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
unsigned int nbytes = req->cryptlen;
unsigned int authsize = crypto_aead_authsize(crypto_aead_reqtfm(req));
struct nx_ccm_priv *priv = &nx_ctx->priv.ccm;
int rc = -1;
if (nbytes > nx_ctx->ap->databytelen)
return -EINVAL;
nbytes -= authsize;
scatterwalk_map_and_copy(priv->oauth_tag,
req->src, nbytes, authsize,
SCATTERWALK_FROM_SG);
rc = generate_pat(desc->info, req, nx_ctx, authsize, nbytes,
csbcpb->cpb.aes_ccm.in_pat_or_b0);
if (rc)
goto out;
rc = nx_build_sg_lists(nx_ctx, desc, req->dst, req->src, nbytes,
csbcpb->cpb.aes_ccm.iv_or_ctr);
if (rc)
goto out;
NX_CPB_FDM(nx_ctx->csbcpb) &= ~NX_FDM_ENDE_ENCRYPT;
NX_CPB_FDM(nx_ctx->csbcpb) &= ~NX_FDM_INTERMEDIATE;
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
atomic_inc(&(nx_ctx->stats->aes_ops));
atomic64_add(csbcpb->csb.processed_byte_count,
&(nx_ctx->stats->aes_bytes));
rc = memcmp(csbcpb->cpb.aes_ccm.out_pat_or_mac, priv->oauth_tag,
authsize) ? -EBADMSG : 0;
out:
return rc;
}
static int ccm_nx_encrypt(struct aead_request *req,
struct blkcipher_desc *desc)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
unsigned int nbytes = req->cryptlen;
unsigned int authsize = crypto_aead_authsize(crypto_aead_reqtfm(req));
int rc = -1;
if (nbytes > nx_ctx->ap->databytelen)
return -EINVAL;
rc = generate_pat(desc->info, req, nx_ctx, authsize, nbytes,
csbcpb->cpb.aes_ccm.in_pat_or_b0);
if (rc)
goto out;
rc = nx_build_sg_lists(nx_ctx, desc, req->dst, req->src, nbytes,
csbcpb->cpb.aes_ccm.iv_or_ctr);
if (rc)
goto out;
NX_CPB_FDM(csbcpb) |= NX_FDM_ENDE_ENCRYPT;
NX_CPB_FDM(csbcpb) &= ~NX_FDM_INTERMEDIATE;
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
atomic_inc(&(nx_ctx->stats->aes_ops));
atomic64_add(csbcpb->csb.processed_byte_count,
&(nx_ctx->stats->aes_bytes));
scatterwalk_map_and_copy(csbcpb->cpb.aes_ccm.out_pat_or_mac,
req->dst, nbytes, authsize,
SCATTERWALK_TO_SG);
out:
return rc;
}
static int ccm4309_aes_nx_encrypt(struct aead_request *req)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
struct blkcipher_desc desc;
u8 *iv = nx_ctx->priv.ccm.iv;
iv[0] = 3;
memcpy(iv + 1, nx_ctx->priv.ccm.nonce, 3);
memcpy(iv + 4, req->iv, 8);
desc.info = iv;
desc.tfm = (struct crypto_blkcipher *)req->base.tfm;
return ccm_nx_encrypt(req, &desc);
}
static int ccm_aes_nx_encrypt(struct aead_request *req)
{
struct blkcipher_desc desc;
int rc;
desc.info = req->iv;
desc.tfm = (struct crypto_blkcipher *)req->base.tfm;
rc = crypto_ccm_check_iv(desc.info);
if (rc)
return rc;
return ccm_nx_encrypt(req, &desc);
}
static int ccm4309_aes_nx_decrypt(struct aead_request *req)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
struct blkcipher_desc desc;
u8 *iv = nx_ctx->priv.ccm.iv;
iv[0] = 3;
memcpy(iv + 1, nx_ctx->priv.ccm.nonce, 3);
memcpy(iv + 4, req->iv, 8);
desc.info = iv;
desc.tfm = (struct crypto_blkcipher *)req->base.tfm;
return ccm_nx_decrypt(req, &desc);
}
static int ccm_aes_nx_decrypt(struct aead_request *req)
{
struct blkcipher_desc desc;
int rc;
desc.info = req->iv;
desc.tfm = (struct crypto_blkcipher *)req->base.tfm;
rc = crypto_ccm_check_iv(desc.info);
if (rc)
return rc;
return ccm_nx_decrypt(req, &desc);
}
