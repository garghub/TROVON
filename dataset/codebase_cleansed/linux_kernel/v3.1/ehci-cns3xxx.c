static int cns3xxx_ehci_init(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval;
if (atomic_inc_return(&usb_pwr_ref) == 1) {
cns3xxx_pwr_power_up(1 << PM_PLL_HM_PD_CTRL_REG_OFFSET_PLL_USB);
cns3xxx_pwr_clk_en(1 << PM_CLK_GATE_REG_OFFSET_USB_HOST);
cns3xxx_pwr_soft_rst(1 << PM_SOFT_RST_REG_OFFST_USB_HOST);
__raw_writel((__raw_readl(MISC_CHIP_CONFIG_REG) | (0X2 << 24)),
MISC_CHIP_CONFIG_REG);
}
ehci->caps = hcd->regs;
ehci->regs = hcd->regs
+ HC_LENGTH(ehci, ehci_readl(ehci, &ehci->caps->hc_capbase));
ehci->hcs_params = ehci_readl(ehci, &ehci->caps->hcs_params);
hcd->has_tt = 0;
ehci_reset(ehci);
retval = ehci_init(hcd);
if (retval)
return retval;
ehci_port_power(ehci, 0);
return retval;
}
static int cns3xxx_ehci_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usb_hcd *hcd;
const struct hc_driver *driver = &cns3xxx_ehci_hc_driver;
struct resource *res;
int irq;
int retval;
if (usb_disabled())
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(dev, "Found HC with no IRQ.\n");
return -ENODEV;
}
irq = res->start;
hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "Found HC with no register addr.\n");
retval = -ENODEV;
goto err1;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len,
driver->description)) {
dev_dbg(dev, "controller already in use\n");
retval = -EBUSY;
goto err1;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
dev_dbg(dev, "error mapping memory\n");
retval = -EFAULT;
goto err2;
}
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval == 0)
return retval;
iounmap(hcd->regs);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return retval;
}
static int cns3xxx_ehci_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
if (atomic_dec_return(&usb_pwr_ref) == 0)
cns3xxx_pwr_clk_dis(1 << PM_CLK_GATE_REG_OFFSET_USB_HOST);
usb_put_hcd(hcd);
platform_set_drvdata(pdev, NULL);
return 0;
}
