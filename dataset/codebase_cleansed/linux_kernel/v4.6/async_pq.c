void
do_sync_gen_syndrome(struct page **blocks, unsigned int offset, int disks,
size_t len, struct async_submit_ctl *submit)
{
void **srcs;
int i;
int start = -1, stop = disks - 3;
if (submit->scribble)
srcs = submit->scribble;
else
srcs = (void **) blocks;
for (i = 0; i < disks; i++) {
if (blocks[i] == NULL) {
BUG_ON(i > disks - 3);
srcs[i] = (void*)raid6_empty_zero_page;
} else {
srcs[i] = page_address(blocks[i]) + offset;
if (i < disks - 2) {
stop = i;
if (start == -1)
start = i;
}
}
}
if (submit->flags & ASYNC_TX_PQ_XOR_DST) {
BUG_ON(!raid6_call.xor_syndrome);
if (start >= 0)
raid6_call.xor_syndrome(disks, start, stop, len, srcs);
} else
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
struct dmaengine_unmap_data *unmap = NULL;
BUG_ON(disks > 255 || !(P(blocks, disks) || Q(blocks, disks)));
if (device)
unmap = dmaengine_get_unmap_data(device->dev, disks, GFP_NOWAIT);
if (unmap && !(submit->flags & ASYNC_TX_PQ_XOR_DST) &&
(src_cnt <= dma_maxpq(device, 0) ||
dma_maxpq(device, DMA_PREP_CONTINUE) > 0) &&
is_dma_pq_aligned(device, offset, 0, len)) {
struct dma_async_tx_descriptor *tx;
enum dma_ctrl_flags dma_flags = 0;
unsigned char coefs[src_cnt];
int i, j;
pr_debug("%s: (async) disks: %d len: %zu\n",
__func__, disks, len);
unmap->len = len;
for (i = 0, j = 0; i < src_cnt; i++) {
if (blocks[i] == NULL)
continue;
unmap->addr[j] = dma_map_page(device->dev, blocks[i], offset,
len, DMA_TO_DEVICE);
coefs[j] = raid6_gfexp[i];
unmap->to_cnt++;
j++;
}
unmap->bidi_cnt++;
if (P(blocks, disks))
unmap->addr[j++] = dma_map_page(device->dev, P(blocks, disks),
offset, len, DMA_BIDIRECTIONAL);
else {
unmap->addr[j++] = 0;
dma_flags |= DMA_PREP_PQ_DISABLE_P;
}
unmap->bidi_cnt++;
if (Q(blocks, disks))
unmap->addr[j++] = dma_map_page(device->dev, Q(blocks, disks),
offset, len, DMA_BIDIRECTIONAL);
else {
unmap->addr[j++] = 0;
dma_flags |= DMA_PREP_PQ_DISABLE_Q;
}
tx = do_async_gen_syndrome(chan, coefs, j, unmap, dma_flags, submit);
dmaengine_unmap_put(unmap);
return tx;
}
dmaengine_unmap_put(unmap);
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
struct dmaengine_unmap_data *unmap = NULL;
BUG_ON(disks < 4);
if (device)
unmap = dmaengine_get_unmap_data(device->dev, disks, GFP_NOWAIT);
if (unmap && disks <= dma_maxpq(device, 0) &&
is_dma_pq_aligned(device, offset, 0, len)) {
struct device *dev = device->dev;
dma_addr_t pq[2];
int i, j = 0, src_cnt = 0;
pr_debug("%s: (async) disks: %d len: %zu\n",
__func__, disks, len);
unmap->len = len;
for (i = 0; i < disks-2; i++)
if (likely(blocks[i])) {
unmap->addr[j] = dma_map_page(dev, blocks[i],
offset, len,
DMA_TO_DEVICE);
coefs[j] = raid6_gfexp[i];
unmap->to_cnt++;
src_cnt++;
j++;
}
if (!P(blocks, disks)) {
pq[0] = 0;
dma_flags |= DMA_PREP_PQ_DISABLE_P;
} else {
pq[0] = dma_map_page(dev, P(blocks, disks),
offset, len,
DMA_TO_DEVICE);
unmap->addr[j++] = pq[0];
unmap->to_cnt++;
}
if (!Q(blocks, disks)) {
pq[1] = 0;
dma_flags |= DMA_PREP_PQ_DISABLE_Q;
} else {
pq[1] = dma_map_page(dev, Q(blocks, disks),
offset, len,
DMA_TO_DEVICE);
unmap->addr[j++] = pq[1];
unmap->to_cnt++;
}
if (submit->flags & ASYNC_TX_FENCE)
dma_flags |= DMA_PREP_FENCE;
for (;;) {
tx = device->device_prep_dma_pq_val(chan, pq,
unmap->addr,
src_cnt,
coefs,
len, pqres,
dma_flags);
if (likely(tx))
break;
async_tx_quiesce(&submit->depend_tx);
dma_async_issue_pending(chan);
}
dma_set_unmap(tx, unmap);
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
__free_page(pq_scribble_page);
}
