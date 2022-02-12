struct dma_async_tx_descriptor *
async_memset(struct page *dest, int val, unsigned int offset, size_t len,
struct async_submit_ctl *submit)
{
struct dma_chan *chan = async_tx_find_channel(submit, DMA_MEMSET,
&dest, 1, NULL, 0, len);
struct dma_device *device = chan ? chan->device : NULL;
struct dma_async_tx_descriptor *tx = NULL;
if (device && is_dma_fill_aligned(device, offset, 0, len)) {
dma_addr_t dma_dest;
unsigned long dma_prep_flags = 0;
if (submit->cb_fn)
dma_prep_flags |= DMA_PREP_INTERRUPT;
if (submit->flags & ASYNC_TX_FENCE)
dma_prep_flags |= DMA_PREP_FENCE;
dma_dest = dma_map_page(device->dev, dest, offset, len,
DMA_FROM_DEVICE);
tx = device->device_prep_dma_memset(chan, dma_dest, val, len,
dma_prep_flags);
}
if (tx) {
pr_debug("%s: (async) len: %zu\n", __func__, len);
async_tx_submit(chan, tx, submit);
} else {
void *dest_buf;
pr_debug("%s: (sync) len: %zu\n", __func__, len);
dest_buf = page_address(dest) + offset;
async_tx_quiesce(&submit->depend_tx);
memset(dest_buf, val, len);
async_tx_sync_epilog(submit);
}
return tx;
}
