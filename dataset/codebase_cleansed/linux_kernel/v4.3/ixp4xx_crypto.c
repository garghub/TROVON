static inline dma_addr_t crypt_virt2phys(struct crypt_ctl *virt)
{
return crypt_phys + (virt - crypt_virt) * sizeof(struct crypt_ctl);
}
static inline struct crypt_ctl *crypt_phys2virt(dma_addr_t phys)
{
return crypt_virt + (phys - crypt_phys) / sizeof(struct crypt_ctl);
}
static inline u32 cipher_cfg_enc(struct crypto_tfm *tfm)
{
return container_of(tfm->__crt_alg, struct ixp_alg,crypto)->cfg_enc;
}
static inline u32 cipher_cfg_dec(struct crypto_tfm *tfm)
{
return container_of(tfm->__crt_alg, struct ixp_alg,crypto)->cfg_dec;
}
static inline const struct ix_hash_algo *ix_hash(struct crypto_tfm *tfm)
{
return container_of(tfm->__crt_alg, struct ixp_alg, crypto)->hash;
}
static int setup_crypt_desc(void)
{
struct device *dev = &pdev->dev;
BUILD_BUG_ON(sizeof(struct crypt_ctl) != 64);
crypt_virt = dma_alloc_coherent(dev,
NPE_QLEN * sizeof(struct crypt_ctl),
&crypt_phys, GFP_ATOMIC);
if (!crypt_virt)
return -ENOMEM;
memset(crypt_virt, 0, NPE_QLEN * sizeof(struct crypt_ctl));
return 0;
}
static struct crypt_ctl *get_crypt_desc(void)
{
int i;
static int idx = 0;
unsigned long flags;
spin_lock_irqsave(&desc_lock, flags);
if (unlikely(!crypt_virt))
setup_crypt_desc();
if (unlikely(!crypt_virt)) {
spin_unlock_irqrestore(&desc_lock, flags);
return NULL;
}
i = idx;
if (crypt_virt[i].ctl_flags == CTL_FLAG_UNUSED) {
if (++idx >= NPE_QLEN)
idx = 0;
crypt_virt[i].ctl_flags = CTL_FLAG_USED;
spin_unlock_irqrestore(&desc_lock, flags);
return crypt_virt +i;
} else {
spin_unlock_irqrestore(&desc_lock, flags);
return NULL;
}
}
static struct crypt_ctl *get_crypt_desc_emerg(void)
{
int i;
static int idx = NPE_QLEN;
struct crypt_ctl *desc;
unsigned long flags;
desc = get_crypt_desc();
if (desc)
return desc;
if (unlikely(!crypt_virt))
return NULL;
spin_lock_irqsave(&emerg_lock, flags);
i = idx;
if (crypt_virt[i].ctl_flags == CTL_FLAG_UNUSED) {
if (++idx >= NPE_QLEN_TOTAL)
idx = NPE_QLEN;
crypt_virt[i].ctl_flags = CTL_FLAG_USED;
spin_unlock_irqrestore(&emerg_lock, flags);
return crypt_virt +i;
} else {
spin_unlock_irqrestore(&emerg_lock, flags);
return NULL;
}
}
static void free_buf_chain(struct device *dev, struct buffer_desc *buf,u32 phys)
{
while (buf) {
struct buffer_desc *buf1;
u32 phys1;
buf1 = buf->next;
phys1 = buf->phys_next;
dma_unmap_single(dev, buf->phys_next, buf->buf_len, buf->dir);
dma_pool_free(buffer_pool, buf, phys);
buf = buf1;
phys = phys1;
}
}
static void finish_scattered_hmac(struct crypt_ctl *crypt)
{
struct aead_request *req = crypt->data.aead_req;
struct aead_ctx *req_ctx = aead_request_ctx(req);
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
int authsize = crypto_aead_authsize(tfm);
int decryptlen = req->assoclen + req->cryptlen - authsize;
if (req_ctx->encrypt) {
scatterwalk_map_and_copy(req_ctx->hmac_virt,
req->dst, decryptlen, authsize, 1);
}
dma_pool_free(buffer_pool, req_ctx->hmac_virt, crypt->icv_rev_aes);
}
static void one_packet(dma_addr_t phys)
{
struct device *dev = &pdev->dev;
struct crypt_ctl *crypt;
struct ixp_ctx *ctx;
int failed;
failed = phys & 0x1 ? -EBADMSG : 0;
phys &= ~0x3;
crypt = crypt_phys2virt(phys);
switch (crypt->ctl_flags & CTL_FLAG_MASK) {
case CTL_FLAG_PERFORM_AEAD: {
struct aead_request *req = crypt->data.aead_req;
struct aead_ctx *req_ctx = aead_request_ctx(req);
free_buf_chain(dev, req_ctx->src, crypt->src_buf);
free_buf_chain(dev, req_ctx->dst, crypt->dst_buf);
if (req_ctx->hmac_virt) {
finish_scattered_hmac(crypt);
}
req->base.complete(&req->base, failed);
break;
}
case CTL_FLAG_PERFORM_ABLK: {
struct ablkcipher_request *req = crypt->data.ablk_req;
struct ablk_ctx *req_ctx = ablkcipher_request_ctx(req);
if (req_ctx->dst) {
free_buf_chain(dev, req_ctx->dst, crypt->dst_buf);
}
free_buf_chain(dev, req_ctx->src, crypt->src_buf);
req->base.complete(&req->base, failed);
break;
}
case CTL_FLAG_GEN_ICV:
ctx = crypto_tfm_ctx(crypt->data.tfm);
dma_pool_free(ctx_pool, crypt->regist_ptr,
crypt->regist_buf->phys_addr);
dma_pool_free(buffer_pool, crypt->regist_buf, crypt->src_buf);
if (atomic_dec_and_test(&ctx->configuring))
complete(&ctx->completion);
break;
case CTL_FLAG_GEN_REVAES:
ctx = crypto_tfm_ctx(crypt->data.tfm);
*(u32*)ctx->decrypt.npe_ctx &= cpu_to_be32(~CIPH_ENCR);
if (atomic_dec_and_test(&ctx->configuring))
complete(&ctx->completion);
break;
default:
BUG();
}
crypt->ctl_flags = CTL_FLAG_UNUSED;
}
static void irqhandler(void *_unused)
{
tasklet_schedule(&crypto_done_tasklet);
}
static void crypto_done_action(unsigned long arg)
{
int i;
for(i=0; i<4; i++) {
dma_addr_t phys = qmgr_get_entry(RECV_QID);
if (!phys)
return;
one_packet(phys);
}
tasklet_schedule(&crypto_done_tasklet);
}
static int init_ixp_crypto(struct device *dev)
{
int ret = -ENODEV;
u32 msg[2] = { 0, 0 };
if (! ( ~(*IXP4XX_EXP_CFG2) & (IXP4XX_FEATURE_HASH |
IXP4XX_FEATURE_AES | IXP4XX_FEATURE_DES))) {
printk(KERN_ERR "ixp_crypto: No HW crypto available\n");
return ret;
}
npe_c = npe_request(NPE_ID);
if (!npe_c)
return ret;
if (!npe_running(npe_c)) {
ret = npe_load_firmware(npe_c, npe_name(npe_c), dev);
if (ret) {
return ret;
}
if (npe_recv_message(npe_c, msg, "STATUS_MSG"))
goto npe_error;
} else {
if (npe_send_message(npe_c, msg, "STATUS_MSG"))
goto npe_error;
if (npe_recv_message(npe_c, msg, "STATUS_MSG"))
goto npe_error;
}
switch ((msg[1]>>16) & 0xff) {
case 3:
printk(KERN_WARNING "Firmware of %s lacks AES support\n",
npe_name(npe_c));
support_aes = 0;
break;
case 4:
case 5:
support_aes = 1;
break;
default:
printk(KERN_ERR "Firmware of %s lacks crypto support\n",
npe_name(npe_c));
return -ENODEV;
}
BUILD_BUG_ON(SHA1_DIGEST_SIZE > sizeof(struct buffer_desc));
buffer_pool = dma_pool_create("buffer", dev,
sizeof(struct buffer_desc), 32, 0);
ret = -ENOMEM;
if (!buffer_pool) {
goto err;
}
ctx_pool = dma_pool_create("context", dev,
NPE_CTX_LEN, 16, 0);
if (!ctx_pool) {
goto err;
}
ret = qmgr_request_queue(SEND_QID, NPE_QLEN_TOTAL, 0, 0,
"ixp_crypto:out", NULL);
if (ret)
goto err;
ret = qmgr_request_queue(RECV_QID, NPE_QLEN, 0, 0,
"ixp_crypto:in", NULL);
if (ret) {
qmgr_release_queue(SEND_QID);
goto err;
}
qmgr_set_irq(RECV_QID, QUEUE_IRQ_SRC_NOT_EMPTY, irqhandler, NULL);
tasklet_init(&crypto_done_tasklet, crypto_done_action, 0);
qmgr_enable_irq(RECV_QID);
return 0;
npe_error:
printk(KERN_ERR "%s not responding\n", npe_name(npe_c));
ret = -EIO;
err:
if (ctx_pool)
dma_pool_destroy(ctx_pool);
if (buffer_pool)
dma_pool_destroy(buffer_pool);
npe_release(npe_c);
return ret;
}
static void release_ixp_crypto(struct device *dev)
{
qmgr_disable_irq(RECV_QID);
tasklet_kill(&crypto_done_tasklet);
qmgr_release_queue(SEND_QID);
qmgr_release_queue(RECV_QID);
dma_pool_destroy(ctx_pool);
dma_pool_destroy(buffer_pool);
npe_release(npe_c);
if (crypt_virt) {
dma_free_coherent(dev,
NPE_QLEN_TOTAL * sizeof( struct crypt_ctl),
crypt_virt, crypt_phys);
}
return;
}
static void reset_sa_dir(struct ix_sa_dir *dir)
{
memset(dir->npe_ctx, 0, NPE_CTX_LEN);
dir->npe_ctx_idx = 0;
dir->npe_mode = 0;
}
static int init_sa_dir(struct ix_sa_dir *dir)
{
dir->npe_ctx = dma_pool_alloc(ctx_pool, GFP_KERNEL, &dir->npe_ctx_phys);
if (!dir->npe_ctx) {
return -ENOMEM;
}
reset_sa_dir(dir);
return 0;
}
static void free_sa_dir(struct ix_sa_dir *dir)
{
memset(dir->npe_ctx, 0, NPE_CTX_LEN);
dma_pool_free(ctx_pool, dir->npe_ctx, dir->npe_ctx_phys);
}
static int init_tfm(struct crypto_tfm *tfm)
{
struct ixp_ctx *ctx = crypto_tfm_ctx(tfm);
int ret;
atomic_set(&ctx->configuring, 0);
ret = init_sa_dir(&ctx->encrypt);
if (ret)
return ret;
ret = init_sa_dir(&ctx->decrypt);
if (ret) {
free_sa_dir(&ctx->encrypt);
}
return ret;
}
static int init_tfm_ablk(struct crypto_tfm *tfm)
{
tfm->crt_ablkcipher.reqsize = sizeof(struct ablk_ctx);
return init_tfm(tfm);
}
static int init_tfm_aead(struct crypto_aead *tfm)
{
crypto_aead_set_reqsize(tfm, sizeof(struct aead_ctx));
return init_tfm(crypto_aead_tfm(tfm));
}
static void exit_tfm(struct crypto_tfm *tfm)
{
struct ixp_ctx *ctx = crypto_tfm_ctx(tfm);
free_sa_dir(&ctx->encrypt);
free_sa_dir(&ctx->decrypt);
}
static void exit_tfm_aead(struct crypto_aead *tfm)
{
exit_tfm(crypto_aead_tfm(tfm));
}
static int register_chain_var(struct crypto_tfm *tfm, u8 xpad, u32 target,
int init_len, u32 ctx_addr, const u8 *key, int key_len)
{
struct ixp_ctx *ctx = crypto_tfm_ctx(tfm);
struct crypt_ctl *crypt;
struct buffer_desc *buf;
int i;
u8 *pad;
u32 pad_phys, buf_phys;
BUILD_BUG_ON(NPE_CTX_LEN < HMAC_PAD_BLOCKLEN);
pad = dma_pool_alloc(ctx_pool, GFP_KERNEL, &pad_phys);
if (!pad)
return -ENOMEM;
buf = dma_pool_alloc(buffer_pool, GFP_KERNEL, &buf_phys);
if (!buf) {
dma_pool_free(ctx_pool, pad, pad_phys);
return -ENOMEM;
}
crypt = get_crypt_desc_emerg();
if (!crypt) {
dma_pool_free(ctx_pool, pad, pad_phys);
dma_pool_free(buffer_pool, buf, buf_phys);
return -EAGAIN;
}
memcpy(pad, key, key_len);
memset(pad + key_len, 0, HMAC_PAD_BLOCKLEN - key_len);
for (i = 0; i < HMAC_PAD_BLOCKLEN; i++) {
pad[i] ^= xpad;
}
crypt->data.tfm = tfm;
crypt->regist_ptr = pad;
crypt->regist_buf = buf;
crypt->auth_offs = 0;
crypt->auth_len = HMAC_PAD_BLOCKLEN;
crypt->crypto_ctx = ctx_addr;
crypt->src_buf = buf_phys;
crypt->icv_rev_aes = target;
crypt->mode = NPE_OP_HASH_GEN_ICV;
crypt->init_len = init_len;
crypt->ctl_flags |= CTL_FLAG_GEN_ICV;
buf->next = 0;
buf->buf_len = HMAC_PAD_BLOCKLEN;
buf->pkt_len = 0;
buf->phys_addr = pad_phys;
atomic_inc(&ctx->configuring);
qmgr_put_entry(SEND_QID, crypt_virt2phys(crypt));
BUG_ON(qmgr_stat_overflow(SEND_QID));
return 0;
}
static int setup_auth(struct crypto_tfm *tfm, int encrypt, unsigned authsize,
const u8 *key, int key_len, unsigned digest_len)
{
u32 itarget, otarget, npe_ctx_addr;
unsigned char *cinfo;
int init_len, ret = 0;
u32 cfgword;
struct ix_sa_dir *dir;
struct ixp_ctx *ctx = crypto_tfm_ctx(tfm);
const struct ix_hash_algo *algo;
dir = encrypt ? &ctx->encrypt : &ctx->decrypt;
cinfo = dir->npe_ctx + dir->npe_ctx_idx;
algo = ix_hash(tfm);
cfgword = algo->cfgword | ( authsize << 6);
#ifndef __ARMEB__
cfgword ^= 0xAA000000;
#endif
*(u32*)cinfo = cpu_to_be32(cfgword);
cinfo += sizeof(cfgword);
memcpy(cinfo, algo->icv, digest_len);
cinfo += digest_len;
itarget = dir->npe_ctx_phys + dir->npe_ctx_idx
+ sizeof(algo->cfgword);
otarget = itarget + digest_len;
init_len = cinfo - (dir->npe_ctx + dir->npe_ctx_idx);
npe_ctx_addr = dir->npe_ctx_phys + dir->npe_ctx_idx;
dir->npe_ctx_idx += init_len;
dir->npe_mode |= NPE_OP_HASH_ENABLE;
if (!encrypt)
dir->npe_mode |= NPE_OP_HASH_VERIFY;
ret = register_chain_var(tfm, HMAC_OPAD_VALUE, otarget,
init_len, npe_ctx_addr, key, key_len);
if (ret)
return ret;
return register_chain_var(tfm, HMAC_IPAD_VALUE, itarget,
init_len, npe_ctx_addr, key, key_len);
}
static int gen_rev_aes_key(struct crypto_tfm *tfm)
{
struct crypt_ctl *crypt;
struct ixp_ctx *ctx = crypto_tfm_ctx(tfm);
struct ix_sa_dir *dir = &ctx->decrypt;
crypt = get_crypt_desc_emerg();
if (!crypt) {
return -EAGAIN;
}
*(u32*)dir->npe_ctx |= cpu_to_be32(CIPH_ENCR);
crypt->data.tfm = tfm;
crypt->crypt_offs = 0;
crypt->crypt_len = AES_BLOCK128;
crypt->src_buf = 0;
crypt->crypto_ctx = dir->npe_ctx_phys;
crypt->icv_rev_aes = dir->npe_ctx_phys + sizeof(u32);
crypt->mode = NPE_OP_ENC_GEN_KEY;
crypt->init_len = dir->npe_ctx_idx;
crypt->ctl_flags |= CTL_FLAG_GEN_REVAES;
atomic_inc(&ctx->configuring);
qmgr_put_entry(SEND_QID, crypt_virt2phys(crypt));
BUG_ON(qmgr_stat_overflow(SEND_QID));
return 0;
}
static int setup_cipher(struct crypto_tfm *tfm, int encrypt,
const u8 *key, int key_len)
{
u8 *cinfo;
u32 cipher_cfg;
u32 keylen_cfg = 0;
struct ix_sa_dir *dir;
struct ixp_ctx *ctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
dir = encrypt ? &ctx->encrypt : &ctx->decrypt;
cinfo = dir->npe_ctx;
if (encrypt) {
cipher_cfg = cipher_cfg_enc(tfm);
dir->npe_mode |= NPE_OP_CRYPT_ENCRYPT;
} else {
cipher_cfg = cipher_cfg_dec(tfm);
}
if (cipher_cfg & MOD_AES) {
switch (key_len) {
case 16: keylen_cfg = MOD_AES128; break;
case 24: keylen_cfg = MOD_AES192; break;
case 32: keylen_cfg = MOD_AES256; break;
default:
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
cipher_cfg |= keylen_cfg;
} else if (cipher_cfg & MOD_3DES) {
const u32 *K = (const u32 *)key;
if (unlikely(!((K[0] ^ K[2]) | (K[1] ^ K[3])) ||
!((K[2] ^ K[4]) | (K[3] ^ K[5]))))
{
*flags |= CRYPTO_TFM_RES_BAD_KEY_SCHED;
return -EINVAL;
}
} else {
u32 tmp[DES_EXPKEY_WORDS];
if (des_ekey(tmp, key) == 0) {
*flags |= CRYPTO_TFM_RES_WEAK_KEY;
}
}
*(u32*)cinfo = cpu_to_be32(cipher_cfg);
cinfo += sizeof(cipher_cfg);
memcpy(cinfo, key, key_len);
if (key_len < DES3_EDE_KEY_SIZE && !(cipher_cfg & MOD_AES)) {
memset(cinfo + key_len, 0, DES3_EDE_KEY_SIZE -key_len);
key_len = DES3_EDE_KEY_SIZE;
}
dir->npe_ctx_idx = sizeof(cipher_cfg) + key_len;
dir->npe_mode |= NPE_OP_CRYPT_ENABLE;
if ((cipher_cfg & MOD_AES) && !encrypt) {
return gen_rev_aes_key(tfm);
}
return 0;
}
static struct buffer_desc *chainup_buffers(struct device *dev,
struct scatterlist *sg, unsigned nbytes,
struct buffer_desc *buf, gfp_t flags,
enum dma_data_direction dir)
{
for (; nbytes > 0; sg = sg_next(sg)) {
unsigned len = min(nbytes, sg->length);
struct buffer_desc *next_buf;
u32 next_buf_phys;
void *ptr;
nbytes -= len;
ptr = page_address(sg_page(sg)) + sg->offset;
next_buf = dma_pool_alloc(buffer_pool, flags, &next_buf_phys);
if (!next_buf) {
buf = NULL;
break;
}
sg_dma_address(sg) = dma_map_single(dev, ptr, len, dir);
buf->next = next_buf;
buf->phys_next = next_buf_phys;
buf = next_buf;
buf->phys_addr = sg_dma_address(sg);
buf->buf_len = len;
buf->dir = dir;
}
buf->next = NULL;
buf->phys_next = 0;
return buf;
}
static int ablk_setkey(struct crypto_ablkcipher *tfm, const u8 *key,
unsigned int key_len)
{
struct ixp_ctx *ctx = crypto_ablkcipher_ctx(tfm);
u32 *flags = &tfm->base.crt_flags;
int ret;
init_completion(&ctx->completion);
atomic_inc(&ctx->configuring);
reset_sa_dir(&ctx->encrypt);
reset_sa_dir(&ctx->decrypt);
ctx->encrypt.npe_mode = NPE_OP_HMAC_DISABLE;
ctx->decrypt.npe_mode = NPE_OP_HMAC_DISABLE;
ret = setup_cipher(&tfm->base, 0, key, key_len);
if (ret)
goto out;
ret = setup_cipher(&tfm->base, 1, key, key_len);
if (ret)
goto out;
if (*flags & CRYPTO_TFM_RES_WEAK_KEY) {
if (*flags & CRYPTO_TFM_REQ_WEAK_KEY) {
ret = -EINVAL;
} else {
*flags &= ~CRYPTO_TFM_RES_WEAK_KEY;
}
}
out:
if (!atomic_dec_and_test(&ctx->configuring))
wait_for_completion(&ctx->completion);
return ret;
}
static int ablk_rfc3686_setkey(struct crypto_ablkcipher *tfm, const u8 *key,
unsigned int key_len)
{
struct ixp_ctx *ctx = crypto_ablkcipher_ctx(tfm);
if (key_len < CTR_RFC3686_NONCE_SIZE)
return -EINVAL;
memcpy(ctx->nonce, key + (key_len - CTR_RFC3686_NONCE_SIZE),
CTR_RFC3686_NONCE_SIZE);
key_len -= CTR_RFC3686_NONCE_SIZE;
return ablk_setkey(tfm, key, key_len);
}
static int ablk_perform(struct ablkcipher_request *req, int encrypt)
{
struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
struct ixp_ctx *ctx = crypto_ablkcipher_ctx(tfm);
unsigned ivsize = crypto_ablkcipher_ivsize(tfm);
struct ix_sa_dir *dir;
struct crypt_ctl *crypt;
unsigned int nbytes = req->nbytes;
enum dma_data_direction src_direction = DMA_BIDIRECTIONAL;
struct ablk_ctx *req_ctx = ablkcipher_request_ctx(req);
struct buffer_desc src_hook;
struct device *dev = &pdev->dev;
gfp_t flags = req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP ?
GFP_KERNEL : GFP_ATOMIC;
if (qmgr_stat_full(SEND_QID))
return -EAGAIN;
if (atomic_read(&ctx->configuring))
return -EAGAIN;
dir = encrypt ? &ctx->encrypt : &ctx->decrypt;
crypt = get_crypt_desc();
if (!crypt)
return -ENOMEM;
crypt->data.ablk_req = req;
crypt->crypto_ctx = dir->npe_ctx_phys;
crypt->mode = dir->npe_mode;
crypt->init_len = dir->npe_ctx_idx;
crypt->crypt_offs = 0;
crypt->crypt_len = nbytes;
BUG_ON(ivsize && !req->info);
memcpy(crypt->iv, req->info, ivsize);
if (req->src != req->dst) {
struct buffer_desc dst_hook;
crypt->mode |= NPE_OP_NOT_IN_PLACE;
req_ctx->dst = NULL;
if (!chainup_buffers(dev, req->dst, nbytes, &dst_hook,
flags, DMA_FROM_DEVICE))
goto free_buf_dest;
src_direction = DMA_TO_DEVICE;
req_ctx->dst = dst_hook.next;
crypt->dst_buf = dst_hook.phys_next;
} else {
req_ctx->dst = NULL;
}
req_ctx->src = NULL;
if (!chainup_buffers(dev, req->src, nbytes, &src_hook,
flags, src_direction))
goto free_buf_src;
req_ctx->src = src_hook.next;
crypt->src_buf = src_hook.phys_next;
crypt->ctl_flags |= CTL_FLAG_PERFORM_ABLK;
qmgr_put_entry(SEND_QID, crypt_virt2phys(crypt));
BUG_ON(qmgr_stat_overflow(SEND_QID));
return -EINPROGRESS;
free_buf_src:
free_buf_chain(dev, req_ctx->src, crypt->src_buf);
free_buf_dest:
if (req->src != req->dst) {
free_buf_chain(dev, req_ctx->dst, crypt->dst_buf);
}
crypt->ctl_flags = CTL_FLAG_UNUSED;
return -ENOMEM;
}
static int ablk_encrypt(struct ablkcipher_request *req)
{
return ablk_perform(req, 1);
}
static int ablk_decrypt(struct ablkcipher_request *req)
{
return ablk_perform(req, 0);
}
static int ablk_rfc3686_crypt(struct ablkcipher_request *req)
{
struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
struct ixp_ctx *ctx = crypto_ablkcipher_ctx(tfm);
u8 iv[CTR_RFC3686_BLOCK_SIZE];
u8 *info = req->info;
int ret;
memcpy(iv, ctx->nonce, CTR_RFC3686_NONCE_SIZE);
memcpy(iv + CTR_RFC3686_NONCE_SIZE, info, CTR_RFC3686_IV_SIZE);
*(__be32 *)(iv + CTR_RFC3686_NONCE_SIZE + CTR_RFC3686_IV_SIZE) =
cpu_to_be32(1);
req->info = iv;
ret = ablk_perform(req, 1);
req->info = info;
return ret;
}
static int aead_perform(struct aead_request *req, int encrypt,
int cryptoffset, int eff_cryptlen, u8 *iv)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ixp_ctx *ctx = crypto_aead_ctx(tfm);
unsigned ivsize = crypto_aead_ivsize(tfm);
unsigned authsize = crypto_aead_authsize(tfm);
struct ix_sa_dir *dir;
struct crypt_ctl *crypt;
unsigned int cryptlen;
struct buffer_desc *buf, src_hook;
struct aead_ctx *req_ctx = aead_request_ctx(req);
struct device *dev = &pdev->dev;
gfp_t flags = req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP ?
GFP_KERNEL : GFP_ATOMIC;
enum dma_data_direction src_direction = DMA_BIDIRECTIONAL;
unsigned int lastlen;
if (qmgr_stat_full(SEND_QID))
return -EAGAIN;
if (atomic_read(&ctx->configuring))
return -EAGAIN;
if (encrypt) {
dir = &ctx->encrypt;
cryptlen = req->cryptlen;
} else {
dir = &ctx->decrypt;
cryptlen = req->cryptlen -authsize;
eff_cryptlen -= authsize;
}
crypt = get_crypt_desc();
if (!crypt)
return -ENOMEM;
crypt->data.aead_req = req;
crypt->crypto_ctx = dir->npe_ctx_phys;
crypt->mode = dir->npe_mode;
crypt->init_len = dir->npe_ctx_idx;
crypt->crypt_offs = cryptoffset;
crypt->crypt_len = eff_cryptlen;
crypt->auth_offs = 0;
crypt->auth_len = req->assoclen + cryptlen;
BUG_ON(ivsize && !req->iv);
memcpy(crypt->iv, req->iv, ivsize);
req_ctx->dst = NULL;
if (req->src != req->dst) {
struct buffer_desc dst_hook;
crypt->mode |= NPE_OP_NOT_IN_PLACE;
src_direction = DMA_TO_DEVICE;
buf = chainup_buffers(dev, req->dst, crypt->auth_len,
&dst_hook, flags, DMA_FROM_DEVICE);
req_ctx->dst = dst_hook.next;
crypt->dst_buf = dst_hook.phys_next;
if (!buf)
goto free_buf_dst;
if (encrypt) {
lastlen = buf->buf_len;
if (lastlen >= authsize)
crypt->icv_rev_aes = buf->phys_addr +
buf->buf_len - authsize;
}
}
buf = chainup_buffers(dev, req->src, crypt->auth_len,
&src_hook, flags, src_direction);
req_ctx->src = src_hook.next;
crypt->src_buf = src_hook.phys_next;
if (!buf)
goto free_buf_src;
if (!encrypt || !req_ctx->dst) {
lastlen = buf->buf_len;
if (lastlen >= authsize)
crypt->icv_rev_aes = buf->phys_addr +
buf->buf_len - authsize;
}
if (unlikely(lastlen < authsize)) {
req_ctx->hmac_virt = dma_pool_alloc(buffer_pool, flags,
&crypt->icv_rev_aes);
if (unlikely(!req_ctx->hmac_virt))
goto free_buf_src;
if (!encrypt) {
scatterwalk_map_and_copy(req_ctx->hmac_virt,
req->src, cryptlen, authsize, 0);
}
req_ctx->encrypt = encrypt;
} else {
req_ctx->hmac_virt = NULL;
}
crypt->ctl_flags |= CTL_FLAG_PERFORM_AEAD;
qmgr_put_entry(SEND_QID, crypt_virt2phys(crypt));
BUG_ON(qmgr_stat_overflow(SEND_QID));
return -EINPROGRESS;
free_buf_src:
free_buf_chain(dev, req_ctx->src, crypt->src_buf);
free_buf_dst:
free_buf_chain(dev, req_ctx->dst, crypt->dst_buf);
crypt->ctl_flags = CTL_FLAG_UNUSED;
return -ENOMEM;
}
static int aead_setup(struct crypto_aead *tfm, unsigned int authsize)
{
struct ixp_ctx *ctx = crypto_aead_ctx(tfm);
u32 *flags = &tfm->base.crt_flags;
unsigned digest_len = crypto_aead_maxauthsize(tfm);
int ret;
if (!ctx->enckey_len && !ctx->authkey_len)
return 0;
init_completion(&ctx->completion);
atomic_inc(&ctx->configuring);
reset_sa_dir(&ctx->encrypt);
reset_sa_dir(&ctx->decrypt);
ret = setup_cipher(&tfm->base, 0, ctx->enckey, ctx->enckey_len);
if (ret)
goto out;
ret = setup_cipher(&tfm->base, 1, ctx->enckey, ctx->enckey_len);
if (ret)
goto out;
ret = setup_auth(&tfm->base, 0, authsize, ctx->authkey,
ctx->authkey_len, digest_len);
if (ret)
goto out;
ret = setup_auth(&tfm->base, 1, authsize, ctx->authkey,
ctx->authkey_len, digest_len);
if (ret)
goto out;
if (*flags & CRYPTO_TFM_RES_WEAK_KEY) {
if (*flags & CRYPTO_TFM_REQ_WEAK_KEY) {
ret = -EINVAL;
goto out;
} else {
*flags &= ~CRYPTO_TFM_RES_WEAK_KEY;
}
}
out:
if (!atomic_dec_and_test(&ctx->configuring))
wait_for_completion(&ctx->completion);
return ret;
}
static int aead_setauthsize(struct crypto_aead *tfm, unsigned int authsize)
{
int max = crypto_aead_maxauthsize(tfm) >> 2;
if ((authsize>>2) < 1 || (authsize>>2) > max || (authsize & 3))
return -EINVAL;
return aead_setup(tfm, authsize);
}
static int aead_setkey(struct crypto_aead *tfm, const u8 *key,
unsigned int keylen)
{
struct ixp_ctx *ctx = crypto_aead_ctx(tfm);
struct crypto_authenc_keys keys;
if (crypto_authenc_extractkeys(&keys, key, keylen) != 0)
goto badkey;
if (keys.authkeylen > sizeof(ctx->authkey))
goto badkey;
if (keys.enckeylen > sizeof(ctx->enckey))
goto badkey;
memcpy(ctx->authkey, keys.authkey, keys.authkeylen);
memcpy(ctx->enckey, keys.enckey, keys.enckeylen);
ctx->authkey_len = keys.authkeylen;
ctx->enckey_len = keys.enckeylen;
return aead_setup(tfm, crypto_aead_authsize(tfm));
badkey:
crypto_aead_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
static int aead_encrypt(struct aead_request *req)
{
return aead_perform(req, 1, req->assoclen, req->cryptlen, req->iv);
}
static int aead_decrypt(struct aead_request *req)
{
return aead_perform(req, 0, req->assoclen, req->cryptlen, req->iv);
}
static int __init ixp_module_init(void)
{
int num = ARRAY_SIZE(ixp4xx_algos);
int i, err;
pdev = platform_device_register_full(&ixp_dev_info);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
spin_lock_init(&desc_lock);
spin_lock_init(&emerg_lock);
err = init_ixp_crypto(&pdev->dev);
if (err) {
platform_device_unregister(pdev);
return err;
}
for (i=0; i< num; i++) {
struct crypto_alg *cra = &ixp4xx_algos[i].crypto;
if (snprintf(cra->cra_driver_name, CRYPTO_MAX_ALG_NAME,
"%s"IXP_POSTFIX, cra->cra_name) >=
CRYPTO_MAX_ALG_NAME)
{
continue;
}
if (!support_aes && (ixp4xx_algos[i].cfg_enc & MOD_AES)) {
continue;
}
cra->cra_type = &crypto_ablkcipher_type;
cra->cra_flags = CRYPTO_ALG_TYPE_ABLKCIPHER |
CRYPTO_ALG_KERN_DRIVER_ONLY |
CRYPTO_ALG_ASYNC;
if (!cra->cra_ablkcipher.setkey)
cra->cra_ablkcipher.setkey = ablk_setkey;
if (!cra->cra_ablkcipher.encrypt)
cra->cra_ablkcipher.encrypt = ablk_encrypt;
if (!cra->cra_ablkcipher.decrypt)
cra->cra_ablkcipher.decrypt = ablk_decrypt;
cra->cra_init = init_tfm_ablk;
cra->cra_ctxsize = sizeof(struct ixp_ctx);
cra->cra_module = THIS_MODULE;
cra->cra_alignmask = 3;
cra->cra_priority = 300;
cra->cra_exit = exit_tfm;
if (crypto_register_alg(cra))
printk(KERN_ERR "Failed to register '%s'\n",
cra->cra_name);
else
ixp4xx_algos[i].registered = 1;
}
for (i = 0; i < ARRAY_SIZE(ixp4xx_aeads); i++) {
struct aead_alg *cra = &ixp4xx_aeads[i].crypto;
if (snprintf(cra->base.cra_driver_name, CRYPTO_MAX_ALG_NAME,
"%s"IXP_POSTFIX, cra->base.cra_name) >=
CRYPTO_MAX_ALG_NAME)
continue;
if (!support_aes && (ixp4xx_algos[i].cfg_enc & MOD_AES))
continue;
cra->base.cra_flags = CRYPTO_ALG_KERN_DRIVER_ONLY |
CRYPTO_ALG_ASYNC;
cra->setkey = aead_setkey;
cra->setauthsize = aead_setauthsize;
cra->encrypt = aead_encrypt;
cra->decrypt = aead_decrypt;
cra->init = init_tfm_aead;
cra->exit = exit_tfm_aead;
cra->base.cra_ctxsize = sizeof(struct ixp_ctx);
cra->base.cra_module = THIS_MODULE;
cra->base.cra_alignmask = 3;
cra->base.cra_priority = 300;
if (crypto_register_aead(cra))
printk(KERN_ERR "Failed to register '%s'\n",
cra->base.cra_driver_name);
else
ixp4xx_aeads[i].registered = 1;
}
return 0;
}
static void __exit ixp_module_exit(void)
{
int num = ARRAY_SIZE(ixp4xx_algos);
int i;
for (i = 0; i < ARRAY_SIZE(ixp4xx_aeads); i++) {
if (ixp4xx_aeads[i].registered)
crypto_unregister_aead(&ixp4xx_aeads[i].crypto);
}
for (i=0; i< num; i++) {
if (ixp4xx_algos[i].registered)
crypto_unregister_alg(&ixp4xx_algos[i].crypto);
}
release_ixp_crypto(&pdev->dev);
platform_device_unregister(pdev);
}
