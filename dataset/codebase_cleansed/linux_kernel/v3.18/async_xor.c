void
do_sync_xor(struct page *dest, struct page **src_list, unsigned int offset,
int src_cnt, size_t len, struct async_submit_ctl *submit)
{
int i;
int xor_src_cnt = 0;
int src_off = 0;
void *dest_buf;
void **srcs;
if (submit->scribble)
srcs = submit->scribble;
else
srcs = (void **) src_list;
for (i = 0; i < src_cnt; i++)
if (src_list[i])
srcs[xor_src_cnt++] = page_address(src_list[i]) + offset;
src_cnt = xor_src_cnt;
dest_buf = page_address(dest) + offset;
if (submit->flags & ASYNC_TX_XOR_ZERO_DST)
memset(dest_buf, 0, len);
while (src_cnt > 0) {
xor_src_cnt = min(src_cnt, MAX_XOR_BLOCKS);
xor_blocks(xor_src_cnt, len, dest_buf, &srcs[src_off]);
src_cnt -= xor_src_cnt;
src_off += xor_src_cnt;
}
async_tx_sync_epilog(submit);
}
struct dma_async_tx_descriptor *
async_xor(struct page *dest, struct page **src_list, unsigned int offset,
int src_cnt, size_t len, struct async_submit_ctl *submit)
{
struct dma_chan *chan = async_tx_find_channel(submit, DMA_XOR,
&dest, 1, src_list,
src_cnt, len);
struct dma_device *device = chan ? chan->device : NULL;
struct dmaengine_unmap_data *unmap = NULL;
BUG_ON(src_cnt <= 1);
if (device)
unmap = dmaengine_get_unmap_data(device->dev, src_cnt+1, GFP_NOIO);
if (unmap && is_dma_xor_aligned(device, offset, 0, len)) {
struct dma_async_tx_descriptor *tx;
int i, j;
pr_debug("%s (async): len: %zu\n", __func__, len);
unmap->len = len;
for (i = 0, j = 0; i < src_cnt; i++) {
if (!src_list[i])
continue;
unmap->to_cnt++;
unmap->addr[j++] = dma_map_page(device->dev, src_list[i],
offset, len, DMA_TO_DEVICE);
}
unmap->addr[j] = dma_map_page(device->dev, dest, offset, len,
DMA_BIDIRECTIONAL);
unmap->bidi_cnt = 1;
tx = do_async_xor(chan, unmap, submit);
dmaengine_unmap_put(unmap);
return tx;
} else {
dmaengine_unmap_put(unmap);
pr_debug("%s (sync): len: %zu\n", __func__, len);
WARN_ONCE(chan, "%s: no space for dma address conversion\n",
__func__);
if (submit->flags & ASYNC_TX_XOR_DROP_DST) {
src_cnt--;
src_list++;
}
async_tx_quiesce(&submit->depend_tx);
do_sync_xor(dest, src_list, offset, src_cnt, len, submit);
return NULL;
}
}
static int page_is_zero(struct page *p, unsigned int offset, size_t len)
{
return !memchr_inv(page_address(p) + offset, 0, len);
}
static inline struct dma_chan *
xor_val_chan(struct async_submit_ctl *submit, struct page *dest,
struct page **src_list, int src_cnt, size_t len)
{
#ifdef CONFIG_ASYNC_TX_DISABLE_XOR_VAL_DMA
return NULL;
#endif
return async_tx_find_channel(submit, DMA_XOR_VAL, &dest, 1, src_list,
src_cnt, len);
}
struct dma_async_tx_descriptor *
async_xor_val(struct page *dest, struct page **src_list, unsigned int offset,
int src_cnt, size_t len, enum sum_check_flags *result,
struct async_submit_ctl *submit)
{
struct dma_chan *chan = xor_val_chan(submit, dest, src_list, src_cnt, len);
struct dma_device *device = chan ? chan->device : NULL;
struct dma_async_tx_descriptor *tx = NULL;
struct dmaengine_unmap_data *unmap = NULL;
BUG_ON(src_cnt <= 1);
if (device)
unmap = dmaengine_get_unmap_data(device->dev, src_cnt, GFP_NOIO);
if (unmap && src_cnt <= device->max_xor &&
is_dma_xor_aligned(device, offset, 0, len)) {
unsigned long dma_prep_flags = 0;
int i;
pr_debug("%s: (async) len: %zu\n", __func__, len);
if (submit->cb_fn)
dma_prep_flags |= DMA_PREP_INTERRUPT;
if (submit->flags & ASYNC_TX_FENCE)
dma_prep_flags |= DMA_PREP_FENCE;
for (i = 0; i < src_cnt; i++) {
unmap->addr[i] = dma_map_page(device->dev, src_list[i],
offset, len, DMA_TO_DEVICE);
unmap->to_cnt++;
}
unmap->len = len;
tx = device->device_prep_dma_xor_val(chan, unmap->addr, src_cnt,
len, result,
dma_prep_flags);
if (unlikely(!tx)) {
async_tx_quiesce(&submit->depend_tx);
while (!tx) {
dma_async_issue_pending(chan);
tx = device->device_prep_dma_xor_val(chan,
unmap->addr, src_cnt, len, result,
dma_prep_flags);
}
}
dma_set_unmap(tx, unmap);
async_tx_submit(chan, tx, submit);
} else {
enum async_tx_flags flags_orig = submit->flags;
pr_debug("%s: (sync) len: %zu\n", __func__, len);
WARN_ONCE(device && src_cnt <= device->max_xor,
"%s: no space for dma address conversion\n",
__func__);
submit->flags |= ASYNC_TX_XOR_DROP_DST;
submit->flags &= ~ASYNC_TX_ACK;
tx = async_xor(dest, src_list, offset, src_cnt, len, submit);
async_tx_quiesce(&tx);
*result = !page_is_zero(dest, offset, len) << SUM_CHECK_P;
async_tx_sync_epilog(submit);
submit->flags = flags_orig;
}
dmaengine_unmap_put(unmap);
return tx;
}
