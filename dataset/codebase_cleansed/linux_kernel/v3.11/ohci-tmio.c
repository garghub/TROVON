static void tmio_write_pm(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct tmio_hcd *tmio = hcd_to_tmio(hcd);
u16 pm;
unsigned long flags;
spin_lock_irqsave(&tmio->lock, flags);
pm = CCR_PM_GKEN | CCR_PM_CKRNEN |
CCR_PM_PMEE | CCR_PM_PMES;
tmio_iowrite16(pm, tmio->ccr + CCR_PM);
spin_unlock_irqrestore(&tmio->lock, flags);
}
static void tmio_stop_hc(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
struct tmio_hcd *tmio = hcd_to_tmio(hcd);
u16 pm;
pm = CCR_PM_GKEN | CCR_PM_CKRNEN;
switch (ohci->num_ports) {
default:
dev_err(&dev->dev, "Unsupported amount of ports: %d\n", ohci->num_ports);
case 3:
pm |= CCR_PM_USBPW3;
case 2:
pm |= CCR_PM_USBPW2;
case 1:
pm |= CCR_PM_USBPW1;
}
tmio_iowrite8(0, tmio->ccr + CCR_INTC);
tmio_iowrite8(0, tmio->ccr + CCR_ILME);
tmio_iowrite16(0, tmio->ccr + CCR_BASE);
tmio_iowrite16(0, tmio->ccr + CCR_BASE + 2);
tmio_iowrite16(pm, tmio->ccr + CCR_PM);
}
static void tmio_start_hc(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct tmio_hcd *tmio = hcd_to_tmio(hcd);
unsigned long base = hcd->rsrc_start;
tmio_write_pm(dev);
tmio_iowrite16(base, tmio->ccr + CCR_BASE);
tmio_iowrite16(base >> 16, tmio->ccr + CCR_BASE + 2);
tmio_iowrite8(1, tmio->ccr + CCR_ILME);
tmio_iowrite8(2, tmio->ccr + CCR_INTC);
dev_info(&dev->dev, "revision %d @ 0x%08llx, irq %d\n",
tmio_ioread8(tmio->ccr + CCR_REVID),
(u64) hcd->rsrc_start, hcd->irq);
}
static int ohci_tmio_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
if ((ret = ohci_init(ohci)) < 0)
return ret;
if ((ret = ohci_run(ohci)) < 0) {
dev_err(hcd->self.controller, "can't start %s\n",
hcd->self.bus_name);
ohci_stop(hcd);
return ret;
}
return 0;
}
static int ohci_hcd_tmio_drv_probe(struct platform_device *dev)
{
const struct mfd_cell *cell = mfd_get_cell(dev);
struct resource *regs = platform_get_resource(dev, IORESOURCE_MEM, 0);
struct resource *config = platform_get_resource(dev, IORESOURCE_MEM, 1);
struct resource *sram = platform_get_resource(dev, IORESOURCE_MEM, 2);
int irq = platform_get_irq(dev, 0);
struct tmio_hcd *tmio;
struct ohci_hcd *ohci;
struct usb_hcd *hcd;
int ret;
if (usb_disabled())
return -ENODEV;
if (!cell)
return -EINVAL;
hcd = usb_create_hcd(&ohci_tmio_hc_driver, &dev->dev, dev_name(&dev->dev));
if (!hcd) {
ret = -ENOMEM;
goto err_usb_create_hcd;
}
hcd->rsrc_start = regs->start;
hcd->rsrc_len = resource_size(regs);
tmio = hcd_to_tmio(hcd);
spin_lock_init(&tmio->lock);
tmio->ccr = ioremap(config->start, resource_size(config));
if (!tmio->ccr) {
ret = -ENOMEM;
goto err_ioremap_ccr;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
ret = -ENOMEM;
goto err_ioremap_regs;
}
if (!dma_declare_coherent_memory(&dev->dev, sram->start,
sram->start,
resource_size(sram),
DMA_MEMORY_MAP | DMA_MEMORY_EXCLUSIVE)) {
ret = -EBUSY;
goto err_dma_declare;
}
if (cell->enable) {
ret = cell->enable(dev);
if (ret)
goto err_enable;
}
tmio_start_hc(dev);
ohci = hcd_to_ohci(hcd);
ohci_hcd_init(ohci);
ret = usb_add_hcd(hcd, irq, 0);
if (ret)
goto err_add_hcd;
if (ret == 0)
return ret;
usb_remove_hcd(hcd);
err_add_hcd:
tmio_stop_hc(dev);
if (cell->disable)
cell->disable(dev);
err_enable:
dma_release_declared_memory(&dev->dev);
err_dma_declare:
iounmap(hcd->regs);
err_ioremap_regs:
iounmap(tmio->ccr);
err_ioremap_ccr:
usb_put_hcd(hcd);
err_usb_create_hcd:
return ret;
}
static int ohci_hcd_tmio_drv_remove(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct tmio_hcd *tmio = hcd_to_tmio(hcd);
const struct mfd_cell *cell = mfd_get_cell(dev);
usb_remove_hcd(hcd);
tmio_stop_hc(dev);
if (cell->disable)
cell->disable(dev);
dma_release_declared_memory(&dev->dev);
iounmap(hcd->regs);
iounmap(tmio->ccr);
usb_put_hcd(hcd);
return 0;
}
static int ohci_hcd_tmio_drv_suspend(struct platform_device *dev, pm_message_t state)
{
const struct mfd_cell *cell = mfd_get_cell(dev);
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
struct tmio_hcd *tmio = hcd_to_tmio(hcd);
unsigned long flags;
u8 misc;
int ret;
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
spin_lock_irqsave(&tmio->lock, flags);
misc = tmio_ioread8(tmio->ccr + CCR_MISC);
misc |= 1 << 3;
tmio_iowrite8(misc, tmio->ccr + CCR_MISC);
spin_unlock_irqrestore(&tmio->lock, flags);
if (cell->suspend) {
ret = cell->suspend(dev);
if (ret)
return ret;
}
return 0;
}
static int ohci_hcd_tmio_drv_resume(struct platform_device *dev)
{
const struct mfd_cell *cell = mfd_get_cell(dev);
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
struct tmio_hcd *tmio = hcd_to_tmio(hcd);
unsigned long flags;
u8 misc;
int ret;
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
if (cell->resume) {
ret = cell->resume(dev);
if (ret)
return ret;
}
tmio_start_hc(dev);
spin_lock_irqsave(&tmio->lock, flags);
misc = tmio_ioread8(tmio->ccr + CCR_MISC);
misc &= ~(1 << 3);
tmio_iowrite8(misc, tmio->ccr + CCR_MISC);
spin_unlock_irqrestore(&tmio->lock, flags);
ohci_resume(hcd, false);
return 0;
}
