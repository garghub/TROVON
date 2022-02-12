static void atmel_start_clock(void)
{
clk_enable(iclk);
clk_enable(fclk);
clocked = 1;
}
static void atmel_stop_clock(void)
{
clk_disable(fclk);
clk_disable(iclk);
clocked = 0;
}
static void atmel_start_ehci(struct platform_device *pdev)
{
dev_dbg(&pdev->dev, "start\n");
atmel_start_clock();
}
static void atmel_stop_ehci(struct platform_device *pdev)
{
dev_dbg(&pdev->dev, "stop\n");
atmel_stop_clock();
}
static int ehci_atmel_setup(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval = 0;
ehci->caps = hcd->regs;
ehci->regs = hcd->regs +
HC_LENGTH(ehci, ehci_readl(ehci, &ehci->caps->hc_capbase));
dbg_hcs_params(ehci, "reset");
dbg_hcc_params(ehci, "reset");
ehci->hcs_params = ehci_readl(ehci, &ehci->caps->hcs_params);
retval = ehci_halt(ehci);
if (retval)
return retval;
retval = ehci_init(hcd);
if (retval)
return retval;
ehci->sbrn = 0x20;
ehci_reset(ehci);
ehci_port_power(ehci, 0);
return retval;
}
static int __devinit ehci_atmel_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
const struct hc_driver *driver = &ehci_atmel_hc_driver;
struct resource *res;
int irq;
int retval;
if (usb_disabled())
return -ENODEV;
pr_debug("Initializing Atmel-SoC USB Host Controller\n");
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(&pdev->dev,
"Found HC with no IRQ. Check %s setup!\n",
dev_name(&pdev->dev));
retval = -ENODEV;
goto fail_create_hcd;
}
if (!pdev->dev.dma_mask)
pdev->dev.dma_mask = &at91_ehci_dma_mask;
hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
retval = -ENOMEM;
goto fail_create_hcd;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev,
"Found HC with no register addr. Check %s setup!\n",
dev_name(&pdev->dev));
retval = -ENODEV;
goto fail_request_resource;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len,
driver->description)) {
dev_dbg(&pdev->dev, "controller already in use\n");
retval = -EBUSY;
goto fail_request_resource;
}
hcd->regs = ioremap_nocache(hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
dev_dbg(&pdev->dev, "error mapping memory\n");
retval = -EFAULT;
goto fail_ioremap;
}
iclk = clk_get(&pdev->dev, "ehci_clk");
if (IS_ERR(iclk)) {
dev_err(&pdev->dev, "Error getting interface clock\n");
retval = -ENOENT;
goto fail_get_iclk;
}
fclk = clk_get(&pdev->dev, "uhpck");
if (IS_ERR(fclk)) {
dev_err(&pdev->dev, "Error getting function clock\n");
retval = -ENOENT;
goto fail_get_fclk;
}
atmel_start_ehci(pdev);
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval)
goto fail_add_hcd;
return retval;
fail_add_hcd:
atmel_stop_ehci(pdev);
clk_put(fclk);
fail_get_fclk:
clk_put(iclk);
fail_get_iclk:
iounmap(hcd->regs);
fail_ioremap:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
fail_request_resource:
usb_put_hcd(hcd);
fail_create_hcd:
dev_err(&pdev->dev, "init %s fail, %d\n",
dev_name(&pdev->dev), retval);
return retval;
}
static int __devexit ehci_atmel_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
ehci_shutdown(hcd);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
atmel_stop_ehci(pdev);
clk_put(fclk);
clk_put(iclk);
fclk = iclk = NULL;
return 0;
}
