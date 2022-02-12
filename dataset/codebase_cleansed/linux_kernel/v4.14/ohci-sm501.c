static int ohci_sm501_init(struct usb_hcd *hcd)
{
return ohci_init(hcd_to_ohci(hcd));
}
static int ohci_sm501_start(struct usb_hcd *hcd)
{
struct device *dev = hcd->self.controller;
int ret;
ret = ohci_run(hcd_to_ohci(hcd));
if (ret < 0) {
dev_err(dev, "can't start %s", hcd->self.bus_name);
ohci_stop(hcd);
}
return ret;
}
static int ohci_hcd_sm501_drv_probe(struct platform_device *pdev)
{
const struct hc_driver *driver = &ohci_sm501_hc_driver;
struct device *dev = &pdev->dev;
struct resource *res, *mem;
int retval, irq;
struct usb_hcd *hcd = NULL;
irq = retval = platform_get_irq(pdev, 0);
if (retval < 0)
goto err0;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (mem == NULL) {
dev_err(dev, "no resource definition for memory\n");
retval = -ENOENT;
goto err0;
}
if (!request_mem_region(mem->start, resource_size(mem), pdev->name)) {
dev_err(dev, "request_mem_region failed\n");
retval = -EBUSY;
goto err0;
}
retval = dma_declare_coherent_memory(dev, mem->start,
mem->start - mem->parent->start,
resource_size(mem),
DMA_MEMORY_EXCLUSIVE);
if (retval) {
dev_err(dev, "cannot declare coherent memory\n");
goto err1;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(dev, "no resource definition for registers\n");
retval = -ENOENT;
goto err2;
}
hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
retval = -ENOMEM;
goto err2;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, pdev->name)) {
dev_err(dev, "request_mem_region failed\n");
retval = -EBUSY;
goto err3;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
dev_err(dev, "cannot remap registers\n");
retval = -ENXIO;
goto err4;
}
ohci_hcd_init(hcd_to_ohci(hcd));
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval)
goto err5;
device_wakeup_enable(hcd->self.controller);
sm501_unit_power(dev->parent, SM501_GATE_USB_HOST, 1);
sm501_modify_reg(dev->parent, SM501_IRQ_MASK, 1 << 6, 0);
return 0;
err5:
iounmap(hcd->regs);
err4:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err3:
usb_put_hcd(hcd);
err2:
dma_release_declared_memory(dev);
err1:
release_mem_region(mem->start, resource_size(mem));
err0:
return retval;
}
static int ohci_hcd_sm501_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct resource *mem;
usb_remove_hcd(hcd);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
dma_release_declared_memory(&pdev->dev);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (mem)
release_mem_region(mem->start, resource_size(mem));
sm501_modify_reg(pdev->dev.parent, SM501_IRQ_MASK, 0, 1 << 6);
sm501_unit_power(pdev->dev.parent, SM501_GATE_USB_HOST, 0);
return 0;
}
static int ohci_sm501_suspend(struct platform_device *pdev, pm_message_t msg)
{
struct device *dev = &pdev->dev;
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
bool do_wakeup = device_may_wakeup(dev);
int ret;
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
ret = ohci_suspend(hcd, do_wakeup);
if (ret)
return ret;
sm501_unit_power(dev->parent, SM501_GATE_USB_HOST, 0);
return ret;
}
static int ohci_sm501_resume(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
sm501_unit_power(dev->parent, SM501_GATE_USB_HOST, 1);
ohci_resume(hcd, false);
return 0;
}
