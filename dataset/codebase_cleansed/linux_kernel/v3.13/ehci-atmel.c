static void atmel_start_clock(void)
{
if (IS_ENABLED(CONFIG_COMMON_CLK)) {
clk_set_rate(uclk, 48000000);
clk_prepare_enable(uclk);
}
clk_prepare_enable(iclk);
clk_prepare_enable(fclk);
clocked = 1;
}
static void atmel_stop_clock(void)
{
clk_disable_unprepare(fclk);
clk_disable_unprepare(iclk);
if (IS_ENABLED(CONFIG_COMMON_CLK))
clk_disable_unprepare(uclk);
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
static int ehci_atmel_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
const struct hc_driver *driver = &ehci_atmel_hc_driver;
struct resource *res;
struct ehci_hcd *ehci;
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
retval = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (retval)
goto fail_create_hcd;
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
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
retval = PTR_ERR(hcd->regs);
goto fail_request_resource;
}
iclk = devm_clk_get(&pdev->dev, "ehci_clk");
if (IS_ERR(iclk)) {
dev_err(&pdev->dev, "Error getting interface clock\n");
retval = -ENOENT;
goto fail_request_resource;
}
fclk = devm_clk_get(&pdev->dev, "uhpck");
if (IS_ERR(fclk)) {
dev_err(&pdev->dev, "Error getting function clock\n");
retval = -ENOENT;
goto fail_request_resource;
}
if (IS_ENABLED(CONFIG_COMMON_CLK)) {
uclk = devm_clk_get(&pdev->dev, "usb_clk");
if (IS_ERR(uclk)) {
dev_err(&pdev->dev, "failed to get uclk\n");
retval = PTR_ERR(uclk);
goto fail_request_resource;
}
}
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
atmel_start_ehci(pdev);
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval)
goto fail_add_hcd;
return retval;
fail_add_hcd:
atmel_stop_ehci(pdev);
fail_request_resource:
usb_put_hcd(hcd);
fail_create_hcd:
dev_err(&pdev->dev, "init %s fail, %d\n",
dev_name(&pdev->dev), retval);
return retval;
}
static int ehci_atmel_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
atmel_stop_ehci(pdev);
fclk = iclk = NULL;
return 0;
}
static int __init ehci_atmel_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ehci_init_driver(&ehci_atmel_hc_driver, NULL);
return platform_driver_register(&ehci_atmel_driver);
}
static void __exit ehci_atmel_cleanup(void)
{
platform_driver_unregister(&ehci_atmel_driver);
}
