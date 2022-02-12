static int ehci_grlib_setup(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval;
retval = ehci_setup(hcd);
if (retval)
return retval;
ehci_port_power(ehci, 1);
return retval;
}
static int __devinit ehci_hcd_grlib_probe(struct platform_device *op)
{
struct device_node *dn = op->dev.of_node;
struct usb_hcd *hcd;
struct ehci_hcd *ehci = NULL;
struct resource res;
u32 hc_capbase;
int irq;
int rv;
if (usb_disabled())
return -ENODEV;
dev_dbg(&op->dev, "initializing GRUSBHC EHCI USB Controller\n");
rv = of_address_to_resource(dn, 0, &res);
if (rv)
return rv;
op->dev.dma_mask = &op->dev.coherent_dma_mask;
hcd = usb_create_hcd(&ehci_grlib_hc_driver, &op->dev,
"GRUSBHC EHCI USB");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res.start;
hcd->rsrc_len = resource_size(&res);
irq = irq_of_parse_and_map(dn, 0);
if (irq == NO_IRQ) {
printk(KERN_ERR "%s: irq_of_parse_and_map failed\n", __FILE__);
rv = -EBUSY;
goto err_irq;
}
hcd->regs = devm_request_and_ioremap(&op->dev, &res);
if (!hcd->regs) {
pr_err("%s: devm_request_and_ioremap failed\n", __FILE__);
rv = -ENOMEM;
goto err_ioremap;
}
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
hc_capbase = ehci_readl(ehci, &ehci->caps->hc_capbase);
if (HC_VERSION(ehci, hc_capbase) != GRUSBHC_HCIVERSION) {
ehci->big_endian_mmio = 1;
ehci->big_endian_desc = 1;
ehci->big_endian_capbase = 1;
}
rv = usb_add_hcd(hcd, irq, 0);
if (rv)
goto err_ioremap;
return 0;
err_ioremap:
irq_dispose_mapping(irq);
err_irq:
usb_put_hcd(hcd);
return rv;
}
static int ehci_hcd_grlib_remove(struct platform_device *op)
{
struct usb_hcd *hcd = dev_get_drvdata(&op->dev);
dev_set_drvdata(&op->dev, NULL);
dev_dbg(&op->dev, "stopping GRLIB GRUSBHC EHCI USB Controller\n");
usb_remove_hcd(hcd);
irq_dispose_mapping(hcd->irq);
usb_put_hcd(hcd);
return 0;
}
static void ehci_hcd_grlib_shutdown(struct platform_device *op)
{
struct usb_hcd *hcd = dev_get_drvdata(&op->dev);
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
