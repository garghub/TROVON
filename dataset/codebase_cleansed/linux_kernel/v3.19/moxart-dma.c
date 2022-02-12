static struct device *chan2dev(struct dma_chan *chan)
{
return &chan->dev->device;
}
static inline struct moxart_chan *to_moxart_dma_chan(struct dma_chan *c)
{
return container_of(c, struct moxart_chan, vc.chan);
}
static inline struct moxart_desc *to_moxart_dma_desc(
struct dma_async_tx_descriptor *t)
{
return container_of(t, struct moxart_desc, vd.tx);
}
static void moxart_dma_desc_free(struct virt_dma_desc *vd)
{
kfree(container_of(vd, struct moxart_desc, vd));
}
static int moxart_terminate_all(struct dma_chan *chan)
{
struct moxart_chan *ch = to_moxart_dma_chan(chan);
unsigned long flags;
LIST_HEAD(head);
u32 ctrl;
dev_dbg(chan2dev(chan), "%s: ch=%p\n", __func__, ch);
spin_lock_irqsave(&ch->vc.lock, flags);
if (ch->desc)
ch->desc = NULL;
ctrl = readl(ch->base + REG_OFF_CTRL);
ctrl &= ~(APB_DMA_ENABLE | APB_DMA_FIN_INT_EN | APB_DMA_ERR_INT_EN);
writel(ctrl, ch->base + REG_OFF_CTRL);
vchan_get_all_descriptors(&ch->vc, &head);
spin_unlock_irqrestore(&ch->vc.lock, flags);
vchan_dma_desc_free_list(&ch->vc, &head);
return 0;
}
static int moxart_slave_config(struct dma_chan *chan,
struct dma_slave_config *cfg)
{
struct moxart_chan *ch = to_moxart_dma_chan(chan);
u32 ctrl;
ch->cfg = *cfg;
ctrl = readl(ch->base + REG_OFF_CTRL);
ctrl |= APB_DMA_BURST_MODE;
ctrl &= ~(APB_DMA_DEST_MASK | APB_DMA_SOURCE_MASK);
ctrl &= ~(APB_DMA_DEST_REQ_NO_MASK | APB_DMA_SOURCE_REQ_NO_MASK);
switch (ch->cfg.src_addr_width) {
case DMA_SLAVE_BUSWIDTH_1_BYTE:
ctrl |= APB_DMA_DATA_WIDTH_1;
if (ch->cfg.direction != DMA_MEM_TO_DEV)
ctrl |= APB_DMA_DEST_INC_1_4;
else
ctrl |= APB_DMA_SOURCE_INC_1_4;
break;
case DMA_SLAVE_BUSWIDTH_2_BYTES:
ctrl |= APB_DMA_DATA_WIDTH_2;
if (ch->cfg.direction != DMA_MEM_TO_DEV)
ctrl |= APB_DMA_DEST_INC_2_8;
else
ctrl |= APB_DMA_SOURCE_INC_2_8;
break;
case DMA_SLAVE_BUSWIDTH_4_BYTES:
ctrl &= ~APB_DMA_DATA_WIDTH;
if (ch->cfg.direction != DMA_MEM_TO_DEV)
ctrl |= APB_DMA_DEST_INC_4_16;
else
ctrl |= APB_DMA_SOURCE_INC_4_16;
break;
default:
return -EINVAL;
}
if (ch->cfg.direction == DMA_MEM_TO_DEV) {
ctrl &= ~APB_DMA_DEST_SELECT;
ctrl |= APB_DMA_SOURCE_SELECT;
ctrl |= (ch->line_reqno << 16 &
APB_DMA_DEST_REQ_NO_MASK);
} else {
ctrl |= APB_DMA_DEST_SELECT;
ctrl &= ~APB_DMA_SOURCE_SELECT;
ctrl |= (ch->line_reqno << 24 &
APB_DMA_SOURCE_REQ_NO_MASK);
}
writel(ctrl, ch->base + REG_OFF_CTRL);
return 0;
}
static int moxart_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
int ret = 0;
switch (cmd) {
case DMA_PAUSE:
case DMA_RESUME:
return -EINVAL;
case DMA_TERMINATE_ALL:
moxart_terminate_all(chan);
break;
case DMA_SLAVE_CONFIG:
ret = moxart_slave_config(chan, (struct dma_slave_config *)arg);
break;
default:
ret = -ENOSYS;
}
return ret;
}
static struct dma_async_tx_descriptor *moxart_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction dir,
unsigned long tx_flags, void *context)
{
struct moxart_chan *ch = to_moxart_dma_chan(chan);
struct moxart_desc *d;
enum dma_slave_buswidth dev_width;
dma_addr_t dev_addr;
struct scatterlist *sgent;
unsigned int es;
unsigned int i;
if (!is_slave_direction(dir)) {
dev_err(chan2dev(chan), "%s: invalid DMA direction\n",
__func__);
return NULL;
}
if (dir == DMA_DEV_TO_MEM) {
dev_addr = ch->cfg.src_addr;
dev_width = ch->cfg.src_addr_width;
} else {
dev_addr = ch->cfg.dst_addr;
dev_width = ch->cfg.dst_addr_width;
}
switch (dev_width) {
case DMA_SLAVE_BUSWIDTH_1_BYTE:
es = MOXART_DMA_DATA_TYPE_S8;
break;
case DMA_SLAVE_BUSWIDTH_2_BYTES:
es = MOXART_DMA_DATA_TYPE_S16;
break;
case DMA_SLAVE_BUSWIDTH_4_BYTES:
es = MOXART_DMA_DATA_TYPE_S32;
break;
default:
dev_err(chan2dev(chan), "%s: unsupported data width (%u)\n",
__func__, dev_width);
return NULL;
}
d = kzalloc(sizeof(*d) + sg_len * sizeof(d->sg[0]), GFP_ATOMIC);
if (!d)
return NULL;
d->dma_dir = dir;
d->dev_addr = dev_addr;
d->es = es;
for_each_sg(sgl, sgent, sg_len, i) {
d->sg[i].addr = sg_dma_address(sgent);
d->sg[i].len = sg_dma_len(sgent);
}
d->sglen = sg_len;
ch->error = 0;
return vchan_tx_prep(&ch->vc, &d->vd, tx_flags);
}
static struct dma_chan *moxart_of_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct moxart_dmadev *mdc = ofdma->of_dma_data;
struct dma_chan *chan;
struct moxart_chan *ch;
chan = dma_get_any_slave_channel(&mdc->dma_slave);
if (!chan)
return NULL;
ch = to_moxart_dma_chan(chan);
ch->line_reqno = dma_spec->args[0];
return chan;
}
static int moxart_alloc_chan_resources(struct dma_chan *chan)
{
struct moxart_chan *ch = to_moxart_dma_chan(chan);
dev_dbg(chan2dev(chan), "%s: allocating channel #%u\n",
__func__, ch->ch_num);
ch->allocated = 1;
return 0;
}
static void moxart_free_chan_resources(struct dma_chan *chan)
{
struct moxart_chan *ch = to_moxart_dma_chan(chan);
vchan_free_chan_resources(&ch->vc);
dev_dbg(chan2dev(chan), "%s: freeing channel #%u\n",
__func__, ch->ch_num);
ch->allocated = 0;
}
static void moxart_dma_set_params(struct moxart_chan *ch, dma_addr_t src_addr,
dma_addr_t dst_addr)
{
writel(src_addr, ch->base + REG_OFF_ADDRESS_SOURCE);
writel(dst_addr, ch->base + REG_OFF_ADDRESS_DEST);
}
static void moxart_set_transfer_params(struct moxart_chan *ch, unsigned int len)
{
struct moxart_desc *d = ch->desc;
unsigned int sglen_div = es_bytes[d->es];
d->dma_cycles = len >> sglen_div;
writel(d->dma_cycles, ch->base + REG_OFF_CYCLES);
dev_dbg(chan2dev(&ch->vc.chan), "%s: set %u DMA cycles (len=%u)\n",
__func__, d->dma_cycles, len);
}
static void moxart_start_dma(struct moxart_chan *ch)
{
u32 ctrl;
ctrl = readl(ch->base + REG_OFF_CTRL);
ctrl |= (APB_DMA_ENABLE | APB_DMA_FIN_INT_EN | APB_DMA_ERR_INT_EN);
writel(ctrl, ch->base + REG_OFF_CTRL);
}
static void moxart_dma_start_sg(struct moxart_chan *ch, unsigned int idx)
{
struct moxart_desc *d = ch->desc;
struct moxart_sg *sg = ch->desc->sg + idx;
if (ch->desc->dma_dir == DMA_MEM_TO_DEV)
moxart_dma_set_params(ch, sg->addr, d->dev_addr);
else if (ch->desc->dma_dir == DMA_DEV_TO_MEM)
moxart_dma_set_params(ch, d->dev_addr, sg->addr);
moxart_set_transfer_params(ch, sg->len);
moxart_start_dma(ch);
}
static void moxart_dma_start_desc(struct dma_chan *chan)
{
struct moxart_chan *ch = to_moxart_dma_chan(chan);
struct virt_dma_desc *vd;
vd = vchan_next_desc(&ch->vc);
if (!vd) {
ch->desc = NULL;
return;
}
list_del(&vd->node);
ch->desc = to_moxart_dma_desc(&vd->tx);
ch->sgidx = 0;
moxart_dma_start_sg(ch, 0);
}
static void moxart_issue_pending(struct dma_chan *chan)
{
struct moxart_chan *ch = to_moxart_dma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&ch->vc.lock, flags);
if (vchan_issue_pending(&ch->vc) && !ch->desc)
moxart_dma_start_desc(chan);
spin_unlock_irqrestore(&ch->vc.lock, flags);
}
static size_t moxart_dma_desc_size(struct moxart_desc *d,
unsigned int completed_sgs)
{
unsigned int i;
size_t size;
for (size = i = completed_sgs; i < d->sglen; i++)
size += d->sg[i].len;
return size;
}
static size_t moxart_dma_desc_size_in_flight(struct moxart_chan *ch)
{
size_t size;
unsigned int completed_cycles, cycles;
size = moxart_dma_desc_size(ch->desc, ch->sgidx);
cycles = readl(ch->base + REG_OFF_CYCLES);
completed_cycles = (ch->desc->dma_cycles - cycles);
size -= completed_cycles << es_bytes[ch->desc->es];
dev_dbg(chan2dev(&ch->vc.chan), "%s: size=%zu\n", __func__, size);
return size;
}
static enum dma_status moxart_tx_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct moxart_chan *ch = to_moxart_dma_chan(chan);
struct virt_dma_desc *vd;
struct moxart_desc *d;
enum dma_status ret;
unsigned long flags;
ret = dma_cookie_status(chan, cookie, txstate);
spin_lock_irqsave(&ch->vc.lock, flags);
vd = vchan_find_desc(&ch->vc, cookie);
if (vd) {
d = to_moxart_dma_desc(&vd->tx);
txstate->residue = moxart_dma_desc_size(d, 0);
} else if (ch->desc && ch->desc->vd.tx.cookie == cookie) {
txstate->residue = moxart_dma_desc_size_in_flight(ch);
}
spin_unlock_irqrestore(&ch->vc.lock, flags);
if (ch->error)
return DMA_ERROR;
return ret;
}
static void moxart_dma_init(struct dma_device *dma, struct device *dev)
{
dma->device_prep_slave_sg = moxart_prep_slave_sg;
dma->device_alloc_chan_resources = moxart_alloc_chan_resources;
dma->device_free_chan_resources = moxart_free_chan_resources;
dma->device_issue_pending = moxart_issue_pending;
dma->device_tx_status = moxart_tx_status;
dma->device_control = moxart_control;
dma->dev = dev;
INIT_LIST_HEAD(&dma->channels);
}
static irqreturn_t moxart_dma_interrupt(int irq, void *devid)
{
struct moxart_dmadev *mc = devid;
struct moxart_chan *ch = &mc->slave_chans[0];
unsigned int i;
unsigned long flags;
u32 ctrl;
dev_dbg(chan2dev(&ch->vc.chan), "%s\n", __func__);
for (i = 0; i < APB_DMA_MAX_CHANNEL; i++, ch++) {
if (!ch->allocated)
continue;
ctrl = readl(ch->base + REG_OFF_CTRL);
dev_dbg(chan2dev(&ch->vc.chan), "%s: ch=%p ch->base=%p ctrl=%x\n",
__func__, ch, ch->base, ctrl);
if (ctrl & APB_DMA_FIN_INT_STS) {
ctrl &= ~APB_DMA_FIN_INT_STS;
if (ch->desc) {
spin_lock_irqsave(&ch->vc.lock, flags);
if (++ch->sgidx < ch->desc->sglen) {
moxart_dma_start_sg(ch, ch->sgidx);
} else {
vchan_cookie_complete(&ch->desc->vd);
moxart_dma_start_desc(&ch->vc.chan);
}
spin_unlock_irqrestore(&ch->vc.lock, flags);
}
}
if (ctrl & APB_DMA_ERR_INT_STS) {
ctrl &= ~APB_DMA_ERR_INT_STS;
ch->error = 1;
}
writel(ctrl, ch->base + REG_OFF_CTRL);
}
return IRQ_HANDLED;
}
static int moxart_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct resource *res;
static void __iomem *dma_base_addr;
int ret, i;
unsigned int irq;
struct moxart_chan *ch;
struct moxart_dmadev *mdc;
mdc = devm_kzalloc(dev, sizeof(*mdc), GFP_KERNEL);
if (!mdc) {
dev_err(dev, "can't allocate DMA container\n");
return -ENOMEM;
}
irq = irq_of_parse_and_map(node, 0);
if (irq == NO_IRQ) {
dev_err(dev, "no IRQ resource\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dma_base_addr = devm_ioremap_resource(dev, res);
if (IS_ERR(dma_base_addr))
return PTR_ERR(dma_base_addr);
dma_cap_zero(mdc->dma_slave.cap_mask);
dma_cap_set(DMA_SLAVE, mdc->dma_slave.cap_mask);
dma_cap_set(DMA_PRIVATE, mdc->dma_slave.cap_mask);
moxart_dma_init(&mdc->dma_slave, dev);
ch = &mdc->slave_chans[0];
for (i = 0; i < APB_DMA_MAX_CHANNEL; i++, ch++) {
ch->ch_num = i;
ch->base = dma_base_addr + i * REG_OFF_CHAN_SIZE;
ch->allocated = 0;
ch->vc.desc_free = moxart_dma_desc_free;
vchan_init(&ch->vc, &mdc->dma_slave);
dev_dbg(dev, "%s: chs[%d]: ch->ch_num=%u ch->base=%p\n",
__func__, i, ch->ch_num, ch->base);
}
platform_set_drvdata(pdev, mdc);
ret = devm_request_irq(dev, irq, moxart_dma_interrupt, 0,
"moxart-dma-engine", mdc);
if (ret) {
dev_err(dev, "devm_request_irq failed\n");
return ret;
}
ret = dma_async_device_register(&mdc->dma_slave);
if (ret) {
dev_err(dev, "dma_async_device_register failed\n");
return ret;
}
ret = of_dma_controller_register(node, moxart_of_xlate, mdc);
if (ret) {
dev_err(dev, "of_dma_controller_register failed\n");
dma_async_device_unregister(&mdc->dma_slave);
return ret;
}
dev_dbg(dev, "%s: IRQ=%u\n", __func__, irq);
return 0;
}
static int moxart_remove(struct platform_device *pdev)
{
struct moxart_dmadev *m = platform_get_drvdata(pdev);
dma_async_device_unregister(&m->dma_slave);
if (pdev->dev.of_node)
of_dma_controller_free(pdev->dev.of_node);
return 0;
}
static int moxart_init(void)
{
return platform_driver_register(&moxart_driver);
}
static void __exit moxart_exit(void)
{
platform_driver_unregister(&moxart_driver);
}
