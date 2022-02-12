static void rcar_dmac_write(struct rcar_dmac *dmac, u32 reg, u32 data)
{
if (reg == RCAR_DMAOR)
writew(data, dmac->iomem + reg);
else
writel(data, dmac->iomem + reg);
}
static u32 rcar_dmac_read(struct rcar_dmac *dmac, u32 reg)
{
if (reg == RCAR_DMAOR)
return readw(dmac->iomem + reg);
else
return readl(dmac->iomem + reg);
}
static u32 rcar_dmac_chan_read(struct rcar_dmac_chan *chan, u32 reg)
{
if (reg == RCAR_DMARS)
return readw(chan->iomem + reg);
else
return readl(chan->iomem + reg);
}
static void rcar_dmac_chan_write(struct rcar_dmac_chan *chan, u32 reg, u32 data)
{
if (reg == RCAR_DMARS)
writew(data, chan->iomem + reg);
else
writel(data, chan->iomem + reg);
}
static bool rcar_dmac_chan_is_busy(struct rcar_dmac_chan *chan)
{
u32 chcr = rcar_dmac_chan_read(chan, RCAR_DMACHCR);
return (chcr & (RCAR_DMACHCR_DE | RCAR_DMACHCR_TE)) == RCAR_DMACHCR_DE;
}
static void rcar_dmac_chan_start_xfer(struct rcar_dmac_chan *chan)
{
struct rcar_dmac_desc *desc = chan->desc.running;
u32 chcr = desc->chcr;
WARN_ON_ONCE(rcar_dmac_chan_is_busy(chan));
if (chan->mid_rid >= 0)
rcar_dmac_chan_write(chan, RCAR_DMARS, chan->mid_rid);
if (desc->hwdescs.use) {
struct rcar_dmac_xfer_chunk *chunk;
dev_dbg(chan->chan.device->dev,
"chan%u: queue desc %p: %u@%pad\n",
chan->index, desc, desc->nchunks, &desc->hwdescs.dma);
#ifdef CONFIG_ARCH_DMA_ADDR_T_64BIT
rcar_dmac_chan_write(chan, RCAR_DMAFIXDPBASE,
desc->hwdescs.dma >> 32);
#endif
rcar_dmac_chan_write(chan, RCAR_DMADPBASE,
(desc->hwdescs.dma & 0xfffffff0) |
RCAR_DMADPBASE_SEL);
rcar_dmac_chan_write(chan, RCAR_DMACHCRB,
RCAR_DMACHCRB_DCNT(desc->nchunks - 1) |
RCAR_DMACHCRB_DRST);
chunk = list_first_entry(&desc->chunks,
struct rcar_dmac_xfer_chunk, node);
rcar_dmac_chan_write(chan, RCAR_DMADAR,
chunk->dst_addr & 0xffffffff);
rcar_dmac_chan_write(chan, RCAR_DMADPCR, RCAR_DMADPCR_DIPT(1));
chcr |= RCAR_DMACHCR_RPT_SAR | RCAR_DMACHCR_RPT_DAR
| RCAR_DMACHCR_RPT_TCR | RCAR_DMACHCR_DPB;
if (!desc->cyclic)
chcr |= RCAR_DMACHCR_DPM_ENABLED | RCAR_DMACHCR_IE;
else if (desc->async_tx.callback)
chcr |= RCAR_DMACHCR_DPM_INFINITE | RCAR_DMACHCR_DSIE;
else
chcr |= RCAR_DMACHCR_DPM_INFINITE;
} else {
struct rcar_dmac_xfer_chunk *chunk = desc->running;
dev_dbg(chan->chan.device->dev,
"chan%u: queue chunk %p: %u@%pad -> %pad\n",
chan->index, chunk, chunk->size, &chunk->src_addr,
&chunk->dst_addr);
#ifdef CONFIG_ARCH_DMA_ADDR_T_64BIT
rcar_dmac_chan_write(chan, RCAR_DMAFIXSAR,
chunk->src_addr >> 32);
rcar_dmac_chan_write(chan, RCAR_DMAFIXDAR,
chunk->dst_addr >> 32);
#endif
rcar_dmac_chan_write(chan, RCAR_DMASAR,
chunk->src_addr & 0xffffffff);
rcar_dmac_chan_write(chan, RCAR_DMADAR,
chunk->dst_addr & 0xffffffff);
rcar_dmac_chan_write(chan, RCAR_DMATCR,
chunk->size >> desc->xfer_shift);
chcr |= RCAR_DMACHCR_DPM_DISABLED | RCAR_DMACHCR_IE;
}
rcar_dmac_chan_write(chan, RCAR_DMACHCR, chcr | RCAR_DMACHCR_DE);
}
static int rcar_dmac_init(struct rcar_dmac *dmac)
{
u16 dmaor;
rcar_dmac_write(dmac, RCAR_DMACHCLR, GENMASK(dmac->n_channels - 1, 0));
rcar_dmac_write(dmac, RCAR_DMAOR,
RCAR_DMAOR_PRI_FIXED | RCAR_DMAOR_DME);
dmaor = rcar_dmac_read(dmac, RCAR_DMAOR);
if ((dmaor & (RCAR_DMAOR_AE | RCAR_DMAOR_DME)) != RCAR_DMAOR_DME) {
dev_warn(dmac->dev, "DMAOR initialization failed.\n");
return -EIO;
}
return 0;
}
static dma_cookie_t rcar_dmac_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct rcar_dmac_chan *chan = to_rcar_dmac_chan(tx->chan);
struct rcar_dmac_desc *desc = to_rcar_dmac_desc(tx);
unsigned long flags;
dma_cookie_t cookie;
spin_lock_irqsave(&chan->lock, flags);
cookie = dma_cookie_assign(tx);
dev_dbg(chan->chan.device->dev, "chan%u: submit #%d@%p\n",
chan->index, tx->cookie, desc);
list_add_tail(&desc->node, &chan->desc.pending);
desc->running = list_first_entry(&desc->chunks,
struct rcar_dmac_xfer_chunk, node);
spin_unlock_irqrestore(&chan->lock, flags);
return cookie;
}
static int rcar_dmac_desc_alloc(struct rcar_dmac_chan *chan, gfp_t gfp)
{
struct rcar_dmac_desc_page *page;
unsigned long flags;
LIST_HEAD(list);
unsigned int i;
page = (void *)get_zeroed_page(gfp);
if (!page)
return -ENOMEM;
for (i = 0; i < RCAR_DMAC_DESCS_PER_PAGE; ++i) {
struct rcar_dmac_desc *desc = &page->descs[i];
dma_async_tx_descriptor_init(&desc->async_tx, &chan->chan);
desc->async_tx.tx_submit = rcar_dmac_tx_submit;
INIT_LIST_HEAD(&desc->chunks);
list_add_tail(&desc->node, &list);
}
spin_lock_irqsave(&chan->lock, flags);
list_splice_tail(&list, &chan->desc.free);
list_add_tail(&page->node, &chan->desc.pages);
spin_unlock_irqrestore(&chan->lock, flags);
return 0;
}
static void rcar_dmac_desc_put(struct rcar_dmac_chan *chan,
struct rcar_dmac_desc *desc)
{
unsigned long flags;
spin_lock_irqsave(&chan->lock, flags);
list_splice_tail_init(&desc->chunks, &chan->desc.chunks_free);
list_add_tail(&desc->node, &chan->desc.free);
spin_unlock_irqrestore(&chan->lock, flags);
}
static void rcar_dmac_desc_recycle_acked(struct rcar_dmac_chan *chan)
{
struct rcar_dmac_desc *desc, *_desc;
unsigned long flags;
LIST_HEAD(list);
spin_lock_irqsave(&chan->lock, flags);
list_splice_init(&chan->desc.wait, &list);
spin_unlock_irqrestore(&chan->lock, flags);
list_for_each_entry_safe(desc, _desc, &list, node) {
if (async_tx_test_ack(&desc->async_tx)) {
list_del(&desc->node);
rcar_dmac_desc_put(chan, desc);
}
}
if (list_empty(&list))
return;
spin_lock_irqsave(&chan->lock, flags);
list_splice(&list, &chan->desc.wait);
spin_unlock_irqrestore(&chan->lock, flags);
}
static struct rcar_dmac_desc *rcar_dmac_desc_get(struct rcar_dmac_chan *chan)
{
struct rcar_dmac_desc *desc;
unsigned long flags;
int ret;
rcar_dmac_desc_recycle_acked(chan);
spin_lock_irqsave(&chan->lock, flags);
while (list_empty(&chan->desc.free)) {
spin_unlock_irqrestore(&chan->lock, flags);
ret = rcar_dmac_desc_alloc(chan, GFP_NOWAIT);
if (ret < 0)
return NULL;
spin_lock_irqsave(&chan->lock, flags);
}
desc = list_first_entry(&chan->desc.free, struct rcar_dmac_desc, node);
list_del(&desc->node);
spin_unlock_irqrestore(&chan->lock, flags);
return desc;
}
static int rcar_dmac_xfer_chunk_alloc(struct rcar_dmac_chan *chan, gfp_t gfp)
{
struct rcar_dmac_desc_page *page;
unsigned long flags;
LIST_HEAD(list);
unsigned int i;
page = (void *)get_zeroed_page(gfp);
if (!page)
return -ENOMEM;
for (i = 0; i < RCAR_DMAC_XFER_CHUNKS_PER_PAGE; ++i) {
struct rcar_dmac_xfer_chunk *chunk = &page->chunks[i];
list_add_tail(&chunk->node, &list);
}
spin_lock_irqsave(&chan->lock, flags);
list_splice_tail(&list, &chan->desc.chunks_free);
list_add_tail(&page->node, &chan->desc.pages);
spin_unlock_irqrestore(&chan->lock, flags);
return 0;
}
static struct rcar_dmac_xfer_chunk *
rcar_dmac_xfer_chunk_get(struct rcar_dmac_chan *chan)
{
struct rcar_dmac_xfer_chunk *chunk;
unsigned long flags;
int ret;
spin_lock_irqsave(&chan->lock, flags);
while (list_empty(&chan->desc.chunks_free)) {
spin_unlock_irqrestore(&chan->lock, flags);
ret = rcar_dmac_xfer_chunk_alloc(chan, GFP_NOWAIT);
if (ret < 0)
return NULL;
spin_lock_irqsave(&chan->lock, flags);
}
chunk = list_first_entry(&chan->desc.chunks_free,
struct rcar_dmac_xfer_chunk, node);
list_del(&chunk->node);
spin_unlock_irqrestore(&chan->lock, flags);
return chunk;
}
static void rcar_dmac_realloc_hwdesc(struct rcar_dmac_chan *chan,
struct rcar_dmac_desc *desc, size_t size)
{
size = PAGE_ALIGN(size);
if (desc->hwdescs.size == size)
return;
if (desc->hwdescs.mem) {
dma_free_coherent(chan->chan.device->dev, desc->hwdescs.size,
desc->hwdescs.mem, desc->hwdescs.dma);
desc->hwdescs.mem = NULL;
desc->hwdescs.size = 0;
}
if (!size)
return;
desc->hwdescs.mem = dma_alloc_coherent(chan->chan.device->dev, size,
&desc->hwdescs.dma, GFP_NOWAIT);
if (!desc->hwdescs.mem)
return;
desc->hwdescs.size = size;
}
static int rcar_dmac_fill_hwdesc(struct rcar_dmac_chan *chan,
struct rcar_dmac_desc *desc)
{
struct rcar_dmac_xfer_chunk *chunk;
struct rcar_dmac_hw_desc *hwdesc;
rcar_dmac_realloc_hwdesc(chan, desc, desc->nchunks * sizeof(*hwdesc));
hwdesc = desc->hwdescs.mem;
if (!hwdesc)
return -ENOMEM;
list_for_each_entry(chunk, &desc->chunks, node) {
hwdesc->sar = chunk->src_addr;
hwdesc->dar = chunk->dst_addr;
hwdesc->tcr = chunk->size >> desc->xfer_shift;
hwdesc++;
}
return 0;
}
static void rcar_dmac_chan_halt(struct rcar_dmac_chan *chan)
{
u32 chcr = rcar_dmac_chan_read(chan, RCAR_DMACHCR);
chcr &= ~(RCAR_DMACHCR_DSE | RCAR_DMACHCR_DSIE | RCAR_DMACHCR_IE |
RCAR_DMACHCR_TE | RCAR_DMACHCR_DE);
rcar_dmac_chan_write(chan, RCAR_DMACHCR, chcr);
}
static void rcar_dmac_chan_reinit(struct rcar_dmac_chan *chan)
{
struct rcar_dmac_desc *desc, *_desc;
unsigned long flags;
LIST_HEAD(descs);
spin_lock_irqsave(&chan->lock, flags);
list_splice_init(&chan->desc.pending, &descs);
list_splice_init(&chan->desc.active, &descs);
list_splice_init(&chan->desc.done, &descs);
list_splice_init(&chan->desc.wait, &descs);
chan->desc.running = NULL;
spin_unlock_irqrestore(&chan->lock, flags);
list_for_each_entry_safe(desc, _desc, &descs, node) {
list_del(&desc->node);
rcar_dmac_desc_put(chan, desc);
}
}
static void rcar_dmac_stop(struct rcar_dmac *dmac)
{
rcar_dmac_write(dmac, RCAR_DMAOR, 0);
}
static void rcar_dmac_abort(struct rcar_dmac *dmac)
{
unsigned int i;
for (i = 0; i < dmac->n_channels; ++i) {
struct rcar_dmac_chan *chan = &dmac->channels[i];
spin_lock(&chan->lock);
rcar_dmac_chan_halt(chan);
spin_unlock(&chan->lock);
rcar_dmac_chan_reinit(chan);
}
}
static void rcar_dmac_chan_configure_desc(struct rcar_dmac_chan *chan,
struct rcar_dmac_desc *desc)
{
static const u32 chcr_ts[] = {
RCAR_DMACHCR_TS_1B, RCAR_DMACHCR_TS_2B,
RCAR_DMACHCR_TS_4B, RCAR_DMACHCR_TS_8B,
RCAR_DMACHCR_TS_16B, RCAR_DMACHCR_TS_32B,
RCAR_DMACHCR_TS_64B,
};
unsigned int xfer_size;
u32 chcr;
switch (desc->direction) {
case DMA_DEV_TO_MEM:
chcr = RCAR_DMACHCR_DM_INC | RCAR_DMACHCR_SM_FIXED
| RCAR_DMACHCR_RS_DMARS;
xfer_size = chan->src_xfer_size;
break;
case DMA_MEM_TO_DEV:
chcr = RCAR_DMACHCR_DM_FIXED | RCAR_DMACHCR_SM_INC
| RCAR_DMACHCR_RS_DMARS;
xfer_size = chan->dst_xfer_size;
break;
case DMA_MEM_TO_MEM:
default:
chcr = RCAR_DMACHCR_DM_INC | RCAR_DMACHCR_SM_INC
| RCAR_DMACHCR_RS_AUTO;
xfer_size = RCAR_DMAC_MEMCPY_XFER_SIZE;
break;
}
desc->xfer_shift = ilog2(xfer_size);
desc->chcr = chcr | chcr_ts[desc->xfer_shift];
}
static struct dma_async_tx_descriptor *
rcar_dmac_chan_prep_sg(struct rcar_dmac_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, dma_addr_t dev_addr,
enum dma_transfer_direction dir, unsigned long dma_flags,
bool cyclic)
{
struct rcar_dmac_xfer_chunk *chunk;
struct rcar_dmac_desc *desc;
struct scatterlist *sg;
unsigned int nchunks = 0;
unsigned int max_chunk_size;
unsigned int full_size = 0;
bool highmem = false;
unsigned int i;
desc = rcar_dmac_desc_get(chan);
if (!desc)
return NULL;
desc->async_tx.flags = dma_flags;
desc->async_tx.cookie = -EBUSY;
desc->cyclic = cyclic;
desc->direction = dir;
rcar_dmac_chan_configure_desc(chan, desc);
max_chunk_size = (RCAR_DMATCR_MASK + 1) << desc->xfer_shift;
for_each_sg(sgl, sg, sg_len, i) {
dma_addr_t mem_addr = sg_dma_address(sg);
unsigned int len = sg_dma_len(sg);
full_size += len;
while (len) {
unsigned int size = min(len, max_chunk_size);
#ifdef CONFIG_ARCH_DMA_ADDR_T_64BIT
if (dev_addr >> 32 != (dev_addr + size - 1) >> 32)
size = ALIGN(dev_addr, 1ULL << 32) - dev_addr;
if (mem_addr >> 32 != (mem_addr + size - 1) >> 32)
size = ALIGN(mem_addr, 1ULL << 32) - mem_addr;
if (dev_addr >> 32 || mem_addr >> 32)
highmem = true;
#endif
chunk = rcar_dmac_xfer_chunk_get(chan);
if (!chunk) {
rcar_dmac_desc_put(chan, desc);
return NULL;
}
if (dir == DMA_DEV_TO_MEM) {
chunk->src_addr = dev_addr;
chunk->dst_addr = mem_addr;
} else {
chunk->src_addr = mem_addr;
chunk->dst_addr = dev_addr;
}
chunk->size = size;
dev_dbg(chan->chan.device->dev,
"chan%u: chunk %p/%p sgl %u@%p, %u/%u %pad -> %pad\n",
chan->index, chunk, desc, i, sg, size, len,
&chunk->src_addr, &chunk->dst_addr);
mem_addr += size;
if (dir == DMA_MEM_TO_MEM)
dev_addr += size;
len -= size;
list_add_tail(&chunk->node, &desc->chunks);
nchunks++;
}
}
desc->nchunks = nchunks;
desc->size = full_size;
desc->hwdescs.use = !highmem && nchunks > 1;
if (desc->hwdescs.use) {
if (rcar_dmac_fill_hwdesc(chan, desc) < 0)
desc->hwdescs.use = false;
}
return &desc->async_tx;
}
static int rcar_dmac_alloc_chan_resources(struct dma_chan *chan)
{
struct rcar_dmac_chan *rchan = to_rcar_dmac_chan(chan);
int ret;
INIT_LIST_HEAD(&rchan->desc.chunks_free);
INIT_LIST_HEAD(&rchan->desc.pages);
ret = rcar_dmac_xfer_chunk_alloc(rchan, GFP_KERNEL);
if (ret < 0)
return -ENOMEM;
ret = rcar_dmac_desc_alloc(rchan, GFP_KERNEL);
if (ret < 0)
return -ENOMEM;
return pm_runtime_get_sync(chan->device->dev);
}
static void rcar_dmac_free_chan_resources(struct dma_chan *chan)
{
struct rcar_dmac_chan *rchan = to_rcar_dmac_chan(chan);
struct rcar_dmac *dmac = to_rcar_dmac(chan->device);
struct rcar_dmac_desc_page *page, *_page;
struct rcar_dmac_desc *desc;
LIST_HEAD(list);
spin_lock_irq(&rchan->lock);
rcar_dmac_chan_halt(rchan);
spin_unlock_irq(&rchan->lock);
if (rchan->mid_rid >= 0) {
clear_bit(rchan->mid_rid, dmac->modules);
rchan->mid_rid = -EINVAL;
}
list_splice_init(&rchan->desc.free, &list);
list_splice_init(&rchan->desc.pending, &list);
list_splice_init(&rchan->desc.active, &list);
list_splice_init(&rchan->desc.done, &list);
list_splice_init(&rchan->desc.wait, &list);
list_for_each_entry(desc, &list, node)
rcar_dmac_realloc_hwdesc(rchan, desc, 0);
list_for_each_entry_safe(page, _page, &rchan->desc.pages, node) {
list_del(&page->node);
free_page((unsigned long)page);
}
pm_runtime_put(chan->device->dev);
}
static struct dma_async_tx_descriptor *
rcar_dmac_prep_dma_memcpy(struct dma_chan *chan, dma_addr_t dma_dest,
dma_addr_t dma_src, size_t len, unsigned long flags)
{
struct rcar_dmac_chan *rchan = to_rcar_dmac_chan(chan);
struct scatterlist sgl;
if (!len)
return NULL;
sg_init_table(&sgl, 1);
sg_set_page(&sgl, pfn_to_page(PFN_DOWN(dma_src)), len,
offset_in_page(dma_src));
sg_dma_address(&sgl) = dma_src;
sg_dma_len(&sgl) = len;
return rcar_dmac_chan_prep_sg(rchan, &sgl, 1, dma_dest,
DMA_MEM_TO_MEM, flags, false);
}
static struct dma_async_tx_descriptor *
rcar_dmac_prep_slave_sg(struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction dir,
unsigned long flags, void *context)
{
struct rcar_dmac_chan *rchan = to_rcar_dmac_chan(chan);
dma_addr_t dev_addr;
if (rchan->mid_rid < 0 || !sg_len) {
dev_warn(chan->device->dev,
"%s: bad parameter: len=%d, id=%d\n",
__func__, sg_len, rchan->mid_rid);
return NULL;
}
dev_addr = dir == DMA_DEV_TO_MEM
? rchan->src_slave_addr : rchan->dst_slave_addr;
return rcar_dmac_chan_prep_sg(rchan, sgl, sg_len, dev_addr,
dir, flags, false);
}
static struct dma_async_tx_descriptor *
rcar_dmac_prep_dma_cyclic(struct dma_chan *chan, dma_addr_t buf_addr,
size_t buf_len, size_t period_len,
enum dma_transfer_direction dir, unsigned long flags)
{
struct rcar_dmac_chan *rchan = to_rcar_dmac_chan(chan);
struct dma_async_tx_descriptor *desc;
struct scatterlist *sgl;
dma_addr_t dev_addr;
unsigned int sg_len;
unsigned int i;
if (rchan->mid_rid < 0 || buf_len < period_len) {
dev_warn(chan->device->dev,
"%s: bad parameter: buf_len=%zu, period_len=%zu, id=%d\n",
__func__, buf_len, period_len, rchan->mid_rid);
return NULL;
}
sg_len = buf_len / period_len;
if (sg_len > RCAR_DMAC_MAX_SG_LEN) {
dev_err(chan->device->dev,
"chan%u: sg length %d exceds limit %d",
rchan->index, sg_len, RCAR_DMAC_MAX_SG_LEN);
return NULL;
}
sgl = kcalloc(sg_len, sizeof(*sgl), GFP_NOWAIT);
if (!sgl)
return NULL;
sg_init_table(sgl, sg_len);
for (i = 0; i < sg_len; ++i) {
dma_addr_t src = buf_addr + (period_len * i);
sg_set_page(&sgl[i], pfn_to_page(PFN_DOWN(src)), period_len,
offset_in_page(src));
sg_dma_address(&sgl[i]) = src;
sg_dma_len(&sgl[i]) = period_len;
}
dev_addr = dir == DMA_DEV_TO_MEM
? rchan->src_slave_addr : rchan->dst_slave_addr;
desc = rcar_dmac_chan_prep_sg(rchan, sgl, sg_len, dev_addr,
dir, flags, true);
kfree(sgl);
return desc;
}
static int rcar_dmac_device_config(struct dma_chan *chan,
struct dma_slave_config *cfg)
{
struct rcar_dmac_chan *rchan = to_rcar_dmac_chan(chan);
rchan->src_slave_addr = cfg->src_addr;
rchan->dst_slave_addr = cfg->dst_addr;
rchan->src_xfer_size = cfg->src_addr_width;
rchan->dst_xfer_size = cfg->dst_addr_width;
return 0;
}
static int rcar_dmac_chan_terminate_all(struct dma_chan *chan)
{
struct rcar_dmac_chan *rchan = to_rcar_dmac_chan(chan);
unsigned long flags;
spin_lock_irqsave(&rchan->lock, flags);
rcar_dmac_chan_halt(rchan);
spin_unlock_irqrestore(&rchan->lock, flags);
rcar_dmac_chan_reinit(rchan);
return 0;
}
static unsigned int rcar_dmac_chan_get_residue(struct rcar_dmac_chan *chan,
dma_cookie_t cookie)
{
struct rcar_dmac_desc *desc = chan->desc.running;
struct rcar_dmac_xfer_chunk *running = NULL;
struct rcar_dmac_xfer_chunk *chunk;
unsigned int residue = 0;
unsigned int dptr = 0;
if (!desc)
return 0;
if (cookie != desc->async_tx.cookie)
return desc->size;
if (desc->hwdescs.use) {
dptr = (rcar_dmac_chan_read(chan, RCAR_DMACHCRB) &
RCAR_DMACHCRB_DPTR_MASK) >> RCAR_DMACHCRB_DPTR_SHIFT;
WARN_ON(dptr >= desc->nchunks);
} else {
running = desc->running;
}
list_for_each_entry_reverse(chunk, &desc->chunks, node) {
if (chunk == running || ++dptr == desc->nchunks)
break;
residue += chunk->size;
}
residue += rcar_dmac_chan_read(chan, RCAR_DMATCR) << desc->xfer_shift;
return residue;
}
static enum dma_status rcar_dmac_tx_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct rcar_dmac_chan *rchan = to_rcar_dmac_chan(chan);
enum dma_status status;
unsigned long flags;
unsigned int residue;
status = dma_cookie_status(chan, cookie, txstate);
if (status == DMA_COMPLETE || !txstate)
return status;
spin_lock_irqsave(&rchan->lock, flags);
residue = rcar_dmac_chan_get_residue(rchan, cookie);
spin_unlock_irqrestore(&rchan->lock, flags);
dma_set_residue(txstate, residue);
return status;
}
static void rcar_dmac_issue_pending(struct dma_chan *chan)
{
struct rcar_dmac_chan *rchan = to_rcar_dmac_chan(chan);
unsigned long flags;
spin_lock_irqsave(&rchan->lock, flags);
if (list_empty(&rchan->desc.pending))
goto done;
list_splice_tail_init(&rchan->desc.pending, &rchan->desc.active);
if (!rchan->desc.running) {
struct rcar_dmac_desc *desc;
desc = list_first_entry(&rchan->desc.active,
struct rcar_dmac_desc, node);
rchan->desc.running = desc;
rcar_dmac_chan_start_xfer(rchan);
}
done:
spin_unlock_irqrestore(&rchan->lock, flags);
}
static irqreturn_t rcar_dmac_isr_desc_stage_end(struct rcar_dmac_chan *chan)
{
struct rcar_dmac_desc *desc = chan->desc.running;
unsigned int stage;
if (WARN_ON(!desc || !desc->cyclic)) {
return IRQ_NONE;
}
stage = (rcar_dmac_chan_read(chan, RCAR_DMACHCRB) &
RCAR_DMACHCRB_DPTR_MASK) >> RCAR_DMACHCRB_DPTR_SHIFT;
rcar_dmac_chan_write(chan, RCAR_DMADPCR, RCAR_DMADPCR_DIPT(stage));
return IRQ_WAKE_THREAD;
}
static irqreturn_t rcar_dmac_isr_transfer_end(struct rcar_dmac_chan *chan)
{
struct rcar_dmac_desc *desc = chan->desc.running;
irqreturn_t ret = IRQ_WAKE_THREAD;
if (WARN_ON_ONCE(!desc)) {
return IRQ_NONE;
}
if (!desc->hwdescs.use) {
if (!list_is_last(&desc->running->node, &desc->chunks)) {
desc->running = list_next_entry(desc->running, node);
if (!desc->cyclic)
ret = IRQ_HANDLED;
goto done;
}
if (desc->cyclic) {
desc->running =
list_first_entry(&desc->chunks,
struct rcar_dmac_xfer_chunk,
node);
goto done;
}
}
list_move_tail(&desc->node, &chan->desc.done);
if (!list_empty(&chan->desc.active))
chan->desc.running = list_first_entry(&chan->desc.active,
struct rcar_dmac_desc,
node);
else
chan->desc.running = NULL;
done:
if (chan->desc.running)
rcar_dmac_chan_start_xfer(chan);
return ret;
}
static irqreturn_t rcar_dmac_isr_channel(int irq, void *dev)
{
u32 mask = RCAR_DMACHCR_DSE | RCAR_DMACHCR_TE;
struct rcar_dmac_chan *chan = dev;
irqreturn_t ret = IRQ_NONE;
u32 chcr;
spin_lock(&chan->lock);
chcr = rcar_dmac_chan_read(chan, RCAR_DMACHCR);
if (chcr & RCAR_DMACHCR_TE)
mask |= RCAR_DMACHCR_DE;
rcar_dmac_chan_write(chan, RCAR_DMACHCR, chcr & ~mask);
if (chcr & RCAR_DMACHCR_DSE)
ret |= rcar_dmac_isr_desc_stage_end(chan);
if (chcr & RCAR_DMACHCR_TE)
ret |= rcar_dmac_isr_transfer_end(chan);
spin_unlock(&chan->lock);
return ret;
}
static irqreturn_t rcar_dmac_isr_channel_thread(int irq, void *dev)
{
struct rcar_dmac_chan *chan = dev;
struct rcar_dmac_desc *desc;
spin_lock_irq(&chan->lock);
if (chan->desc.running && chan->desc.running->cyclic) {
dma_async_tx_callback callback;
void *callback_param;
desc = chan->desc.running;
callback = desc->async_tx.callback;
callback_param = desc->async_tx.callback_param;
if (callback) {
spin_unlock_irq(&chan->lock);
callback(callback_param);
spin_lock_irq(&chan->lock);
}
}
while (!list_empty(&chan->desc.done)) {
desc = list_first_entry(&chan->desc.done, struct rcar_dmac_desc,
node);
dma_cookie_complete(&desc->async_tx);
list_del(&desc->node);
if (desc->async_tx.callback) {
spin_unlock_irq(&chan->lock);
desc->async_tx.callback(desc->async_tx.callback_param);
spin_lock_irq(&chan->lock);
}
list_add_tail(&desc->node, &chan->desc.wait);
}
spin_unlock_irq(&chan->lock);
rcar_dmac_desc_recycle_acked(chan);
return IRQ_HANDLED;
}
static irqreturn_t rcar_dmac_isr_error(int irq, void *data)
{
struct rcar_dmac *dmac = data;
if (!(rcar_dmac_read(dmac, RCAR_DMAOR) & RCAR_DMAOR_AE))
return IRQ_NONE;
rcar_dmac_stop(dmac);
rcar_dmac_abort(dmac);
rcar_dmac_init(dmac);
return IRQ_HANDLED;
}
static bool rcar_dmac_chan_filter(struct dma_chan *chan, void *arg)
{
struct rcar_dmac *dmac = to_rcar_dmac(chan->device);
struct of_phandle_args *dma_spec = arg;
if (chan->device->device_config != rcar_dmac_device_config ||
dma_spec->np != chan->device->dev->of_node)
return false;
return !test_and_set_bit(dma_spec->args[0], dmac->modules);
}
static struct dma_chan *rcar_dmac_of_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct rcar_dmac_chan *rchan;
struct dma_chan *chan;
dma_cap_mask_t mask;
if (dma_spec->args_count != 1)
return NULL;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
chan = dma_request_channel(mask, rcar_dmac_chan_filter, dma_spec);
if (!chan)
return NULL;
rchan = to_rcar_dmac_chan(chan);
rchan->mid_rid = dma_spec->args[0];
return chan;
}
static int rcar_dmac_sleep_suspend(struct device *dev)
{
return 0;
}
static int rcar_dmac_sleep_resume(struct device *dev)
{
return 0;
}
static int rcar_dmac_runtime_suspend(struct device *dev)
{
return 0;
}
static int rcar_dmac_runtime_resume(struct device *dev)
{
struct rcar_dmac *dmac = dev_get_drvdata(dev);
return rcar_dmac_init(dmac);
}
static int rcar_dmac_chan_probe(struct rcar_dmac *dmac,
struct rcar_dmac_chan *rchan,
unsigned int index)
{
struct platform_device *pdev = to_platform_device(dmac->dev);
struct dma_chan *chan = &rchan->chan;
char pdev_irqname[5];
char *irqname;
int irq;
int ret;
rchan->index = index;
rchan->iomem = dmac->iomem + RCAR_DMAC_CHAN_OFFSET(index);
rchan->mid_rid = -EINVAL;
spin_lock_init(&rchan->lock);
INIT_LIST_HEAD(&rchan->desc.free);
INIT_LIST_HEAD(&rchan->desc.pending);
INIT_LIST_HEAD(&rchan->desc.active);
INIT_LIST_HEAD(&rchan->desc.done);
INIT_LIST_HEAD(&rchan->desc.wait);
sprintf(pdev_irqname, "ch%u", index);
irq = platform_get_irq_byname(pdev, pdev_irqname);
if (irq < 0) {
dev_err(dmac->dev, "no IRQ specified for channel %u\n", index);
return -ENODEV;
}
irqname = devm_kasprintf(dmac->dev, GFP_KERNEL, "%s:%u",
dev_name(dmac->dev), index);
if (!irqname)
return -ENOMEM;
ret = devm_request_threaded_irq(dmac->dev, irq, rcar_dmac_isr_channel,
rcar_dmac_isr_channel_thread, 0,
irqname, rchan);
if (ret) {
dev_err(dmac->dev, "failed to request IRQ %u (%d)\n", irq, ret);
return ret;
}
chan->device = &dmac->engine;
dma_cookie_init(chan);
list_add_tail(&chan->device_node, &dmac->engine.channels);
return 0;
}
static int rcar_dmac_parse_of(struct device *dev, struct rcar_dmac *dmac)
{
struct device_node *np = dev->of_node;
int ret;
ret = of_property_read_u32(np, "dma-channels", &dmac->n_channels);
if (ret < 0) {
dev_err(dev, "unable to read dma-channels property\n");
return ret;
}
if (dmac->n_channels <= 0 || dmac->n_channels >= 100) {
dev_err(dev, "invalid number of channels %u\n",
dmac->n_channels);
return -EINVAL;
}
return 0;
}
static int rcar_dmac_probe(struct platform_device *pdev)
{
const enum dma_slave_buswidth widths = DMA_SLAVE_BUSWIDTH_1_BYTE |
DMA_SLAVE_BUSWIDTH_2_BYTES | DMA_SLAVE_BUSWIDTH_4_BYTES |
DMA_SLAVE_BUSWIDTH_8_BYTES | DMA_SLAVE_BUSWIDTH_16_BYTES |
DMA_SLAVE_BUSWIDTH_32_BYTES | DMA_SLAVE_BUSWIDTH_64_BYTES;
unsigned int channels_offset = 0;
struct dma_device *engine;
struct rcar_dmac *dmac;
struct resource *mem;
unsigned int i;
char *irqname;
int irq;
int ret;
dmac = devm_kzalloc(&pdev->dev, sizeof(*dmac), GFP_KERNEL);
if (!dmac)
return -ENOMEM;
dmac->dev = &pdev->dev;
platform_set_drvdata(pdev, dmac);
ret = rcar_dmac_parse_of(&pdev->dev, dmac);
if (ret < 0)
return ret;
if (pdev->dev.iommu_group) {
dmac->n_channels--;
channels_offset = 1;
}
dmac->channels = devm_kcalloc(&pdev->dev, dmac->n_channels,
sizeof(*dmac->channels), GFP_KERNEL);
if (!dmac->channels)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dmac->iomem = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(dmac->iomem))
return PTR_ERR(dmac->iomem);
irq = platform_get_irq_byname(pdev, "error");
if (irq < 0) {
dev_err(&pdev->dev, "no error IRQ specified\n");
return -ENODEV;
}
irqname = devm_kasprintf(dmac->dev, GFP_KERNEL, "%s:error",
dev_name(dmac->dev));
if (!irqname)
return -ENOMEM;
ret = devm_request_irq(&pdev->dev, irq, rcar_dmac_isr_error, 0,
irqname, dmac);
if (ret) {
dev_err(&pdev->dev, "failed to request IRQ %u (%d)\n",
irq, ret);
return ret;
}
pm_runtime_enable(&pdev->dev);
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "runtime PM get sync failed (%d)\n", ret);
return ret;
}
ret = rcar_dmac_init(dmac);
pm_runtime_put(&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "failed to reset device\n");
goto error;
}
INIT_LIST_HEAD(&dmac->engine.channels);
for (i = 0; i < dmac->n_channels; ++i) {
ret = rcar_dmac_chan_probe(dmac, &dmac->channels[i],
i + channels_offset);
if (ret < 0)
goto error;
}
ret = of_dma_controller_register(pdev->dev.of_node, rcar_dmac_of_xlate,
NULL);
if (ret < 0)
goto error;
engine = &dmac->engine;
dma_cap_set(DMA_MEMCPY, engine->cap_mask);
dma_cap_set(DMA_SLAVE, engine->cap_mask);
engine->dev = &pdev->dev;
engine->copy_align = ilog2(RCAR_DMAC_MEMCPY_XFER_SIZE);
engine->src_addr_widths = widths;
engine->dst_addr_widths = widths;
engine->directions = BIT(DMA_MEM_TO_DEV) | BIT(DMA_DEV_TO_MEM);
engine->residue_granularity = DMA_RESIDUE_GRANULARITY_BURST;
engine->device_alloc_chan_resources = rcar_dmac_alloc_chan_resources;
engine->device_free_chan_resources = rcar_dmac_free_chan_resources;
engine->device_prep_dma_memcpy = rcar_dmac_prep_dma_memcpy;
engine->device_prep_slave_sg = rcar_dmac_prep_slave_sg;
engine->device_prep_dma_cyclic = rcar_dmac_prep_dma_cyclic;
engine->device_config = rcar_dmac_device_config;
engine->device_terminate_all = rcar_dmac_chan_terminate_all;
engine->device_tx_status = rcar_dmac_tx_status;
engine->device_issue_pending = rcar_dmac_issue_pending;
ret = dma_async_device_register(engine);
if (ret < 0)
goto error;
return 0;
error:
of_dma_controller_free(pdev->dev.of_node);
pm_runtime_disable(&pdev->dev);
return ret;
}
static int rcar_dmac_remove(struct platform_device *pdev)
{
struct rcar_dmac *dmac = platform_get_drvdata(pdev);
of_dma_controller_free(pdev->dev.of_node);
dma_async_device_unregister(&dmac->engine);
pm_runtime_disable(&pdev->dev);
return 0;
}
static void rcar_dmac_shutdown(struct platform_device *pdev)
{
struct rcar_dmac *dmac = platform_get_drvdata(pdev);
rcar_dmac_stop(dmac);
}
