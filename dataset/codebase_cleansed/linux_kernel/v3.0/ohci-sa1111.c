static void sa1111_start_hc(struct sa1111_dev *dev)
{
unsigned int usb_rst = 0;
printk(KERN_DEBUG "%s: starting SA-1111 OHCI USB Controller\n",
__FILE__);
#ifdef CONFIG_SA1100_BADGE4
if (machine_is_badge4()) {
badge4_set_5V(BADGE4_5V_USB, 1);
}
#endif
if (machine_is_xp860() ||
machine_has_neponset() ||
machine_is_pfs168() ||
machine_is_badge4())
usb_rst = USB_RESET_PWRSENSELOW | USB_RESET_PWRCTRLLOW;
sa1111_writel(usb_rst | USB_RESET_FORCEIFRESET | USB_RESET_FORCEHCRESET,
dev->mapbase + SA1111_USB_RESET);
sa1111_enable_device(dev);
udelay(11);
sa1111_writel(usb_rst, dev->mapbase + SA1111_USB_RESET);
}
static void sa1111_stop_hc(struct sa1111_dev *dev)
{
unsigned int usb_rst;
printk(KERN_DEBUG "%s: stopping SA-1111 OHCI USB Controller\n",
__FILE__);
usb_rst = sa1111_readl(dev->mapbase + SA1111_USB_RESET);
sa1111_writel(usb_rst | USB_RESET_FORCEIFRESET | USB_RESET_FORCEHCRESET,
dev->mapbase + SA1111_USB_RESET);
sa1111_disable_device(dev);
#ifdef CONFIG_SA1100_BADGE4
if (machine_is_badge4()) {
badge4_set_5V(BADGE4_5V_USB, 0);
}
#endif
}
int usb_hcd_sa1111_probe (const struct hc_driver *driver,
struct sa1111_dev *dev)
{
struct usb_hcd *hcd;
int retval;
hcd = usb_create_hcd (driver, &dev->dev, "sa1111");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = dev->res.start;
hcd->rsrc_len = dev->res.end - dev->res.start + 1;
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
dbg("request_mem_region failed");
retval = -EBUSY;
goto err1;
}
hcd->regs = dev->mapbase;
sa1111_start_hc(dev);
ohci_hcd_init(hcd_to_ohci(hcd));
retval = usb_add_hcd(hcd, dev->irq[1], IRQF_DISABLED);
if (retval == 0)
return retval;
sa1111_stop_hc(dev);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return retval;
}
void usb_hcd_sa1111_remove (struct usb_hcd *hcd, struct sa1111_dev *dev)
{
usb_remove_hcd(hcd);
sa1111_stop_hc(dev);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
}
static int __devinit
ohci_sa1111_start (struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
int ret;
if ((ret = ohci_init(ohci)) < 0)
return ret;
if ((ret = ohci_run (ohci)) < 0) {
err ("can't start %s", hcd->self.bus_name);
ohci_stop (hcd);
return ret;
}
return 0;
}
static int ohci_hcd_sa1111_drv_probe(struct sa1111_dev *dev)
{
int ret;
if (usb_disabled())
return -ENODEV;
ret = usb_hcd_sa1111_probe(&ohci_sa1111_hc_driver, dev);
return ret;
}
static int ohci_hcd_sa1111_drv_remove(struct sa1111_dev *dev)
{
struct usb_hcd *hcd = sa1111_get_drvdata(dev);
usb_hcd_sa1111_remove(hcd, dev);
return 0;
}
