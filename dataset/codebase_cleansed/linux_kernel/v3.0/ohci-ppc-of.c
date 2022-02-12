static int __devinit
ohci_ppc_of_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
if ((ret = ohci_init(ohci)) < 0)
return ret;
if ((ret = ohci_run(ohci)) < 0) {
err("can't start %s", ohci_to_hcd(ohci)->self.bus_name);
ohci_stop(hcd);
return ret;
}
return 0;
}
static int __devinit ohci_hcd_ppc_of_probe(struct platform_device *op)
{
struct device_node *dn = op->dev.of_node;
struct usb_hcd *hcd;
struct ohci_hcd *ohci;
struct resource res;
int irq;
int rv;
int is_bigendian;
struct device_node *np;
if (usb_disabled())
return -ENODEV;
is_bigendian =
of_device_is_compatible(dn, "ohci-bigendian") ||
of_device_is_compatible(dn, "ohci-be");
dev_dbg(&op->dev, "initializing PPC-OF USB Controller\n");
rv = of_address_to_resource(dn, 0, &res);
if (rv)
return rv;
hcd = usb_create_hcd(&ohci_ppc_of_hc_driver, &op->dev, "PPC-OF USB");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res.start;
hcd->rsrc_len = res.end - res.start + 1;
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
printk(KERN_ERR "%s: request_mem_region failed\n", __FILE__);
rv = -EBUSY;
goto err_rmr;
}
irq = irq_of_parse_and_map(dn, 0);
if (irq == NO_IRQ) {
printk(KERN_ERR "%s: irq_of_parse_and_map failed\n", __FILE__);
rv = -EBUSY;
goto err_irq;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
printk(KERN_ERR "%s: ioremap failed\n", __FILE__);
rv = -ENOMEM;
goto err_ioremap;
}
ohci = hcd_to_ohci(hcd);
if (is_bigendian) {
ohci->flags |= OHCI_QUIRK_BE_MMIO | OHCI_QUIRK_BE_DESC;
if (of_device_is_compatible(dn, "fsl,mpc5200-ohci"))
ohci->flags |= OHCI_QUIRK_FRAME_NO;
if (of_device_is_compatible(dn, "mpc5200-ohci"))
ohci->flags |= OHCI_QUIRK_FRAME_NO;
}
ohci_hcd_init(ohci);
rv = usb_add_hcd(hcd, irq, IRQF_DISABLED);
if (rv == 0)
return 0;
np = of_find_compatible_node(NULL, NULL, "ibm,usb-ehci-440epx");
if (np != NULL) {
if (!of_address_to_resource(np, 0, &res)) {
if (!request_mem_region(res.start, 0x4, hcd_name)) {
writel_be((readl_be(&ohci->regs->control) |
OHCI_USB_SUSPEND), &ohci->regs->control);
(void) readl_be(&ohci->regs->control);
} else
release_mem_region(res.start, 0x4);
} else
pr_debug("%s: cannot get ehci offset from fdt\n", __FILE__);
}
iounmap(hcd->regs);
err_ioremap:
irq_dispose_mapping(irq);
err_irq:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err_rmr:
usb_put_hcd(hcd);
return rv;
}
static int ohci_hcd_ppc_of_remove(struct platform_device *op)
{
struct usb_hcd *hcd = dev_get_drvdata(&op->dev);
dev_set_drvdata(&op->dev, NULL);
dev_dbg(&op->dev, "stopping PPC-OF USB Controller\n");
usb_remove_hcd(hcd);
iounmap(hcd->regs);
irq_dispose_mapping(hcd->irq);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
static void ohci_hcd_ppc_of_shutdown(struct platform_device *op)
{
struct usb_hcd *hcd = dev_get_drvdata(&op->dev);
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
