static void artpec6_crypto_walk_init(struct artpec6_crypto_walk *awalk,
struct scatterlist *sg)
{
awalk->sg = sg;
awalk->offset = 0;
}
static size_t artpec6_crypto_walk_advance(struct artpec6_crypto_walk *awalk,
size_t nbytes)
{
while (nbytes && awalk->sg) {
size_t piece;
WARN_ON(awalk->offset > awalk->sg->length);
piece = min(nbytes, (size_t)awalk->sg->length - awalk->offset);
nbytes -= piece;
awalk->offset += piece;
if (awalk->offset == awalk->sg->length) {
awalk->sg = sg_next(awalk->sg);
awalk->offset = 0;
}
}
return nbytes;
}
static size_t
artpec6_crypto_walk_chunklen(const struct artpec6_crypto_walk *awalk)
{
WARN_ON(awalk->sg->length == awalk->offset);
return awalk->sg->length - awalk->offset;
}
static dma_addr_t
artpec6_crypto_walk_chunk_phys(const struct artpec6_crypto_walk *awalk)
{
return sg_phys(awalk->sg) + awalk->offset;
}
static void
artpec6_crypto_copy_bounce_buffers(struct artpec6_crypto_req_common *common)
{
struct artpec6_crypto_dma_descriptors *dma = common->dma;
struct artpec6_crypto_bounce_buffer *b;
struct artpec6_crypto_bounce_buffer *next;
list_for_each_entry_safe(b, next, &dma->bounce_buffers, list) {
pr_debug("bounce entry %p: %zu bytes @ %zu from %p\n",
b, b->length, b->offset, b->buf);
sg_pcopy_from_buffer(b->sg,
1,
b->buf,
b->length,
b->offset);
list_del(&b->list);
kfree(b);
}
}
static inline bool artpec6_crypto_busy(void)
{
struct artpec6_crypto *ac = dev_get_drvdata(artpec6_crypto_dev);
int fifo_count = ac->pending_count;
return fifo_count > 6;
}
static int artpec6_crypto_submit(struct artpec6_crypto_req_common *req)
{
struct artpec6_crypto *ac = dev_get_drvdata(artpec6_crypto_dev);
int ret = -EBUSY;
spin_lock_bh(&ac->queue_lock);
if (!artpec6_crypto_busy()) {
list_add_tail(&req->list, &ac->pending);
artpec6_crypto_start_dma(req);
ret = -EINPROGRESS;
} else if (req->req->flags & CRYPTO_TFM_REQ_MAY_BACKLOG) {
list_add_tail(&req->list, &ac->queue);
} else {
artpec6_crypto_common_destroy(req);
}
spin_unlock_bh(&ac->queue_lock);
return ret;
}
static void artpec6_crypto_start_dma(struct artpec6_crypto_req_common *common)
{
struct artpec6_crypto *ac = dev_get_drvdata(artpec6_crypto_dev);
enum artpec6_crypto_variant variant = ac->variant;
void __iomem *base = ac->base;
struct artpec6_crypto_dma_descriptors *dma = common->dma;
u32 ind, statd, outd;
wmb();
ind = FIELD_PREP(PDMA_IN_DESCRQ_PUSH_LEN, dma->in_cnt - 1) |
FIELD_PREP(PDMA_IN_DESCRQ_PUSH_ADDR, dma->in_dma_addr >> 6);
statd = FIELD_PREP(PDMA_IN_STATQ_PUSH_LEN, dma->in_cnt - 1) |
FIELD_PREP(PDMA_IN_STATQ_PUSH_ADDR, dma->stat_dma_addr >> 6);
outd = FIELD_PREP(PDMA_OUT_DESCRQ_PUSH_LEN, dma->out_cnt - 1) |
FIELD_PREP(PDMA_OUT_DESCRQ_PUSH_ADDR, dma->out_dma_addr >> 6);
if (variant == ARTPEC6_CRYPTO) {
writel_relaxed(ind, base + A6_PDMA_IN_DESCRQ_PUSH);
writel_relaxed(statd, base + A6_PDMA_IN_STATQ_PUSH);
writel_relaxed(PDMA_IN_CMD_START, base + A6_PDMA_IN_CMD);
} else {
writel_relaxed(ind, base + A7_PDMA_IN_DESCRQ_PUSH);
writel_relaxed(statd, base + A7_PDMA_IN_STATQ_PUSH);
writel_relaxed(PDMA_IN_CMD_START, base + A7_PDMA_IN_CMD);
}
writel_relaxed(outd, base + PDMA_OUT_DESCRQ_PUSH);
writel_relaxed(PDMA_OUT_CMD_START, base + PDMA_OUT_CMD);
ac->pending_count++;
}
static void
artpec6_crypto_init_dma_operation(struct artpec6_crypto_req_common *common)
{
struct artpec6_crypto_dma_descriptors *dma = common->dma;
dma->out_cnt = 0;
dma->in_cnt = 0;
dma->map_count = 0;
INIT_LIST_HEAD(&dma->bounce_buffers);
}
static bool fault_inject_dma_descr(void)
{
#ifdef CONFIG_FAULT_INJECTION
return should_fail(&artpec6_crypto_fail_dma_array_full, 1);
#else
return false;
#endif
}
static int
artpec6_crypto_setup_out_descr_phys(struct artpec6_crypto_req_common *common,
dma_addr_t addr, size_t len, bool eop)
{
struct artpec6_crypto_dma_descriptors *dma = common->dma;
struct pdma_descr *d;
if (dma->out_cnt >= PDMA_DESCR_COUNT ||
fault_inject_dma_descr()) {
pr_err("No free OUT DMA descriptors available!\n");
return -ENOSPC;
}
d = &dma->out[dma->out_cnt++];
memset(d, 0, sizeof(*d));
d->ctrl.short_descr = 0;
d->ctrl.eop = eop;
d->data.len = len;
d->data.buf = addr;
return 0;
}
static int
artpec6_crypto_setup_out_descr_short(struct artpec6_crypto_req_common *common,
void *dst, unsigned int len, bool eop)
{
struct artpec6_crypto_dma_descriptors *dma = common->dma;
struct pdma_descr *d;
if (dma->out_cnt >= PDMA_DESCR_COUNT ||
fault_inject_dma_descr()) {
pr_err("No free OUT DMA descriptors available!\n");
return -ENOSPC;
} else if (len > 7 || len < 1) {
return -EINVAL;
}
d = &dma->out[dma->out_cnt++];
memset(d, 0, sizeof(*d));
d->ctrl.short_descr = 1;
d->ctrl.short_len = len;
d->ctrl.eop = eop;
memcpy(d->shrt.data, dst, len);
return 0;
}
static int artpec6_crypto_dma_map_page(struct artpec6_crypto_req_common *common,
struct page *page, size_t offset,
size_t size,
enum dma_data_direction dir,
dma_addr_t *dma_addr_out)
{
struct artpec6_crypto_dma_descriptors *dma = common->dma;
struct device *dev = artpec6_crypto_dev;
struct artpec6_crypto_dma_map *map;
dma_addr_t dma_addr;
*dma_addr_out = 0;
if (dma->map_count >= ARRAY_SIZE(dma->maps))
return -ENOMEM;
dma_addr = dma_map_page(dev, page, offset, size, dir);
if (dma_mapping_error(dev, dma_addr))
return -ENOMEM;
map = &dma->maps[dma->map_count++];
map->size = size;
map->dma_addr = dma_addr;
map->dir = dir;
*dma_addr_out = dma_addr;
return 0;
}
static int
artpec6_crypto_dma_map_single(struct artpec6_crypto_req_common *common,
void *ptr, size_t size,
enum dma_data_direction dir,
dma_addr_t *dma_addr_out)
{
struct page *page = virt_to_page(ptr);
size_t offset = (uintptr_t)ptr & ~PAGE_MASK;
return artpec6_crypto_dma_map_page(common, page, offset, size, dir,
dma_addr_out);
}
static int
artpec6_crypto_dma_map_descs(struct artpec6_crypto_req_common *common)
{
struct artpec6_crypto_dma_descriptors *dma = common->dma;
int ret;
ret = artpec6_crypto_dma_map_single(common, dma->in,
sizeof(dma->in[0]) * dma->in_cnt,
DMA_TO_DEVICE, &dma->in_dma_addr);
if (ret)
return ret;
ret = artpec6_crypto_dma_map_single(common, dma->out,
sizeof(dma->out[0]) * dma->out_cnt,
DMA_TO_DEVICE, &dma->out_dma_addr);
if (ret)
return ret;
dma->stat[dma->in_cnt - 1] = 0;
return artpec6_crypto_dma_map_single(common,
dma->stat + dma->in_cnt - 1,
sizeof(dma->stat[0]),
DMA_BIDIRECTIONAL,
&dma->stat_dma_addr);
}
static void
artpec6_crypto_dma_unmap_all(struct artpec6_crypto_req_common *common)
{
struct artpec6_crypto_dma_descriptors *dma = common->dma;
struct device *dev = artpec6_crypto_dev;
int i;
for (i = 0; i < dma->map_count; i++) {
struct artpec6_crypto_dma_map *map = &dma->maps[i];
dma_unmap_page(dev, map->dma_addr, map->size, map->dir);
}
dma->map_count = 0;
}
static int
artpec6_crypto_setup_out_descr(struct artpec6_crypto_req_common *common,
void *dst, unsigned int len, bool eop,
bool use_short)
{
if (use_short && len < 7) {
return artpec6_crypto_setup_out_descr_short(common, dst, len,
eop);
} else {
int ret;
dma_addr_t dma_addr;
ret = artpec6_crypto_dma_map_single(common, dst, len,
DMA_TO_DEVICE,
&dma_addr);
if (ret)
return ret;
return artpec6_crypto_setup_out_descr_phys(common, dma_addr,
len, eop);
}
}
static int
artpec6_crypto_setup_in_descr_phys(struct artpec6_crypto_req_common *common,
dma_addr_t addr, unsigned int len, bool intr)
{
struct artpec6_crypto_dma_descriptors *dma = common->dma;
struct pdma_descr *d;
if (dma->in_cnt >= PDMA_DESCR_COUNT ||
fault_inject_dma_descr()) {
pr_err("No free IN DMA descriptors available!\n");
return -ENOSPC;
}
d = &dma->in[dma->in_cnt++];
memset(d, 0, sizeof(*d));
d->ctrl.intr = intr;
d->data.len = len;
d->data.buf = addr;
return 0;
}
static int
artpec6_crypto_setup_in_descr(struct artpec6_crypto_req_common *common,
void *buffer, unsigned int len, bool last)
{
dma_addr_t dma_addr;
int ret;
ret = artpec6_crypto_dma_map_single(common, buffer, len,
DMA_FROM_DEVICE, &dma_addr);
if (ret)
return ret;
return artpec6_crypto_setup_in_descr_phys(common, dma_addr, len, last);
}
static struct artpec6_crypto_bounce_buffer *
artpec6_crypto_alloc_bounce(gfp_t flags)
{
void *base;
size_t alloc_size = sizeof(struct artpec6_crypto_bounce_buffer) +
2 * ARTPEC_CACHE_LINE_MAX;
struct artpec6_crypto_bounce_buffer *bbuf = kzalloc(alloc_size, flags);
if (!bbuf)
return NULL;
base = bbuf + 1;
bbuf->buf = PTR_ALIGN(base, ARTPEC_CACHE_LINE_MAX);
return bbuf;
}
static int setup_bounce_buffer_in(struct artpec6_crypto_req_common *common,
struct artpec6_crypto_walk *walk, size_t size)
{
struct artpec6_crypto_bounce_buffer *bbuf;
int ret;
bbuf = artpec6_crypto_alloc_bounce(common->gfp_flags);
if (!bbuf)
return -ENOMEM;
bbuf->length = size;
bbuf->sg = walk->sg;
bbuf->offset = walk->offset;
ret = artpec6_crypto_setup_in_descr(common, bbuf->buf, size, false);
if (ret) {
kfree(bbuf);
return ret;
}
pr_debug("BOUNCE %zu offset %zu\n", size, walk->offset);
list_add_tail(&bbuf->list, &common->dma->bounce_buffers);
return 0;
}
static int
artpec6_crypto_setup_sg_descrs_in(struct artpec6_crypto_req_common *common,
struct artpec6_crypto_walk *walk,
size_t count)
{
size_t chunk;
int ret;
dma_addr_t addr;
while (walk->sg && count) {
chunk = min(count, artpec6_crypto_walk_chunklen(walk));
addr = artpec6_crypto_walk_chunk_phys(walk);
if (!IS_ALIGNED(addr, ARTPEC_CACHE_LINE_MAX)) {
chunk = min_t(dma_addr_t, chunk,
ALIGN(addr, ARTPEC_CACHE_LINE_MAX) -
addr);
pr_debug("CHUNK-b %pad:%zu\n", &addr, chunk);
ret = setup_bounce_buffer_in(common, walk, chunk);
} else if (chunk < ARTPEC_CACHE_LINE_MAX) {
pr_debug("CHUNK-b %pad:%zu\n", &addr, chunk);
ret = setup_bounce_buffer_in(common, walk, chunk);
} else {
dma_addr_t dma_addr;
chunk = chunk & ~(ARTPEC_CACHE_LINE_MAX-1);
pr_debug("CHUNK %pad:%zu\n", &addr, chunk);
ret = artpec6_crypto_dma_map_page(common,
sg_page(walk->sg),
walk->sg->offset +
walk->offset,
chunk,
DMA_FROM_DEVICE,
&dma_addr);
if (ret)
return ret;
ret = artpec6_crypto_setup_in_descr_phys(common,
dma_addr,
chunk, false);
}
if (ret)
return ret;
count = count - chunk;
artpec6_crypto_walk_advance(walk, chunk);
}
if (count)
pr_err("EOL unexpected %zu bytes left\n", count);
return count ? -EINVAL : 0;
}
static int
artpec6_crypto_setup_sg_descrs_out(struct artpec6_crypto_req_common *common,
struct artpec6_crypto_walk *walk,
size_t count)
{
size_t chunk;
int ret;
dma_addr_t addr;
while (walk->sg && count) {
chunk = min(count, artpec6_crypto_walk_chunklen(walk));
addr = artpec6_crypto_walk_chunk_phys(walk);
pr_debug("OUT-CHUNK %pad:%zu\n", &addr, chunk);
if (addr & 3) {
char buf[3];
chunk = min_t(size_t, chunk, (4-(addr&3)));
sg_pcopy_to_buffer(walk->sg, 1, buf, chunk,
walk->offset);
ret = artpec6_crypto_setup_out_descr_short(common, buf,
chunk,
false);
} else {
dma_addr_t dma_addr;
ret = artpec6_crypto_dma_map_page(common,
sg_page(walk->sg),
walk->sg->offset +
walk->offset,
chunk,
DMA_TO_DEVICE,
&dma_addr);
if (ret)
return ret;
ret = artpec6_crypto_setup_out_descr_phys(common,
dma_addr,
chunk, false);
}
if (ret)
return ret;
count = count - chunk;
artpec6_crypto_walk_advance(walk, chunk);
}
if (count)
pr_err("EOL unexpected %zu bytes left\n", count);
return count ? -EINVAL : 0;
}
static int
artpec6_crypto_terminate_out_descrs(struct artpec6_crypto_req_common *common)
{
struct artpec6_crypto_dma_descriptors *dma = common->dma;
struct pdma_descr *d;
if (!dma->out_cnt || dma->out_cnt > PDMA_DESCR_COUNT) {
pr_err("%s: OUT descriptor list is %s\n",
MODULE_NAME, dma->out_cnt ? "empty" : "full");
return -EINVAL;
}
d = &dma->out[dma->out_cnt-1];
d->ctrl.eop = 1;
return 0;
}
static int
artpec6_crypto_terminate_in_descrs(struct artpec6_crypto_req_common *common)
{
struct artpec6_crypto_dma_descriptors *dma = common->dma;
struct pdma_descr *d;
if (!dma->in_cnt || dma->in_cnt > PDMA_DESCR_COUNT) {
pr_err("%s: IN descriptor list is %s\n",
MODULE_NAME, dma->in_cnt ? "empty" : "full");
return -EINVAL;
}
d = &dma->in[dma->in_cnt-1];
d->ctrl.intr = 1;
return 0;
}
static size_t
create_hash_pad(int oper, unsigned char *dst, u64 dgstlen, u64 bitcount)
{
unsigned int mod, target, diff, pad_bytes, size_bytes;
__be64 bits = __cpu_to_be64(bitcount);
switch (oper) {
case regk_crypto_sha1:
case regk_crypto_sha256:
case regk_crypto_hmac_sha1:
case regk_crypto_hmac_sha256:
target = 448 / 8;
mod = 512 / 8;
size_bytes = 8;
break;
default:
target = 896 / 8;
mod = 1024 / 8;
size_bytes = 16;
break;
}
target -= 1;
diff = dgstlen & (mod - 1);
pad_bytes = diff > target ? target + mod - diff : target - diff;
memset(dst + 1, 0, pad_bytes);
dst[0] = 0x80;
if (size_bytes == 16) {
memset(dst + 1 + pad_bytes, 0, 8);
memcpy(dst + 1 + pad_bytes + 8, &bits, 8);
} else {
memcpy(dst + 1 + pad_bytes, &bits, 8);
}
return pad_bytes + size_bytes + 1;
}
static int artpec6_crypto_common_init(struct artpec6_crypto_req_common *common,
struct crypto_async_request *parent,
void (*complete)(struct crypto_async_request *req),
struct scatterlist *dstsg, unsigned int nbytes)
{
gfp_t flags;
struct artpec6_crypto *ac = dev_get_drvdata(artpec6_crypto_dev);
flags = (parent->flags & CRYPTO_TFM_REQ_MAY_SLEEP) ?
GFP_KERNEL : GFP_ATOMIC;
common->gfp_flags = flags;
common->dma = kmem_cache_alloc(ac->dma_cache, flags);
if (!common->dma)
return -ENOMEM;
common->req = parent;
common->complete = complete;
return 0;
}
static void
artpec6_crypto_bounce_destroy(struct artpec6_crypto_dma_descriptors *dma)
{
struct artpec6_crypto_bounce_buffer *b;
struct artpec6_crypto_bounce_buffer *next;
list_for_each_entry_safe(b, next, &dma->bounce_buffers, list) {
kfree(b);
}
}
static int
artpec6_crypto_common_destroy(struct artpec6_crypto_req_common *common)
{
struct artpec6_crypto *ac = dev_get_drvdata(artpec6_crypto_dev);
artpec6_crypto_dma_unmap_all(common);
artpec6_crypto_bounce_destroy(common->dma);
kmem_cache_free(ac->dma_cache, common->dma);
common->dma = NULL;
return 0;
}
static int artpec6_crypto_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *cipher = crypto_skcipher_reqtfm(req);
struct artpec6_cryptotfm_context *ctx = crypto_skcipher_ctx(cipher);
struct artpec6_crypto_request_context *req_ctx = NULL;
void (*complete)(struct crypto_async_request *req);
int ret;
req_ctx = skcipher_request_ctx(req);
switch (ctx->crypto_type) {
case ARTPEC6_CRYPTO_CIPHER_AES_CBC:
case ARTPEC6_CRYPTO_CIPHER_AES_ECB:
case ARTPEC6_CRYPTO_CIPHER_AES_XTS:
req_ctx->decrypt = 0;
break;
default:
break;
}
switch (ctx->crypto_type) {
case ARTPEC6_CRYPTO_CIPHER_AES_CBC:
complete = artpec6_crypto_complete_cbc_encrypt;
break;
default:
complete = artpec6_crypto_complete_crypto;
break;
}
ret = artpec6_crypto_common_init(&req_ctx->common,
&req->base,
complete,
req->dst, req->cryptlen);
if (ret)
return ret;
ret = artpec6_crypto_prepare_crypto(req);
if (ret) {
artpec6_crypto_common_destroy(&req_ctx->common);
return ret;
}
return artpec6_crypto_submit(&req_ctx->common);
}
static int artpec6_crypto_decrypt(struct skcipher_request *req)
{
int ret;
struct crypto_skcipher *cipher = crypto_skcipher_reqtfm(req);
struct artpec6_cryptotfm_context *ctx = crypto_skcipher_ctx(cipher);
struct artpec6_crypto_request_context *req_ctx = NULL;
void (*complete)(struct crypto_async_request *req);
req_ctx = skcipher_request_ctx(req);
switch (ctx->crypto_type) {
case ARTPEC6_CRYPTO_CIPHER_AES_CBC:
case ARTPEC6_CRYPTO_CIPHER_AES_ECB:
case ARTPEC6_CRYPTO_CIPHER_AES_XTS:
req_ctx->decrypt = 1;
break;
default:
break;
}
switch (ctx->crypto_type) {
case ARTPEC6_CRYPTO_CIPHER_AES_CBC:
complete = artpec6_crypto_complete_cbc_decrypt;
break;
default:
complete = artpec6_crypto_complete_crypto;
break;
}
ret = artpec6_crypto_common_init(&req_ctx->common, &req->base,
complete,
req->dst, req->cryptlen);
if (ret)
return ret;
ret = artpec6_crypto_prepare_crypto(req);
if (ret) {
artpec6_crypto_common_destroy(&req_ctx->common);
return ret;
}
return artpec6_crypto_submit(&req_ctx->common);
}
static int
artpec6_crypto_ctr_crypt(struct skcipher_request *req, bool encrypt)
{
struct crypto_skcipher *cipher = crypto_skcipher_reqtfm(req);
struct artpec6_cryptotfm_context *ctx = crypto_skcipher_ctx(cipher);
size_t iv_len = crypto_skcipher_ivsize(cipher);
unsigned int counter = be32_to_cpup((__be32 *)
(req->iv + iv_len - 4));
unsigned int nblks = ALIGN(req->cryptlen, AES_BLOCK_SIZE) /
AES_BLOCK_SIZE;
if (counter + nblks < counter) {
int ret;
pr_debug("counter %x will overflow (nblks %u), falling back\n",
counter, counter + nblks);
ret = crypto_skcipher_setkey(ctx->fallback, ctx->aes_key,
ctx->key_length);
if (ret)
return ret;
{
SKCIPHER_REQUEST_ON_STACK(subreq, ctx->fallback);
skcipher_request_set_tfm(subreq, ctx->fallback);
skcipher_request_set_callback(subreq, req->base.flags,
NULL, NULL);
skcipher_request_set_crypt(subreq, req->src, req->dst,
req->cryptlen, req->iv);
ret = encrypt ? crypto_skcipher_encrypt(subreq)
: crypto_skcipher_decrypt(subreq);
skcipher_request_zero(subreq);
}
return ret;
}
return encrypt ? artpec6_crypto_encrypt(req)
: artpec6_crypto_decrypt(req);
}
static int artpec6_crypto_ctr_encrypt(struct skcipher_request *req)
{
return artpec6_crypto_ctr_crypt(req, true);
}
static int artpec6_crypto_ctr_decrypt(struct skcipher_request *req)
{
return artpec6_crypto_ctr_crypt(req, false);
}
static int artpec6_crypto_aead_init(struct crypto_aead *tfm)
{
struct artpec6_cryptotfm_context *tfm_ctx = crypto_aead_ctx(tfm);
memset(tfm_ctx, 0, sizeof(*tfm_ctx));
crypto_aead_set_reqsize(tfm,
sizeof(struct artpec6_crypto_aead_req_ctx));
return 0;
}
static int artpec6_crypto_aead_set_key(struct crypto_aead *tfm, const u8 *key,
unsigned int len)
{
struct artpec6_cryptotfm_context *ctx = crypto_tfm_ctx(&tfm->base);
if (len != 16 && len != 24 && len != 32) {
crypto_aead_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -1;
}
ctx->key_length = len;
memcpy(ctx->aes_key, key, len);
return 0;
}
static int artpec6_crypto_aead_encrypt(struct aead_request *req)
{
int ret;
struct artpec6_crypto_aead_req_ctx *req_ctx = aead_request_ctx(req);
req_ctx->decrypt = false;
ret = artpec6_crypto_common_init(&req_ctx->common, &req->base,
artpec6_crypto_complete_aead,
NULL, 0);
if (ret)
return ret;
ret = artpec6_crypto_prepare_aead(req);
if (ret) {
artpec6_crypto_common_destroy(&req_ctx->common);
return ret;
}
return artpec6_crypto_submit(&req_ctx->common);
}
static int artpec6_crypto_aead_decrypt(struct aead_request *req)
{
int ret;
struct artpec6_crypto_aead_req_ctx *req_ctx = aead_request_ctx(req);
req_ctx->decrypt = true;
if (req->cryptlen < AES_BLOCK_SIZE)
return -EINVAL;
ret = artpec6_crypto_common_init(&req_ctx->common,
&req->base,
artpec6_crypto_complete_aead,
NULL, 0);
if (ret)
return ret;
ret = artpec6_crypto_prepare_aead(req);
if (ret) {
artpec6_crypto_common_destroy(&req_ctx->common);
return ret;
}
return artpec6_crypto_submit(&req_ctx->common);
}
static int artpec6_crypto_prepare_hash(struct ahash_request *areq)
{
struct artpec6_hashalg_context *ctx = crypto_tfm_ctx(areq->base.tfm);
struct artpec6_hash_request_context *req_ctx = ahash_request_ctx(areq);
size_t digestsize = crypto_ahash_digestsize(crypto_ahash_reqtfm(areq));
size_t contextsize = digestsize == SHA384_DIGEST_SIZE ?
SHA512_DIGEST_SIZE : digestsize;
size_t blocksize = crypto_tfm_alg_blocksize(
crypto_ahash_tfm(crypto_ahash_reqtfm(areq)));
struct artpec6_crypto_req_common *common = &req_ctx->common;
struct artpec6_crypto *ac = dev_get_drvdata(artpec6_crypto_dev);
enum artpec6_crypto_variant variant = ac->variant;
u32 sel_ctx;
bool ext_ctx = false;
bool run_hw = false;
int error = 0;
artpec6_crypto_init_dma_operation(common);
if (req_ctx->hash_flags & HASH_FLAG_HMAC) {
if (variant == ARTPEC6_CRYPTO) {
req_ctx->key_md = FIELD_PREP(A6_CRY_MD_OPER,
a6_regk_crypto_dlkey);
} else {
req_ctx->key_md = FIELD_PREP(A7_CRY_MD_OPER,
a7_regk_crypto_dlkey);
}
memcpy(req_ctx->key_buffer, ctx->hmac_key,
ctx->hmac_key_length);
memset(req_ctx->key_buffer + ctx->hmac_key_length, 0,
blocksize - ctx->hmac_key_length);
error = artpec6_crypto_setup_out_descr(common,
(void *)&req_ctx->key_md,
sizeof(req_ctx->key_md), false, false);
if (error)
return error;
error = artpec6_crypto_setup_out_descr(common,
req_ctx->key_buffer, blocksize,
true, false);
if (error)
return error;
}
if (!(req_ctx->hash_flags & HASH_FLAG_INIT_CTX)) {
sel_ctx = regk_crypto_ext;
ext_ctx = true;
} else {
sel_ctx = regk_crypto_init;
}
if (variant == ARTPEC6_CRYPTO) {
req_ctx->hash_md &= ~A6_CRY_MD_HASH_SEL_CTX;
req_ctx->hash_md |= FIELD_PREP(A6_CRY_MD_HASH_SEL_CTX, sel_ctx);
if (req_ctx->hash_flags & HASH_FLAG_FINALIZE)
req_ctx->hash_md |= A6_CRY_MD_HASH_HMAC_FIN;
} else {
req_ctx->hash_md &= ~A7_CRY_MD_HASH_SEL_CTX;
req_ctx->hash_md |= FIELD_PREP(A7_CRY_MD_HASH_SEL_CTX, sel_ctx);
if (req_ctx->hash_flags & HASH_FLAG_FINALIZE)
req_ctx->hash_md |= A7_CRY_MD_HASH_HMAC_FIN;
}
error = artpec6_crypto_setup_out_descr(common,
(void *)&req_ctx->hash_md,
sizeof(req_ctx->hash_md), false, false);
if (error)
return error;
error = artpec6_crypto_setup_in_descr(common, ac->pad_buffer, 4, false);
if (error)
return error;
if (ext_ctx) {
error = artpec6_crypto_setup_out_descr(common,
req_ctx->digeststate,
contextsize, false, false);
if (error)
return error;
}
if (req_ctx->hash_flags & HASH_FLAG_UPDATE) {
size_t done_bytes = 0;
size_t total_bytes = areq->nbytes + req_ctx->partial_bytes;
size_t ready_bytes = round_down(total_bytes, blocksize);
struct artpec6_crypto_walk walk;
run_hw = ready_bytes > 0;
if (req_ctx->partial_bytes && ready_bytes) {
memcpy(req_ctx->partial_buffer_out,
req_ctx->partial_buffer,
req_ctx->partial_bytes);
error = artpec6_crypto_setup_out_descr(common,
req_ctx->partial_buffer_out,
req_ctx->partial_bytes,
false, true);
if (error)
return error;
done_bytes += req_ctx->partial_bytes;
req_ctx->partial_bytes = 0;
}
artpec6_crypto_walk_init(&walk, areq->src);
error = artpec6_crypto_setup_sg_descrs_out(common, &walk,
ready_bytes -
done_bytes);
if (error)
return error;
if (walk.sg) {
size_t sg_skip = ready_bytes - done_bytes;
size_t sg_rem = areq->nbytes - sg_skip;
sg_pcopy_to_buffer(areq->src, sg_nents(areq->src),
req_ctx->partial_buffer +
req_ctx->partial_bytes,
sg_rem, sg_skip);
req_ctx->partial_bytes += sg_rem;
}
req_ctx->digcnt += ready_bytes;
req_ctx->hash_flags &= ~(HASH_FLAG_UPDATE);
}
if (req_ctx->hash_flags & HASH_FLAG_FINALIZE) {
bool needtrim = contextsize != digestsize;
size_t hash_pad_len;
u64 digest_bits;
u32 oper;
if (variant == ARTPEC6_CRYPTO)
oper = FIELD_GET(A6_CRY_MD_OPER, req_ctx->hash_md);
else
oper = FIELD_GET(A7_CRY_MD_OPER, req_ctx->hash_md);
if (req_ctx->partial_bytes) {
memcpy(req_ctx->partial_buffer_out,
req_ctx->partial_buffer,
req_ctx->partial_bytes);
error = artpec6_crypto_setup_out_descr(common,
req_ctx->partial_buffer_out,
req_ctx->partial_bytes,
false, true);
if (error)
return error;
req_ctx->digcnt += req_ctx->partial_bytes;
req_ctx->partial_bytes = 0;
}
if (req_ctx->hash_flags & HASH_FLAG_HMAC)
digest_bits = 8 * (req_ctx->digcnt + blocksize);
else
digest_bits = 8 * req_ctx->digcnt;
hash_pad_len = create_hash_pad(oper, req_ctx->pad_buffer,
req_ctx->digcnt, digest_bits);
error = artpec6_crypto_setup_out_descr(common,
req_ctx->pad_buffer,
hash_pad_len, false,
true);
req_ctx->digcnt = 0;
if (error)
return error;
error = artpec6_crypto_setup_in_descr(common, areq->result,
digestsize,
!needtrim);
if (error)
return error;
if (needtrim) {
error = artpec6_crypto_setup_in_descr(common,
req_ctx->partial_buffer,
digestsize - contextsize, true);
if (error)
return error;
}
} else {
if (!run_hw)
return ARTPEC6_CRYPTO_PREPARE_HASH_NO_START;
error = artpec6_crypto_setup_in_descr(common,
req_ctx->digeststate,
contextsize, false);
if (error)
return error;
}
req_ctx->hash_flags &= ~(HASH_FLAG_INIT_CTX | HASH_FLAG_UPDATE |
HASH_FLAG_FINALIZE);
error = artpec6_crypto_terminate_in_descrs(common);
if (error)
return error;
error = artpec6_crypto_terminate_out_descrs(common);
if (error)
return error;
error = artpec6_crypto_dma_map_descs(common);
if (error)
return error;
return ARTPEC6_CRYPTO_PREPARE_HASH_START;
}
static int artpec6_crypto_aes_ecb_init(struct crypto_skcipher *tfm)
{
struct artpec6_cryptotfm_context *ctx = crypto_skcipher_ctx(tfm);
tfm->reqsize = sizeof(struct artpec6_crypto_request_context);
ctx->crypto_type = ARTPEC6_CRYPTO_CIPHER_AES_ECB;
return 0;
}
static int artpec6_crypto_aes_ctr_init(struct crypto_skcipher *tfm)
{
struct artpec6_cryptotfm_context *ctx = crypto_skcipher_ctx(tfm);
ctx->fallback = crypto_alloc_skcipher(crypto_tfm_alg_name(&tfm->base),
0,
CRYPTO_ALG_ASYNC |
CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(ctx->fallback))
return PTR_ERR(ctx->fallback);
tfm->reqsize = sizeof(struct artpec6_crypto_request_context);
ctx->crypto_type = ARTPEC6_CRYPTO_CIPHER_AES_CTR;
return 0;
}
static int artpec6_crypto_aes_cbc_init(struct crypto_skcipher *tfm)
{
struct artpec6_cryptotfm_context *ctx = crypto_skcipher_ctx(tfm);
tfm->reqsize = sizeof(struct artpec6_crypto_request_context);
ctx->crypto_type = ARTPEC6_CRYPTO_CIPHER_AES_CBC;
return 0;
}
static int artpec6_crypto_aes_xts_init(struct crypto_skcipher *tfm)
{
struct artpec6_cryptotfm_context *ctx = crypto_skcipher_ctx(tfm);
tfm->reqsize = sizeof(struct artpec6_crypto_request_context);
ctx->crypto_type = ARTPEC6_CRYPTO_CIPHER_AES_XTS;
return 0;
}
static void artpec6_crypto_aes_exit(struct crypto_skcipher *tfm)
{
struct artpec6_cryptotfm_context *ctx = crypto_skcipher_ctx(tfm);
memset(ctx, 0, sizeof(*ctx));
}
static void artpec6_crypto_aes_ctr_exit(struct crypto_skcipher *tfm)
{
struct artpec6_cryptotfm_context *ctx = crypto_skcipher_ctx(tfm);
crypto_free_skcipher(ctx->fallback);
artpec6_crypto_aes_exit(tfm);
}
static int
artpec6_crypto_cipher_set_key(struct crypto_skcipher *cipher, const u8 *key,
unsigned int keylen)
{
struct artpec6_cryptotfm_context *ctx =
crypto_skcipher_ctx(cipher);
switch (keylen) {
case 16:
case 24:
case 32:
break;
default:
crypto_skcipher_set_flags(cipher,
CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
memcpy(ctx->aes_key, key, keylen);
ctx->key_length = keylen;
return 0;
}
static int
artpec6_crypto_xts_set_key(struct crypto_skcipher *cipher, const u8 *key,
unsigned int keylen)
{
struct artpec6_cryptotfm_context *ctx =
crypto_skcipher_ctx(cipher);
int ret;
ret = xts_check_key(&cipher->base, key, keylen);
if (ret)
return ret;
switch (keylen) {
case 32:
case 48:
case 64:
break;
default:
crypto_skcipher_set_flags(cipher,
CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
memcpy(ctx->aes_key, key, keylen);
ctx->key_length = keylen;
return 0;
}
static int artpec6_crypto_prepare_crypto(struct skcipher_request *areq)
{
int ret;
struct artpec6_crypto_walk walk;
struct crypto_skcipher *cipher = crypto_skcipher_reqtfm(areq);
struct artpec6_cryptotfm_context *ctx = crypto_skcipher_ctx(cipher);
struct artpec6_crypto_request_context *req_ctx = NULL;
size_t iv_len = crypto_skcipher_ivsize(cipher);
struct artpec6_crypto *ac = dev_get_drvdata(artpec6_crypto_dev);
enum artpec6_crypto_variant variant = ac->variant;
struct artpec6_crypto_req_common *common;
bool cipher_decr = false;
size_t cipher_klen;
u32 cipher_len = 0;
u32 oper;
req_ctx = skcipher_request_ctx(areq);
common = &req_ctx->common;
artpec6_crypto_init_dma_operation(common);
if (variant == ARTPEC6_CRYPTO)
ctx->key_md = FIELD_PREP(A6_CRY_MD_OPER, a6_regk_crypto_dlkey);
else
ctx->key_md = FIELD_PREP(A7_CRY_MD_OPER, a7_regk_crypto_dlkey);
ret = artpec6_crypto_setup_out_descr(common, (void *)&ctx->key_md,
sizeof(ctx->key_md), false, false);
if (ret)
return ret;
ret = artpec6_crypto_setup_out_descr(common, ctx->aes_key,
ctx->key_length, true, false);
if (ret)
return ret;
req_ctx->cipher_md = 0;
if (ctx->crypto_type == ARTPEC6_CRYPTO_CIPHER_AES_XTS)
cipher_klen = ctx->key_length/2;
else
cipher_klen = ctx->key_length;
switch (cipher_klen) {
case 16:
cipher_len = regk_crypto_key_128;
break;
case 24:
cipher_len = regk_crypto_key_192;
break;
case 32:
cipher_len = regk_crypto_key_256;
break;
default:
pr_err("%s: Invalid key length %d!\n",
MODULE_NAME, ctx->key_length);
return -EINVAL;
}
switch (ctx->crypto_type) {
case ARTPEC6_CRYPTO_CIPHER_AES_ECB:
oper = regk_crypto_aes_ecb;
cipher_decr = req_ctx->decrypt;
break;
case ARTPEC6_CRYPTO_CIPHER_AES_CBC:
oper = regk_crypto_aes_cbc;
cipher_decr = req_ctx->decrypt;
break;
case ARTPEC6_CRYPTO_CIPHER_AES_CTR:
oper = regk_crypto_aes_ctr;
cipher_decr = false;
break;
case ARTPEC6_CRYPTO_CIPHER_AES_XTS:
oper = regk_crypto_aes_xts;
cipher_decr = req_ctx->decrypt;
if (variant == ARTPEC6_CRYPTO)
req_ctx->cipher_md |= A6_CRY_MD_CIPHER_DSEQ;
else
req_ctx->cipher_md |= A7_CRY_MD_CIPHER_DSEQ;
break;
default:
pr_err("%s: Invalid cipher mode %d!\n",
MODULE_NAME, ctx->crypto_type);
return -EINVAL;
}
if (variant == ARTPEC6_CRYPTO) {
req_ctx->cipher_md |= FIELD_PREP(A6_CRY_MD_OPER, oper);
req_ctx->cipher_md |= FIELD_PREP(A6_CRY_MD_CIPHER_LEN,
cipher_len);
if (cipher_decr)
req_ctx->cipher_md |= A6_CRY_MD_CIPHER_DECR;
} else {
req_ctx->cipher_md |= FIELD_PREP(A7_CRY_MD_OPER, oper);
req_ctx->cipher_md |= FIELD_PREP(A7_CRY_MD_CIPHER_LEN,
cipher_len);
if (cipher_decr)
req_ctx->cipher_md |= A7_CRY_MD_CIPHER_DECR;
}
ret = artpec6_crypto_setup_out_descr(common,
&req_ctx->cipher_md,
sizeof(req_ctx->cipher_md),
false, false);
if (ret)
return ret;
ret = artpec6_crypto_setup_in_descr(common, ac->pad_buffer, 4, false);
if (ret)
return ret;
if (iv_len) {
ret = artpec6_crypto_setup_out_descr(common, areq->iv, iv_len,
false, false);
if (ret)
return ret;
}
artpec6_crypto_walk_init(&walk, areq->src);
ret = artpec6_crypto_setup_sg_descrs_out(common, &walk, areq->cryptlen);
if (ret)
return ret;
artpec6_crypto_walk_init(&walk, areq->dst);
ret = artpec6_crypto_setup_sg_descrs_in(common, &walk, areq->cryptlen);
if (ret)
return ret;
if (ctx->crypto_type == ARTPEC6_CRYPTO_CIPHER_AES_CTR ||
ctx->crypto_type == ARTPEC6_CRYPTO_CIPHER_AES_XTS) {
size_t pad = ALIGN(areq->cryptlen, AES_BLOCK_SIZE) -
areq->cryptlen;
if (pad) {
ret = artpec6_crypto_setup_out_descr(common,
ac->pad_buffer,
pad, false, false);
if (ret)
return ret;
ret = artpec6_crypto_setup_in_descr(common,
ac->pad_buffer, pad,
false);
if (ret)
return ret;
}
}
ret = artpec6_crypto_terminate_out_descrs(common);
if (ret)
return ret;
ret = artpec6_crypto_terminate_in_descrs(common);
if (ret)
return ret;
return artpec6_crypto_dma_map_descs(common);
}
static int artpec6_crypto_prepare_aead(struct aead_request *areq)
{
size_t count;
int ret;
size_t input_length;
struct artpec6_cryptotfm_context *ctx = crypto_tfm_ctx(areq->base.tfm);
struct artpec6_crypto_aead_req_ctx *req_ctx = aead_request_ctx(areq);
struct crypto_aead *cipher = crypto_aead_reqtfm(areq);
struct artpec6_crypto_req_common *common = &req_ctx->common;
struct artpec6_crypto *ac = dev_get_drvdata(artpec6_crypto_dev);
enum artpec6_crypto_variant variant = ac->variant;
u32 md_cipher_len;
artpec6_crypto_init_dma_operation(common);
if (variant == ARTPEC6_CRYPTO) {
ctx->key_md = FIELD_PREP(A6_CRY_MD_OPER,
a6_regk_crypto_dlkey);
} else {
ctx->key_md = FIELD_PREP(A7_CRY_MD_OPER,
a7_regk_crypto_dlkey);
}
ret = artpec6_crypto_setup_out_descr(common, (void *)&ctx->key_md,
sizeof(ctx->key_md), false, false);
if (ret)
return ret;
ret = artpec6_crypto_setup_out_descr(common, ctx->aes_key,
ctx->key_length, true, false);
if (ret)
return ret;
req_ctx->cipher_md = 0;
switch (ctx->key_length) {
case 16:
md_cipher_len = regk_crypto_key_128;
break;
case 24:
md_cipher_len = regk_crypto_key_192;
break;
case 32:
md_cipher_len = regk_crypto_key_256;
break;
default:
return -EINVAL;
}
if (variant == ARTPEC6_CRYPTO) {
req_ctx->cipher_md |= FIELD_PREP(A6_CRY_MD_OPER,
regk_crypto_aes_gcm);
req_ctx->cipher_md |= FIELD_PREP(A6_CRY_MD_CIPHER_LEN,
md_cipher_len);
if (req_ctx->decrypt)
req_ctx->cipher_md |= A6_CRY_MD_CIPHER_DECR;
} else {
req_ctx->cipher_md |= FIELD_PREP(A7_CRY_MD_OPER,
regk_crypto_aes_gcm);
req_ctx->cipher_md |= FIELD_PREP(A7_CRY_MD_CIPHER_LEN,
md_cipher_len);
if (req_ctx->decrypt)
req_ctx->cipher_md |= A7_CRY_MD_CIPHER_DECR;
}
ret = artpec6_crypto_setup_out_descr(common,
(void *) &req_ctx->cipher_md,
sizeof(req_ctx->cipher_md), false,
false);
if (ret)
return ret;
ret = artpec6_crypto_setup_in_descr(common, ac->pad_buffer, 4, false);
if (ret)
return ret;
input_length = areq->cryptlen;
if (req_ctx->decrypt)
input_length -= AES_BLOCK_SIZE;
req_ctx->hw_ctx.aad_length_bits =
__cpu_to_be64(8*areq->assoclen);
req_ctx->hw_ctx.text_length_bits =
__cpu_to_be64(8*input_length);
memcpy(req_ctx->hw_ctx.J0, areq->iv, crypto_aead_ivsize(cipher));
crypto_inc(req_ctx->hw_ctx.J0+12, 4);
ret = artpec6_crypto_setup_out_descr(common, &req_ctx->hw_ctx,
sizeof(struct artpec6_crypto_aead_hw_ctx), false, false);
if (ret)
return ret;
{
struct artpec6_crypto_walk walk;
artpec6_crypto_walk_init(&walk, areq->src);
count = areq->assoclen;
ret = artpec6_crypto_setup_sg_descrs_out(common, &walk, count);
if (ret)
return ret;
if (!IS_ALIGNED(areq->assoclen, 16)) {
size_t assoc_pad = 16 - (areq->assoclen % 16);
ret = artpec6_crypto_setup_out_descr(common,
ac->zero_buffer,
assoc_pad, false,
false);
if (ret)
return ret;
}
count = input_length;
ret = artpec6_crypto_setup_sg_descrs_out(common, &walk, count);
if (ret)
return ret;
if (!IS_ALIGNED(input_length, 16)) {
size_t crypto_pad = 16 - (input_length % 16);
ret = artpec6_crypto_setup_out_descr(common,
ac->zero_buffer,
crypto_pad,
false,
false);
if (ret)
return ret;
}
}
{
struct artpec6_crypto_walk walk;
size_t output_len = areq->cryptlen;
if (req_ctx->decrypt)
output_len -= AES_BLOCK_SIZE;
artpec6_crypto_walk_init(&walk, areq->dst);
count = artpec6_crypto_walk_advance(&walk, areq->assoclen);
if (count)
return -EINVAL;
count = output_len;
ret = artpec6_crypto_setup_sg_descrs_in(common, &walk, count);
if (ret)
return ret;
if (!IS_ALIGNED(output_len, 16)) {
size_t crypto_pad = 16 - (output_len % 16);
ret = artpec6_crypto_setup_in_descr(common,
ac->pad_buffer,
crypto_pad, false);
if (ret)
return ret;
}
count = AES_BLOCK_SIZE;
if (req_ctx->decrypt) {
ret = artpec6_crypto_setup_in_descr(common,
req_ctx->decryption_tag, count, false);
if (ret)
return ret;
} else {
ret = artpec6_crypto_setup_sg_descrs_in(common, &walk,
count);
if (ret)
return ret;
}
}
ret = artpec6_crypto_terminate_in_descrs(common);
if (ret)
return ret;
ret = artpec6_crypto_terminate_out_descrs(common);
if (ret)
return ret;
return artpec6_crypto_dma_map_descs(common);
}
static void artpec6_crypto_process_queue(struct artpec6_crypto *ac)
{
struct artpec6_crypto_req_common *req;
while (!list_empty(&ac->queue) && !artpec6_crypto_busy()) {
req = list_first_entry(&ac->queue,
struct artpec6_crypto_req_common,
list);
list_move_tail(&req->list, &ac->pending);
artpec6_crypto_start_dma(req);
req->req->complete(req->req, -EINPROGRESS);
}
if (ac->pending_count)
mod_timer(&ac->timer, jiffies + msecs_to_jiffies(100));
else
del_timer(&ac->timer);
}
static void artpec6_crypto_timeout(unsigned long data)
{
struct artpec6_crypto *ac = (struct artpec6_crypto *) data;
dev_info_ratelimited(artpec6_crypto_dev, "timeout\n");
tasklet_schedule(&ac->task);
}
static void artpec6_crypto_task(unsigned long data)
{
struct artpec6_crypto *ac = (struct artpec6_crypto *)data;
struct artpec6_crypto_req_common *req;
struct artpec6_crypto_req_common *n;
if (list_empty(&ac->pending)) {
pr_debug("Spurious IRQ\n");
return;
}
spin_lock_bh(&ac->queue_lock);
list_for_each_entry_safe(req, n, &ac->pending, list) {
struct artpec6_crypto_dma_descriptors *dma = req->dma;
u32 stat;
dma_sync_single_for_cpu(artpec6_crypto_dev, dma->stat_dma_addr,
sizeof(dma->stat[0]),
DMA_BIDIRECTIONAL);
stat = req->dma->stat[req->dma->in_cnt-1];
pr_debug("Request %p status is %X\n", req, stat);
if (!stat)
break;
#ifdef CONFIG_FAULT_INJECTION
if (should_fail(&artpec6_crypto_fail_status_read, 1))
continue;
#endif
pr_debug("Completing request %p\n", req);
list_del(&req->list);
artpec6_crypto_dma_unmap_all(req);
artpec6_crypto_copy_bounce_buffers(req);
ac->pending_count--;
artpec6_crypto_common_destroy(req);
req->complete(req->req);
}
artpec6_crypto_process_queue(ac);
spin_unlock_bh(&ac->queue_lock);
}
static void artpec6_crypto_complete_crypto(struct crypto_async_request *req)
{
req->complete(req, 0);
}
static void
artpec6_crypto_complete_cbc_decrypt(struct crypto_async_request *req)
{
struct skcipher_request *cipher_req = container_of(req,
struct skcipher_request, base);
scatterwalk_map_and_copy(cipher_req->iv, cipher_req->src,
cipher_req->cryptlen - AES_BLOCK_SIZE,
AES_BLOCK_SIZE, 0);
req->complete(req, 0);
}
static void
artpec6_crypto_complete_cbc_encrypt(struct crypto_async_request *req)
{
struct skcipher_request *cipher_req = container_of(req,
struct skcipher_request, base);
scatterwalk_map_and_copy(cipher_req->iv, cipher_req->dst,
cipher_req->cryptlen - AES_BLOCK_SIZE,
AES_BLOCK_SIZE, 0);
req->complete(req, 0);
}
static void artpec6_crypto_complete_aead(struct crypto_async_request *req)
{
int result = 0;
struct aead_request *areq = container_of(req,
struct aead_request, base);
struct artpec6_crypto_aead_req_ctx *req_ctx = aead_request_ctx(areq);
if (req_ctx->decrypt) {
u8 input_tag[AES_BLOCK_SIZE];
sg_pcopy_to_buffer(areq->src,
sg_nents(areq->src),
input_tag,
AES_BLOCK_SIZE,
areq->assoclen + areq->cryptlen -
AES_BLOCK_SIZE);
if (memcmp(req_ctx->decryption_tag,
input_tag,
AES_BLOCK_SIZE)) {
pr_debug("***EBADMSG:\n");
print_hex_dump_debug("ref:", DUMP_PREFIX_ADDRESS, 32, 1,
input_tag, AES_BLOCK_SIZE, true);
print_hex_dump_debug("out:", DUMP_PREFIX_ADDRESS, 32, 1,
req_ctx->decryption_tag,
AES_BLOCK_SIZE, true);
result = -EBADMSG;
}
}
req->complete(req, result);
}
static void artpec6_crypto_complete_hash(struct crypto_async_request *req)
{
req->complete(req, 0);
}
static int
artpec6_crypto_hash_set_key(struct crypto_ahash *tfm,
const u8 *key, unsigned int keylen)
{
struct artpec6_hashalg_context *tfm_ctx = crypto_tfm_ctx(&tfm->base);
size_t blocksize;
int ret;
if (!keylen) {
pr_err("Invalid length (%d) of HMAC key\n",
keylen);
return -EINVAL;
}
memset(tfm_ctx->hmac_key, 0, sizeof(tfm_ctx->hmac_key));
blocksize = crypto_tfm_alg_blocksize(crypto_ahash_tfm(tfm));
if (keylen > blocksize) {
SHASH_DESC_ON_STACK(hdesc, tfm_ctx->child_hash);
hdesc->tfm = tfm_ctx->child_hash;
hdesc->flags = crypto_ahash_get_flags(tfm) &
CRYPTO_TFM_REQ_MAY_SLEEP;
tfm_ctx->hmac_key_length = blocksize;
ret = crypto_shash_digest(hdesc, key, keylen,
tfm_ctx->hmac_key);
if (ret)
return ret;
} else {
memcpy(tfm_ctx->hmac_key, key, keylen);
tfm_ctx->hmac_key_length = keylen;
}
return 0;
}
static int
artpec6_crypto_init_hash(struct ahash_request *req, u8 type, int hmac)
{
struct artpec6_crypto *ac = dev_get_drvdata(artpec6_crypto_dev);
enum artpec6_crypto_variant variant = ac->variant;
struct artpec6_hash_request_context *req_ctx = ahash_request_ctx(req);
u32 oper;
memset(req_ctx, 0, sizeof(*req_ctx));
req_ctx->hash_flags = HASH_FLAG_INIT_CTX;
if (hmac)
req_ctx->hash_flags |= (HASH_FLAG_HMAC | HASH_FLAG_UPDATE_KEY);
switch (type) {
case ARTPEC6_CRYPTO_HASH_SHA1:
oper = hmac ? regk_crypto_hmac_sha1 : regk_crypto_sha1;
break;
case ARTPEC6_CRYPTO_HASH_SHA256:
oper = hmac ? regk_crypto_hmac_sha256 : regk_crypto_sha256;
break;
case ARTPEC6_CRYPTO_HASH_SHA384:
oper = hmac ? regk_crypto_hmac_sha384 : regk_crypto_sha384;
break;
case ARTPEC6_CRYPTO_HASH_SHA512:
oper = hmac ? regk_crypto_hmac_sha512 : regk_crypto_sha512;
break;
default:
pr_err("%s: Unsupported hash type 0x%x\n", MODULE_NAME, type);
return -EINVAL;
}
if (variant == ARTPEC6_CRYPTO)
req_ctx->hash_md = FIELD_PREP(A6_CRY_MD_OPER, oper);
else
req_ctx->hash_md = FIELD_PREP(A7_CRY_MD_OPER, oper);
return 0;
}
static int artpec6_crypto_prepare_submit_hash(struct ahash_request *req)
{
struct artpec6_hash_request_context *req_ctx = ahash_request_ctx(req);
int ret;
if (!req_ctx->common.dma) {
ret = artpec6_crypto_common_init(&req_ctx->common,
&req->base,
artpec6_crypto_complete_hash,
NULL, 0);
if (ret)
return ret;
}
ret = artpec6_crypto_prepare_hash(req);
switch (ret) {
case ARTPEC6_CRYPTO_PREPARE_HASH_START:
ret = artpec6_crypto_submit(&req_ctx->common);
break;
case ARTPEC6_CRYPTO_PREPARE_HASH_NO_START:
ret = 0;
default:
artpec6_crypto_common_destroy(&req_ctx->common);
break;
}
return ret;
}
static int artpec6_crypto_hash_final(struct ahash_request *req)
{
struct artpec6_hash_request_context *req_ctx = ahash_request_ctx(req);
req_ctx->hash_flags |= HASH_FLAG_FINALIZE;
return artpec6_crypto_prepare_submit_hash(req);
}
static int artpec6_crypto_hash_update(struct ahash_request *req)
{
struct artpec6_hash_request_context *req_ctx = ahash_request_ctx(req);
req_ctx->hash_flags |= HASH_FLAG_UPDATE;
return artpec6_crypto_prepare_submit_hash(req);
}
static int artpec6_crypto_sha1_init(struct ahash_request *req)
{
return artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA1, 0);
}
static int artpec6_crypto_sha1_digest(struct ahash_request *req)
{
struct artpec6_hash_request_context *req_ctx = ahash_request_ctx(req);
artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA1, 0);
req_ctx->hash_flags |= HASH_FLAG_UPDATE | HASH_FLAG_FINALIZE;
return artpec6_crypto_prepare_submit_hash(req);
}
static int artpec6_crypto_sha256_init(struct ahash_request *req)
{
return artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA256, 0);
}
static int artpec6_crypto_sha256_digest(struct ahash_request *req)
{
struct artpec6_hash_request_context *req_ctx = ahash_request_ctx(req);
artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA256, 0);
req_ctx->hash_flags |= HASH_FLAG_UPDATE | HASH_FLAG_FINALIZE;
return artpec6_crypto_prepare_submit_hash(req);
}
static int __maybe_unused artpec6_crypto_sha384_init(struct ahash_request *req)
{
return artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA384, 0);
}
static int __maybe_unused
artpec6_crypto_sha384_digest(struct ahash_request *req)
{
struct artpec6_hash_request_context *req_ctx = ahash_request_ctx(req);
artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA384, 0);
req_ctx->hash_flags |= HASH_FLAG_UPDATE | HASH_FLAG_FINALIZE;
return artpec6_crypto_prepare_submit_hash(req);
}
static int artpec6_crypto_sha512_init(struct ahash_request *req)
{
return artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA512, 0);
}
static int artpec6_crypto_sha512_digest(struct ahash_request *req)
{
struct artpec6_hash_request_context *req_ctx = ahash_request_ctx(req);
artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA512, 0);
req_ctx->hash_flags |= HASH_FLAG_UPDATE | HASH_FLAG_FINALIZE;
return artpec6_crypto_prepare_submit_hash(req);
}
static int artpec6_crypto_hmac_sha256_init(struct ahash_request *req)
{
return artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA256, 1);
}
static int __maybe_unused
artpec6_crypto_hmac_sha384_init(struct ahash_request *req)
{
return artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA384, 1);
}
static int artpec6_crypto_hmac_sha512_init(struct ahash_request *req)
{
return artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA512, 1);
}
static int artpec6_crypto_hmac_sha256_digest(struct ahash_request *req)
{
struct artpec6_hash_request_context *req_ctx = ahash_request_ctx(req);
artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA256, 1);
req_ctx->hash_flags |= HASH_FLAG_UPDATE | HASH_FLAG_FINALIZE;
return artpec6_crypto_prepare_submit_hash(req);
}
static int __maybe_unused
artpec6_crypto_hmac_sha384_digest(struct ahash_request *req)
{
struct artpec6_hash_request_context *req_ctx = ahash_request_ctx(req);
artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA384, 1);
req_ctx->hash_flags |= HASH_FLAG_UPDATE | HASH_FLAG_FINALIZE;
return artpec6_crypto_prepare_submit_hash(req);
}
static int artpec6_crypto_hmac_sha512_digest(struct ahash_request *req)
{
struct artpec6_hash_request_context *req_ctx = ahash_request_ctx(req);
artpec6_crypto_init_hash(req, ARTPEC6_CRYPTO_HASH_SHA512, 1);
req_ctx->hash_flags |= HASH_FLAG_UPDATE | HASH_FLAG_FINALIZE;
return artpec6_crypto_prepare_submit_hash(req);
}
static int artpec6_crypto_ahash_init_common(struct crypto_tfm *tfm,
const char *base_hash_name)
{
struct artpec6_hashalg_context *tfm_ctx = crypto_tfm_ctx(tfm);
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct artpec6_hash_request_context));
memset(tfm_ctx, 0, sizeof(*tfm_ctx));
if (base_hash_name) {
struct crypto_shash *child;
child = crypto_alloc_shash(base_hash_name, 0,
CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(child))
return PTR_ERR(child);
tfm_ctx->child_hash = child;
}
return 0;
}
static int artpec6_crypto_ahash_init(struct crypto_tfm *tfm)
{
return artpec6_crypto_ahash_init_common(tfm, NULL);
}
static int artpec6_crypto_ahash_init_hmac_sha256(struct crypto_tfm *tfm)
{
return artpec6_crypto_ahash_init_common(tfm, "sha256");
}
static int __maybe_unused
artpec6_crypto_ahash_init_hmac_sha384(struct crypto_tfm *tfm)
{
return artpec6_crypto_ahash_init_common(tfm, "sha384");
}
static int artpec6_crypto_ahash_init_hmac_sha512(struct crypto_tfm *tfm)
{
return artpec6_crypto_ahash_init_common(tfm, "sha512");
}
static void artpec6_crypto_ahash_exit(struct crypto_tfm *tfm)
{
struct artpec6_hashalg_context *tfm_ctx = crypto_tfm_ctx(tfm);
if (tfm_ctx->child_hash)
crypto_free_shash(tfm_ctx->child_hash);
memset(tfm_ctx->hmac_key, 0, sizeof(tfm_ctx->hmac_key));
tfm_ctx->hmac_key_length = 0;
}
static int artpec6_crypto_hash_export(struct ahash_request *req, void *out)
{
const struct artpec6_hash_request_context *ctx = ahash_request_ctx(req);
struct artpec6_hash_export_state *state = out;
struct artpec6_crypto *ac = dev_get_drvdata(artpec6_crypto_dev);
enum artpec6_crypto_variant variant = ac->variant;
BUILD_BUG_ON(sizeof(state->partial_buffer) !=
sizeof(ctx->partial_buffer));
BUILD_BUG_ON(sizeof(state->digeststate) != sizeof(ctx->digeststate));
state->digcnt = ctx->digcnt;
state->partial_bytes = ctx->partial_bytes;
state->hash_flags = ctx->hash_flags;
if (variant == ARTPEC6_CRYPTO)
state->oper = FIELD_GET(A6_CRY_MD_OPER, ctx->hash_md);
else
state->oper = FIELD_GET(A7_CRY_MD_OPER, ctx->hash_md);
memcpy(state->partial_buffer, ctx->partial_buffer,
sizeof(state->partial_buffer));
memcpy(state->digeststate, ctx->digeststate,
sizeof(state->digeststate));
return 0;
}
static int artpec6_crypto_hash_import(struct ahash_request *req, const void *in)
{
struct artpec6_hash_request_context *ctx = ahash_request_ctx(req);
const struct artpec6_hash_export_state *state = in;
struct artpec6_crypto *ac = dev_get_drvdata(artpec6_crypto_dev);
enum artpec6_crypto_variant variant = ac->variant;
memset(ctx, 0, sizeof(*ctx));
ctx->digcnt = state->digcnt;
ctx->partial_bytes = state->partial_bytes;
ctx->hash_flags = state->hash_flags;
if (variant == ARTPEC6_CRYPTO)
ctx->hash_md = FIELD_PREP(A6_CRY_MD_OPER, state->oper);
else
ctx->hash_md = FIELD_PREP(A7_CRY_MD_OPER, state->oper);
memcpy(ctx->partial_buffer, state->partial_buffer,
sizeof(state->partial_buffer));
memcpy(ctx->digeststate, state->digeststate,
sizeof(state->digeststate));
return 0;
}
static int init_crypto_hw(struct artpec6_crypto *ac)
{
enum artpec6_crypto_variant variant = ac->variant;
void __iomem *base = ac->base;
u32 out_descr_buf_size;
u32 out_data_buf_size;
u32 in_data_buf_size;
u32 in_descr_buf_size;
u32 in_stat_buf_size;
u32 in, out;
out_data_buf_size = 16;
out_descr_buf_size = 15;
in_data_buf_size = 8;
in_descr_buf_size = 4;
in_stat_buf_size = 4;
BUILD_BUG_ON_MSG((out_data_buf_size
+ out_descr_buf_size) * 64 > 1984,
"Invalid OUT configuration");
BUILD_BUG_ON_MSG((in_data_buf_size
+ in_descr_buf_size
+ in_stat_buf_size) * 64 > 1024,
"Invalid IN configuration");
in = FIELD_PREP(PDMA_IN_BUF_CFG_DATA_BUF_SIZE, in_data_buf_size) |
FIELD_PREP(PDMA_IN_BUF_CFG_DESCR_BUF_SIZE, in_descr_buf_size) |
FIELD_PREP(PDMA_IN_BUF_CFG_STAT_BUF_SIZE, in_stat_buf_size);
out = FIELD_PREP(PDMA_OUT_BUF_CFG_DATA_BUF_SIZE, out_data_buf_size) |
FIELD_PREP(PDMA_OUT_BUF_CFG_DESCR_BUF_SIZE, out_descr_buf_size);
writel_relaxed(out, base + PDMA_OUT_BUF_CFG);
writel_relaxed(PDMA_OUT_CFG_EN, base + PDMA_OUT_CFG);
if (variant == ARTPEC6_CRYPTO) {
writel_relaxed(in, base + A6_PDMA_IN_BUF_CFG);
writel_relaxed(PDMA_IN_CFG_EN, base + A6_PDMA_IN_CFG);
writel_relaxed(A6_PDMA_INTR_MASK_IN_DATA |
A6_PDMA_INTR_MASK_IN_EOP_FLUSH,
base + A6_PDMA_INTR_MASK);
} else {
writel_relaxed(in, base + A7_PDMA_IN_BUF_CFG);
writel_relaxed(PDMA_IN_CFG_EN, base + A7_PDMA_IN_CFG);
writel_relaxed(A7_PDMA_INTR_MASK_IN_DATA |
A7_PDMA_INTR_MASK_IN_EOP_FLUSH,
base + A7_PDMA_INTR_MASK);
}
return 0;
}
static void artpec6_crypto_disable_hw(struct artpec6_crypto *ac)
{
enum artpec6_crypto_variant variant = ac->variant;
void __iomem *base = ac->base;
if (variant == ARTPEC6_CRYPTO) {
writel_relaxed(A6_PDMA_IN_CMD_STOP, base + A6_PDMA_IN_CMD);
writel_relaxed(0, base + A6_PDMA_IN_CFG);
writel_relaxed(A6_PDMA_OUT_CMD_STOP, base + PDMA_OUT_CMD);
} else {
writel_relaxed(A7_PDMA_IN_CMD_STOP, base + A7_PDMA_IN_CMD);
writel_relaxed(0, base + A7_PDMA_IN_CFG);
writel_relaxed(A7_PDMA_OUT_CMD_STOP, base + PDMA_OUT_CMD);
}
writel_relaxed(0, base + PDMA_OUT_CFG);
}
static irqreturn_t artpec6_crypto_irq(int irq, void *dev_id)
{
struct artpec6_crypto *ac = dev_id;
enum artpec6_crypto_variant variant = ac->variant;
void __iomem *base = ac->base;
u32 mask_in_data, mask_in_eop_flush;
u32 in_cmd_flush_stat, in_cmd_reg;
u32 ack_intr_reg;
u32 ack = 0;
u32 intr;
if (variant == ARTPEC6_CRYPTO) {
intr = readl_relaxed(base + A6_PDMA_MASKED_INTR);
mask_in_data = A6_PDMA_INTR_MASK_IN_DATA;
mask_in_eop_flush = A6_PDMA_INTR_MASK_IN_EOP_FLUSH;
in_cmd_flush_stat = A6_PDMA_IN_CMD_FLUSH_STAT;
in_cmd_reg = A6_PDMA_IN_CMD;
ack_intr_reg = A6_PDMA_ACK_INTR;
} else {
intr = readl_relaxed(base + A7_PDMA_MASKED_INTR);
mask_in_data = A7_PDMA_INTR_MASK_IN_DATA;
mask_in_eop_flush = A7_PDMA_INTR_MASK_IN_EOP_FLUSH;
in_cmd_flush_stat = A7_PDMA_IN_CMD_FLUSH_STAT;
in_cmd_reg = A7_PDMA_IN_CMD;
ack_intr_reg = A7_PDMA_ACK_INTR;
}
if (intr & mask_in_data)
ack |= mask_in_data;
if (intr & mask_in_eop_flush)
ack |= mask_in_eop_flush;
else
writel_relaxed(in_cmd_flush_stat, base + in_cmd_reg);
writel_relaxed(ack, base + ack_intr_reg);
if (intr & mask_in_eop_flush)
tasklet_schedule(&ac->task);
return IRQ_HANDLED;
}
static void artpec6_crypto_init_debugfs(void)
{
dbgfs_root = debugfs_create_dir("artpec6_crypto", NULL);
if (!dbgfs_root || IS_ERR(dbgfs_root)) {
dbgfs_root = NULL;
pr_err("%s: Could not initialise debugfs!\n", MODULE_NAME);
return;
}
#ifdef CONFIG_FAULT_INJECTION
fault_create_debugfs_attr("fail_status_read", dbgfs_root,
&artpec6_crypto_fail_status_read);
fault_create_debugfs_attr("fail_dma_array_full", dbgfs_root,
&artpec6_crypto_fail_dma_array_full);
#endif
}
static void artpec6_crypto_free_debugfs(void)
{
if (!dbgfs_root)
return;
debugfs_remove_recursive(dbgfs_root);
dbgfs_root = NULL;
}
static int artpec6_crypto_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
enum artpec6_crypto_variant variant;
struct artpec6_crypto *ac;
struct device *dev = &pdev->dev;
void __iomem *base;
struct resource *res;
int irq;
int err;
if (artpec6_crypto_dev)
return -ENODEV;
match = of_match_node(artpec6_crypto_of_match, dev->of_node);
if (!match)
return -EINVAL;
variant = (enum artpec6_crypto_variant)match->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return -ENODEV;
ac = devm_kzalloc(&pdev->dev, sizeof(struct artpec6_crypto),
GFP_KERNEL);
if (!ac)
return -ENOMEM;
platform_set_drvdata(pdev, ac);
ac->variant = variant;
spin_lock_init(&ac->queue_lock);
INIT_LIST_HEAD(&ac->queue);
INIT_LIST_HEAD(&ac->pending);
setup_timer(&ac->timer, artpec6_crypto_timeout, (unsigned long) ac);
ac->base = base;
ac->dma_cache = kmem_cache_create("artpec6_crypto_dma",
sizeof(struct artpec6_crypto_dma_descriptors),
64,
0,
NULL);
if (!ac->dma_cache)
return -ENOMEM;
#ifdef CONFIG_DEBUG_FS
artpec6_crypto_init_debugfs();
#endif
tasklet_init(&ac->task, artpec6_crypto_task,
(unsigned long)ac);
ac->pad_buffer = devm_kzalloc(&pdev->dev, 2 * ARTPEC_CACHE_LINE_MAX,
GFP_KERNEL);
if (!ac->pad_buffer)
return -ENOMEM;
ac->pad_buffer = PTR_ALIGN(ac->pad_buffer, ARTPEC_CACHE_LINE_MAX);
ac->zero_buffer = devm_kzalloc(&pdev->dev, 2 * ARTPEC_CACHE_LINE_MAX,
GFP_KERNEL);
if (!ac->zero_buffer)
return -ENOMEM;
ac->zero_buffer = PTR_ALIGN(ac->zero_buffer, ARTPEC_CACHE_LINE_MAX);
err = init_crypto_hw(ac);
if (err)
goto free_cache;
err = devm_request_irq(&pdev->dev, irq, artpec6_crypto_irq, 0,
"artpec6-crypto", ac);
if (err)
goto disable_hw;
artpec6_crypto_dev = &pdev->dev;
err = crypto_register_ahashes(hash_algos, ARRAY_SIZE(hash_algos));
if (err) {
dev_err(dev, "Failed to register ahashes\n");
goto disable_hw;
}
if (variant != ARTPEC6_CRYPTO) {
err = crypto_register_ahashes(artpec7_hash_algos,
ARRAY_SIZE(artpec7_hash_algos));
if (err) {
dev_err(dev, "Failed to register ahashes\n");
goto unregister_ahashes;
}
}
err = crypto_register_skciphers(crypto_algos, ARRAY_SIZE(crypto_algos));
if (err) {
dev_err(dev, "Failed to register ciphers\n");
goto unregister_a7_ahashes;
}
err = crypto_register_aeads(aead_algos, ARRAY_SIZE(aead_algos));
if (err) {
dev_err(dev, "Failed to register aeads\n");
goto unregister_algs;
}
return 0;
unregister_algs:
crypto_unregister_skciphers(crypto_algos, ARRAY_SIZE(crypto_algos));
unregister_a7_ahashes:
if (variant != ARTPEC6_CRYPTO)
crypto_unregister_ahashes(artpec7_hash_algos,
ARRAY_SIZE(artpec7_hash_algos));
unregister_ahashes:
crypto_unregister_ahashes(hash_algos, ARRAY_SIZE(hash_algos));
disable_hw:
artpec6_crypto_disable_hw(ac);
free_cache:
kmem_cache_destroy(ac->dma_cache);
return err;
}
static int artpec6_crypto_remove(struct platform_device *pdev)
{
struct artpec6_crypto *ac = platform_get_drvdata(pdev);
int irq = platform_get_irq(pdev, 0);
crypto_unregister_ahashes(hash_algos, ARRAY_SIZE(hash_algos));
if (ac->variant != ARTPEC6_CRYPTO)
crypto_unregister_ahashes(artpec7_hash_algos,
ARRAY_SIZE(artpec7_hash_algos));
crypto_unregister_skciphers(crypto_algos, ARRAY_SIZE(crypto_algos));
crypto_unregister_aeads(aead_algos, ARRAY_SIZE(aead_algos));
tasklet_disable(&ac->task);
devm_free_irq(&pdev->dev, irq, ac);
tasklet_kill(&ac->task);
del_timer_sync(&ac->timer);
artpec6_crypto_disable_hw(ac);
kmem_cache_destroy(ac->dma_cache);
#ifdef CONFIG_DEBUG_FS
artpec6_crypto_free_debugfs();
#endif
return 0;
}
