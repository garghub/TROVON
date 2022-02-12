static void ci13xxx_msm_notify_event(struct ci13xxx *udc, unsigned event)
{
struct device *dev = udc->gadget.dev.parent;
int val;
switch (event) {
case CI13XXX_CONTROLLER_RESET_EVENT:
dev_dbg(dev, "CI13XXX_CONTROLLER_RESET_EVENT received\n");
writel(0, USB_AHBBURST);
writel(0, USB_AHBMODE);
break;
case CI13XXX_CONTROLLER_STOPPED_EVENT:
dev_dbg(dev, "CI13XXX_CONTROLLER_STOPPED_EVENT received\n");
val = usb_phy_io_read(udc->transceiver, ULPI_FUNC_CTRL);
val &= ~ULPI_FUNC_CTRL_OPMODE_MASK;
val |= ULPI_FUNC_CTRL_OPMODE_NONDRIVING;
usb_phy_io_write(udc->transceiver, val, ULPI_FUNC_CTRL);
break;
default:
dev_dbg(dev, "unknown ci13xxx_udc event\n");
break;
}
}
static int ci13xxx_msm_probe(struct platform_device *pdev)
{
struct platform_device *plat_ci;
int ret;
dev_dbg(&pdev->dev, "ci13xxx_msm_probe\n");
plat_ci = platform_device_alloc("ci_hdrc", -1);
if (!plat_ci) {
dev_err(&pdev->dev, "can't allocate ci_hdrc platform device\n");
return -ENOMEM;
}
ret = platform_device_add_resources(plat_ci, pdev->resource,
pdev->num_resources);
if (ret) {
dev_err(&pdev->dev, "can't add resources to platform device\n");
goto put_platform;
}
ret = platform_device_add_data(plat_ci, &ci13xxx_msm_udc_driver,
sizeof(ci13xxx_msm_udc_driver));
if (ret)
goto put_platform;
ret = platform_device_add(plat_ci);
if (ret)
goto put_platform;
pm_runtime_no_callbacks(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return 0;
put_platform:
platform_device_put(plat_ci);
return ret;
}
static int __init ci13xxx_msm_init(void)
{
return platform_driver_register(&ci13xxx_msm_driver);
}
