static inline struct bcm2835_dmadev *to_bcm2835_dma_dev(struct dma_device *d)
{
return container_of(d, struct bcm2835_dmadev, ddev);
}
static inline struct bcm2835_chan *to_bcm2835_dma_chan(struct dma_chan *c)
{
return container_of(c, struct bcm2835_chan, vc.chan);
}
static inline struct bcm2835_desc *to_bcm2835_dma_desc(
struct dma_async_tx_descriptor *t)
{
return container_of(t, struct bcm2835_desc, vd.tx);
}
static void bcm2835_dma_desc_free(struct virt_dma_desc *vd)
{
struct bcm2835_desc *desc = container_of(vd, struct bcm2835_desc, vd);
dma_free_coherent(desc->vd.tx.chan->device->dev,
desc->control_block_size,
desc->control_block_base,
desc->control_block_base_phys);
kfree(desc);
}
static int bcm2835_dma_abort(void __iomem *chan_base)
{
unsigned long cs;
long int timeout = 10000;
cs = readl(chan_base + BCM2835_DMA_CS);
if (!(cs & BCM2835_DMA_ACTIVE))
return 0;
writel(0, chan_base + BCM2835_DMA_CS);
while ((cs & BCM2835_DMA_ISPAUSED) && --timeout) {
cpu_relax();
cs = readl(chan_base + BCM2835_DMA_CS);
}
if (!timeout)
return -ETIMEDOUT;
if (!(cs & BCM2835_DMA_ACTIVE))
return 0;
writel(0, chan_base + BCM2835_DMA_NEXTCB);
writel(BCM2835_DMA_ABORT | BCM2835_DMA_ACTIVE,
chan_base + BCM2835_DMA_CS);
return 0;
}
static void bcm2835_dma_start_desc(struct bcm2835_chan *c)
{
struct virt_dma_desc *vd = vchan_next_desc(&c->vc);
struct bcm2835_desc *d;
if (!vd) {
c->desc = NULL;
return;
}
list_del(&vd->node);
c->desc = d = to_bcm2835_dma_desc(&vd->tx);
writel(d->control_block_base_phys, c->chan_base + BCM2835_DMA_ADDR);
writel(BCM2835_DMA_ACTIVE, c->chan_base + BCM2835_DMA_CS);
}
static irqreturn_t bcm2835_dma_callback(int irq, void *data)
{
struct bcm2835_chan *c = data;
struct bcm2835_desc *d;
unsigned long flags;
spin_lock_irqsave(&c->vc.lock, flags);
writel(BCM2835_DMA_INT, c->chan_base + BCM2835_DMA_CS);
d = c->desc;
if (d) {
vchan_cyclic_callback(&d->vd);
}
writel(BCM2835_DMA_ACTIVE, c->chan_base + BCM2835_DMA_CS);
spin_unlock_irqrestore(&c->vc.lock, flags);
return IRQ_HANDLED;
}
static int bcm2835_dma_alloc_chan_resources(struct dma_chan *chan)
{
struct bcm2835_chan *c = to_bcm2835_dma_chan(chan);
dev_dbg(c->vc.chan.device->dev,
"Allocating DMA channel %d\n", c->ch);
return request_irq(c->irq_number,
bcm2835_dma_callback, 0, "DMA IRQ", c);
}
static void bcm2835_dma_free_chan_resources(struct dma_chan *chan)
{
struct bcm2835_chan *c = to_bcm2835_dma_chan(chan);
vchan_free_chan_resources(&c->vc);
free_irq(c->irq_number, c);
dev_dbg(c->vc.chan.device->dev, "Freeing DMA channel %u\n", c->ch);
}
static size_t bcm2835_dma_desc_size(struct bcm2835_desc *d)
{
return d->size;
}
static size_t bcm2835_dma_desc_size_pos(struct bcm2835_desc *d, dma_addr_t addr)
{
unsigned int i;
size_t size;
for (size = i = 0; i < d->frames; i++) {
struct bcm2835_dma_cb *control_block =
&d->control_block_base[i];
size_t this_size = control_block->length;
dma_addr_t dma;
if (d->dir == DMA_DEV_TO_MEM)
dma = control_block->dst;
else
dma = control_block->src;
if (size)
size += this_size;
else if (addr >= dma && addr < dma + this_size)
size += dma + this_size - addr;
}
return size;
}
static enum dma_status bcm2835_dma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie, struct dma_tx_state *txstate)
{
struct bcm2835_chan *c = to_bcm2835_dma_chan(chan);
struct virt_dma_desc *vd;
enum dma_status ret;
unsigned long flags;
ret = dma_cookie_status(chan, cookie, txstate);
if (ret == DMA_COMPLETE || !txstate)
return ret;
spin_lock_irqsave(&c->vc.lock, flags);
vd = vchan_find_desc(&c->vc, cookie);
if (vd) {
txstate->residue =
bcm2835_dma_desc_size(to_bcm2835_dma_desc(&vd->tx));
} else if (c->desc && c->desc->vd.tx.cookie == cookie) {
struct bcm2835_desc *d = c->desc;
dma_addr_t pos;
if (d->dir == DMA_MEM_TO_DEV)
pos = readl(c->chan_base + BCM2835_DMA_SOURCE_AD);
else if (d->dir == DMA_DEV_TO_MEM)
pos = readl(c->chan_base + BCM2835_DMA_DEST_AD);
else
pos = 0;
txstate->residue = bcm2835_dma_desc_size_pos(d, pos);
} else {
txstate->residue = 0;
}
spin_unlock_irqrestore(&c->vc.lock, flags);
return ret;
}
static void bcm2835_dma_issue_pending(struct dma_chan *chan)
{
struct bcm2835_chan *c = to_bcm2835_dma_chan(chan);
unsigned long flags;
c->cyclic = true;
spin_lock_irqsave(&c->vc.lock, flags);
if (vchan_issue_pending(&c->vc) && !c->desc)
bcm2835_dma_start_desc(c);
spin_unlock_irqrestore(&c->vc.lock, flags);
}
static struct dma_async_tx_descriptor *bcm2835_dma_prep_dma_cyclic(
struct dma_chan *chan, dma_addr_t buf_addr, size_t buf_len,
size_t period_len, enum dma_transfer_direction direction,
unsigned long flags, void *context)
{
struct bcm2835_chan *c = to_bcm2835_dma_chan(chan);
enum dma_slave_buswidth dev_width;
struct bcm2835_desc *d;
dma_addr_t dev_addr;
unsigned int es, sync_type;
unsigned int frame;
if (!is_slave_direction(direction)) {
dev_err(chan->device->dev, "%s: bad direction?\n", __func__);
return NULL;
}
if (direction == DMA_DEV_TO_MEM) {
dev_addr = c->cfg.src_addr;
dev_width = c->cfg.src_addr_width;
sync_type = BCM2835_DMA_S_DREQ;
} else {
dev_addr = c->cfg.dst_addr;
dev_width = c->cfg.dst_addr_width;
sync_type = BCM2835_DMA_D_DREQ;
}
switch (dev_width) {
case DMA_SLAVE_BUSWIDTH_4_BYTES:
es = BCM2835_DMA_DATA_TYPE_S32;
break;
default:
return NULL;
}
d = kzalloc(sizeof(*d), GFP_NOWAIT);
if (!d)
return NULL;
d->dir = direction;
d->frames = buf_len / period_len;
d->control_block_size = d->frames * sizeof(struct bcm2835_dma_cb);
d->control_block_base = dma_zalloc_coherent(chan->device->dev,
d->control_block_size, &d->control_block_base_phys,
GFP_NOWAIT);
if (!d->control_block_base) {
kfree(d);
return NULL;
}
for (frame = 0; frame < d->frames; frame++) {
struct bcm2835_dma_cb *control_block =
&d->control_block_base[frame];
if (d->dir == DMA_DEV_TO_MEM) {
control_block->info = BCM2835_DMA_D_INC;
control_block->src = dev_addr;
control_block->dst = buf_addr + frame * period_len;
} else {
control_block->info = BCM2835_DMA_S_INC;
control_block->src = buf_addr + frame * period_len;
control_block->dst = dev_addr;
}
control_block->info |= BCM2835_DMA_INT_EN;
if (sync_type != 0)
control_block->info |= sync_type;
if (c->dreq != 0)
control_block->info |=
BCM2835_DMA_PER_MAP(c->dreq);
control_block->length = period_len;
d->size += control_block->length;
control_block->next = d->control_block_base_phys +
sizeof(struct bcm2835_dma_cb)
* ((frame + 1) % d->frames);
}
return vchan_tx_prep(&c->vc, &d->vd, flags);
}
static int bcm2835_dma_slave_config(struct bcm2835_chan *c,
struct dma_slave_config *cfg)
{
if ((cfg->direction == DMA_DEV_TO_MEM &&
cfg->src_addr_width != DMA_SLAVE_BUSWIDTH_4_BYTES) ||
(cfg->direction == DMA_MEM_TO_DEV &&
cfg->dst_addr_width != DMA_SLAVE_BUSWIDTH_4_BYTES) ||
!is_slave_direction(cfg->direction)) {
return -EINVAL;
}
c->cfg = *cfg;
return 0;
}
static int bcm2835_dma_terminate_all(struct bcm2835_chan *c)
{
struct bcm2835_dmadev *d = to_bcm2835_dma_dev(c->vc.chan.device);
unsigned long flags;
int timeout = 10000;
LIST_HEAD(head);
spin_lock_irqsave(&c->vc.lock, flags);
spin_lock(&d->lock);
list_del_init(&c->node);
spin_unlock(&d->lock);
if (c->desc) {
c->desc = NULL;
bcm2835_dma_abort(c->chan_base);
while (--timeout) {
if (!(readl(c->chan_base + BCM2835_DMA_CS) &
BCM2835_DMA_ACTIVE))
break;
cpu_relax();
}
if (!timeout)
dev_err(d->ddev.dev, "DMA transfer could not be terminated\n");
}
vchan_get_all_descriptors(&c->vc, &head);
spin_unlock_irqrestore(&c->vc.lock, flags);
vchan_dma_desc_free_list(&c->vc, &head);
return 0;
}
static int bcm2835_dma_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
struct bcm2835_chan *c = to_bcm2835_dma_chan(chan);
switch (cmd) {
case DMA_SLAVE_CONFIG:
return bcm2835_dma_slave_config(c,
(struct dma_slave_config *)arg);
case DMA_TERMINATE_ALL:
return bcm2835_dma_terminate_all(c);
default:
return -ENXIO;
}
}
static int bcm2835_dma_chan_init(struct bcm2835_dmadev *d, int chan_id, int irq)
{
struct bcm2835_chan *c;
c = devm_kzalloc(d->ddev.dev, sizeof(*c), GFP_KERNEL);
if (!c)
return -ENOMEM;
c->vc.desc_free = bcm2835_dma_desc_free;
vchan_init(&c->vc, &d->ddev);
INIT_LIST_HEAD(&c->node);
d->ddev.chancnt++;
c->chan_base = BCM2835_DMA_CHANIO(d->base, chan_id);
c->ch = chan_id;
c->irq_number = irq;
return 0;
}
static void bcm2835_dma_free(struct bcm2835_dmadev *od)
{
struct bcm2835_chan *c, *next;
list_for_each_entry_safe(c, next, &od->ddev.channels,
vc.chan.device_node) {
list_del(&c->vc.chan.device_node);
tasklet_kill(&c->vc.task);
}
}
static struct dma_chan *bcm2835_dma_xlate(struct of_phandle_args *spec,
struct of_dma *ofdma)
{
struct bcm2835_dmadev *d = ofdma->of_dma_data;
struct dma_chan *chan;
chan = dma_get_any_slave_channel(&d->ddev);
if (!chan)
return NULL;
to_bcm2835_dma_chan(chan)->dreq = spec->args[0];
return chan;
}
static int bcm2835_dma_device_slave_caps(struct dma_chan *dchan,
struct dma_slave_caps *caps)
{
caps->src_addr_widths = BIT(DMA_SLAVE_BUSWIDTH_4_BYTES);
caps->dstn_addr_widths = BIT(DMA_SLAVE_BUSWIDTH_4_BYTES);
caps->directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
caps->cmd_pause = false;
caps->cmd_terminate = true;
return 0;
}
static int bcm2835_dma_probe(struct platform_device *pdev)
{
struct bcm2835_dmadev *od;
struct resource *res;
void __iomem *base;
int rc;
int i;
int irq;
uint32_t chans_available;
if (!pdev->dev.dma_mask)
pdev->dev.dma_mask = &pdev->dev.coherent_dma_mask;
rc = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (rc)
return rc;
od = devm_kzalloc(&pdev->dev, sizeof(*od), GFP_KERNEL);
if (!od)
return -ENOMEM;
pdev->dev.dma_parms = &od->dma_parms;
dma_set_max_seg_size(&pdev->dev, 0x3FFFFFFF);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
od->base = base;
dma_cap_set(DMA_SLAVE, od->ddev.cap_mask);
dma_cap_set(DMA_PRIVATE, od->ddev.cap_mask);
dma_cap_set(DMA_CYCLIC, od->ddev.cap_mask);
od->ddev.device_alloc_chan_resources = bcm2835_dma_alloc_chan_resources;
od->ddev.device_free_chan_resources = bcm2835_dma_free_chan_resources;
od->ddev.device_tx_status = bcm2835_dma_tx_status;
od->ddev.device_issue_pending = bcm2835_dma_issue_pending;
od->ddev.device_slave_caps = bcm2835_dma_device_slave_caps;
od->ddev.device_prep_dma_cyclic = bcm2835_dma_prep_dma_cyclic;
od->ddev.device_control = bcm2835_dma_control;
od->ddev.dev = &pdev->dev;
INIT_LIST_HEAD(&od->ddev.channels);
spin_lock_init(&od->lock);
platform_set_drvdata(pdev, od);
if (of_property_read_u32(pdev->dev.of_node,
"brcm,dma-channel-mask",
&chans_available)) {
dev_err(&pdev->dev, "Failed to get channel mask\n");
rc = -EINVAL;
goto err_no_dma;
}
chans_available &= ~(BCM2835_DMA_FIQ_MASK | BCM2835_DMA_BULK_MASK);
for (i = 0; i < pdev->num_resources; i++) {
irq = platform_get_irq(pdev, i);
if (irq < 0)
break;
if (chans_available & (1 << i)) {
rc = bcm2835_dma_chan_init(od, i, irq);
if (rc)
goto err_no_dma;
}
}
dev_dbg(&pdev->dev, "Initialized %i DMA channels\n", i);
rc = of_dma_controller_register(pdev->dev.of_node,
bcm2835_dma_xlate, od);
if (rc) {
dev_err(&pdev->dev, "Failed to register DMA controller\n");
goto err_no_dma;
}
rc = dma_async_device_register(&od->ddev);
if (rc) {
dev_err(&pdev->dev,
"Failed to register slave DMA engine device: %d\n", rc);
goto err_no_dma;
}
dev_dbg(&pdev->dev, "Load BCM2835 DMA engine driver\n");
return 0;
err_no_dma:
bcm2835_dma_free(od);
return rc;
}
static int bcm2835_dma_remove(struct platform_device *pdev)
{
struct bcm2835_dmadev *od = platform_get_drvdata(pdev);
dma_async_device_unregister(&od->ddev);
bcm2835_dma_free(od);
return 0;
}
