static void tilegx_start_ehc(void)
{
}
static void tilegx_stop_ehc(void)
{
}
static int tilegx_ehci_setup(struct usb_hcd *hcd)
{
int ret = ehci_init(hcd);
return ret;
}
static int ehci_hcd_tilegx_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
struct tilegx_usb_platform_data *pdata = dev_get_platdata(&pdev->dev);
pte_t pte = { 0 };
int my_cpu = smp_processor_id();
int ret;
if (usb_disabled())
return -ENODEV;
if (gxio_usb_host_init(&pdata->usb_ctx, pdata->dev_index, 1) != 0)
return -ENXIO;
hcd = usb_create_hcd(&ehci_tilegx_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd) {
ret = -ENOMEM;
goto err_hcd;
}
hcd->rsrc_start =
(ulong) gxio_usb_host_get_reg_start(&pdata->usb_ctx);
hcd->rsrc_len = gxio_usb_host_get_reg_len(&pdata->usb_ctx);
hcd->regs = gxio_usb_host_get_reg_start(&pdata->usb_ctx);
tilegx_start_ehc();
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
ehci->regs =
hcd->regs + HC_LENGTH(ehci, readl(&ehci->caps->hc_capbase));
ehci->hcs_params = readl(&ehci->caps->hcs_params);
pdata->irq = irq_alloc_hwirq(-1);
if (!pdata->irq) {
ret = -ENXIO;
goto err_no_irq;
}
tile_irq_activate(pdata->irq, TILE_IRQ_PERCPU);
ret = gxio_usb_host_cfg_interrupt(&pdata->usb_ctx,
cpu_x(my_cpu), cpu_y(my_cpu),
KERNEL_PL, pdata->irq);
if (ret) {
ret = -ENXIO;
goto err_have_irq;
}
pte = pte_set_home(pte, PAGE_HOME_HASH);
ret = gxio_usb_host_register_client_memory(&pdata->usb_ctx, pte, 0);
if (ret) {
ret = -ENXIO;
goto err_have_irq;
}
ret = usb_add_hcd(hcd, pdata->irq, IRQF_SHARED);
if (ret == 0) {
platform_set_drvdata(pdev, hcd);
device_wakeup_enable(hcd->self.controller);
return ret;
}
err_have_irq:
irq_free_hwirq(pdata->irq);
err_no_irq:
tilegx_stop_ehc();
usb_put_hcd(hcd);
err_hcd:
gxio_usb_host_destroy(&pdata->usb_ctx);
return ret;
}
static int ehci_hcd_tilegx_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct tilegx_usb_platform_data *pdata = dev_get_platdata(&pdev->dev);
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
tilegx_stop_ehc();
gxio_usb_host_destroy(&pdata->usb_ctx);
irq_free_hwirq(pdata->irq);
return 0;
}
static void ehci_hcd_tilegx_drv_shutdown(struct platform_device *pdev)
{
usb_hcd_platform_shutdown(pdev);
ehci_hcd_tilegx_drv_remove(pdev);
}
