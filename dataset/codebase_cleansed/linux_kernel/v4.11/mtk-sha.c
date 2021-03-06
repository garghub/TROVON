static inline u32 mtk_sha_read(struct mtk_cryp *cryp, u32 offset)
{
return readl_relaxed(cryp->base + offset);
}
static inline void mtk_sha_write(struct mtk_cryp *cryp,
u32 offset, u32 value)
{
writel_relaxed(value, cryp->base + offset);
}
static struct mtk_cryp *mtk_sha_find_dev(struct mtk_sha_ctx *tctx)
{
struct mtk_cryp *cryp = NULL;
struct mtk_cryp *tmp;
spin_lock_bh(&mtk_sha.lock);
if (!tctx->cryp) {
list_for_each_entry(tmp, &mtk_sha.dev_list, sha_list) {
cryp = tmp;
break;
}
tctx->cryp = cryp;
} else {
cryp = tctx->cryp;
}
tctx->id = cryp->rec;
cryp->rec = !cryp->rec;
spin_unlock_bh(&mtk_sha.lock);
return cryp;
}
static int mtk_sha_append_sg(struct mtk_sha_reqctx *ctx)
{
size_t count;
while ((ctx->bufcnt < SHA_BUF_SIZE) && ctx->total) {
count = min(ctx->sg->length - ctx->offset, ctx->total);
count = min(count, SHA_BUF_SIZE - ctx->bufcnt);
if (count <= 0) {
if ((ctx->sg->length == 0) && !sg_is_last(ctx->sg)) {
ctx->sg = sg_next(ctx->sg);
continue;
} else {
break;
}
}
scatterwalk_map_and_copy(ctx->buffer + ctx->bufcnt, ctx->sg,
ctx->offset, count, 0);
ctx->bufcnt += count;
ctx->offset += count;
ctx->total -= count;
if (ctx->offset == ctx->sg->length) {
ctx->sg = sg_next(ctx->sg);
if (ctx->sg)
ctx->offset = 0;
else
ctx->total = 0;
}
}
return 0;
}
static void mtk_sha_fill_padding(struct mtk_sha_reqctx *ctx, u32 len)
{
u32 index, padlen;
u64 bits[2];
u64 size = ctx->digcnt;
size += ctx->bufcnt;
size += len;
bits[1] = cpu_to_be64(size << 3);
bits[0] = cpu_to_be64(size >> 61);
if (ctx->flags & (SHA_FLAGS_SHA384 | SHA_FLAGS_SHA512)) {
index = ctx->bufcnt & 0x7f;
padlen = (index < 112) ? (112 - index) : ((128 + 112) - index);
*(ctx->buffer + ctx->bufcnt) = 0x80;
memset(ctx->buffer + ctx->bufcnt + 1, 0, padlen - 1);
memcpy(ctx->buffer + ctx->bufcnt + padlen, bits, 16);
ctx->bufcnt += padlen + 16;
ctx->flags |= SHA_FLAGS_PAD;
} else {
index = ctx->bufcnt & 0x3f;
padlen = (index < 56) ? (56 - index) : ((64 + 56) - index);
*(ctx->buffer + ctx->bufcnt) = 0x80;
memset(ctx->buffer + ctx->bufcnt + 1, 0, padlen - 1);
memcpy(ctx->buffer + ctx->bufcnt + padlen, &bits[1], 8);
ctx->bufcnt += padlen + 8;
ctx->flags |= SHA_FLAGS_PAD;
}
}
static void mtk_sha_info_init(struct mtk_sha_reqctx *ctx)
{
struct mtk_sha_ct *ct = &ctx->info.ct;
struct mtk_sha_tfm *tfm = &ctx->info.tfm;
ctx->ct_hdr = SHA_CT_CTRL_HDR;
ctx->ct_size = SHA_CT_SIZE;
tfm->ctrl[0] = SHA_TFM_HASH | SHA_TFM_INNER_DIG |
SHA_TFM_SIZE(SIZE_IN_WORDS(ctx->ds));
switch (ctx->flags & SHA_FLAGS_ALGO_MSK) {
case SHA_FLAGS_SHA1:
tfm->ctrl[0] |= SHA_TFM_SHA1;
break;
case SHA_FLAGS_SHA224:
tfm->ctrl[0] |= SHA_TFM_SHA224;
break;
case SHA_FLAGS_SHA256:
tfm->ctrl[0] |= SHA_TFM_SHA256;
break;
case SHA_FLAGS_SHA384:
tfm->ctrl[0] |= SHA_TFM_SHA384;
break;
case SHA_FLAGS_SHA512:
tfm->ctrl[0] |= SHA_TFM_SHA512;
break;
default:
return;
}
tfm->ctrl[1] = SHA_TFM_HASH_STORE;
ct->ctrl[0] = tfm->ctrl[0] | SHA_TFM_CONTINUE | SHA_TFM_START;
ct->ctrl[1] = tfm->ctrl[1];
ct->cmd[0] = SHA_CMD0;
ct->cmd[1] = SHA_CMD1;
ct->cmd[2] = SHA_CMD2 | SHA_TFM_DIGEST(SIZE_IN_WORDS(ctx->ds));
}
static int mtk_sha_info_update(struct mtk_cryp *cryp,
struct mtk_sha_rec *sha,
size_t len)
{
struct mtk_sha_reqctx *ctx = ahash_request_ctx(sha->req);
struct mtk_sha_info *info = &ctx->info;
struct mtk_sha_ct *ct = &info->ct;
if (ctx->start)
ctx->start = false;
else
ct->ctrl[0] &= ~SHA_TFM_START;
ctx->ct_hdr &= ~SHA_DATA_LEN_MSK;
ctx->ct_hdr |= cpu_to_le32(len);
ct->cmd[0] &= ~SHA_DATA_LEN_MSK;
ct->cmd[0] |= cpu_to_le32(len);
ctx->digcnt += len;
ctx->ct_dma = dma_map_single(cryp->dev, info, sizeof(*info),
DMA_BIDIRECTIONAL);
if (unlikely(dma_mapping_error(cryp->dev, ctx->ct_dma))) {
dev_err(cryp->dev, "dma %zu bytes error\n", sizeof(*info));
return -EINVAL;
}
ctx->tfm_dma = ctx->ct_dma + sizeof(*ct);
return 0;
}
static int mtk_sha_finish_hmac(struct ahash_request *req)
{
struct mtk_sha_ctx *tctx = crypto_tfm_ctx(req->base.tfm);
struct mtk_sha_hmac_ctx *bctx = tctx->base;
struct mtk_sha_reqctx *ctx = ahash_request_ctx(req);
SHASH_DESC_ON_STACK(shash, bctx->shash);
shash->tfm = bctx->shash;
shash->flags = 0;
return crypto_shash_init(shash) ?:
crypto_shash_update(shash, bctx->opad, ctx->bs) ?:
crypto_shash_finup(shash, req->result, ctx->ds, req->result);
}
static int mtk_sha_init(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct mtk_sha_ctx *tctx = crypto_ahash_ctx(tfm);
struct mtk_sha_reqctx *ctx = ahash_request_ctx(req);
ctx->flags = 0;
ctx->ds = crypto_ahash_digestsize(tfm);
switch (ctx->ds) {
case SHA1_DIGEST_SIZE:
ctx->flags |= SHA_FLAGS_SHA1;
ctx->bs = SHA1_BLOCK_SIZE;
break;
case SHA224_DIGEST_SIZE:
ctx->flags |= SHA_FLAGS_SHA224;
ctx->bs = SHA224_BLOCK_SIZE;
break;
case SHA256_DIGEST_SIZE:
ctx->flags |= SHA_FLAGS_SHA256;
ctx->bs = SHA256_BLOCK_SIZE;
break;
case SHA384_DIGEST_SIZE:
ctx->flags |= SHA_FLAGS_SHA384;
ctx->bs = SHA384_BLOCK_SIZE;
break;
case SHA512_DIGEST_SIZE:
ctx->flags |= SHA_FLAGS_SHA512;
ctx->bs = SHA512_BLOCK_SIZE;
break;
default:
return -EINVAL;
}
ctx->bufcnt = 0;
ctx->digcnt = 0;
ctx->buffer = tctx->buf;
ctx->start = true;
if (tctx->flags & SHA_FLAGS_HMAC) {
struct mtk_sha_hmac_ctx *bctx = tctx->base;
memcpy(ctx->buffer, bctx->ipad, ctx->bs);
ctx->bufcnt = ctx->bs;
ctx->flags |= SHA_FLAGS_HMAC;
}
return 0;
}
static int mtk_sha_xmit(struct mtk_cryp *cryp, struct mtk_sha_rec *sha,
dma_addr_t addr, size_t len)
{
struct mtk_sha_reqctx *ctx = ahash_request_ctx(sha->req);
struct mtk_ring *ring = cryp->ring[sha->id];
struct mtk_desc *cmd = ring->cmd_base + ring->cmd_pos;
struct mtk_desc *res = ring->res_base + ring->res_pos;
int err;
err = mtk_sha_info_update(cryp, sha, len);
if (err)
return err;
res->hdr = MTK_DESC_FIRST | MTK_DESC_LAST | MTK_DESC_BUF_LEN(len);
res->buf = cpu_to_le32(cryp->tmp_dma);
cmd->hdr = MTK_DESC_FIRST | MTK_DESC_LAST | MTK_DESC_BUF_LEN(len) |
MTK_DESC_CT_LEN(ctx->ct_size);
cmd->buf = cpu_to_le32(addr);
cmd->ct = cpu_to_le32(ctx->ct_dma);
cmd->ct_hdr = ctx->ct_hdr;
cmd->tfm = cpu_to_le32(ctx->tfm_dma);
if (++ring->cmd_pos == MTK_DESC_NUM)
ring->cmd_pos = 0;
ring->res_pos = ring->cmd_pos;
wmb();
mtk_sha_write(cryp, RDR_PREP_COUNT(sha->id), MTK_DESC_CNT(1));
mtk_sha_write(cryp, CDR_PREP_COUNT(sha->id), MTK_DESC_CNT(1));
return -EINPROGRESS;
}
static int mtk_sha_xmit2(struct mtk_cryp *cryp,
struct mtk_sha_rec *sha,
struct mtk_sha_reqctx *ctx,
size_t len1, size_t len2)
{
struct mtk_ring *ring = cryp->ring[sha->id];
struct mtk_desc *cmd = ring->cmd_base + ring->cmd_pos;
struct mtk_desc *res = ring->res_base + ring->res_pos;
int err;
err = mtk_sha_info_update(cryp, sha, len1 + len2);
if (err)
return err;
res->hdr = MTK_DESC_BUF_LEN(len1) | MTK_DESC_FIRST;
res->buf = cpu_to_le32(cryp->tmp_dma);
cmd->hdr = MTK_DESC_BUF_LEN(len1) | MTK_DESC_FIRST |
MTK_DESC_CT_LEN(ctx->ct_size);
cmd->buf = cpu_to_le32(sg_dma_address(ctx->sg));
cmd->ct = cpu_to_le32(ctx->ct_dma);
cmd->ct_hdr = ctx->ct_hdr;
cmd->tfm = cpu_to_le32(ctx->tfm_dma);
if (++ring->cmd_pos == MTK_DESC_NUM)
ring->cmd_pos = 0;
ring->res_pos = ring->cmd_pos;
cmd = ring->cmd_base + ring->cmd_pos;
res = ring->res_base + ring->res_pos;
res->hdr = MTK_DESC_BUF_LEN(len2) | MTK_DESC_LAST;
res->buf = cpu_to_le32(cryp->tmp_dma);
cmd->hdr = MTK_DESC_BUF_LEN(len2) | MTK_DESC_LAST;
cmd->buf = cpu_to_le32(ctx->dma_addr);
if (++ring->cmd_pos == MTK_DESC_NUM)
ring->cmd_pos = 0;
ring->res_pos = ring->cmd_pos;
wmb();
mtk_sha_write(cryp, RDR_PREP_COUNT(sha->id), MTK_DESC_CNT(2));
mtk_sha_write(cryp, CDR_PREP_COUNT(sha->id), MTK_DESC_CNT(2));
return -EINPROGRESS;
}
static int mtk_sha_dma_map(struct mtk_cryp *cryp,
struct mtk_sha_rec *sha,
struct mtk_sha_reqctx *ctx,
size_t count)
{
ctx->dma_addr = dma_map_single(cryp->dev, ctx->buffer,
SHA_BUF_SIZE, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(cryp->dev, ctx->dma_addr))) {
dev_err(cryp->dev, "dma map error\n");
return -EINVAL;
}
ctx->flags &= ~SHA_FLAGS_SG;
return mtk_sha_xmit(cryp, sha, ctx->dma_addr, count);
}
static int mtk_sha_update_slow(struct mtk_cryp *cryp,
struct mtk_sha_rec *sha)
{
struct mtk_sha_reqctx *ctx = ahash_request_ctx(sha->req);
size_t count;
u32 final;
mtk_sha_append_sg(ctx);
final = (ctx->flags & SHA_FLAGS_FINUP) && !ctx->total;
dev_dbg(cryp->dev, "slow: bufcnt: %zu\n", ctx->bufcnt);
if (final) {
sha->flags |= SHA_FLAGS_FINAL;
mtk_sha_fill_padding(ctx, 0);
}
if (final || (ctx->bufcnt == SHA_BUF_SIZE && ctx->total)) {
count = ctx->bufcnt;
ctx->bufcnt = 0;
return mtk_sha_dma_map(cryp, sha, ctx, count);
}
return 0;
}
static int mtk_sha_update_start(struct mtk_cryp *cryp,
struct mtk_sha_rec *sha)
{
struct mtk_sha_reqctx *ctx = ahash_request_ctx(sha->req);
u32 len, final, tail;
struct scatterlist *sg;
if (!ctx->total)
return 0;
if (ctx->bufcnt || ctx->offset)
return mtk_sha_update_slow(cryp, sha);
sg = ctx->sg;
if (!IS_ALIGNED(sg->offset, sizeof(u32)))
return mtk_sha_update_slow(cryp, sha);
if (!sg_is_last(sg) && !IS_ALIGNED(sg->length, ctx->bs))
return mtk_sha_update_slow(cryp, sha);
len = min(ctx->total, sg->length);
if (sg_is_last(sg)) {
if (!(ctx->flags & SHA_FLAGS_FINUP)) {
tail = len & (ctx->bs - 1);
len -= tail;
}
}
ctx->total -= len;
ctx->offset = len;
final = (ctx->flags & SHA_FLAGS_FINUP) && !ctx->total;
if (final) {
size_t count;
tail = len & (ctx->bs - 1);
len -= tail;
ctx->total += tail;
ctx->offset = len;
sg = ctx->sg;
mtk_sha_append_sg(ctx);
mtk_sha_fill_padding(ctx, len);
ctx->dma_addr = dma_map_single(cryp->dev, ctx->buffer,
SHA_BUF_SIZE, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(cryp->dev, ctx->dma_addr))) {
dev_err(cryp->dev, "dma map bytes error\n");
return -EINVAL;
}
sha->flags |= SHA_FLAGS_FINAL;
count = ctx->bufcnt;
ctx->bufcnt = 0;
if (len == 0) {
ctx->flags &= ~SHA_FLAGS_SG;
return mtk_sha_xmit(cryp, sha, ctx->dma_addr, count);
} else {
ctx->sg = sg;
if (!dma_map_sg(cryp->dev, ctx->sg, 1, DMA_TO_DEVICE)) {
dev_err(cryp->dev, "dma_map_sg error\n");
return -EINVAL;
}
ctx->flags |= SHA_FLAGS_SG;
return mtk_sha_xmit2(cryp, sha, ctx, len, count);
}
}
if (!dma_map_sg(cryp->dev, ctx->sg, 1, DMA_TO_DEVICE)) {
dev_err(cryp->dev, "dma_map_sg error\n");
return -EINVAL;
}
ctx->flags |= SHA_FLAGS_SG;
return mtk_sha_xmit(cryp, sha, sg_dma_address(ctx->sg), len);
}
static int mtk_sha_final_req(struct mtk_cryp *cryp,
struct mtk_sha_rec *sha)
{
struct mtk_sha_reqctx *ctx = ahash_request_ctx(sha->req);
size_t count;
mtk_sha_fill_padding(ctx, 0);
sha->flags |= SHA_FLAGS_FINAL;
count = ctx->bufcnt;
ctx->bufcnt = 0;
return mtk_sha_dma_map(cryp, sha, ctx, count);
}
static int mtk_sha_finish(struct ahash_request *req)
{
struct mtk_sha_reqctx *ctx = ahash_request_ctx(req);
u32 *digest = ctx->info.tfm.digest;
u32 *result = (u32 *)req->result;
int i;
for (i = 0; i < SIZE_IN_WORDS(ctx->ds); i++)
result[i] = le32_to_cpu(digest[i]);
if (ctx->flags & SHA_FLAGS_HMAC)
return mtk_sha_finish_hmac(req);
return 0;
}
static void mtk_sha_finish_req(struct mtk_cryp *cryp,
struct mtk_sha_rec *sha,
int err)
{
if (likely(!err && (SHA_FLAGS_FINAL & sha->flags)))
err = mtk_sha_finish(sha->req);
sha->flags &= ~(SHA_FLAGS_BUSY | SHA_FLAGS_FINAL);
sha->req->base.complete(&sha->req->base, err);
mtk_sha_handle_queue(cryp, sha->id - RING2, NULL);
}
static int mtk_sha_handle_queue(struct mtk_cryp *cryp, u8 id,
struct ahash_request *req)
{
struct mtk_sha_rec *sha = cryp->sha[id];
struct crypto_async_request *async_req, *backlog;
struct mtk_sha_reqctx *ctx;
unsigned long flags;
int err = 0, ret = 0;
spin_lock_irqsave(&sha->lock, flags);
if (req)
ret = ahash_enqueue_request(&sha->queue, req);
if (SHA_FLAGS_BUSY & sha->flags) {
spin_unlock_irqrestore(&sha->lock, flags);
return ret;
}
backlog = crypto_get_backlog(&sha->queue);
async_req = crypto_dequeue_request(&sha->queue);
if (async_req)
sha->flags |= SHA_FLAGS_BUSY;
spin_unlock_irqrestore(&sha->lock, flags);
if (!async_req)
return ret;
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
req = ahash_request_cast(async_req);
ctx = ahash_request_ctx(req);
sha->req = req;
mtk_sha_info_init(ctx);
if (ctx->op == SHA_OP_UPDATE) {
err = mtk_sha_update_start(cryp, sha);
if (err != -EINPROGRESS && (ctx->flags & SHA_FLAGS_FINUP))
err = mtk_sha_final_req(cryp, sha);
} else if (ctx->op == SHA_OP_FINAL) {
err = mtk_sha_final_req(cryp, sha);
}
if (unlikely(err != -EINPROGRESS))
mtk_sha_finish_req(cryp, sha, err);
return ret;
}
static int mtk_sha_enqueue(struct ahash_request *req, u32 op)
{
struct mtk_sha_reqctx *ctx = ahash_request_ctx(req);
struct mtk_sha_ctx *tctx = crypto_tfm_ctx(req->base.tfm);
ctx->op = op;
return mtk_sha_handle_queue(tctx->cryp, tctx->id, req);
}
static void mtk_sha_unmap(struct mtk_cryp *cryp, struct mtk_sha_rec *sha)
{
struct mtk_sha_reqctx *ctx = ahash_request_ctx(sha->req);
dma_unmap_single(cryp->dev, ctx->ct_dma, sizeof(ctx->info),
DMA_BIDIRECTIONAL);
if (ctx->flags & SHA_FLAGS_SG) {
dma_unmap_sg(cryp->dev, ctx->sg, 1, DMA_TO_DEVICE);
if (ctx->sg->length == ctx->offset) {
ctx->sg = sg_next(ctx->sg);
if (ctx->sg)
ctx->offset = 0;
}
if (ctx->flags & SHA_FLAGS_PAD) {
dma_unmap_single(cryp->dev, ctx->dma_addr,
SHA_BUF_SIZE, DMA_TO_DEVICE);
}
} else
dma_unmap_single(cryp->dev, ctx->dma_addr,
SHA_BUF_SIZE, DMA_TO_DEVICE);
}
static void mtk_sha_complete(struct mtk_cryp *cryp,
struct mtk_sha_rec *sha)
{
int err = 0;
err = mtk_sha_update_start(cryp, sha);
if (err != -EINPROGRESS)
mtk_sha_finish_req(cryp, sha, err);
}
static int mtk_sha_update(struct ahash_request *req)
{
struct mtk_sha_reqctx *ctx = ahash_request_ctx(req);
ctx->total = req->nbytes;
ctx->sg = req->src;
ctx->offset = 0;
if ((ctx->bufcnt + ctx->total < SHA_BUF_SIZE) &&
!(ctx->flags & SHA_FLAGS_FINUP))
return mtk_sha_append_sg(ctx);
return mtk_sha_enqueue(req, SHA_OP_UPDATE);
}
static int mtk_sha_final(struct ahash_request *req)
{
struct mtk_sha_reqctx *ctx = ahash_request_ctx(req);
ctx->flags |= SHA_FLAGS_FINUP;
if (ctx->flags & SHA_FLAGS_PAD)
return mtk_sha_finish(req);
return mtk_sha_enqueue(req, SHA_OP_FINAL);
}
static int mtk_sha_finup(struct ahash_request *req)
{
struct mtk_sha_reqctx *ctx = ahash_request_ctx(req);
int err1, err2;
ctx->flags |= SHA_FLAGS_FINUP;
err1 = mtk_sha_update(req);
if (err1 == -EINPROGRESS || err1 == -EBUSY)
return err1;
err2 = mtk_sha_final(req);
return err1 ?: err2;
}
static int mtk_sha_digest(struct ahash_request *req)
{
return mtk_sha_init(req) ?: mtk_sha_finup(req);
}
static int mtk_sha_setkey(struct crypto_ahash *tfm, const u8 *key,
u32 keylen)
{
struct mtk_sha_ctx *tctx = crypto_ahash_ctx(tfm);
struct mtk_sha_hmac_ctx *bctx = tctx->base;
size_t bs = crypto_shash_blocksize(bctx->shash);
size_t ds = crypto_shash_digestsize(bctx->shash);
int err, i;
SHASH_DESC_ON_STACK(shash, bctx->shash);
shash->tfm = bctx->shash;
shash->flags = crypto_shash_get_flags(bctx->shash) &
CRYPTO_TFM_REQ_MAY_SLEEP;
if (keylen > bs) {
err = crypto_shash_digest(shash, key, keylen, bctx->ipad);
if (err)
return err;
keylen = ds;
} else {
memcpy(bctx->ipad, key, keylen);
}
memset(bctx->ipad + keylen, 0, bs - keylen);
memcpy(bctx->opad, bctx->ipad, bs);
for (i = 0; i < bs; i++) {
bctx->ipad[i] ^= 0x36;
bctx->opad[i] ^= 0x5c;
}
return 0;
}
static int mtk_sha_export(struct ahash_request *req, void *out)
{
const struct mtk_sha_reqctx *ctx = ahash_request_ctx(req);
memcpy(out, ctx, sizeof(*ctx));
return 0;
}
static int mtk_sha_import(struct ahash_request *req, const void *in)
{
struct mtk_sha_reqctx *ctx = ahash_request_ctx(req);
memcpy(ctx, in, sizeof(*ctx));
return 0;
}
static int mtk_sha_cra_init_alg(struct crypto_tfm *tfm,
const char *alg_base)
{
struct mtk_sha_ctx *tctx = crypto_tfm_ctx(tfm);
struct mtk_cryp *cryp = NULL;
cryp = mtk_sha_find_dev(tctx);
if (!cryp)
return -ENODEV;
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct mtk_sha_reqctx));
if (alg_base) {
struct mtk_sha_hmac_ctx *bctx = tctx->base;
tctx->flags |= SHA_FLAGS_HMAC;
bctx->shash = crypto_alloc_shash(alg_base, 0,
CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(bctx->shash)) {
pr_err("base driver %s could not be loaded.\n",
alg_base);
return PTR_ERR(bctx->shash);
}
}
return 0;
}
static int mtk_sha_cra_init(struct crypto_tfm *tfm)
{
return mtk_sha_cra_init_alg(tfm, NULL);
}
static int mtk_sha_cra_sha1_init(struct crypto_tfm *tfm)
{
return mtk_sha_cra_init_alg(tfm, "sha1");
}
static int mtk_sha_cra_sha224_init(struct crypto_tfm *tfm)
{
return mtk_sha_cra_init_alg(tfm, "sha224");
}
static int mtk_sha_cra_sha256_init(struct crypto_tfm *tfm)
{
return mtk_sha_cra_init_alg(tfm, "sha256");
}
static int mtk_sha_cra_sha384_init(struct crypto_tfm *tfm)
{
return mtk_sha_cra_init_alg(tfm, "sha384");
}
static int mtk_sha_cra_sha512_init(struct crypto_tfm *tfm)
{
return mtk_sha_cra_init_alg(tfm, "sha512");
}
static void mtk_sha_cra_exit(struct crypto_tfm *tfm)
{
struct mtk_sha_ctx *tctx = crypto_tfm_ctx(tfm);
if (tctx->flags & SHA_FLAGS_HMAC) {
struct mtk_sha_hmac_ctx *bctx = tctx->base;
crypto_free_shash(bctx->shash);
}
}
static void mtk_sha_task0(unsigned long data)
{
struct mtk_cryp *cryp = (struct mtk_cryp *)data;
struct mtk_sha_rec *sha = cryp->sha[0];
mtk_sha_unmap(cryp, sha);
mtk_sha_complete(cryp, sha);
}
static void mtk_sha_task1(unsigned long data)
{
struct mtk_cryp *cryp = (struct mtk_cryp *)data;
struct mtk_sha_rec *sha = cryp->sha[1];
mtk_sha_unmap(cryp, sha);
mtk_sha_complete(cryp, sha);
}
static irqreturn_t mtk_sha_ring2_irq(int irq, void *dev_id)
{
struct mtk_cryp *cryp = (struct mtk_cryp *)dev_id;
struct mtk_sha_rec *sha = cryp->sha[0];
u32 val = mtk_sha_read(cryp, RDR_STAT(RING2));
mtk_sha_write(cryp, RDR_STAT(RING2), val);
if (likely((SHA_FLAGS_BUSY & sha->flags))) {
mtk_sha_write(cryp, RDR_PROC_COUNT(RING2), MTK_CNT_RST);
mtk_sha_write(cryp, RDR_THRESH(RING2),
MTK_RDR_PROC_THRESH | MTK_RDR_PROC_MODE);
tasklet_schedule(&sha->task);
} else {
dev_warn(cryp->dev, "AES interrupt when no active requests.\n");
}
return IRQ_HANDLED;
}
static irqreturn_t mtk_sha_ring3_irq(int irq, void *dev_id)
{
struct mtk_cryp *cryp = (struct mtk_cryp *)dev_id;
struct mtk_sha_rec *sha = cryp->sha[1];
u32 val = mtk_sha_read(cryp, RDR_STAT(RING3));
mtk_sha_write(cryp, RDR_STAT(RING3), val);
if (likely((SHA_FLAGS_BUSY & sha->flags))) {
mtk_sha_write(cryp, RDR_PROC_COUNT(RING3), MTK_CNT_RST);
mtk_sha_write(cryp, RDR_THRESH(RING3),
MTK_RDR_PROC_THRESH | MTK_RDR_PROC_MODE);
tasklet_schedule(&sha->task);
} else {
dev_warn(cryp->dev, "AES interrupt when no active requests.\n");
}
return IRQ_HANDLED;
}
static int mtk_sha_record_init(struct mtk_cryp *cryp)
{
struct mtk_sha_rec **sha = cryp->sha;
int i, err = -ENOMEM;
for (i = 0; i < MTK_REC_NUM; i++) {
sha[i] = kzalloc(sizeof(**sha), GFP_KERNEL);
if (!sha[i])
goto err_cleanup;
sha[i]->id = i + RING2;
spin_lock_init(&sha[i]->lock);
crypto_init_queue(&sha[i]->queue, SHA_QUEUE_SIZE);
}
tasklet_init(&sha[0]->task, mtk_sha_task0, (unsigned long)cryp);
tasklet_init(&sha[1]->task, mtk_sha_task1, (unsigned long)cryp);
cryp->rec = 1;
return 0;
err_cleanup:
for (; i--; )
kfree(sha[i]);
return err;
}
static void mtk_sha_record_free(struct mtk_cryp *cryp)
{
int i;
for (i = 0; i < MTK_REC_NUM; i++) {
tasklet_kill(&cryp->sha[i]->task);
kfree(cryp->sha[i]);
}
}
static void mtk_sha_unregister_algs(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(algs_sha1_sha224_sha256); i++)
crypto_unregister_ahash(&algs_sha1_sha224_sha256[i]);
for (i = 0; i < ARRAY_SIZE(algs_sha384_sha512); i++)
crypto_unregister_ahash(&algs_sha384_sha512[i]);
}
static int mtk_sha_register_algs(void)
{
int err, i;
for (i = 0; i < ARRAY_SIZE(algs_sha1_sha224_sha256); i++) {
err = crypto_register_ahash(&algs_sha1_sha224_sha256[i]);
if (err)
goto err_sha_224_256_algs;
}
for (i = 0; i < ARRAY_SIZE(algs_sha384_sha512); i++) {
err = crypto_register_ahash(&algs_sha384_sha512[i]);
if (err)
goto err_sha_384_512_algs;
}
return 0;
err_sha_384_512_algs:
for (; i--; )
crypto_unregister_ahash(&algs_sha384_sha512[i]);
i = ARRAY_SIZE(algs_sha1_sha224_sha256);
err_sha_224_256_algs:
for (; i--; )
crypto_unregister_ahash(&algs_sha1_sha224_sha256[i]);
return err;
}
int mtk_hash_alg_register(struct mtk_cryp *cryp)
{
int err;
INIT_LIST_HEAD(&cryp->sha_list);
err = mtk_sha_record_init(cryp);
if (err)
goto err_record;
err = devm_request_irq(cryp->dev, cryp->irq[RING2],
mtk_sha_ring2_irq, IRQF_TRIGGER_LOW,
"mtk-sha", cryp);
if (err) {
dev_err(cryp->dev, "unable to request sha irq0.\n");
goto err_res;
}
err = devm_request_irq(cryp->dev, cryp->irq[RING3],
mtk_sha_ring3_irq, IRQF_TRIGGER_LOW,
"mtk-sha", cryp);
if (err) {
dev_err(cryp->dev, "unable to request sha irq1.\n");
goto err_res;
}
mtk_sha_write(cryp, AIC_ENABLE_SET(RING2), MTK_IRQ_RDR2);
mtk_sha_write(cryp, AIC_ENABLE_SET(RING3), MTK_IRQ_RDR3);
cryp->tmp = dma_alloc_coherent(cryp->dev, SHA_TMP_BUF_SIZE,
&cryp->tmp_dma, GFP_KERNEL);
if (!cryp->tmp) {
dev_err(cryp->dev, "unable to allocate tmp buffer.\n");
err = -EINVAL;
goto err_res;
}
spin_lock(&mtk_sha.lock);
list_add_tail(&cryp->sha_list, &mtk_sha.dev_list);
spin_unlock(&mtk_sha.lock);
err = mtk_sha_register_algs();
if (err)
goto err_algs;
return 0;
err_algs:
spin_lock(&mtk_sha.lock);
list_del(&cryp->sha_list);
spin_unlock(&mtk_sha.lock);
dma_free_coherent(cryp->dev, SHA_TMP_BUF_SIZE,
cryp->tmp, cryp->tmp_dma);
err_res:
mtk_sha_record_free(cryp);
err_record:
dev_err(cryp->dev, "mtk-sha initialization failed.\n");
return err;
}
void mtk_hash_alg_release(struct mtk_cryp *cryp)
{
spin_lock(&mtk_sha.lock);
list_del(&cryp->sha_list);
spin_unlock(&mtk_sha.lock);
mtk_sha_unregister_algs();
dma_free_coherent(cryp->dev, SHA_TMP_BUF_SIZE,
cryp->tmp, cryp->tmp_dma);
mtk_sha_record_free(cryp);
}
