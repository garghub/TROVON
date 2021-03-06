static inline
struct sirfsoc_dma_chan *dma_chan_to_sirfsoc_dma_chan(struct dma_chan *c)
{
return container_of(c, struct sirfsoc_dma_chan, chan);
}
static inline struct sirfsoc_dma *dma_chan_to_sirfsoc_dma(struct dma_chan *c)
{
struct sirfsoc_dma_chan *schan = dma_chan_to_sirfsoc_dma_chan(c);
return container_of(schan, struct sirfsoc_dma, channels[c->chan_id]);
}
static void sirfsoc_dma_execute(struct sirfsoc_dma_chan *schan)
{
struct sirfsoc_dma *sdma = dma_chan_to_sirfsoc_dma(&schan->chan);
int cid = schan->chan.chan_id;
struct sirfsoc_dma_desc *sdesc = NULL;
sdesc = list_first_entry(&schan->queued, struct sirfsoc_dma_desc,
node);
list_move_tail(&sdesc->node, &schan->active);
writel_relaxed(sdesc->width, sdma->base + SIRFSOC_DMA_WIDTH_0 +
cid * 4);
writel_relaxed(cid | (schan->mode << SIRFSOC_DMA_MODE_CTRL_BIT) |
(sdesc->dir << SIRFSOC_DMA_DIR_CTRL_BIT),
sdma->base + cid * 0x10 + SIRFSOC_DMA_CH_CTRL);
writel_relaxed(sdesc->xlen, sdma->base + cid * 0x10 +
SIRFSOC_DMA_CH_XLEN);
writel_relaxed(sdesc->ylen, sdma->base + cid * 0x10 +
SIRFSOC_DMA_CH_YLEN);
writel_relaxed(readl_relaxed(sdma->base + SIRFSOC_DMA_INT_EN) |
(1 << cid), sdma->base + SIRFSOC_DMA_INT_EN);
writel(sdesc->addr >> 2, sdma->base + cid * 0x10 + SIRFSOC_DMA_CH_ADDR);
if (sdesc->cyclic) {
writel((1 << cid) | 1 << (cid + 16) |
readl_relaxed(sdma->base + SIRFSOC_DMA_CH_LOOP_CTRL),
sdma->base + SIRFSOC_DMA_CH_LOOP_CTRL);
schan->happened_cyclic = schan->completed_cyclic = 0;
}
}
static irqreturn_t sirfsoc_dma_irq(int irq, void *data)
{
struct sirfsoc_dma *sdma = data;
struct sirfsoc_dma_chan *schan;
struct sirfsoc_dma_desc *sdesc = NULL;
u32 is;
int ch;
is = readl(sdma->base + SIRFSOC_DMA_CH_INT);
while ((ch = fls(is) - 1) >= 0) {
is &= ~(1 << ch);
writel_relaxed(1 << ch, sdma->base + SIRFSOC_DMA_CH_INT);
schan = &sdma->channels[ch];
spin_lock(&schan->lock);
sdesc = list_first_entry(&schan->active, struct sirfsoc_dma_desc,
node);
if (!sdesc->cyclic) {
list_splice_tail_init(&schan->active, &schan->completed);
if (!list_empty(&schan->queued))
sirfsoc_dma_execute(schan);
} else
schan->happened_cyclic++;
spin_unlock(&schan->lock);
}
tasklet_schedule(&sdma->tasklet);
return IRQ_HANDLED;
}
static void sirfsoc_dma_process_completed(struct sirfsoc_dma *sdma)
{
dma_cookie_t last_cookie = 0;
struct sirfsoc_dma_chan *schan;
struct sirfsoc_dma_desc *sdesc;
struct dma_async_tx_descriptor *desc;
unsigned long flags;
unsigned long happened_cyclic;
LIST_HEAD(list);
int i;
for (i = 0; i < sdma->dma.chancnt; i++) {
schan = &sdma->channels[i];
spin_lock_irqsave(&schan->lock, flags);
if (!list_empty(&schan->completed)) {
list_splice_tail_init(&schan->completed, &list);
spin_unlock_irqrestore(&schan->lock, flags);
list_for_each_entry(sdesc, &list, node) {
desc = &sdesc->desc;
if (desc->callback)
desc->callback(desc->callback_param);
last_cookie = desc->cookie;
dma_run_dependencies(desc);
}
spin_lock_irqsave(&schan->lock, flags);
list_splice_tail_init(&list, &schan->free);
schan->chan.completed_cookie = last_cookie;
spin_unlock_irqrestore(&schan->lock, flags);
} else {
sdesc = list_first_entry(&schan->active, struct sirfsoc_dma_desc,
node);
if (!sdesc || (sdesc && !sdesc->cyclic)) {
spin_unlock_irqrestore(&schan->lock, flags);
continue;
}
happened_cyclic = schan->happened_cyclic;
spin_unlock_irqrestore(&schan->lock, flags);
desc = &sdesc->desc;
while (happened_cyclic != schan->completed_cyclic) {
if (desc->callback)
desc->callback(desc->callback_param);
schan->completed_cyclic++;
}
}
}
}
static void sirfsoc_dma_tasklet(unsigned long data)
{
struct sirfsoc_dma *sdma = (void *)data;
sirfsoc_dma_process_completed(sdma);
}
static dma_cookie_t sirfsoc_dma_tx_submit(struct dma_async_tx_descriptor *txd)
{
struct sirfsoc_dma_chan *schan = dma_chan_to_sirfsoc_dma_chan(txd->chan);
struct sirfsoc_dma_desc *sdesc;
unsigned long flags;
dma_cookie_t cookie;
sdesc = container_of(txd, struct sirfsoc_dma_desc, desc);
spin_lock_irqsave(&schan->lock, flags);
list_move_tail(&sdesc->node, &schan->queued);
cookie = dma_cookie_assign(txd);
spin_unlock_irqrestore(&schan->lock, flags);
return cookie;
}
static int sirfsoc_dma_slave_config(struct sirfsoc_dma_chan *schan,
struct dma_slave_config *config)
{
unsigned long flags;
if ((config->src_addr_width != DMA_SLAVE_BUSWIDTH_4_BYTES) ||
(config->dst_addr_width != DMA_SLAVE_BUSWIDTH_4_BYTES))
return -EINVAL;
spin_lock_irqsave(&schan->lock, flags);
schan->mode = (config->src_maxburst == 4 ? 1 : 0);
spin_unlock_irqrestore(&schan->lock, flags);
return 0;
}
static int sirfsoc_dma_terminate_all(struct sirfsoc_dma_chan *schan)
{
struct sirfsoc_dma *sdma = dma_chan_to_sirfsoc_dma(&schan->chan);
int cid = schan->chan.chan_id;
unsigned long flags;
writel_relaxed(readl_relaxed(sdma->base + SIRFSOC_DMA_INT_EN) &
~(1 << cid), sdma->base + SIRFSOC_DMA_INT_EN);
writel_relaxed(1 << cid, sdma->base + SIRFSOC_DMA_CH_VALID);
writel_relaxed(readl_relaxed(sdma->base + SIRFSOC_DMA_CH_LOOP_CTRL)
& ~((1 << cid) | 1 << (cid + 16)),
sdma->base + SIRFSOC_DMA_CH_LOOP_CTRL);
spin_lock_irqsave(&schan->lock, flags);
list_splice_tail_init(&schan->active, &schan->free);
list_splice_tail_init(&schan->queued, &schan->free);
spin_unlock_irqrestore(&schan->lock, flags);
return 0;
}
static int sirfsoc_dma_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
struct dma_slave_config *config;
struct sirfsoc_dma_chan *schan = dma_chan_to_sirfsoc_dma_chan(chan);
switch (cmd) {
case DMA_TERMINATE_ALL:
return sirfsoc_dma_terminate_all(schan);
case DMA_SLAVE_CONFIG:
config = (struct dma_slave_config *)arg;
return sirfsoc_dma_slave_config(schan, config);
default:
break;
}
return -ENOSYS;
}
static int sirfsoc_dma_alloc_chan_resources(struct dma_chan *chan)
{
struct sirfsoc_dma *sdma = dma_chan_to_sirfsoc_dma(chan);
struct sirfsoc_dma_chan *schan = dma_chan_to_sirfsoc_dma_chan(chan);
struct sirfsoc_dma_desc *sdesc;
unsigned long flags;
LIST_HEAD(descs);
int i;
for (i = 0; i < SIRFSOC_DMA_DESCRIPTORS; i++) {
sdesc = kzalloc(sizeof(*sdesc), GFP_KERNEL);
if (!sdesc) {
dev_notice(sdma->dma.dev, "Memory allocation error. "
"Allocated only %u descriptors\n", i);
break;
}
dma_async_tx_descriptor_init(&sdesc->desc, chan);
sdesc->desc.flags = DMA_CTRL_ACK;
sdesc->desc.tx_submit = sirfsoc_dma_tx_submit;
list_add_tail(&sdesc->node, &descs);
}
if (i == 0)
return -ENOMEM;
spin_lock_irqsave(&schan->lock, flags);
list_splice_tail_init(&descs, &schan->free);
spin_unlock_irqrestore(&schan->lock, flags);
return i;
}
static void sirfsoc_dma_free_chan_resources(struct dma_chan *chan)
{
struct sirfsoc_dma_chan *schan = dma_chan_to_sirfsoc_dma_chan(chan);
struct sirfsoc_dma_desc *sdesc, *tmp;
unsigned long flags;
LIST_HEAD(descs);
spin_lock_irqsave(&schan->lock, flags);
BUG_ON(!list_empty(&schan->prepared));
BUG_ON(!list_empty(&schan->queued));
BUG_ON(!list_empty(&schan->active));
BUG_ON(!list_empty(&schan->completed));
list_splice_tail_init(&schan->free, &descs);
spin_unlock_irqrestore(&schan->lock, flags);
list_for_each_entry_safe(sdesc, tmp, &descs, node)
kfree(sdesc);
}
static void sirfsoc_dma_issue_pending(struct dma_chan *chan)
{
struct sirfsoc_dma_chan *schan = dma_chan_to_sirfsoc_dma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&schan->lock, flags);
if (list_empty(&schan->active) && !list_empty(&schan->queued))
sirfsoc_dma_execute(schan);
spin_unlock_irqrestore(&schan->lock, flags);
}
static enum dma_status
sirfsoc_dma_tx_status(struct dma_chan *chan, dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct sirfsoc_dma_chan *schan = dma_chan_to_sirfsoc_dma_chan(chan);
unsigned long flags;
enum dma_status ret;
spin_lock_irqsave(&schan->lock, flags);
ret = dma_cookie_status(chan, cookie, txstate);
spin_unlock_irqrestore(&schan->lock, flags);
return ret;
}
static struct dma_async_tx_descriptor *sirfsoc_dma_prep_interleaved(
struct dma_chan *chan, struct dma_interleaved_template *xt,
unsigned long flags)
{
struct sirfsoc_dma *sdma = dma_chan_to_sirfsoc_dma(chan);
struct sirfsoc_dma_chan *schan = dma_chan_to_sirfsoc_dma_chan(chan);
struct sirfsoc_dma_desc *sdesc = NULL;
unsigned long iflags;
int ret;
if ((xt->dir != DMA_MEM_TO_DEV) && (xt->dir != DMA_DEV_TO_MEM)) {
ret = -EINVAL;
goto err_dir;
}
spin_lock_irqsave(&schan->lock, iflags);
if (!list_empty(&schan->free)) {
sdesc = list_first_entry(&schan->free, struct sirfsoc_dma_desc,
node);
list_del(&sdesc->node);
}
spin_unlock_irqrestore(&schan->lock, iflags);
if (!sdesc) {
sirfsoc_dma_process_completed(sdma);
ret = 0;
goto no_desc;
}
spin_lock_irqsave(&schan->lock, iflags);
if ((xt->frame_size == 1) && (xt->numf > 0)) {
sdesc->cyclic = 0;
sdesc->xlen = xt->sgl[0].size / SIRFSOC_DMA_WORD_LEN;
sdesc->width = (xt->sgl[0].size + xt->sgl[0].icg) /
SIRFSOC_DMA_WORD_LEN;
sdesc->ylen = xt->numf - 1;
if (xt->dir == DMA_MEM_TO_DEV) {
sdesc->addr = xt->src_start;
sdesc->dir = 1;
} else {
sdesc->addr = xt->dst_start;
sdesc->dir = 0;
}
list_add_tail(&sdesc->node, &schan->prepared);
} else {
pr_err("sirfsoc DMA Invalid xfer\n");
ret = -EINVAL;
goto err_xfer;
}
spin_unlock_irqrestore(&schan->lock, iflags);
return &sdesc->desc;
err_xfer:
spin_unlock_irqrestore(&schan->lock, iflags);
no_desc:
err_dir:
return ERR_PTR(ret);
}
static struct dma_async_tx_descriptor *
sirfsoc_dma_prep_cyclic(struct dma_chan *chan, dma_addr_t addr,
size_t buf_len, size_t period_len,
enum dma_transfer_direction direction, unsigned long flags, void *context)
{
struct sirfsoc_dma_chan *schan = dma_chan_to_sirfsoc_dma_chan(chan);
struct sirfsoc_dma_desc *sdesc = NULL;
unsigned long iflags;
if (buf_len != 2 * period_len)
return ERR_PTR(-EINVAL);
spin_lock_irqsave(&schan->lock, iflags);
if (!list_empty(&schan->free)) {
sdesc = list_first_entry(&schan->free, struct sirfsoc_dma_desc,
node);
list_del(&sdesc->node);
}
spin_unlock_irqrestore(&schan->lock, iflags);
if (!sdesc)
return 0;
spin_lock_irqsave(&schan->lock, iflags);
sdesc->addr = addr;
sdesc->cyclic = 1;
sdesc->xlen = 0;
sdesc->ylen = buf_len / SIRFSOC_DMA_WORD_LEN - 1;
sdesc->width = 1;
list_add_tail(&sdesc->node, &schan->prepared);
spin_unlock_irqrestore(&schan->lock, iflags);
return &sdesc->desc;
}
bool sirfsoc_dma_filter_id(struct dma_chan *chan, void *chan_id)
{
unsigned int ch_nr = (unsigned int) chan_id;
if (ch_nr == chan->chan_id +
chan->device->dev_id * SIRFSOC_DMA_CHANNELS)
return true;
return false;
}
static int __devinit sirfsoc_dma_probe(struct platform_device *op)
{
struct device_node *dn = op->dev.of_node;
struct device *dev = &op->dev;
struct dma_device *dma;
struct sirfsoc_dma *sdma;
struct sirfsoc_dma_chan *schan;
struct resource res;
ulong regs_start, regs_size;
u32 id;
int ret, i;
sdma = devm_kzalloc(dev, sizeof(*sdma), GFP_KERNEL);
if (!sdma) {
dev_err(dev, "Memory exhausted!\n");
return -ENOMEM;
}
if (of_property_read_u32(dn, "cell-index", &id)) {
dev_err(dev, "Fail to get DMAC index\n");
return -ENODEV;
}
sdma->irq = irq_of_parse_and_map(dn, 0);
if (sdma->irq == NO_IRQ) {
dev_err(dev, "Error mapping IRQ!\n");
return -EINVAL;
}
ret = of_address_to_resource(dn, 0, &res);
if (ret) {
dev_err(dev, "Error parsing memory region!\n");
goto irq_dispose;
}
regs_start = res.start;
regs_size = resource_size(&res);
sdma->base = devm_ioremap(dev, regs_start, regs_size);
if (!sdma->base) {
dev_err(dev, "Error mapping memory region!\n");
ret = -ENOMEM;
goto irq_dispose;
}
ret = request_irq(sdma->irq, &sirfsoc_dma_irq, 0, DRV_NAME, sdma);
if (ret) {
dev_err(dev, "Error requesting IRQ!\n");
ret = -EINVAL;
goto irq_dispose;
}
dma = &sdma->dma;
dma->dev = dev;
dma->chancnt = SIRFSOC_DMA_CHANNELS;
dma->device_alloc_chan_resources = sirfsoc_dma_alloc_chan_resources;
dma->device_free_chan_resources = sirfsoc_dma_free_chan_resources;
dma->device_issue_pending = sirfsoc_dma_issue_pending;
dma->device_control = sirfsoc_dma_control;
dma->device_tx_status = sirfsoc_dma_tx_status;
dma->device_prep_interleaved_dma = sirfsoc_dma_prep_interleaved;
dma->device_prep_dma_cyclic = sirfsoc_dma_prep_cyclic;
INIT_LIST_HEAD(&dma->channels);
dma_cap_set(DMA_SLAVE, dma->cap_mask);
dma_cap_set(DMA_CYCLIC, dma->cap_mask);
dma_cap_set(DMA_INTERLEAVE, dma->cap_mask);
dma_cap_set(DMA_PRIVATE, dma->cap_mask);
for (i = 0; i < dma->chancnt; i++) {
schan = &sdma->channels[i];
schan->chan.device = dma;
dma_cookie_init(&schan->chan);
INIT_LIST_HEAD(&schan->free);
INIT_LIST_HEAD(&schan->prepared);
INIT_LIST_HEAD(&schan->queued);
INIT_LIST_HEAD(&schan->active);
INIT_LIST_HEAD(&schan->completed);
spin_lock_init(&schan->lock);
list_add_tail(&schan->chan.device_node, &dma->channels);
}
tasklet_init(&sdma->tasklet, sirfsoc_dma_tasklet, (unsigned long)sdma);
dev_set_drvdata(dev, sdma);
ret = dma_async_device_register(dma);
if (ret)
goto free_irq;
dev_info(dev, "initialized SIRFSOC DMAC driver\n");
return 0;
free_irq:
free_irq(sdma->irq, sdma);
irq_dispose:
irq_dispose_mapping(sdma->irq);
return ret;
}
static int __devexit sirfsoc_dma_remove(struct platform_device *op)
{
struct device *dev = &op->dev;
struct sirfsoc_dma *sdma = dev_get_drvdata(dev);
dma_async_device_unregister(&sdma->dma);
free_irq(sdma->irq, sdma);
irq_dispose_mapping(sdma->irq);
return 0;
}
