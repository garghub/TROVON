static inline struct spacc_alg *to_spacc_alg(struct crypto_alg *alg)
{
return alg ? container_of(alg, struct spacc_alg, alg) : NULL;
}
static inline struct spacc_aead *to_spacc_aead(struct aead_alg *alg)
{
return container_of(alg, struct spacc_aead, alg);
}
static inline int spacc_fifo_cmd_full(struct spacc_engine *engine)
{
u32 fifo_stat = readl(engine->regs + SPA_FIFO_STAT_REG_OFFSET);
return fifo_stat & SPA_FIFO_CMD_FULL;
}
static inline void __iomem *spacc_ctx_page_addr(struct spacc_generic_ctx *ctx,
unsigned indx,
bool is_cipher_ctx)
{
return is_cipher_ctx ? ctx->engine->cipher_ctx_base +
(indx * ctx->engine->cipher_pg_sz) :
ctx->engine->hash_key_base + (indx * ctx->engine->hash_pg_sz);
}
static inline void memcpy_toio32(u32 __iomem *dst, const void *src,
unsigned count)
{
const u32 *src32 = (const u32 *) src;
while (count--)
writel(*src32++, dst++);
}
static void spacc_cipher_write_ctx(struct spacc_generic_ctx *ctx,
void __iomem *page_addr, const u8 *key,
size_t key_len, const u8 *iv, size_t iv_len)
{
void __iomem *key_ptr = page_addr + ctx->key_offs;
void __iomem *iv_ptr = page_addr + ctx->iv_offs;
memcpy_toio32(key_ptr, key, key_len / 4);
memcpy_toio32(iv_ptr, iv, iv_len / 4);
}
static unsigned spacc_load_ctx(struct spacc_generic_ctx *ctx,
const u8 *ciph_key, size_t ciph_len,
const u8 *iv, size_t ivlen, const u8 *hash_key,
size_t hash_len)
{
unsigned indx = ctx->engine->next_ctx++;
void __iomem *ciph_page_addr, *hash_page_addr;
ciph_page_addr = spacc_ctx_page_addr(ctx, indx, 1);
hash_page_addr = spacc_ctx_page_addr(ctx, indx, 0);
ctx->engine->next_ctx &= ctx->engine->fifo_sz - 1;
spacc_cipher_write_ctx(ctx, ciph_page_addr, ciph_key, ciph_len, iv,
ivlen);
writel(ciph_len | (indx << SPA_KEY_SZ_CTX_INDEX_OFFSET) |
(1 << SPA_KEY_SZ_CIPHER_OFFSET),
ctx->engine->regs + SPA_KEY_SZ_REG_OFFSET);
if (hash_key) {
memcpy_toio32(hash_page_addr, hash_key, hash_len / 4);
writel(hash_len | (indx << SPA_KEY_SZ_CTX_INDEX_OFFSET),
ctx->engine->regs + SPA_KEY_SZ_REG_OFFSET);
}
return indx;
}
static inline int sg_count(struct scatterlist *sg_list, int nbytes)
{
return sg_nents_for_len(sg_list, nbytes);
}
static inline void ddt_set(struct spacc_ddt *ddt, dma_addr_t phys, size_t len)
{
ddt->p = phys;
ddt->len = len;
}
static struct spacc_ddt *spacc_sg_to_ddt(struct spacc_engine *engine,
struct scatterlist *payload,
unsigned nbytes,
enum dma_data_direction dir,
dma_addr_t *ddt_phys)
{
unsigned nents, mapped_ents;
struct scatterlist *cur;
struct spacc_ddt *ddt;
int i;
nents = sg_count(payload, nbytes);
mapped_ents = dma_map_sg(engine->dev, payload, nents, dir);
if (mapped_ents + 1 > MAX_DDT_LEN)
goto out;
ddt = dma_pool_alloc(engine->req_pool, GFP_ATOMIC, ddt_phys);
if (!ddt)
goto out;
for_each_sg(payload, cur, mapped_ents, i)
ddt_set(&ddt[i], sg_dma_address(cur), sg_dma_len(cur));
ddt_set(&ddt[mapped_ents], 0, 0);
return ddt;
out:
dma_unmap_sg(engine->dev, payload, nents, dir);
return NULL;
}
static int spacc_aead_make_ddts(struct aead_request *areq)
{
struct crypto_aead *aead = crypto_aead_reqtfm(areq);
struct spacc_req *req = aead_request_ctx(areq);
struct spacc_engine *engine = req->engine;
struct spacc_ddt *src_ddt, *dst_ddt;
unsigned total;
unsigned int src_nents, dst_nents;
struct scatterlist *cur;
int i, dst_ents, src_ents;
total = areq->assoclen + areq->cryptlen;
if (req->is_encrypt)
total += crypto_aead_authsize(aead);
src_nents = sg_count(areq->src, total);
if (src_nents + 1 > MAX_DDT_LEN)
return -E2BIG;
dst_nents = 0;
if (areq->src != areq->dst) {
dst_nents = sg_count(areq->dst, total);
if (src_nents + 1 > MAX_DDT_LEN)
return -E2BIG;
}
src_ddt = dma_pool_alloc(engine->req_pool, GFP_ATOMIC, &req->src_addr);
if (!src_ddt)
goto err;
dst_ddt = dma_pool_alloc(engine->req_pool, GFP_ATOMIC, &req->dst_addr);
if (!dst_ddt)
goto err_free_src;
req->src_ddt = src_ddt;
req->dst_ddt = dst_ddt;
if (dst_nents) {
src_ents = dma_map_sg(engine->dev, areq->src, src_nents,
DMA_TO_DEVICE);
if (!src_ents)
goto err_free_dst;
dst_ents = dma_map_sg(engine->dev, areq->dst, dst_nents,
DMA_FROM_DEVICE);
if (!dst_ents) {
dma_unmap_sg(engine->dev, areq->src, src_nents,
DMA_TO_DEVICE);
goto err_free_dst;
}
} else {
src_ents = dma_map_sg(engine->dev, areq->src, src_nents,
DMA_BIDIRECTIONAL);
if (!src_ents)
goto err_free_dst;
dst_ents = src_ents;
}
for_each_sg(areq->src, cur, src_ents, i)
ddt_set(src_ddt++, sg_dma_address(cur), sg_dma_len(cur));
total = req->is_encrypt ? 0 : areq->assoclen;
for_each_sg(areq->dst, cur, dst_ents, i) {
unsigned len = sg_dma_len(cur);
if (len <= total) {
total -= len;
continue;
}
ddt_set(dst_ddt++, sg_dma_address(cur) + total, len - total);
}
ddt_set(src_ddt, 0, 0);
ddt_set(dst_ddt, 0, 0);
return 0;
err_free_dst:
dma_pool_free(engine->req_pool, dst_ddt, req->dst_addr);
err_free_src:
dma_pool_free(engine->req_pool, src_ddt, req->src_addr);
err:
return -ENOMEM;
}
static void spacc_aead_free_ddts(struct spacc_req *req)
{
struct aead_request *areq = container_of(req->req, struct aead_request,
base);
struct crypto_aead *aead = crypto_aead_reqtfm(areq);
unsigned total = areq->assoclen + areq->cryptlen +
(req->is_encrypt ? crypto_aead_authsize(aead) : 0);
struct spacc_aead_ctx *aead_ctx = crypto_aead_ctx(aead);
struct spacc_engine *engine = aead_ctx->generic.engine;
unsigned nents = sg_count(areq->src, total);
if (areq->src != areq->dst) {
dma_unmap_sg(engine->dev, areq->src, nents, DMA_TO_DEVICE);
dma_unmap_sg(engine->dev, areq->dst,
sg_count(areq->dst, total),
DMA_FROM_DEVICE);
} else
dma_unmap_sg(engine->dev, areq->src, nents, DMA_BIDIRECTIONAL);
dma_pool_free(engine->req_pool, req->src_ddt, req->src_addr);
dma_pool_free(engine->req_pool, req->dst_ddt, req->dst_addr);
}
static void spacc_free_ddt(struct spacc_req *req, struct spacc_ddt *ddt,
dma_addr_t ddt_addr, struct scatterlist *payload,
unsigned nbytes, enum dma_data_direction dir)
{
unsigned nents = sg_count(payload, nbytes);
dma_unmap_sg(req->engine->dev, payload, nents, dir);
dma_pool_free(req->engine->req_pool, ddt, ddt_addr);
}
static int spacc_aead_setkey(struct crypto_aead *tfm, const u8 *key,
unsigned int keylen)
{
struct spacc_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct crypto_authenc_keys keys;
int err;
crypto_aead_clear_flags(ctx->sw_cipher, CRYPTO_TFM_REQ_MASK);
crypto_aead_set_flags(ctx->sw_cipher, crypto_aead_get_flags(tfm) &
CRYPTO_TFM_REQ_MASK);
err = crypto_aead_setkey(ctx->sw_cipher, key, keylen);
crypto_aead_clear_flags(tfm, CRYPTO_TFM_RES_MASK);
crypto_aead_set_flags(tfm, crypto_aead_get_flags(ctx->sw_cipher) &
CRYPTO_TFM_RES_MASK);
if (err)
return err;
if (crypto_authenc_extractkeys(&keys, key, keylen) != 0)
goto badkey;
if (keys.enckeylen > AES_MAX_KEY_SIZE)
goto badkey;
if (keys.authkeylen > sizeof(ctx->hash_ctx))
goto badkey;
memcpy(ctx->cipher_key, keys.enckey, keys.enckeylen);
ctx->cipher_key_len = keys.enckeylen;
memcpy(ctx->hash_ctx, keys.authkey, keys.authkeylen);
ctx->hash_key_len = keys.authkeylen;
return 0;
badkey:
crypto_aead_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
static int spacc_aead_setauthsize(struct crypto_aead *tfm,
unsigned int authsize)
{
struct spacc_aead_ctx *ctx = crypto_tfm_ctx(crypto_aead_tfm(tfm));
return crypto_aead_setauthsize(ctx->sw_cipher, authsize);
}
static int spacc_aead_need_fallback(struct aead_request *aead_req)
{
struct crypto_aead *aead = crypto_aead_reqtfm(aead_req);
struct aead_alg *alg = crypto_aead_alg(aead);
struct spacc_aead *spacc_alg = to_spacc_aead(alg);
struct spacc_aead_ctx *ctx = crypto_aead_ctx(aead);
if ((spacc_alg->ctrl_default & SPACC_CRYPTO_ALG_MASK) ==
SPA_CTRL_CIPH_ALG_AES &&
ctx->cipher_key_len != AES_KEYSIZE_128 &&
ctx->cipher_key_len != AES_KEYSIZE_256)
return 1;
return 0;
}
static int spacc_aead_do_fallback(struct aead_request *req, unsigned alg_type,
bool is_encrypt)
{
struct crypto_tfm *old_tfm = crypto_aead_tfm(crypto_aead_reqtfm(req));
struct spacc_aead_ctx *ctx = crypto_tfm_ctx(old_tfm);
struct aead_request *subreq = aead_request_ctx(req);
aead_request_set_tfm(subreq, ctx->sw_cipher);
aead_request_set_callback(subreq, req->base.flags,
req->base.complete, req->base.data);
aead_request_set_crypt(subreq, req->src, req->dst, req->cryptlen,
req->iv);
aead_request_set_ad(subreq, req->assoclen);
return is_encrypt ? crypto_aead_encrypt(subreq) :
crypto_aead_decrypt(subreq);
}
static void spacc_aead_complete(struct spacc_req *req)
{
spacc_aead_free_ddts(req);
req->req->complete(req->req, req->result);
}
static int spacc_aead_submit(struct spacc_req *req)
{
struct aead_request *aead_req =
container_of(req->req, struct aead_request, base);
struct crypto_aead *aead = crypto_aead_reqtfm(aead_req);
unsigned int authsize = crypto_aead_authsize(aead);
struct spacc_aead_ctx *ctx = crypto_aead_ctx(aead);
struct aead_alg *alg = crypto_aead_alg(aead);
struct spacc_aead *spacc_alg = to_spacc_aead(alg);
struct spacc_engine *engine = ctx->generic.engine;
u32 ctrl, proc_len, assoc_len;
req->result = -EINPROGRESS;
req->ctx_id = spacc_load_ctx(&ctx->generic, ctx->cipher_key,
ctx->cipher_key_len, aead_req->iv, crypto_aead_ivsize(aead),
ctx->hash_ctx, ctx->hash_key_len);
writel(req->src_addr, engine->regs + SPA_SRC_PTR_REG_OFFSET);
writel(req->dst_addr, engine->regs + SPA_DST_PTR_REG_OFFSET);
writel(0, engine->regs + SPA_OFFSET_REG_OFFSET);
assoc_len = aead_req->assoclen;
proc_len = aead_req->cryptlen + assoc_len;
if (!req->is_encrypt)
proc_len -= authsize;
writel(proc_len, engine->regs + SPA_PROC_LEN_REG_OFFSET);
writel(assoc_len, engine->regs + SPA_AAD_LEN_REG_OFFSET);
writel(authsize, engine->regs + SPA_ICV_LEN_REG_OFFSET);
writel(0, engine->regs + SPA_ICV_OFFSET_REG_OFFSET);
writel(0, engine->regs + SPA_AUX_INFO_REG_OFFSET);
ctrl = spacc_alg->ctrl_default | (req->ctx_id << SPA_CTRL_CTX_IDX) |
(1 << SPA_CTRL_ICV_APPEND);
if (req->is_encrypt)
ctrl |= (1 << SPA_CTRL_ENCRYPT_IDX) | (1 << SPA_CTRL_AAD_COPY);
else
ctrl |= (1 << SPA_CTRL_KEY_EXP);
mod_timer(&engine->packet_timeout, jiffies + PACKET_TIMEOUT);
writel(ctrl, engine->regs + SPA_CTRL_REG_OFFSET);
return -EINPROGRESS;
}
static void spacc_push(struct spacc_engine *engine)
{
struct spacc_req *req;
while (!list_empty(&engine->pending) &&
engine->in_flight + 1 <= engine->fifo_sz) {
++engine->in_flight;
req = list_first_entry(&engine->pending, struct spacc_req,
list);
list_move_tail(&req->list, &engine->in_progress);
req->result = spacc_req_submit(req);
}
}
static int spacc_aead_setup(struct aead_request *req,
unsigned alg_type, bool is_encrypt)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct aead_alg *alg = crypto_aead_alg(aead);
struct spacc_engine *engine = to_spacc_aead(alg)->engine;
struct spacc_req *dev_req = aead_request_ctx(req);
int err;
unsigned long flags;
dev_req->req = &req->base;
dev_req->is_encrypt = is_encrypt;
dev_req->result = -EBUSY;
dev_req->engine = engine;
dev_req->complete = spacc_aead_complete;
if (unlikely(spacc_aead_need_fallback(req) ||
((err = spacc_aead_make_ddts(req)) == -E2BIG)))
return spacc_aead_do_fallback(req, alg_type, is_encrypt);
if (err)
goto out;
err = -EINPROGRESS;
spin_lock_irqsave(&engine->hw_lock, flags);
if (unlikely(spacc_fifo_cmd_full(engine)) ||
engine->in_flight + 1 > engine->fifo_sz) {
if (!(req->base.flags & CRYPTO_TFM_REQ_MAY_BACKLOG)) {
err = -EBUSY;
spin_unlock_irqrestore(&engine->hw_lock, flags);
goto out_free_ddts;
}
list_add_tail(&dev_req->list, &engine->pending);
} else {
list_add_tail(&dev_req->list, &engine->pending);
spacc_push(engine);
}
spin_unlock_irqrestore(&engine->hw_lock, flags);
goto out;
out_free_ddts:
spacc_aead_free_ddts(dev_req);
out:
return err;
}
static int spacc_aead_encrypt(struct aead_request *req)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct spacc_aead *alg = to_spacc_aead(crypto_aead_alg(aead));
return spacc_aead_setup(req, alg->type, 1);
}
static int spacc_aead_decrypt(struct aead_request *req)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct spacc_aead *alg = to_spacc_aead(crypto_aead_alg(aead));
return spacc_aead_setup(req, alg->type, 0);
}
static int spacc_aead_cra_init(struct crypto_aead *tfm)
{
struct spacc_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_alg *alg = crypto_aead_alg(tfm);
struct spacc_aead *spacc_alg = to_spacc_aead(alg);
struct spacc_engine *engine = spacc_alg->engine;
ctx->generic.flags = spacc_alg->type;
ctx->generic.engine = engine;
ctx->sw_cipher = crypto_alloc_aead(alg->base.cra_name, 0,
CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(ctx->sw_cipher))
return PTR_ERR(ctx->sw_cipher);
ctx->generic.key_offs = spacc_alg->key_offs;
ctx->generic.iv_offs = spacc_alg->iv_offs;
crypto_aead_set_reqsize(
tfm,
max(sizeof(struct spacc_req),
sizeof(struct aead_request) +
crypto_aead_reqsize(ctx->sw_cipher)));
return 0;
}
static void spacc_aead_cra_exit(struct crypto_aead *tfm)
{
struct spacc_aead_ctx *ctx = crypto_aead_ctx(tfm);
crypto_free_aead(ctx->sw_cipher);
}
static int spacc_des_setkey(struct crypto_ablkcipher *cipher, const u8 *key,
unsigned int len)
{
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(cipher);
struct spacc_ablk_ctx *ctx = crypto_tfm_ctx(tfm);
u32 tmp[DES_EXPKEY_WORDS];
if (len > DES3_EDE_KEY_SIZE) {
crypto_ablkcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
if (unlikely(!des_ekey(tmp, key)) &&
(crypto_ablkcipher_get_flags(cipher) & CRYPTO_TFM_REQ_WEAK_KEY)) {
tfm->crt_flags |= CRYPTO_TFM_RES_WEAK_KEY;
return -EINVAL;
}
memcpy(ctx->key, key, len);
ctx->key_len = len;
return 0;
}
static int spacc_aes_setkey(struct crypto_ablkcipher *cipher, const u8 *key,
unsigned int len)
{
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(cipher);
struct spacc_ablk_ctx *ctx = crypto_tfm_ctx(tfm);
int err = 0;
if (len > AES_MAX_KEY_SIZE) {
crypto_ablkcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
if (len != AES_KEYSIZE_128 && len != AES_KEYSIZE_256 &&
ctx->sw_cipher) {
ctx->sw_cipher->base.crt_flags &= ~CRYPTO_TFM_REQ_MASK;
ctx->sw_cipher->base.crt_flags |=
cipher->base.crt_flags & CRYPTO_TFM_REQ_MASK;
err = crypto_ablkcipher_setkey(ctx->sw_cipher, key, len);
if (err)
goto sw_setkey_failed;
} else if (len != AES_KEYSIZE_128 && len != AES_KEYSIZE_256 &&
!ctx->sw_cipher)
err = -EINVAL;
memcpy(ctx->key, key, len);
ctx->key_len = len;
sw_setkey_failed:
if (err && ctx->sw_cipher) {
tfm->crt_flags &= ~CRYPTO_TFM_RES_MASK;
tfm->crt_flags |=
ctx->sw_cipher->base.crt_flags & CRYPTO_TFM_RES_MASK;
}
return err;
}
static int spacc_kasumi_f8_setkey(struct crypto_ablkcipher *cipher,
const u8 *key, unsigned int len)
{
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(cipher);
struct spacc_ablk_ctx *ctx = crypto_tfm_ctx(tfm);
int err = 0;
if (len > AES_MAX_KEY_SIZE) {
crypto_ablkcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
err = -EINVAL;
goto out;
}
memcpy(ctx->key, key, len);
ctx->key_len = len;
out:
return err;
}
static int spacc_ablk_need_fallback(struct spacc_req *req)
{
struct spacc_ablk_ctx *ctx;
struct crypto_tfm *tfm = req->req->tfm;
struct crypto_alg *alg = req->req->tfm->__crt_alg;
struct spacc_alg *spacc_alg = to_spacc_alg(alg);
ctx = crypto_tfm_ctx(tfm);
return (spacc_alg->ctrl_default & SPACC_CRYPTO_ALG_MASK) ==
SPA_CTRL_CIPH_ALG_AES &&
ctx->key_len != AES_KEYSIZE_128 &&
ctx->key_len != AES_KEYSIZE_256;
}
static void spacc_ablk_complete(struct spacc_req *req)
{
struct ablkcipher_request *ablk_req =
container_of(req->req, struct ablkcipher_request, base);
if (ablk_req->src != ablk_req->dst) {
spacc_free_ddt(req, req->src_ddt, req->src_addr, ablk_req->src,
ablk_req->nbytes, DMA_TO_DEVICE);
spacc_free_ddt(req, req->dst_ddt, req->dst_addr, ablk_req->dst,
ablk_req->nbytes, DMA_FROM_DEVICE);
} else
spacc_free_ddt(req, req->dst_ddt, req->dst_addr, ablk_req->dst,
ablk_req->nbytes, DMA_BIDIRECTIONAL);
req->req->complete(req->req, req->result);
}
static int spacc_ablk_submit(struct spacc_req *req)
{
struct crypto_tfm *tfm = req->req->tfm;
struct spacc_ablk_ctx *ctx = crypto_tfm_ctx(tfm);
struct ablkcipher_request *ablk_req = ablkcipher_request_cast(req->req);
struct crypto_alg *alg = req->req->tfm->__crt_alg;
struct spacc_alg *spacc_alg = to_spacc_alg(alg);
struct spacc_engine *engine = ctx->generic.engine;
u32 ctrl;
req->ctx_id = spacc_load_ctx(&ctx->generic, ctx->key,
ctx->key_len, ablk_req->info, alg->cra_ablkcipher.ivsize,
NULL, 0);
writel(req->src_addr, engine->regs + SPA_SRC_PTR_REG_OFFSET);
writel(req->dst_addr, engine->regs + SPA_DST_PTR_REG_OFFSET);
writel(0, engine->regs + SPA_OFFSET_REG_OFFSET);
writel(ablk_req->nbytes, engine->regs + SPA_PROC_LEN_REG_OFFSET);
writel(0, engine->regs + SPA_ICV_OFFSET_REG_OFFSET);
writel(0, engine->regs + SPA_AUX_INFO_REG_OFFSET);
writel(0, engine->regs + SPA_AAD_LEN_REG_OFFSET);
ctrl = spacc_alg->ctrl_default | (req->ctx_id << SPA_CTRL_CTX_IDX) |
(req->is_encrypt ? (1 << SPA_CTRL_ENCRYPT_IDX) :
(1 << SPA_CTRL_KEY_EXP));
mod_timer(&engine->packet_timeout, jiffies + PACKET_TIMEOUT);
writel(ctrl, engine->regs + SPA_CTRL_REG_OFFSET);
return -EINPROGRESS;
}
static int spacc_ablk_do_fallback(struct ablkcipher_request *req,
unsigned alg_type, bool is_encrypt)
{
struct crypto_tfm *old_tfm =
crypto_ablkcipher_tfm(crypto_ablkcipher_reqtfm(req));
struct spacc_ablk_ctx *ctx = crypto_tfm_ctx(old_tfm);
int err;
if (!ctx->sw_cipher)
return -EINVAL;
ablkcipher_request_set_tfm(req, ctx->sw_cipher);
err = is_encrypt ? crypto_ablkcipher_encrypt(req) :
crypto_ablkcipher_decrypt(req);
ablkcipher_request_set_tfm(req, __crypto_ablkcipher_cast(old_tfm));
return err;
}
static int spacc_ablk_setup(struct ablkcipher_request *req, unsigned alg_type,
bool is_encrypt)
{
struct crypto_alg *alg = req->base.tfm->__crt_alg;
struct spacc_engine *engine = to_spacc_alg(alg)->engine;
struct spacc_req *dev_req = ablkcipher_request_ctx(req);
unsigned long flags;
int err = -ENOMEM;
dev_req->req = &req->base;
dev_req->is_encrypt = is_encrypt;
dev_req->engine = engine;
dev_req->complete = spacc_ablk_complete;
dev_req->result = -EINPROGRESS;
if (unlikely(spacc_ablk_need_fallback(dev_req)))
return spacc_ablk_do_fallback(req, alg_type, is_encrypt);
if (req->src != req->dst) {
dev_req->src_ddt = spacc_sg_to_ddt(engine, req->src,
req->nbytes, DMA_TO_DEVICE, &dev_req->src_addr);
if (!dev_req->src_ddt)
goto out;
dev_req->dst_ddt = spacc_sg_to_ddt(engine, req->dst,
req->nbytes, DMA_FROM_DEVICE, &dev_req->dst_addr);
if (!dev_req->dst_ddt)
goto out_free_src;
} else {
dev_req->dst_ddt = spacc_sg_to_ddt(engine, req->dst,
req->nbytes, DMA_BIDIRECTIONAL, &dev_req->dst_addr);
if (!dev_req->dst_ddt)
goto out;
dev_req->src_ddt = NULL;
dev_req->src_addr = dev_req->dst_addr;
}
err = -EINPROGRESS;
spin_lock_irqsave(&engine->hw_lock, flags);
if (unlikely(spacc_fifo_cmd_full(engine)) ||
engine->in_flight + 1 > engine->fifo_sz) {
if (!(req->base.flags & CRYPTO_TFM_REQ_MAY_BACKLOG)) {
err = -EBUSY;
spin_unlock_irqrestore(&engine->hw_lock, flags);
goto out_free_ddts;
}
list_add_tail(&dev_req->list, &engine->pending);
} else {
list_add_tail(&dev_req->list, &engine->pending);
spacc_push(engine);
}
spin_unlock_irqrestore(&engine->hw_lock, flags);
goto out;
out_free_ddts:
spacc_free_ddt(dev_req, dev_req->dst_ddt, dev_req->dst_addr, req->dst,
req->nbytes, req->src == req->dst ?
DMA_BIDIRECTIONAL : DMA_FROM_DEVICE);
out_free_src:
if (req->src != req->dst)
spacc_free_ddt(dev_req, dev_req->src_ddt, dev_req->src_addr,
req->src, req->nbytes, DMA_TO_DEVICE);
out:
return err;
}
static int spacc_ablk_cra_init(struct crypto_tfm *tfm)
{
struct spacc_ablk_ctx *ctx = crypto_tfm_ctx(tfm);
struct crypto_alg *alg = tfm->__crt_alg;
struct spacc_alg *spacc_alg = to_spacc_alg(alg);
struct spacc_engine *engine = spacc_alg->engine;
ctx->generic.flags = spacc_alg->type;
ctx->generic.engine = engine;
if (alg->cra_flags & CRYPTO_ALG_NEED_FALLBACK) {
ctx->sw_cipher = crypto_alloc_ablkcipher(alg->cra_name, 0,
CRYPTO_ALG_ASYNC | CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(ctx->sw_cipher)) {
dev_warn(engine->dev, "failed to allocate fallback for %s\n",
alg->cra_name);
ctx->sw_cipher = NULL;
}
}
ctx->generic.key_offs = spacc_alg->key_offs;
ctx->generic.iv_offs = spacc_alg->iv_offs;
tfm->crt_ablkcipher.reqsize = sizeof(struct spacc_req);
return 0;
}
static void spacc_ablk_cra_exit(struct crypto_tfm *tfm)
{
struct spacc_ablk_ctx *ctx = crypto_tfm_ctx(tfm);
if (ctx->sw_cipher)
crypto_free_ablkcipher(ctx->sw_cipher);
ctx->sw_cipher = NULL;
}
static int spacc_ablk_encrypt(struct ablkcipher_request *req)
{
struct crypto_ablkcipher *cipher = crypto_ablkcipher_reqtfm(req);
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(cipher);
struct spacc_alg *alg = to_spacc_alg(tfm->__crt_alg);
return spacc_ablk_setup(req, alg->type, 1);
}
static int spacc_ablk_decrypt(struct ablkcipher_request *req)
{
struct crypto_ablkcipher *cipher = crypto_ablkcipher_reqtfm(req);
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(cipher);
struct spacc_alg *alg = to_spacc_alg(tfm->__crt_alg);
return spacc_ablk_setup(req, alg->type, 0);
}
static inline int spacc_fifo_stat_empty(struct spacc_engine *engine)
{
return readl(engine->regs + SPA_FIFO_STAT_REG_OFFSET) &
SPA_FIFO_STAT_EMPTY;
}
static void spacc_process_done(struct spacc_engine *engine)
{
struct spacc_req *req;
unsigned long flags;
spin_lock_irqsave(&engine->hw_lock, flags);
while (!spacc_fifo_stat_empty(engine)) {
req = list_first_entry(&engine->in_progress, struct spacc_req,
list);
list_move_tail(&req->list, &engine->completed);
--engine->in_flight;
writel(~0, engine->regs + SPA_STAT_POP_REG_OFFSET);
req->result = (readl(engine->regs + SPA_STATUS_REG_OFFSET) &
SPA_STATUS_RES_CODE_MASK) >> SPA_STATUS_RES_CODE_OFFSET;
if (unlikely(req->result)) {
switch (req->result) {
case SPA_STATUS_ICV_FAIL:
req->result = -EBADMSG;
break;
case SPA_STATUS_MEMORY_ERROR:
dev_warn(engine->dev,
"memory error triggered\n");
req->result = -EFAULT;
break;
case SPA_STATUS_BLOCK_ERROR:
dev_warn(engine->dev,
"block error triggered\n");
req->result = -EIO;
break;
}
}
}
tasklet_schedule(&engine->complete);
spin_unlock_irqrestore(&engine->hw_lock, flags);
}
static irqreturn_t spacc_spacc_irq(int irq, void *dev)
{
struct spacc_engine *engine = (struct spacc_engine *)dev;
u32 spacc_irq_stat = readl(engine->regs + SPA_IRQ_STAT_REG_OFFSET);
writel(spacc_irq_stat, engine->regs + SPA_IRQ_STAT_REG_OFFSET);
spacc_process_done(engine);
return IRQ_HANDLED;
}
static void spacc_packet_timeout(unsigned long data)
{
struct spacc_engine *engine = (struct spacc_engine *)data;
spacc_process_done(engine);
}
static int spacc_req_submit(struct spacc_req *req)
{
struct crypto_alg *alg = req->req->tfm->__crt_alg;
if (CRYPTO_ALG_TYPE_AEAD == (CRYPTO_ALG_TYPE_MASK & alg->cra_flags))
return spacc_aead_submit(req);
else
return spacc_ablk_submit(req);
}
static void spacc_spacc_complete(unsigned long data)
{
struct spacc_engine *engine = (struct spacc_engine *)data;
struct spacc_req *req, *tmp;
unsigned long flags;
LIST_HEAD(completed);
spin_lock_irqsave(&engine->hw_lock, flags);
list_splice_init(&engine->completed, &completed);
spacc_push(engine);
if (engine->in_flight)
mod_timer(&engine->packet_timeout, jiffies + PACKET_TIMEOUT);
spin_unlock_irqrestore(&engine->hw_lock, flags);
list_for_each_entry_safe(req, tmp, &completed, list) {
list_del(&req->list);
req->complete(req);
}
}
static int spacc_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct spacc_engine *engine = platform_get_drvdata(pdev);
clk_disable(engine->clk);
return 0;
}
static int spacc_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct spacc_engine *engine = platform_get_drvdata(pdev);
return clk_enable(engine->clk);
}
static inline struct spacc_engine *spacc_dev_to_engine(struct device *dev)
{
return dev ? platform_get_drvdata(to_platform_device(dev)) : NULL;
}
static ssize_t spacc_stat_irq_thresh_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct spacc_engine *engine = spacc_dev_to_engine(dev);
return snprintf(buf, PAGE_SIZE, "%u\n", engine->stat_irq_thresh);
}
static ssize_t spacc_stat_irq_thresh_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct spacc_engine *engine = spacc_dev_to_engine(dev);
unsigned long thresh;
if (kstrtoul(buf, 0, &thresh))
return -EINVAL;
thresh = clamp(thresh, 1UL, engine->fifo_sz - 1);
engine->stat_irq_thresh = thresh;
writel(engine->stat_irq_thresh << SPA_IRQ_CTRL_STAT_CNT_OFFSET,
engine->regs + SPA_IRQ_CTRL_REG_OFFSET);
return len;
}
static bool spacc_is_compatible(struct platform_device *pdev,
const char *spacc_type)
{
const struct platform_device_id *platid = platform_get_device_id(pdev);
if (platid && !strcmp(platid->name, spacc_type))
return true;
#ifdef CONFIG_OF
if (of_device_is_compatible(pdev->dev.of_node, spacc_type))
return true;
#endif
return false;
}
static int spacc_probe(struct platform_device *pdev)
{
int i, err, ret = -EINVAL;
struct resource *mem, *irq;
struct spacc_engine *engine = devm_kzalloc(&pdev->dev, sizeof(*engine),
GFP_KERNEL);
if (!engine)
return -ENOMEM;
if (spacc_is_compatible(pdev, "picochip,spacc-ipsec")) {
engine->max_ctxs = SPACC_CRYPTO_IPSEC_MAX_CTXS;
engine->cipher_pg_sz = SPACC_CRYPTO_IPSEC_CIPHER_PG_SZ;
engine->hash_pg_sz = SPACC_CRYPTO_IPSEC_HASH_PG_SZ;
engine->fifo_sz = SPACC_CRYPTO_IPSEC_FIFO_SZ;
engine->algs = ipsec_engine_algs;
engine->num_algs = ARRAY_SIZE(ipsec_engine_algs);
engine->aeads = ipsec_engine_aeads;
engine->num_aeads = ARRAY_SIZE(ipsec_engine_aeads);
} else if (spacc_is_compatible(pdev, "picochip,spacc-l2")) {
engine->max_ctxs = SPACC_CRYPTO_L2_MAX_CTXS;
engine->cipher_pg_sz = SPACC_CRYPTO_L2_CIPHER_PG_SZ;
engine->hash_pg_sz = SPACC_CRYPTO_L2_HASH_PG_SZ;
engine->fifo_sz = SPACC_CRYPTO_L2_FIFO_SZ;
engine->algs = l2_engine_algs;
engine->num_algs = ARRAY_SIZE(l2_engine_algs);
} else {
return -EINVAL;
}
engine->name = dev_name(&pdev->dev);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
engine->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(engine->regs))
return PTR_ERR(engine->regs);
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq) {
dev_err(&pdev->dev, "no memory/irq resource for engine\n");
return -ENXIO;
}
if (devm_request_irq(&pdev->dev, irq->start, spacc_spacc_irq, 0,
engine->name, engine)) {
dev_err(engine->dev, "failed to request IRQ\n");
return -EBUSY;
}
engine->dev = &pdev->dev;
engine->cipher_ctx_base = engine->regs + SPA_CIPH_KEY_BASE_REG_OFFSET;
engine->hash_key_base = engine->regs + SPA_HASH_KEY_BASE_REG_OFFSET;
engine->req_pool = dmam_pool_create(engine->name, engine->dev,
MAX_DDT_LEN * sizeof(struct spacc_ddt), 8, SZ_64K);
if (!engine->req_pool)
return -ENOMEM;
spin_lock_init(&engine->hw_lock);
engine->clk = clk_get(&pdev->dev, "ref");
if (IS_ERR(engine->clk)) {
dev_info(&pdev->dev, "clk unavailable\n");
device_remove_file(&pdev->dev, &dev_attr_stat_irq_thresh);
return PTR_ERR(engine->clk);
}
if (clk_prepare_enable(engine->clk)) {
dev_info(&pdev->dev, "unable to prepare/enable clk\n");
clk_put(engine->clk);
return -EIO;
}
err = device_create_file(&pdev->dev, &dev_attr_stat_irq_thresh);
if (err) {
clk_disable_unprepare(engine->clk);
clk_put(engine->clk);
return err;
}
engine->stat_irq_thresh = (engine->fifo_sz / 2);
writel(engine->stat_irq_thresh << SPA_IRQ_CTRL_STAT_CNT_OFFSET,
engine->regs + SPA_IRQ_CTRL_REG_OFFSET);
writel(SPA_IRQ_EN_STAT_EN | SPA_IRQ_EN_GLBL_EN,
engine->regs + SPA_IRQ_EN_REG_OFFSET);
setup_timer(&engine->packet_timeout, spacc_packet_timeout,
(unsigned long)engine);
INIT_LIST_HEAD(&engine->pending);
INIT_LIST_HEAD(&engine->completed);
INIT_LIST_HEAD(&engine->in_progress);
engine->in_flight = 0;
tasklet_init(&engine->complete, spacc_spacc_complete,
(unsigned long)engine);
platform_set_drvdata(pdev, engine);
INIT_LIST_HEAD(&engine->registered_algs);
for (i = 0; i < engine->num_algs; ++i) {
engine->algs[i].engine = engine;
err = crypto_register_alg(&engine->algs[i].alg);
if (!err) {
list_add_tail(&engine->algs[i].entry,
&engine->registered_algs);
ret = 0;
}
if (err)
dev_err(engine->dev, "failed to register alg \"%s\"\n",
engine->algs[i].alg.cra_name);
else
dev_dbg(engine->dev, "registered alg \"%s\"\n",
engine->algs[i].alg.cra_name);
}
INIT_LIST_HEAD(&engine->registered_aeads);
for (i = 0; i < engine->num_aeads; ++i) {
engine->aeads[i].engine = engine;
err = crypto_register_aead(&engine->aeads[i].alg);
if (!err) {
list_add_tail(&engine->aeads[i].entry,
&engine->registered_aeads);
ret = 0;
}
if (err)
dev_err(engine->dev, "failed to register alg \"%s\"\n",
engine->aeads[i].alg.base.cra_name);
else
dev_dbg(engine->dev, "registered alg \"%s\"\n",
engine->aeads[i].alg.base.cra_name);
}
return ret;
}
static int spacc_remove(struct platform_device *pdev)
{
struct spacc_aead *aead, *an;
struct spacc_alg *alg, *next;
struct spacc_engine *engine = platform_get_drvdata(pdev);
del_timer_sync(&engine->packet_timeout);
device_remove_file(&pdev->dev, &dev_attr_stat_irq_thresh);
list_for_each_entry_safe(aead, an, &engine->registered_aeads, entry) {
list_del(&aead->entry);
crypto_unregister_aead(&aead->alg);
}
list_for_each_entry_safe(alg, next, &engine->registered_algs, entry) {
list_del(&alg->entry);
crypto_unregister_alg(&alg->alg);
}
clk_disable_unprepare(engine->clk);
clk_put(engine->clk);
return 0;
}
