static int gcm_aes_nx_set_key(struct crypto_aead *tfm,
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
case AES_KEYSIZE_192:
NX_CPB_SET_KEY_SIZE(csbcpb, NX_KS_AES_192);
NX_CPB_SET_KEY_SIZE(csbcpb_aead, NX_KS_AES_192);
nx_ctx->ap = &nx_ctx->props[NX_PROPS_AES_192];
break;
case AES_KEYSIZE_256:
NX_CPB_SET_KEY_SIZE(csbcpb, NX_KS_AES_256);
NX_CPB_SET_KEY_SIZE(csbcpb_aead, NX_KS_AES_256);
nx_ctx->ap = &nx_ctx->props[NX_PROPS_AES_256];
break;
default:
return -EINVAL;
}
csbcpb->cpb.hdr.mode = NX_MODE_AES_GCM;
memcpy(csbcpb->cpb.aes_gcm.key, in_key, key_len);
csbcpb_aead->cpb.hdr.mode = NX_MODE_AES_GCA;
memcpy(csbcpb_aead->cpb.aes_gca.key, in_key, key_len);
return 0;
}
static int gcm4106_aes_nx_set_key(struct crypto_aead *tfm,
const u8 *in_key,
unsigned int key_len)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(&tfm->base);
char *nonce = nx_ctx->priv.gcm.nonce;
int rc;
if (key_len < 4)
return -EINVAL;
key_len -= 4;
rc = gcm_aes_nx_set_key(tfm, in_key, key_len);
if (rc)
goto out;
memcpy(nonce, in_key + key_len, 4);
out:
return rc;
}
static int gcm4106_aes_nx_setauthsize(struct crypto_aead *tfm,
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
return 0;
}
static int nx_gca(struct nx_crypto_ctx *nx_ctx,
struct aead_request *req,
u8 *out)
{
int rc;
struct nx_csbcpb *csbcpb_aead = nx_ctx->csbcpb_aead;
struct scatter_walk walk;
struct nx_sg *nx_sg = nx_ctx->in_sg;
unsigned int nbytes = req->assoclen;
unsigned int processed = 0, to_process;
unsigned int max_sg_len;
if (nbytes <= AES_BLOCK_SIZE) {
scatterwalk_start(&walk, req->src);
scatterwalk_copychunks(out, &walk, nbytes, SCATTERWALK_FROM_SG);
scatterwalk_done(&walk, SCATTERWALK_FROM_SG, 0);
return 0;
}
NX_CPB_FDM(csbcpb_aead) &= ~NX_FDM_CONTINUATION;
max_sg_len = min_t(u64, nx_driver.of.max_sg_len/sizeof(struct nx_sg),
nx_ctx->ap->sglen);
max_sg_len = min_t(u64, max_sg_len,
nx_ctx->ap->databytelen/NX_PAGE_SIZE);
do {
to_process = min_t(u64, nbytes - processed,
nx_ctx->ap->databytelen);
to_process = min_t(u64, to_process,
NX_PAGE_SIZE * (max_sg_len - 1));
nx_sg = nx_walk_and_build(nx_ctx->in_sg, max_sg_len,
req->src, processed, &to_process);
if ((to_process + processed) < nbytes)
NX_CPB_FDM(csbcpb_aead) |= NX_FDM_INTERMEDIATE;
else
NX_CPB_FDM(csbcpb_aead) &= ~NX_FDM_INTERMEDIATE;
nx_ctx->op_aead.inlen = (nx_ctx->in_sg - nx_sg)
* sizeof(struct nx_sg);
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op_aead,
req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
return rc;
memcpy(csbcpb_aead->cpb.aes_gca.in_pat,
csbcpb_aead->cpb.aes_gca.out_pat,
AES_BLOCK_SIZE);
NX_CPB_FDM(csbcpb_aead) |= NX_FDM_CONTINUATION;
atomic_inc(&(nx_ctx->stats->aes_ops));
atomic64_add(req->assoclen, &(nx_ctx->stats->aes_bytes));
processed += to_process;
} while (processed < nbytes);
memcpy(out, csbcpb_aead->cpb.aes_gca.out_pat, AES_BLOCK_SIZE);
return rc;
}
static int gmac(struct aead_request *req, struct blkcipher_desc *desc)
{
int rc;
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
struct nx_sg *nx_sg;
unsigned int nbytes = req->assoclen;
unsigned int processed = 0, to_process;
unsigned int max_sg_len;
csbcpb->cpb.hdr.mode = NX_MODE_AES_GMAC;
NX_CPB_FDM(csbcpb) &= ~NX_FDM_CONTINUATION;
max_sg_len = min_t(u64, nx_driver.of.max_sg_len/sizeof(struct nx_sg),
nx_ctx->ap->sglen);
max_sg_len = min_t(u64, max_sg_len,
nx_ctx->ap->databytelen/NX_PAGE_SIZE);
memcpy(csbcpb->cpb.aes_gcm.iv_or_cnt, desc->info, AES_BLOCK_SIZE);
do {
to_process = min_t(u64, nbytes - processed,
nx_ctx->ap->databytelen);
to_process = min_t(u64, to_process,
NX_PAGE_SIZE * (max_sg_len - 1));
nx_sg = nx_walk_and_build(nx_ctx->in_sg, max_sg_len,
req->src, processed, &to_process);
if ((to_process + processed) < nbytes)
NX_CPB_FDM(csbcpb) |= NX_FDM_INTERMEDIATE;
else
NX_CPB_FDM(csbcpb) &= ~NX_FDM_INTERMEDIATE;
nx_ctx->op.inlen = (nx_ctx->in_sg - nx_sg)
* sizeof(struct nx_sg);
csbcpb->cpb.aes_gcm.bit_length_data = 0;
csbcpb->cpb.aes_gcm.bit_length_aad = 8 * nbytes;
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
memcpy(csbcpb->cpb.aes_gcm.in_pat_or_aad,
csbcpb->cpb.aes_gcm.out_pat_or_mac, AES_BLOCK_SIZE);
memcpy(csbcpb->cpb.aes_gcm.in_s0,
csbcpb->cpb.aes_gcm.out_s0, AES_BLOCK_SIZE);
NX_CPB_FDM(csbcpb) |= NX_FDM_CONTINUATION;
atomic_inc(&(nx_ctx->stats->aes_ops));
atomic64_add(req->assoclen, &(nx_ctx->stats->aes_bytes));
processed += to_process;
} while (processed < nbytes);
out:
csbcpb->cpb.hdr.mode = NX_MODE_AES_GCM;
return rc;
}
static int gcm_empty(struct aead_request *req, struct blkcipher_desc *desc,
int enc)
{
int rc;
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
char out[AES_BLOCK_SIZE];
struct nx_sg *in_sg, *out_sg;
int len;
csbcpb->cpb.hdr.mode = NX_MODE_AES_ECB;
memcpy(csbcpb->cpb.aes_ecb.key, csbcpb->cpb.aes_gcm.key,
sizeof(csbcpb->cpb.aes_ecb.key));
if (enc)
NX_CPB_FDM(csbcpb) |= NX_FDM_ENDE_ENCRYPT;
else
NX_CPB_FDM(csbcpb) &= ~NX_FDM_ENDE_ENCRYPT;
len = AES_BLOCK_SIZE;
in_sg = nx_build_sg_list(nx_ctx->in_sg, (u8 *) desc->info,
&len, nx_ctx->ap->sglen);
if (len != AES_BLOCK_SIZE)
return -EINVAL;
len = sizeof(out);
out_sg = nx_build_sg_list(nx_ctx->out_sg, (u8 *) out, &len,
nx_ctx->ap->sglen);
if (len != sizeof(out))
return -EINVAL;
nx_ctx->op.inlen = (nx_ctx->in_sg - in_sg) * sizeof(struct nx_sg);
nx_ctx->op.outlen = (nx_ctx->out_sg - out_sg) * sizeof(struct nx_sg);
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
desc->flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
atomic_inc(&(nx_ctx->stats->aes_ops));
memcpy(csbcpb->cpb.aes_gcm.out_pat_or_mac, out,
crypto_aead_authsize(crypto_aead_reqtfm(req)));
out:
csbcpb->cpb.hdr.mode = NX_MODE_AES_GCM;
memset(csbcpb->cpb.aes_ecb.key, 0, sizeof(csbcpb->cpb.aes_ecb.key));
return rc;
}
static int gcm_aes_nx_crypt(struct aead_request *req, int enc)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
struct nx_gcm_rctx *rctx = aead_request_ctx(req);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
struct blkcipher_desc desc;
unsigned int nbytes = req->cryptlen;
unsigned int processed = 0, to_process;
unsigned long irq_flags;
int rc = -EINVAL;
spin_lock_irqsave(&nx_ctx->lock, irq_flags);
desc.info = rctx->iv;
*(u32 *)(desc.info + NX_GCM_CTR_OFFSET) = 1;
if (nbytes == 0) {
if (req->assoclen == 0)
rc = gcm_empty(req, &desc, enc);
else
rc = gmac(req, &desc);
if (rc)
goto out;
else
goto mac;
}
csbcpb->cpb.aes_gcm.bit_length_aad = req->assoclen * 8;
if (req->assoclen) {
rc = nx_gca(nx_ctx, req, csbcpb->cpb.aes_gcm.in_pat_or_aad);
if (rc)
goto out;
}
NX_CPB_FDM(csbcpb) &= ~NX_FDM_CONTINUATION;
if (enc) {
NX_CPB_FDM(csbcpb) |= NX_FDM_ENDE_ENCRYPT;
} else {
NX_CPB_FDM(csbcpb) &= ~NX_FDM_ENDE_ENCRYPT;
nbytes -= crypto_aead_authsize(crypto_aead_reqtfm(req));
}
do {
to_process = nbytes - processed;
csbcpb->cpb.aes_gcm.bit_length_data = nbytes * 8;
desc.tfm = (struct crypto_blkcipher *) req->base.tfm;
rc = nx_build_sg_lists(nx_ctx, &desc, req->dst,
req->src, &to_process,
processed + req->assoclen,
csbcpb->cpb.aes_gcm.iv_or_cnt);
if (rc)
goto out;
if ((to_process + processed) < nbytes)
NX_CPB_FDM(csbcpb) |= NX_FDM_INTERMEDIATE;
else
NX_CPB_FDM(csbcpb) &= ~NX_FDM_INTERMEDIATE;
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
memcpy(desc.info, csbcpb->cpb.aes_gcm.out_cnt, AES_BLOCK_SIZE);
memcpy(csbcpb->cpb.aes_gcm.in_pat_or_aad,
csbcpb->cpb.aes_gcm.out_pat_or_mac, AES_BLOCK_SIZE);
memcpy(csbcpb->cpb.aes_gcm.in_s0,
csbcpb->cpb.aes_gcm.out_s0, AES_BLOCK_SIZE);
NX_CPB_FDM(csbcpb) |= NX_FDM_CONTINUATION;
atomic_inc(&(nx_ctx->stats->aes_ops));
atomic64_add(csbcpb->csb.processed_byte_count,
&(nx_ctx->stats->aes_bytes));
processed += to_process;
} while (processed < nbytes);
mac:
if (enc) {
scatterwalk_map_and_copy(
csbcpb->cpb.aes_gcm.out_pat_or_mac,
req->dst, req->assoclen + nbytes,
crypto_aead_authsize(crypto_aead_reqtfm(req)),
SCATTERWALK_TO_SG);
} else {
u8 *itag = nx_ctx->priv.gcm.iauth_tag;
u8 *otag = csbcpb->cpb.aes_gcm.out_pat_or_mac;
scatterwalk_map_and_copy(
itag, req->src, req->assoclen + nbytes,
crypto_aead_authsize(crypto_aead_reqtfm(req)),
SCATTERWALK_FROM_SG);
rc = memcmp(itag, otag,
crypto_aead_authsize(crypto_aead_reqtfm(req))) ?
-EBADMSG : 0;
}
out:
spin_unlock_irqrestore(&nx_ctx->lock, irq_flags);
return rc;
}
static int gcm_aes_nx_encrypt(struct aead_request *req)
{
struct nx_gcm_rctx *rctx = aead_request_ctx(req);
char *iv = rctx->iv;
memcpy(iv, req->iv, 12);
return gcm_aes_nx_crypt(req, 1);
}
static int gcm_aes_nx_decrypt(struct aead_request *req)
{
struct nx_gcm_rctx *rctx = aead_request_ctx(req);
char *iv = rctx->iv;
memcpy(iv, req->iv, 12);
return gcm_aes_nx_crypt(req, 0);
}
static int gcm4106_aes_nx_encrypt(struct aead_request *req)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
struct nx_gcm_rctx *rctx = aead_request_ctx(req);
char *iv = rctx->iv;
char *nonce = nx_ctx->priv.gcm.nonce;
memcpy(iv, nonce, NX_GCM4106_NONCE_LEN);
memcpy(iv + NX_GCM4106_NONCE_LEN, req->iv, 8);
return gcm_aes_nx_crypt(req, 1);
}
static int gcm4106_aes_nx_decrypt(struct aead_request *req)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
struct nx_gcm_rctx *rctx = aead_request_ctx(req);
char *iv = rctx->iv;
char *nonce = nx_ctx->priv.gcm.nonce;
memcpy(iv, nonce, NX_GCM4106_NONCE_LEN);
memcpy(iv + NX_GCM4106_NONCE_LEN, req->iv, 8);
return gcm_aes_nx_crypt(req, 0);
}
