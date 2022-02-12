static irqreturn_t tw686x_irq(int irq, void *dev_id)
{
struct tw686x_dev *dev = (struct tw686x_dev *)dev_id;
u32 int_status = reg_read(dev, INT_STATUS);
unsigned long flags;
unsigned int handled = 0;
if (int_status) {
spin_lock_irqsave(&dev->irq_lock, flags);
dev->dma_requests |= int_status;
spin_unlock_irqrestore(&dev->irq_lock, flags);
if (int_status & 0xFF0000FF)
handled = tw686x_kh_video_irq(dev);
}
return IRQ_RETVAL(handled);
}
static int tw686x_probe(struct pci_dev *pci_dev,
const struct pci_device_id *pci_id)
{
struct tw686x_dev *dev;
int err;
dev = devm_kzalloc(&pci_dev->dev, sizeof(*dev) +
(pci_id->driver_data & TYPE_MAX_CHANNELS) *
sizeof(dev->video_channels[0]), GFP_KERNEL);
if (!dev)
return -ENOMEM;
sprintf(dev->name, "TW%04X", pci_dev->device);
dev->type = pci_id->driver_data;
pr_info("%s: PCI %s, IRQ %d, MMIO 0x%lx\n", dev->name,
pci_name(pci_dev), pci_dev->irq,
(unsigned long)pci_resource_start(pci_dev, 0));
dev->pci_dev = pci_dev;
if (pcim_enable_device(pci_dev))
return -EIO;
pci_set_master(pci_dev);
if (pci_set_dma_mask(pci_dev, DMA_BIT_MASK(32))) {
pr_err("%s: 32-bit PCI DMA not supported\n", dev->name);
return -EIO;
}
err = pci_request_regions(pci_dev, dev->name);
if (err < 0) {
pr_err("%s: Unable to get MMIO region\n", dev->name);
return err;
}
dev->mmio = pci_ioremap_bar(pci_dev, 0);
if (!dev->mmio) {
pr_err("%s: Unable to remap MMIO region\n", dev->name);
return -EIO;
}
reg_write(dev, SYS_SOFT_RST, 0x0F);
mdelay(1);
reg_write(dev, SRST[0], 0x3F);
if (max_channels(dev) > 4)
reg_write(dev, SRST[1], 0x3F);
reg_write(dev, DMA_CMD, 0);
reg_write(dev, DMA_CHANNEL_ENABLE, 0);
reg_write(dev, DMA_CHANNEL_TIMEOUT, 0x3EFF0FF0);
reg_write(dev, DMA_TIMER_INTERVAL, 0x38000);
reg_write(dev, DMA_CONFIG, 0xFFFFFF04);
spin_lock_init(&dev->irq_lock);
err = devm_request_irq(&pci_dev->dev, pci_dev->irq, tw686x_irq,
IRQF_SHARED, dev->name, dev);
if (err < 0) {
pr_err("%s: Unable to get IRQ\n", dev->name);
return err;
}
err = tw686x_kh_video_init(dev);
if (err)
return err;
pci_set_drvdata(pci_dev, dev);
return 0;
}
static void tw686x_remove(struct pci_dev *pci_dev)
{
struct tw686x_dev *dev = pci_get_drvdata(pci_dev);
tw686x_kh_video_free(dev);
}
