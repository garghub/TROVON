static void pnx8550_start_hc(struct platform_device *dev)
{
outl(0x00000003, PCI_BASE | 0x0004770c);
outl(0x00000003, PCI_BASE | 0x00047710);
udelay(100);
}
static void pnx8550_stop_hc(struct platform_device *dev)
{
udelay(10);
}
int usb_hcd_pnx8550_probe (const struct hc_driver *driver,
struct platform_device *dev)
{
int retval;
struct usb_hcd *hcd;
if (dev->resource[0].flags != IORESOURCE_MEM ||
dev->resource[1].flags != IORESOURCE_IRQ) {
dev_err (&dev->dev,"invalid resource type\n");
return -ENOMEM;
}
hcd = usb_create_hcd (driver, &dev->dev, "pnx8550");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = dev->resource[0].start;
hcd->rsrc_len = dev->resource[0].end - dev->resource[0].start + 1;
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
dev_err(&dev->dev, "request_mem_region [0x%08llx, 0x%08llx] "
"failed\n", hcd->rsrc_start, hcd->rsrc_len);
retval = -EBUSY;
goto err1;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
dev_err(&dev->dev, "ioremap [[0x%08llx, 0x%08llx] failed\n",
hcd->rsrc_start, hcd->rsrc_len);
retval = -ENOMEM;
goto err2;
}
pnx8550_start_hc(dev);
ohci_hcd_init(hcd_to_ohci(hcd));
retval = usb_add_hcd(hcd, dev->resource[1].start, 0);
if (retval == 0)
return retval;
pnx8550_stop_hc(dev);
iounmap(hcd->regs);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return retval;
}
void usb_hcd_pnx8550_remove (struct usb_hcd *hcd, struct platform_device *dev)
{
usb_remove_hcd(hcd);
pnx8550_stop_hc(dev);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
}
static int __devinit
ohci_pnx8550_start (struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
int ret;
ohci_dbg (ohci, "ohci_pnx8550_start, ohci:%p", ohci);
if ((ret = ohci_init(ohci)) < 0)
return ret;
if ((ret = ohci_run (ohci)) < 0) {
err ("can't start %s", hcd->self.bus_name);
ohci_stop (hcd);
return ret;
}
return 0;
}
static int ohci_hcd_pnx8550_drv_probe(struct platform_device *pdev)
{
int ret;
if (usb_disabled())
return -ENODEV;
ret = usb_hcd_pnx8550_probe(&ohci_pnx8550_hc_driver, pdev);
return ret;
}
static int ohci_hcd_pnx8550_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_hcd_pnx8550_remove(hcd, pdev);
return 0;
}
