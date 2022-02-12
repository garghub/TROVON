static void tilegx_start_ohc(void)
{
}
static void tilegx_stop_ohc(void)
{
}
static int tilegx_ohci_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
ret = ohci_init(ohci);
if (ret < 0)
return ret;
ret = ohci_run(ohci);
if (ret < 0) {
dev_err(hcd->self.controller, "can't start %s\n",
hcd->self.bus_name);
ohci_stop(hcd);
return ret;
}
return 0;
}
static int ohci_hcd_tilegx_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct tilegx_usb_platform_data *pdata = pdev->dev.platform_data;
pte_t pte = { 0 };
int my_cpu = smp_processor_id();
int ret;
if (usb_disabled())
return -ENODEV;
if (gxio_usb_host_init(&pdata->usb_ctx, pdata->dev_index, 0) != 0)
return -ENXIO;
hcd = usb_create_hcd(&ohci_tilegx_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd)
return -ENOMEM;
hcd->rsrc_start =
(ulong) gxio_usb_host_get_reg_start(&pdata->usb_ctx);
hcd->rsrc_len = gxio_usb_host_get_reg_len(&pdata->usb_ctx);
hcd->regs = gxio_usb_host_get_reg_start(&pdata->usb_ctx);
tilegx_start_ohc();
pdata->irq = create_irq();
if (pdata->irq < 0) {
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
ohci_hcd_init(hcd_to_ohci(hcd));
ret = usb_add_hcd(hcd, pdata->irq, IRQF_SHARED);
if (ret == 0) {
platform_set_drvdata(pdev, hcd);
return ret;
}
err_have_irq:
destroy_irq(pdata->irq);
err_no_irq:
tilegx_stop_ohc();
usb_put_hcd(hcd);
gxio_usb_host_destroy(&pdata->usb_ctx);
return ret;
}
static int ohci_hcd_tilegx_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct tilegx_usb_platform_data* pdata = pdev->dev.platform_data;
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
tilegx_stop_ohc();
gxio_usb_host_destroy(&pdata->usb_ctx);
destroy_irq(pdata->irq);
platform_set_drvdata(pdev, NULL);
return 0;
}
static void ohci_hcd_tilegx_drv_shutdown(struct platform_device *pdev)
{
usb_hcd_platform_shutdown(pdev);
ohci_hcd_tilegx_drv_remove(pdev);
}
