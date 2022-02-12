static void ci13xxx_msm_notify_event(struct ci13xxx *ci, unsigned event)
{
struct device *dev = ci->gadget.dev.parent;
int val;
switch (event) {
case CI13XXX_CONTROLLER_RESET_EVENT:
dev_dbg(dev, "CI13XXX_CONTROLLER_RESET_EVENT received\n");
writel(0, USB_AHBBURST);
writel(0, USB_AHBMODE);
break;
case CI13XXX_CONTROLLER_STOPPED_EVENT:
dev_dbg(dev, "CI13XXX_CONTROLLER_STOPPED_EVENT received\n");
val = usb_phy_io_read(ci->transceiver, ULPI_FUNC_CTRL);
val &= ~ULPI_FUNC_CTRL_OPMODE_MASK;
val |= ULPI_FUNC_CTRL_OPMODE_NONDRIVING;
usb_phy_io_write(ci->transceiver, val, ULPI_FUNC_CTRL);
break;
default:
dev_dbg(dev, "unknown ci13xxx event\n");
break;
}
}
static int __devinit ci13xxx_msm_probe(struct platform_device *pdev)
{
struct platform_device *plat_ci;
dev_dbg(&pdev->dev, "ci13xxx_msm_probe\n");
plat_ci = ci13xxx_add_device(&pdev->dev,
pdev->resource, pdev->num_resources,
&ci13xxx_msm_platdata);
if (IS_ERR(plat_ci)) {
dev_err(&pdev->dev, "ci13xxx_add_device failed!\n");
return PTR_ERR(plat_ci);
}
platform_set_drvdata(pdev, plat_ci);
pm_runtime_no_callbacks(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return 0;
}
static int __devexit ci13xxx_msm_remove(struct platform_device *pdev)
{
struct platform_device *plat_ci = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
ci13xxx_remove_device(plat_ci);
return 0;
}
