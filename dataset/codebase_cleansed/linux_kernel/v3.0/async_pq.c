void
do_sync_gen_syndrome(struct page **blocks, unsigned int offset, int disks,
size_t len, struct async_submit_ctl *submit)
{
void **srcs;
int i;
if (submit->scribble)
srcs = submit->scribble;
else
srcs = (void **) blocks;
for (i = 0; i < disks; i++) {
if (blocks[i] == NULL) {
BUG_ON(i > disks - 3);
srcs[i] = (void*)raid6_empty_zero_page;
} else
srcs[i] = page_address(blocks[i]) + offset;
}
raid6_call.gen_syndrome(disks, len, srcs);
async_tx_sync_epilog(submit);
}
struct dma_async_tx_descriptor *
async_gen_syndrome(struct page **blocks, unsigned int offset, int disks,
size_t len, struct async_submit_ctl *submit)
{
int src_cnt = disks - 2;
struct dma_chan *chan = async_tx_find_channel(submit, DMA_PQ,
&P(blocks, disks), 2,
blocks, src_cnt, len);
struct dma_device *device = chan ? chan->device : NULL;
dma_addr_t *dma_src = NULL;
BUG_ON(disks > 255 || !(P(blocks, disks) || Q(blocks, disks)));
if (submit->scribble)
dma_src = submit->scribble;
else if (sizeof(dma_addr_t) <= sizeof(struct page *))
dma_src = (dma_addr_t *) blocks;
if (dma_src && device &&
(src_cnt <= dma_maxpq(device, 0) ||
dma_maxpq(device, DMA_PREP_CONTINUE) > 0) &&
is_dma_pq_aligned(device, offset, 0, len)) {
pr_debug("%s: (async) disks: %d len: %zu\n",
__func__, disks, len);
return do_async_gen_syndrome(chan, blocks, raid6_gfexp, offset,
disks, len, dma_src, submit);
}
pr_debug("%s: (sync) disks: %d len: %zu\n", __func__, disks, len);
async_tx_quiesce(&submit->depend_tx);
if (!P(blocks, disks)) {
P(blocks, disks) = pq_scribble_page;
BUG_ON(len + offset > PAGE_SIZE);
}
if (!Q(blocks, disks)) {
Q(blocks, disks) = pq_scribble_page;
BUG_ON(len + offset > PAGE_SIZE);
}
do_sync_gen_syndrome(blocks, offset, disks, len, submit);
return NULL;
}
static inline struct dma_chan *
pq_val_chan(struct async_submit_ctl *submit, struct page **blocks, int disks, size_t len)
{
#ifdef CONFIG_ASYNC_TX_DISABLE_PQ_VAL_DMA
return NULL;
#endif
return async_tx_find_channel(submit, DMA_PQ_VAL, NULL, 0, blocks,
disks, len);
}
struct dma_async_tx_descriptor *
async_syndrome_val(struct page **blocks, unsigned int offset, int disks,
size_t len, enum sum_check_flags *pqres, struct page *spare,
struct async_submit_ctl *submit)
{
struct dma_chan *chan = pq_val_chan(submit, blocks, disks, len);
struct dma_device *device = chan ? chan->device : NULL;
struct dma_async_tx_descriptor *tx;
unsigned char coefs[disks-2];
enum dma_ctrl_flags dma_flags = submit->cb_fn ? DMA_PREP_INTERRUPT : 0;
dma_addr_t *dma_src = NULL;
int src_cnt = 0;
BUG_ON(disks < 4);
if (submit->scribble)
dma_src = submit->scribble;
else if (sizeof(dma_addr_t) <= sizeof(struct page *))
dma_src = (dma_addr_t *) blocks;
if (dma_src && device && disks <= dma_maxpq(device, 0) &&
is_dma_pq_aligned(device, offset, 0, len)) {
struct device *dev = device->dev;
dma_addr_t *pq = &dma_src[disks-2];
int i;
pr_debug("%s: (async) disks: %d len: %zu\n",
__func__, disks, len);
if (!P(blocks, disks))
dma_flags |= DMA_PREP_PQ_DISABLE_P;
else
pq[0] = dma_map_page(dev, P(blocks, disks),
offset, len,
DMA_TO_DEVICE);
if (!Q(blocks, disks))
dma_flags |= DMA_PREP_PQ_DISABLE_Q;
else
pq[1] = dma_map_page(dev, Q(blocks, disks),
offset, len,
DMA_TO_DEVICE);
if (submit->flags & ASYNC_TX_FENCE)
dma_flags |= DMA_PREP_FENCE;
for (i = 0; i < disks-2; i++)
if (likely(blocks[i])) {
dma_src[src_cnt] = dma_map_page(dev, blocks[i],
offset, len,
DMA_TO_DEVICE);
coefs[src_cnt] = raid6_gfexp[i];
src_cnt++;
}
for (;;) {
tx = device->device_prep_dma_pq_val(chan, pq, dma_src,
src_cnt,
coefs,
len, pqres,
dma_flags);
if (likely(tx))
break;
async_tx_quiesce(&submit->depend_tx);
dma_async_issue_pending(chan);
}
async_tx_submit(chan, tx, submit);
return tx;
} else {
struct page *p_src = P(blocks, disks);
struct page *q_src = Q(blocks, disks);
enum async_tx_flags flags_orig = submit->flags;
dma_async_tx_callback cb_fn_orig = submit->cb_fn;
void *scribble = submit->scribble;
void *cb_param_orig = submit->cb_param;
void *p, *q, *s;
pr_debug("%s: (sync) disks: %d len: %zu\n",
__func__, disks, len);
BUG_ON(!spare || !scribble);
async_tx_quiesce(&submit->depend_tx);
tx = NULL;
*pqres = 0;
if (p_src) {
init_async_submit(submit, ASYNC_TX_XOR_ZERO_DST, NULL,
NULL, NULL, scribble);
tx = async_xor(spare, blocks, offset, disks-2, len, submit);
async_tx_quiesce(&tx);
p = page_address(p_src) + offset;
s = page_address(spare) + offset;
*pqres |= !!memcmp(p, s, len) << SUM_CHECK_P;
}
if (q_src) {
P(blocks, disks) = NULL;
Q(blocks, disks) = spare;
init_async_submit(submit, 0, NULL, NULL, NULL, scribble);
tx = async_gen_syndrome(blocks, offset, disks, len, submit);
async_tx_quiesce(&tx);
q = page_address(q_src) + offset;
s = page_address(spare) + offset;
*pqres |= !!memcmp(q, s, len) << SUM_CHECK_Q;
}
P(blocks, disks) = p_src;
Q(blocks, disks) = q_src;
submit->cb_fn = cb_fn_orig;
submit->cb_param = cb_param_orig;
submit->flags = flags_orig;
async_tx_sync_epilog(submit);
return NULL;
}
}
static int __init async_pq_init(void)
{
pq_scribble_page = alloc_page(GFP_KERNEL);
if (pq_scribble_page)
return 0;
pr_err("%s: failed to allocate required spare page\n", __func__);
return -ENOMEM;
}
static void __exit async_pq_exit(void)
{
put_page(pq_scribble_page);
}
