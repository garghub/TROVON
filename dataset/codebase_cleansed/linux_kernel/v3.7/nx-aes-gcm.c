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
static int gcm_aes_nx_setauthsize(struct crypto_aead *tfm,
unsigned int authsize)
{
if (authsize > crypto_aead_alg(tfm)->maxauthsize)
return -EINVAL;
crypto_aead_crt(tfm)->authsize = authsize;
return 0;
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
crypto_aead_crt(tfm)->authsize = authsize;
return 0;
}
static int nx_gca(struct nx_crypto_ctx *nx_ctx,
struct aead_request *req,
u8 *out)
{
struct nx_csbcpb *csbcpb_aead = nx_ctx->csbcpb_aead;
int rc = -EINVAL;
struct scatter_walk walk;
struct nx_sg *nx_sg = nx_ctx->in_sg;
if (req->assoclen > nx_ctx->ap->databytelen)
goto out;
if (req->assoclen <= AES_BLOCK_SIZE) {
scatterwalk_start(&walk, req->assoc);
scatterwalk_copychunks(out, &walk, req->assoclen,
SCATTERWALK_FROM_SG);
scatterwalk_done(&walk, SCATTERWALK_FROM_SG, 0);
rc = 0;
goto out;
}
nx_sg = nx_walk_and_build(nx_sg, nx_ctx->ap->sglen, req->assoc, 0,
req->assoclen);
nx_ctx->op_aead.inlen = (nx_ctx->in_sg - nx_sg) * sizeof(struct nx_sg);
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op_aead,
req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
atomic_inc(&(nx_ctx->stats->aes_ops));
atomic64_add(req->assoclen, &(nx_ctx->stats->aes_bytes));
memcpy(out, csbcpb_aead->cpb.aes_gca.out_pat, AES_BLOCK_SIZE);
out:
return rc;
}
static int gcm_aes_nx_crypt(struct aead_request *req, int enc)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
struct blkcipher_desc desc;
unsigned int nbytes = req->cryptlen;
int rc = -EINVAL;
if (nbytes > nx_ctx->ap->databytelen)
goto out;
desc.info = nx_ctx->priv.gcm.iv;
*(u32 *)(desc.info + NX_GCM_CTR_OFFSET) = 1;
if (nbytes == 0) {
char src[AES_BLOCK_SIZE] = {};
struct scatterlist sg;
desc.tfm = crypto_alloc_blkcipher("ctr(aes)", 0, 0);
if (IS_ERR(desc.tfm)) {
rc = -ENOMEM;
goto out;
}
crypto_blkcipher_setkey(desc.tfm, csbcpb->cpb.aes_gcm.key,
NX_CPB_KEY_SIZE(csbcpb) == NX_KS_AES_128 ? 16 :
NX_CPB_KEY_SIZE(csbcpb) == NX_KS_AES_192 ? 24 : 32);
sg_init_one(&sg, src, AES_BLOCK_SIZE);
if (enc)
crypto_blkcipher_encrypt_iv(&desc, req->dst, &sg,
AES_BLOCK_SIZE);
else
crypto_blkcipher_decrypt_iv(&desc, req->dst, &sg,
AES_BLOCK_SIZE);
crypto_free_blkcipher(desc.tfm);
rc = 0;
goto out;
}
desc.tfm = (struct crypto_blkcipher *)req->base.tfm;
csbcpb->cpb.aes_gcm.bit_length_aad = req->assoclen * 8;
if (req->assoclen) {
rc = nx_gca(nx_ctx, req, csbcpb->cpb.aes_gcm.in_pat_or_aad);
if (rc)
goto out;
}
if (enc)
NX_CPB_FDM(csbcpb) |= NX_FDM_ENDE_ENCRYPT;
else
nbytes -= AES_BLOCK_SIZE;
csbcpb->cpb.aes_gcm.bit_length_data = nbytes * 8;
rc = nx_build_sg_lists(nx_ctx, &desc, req->dst, req->src, nbytes,
csbcpb->cpb.aes_gcm.iv_or_cnt);
if (rc)
goto out;
rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP);
if (rc)
goto out;
atomic_inc(&(nx_ctx->stats->aes_ops));
atomic64_add(csbcpb->csb.processed_byte_count,
&(nx_ctx->stats->aes_bytes));
if (enc) {
scatterwalk_map_and_copy(csbcpb->cpb.aes_gcm.out_pat_or_mac,
req->dst, nbytes,
crypto_aead_authsize(crypto_aead_reqtfm(req)),
SCATTERWALK_TO_SG);
} else if (req->assoclen) {
u8 *itag = nx_ctx->priv.gcm.iauth_tag;
u8 *otag = csbcpb->cpb.aes_gcm.out_pat_or_mac;
scatterwalk_map_and_copy(itag, req->dst, nbytes,
crypto_aead_authsize(crypto_aead_reqtfm(req)),
SCATTERWALK_FROM_SG);
rc = memcmp(itag, otag,
crypto_aead_authsize(crypto_aead_reqtfm(req))) ?
-EBADMSG : 0;
}
out:
return rc;
}
static int gcm_aes_nx_encrypt(struct aead_request *req)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
char *iv = nx_ctx->priv.gcm.iv;
memcpy(iv, req->iv, 12);
return gcm_aes_nx_crypt(req, 1);
}
static int gcm_aes_nx_decrypt(struct aead_request *req)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
char *iv = nx_ctx->priv.gcm.iv;
memcpy(iv, req->iv, 12);
return gcm_aes_nx_crypt(req, 0);
}
static int gcm4106_aes_nx_encrypt(struct aead_request *req)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
char *iv = nx_ctx->priv.gcm.iv;
char *nonce = nx_ctx->priv.gcm.nonce;
memcpy(iv, nonce, NX_GCM4106_NONCE_LEN);
memcpy(iv + NX_GCM4106_NONCE_LEN, req->iv, 8);
return gcm_aes_nx_crypt(req, 1);
}
static int gcm4106_aes_nx_decrypt(struct aead_request *req)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(req->base.tfm);
char *iv = nx_ctx->priv.gcm.iv;
char *nonce = nx_ctx->priv.gcm.nonce;
memcpy(iv, nonce, NX_GCM4106_NONCE_LEN);
memcpy(iv + NX_GCM4106_NONCE_LEN, req->iv, 8);
return gcm_aes_nx_crypt(req, 0);
}
