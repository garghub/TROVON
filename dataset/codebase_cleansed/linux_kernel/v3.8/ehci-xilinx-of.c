static int ehci_xilinx_port_handed_over(struct usb_hcd *hcd, int portnum)
{
dev_warn(hcd->self.controller, "port %d cannot be enabled\n", portnum);
if (hcd->has_tt) {
dev_warn(hcd->self.controller,
"Maybe you have connected a low speed device?\n");
dev_warn(hcd->self.controller,
"We do not support low speed devices\n");
} else {
dev_warn(hcd->self.controller,
"Maybe your device is not a high speed device?\n");
dev_warn(hcd->self.controller,
"The USB host controller does not support full speed "
"nor low speed devices\n");
dev_warn(hcd->self.controller,
"You can reconfigure the host controller to have "
"full speed support\n");
}
return 0;
}
static int ehci_hcd_xilinx_of_probe(struct platform_device *op)
{
struct device_node *dn = op->dev.of_node;
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
struct resource res;
int irq;
int rv;
int *value;
if (usb_disabled())
return -ENODEV;
dev_dbg(&op->dev, "initializing XILINX-OF USB Controller\n");
rv = of_address_to_resource(dn, 0, &res);
if (rv)
return rv;
hcd = usb_create_hcd(&ehci_xilinx_of_hc_driver, &op->dev,
"XILINX-OF USB");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res.start;
hcd->rsrc_len = resource_size(&res);
irq = irq_of_parse_and_map(dn, 0);
if (!irq) {
printk(KERN_ERR "%s: irq_of_parse_and_map failed\n", __FILE__);
rv = -EBUSY;
goto err_irq;
}
hcd->regs = devm_request_and_ioremap(&op->dev, &res);
if (!hcd->regs) {
pr_err("%s: devm_request_and_ioremap failed\n", __FILE__);
rv = -ENOMEM;
goto err_irq;
}
ehci = hcd_to_ehci(hcd);
ehci->big_endian_mmio = 1;
ehci->big_endian_desc = 1;
value = (int *)of_get_property(dn, "xlnx,support-usb-fs", NULL);
if (value && (*value == 1)) {
ehci_dbg(ehci, "USB host controller supports FS devices\n");
hcd->has_tt = 1;
} else {
ehci_dbg(ehci,
"USB host controller is HS only\n");
hcd->has_tt = 0;
}
ehci->caps = hcd->regs + 0x100;
rv = usb_add_hcd(hcd, irq, 0);
if (rv == 0)
return 0;
err_irq:
usb_put_hcd(hcd);
return rv;
}
static int ehci_hcd_xilinx_of_remove(struct platform_device *op)
{
struct usb_hcd *hcd = dev_get_drvdata(&op->dev);
dev_set_drvdata(&op->dev, NULL);
dev_dbg(&op->dev, "stopping XILINX-OF USB Controller\n");
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
return 0;
}
static void ehci_hcd_xilinx_of_shutdown(struct platform_device *op)
{
struct usb_hcd *hcd = dev_get_drvdata(&op->dev);
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
