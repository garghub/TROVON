static int
ohci_ppc_of_start(struct usb_hcd *hcd)
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
static int ohci_hcd_ppc_of_probe(struct platform_device *op)
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
hcd->rsrc_len = resource_size(&res);
hcd->regs = devm_ioremap_resource(&op->dev, &res);
if (IS_ERR(hcd->regs)) {
rv = PTR_ERR(hcd->regs);
goto err_rmr;
}
irq = irq_of_parse_and_map(dn, 0);
if (irq == NO_IRQ) {
dev_err(&op->dev, "%s: irq_of_parse_and_map failed\n",
__FILE__);
rv = -EBUSY;
goto err_rmr;
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
rv = usb_add_hcd(hcd, irq, 0);
if (rv == 0) {
device_wakeup_enable(hcd->self.controller);
return 0;
}
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
irq_dispose_mapping(irq);
err_rmr:
usb_put_hcd(hcd);
return rv;
}
static int ohci_hcd_ppc_of_remove(struct platform_device *op)
{
struct usb_hcd *hcd = platform_get_drvdata(op);
dev_dbg(&op->dev, "stopping PPC-OF USB Controller\n");
usb_remove_hcd(hcd);
irq_dispose_mapping(hcd->irq);
usb_put_hcd(hcd);
return 0;
}
