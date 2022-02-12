static inline u32 nbpf_chan_read(struct nbpf_channel *chan,
unsigned int offset)
{
u32 data = ioread32(chan->base + offset);
dev_dbg(chan->dma_chan.device->dev, "%s(0x%p + 0x%x) = 0x%x\n",
__func__, chan->base, offset, data);
return data;
}
static inline void nbpf_chan_write(struct nbpf_channel *chan,
unsigned int offset, u32 data)
{
iowrite32(data, chan->base + offset);
dev_dbg(chan->dma_chan.device->dev, "%s(0x%p + 0x%x) = 0x%x\n",
__func__, chan->base, offset, data);
}
static inline u32 nbpf_read(struct nbpf_device *nbpf,
unsigned int offset)
{
u32 data = ioread32(nbpf->base + offset);
dev_dbg(nbpf->dma_dev.dev, "%s(0x%p + 0x%x) = 0x%x\n",
__func__, nbpf->base, offset, data);
return data;
}
static inline void nbpf_write(struct nbpf_device *nbpf,
unsigned int offset, u32 data)
{
iowrite32(data, nbpf->base + offset);
dev_dbg(nbpf->dma_dev.dev, "%s(0x%p + 0x%x) = 0x%x\n",
__func__, nbpf->base, offset, data);
}
static void nbpf_chan_halt(struct nbpf_channel *chan)
{
nbpf_chan_write(chan, NBPF_CHAN_CTRL, NBPF_CHAN_CTRL_CLREN);
}
static bool nbpf_status_get(struct nbpf_channel *chan)
{
u32 status = nbpf_read(chan->nbpf, NBPF_DSTAT_END);
return status & BIT(chan - chan->nbpf->chan);
}
static void nbpf_status_ack(struct nbpf_channel *chan)
{
nbpf_chan_write(chan, NBPF_CHAN_CTRL, NBPF_CHAN_CTRL_CLREND);
}
static u32 nbpf_error_get(struct nbpf_device *nbpf)
{
return nbpf_read(nbpf, NBPF_DSTAT_ER);
}
static struct nbpf_channel *nbpf_error_get_channel(struct nbpf_device *nbpf, u32 error)
{
return nbpf->chan + __ffs(error);
}
static void nbpf_error_clear(struct nbpf_channel *chan)
{
u32 status;
int i;
nbpf_chan_halt(chan);
for (i = 1000; i; i--) {
status = nbpf_chan_read(chan, NBPF_CHAN_STAT);
if (!(status & NBPF_CHAN_STAT_TACT))
break;
cpu_relax();
}
if (!i)
dev_err(chan->dma_chan.device->dev,
"%s(): abort timeout, channel status 0x%x\n", __func__, status);
nbpf_chan_write(chan, NBPF_CHAN_CTRL, NBPF_CHAN_CTRL_SWRST);
}
static int nbpf_start(struct nbpf_desc *desc)
{
struct nbpf_channel *chan = desc->chan;
struct nbpf_link_desc *ldesc = list_first_entry(&desc->sg, struct nbpf_link_desc, node);
nbpf_chan_write(chan, NBPF_CHAN_NXLA, (u32)ldesc->hwdesc_dma_addr);
nbpf_chan_write(chan, NBPF_CHAN_CTRL, NBPF_CHAN_CTRL_SETEN | NBPF_CHAN_CTRL_CLRSUS);
chan->paused = false;
if (ldesc->hwdesc->config & NBPF_CHAN_CFG_TM)
nbpf_chan_write(chan, NBPF_CHAN_CTRL, NBPF_CHAN_CTRL_STG);
dev_dbg(chan->nbpf->dma_dev.dev, "%s(): next 0x%x, cur 0x%x\n", __func__,
nbpf_chan_read(chan, NBPF_CHAN_NXLA), nbpf_chan_read(chan, NBPF_CHAN_CRLA));
return 0;
}
static void nbpf_chan_prepare(struct nbpf_channel *chan)
{
chan->dmarq_cfg = (chan->flags & NBPF_SLAVE_RQ_HIGH ? NBPF_CHAN_CFG_HIEN : 0) |
(chan->flags & NBPF_SLAVE_RQ_LOW ? NBPF_CHAN_CFG_LOEN : 0) |
(chan->flags & NBPF_SLAVE_RQ_LEVEL ?
NBPF_CHAN_CFG_LVL | (NBPF_CHAN_CFG_AM & 0x200) : 0) |
chan->terminal;
}
static void nbpf_chan_prepare_default(struct nbpf_channel *chan)
{
chan->dmarq_cfg = NBPF_CHAN_CFG_AM & 0x400;
chan->terminal = 0;
chan->flags = 0;
}
static void nbpf_chan_configure(struct nbpf_channel *chan)
{
nbpf_chan_write(chan, NBPF_CHAN_CFG, NBPF_CHAN_CFG_DMS | chan->dmarq_cfg);
}
static u32 nbpf_xfer_ds(struct nbpf_device *nbpf, size_t size,
enum dma_transfer_direction direction)
{
int max_burst = nbpf->config->buffer_size * 8;
if (nbpf->max_burst_mem_read || nbpf->max_burst_mem_write) {
switch (direction) {
case DMA_MEM_TO_MEM:
max_burst = min_not_zero(nbpf->max_burst_mem_read,
nbpf->max_burst_mem_write);
break;
case DMA_MEM_TO_DEV:
if (nbpf->max_burst_mem_read)
max_burst = nbpf->max_burst_mem_read;
break;
case DMA_DEV_TO_MEM:
if (nbpf->max_burst_mem_write)
max_burst = nbpf->max_burst_mem_write;
break;
case DMA_DEV_TO_DEV:
default:
break;
}
}
return min_t(int, __ffs(size), ilog2(max_burst));
}
static size_t nbpf_xfer_size(struct nbpf_device *nbpf,
enum dma_slave_buswidth width, u32 burst)
{
size_t size;
if (!burst)
burst = 1;
switch (width) {
case DMA_SLAVE_BUSWIDTH_8_BYTES:
size = 8 * burst;
break;
case DMA_SLAVE_BUSWIDTH_4_BYTES:
size = 4 * burst;
break;
case DMA_SLAVE_BUSWIDTH_2_BYTES:
size = 2 * burst;
break;
default:
pr_warn("%s(): invalid bus width %u\n", __func__, width);
case DMA_SLAVE_BUSWIDTH_1_BYTE:
size = burst;
}
return nbpf_xfer_ds(nbpf, size, DMA_TRANS_NONE);
}
static int nbpf_prep_one(struct nbpf_link_desc *ldesc,
enum dma_transfer_direction direction,
dma_addr_t src, dma_addr_t dst, size_t size, bool last)
{
struct nbpf_link_reg *hwdesc = ldesc->hwdesc;
struct nbpf_desc *desc = ldesc->desc;
struct nbpf_channel *chan = desc->chan;
struct device *dev = chan->dma_chan.device->dev;
size_t mem_xfer, slave_xfer;
bool can_burst;
hwdesc->header = NBPF_HEADER_WBD | NBPF_HEADER_LV |
(last ? NBPF_HEADER_LE : 0);
hwdesc->src_addr = src;
hwdesc->dst_addr = dst;
hwdesc->transaction_size = size;
mem_xfer = nbpf_xfer_ds(chan->nbpf, size, direction);
switch (direction) {
case DMA_DEV_TO_MEM:
can_burst = chan->slave_src_width >= 3;
slave_xfer = min(mem_xfer, can_burst ?
chan->slave_src_burst : chan->slave_src_width);
if (mem_xfer > chan->slave_src_burst && !can_burst)
mem_xfer = chan->slave_src_burst;
hwdesc->config = NBPF_CHAN_CFG_SAD | (NBPF_CHAN_CFG_DDS & (mem_xfer << 16)) |
(NBPF_CHAN_CFG_SDS & (slave_xfer << 12)) | NBPF_CHAN_CFG_REQD |
NBPF_CHAN_CFG_SBE;
break;
case DMA_MEM_TO_DEV:
slave_xfer = min(mem_xfer, chan->slave_dst_width >= 3 ?
chan->slave_dst_burst : chan->slave_dst_width);
hwdesc->config = NBPF_CHAN_CFG_DAD | (NBPF_CHAN_CFG_SDS & (mem_xfer << 12)) |
(NBPF_CHAN_CFG_DDS & (slave_xfer << 16)) | NBPF_CHAN_CFG_REQD;
break;
case DMA_MEM_TO_MEM:
hwdesc->config = NBPF_CHAN_CFG_TCM | NBPF_CHAN_CFG_TM |
(NBPF_CHAN_CFG_SDS & (mem_xfer << 12)) |
(NBPF_CHAN_CFG_DDS & (mem_xfer << 16));
break;
default:
return -EINVAL;
}
hwdesc->config |= chan->dmarq_cfg | (last ? 0 : NBPF_CHAN_CFG_DEM) |
NBPF_CHAN_CFG_DMS;
dev_dbg(dev, "%s(): desc @ %pad: hdr 0x%x, cfg 0x%x, %zu @ %pad -> %pad\n",
__func__, &ldesc->hwdesc_dma_addr, hwdesc->header,
hwdesc->config, size, &src, &dst);
dma_sync_single_for_device(dev, ldesc->hwdesc_dma_addr, sizeof(*hwdesc),
DMA_TO_DEVICE);
return 0;
}
static size_t nbpf_bytes_left(struct nbpf_channel *chan)
{
return nbpf_chan_read(chan, NBPF_CHAN_CUR_TR_BYTE);
}
static void nbpf_configure(struct nbpf_device *nbpf)
{
nbpf_write(nbpf, NBPF_CTRL, NBPF_CTRL_LVINT);
}
static void nbpf_issue_pending(struct dma_chan *dchan)
{
struct nbpf_channel *chan = nbpf_to_chan(dchan);
unsigned long flags;
dev_dbg(dchan->device->dev, "Entry %s()\n", __func__);
spin_lock_irqsave(&chan->lock, flags);
if (list_empty(&chan->queued))
goto unlock;
list_splice_tail_init(&chan->queued, &chan->active);
if (!chan->running) {
struct nbpf_desc *desc = list_first_entry(&chan->active,
struct nbpf_desc, node);
if (!nbpf_start(desc))
chan->running = desc;
}
unlock:
spin_unlock_irqrestore(&chan->lock, flags);
}
static enum dma_status nbpf_tx_status(struct dma_chan *dchan,
dma_cookie_t cookie, struct dma_tx_state *state)
{
struct nbpf_channel *chan = nbpf_to_chan(dchan);
enum dma_status status = dma_cookie_status(dchan, cookie, state);
if (state) {
dma_cookie_t running;
unsigned long flags;
spin_lock_irqsave(&chan->lock, flags);
running = chan->running ? chan->running->async_tx.cookie : -EINVAL;
if (cookie == running) {
state->residue = nbpf_bytes_left(chan);
dev_dbg(dchan->device->dev, "%s(): residue %u\n", __func__,
state->residue);
} else if (status == DMA_IN_PROGRESS) {
struct nbpf_desc *desc;
bool found = false;
list_for_each_entry(desc, &chan->active, node)
if (desc->async_tx.cookie == cookie) {
found = true;
break;
}
if (!found)
list_for_each_entry(desc, &chan->queued, node)
if (desc->async_tx.cookie == cookie) {
found = true;
break;
}
state->residue = found ? desc->length : 0;
}
spin_unlock_irqrestore(&chan->lock, flags);
}
if (chan->paused)
status = DMA_PAUSED;
return status;
}
static dma_cookie_t nbpf_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct nbpf_desc *desc = container_of(tx, struct nbpf_desc, async_tx);
struct nbpf_channel *chan = desc->chan;
unsigned long flags;
dma_cookie_t cookie;
spin_lock_irqsave(&chan->lock, flags);
cookie = dma_cookie_assign(tx);
list_add_tail(&desc->node, &chan->queued);
spin_unlock_irqrestore(&chan->lock, flags);
dev_dbg(chan->dma_chan.device->dev, "Entry %s(%d)\n", __func__, cookie);
return cookie;
}
static int nbpf_desc_page_alloc(struct nbpf_channel *chan)
{
struct dma_chan *dchan = &chan->dma_chan;
struct nbpf_desc_page *dpage = (void *)get_zeroed_page(GFP_KERNEL | GFP_DMA);
struct nbpf_link_desc *ldesc;
struct nbpf_link_reg *hwdesc;
struct nbpf_desc *desc;
LIST_HEAD(head);
LIST_HEAD(lhead);
int i;
struct device *dev = dchan->device->dev;
if (!dpage)
return -ENOMEM;
dev_dbg(dev, "%s(): alloc %lu descriptors, %lu segments, total alloc %zu\n",
__func__, NBPF_DESCS_PER_PAGE, NBPF_SEGMENTS_PER_PAGE, sizeof(*dpage));
for (i = 0, ldesc = dpage->ldesc, hwdesc = dpage->hwdesc;
i < ARRAY_SIZE(dpage->ldesc);
i++, ldesc++, hwdesc++) {
ldesc->hwdesc = hwdesc;
list_add_tail(&ldesc->node, &lhead);
ldesc->hwdesc_dma_addr = dma_map_single(dchan->device->dev,
hwdesc, sizeof(*hwdesc), DMA_TO_DEVICE);
dev_dbg(dev, "%s(): mapped 0x%p to %pad\n", __func__,
hwdesc, &ldesc->hwdesc_dma_addr);
}
for (i = 0, desc = dpage->desc;
i < ARRAY_SIZE(dpage->desc);
i++, desc++) {
dma_async_tx_descriptor_init(&desc->async_tx, dchan);
desc->async_tx.tx_submit = nbpf_tx_submit;
desc->chan = chan;
INIT_LIST_HEAD(&desc->sg);
list_add_tail(&desc->node, &head);
}
spin_lock_irq(&chan->lock);
list_splice_tail(&lhead, &chan->free_links);
list_splice_tail(&head, &chan->free);
list_add(&dpage->node, &chan->desc_page);
spin_unlock_irq(&chan->lock);
return ARRAY_SIZE(dpage->desc);
}
static void nbpf_desc_put(struct nbpf_desc *desc)
{
struct nbpf_channel *chan = desc->chan;
struct nbpf_link_desc *ldesc, *tmp;
unsigned long flags;
spin_lock_irqsave(&chan->lock, flags);
list_for_each_entry_safe(ldesc, tmp, &desc->sg, node)
list_move(&ldesc->node, &chan->free_links);
list_add(&desc->node, &chan->free);
spin_unlock_irqrestore(&chan->lock, flags);
}
static void nbpf_scan_acked(struct nbpf_channel *chan)
{
struct nbpf_desc *desc, *tmp;
unsigned long flags;
LIST_HEAD(head);
spin_lock_irqsave(&chan->lock, flags);
list_for_each_entry_safe(desc, tmp, &chan->done, node)
if (async_tx_test_ack(&desc->async_tx) && desc->user_wait) {
list_move(&desc->node, &head);
desc->user_wait = false;
}
spin_unlock_irqrestore(&chan->lock, flags);
list_for_each_entry_safe(desc, tmp, &head, node) {
list_del(&desc->node);
nbpf_desc_put(desc);
}
}
static struct nbpf_desc *nbpf_desc_get(struct nbpf_channel *chan, size_t len)
{
struct nbpf_desc *desc = NULL;
struct nbpf_link_desc *ldesc, *prev = NULL;
nbpf_scan_acked(chan);
spin_lock_irq(&chan->lock);
do {
int i = 0, ret;
if (list_empty(&chan->free)) {
spin_unlock_irq(&chan->lock);
ret = nbpf_desc_page_alloc(chan);
if (ret < 0)
return NULL;
spin_lock_irq(&chan->lock);
continue;
}
desc = list_first_entry(&chan->free, struct nbpf_desc, node);
list_del(&desc->node);
do {
if (list_empty(&chan->free_links)) {
spin_unlock_irq(&chan->lock);
ret = nbpf_desc_page_alloc(chan);
if (ret < 0) {
nbpf_desc_put(desc);
return NULL;
}
spin_lock_irq(&chan->lock);
continue;
}
ldesc = list_first_entry(&chan->free_links,
struct nbpf_link_desc, node);
ldesc->desc = desc;
if (prev)
prev->hwdesc->next = (u32)ldesc->hwdesc_dma_addr;
prev = ldesc;
list_move_tail(&ldesc->node, &desc->sg);
i++;
} while (i < len);
} while (!desc);
prev->hwdesc->next = 0;
spin_unlock_irq(&chan->lock);
return desc;
}
static void nbpf_chan_idle(struct nbpf_channel *chan)
{
struct nbpf_desc *desc, *tmp;
unsigned long flags;
LIST_HEAD(head);
spin_lock_irqsave(&chan->lock, flags);
list_splice_init(&chan->done, &head);
list_splice_init(&chan->active, &head);
list_splice_init(&chan->queued, &head);
chan->running = NULL;
spin_unlock_irqrestore(&chan->lock, flags);
list_for_each_entry_safe(desc, tmp, &head, node) {
dev_dbg(chan->nbpf->dma_dev.dev, "%s(): force-free desc %p cookie %d\n",
__func__, desc, desc->async_tx.cookie);
list_del(&desc->node);
nbpf_desc_put(desc);
}
}
static int nbpf_pause(struct dma_chan *dchan)
{
struct nbpf_channel *chan = nbpf_to_chan(dchan);
dev_dbg(dchan->device->dev, "Entry %s\n", __func__);
chan->paused = true;
nbpf_chan_write(chan, NBPF_CHAN_CTRL, NBPF_CHAN_CTRL_SETSUS);
nbpf_chan_write(chan, NBPF_CHAN_CTRL, NBPF_CHAN_CTRL_CLREN);
return 0;
}
static int nbpf_terminate_all(struct dma_chan *dchan)
{
struct nbpf_channel *chan = nbpf_to_chan(dchan);
dev_dbg(dchan->device->dev, "Entry %s\n", __func__);
dev_dbg(dchan->device->dev, "Terminating\n");
nbpf_chan_halt(chan);
nbpf_chan_idle(chan);
return 0;
}
static int nbpf_config(struct dma_chan *dchan,
struct dma_slave_config *config)
{
struct nbpf_channel *chan = nbpf_to_chan(dchan);
dev_dbg(dchan->device->dev, "Entry %s\n", __func__);
chan->slave_dst_addr = config->dst_addr;
chan->slave_dst_width = nbpf_xfer_size(chan->nbpf,
config->dst_addr_width, 1);
chan->slave_dst_burst = nbpf_xfer_size(chan->nbpf,
config->dst_addr_width,
config->dst_maxburst);
chan->slave_src_addr = config->src_addr;
chan->slave_src_width = nbpf_xfer_size(chan->nbpf,
config->src_addr_width, 1);
chan->slave_src_burst = nbpf_xfer_size(chan->nbpf,
config->src_addr_width,
config->src_maxburst);
return 0;
}
static struct dma_async_tx_descriptor *nbpf_prep_sg(struct nbpf_channel *chan,
struct scatterlist *src_sg, struct scatterlist *dst_sg,
size_t len, enum dma_transfer_direction direction,
unsigned long flags)
{
struct nbpf_link_desc *ldesc;
struct scatterlist *mem_sg;
struct nbpf_desc *desc;
bool inc_src, inc_dst;
size_t data_len = 0;
int i = 0;
switch (direction) {
case DMA_DEV_TO_MEM:
mem_sg = dst_sg;
inc_src = false;
inc_dst = true;
break;
case DMA_MEM_TO_DEV:
mem_sg = src_sg;
inc_src = true;
inc_dst = false;
break;
default:
case DMA_MEM_TO_MEM:
mem_sg = src_sg;
inc_src = true;
inc_dst = true;
}
desc = nbpf_desc_get(chan, len);
if (!desc)
return NULL;
desc->async_tx.flags = flags;
desc->async_tx.cookie = -EBUSY;
desc->user_wait = false;
list_for_each_entry(ldesc, &desc->sg, node) {
int ret = nbpf_prep_one(ldesc, direction,
sg_dma_address(src_sg),
sg_dma_address(dst_sg),
sg_dma_len(mem_sg),
i == len - 1);
if (ret < 0) {
nbpf_desc_put(desc);
return NULL;
}
data_len += sg_dma_len(mem_sg);
if (inc_src)
src_sg = sg_next(src_sg);
if (inc_dst)
dst_sg = sg_next(dst_sg);
mem_sg = direction == DMA_DEV_TO_MEM ? dst_sg : src_sg;
i++;
}
desc->length = data_len;
return &desc->async_tx;
}
static struct dma_async_tx_descriptor *nbpf_prep_memcpy(
struct dma_chan *dchan, dma_addr_t dst, dma_addr_t src,
size_t len, unsigned long flags)
{
struct nbpf_channel *chan = nbpf_to_chan(dchan);
struct scatterlist dst_sg;
struct scatterlist src_sg;
sg_init_table(&dst_sg, 1);
sg_init_table(&src_sg, 1);
sg_dma_address(&dst_sg) = dst;
sg_dma_address(&src_sg) = src;
sg_dma_len(&dst_sg) = len;
sg_dma_len(&src_sg) = len;
dev_dbg(dchan->device->dev, "%s(): %zu @ %pad -> %pad\n",
__func__, len, &src, &dst);
return nbpf_prep_sg(chan, &src_sg, &dst_sg, 1,
DMA_MEM_TO_MEM, flags);
}
static struct dma_async_tx_descriptor *nbpf_prep_memcpy_sg(
struct dma_chan *dchan,
struct scatterlist *dst_sg, unsigned int dst_nents,
struct scatterlist *src_sg, unsigned int src_nents,
unsigned long flags)
{
struct nbpf_channel *chan = nbpf_to_chan(dchan);
if (dst_nents != src_nents)
return NULL;
return nbpf_prep_sg(chan, src_sg, dst_sg, src_nents,
DMA_MEM_TO_MEM, flags);
}
static struct dma_async_tx_descriptor *nbpf_prep_slave_sg(
struct dma_chan *dchan, struct scatterlist *sgl, unsigned int sg_len,
enum dma_transfer_direction direction, unsigned long flags, void *context)
{
struct nbpf_channel *chan = nbpf_to_chan(dchan);
struct scatterlist slave_sg;
dev_dbg(dchan->device->dev, "Entry %s()\n", __func__);
sg_init_table(&slave_sg, 1);
switch (direction) {
case DMA_MEM_TO_DEV:
sg_dma_address(&slave_sg) = chan->slave_dst_addr;
return nbpf_prep_sg(chan, sgl, &slave_sg, sg_len,
direction, flags);
case DMA_DEV_TO_MEM:
sg_dma_address(&slave_sg) = chan->slave_src_addr;
return nbpf_prep_sg(chan, &slave_sg, sgl, sg_len,
direction, flags);
default:
return NULL;
}
}
static int nbpf_alloc_chan_resources(struct dma_chan *dchan)
{
struct nbpf_channel *chan = nbpf_to_chan(dchan);
int ret;
INIT_LIST_HEAD(&chan->free);
INIT_LIST_HEAD(&chan->free_links);
INIT_LIST_HEAD(&chan->queued);
INIT_LIST_HEAD(&chan->active);
INIT_LIST_HEAD(&chan->done);
ret = nbpf_desc_page_alloc(chan);
if (ret < 0)
return ret;
dev_dbg(dchan->device->dev, "Entry %s(): terminal %u\n", __func__,
chan->terminal);
nbpf_chan_configure(chan);
return ret;
}
static void nbpf_free_chan_resources(struct dma_chan *dchan)
{
struct nbpf_channel *chan = nbpf_to_chan(dchan);
struct nbpf_desc_page *dpage, *tmp;
dev_dbg(dchan->device->dev, "Entry %s()\n", __func__);
nbpf_chan_halt(chan);
nbpf_chan_idle(chan);
nbpf_chan_prepare_default(chan);
list_for_each_entry_safe(dpage, tmp, &chan->desc_page, node) {
struct nbpf_link_desc *ldesc;
int i;
list_del(&dpage->node);
for (i = 0, ldesc = dpage->ldesc;
i < ARRAY_SIZE(dpage->ldesc);
i++, ldesc++)
dma_unmap_single(dchan->device->dev, ldesc->hwdesc_dma_addr,
sizeof(*ldesc->hwdesc), DMA_TO_DEVICE);
free_page((unsigned long)dpage);
}
}
static struct dma_chan *nbpf_of_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct nbpf_device *nbpf = ofdma->of_dma_data;
struct dma_chan *dchan;
struct nbpf_channel *chan;
if (dma_spec->args_count != 2)
return NULL;
dchan = dma_get_any_slave_channel(&nbpf->dma_dev);
if (!dchan)
return NULL;
dev_dbg(dchan->device->dev, "Entry %s(%s)\n", __func__,
dma_spec->np->name);
chan = nbpf_to_chan(dchan);
chan->terminal = dma_spec->args[0];
chan->flags = dma_spec->args[1];
nbpf_chan_prepare(chan);
nbpf_chan_configure(chan);
return dchan;
}
static void nbpf_chan_tasklet(unsigned long data)
{
struct nbpf_channel *chan = (struct nbpf_channel *)data;
struct nbpf_desc *desc, *tmp;
struct dmaengine_desc_callback cb;
while (!list_empty(&chan->done)) {
bool found = false, must_put, recycling = false;
spin_lock_irq(&chan->lock);
list_for_each_entry_safe(desc, tmp, &chan->done, node) {
if (!desc->user_wait) {
found = true;
break;
} else if (async_tx_test_ack(&desc->async_tx)) {
list_del(&desc->node);
spin_unlock_irq(&chan->lock);
nbpf_desc_put(desc);
recycling = true;
break;
}
}
if (recycling)
continue;
if (!found) {
spin_unlock_irq(&chan->lock);
break;
}
dma_cookie_complete(&desc->async_tx);
if (async_tx_test_ack(&desc->async_tx)) {
list_del(&desc->node);
must_put = true;
} else {
desc->user_wait = true;
must_put = false;
}
dmaengine_desc_get_callback(&desc->async_tx, &cb);
spin_unlock_irq(&chan->lock);
dmaengine_desc_callback_invoke(&cb, NULL);
if (must_put)
nbpf_desc_put(desc);
}
}
static irqreturn_t nbpf_chan_irq(int irq, void *dev)
{
struct nbpf_channel *chan = dev;
bool done = nbpf_status_get(chan);
struct nbpf_desc *desc;
irqreturn_t ret;
bool bh = false;
if (!done)
return IRQ_NONE;
nbpf_status_ack(chan);
dev_dbg(&chan->dma_chan.dev->device, "%s()\n", __func__);
spin_lock(&chan->lock);
desc = chan->running;
if (WARN_ON(!desc)) {
ret = IRQ_NONE;
goto unlock;
} else {
ret = IRQ_HANDLED;
bh = true;
}
list_move_tail(&desc->node, &chan->done);
chan->running = NULL;
if (!list_empty(&chan->active)) {
desc = list_first_entry(&chan->active,
struct nbpf_desc, node);
if (!nbpf_start(desc))
chan->running = desc;
}
unlock:
spin_unlock(&chan->lock);
if (bh)
tasklet_schedule(&chan->tasklet);
return ret;
}
static irqreturn_t nbpf_err_irq(int irq, void *dev)
{
struct nbpf_device *nbpf = dev;
u32 error = nbpf_error_get(nbpf);
dev_warn(nbpf->dma_dev.dev, "DMA error IRQ %u\n", irq);
if (!error)
return IRQ_NONE;
do {
struct nbpf_channel *chan = nbpf_error_get_channel(nbpf, error);
nbpf_error_clear(chan);
nbpf_chan_idle(chan);
error = nbpf_error_get(nbpf);
} while (error);
return IRQ_HANDLED;
}
static int nbpf_chan_probe(struct nbpf_device *nbpf, int n)
{
struct dma_device *dma_dev = &nbpf->dma_dev;
struct nbpf_channel *chan = nbpf->chan + n;
int ret;
chan->nbpf = nbpf;
chan->base = nbpf->base + NBPF_REG_CHAN_OFFSET + NBPF_REG_CHAN_SIZE * n;
INIT_LIST_HEAD(&chan->desc_page);
spin_lock_init(&chan->lock);
chan->dma_chan.device = dma_dev;
dma_cookie_init(&chan->dma_chan);
nbpf_chan_prepare_default(chan);
dev_dbg(dma_dev->dev, "%s(): channel %d: -> %p\n", __func__, n, chan->base);
snprintf(chan->name, sizeof(chan->name), "nbpf %d", n);
tasklet_init(&chan->tasklet, nbpf_chan_tasklet, (unsigned long)chan);
ret = devm_request_irq(dma_dev->dev, chan->irq,
nbpf_chan_irq, IRQF_SHARED,
chan->name, chan);
if (ret < 0)
return ret;
list_add_tail(&chan->dma_chan.device_node,
&dma_dev->channels);
return 0;
}
static int nbpf_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *of_id = of_match_device(nbpf_match, dev);
struct device_node *np = dev->of_node;
struct nbpf_device *nbpf;
struct dma_device *dma_dev;
struct resource *iomem, *irq_res;
const struct nbpf_config *cfg;
int num_channels;
int ret, irq, eirq, i;
int irqbuf[9] ;
unsigned int irqs = 0;
BUILD_BUG_ON(sizeof(struct nbpf_desc_page) > PAGE_SIZE);
if (!np || !of_id || !of_id->data)
return -ENODEV;
cfg = of_id->data;
num_channels = cfg->num_channels;
nbpf = devm_kzalloc(dev, sizeof(*nbpf) + num_channels *
sizeof(nbpf->chan[0]), GFP_KERNEL);
if (!nbpf)
return -ENOMEM;
dma_dev = &nbpf->dma_dev;
dma_dev->dev = dev;
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
nbpf->base = devm_ioremap_resource(dev, iomem);
if (IS_ERR(nbpf->base))
return PTR_ERR(nbpf->base);
nbpf->clk = devm_clk_get(dev, NULL);
if (IS_ERR(nbpf->clk))
return PTR_ERR(nbpf->clk);
of_property_read_u32(np, "max-burst-mem-read",
&nbpf->max_burst_mem_read);
of_property_read_u32(np, "max-burst-mem-write",
&nbpf->max_burst_mem_write);
nbpf->config = cfg;
for (i = 0; irqs < ARRAY_SIZE(irqbuf); i++) {
irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, i);
if (!irq_res)
break;
for (irq = irq_res->start; irq <= irq_res->end;
irq++, irqs++)
irqbuf[irqs] = irq;
}
if (irqs != 1 && irqs != 2 && irqs != num_channels + 1)
return -ENXIO;
if (irqs == 1) {
eirq = irqbuf[0];
for (i = 0; i <= num_channels; i++)
nbpf->chan[i].irq = irqbuf[0];
} else {
eirq = platform_get_irq_byname(pdev, "error");
if (eirq < 0)
return eirq;
if (irqs == num_channels + 1) {
struct nbpf_channel *chan;
for (i = 0, chan = nbpf->chan; i <= num_channels;
i++, chan++) {
if (irqbuf[i] == eirq)
i++;
chan->irq = irqbuf[i];
}
if (chan != nbpf->chan + num_channels)
return -EINVAL;
} else {
if (irqbuf[0] == eirq)
irq = irqbuf[1];
else
irq = irqbuf[0];
for (i = 0; i <= num_channels; i++)
nbpf->chan[i].irq = irq;
}
}
ret = devm_request_irq(dev, eirq, nbpf_err_irq,
IRQF_SHARED, "dma error", nbpf);
if (ret < 0)
return ret;
nbpf->eirq = eirq;
INIT_LIST_HEAD(&dma_dev->channels);
for (i = 0; i < num_channels; i++) {
ret = nbpf_chan_probe(nbpf, i);
if (ret < 0)
return ret;
}
dma_cap_set(DMA_MEMCPY, dma_dev->cap_mask);
dma_cap_set(DMA_SLAVE, dma_dev->cap_mask);
dma_cap_set(DMA_PRIVATE, dma_dev->cap_mask);
dma_cap_set(DMA_SG, dma_dev->cap_mask);
dma_dev->device_alloc_chan_resources
= nbpf_alloc_chan_resources;
dma_dev->device_free_chan_resources = nbpf_free_chan_resources;
dma_dev->device_prep_dma_sg = nbpf_prep_memcpy_sg;
dma_dev->device_prep_dma_memcpy = nbpf_prep_memcpy;
dma_dev->device_tx_status = nbpf_tx_status;
dma_dev->device_issue_pending = nbpf_issue_pending;
dma_dev->device_prep_slave_sg = nbpf_prep_slave_sg;
dma_dev->device_config = nbpf_config;
dma_dev->device_pause = nbpf_pause;
dma_dev->device_terminate_all = nbpf_terminate_all;
dma_dev->src_addr_widths = NBPF_DMA_BUSWIDTHS;
dma_dev->dst_addr_widths = NBPF_DMA_BUSWIDTHS;
dma_dev->directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
platform_set_drvdata(pdev, nbpf);
ret = clk_prepare_enable(nbpf->clk);
if (ret < 0)
return ret;
nbpf_configure(nbpf);
ret = dma_async_device_register(dma_dev);
if (ret < 0)
goto e_clk_off;
ret = of_dma_controller_register(np, nbpf_of_xlate, nbpf);
if (ret < 0)
goto e_dma_dev_unreg;
return 0;
e_dma_dev_unreg:
dma_async_device_unregister(dma_dev);
e_clk_off:
clk_disable_unprepare(nbpf->clk);
return ret;
}
static int nbpf_remove(struct platform_device *pdev)
{
struct nbpf_device *nbpf = platform_get_drvdata(pdev);
int i;
devm_free_irq(&pdev->dev, nbpf->eirq, nbpf);
for (i = 0; i < nbpf->config->num_channels; i++) {
struct nbpf_channel *chan = nbpf->chan + i;
devm_free_irq(&pdev->dev, chan->irq, chan);
tasklet_kill(&chan->tasklet);
}
of_dma_controller_free(pdev->dev.of_node);
dma_async_device_unregister(&nbpf->dma_dev);
clk_disable_unprepare(nbpf->clk);
return 0;
}
static int nbpf_runtime_suspend(struct device *dev)
{
struct nbpf_device *nbpf = platform_get_drvdata(to_platform_device(dev));
clk_disable_unprepare(nbpf->clk);
return 0;
}
static int nbpf_runtime_resume(struct device *dev)
{
struct nbpf_device *nbpf = platform_get_drvdata(to_platform_device(dev));
return clk_prepare_enable(nbpf->clk);
}
