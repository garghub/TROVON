static void usb_dmac_write(struct usb_dmac *dmac, u32 reg, u32 data)
{
writel(data, dmac->iomem + reg);
}
static u32 usb_dmac_read(struct usb_dmac *dmac, u32 reg)
{
return readl(dmac->iomem + reg);
}
static u32 usb_dmac_chan_read(struct usb_dmac_chan *chan, u32 reg)
{
return readl(chan->iomem + reg);
}
static void usb_dmac_chan_write(struct usb_dmac_chan *chan, u32 reg, u32 data)
{
writel(data, chan->iomem + reg);
}
static bool usb_dmac_chan_is_busy(struct usb_dmac_chan *chan)
{
u32 chcr = usb_dmac_chan_read(chan, USB_DMACHCR);
return (chcr & (USB_DMACHCR_DE | USB_DMACHCR_TE)) == USB_DMACHCR_DE;
}
static u32 usb_dmac_calc_tend(u32 size)
{
return 0xffffffff << (32 - (size % USB_DMAC_XFER_SIZE ? :
USB_DMAC_XFER_SIZE));
}
static void usb_dmac_chan_start_sg(struct usb_dmac_chan *chan,
unsigned int index)
{
struct usb_dmac_desc *desc = chan->desc;
struct usb_dmac_sg *sg = desc->sg + index;
dma_addr_t src_addr = 0, dst_addr = 0;
WARN_ON_ONCE(usb_dmac_chan_is_busy(chan));
if (desc->direction == DMA_DEV_TO_MEM)
dst_addr = sg->mem_addr;
else
src_addr = sg->mem_addr;
dev_dbg(chan->vc.chan.device->dev,
"chan%u: queue sg %p: %u@%pad -> %pad\n",
chan->index, sg, sg->size, &src_addr, &dst_addr);
usb_dmac_chan_write(chan, USB_DMASAR, src_addr & 0xffffffff);
usb_dmac_chan_write(chan, USB_DMADAR, dst_addr & 0xffffffff);
usb_dmac_chan_write(chan, USB_DMATCR,
DIV_ROUND_UP(sg->size, USB_DMAC_XFER_SIZE));
usb_dmac_chan_write(chan, USB_DMATEND, usb_dmac_calc_tend(sg->size));
usb_dmac_chan_write(chan, USB_DMACHCR, USB_DMAC_CHCR_TS |
USB_DMACHCR_NULLE | USB_DMACHCR_IE | USB_DMACHCR_DE);
}
static void usb_dmac_chan_start_desc(struct usb_dmac_chan *chan)
{
struct virt_dma_desc *vd;
vd = vchan_next_desc(&chan->vc);
if (!vd) {
chan->desc = NULL;
return;
}
list_del(&vd->node);
chan->desc = to_usb_dmac_desc(vd);
chan->desc->sg_index = 0;
usb_dmac_chan_start_sg(chan, 0);
}
static int usb_dmac_init(struct usb_dmac *dmac)
{
u16 dmaor;
usb_dmac_write(dmac, USB_DMAOR, USB_DMAOR_DME);
dmaor = usb_dmac_read(dmac, USB_DMAOR);
if ((dmaor & (USB_DMAOR_AE | USB_DMAOR_DME)) != USB_DMAOR_DME) {
dev_warn(dmac->dev, "DMAOR initialization failed.\n");
return -EIO;
}
return 0;
}
static int usb_dmac_desc_alloc(struct usb_dmac_chan *chan, unsigned int sg_len,
gfp_t gfp)
{
struct usb_dmac_desc *desc;
unsigned long flags;
desc = kzalloc(sizeof(*desc) + sg_len * sizeof(desc->sg[0]), gfp);
if (!desc)
return -ENOMEM;
desc->sg_allocated_len = sg_len;
INIT_LIST_HEAD(&desc->node);
spin_lock_irqsave(&chan->vc.lock, flags);
list_add_tail(&desc->node, &chan->desc_freed);
spin_unlock_irqrestore(&chan->vc.lock, flags);
return 0;
}
static void usb_dmac_desc_free(struct usb_dmac_chan *chan)
{
struct usb_dmac_desc *desc, *_desc;
LIST_HEAD(list);
list_splice_init(&chan->desc_freed, &list);
list_splice_init(&chan->desc_got, &list);
list_for_each_entry_safe(desc, _desc, &list, node) {
list_del(&desc->node);
kfree(desc);
}
chan->descs_allocated = 0;
}
static struct usb_dmac_desc *usb_dmac_desc_get(struct usb_dmac_chan *chan,
unsigned int sg_len, gfp_t gfp)
{
struct usb_dmac_desc *desc = NULL;
unsigned long flags;
spin_lock_irqsave(&chan->vc.lock, flags);
list_for_each_entry(desc, &chan->desc_freed, node) {
if (sg_len <= desc->sg_allocated_len) {
list_move_tail(&desc->node, &chan->desc_got);
spin_unlock_irqrestore(&chan->vc.lock, flags);
return desc;
}
}
spin_unlock_irqrestore(&chan->vc.lock, flags);
if (!usb_dmac_desc_alloc(chan, sg_len, gfp)) {
spin_lock_irqsave(&chan->vc.lock, flags);
desc = list_last_entry(&chan->desc_freed, struct usb_dmac_desc,
node);
list_move_tail(&desc->node, &chan->desc_got);
spin_unlock_irqrestore(&chan->vc.lock, flags);
return desc;
}
return NULL;
}
static void usb_dmac_desc_put(struct usb_dmac_chan *chan,
struct usb_dmac_desc *desc)
{
unsigned long flags;
spin_lock_irqsave(&chan->vc.lock, flags);
list_move_tail(&desc->node, &chan->desc_freed);
spin_unlock_irqrestore(&chan->vc.lock, flags);
}
static void usb_dmac_soft_reset(struct usb_dmac_chan *uchan)
{
struct dma_chan *chan = &uchan->vc.chan;
struct usb_dmac *dmac = to_usb_dmac(chan->device);
int i;
for (i = 0; i < dmac->n_channels; ++i) {
if (usb_dmac_chan_is_busy(uchan))
return;
}
usb_dmac_write(dmac, USB_DMAOR, 0);
usb_dmac_write(dmac, USB_DMASWR, USB_DMASWR_SWR);
udelay(100);
usb_dmac_write(dmac, USB_DMASWR, 0);
usb_dmac_write(dmac, USB_DMAOR, 1);
}
static void usb_dmac_chan_halt(struct usb_dmac_chan *chan)
{
u32 chcr = usb_dmac_chan_read(chan, USB_DMACHCR);
chcr &= ~(USB_DMACHCR_IE | USB_DMACHCR_TE | USB_DMACHCR_DE);
usb_dmac_chan_write(chan, USB_DMACHCR, chcr);
usb_dmac_soft_reset(chan);
}
static void usb_dmac_stop(struct usb_dmac *dmac)
{
usb_dmac_write(dmac, USB_DMAOR, 0);
}
static int usb_dmac_alloc_chan_resources(struct dma_chan *chan)
{
struct usb_dmac_chan *uchan = to_usb_dmac_chan(chan);
int ret;
while (uchan->descs_allocated < USB_DMAC_INITIAL_NR_DESC) {
ret = usb_dmac_desc_alloc(uchan, USB_DMAC_INITIAL_NR_SG,
GFP_KERNEL);
if (ret < 0) {
usb_dmac_desc_free(uchan);
return ret;
}
uchan->descs_allocated++;
}
return pm_runtime_get_sync(chan->device->dev);
}
static void usb_dmac_free_chan_resources(struct dma_chan *chan)
{
struct usb_dmac_chan *uchan = to_usb_dmac_chan(chan);
unsigned long flags;
spin_lock_irqsave(&uchan->vc.lock, flags);
usb_dmac_chan_halt(uchan);
spin_unlock_irqrestore(&uchan->vc.lock, flags);
usb_dmac_desc_free(uchan);
vchan_free_chan_resources(&uchan->vc);
pm_runtime_put(chan->device->dev);
}
static struct dma_async_tx_descriptor *
usb_dmac_prep_slave_sg(struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction dir,
unsigned long dma_flags, void *context)
{
struct usb_dmac_chan *uchan = to_usb_dmac_chan(chan);
struct usb_dmac_desc *desc;
struct scatterlist *sg;
int i;
if (!sg_len) {
dev_warn(chan->device->dev,
"%s: bad parameter: len=%d\n", __func__, sg_len);
return NULL;
}
desc = usb_dmac_desc_get(uchan, sg_len, GFP_NOWAIT);
if (!desc)
return NULL;
desc->direction = dir;
desc->sg_len = sg_len;
for_each_sg(sgl, sg, sg_len, i) {
desc->sg[i].mem_addr = sg_dma_address(sg);
desc->sg[i].size = sg_dma_len(sg);
}
return vchan_tx_prep(&uchan->vc, &desc->vd, dma_flags);
}
static int usb_dmac_chan_terminate_all(struct dma_chan *chan)
{
struct usb_dmac_chan *uchan = to_usb_dmac_chan(chan);
struct usb_dmac_desc *desc, *_desc;
unsigned long flags;
LIST_HEAD(head);
LIST_HEAD(list);
spin_lock_irqsave(&uchan->vc.lock, flags);
usb_dmac_chan_halt(uchan);
vchan_get_all_descriptors(&uchan->vc, &head);
if (uchan->desc)
uchan->desc = NULL;
list_splice_init(&uchan->desc_got, &list);
list_for_each_entry_safe(desc, _desc, &list, node)
list_move_tail(&desc->node, &uchan->desc_freed);
spin_unlock_irqrestore(&uchan->vc.lock, flags);
vchan_dma_desc_free_list(&uchan->vc, &head);
return 0;
}
static unsigned int usb_dmac_get_current_residue(struct usb_dmac_chan *chan,
struct usb_dmac_desc *desc,
int sg_index)
{
struct usb_dmac_sg *sg = desc->sg + sg_index;
u32 mem_addr = sg->mem_addr & 0xffffffff;
unsigned int residue = sg->size;
if (desc->direction == DMA_DEV_TO_MEM)
residue -= usb_dmac_chan_read(chan, USB_DMADAR) - mem_addr;
else
residue -= usb_dmac_chan_read(chan, USB_DMASAR) - mem_addr;
return residue;
}
static u32 usb_dmac_chan_get_residue_if_complete(struct usb_dmac_chan *chan,
dma_cookie_t cookie)
{
struct usb_dmac_desc *desc;
u32 residue = 0;
list_for_each_entry_reverse(desc, &chan->desc_freed, node) {
if (desc->done_cookie == cookie) {
residue = desc->residue;
break;
}
}
return residue;
}
static u32 usb_dmac_chan_get_residue(struct usb_dmac_chan *chan,
dma_cookie_t cookie)
{
u32 residue = 0;
struct virt_dma_desc *vd;
struct usb_dmac_desc *desc = chan->desc;
int i;
if (!desc) {
vd = vchan_find_desc(&chan->vc, cookie);
if (!vd)
return 0;
desc = to_usb_dmac_desc(vd);
}
for (i = desc->sg_index + 1; i < desc->sg_len; i++)
residue += desc->sg[i].size;
residue += usb_dmac_get_current_residue(chan, desc, desc->sg_index);
return residue;
}
static enum dma_status usb_dmac_tx_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct usb_dmac_chan *uchan = to_usb_dmac_chan(chan);
enum dma_status status;
unsigned int residue = 0;
unsigned long flags;
status = dma_cookie_status(chan, cookie, txstate);
if (!txstate)
return status;
spin_lock_irqsave(&uchan->vc.lock, flags);
if (status == DMA_COMPLETE)
residue = usb_dmac_chan_get_residue_if_complete(uchan, cookie);
else
residue = usb_dmac_chan_get_residue(uchan, cookie);
spin_unlock_irqrestore(&uchan->vc.lock, flags);
dma_set_residue(txstate, residue);
return status;
}
static void usb_dmac_issue_pending(struct dma_chan *chan)
{
struct usb_dmac_chan *uchan = to_usb_dmac_chan(chan);
unsigned long flags;
spin_lock_irqsave(&uchan->vc.lock, flags);
if (vchan_issue_pending(&uchan->vc) && !uchan->desc)
usb_dmac_chan_start_desc(uchan);
spin_unlock_irqrestore(&uchan->vc.lock, flags);
}
static void usb_dmac_virt_desc_free(struct virt_dma_desc *vd)
{
struct usb_dmac_desc *desc = to_usb_dmac_desc(vd);
struct usb_dmac_chan *chan = to_usb_dmac_chan(vd->tx.chan);
usb_dmac_desc_put(chan, desc);
}
static void usb_dmac_isr_transfer_end(struct usb_dmac_chan *chan)
{
struct usb_dmac_desc *desc = chan->desc;
BUG_ON(!desc);
if (++desc->sg_index < desc->sg_len) {
usb_dmac_chan_start_sg(chan, desc->sg_index);
} else {
desc->residue = usb_dmac_get_current_residue(chan, desc,
desc->sg_index - 1);
desc->done_cookie = desc->vd.tx.cookie;
vchan_cookie_complete(&desc->vd);
usb_dmac_chan_start_desc(chan);
}
}
static irqreturn_t usb_dmac_isr_channel(int irq, void *dev)
{
struct usb_dmac_chan *chan = dev;
irqreturn_t ret = IRQ_NONE;
u32 mask = USB_DMACHCR_TE;
u32 check_bits = USB_DMACHCR_TE | USB_DMACHCR_SP;
u32 chcr;
spin_lock(&chan->vc.lock);
chcr = usb_dmac_chan_read(chan, USB_DMACHCR);
if (chcr & check_bits)
mask |= USB_DMACHCR_DE | check_bits;
if (chcr & USB_DMACHCR_NULL) {
mask |= USB_DMACHCR_NULL;
chcr |= USB_DMACHCR_FTE;
ret |= IRQ_HANDLED;
}
usb_dmac_chan_write(chan, USB_DMACHCR, chcr & ~mask);
if (chcr & check_bits) {
usb_dmac_isr_transfer_end(chan);
ret |= IRQ_HANDLED;
}
spin_unlock(&chan->vc.lock);
return ret;
}
static bool usb_dmac_chan_filter(struct dma_chan *chan, void *arg)
{
struct usb_dmac_chan *uchan = to_usb_dmac_chan(chan);
struct of_phandle_args *dma_spec = arg;
if (dma_spec->np != chan->device->dev->of_node)
return false;
if (uchan->index != dma_spec->args[0])
return false;
return true;
}
static struct dma_chan *usb_dmac_of_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct usb_dmac_chan *uchan;
struct dma_chan *chan;
dma_cap_mask_t mask;
if (dma_spec->args_count != 1)
return NULL;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
chan = dma_request_channel(mask, usb_dmac_chan_filter, dma_spec);
if (!chan)
return NULL;
uchan = to_usb_dmac_chan(chan);
return chan;
}
static int usb_dmac_runtime_suspend(struct device *dev)
{
struct usb_dmac *dmac = dev_get_drvdata(dev);
int i;
for (i = 0; i < dmac->n_channels; ++i) {
if (!dmac->channels[i].iomem)
break;
usb_dmac_chan_halt(&dmac->channels[i]);
}
return 0;
}
static int usb_dmac_runtime_resume(struct device *dev)
{
struct usb_dmac *dmac = dev_get_drvdata(dev);
return usb_dmac_init(dmac);
}
static int usb_dmac_chan_probe(struct usb_dmac *dmac,
struct usb_dmac_chan *uchan,
unsigned int index)
{
struct platform_device *pdev = to_platform_device(dmac->dev);
char pdev_irqname[5];
char *irqname;
int ret;
uchan->index = index;
uchan->iomem = dmac->iomem + USB_DMAC_CHAN_OFFSET(index);
sprintf(pdev_irqname, "ch%u", index);
uchan->irq = platform_get_irq_byname(pdev, pdev_irqname);
if (uchan->irq < 0) {
dev_err(dmac->dev, "no IRQ specified for channel %u\n", index);
return -ENODEV;
}
irqname = devm_kasprintf(dmac->dev, GFP_KERNEL, "%s:%u",
dev_name(dmac->dev), index);
if (!irqname)
return -ENOMEM;
ret = devm_request_irq(dmac->dev, uchan->irq, usb_dmac_isr_channel,
IRQF_SHARED, irqname, uchan);
if (ret) {
dev_err(dmac->dev, "failed to request IRQ %u (%d)\n",
uchan->irq, ret);
return ret;
}
uchan->vc.desc_free = usb_dmac_virt_desc_free;
vchan_init(&uchan->vc, &dmac->engine);
INIT_LIST_HEAD(&uchan->desc_freed);
INIT_LIST_HEAD(&uchan->desc_got);
return 0;
}
static int usb_dmac_parse_of(struct device *dev, struct usb_dmac *dmac)
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
static int usb_dmac_probe(struct platform_device *pdev)
{
const enum dma_slave_buswidth widths = USB_DMAC_SLAVE_BUSWIDTH;
struct dma_device *engine;
struct usb_dmac *dmac;
struct resource *mem;
unsigned int i;
int ret;
dmac = devm_kzalloc(&pdev->dev, sizeof(*dmac), GFP_KERNEL);
if (!dmac)
return -ENOMEM;
dmac->dev = &pdev->dev;
platform_set_drvdata(pdev, dmac);
ret = usb_dmac_parse_of(&pdev->dev, dmac);
if (ret < 0)
return ret;
dmac->channels = devm_kcalloc(&pdev->dev, dmac->n_channels,
sizeof(*dmac->channels), GFP_KERNEL);
if (!dmac->channels)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dmac->iomem = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(dmac->iomem))
return PTR_ERR(dmac->iomem);
pm_runtime_enable(&pdev->dev);
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "runtime PM get sync failed (%d)\n", ret);
goto error_pm;
}
ret = usb_dmac_init(dmac);
if (ret) {
dev_err(&pdev->dev, "failed to reset device\n");
goto error;
}
INIT_LIST_HEAD(&dmac->engine.channels);
for (i = 0; i < dmac->n_channels; ++i) {
ret = usb_dmac_chan_probe(dmac, &dmac->channels[i], i);
if (ret < 0)
goto error;
}
ret = of_dma_controller_register(pdev->dev.of_node, usb_dmac_of_xlate,
NULL);
if (ret < 0)
goto error;
engine = &dmac->engine;
dma_cap_set(DMA_SLAVE, engine->cap_mask);
engine->dev = &pdev->dev;
engine->src_addr_widths = widths;
engine->dst_addr_widths = widths;
engine->directions = BIT(DMA_MEM_TO_DEV) | BIT(DMA_DEV_TO_MEM);
engine->residue_granularity = DMA_RESIDUE_GRANULARITY_BURST;
engine->device_alloc_chan_resources = usb_dmac_alloc_chan_resources;
engine->device_free_chan_resources = usb_dmac_free_chan_resources;
engine->device_prep_slave_sg = usb_dmac_prep_slave_sg;
engine->device_terminate_all = usb_dmac_chan_terminate_all;
engine->device_tx_status = usb_dmac_tx_status;
engine->device_issue_pending = usb_dmac_issue_pending;
ret = dma_async_device_register(engine);
if (ret < 0)
goto error;
pm_runtime_put(&pdev->dev);
return 0;
error:
of_dma_controller_free(pdev->dev.of_node);
pm_runtime_put(&pdev->dev);
error_pm:
pm_runtime_disable(&pdev->dev);
return ret;
}
static void usb_dmac_chan_remove(struct usb_dmac *dmac,
struct usb_dmac_chan *uchan)
{
usb_dmac_chan_halt(uchan);
devm_free_irq(dmac->dev, uchan->irq, uchan);
}
static int usb_dmac_remove(struct platform_device *pdev)
{
struct usb_dmac *dmac = platform_get_drvdata(pdev);
int i;
for (i = 0; i < dmac->n_channels; ++i)
usb_dmac_chan_remove(dmac, &dmac->channels[i]);
of_dma_controller_free(pdev->dev.of_node);
dma_async_device_unregister(&dmac->engine);
pm_runtime_disable(&pdev->dev);
return 0;
}
static void usb_dmac_shutdown(struct platform_device *pdev)
{
struct usb_dmac *dmac = platform_get_drvdata(pdev);
usb_dmac_stop(dmac);
}
