static int ohci_sa1111_reset(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
ohci_hcd_init(ohci);
return ohci_init(ohci);
}
static int ohci_sa1111_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
ret = ohci_run(ohci);
if (ret < 0) {
ohci_err(ohci, "can't start\n");
ohci_stop(hcd);
}
return ret;
}
static int sa1111_start_hc(struct sa1111_dev *dev)
{
unsigned int usb_rst = 0;
int ret;
dev_dbg(&dev->dev, "starting SA-1111 OHCI USB Controller\n");
if (machine_is_xp860() ||
machine_is_assabet() ||
machine_is_pfs168() ||
machine_is_badge4())
usb_rst = USB_RESET_PWRSENSELOW | USB_RESET_PWRCTRLLOW;
sa1111_writel(usb_rst | USB_RESET_FORCEIFRESET | USB_RESET_FORCEHCRESET,
dev->mapbase + USB_RESET);
ret = sa1111_enable_device(dev);
if (ret == 0) {
udelay(11);
sa1111_writel(usb_rst, dev->mapbase + USB_RESET);
}
return ret;
}
static void sa1111_stop_hc(struct sa1111_dev *dev)
{
unsigned int usb_rst;
dev_dbg(&dev->dev, "stopping SA-1111 OHCI USB Controller\n");
usb_rst = sa1111_readl(dev->mapbase + USB_RESET);
sa1111_writel(usb_rst | USB_RESET_FORCEIFRESET | USB_RESET_FORCEHCRESET,
dev->mapbase + USB_RESET);
sa1111_disable_device(dev);
}
static int ohci_hcd_sa1111_probe(struct sa1111_dev *dev)
{
struct usb_hcd *hcd;
int ret;
if (usb_disabled())
return -ENODEV;
hcd = usb_create_hcd(&ohci_sa1111_hc_driver, &dev->dev, "sa1111");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = dev->res.start;
hcd->rsrc_len = resource_size(&dev->res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
dev_dbg(&dev->dev, "request_mem_region failed\n");
ret = -EBUSY;
goto err1;
}
hcd->regs = dev->mapbase;
ret = sa1111_start_hc(dev);
if (ret)
goto err2;
ret = usb_add_hcd(hcd, dev->irq[1], 0);
if (ret == 0) {
device_wakeup_enable(hcd->self.controller);
return ret;
}
sa1111_stop_hc(dev);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return ret;
}
static int ohci_hcd_sa1111_remove(struct sa1111_dev *dev)
{
struct usb_hcd *hcd = sa1111_get_drvdata(dev);
usb_remove_hcd(hcd);
sa1111_stop_hc(dev);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
static void ohci_hcd_sa1111_shutdown(struct sa1111_dev *dev)
{
struct usb_hcd *hcd = sa1111_get_drvdata(dev);
if (test_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags)) {
hcd->driver->shutdown(hcd);
sa1111_stop_hc(dev);
}
}
