static int uhci_grlib_init(struct usb_hcd *hcd)
{
struct uhci_hcd *uhci = hcd_to_uhci(hcd);
if (!(uhci_readw(uhci, USBPORTSC1) & 0x80)) {
uhci->big_endian_mmio = 1;
uhci->big_endian_desc = 1;
}
uhci->rh_numports = uhci_count_ports(hcd);
uhci->reset_hc = uhci_generic_reset_hc;
uhci->check_and_reset_hc = uhci_generic_check_and_reset_hc;
uhci->configure_hc = NULL;
uhci->resume_detect_interrupts_are_broken = NULL;
uhci->global_suspend_mode_is_broken = NULL;
check_and_reset_hc(uhci);
return 0;
}
static int uhci_hcd_grlib_probe(struct platform_device *op)
{
struct device_node *dn = op->dev.of_node;
struct usb_hcd *hcd;
struct uhci_hcd *uhci = NULL;
struct resource res;
int irq;
int rv;
if (usb_disabled())
return -ENODEV;
dev_dbg(&op->dev, "initializing GRUSBHC UHCI USB Controller\n");
rv = of_address_to_resource(dn, 0, &res);
if (rv)
return rv;
op->dev.dma_mask = &op->dev.coherent_dma_mask;
hcd = usb_create_hcd(&uhci_grlib_hc_driver, &op->dev,
"GRUSBHC UHCI USB");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res.start;
hcd->rsrc_len = resource_size(&res);
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
uhci = hcd_to_uhci(hcd);
uhci->regs = hcd->regs;
rv = usb_add_hcd(hcd, irq, 0);
if (rv)
goto err_uhci;
return 0;
err_uhci:
iounmap(hcd->regs);
err_ioremap:
irq_dispose_mapping(irq);
err_irq:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err_rmr:
usb_put_hcd(hcd);
return rv;
}
static int uhci_hcd_grlib_remove(struct platform_device *op)
{
struct usb_hcd *hcd = platform_get_drvdata(op);
dev_dbg(&op->dev, "stopping GRLIB GRUSBHC UHCI USB Controller\n");
usb_remove_hcd(hcd);
iounmap(hcd->regs);
irq_dispose_mapping(hcd->irq);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
static void uhci_hcd_grlib_shutdown(struct platform_device *op)
{
struct usb_hcd *hcd = platform_get_drvdata(op);
uhci_hc_died(hcd_to_uhci(hcd));
}
