static void ci_hdrc_msm_notify_event(struct ci_hdrc *ci, unsigned event)
{
struct device *dev = ci->gadget.dev.parent;
switch (event) {
case CI_HDRC_CONTROLLER_RESET_EVENT:
dev_dbg(dev, "CI_HDRC_CONTROLLER_RESET_EVENT received\n");
writel(0, USB_AHBBURST);
writel(0, USB_AHBMODE);
usb_phy_init(ci->transceiver);
break;
case CI_HDRC_CONTROLLER_STOPPED_EVENT:
dev_dbg(dev, "CI_HDRC_CONTROLLER_STOPPED_EVENT received\n");
usb_phy_notify_disconnect(ci->transceiver, USB_SPEED_UNKNOWN);
break;
default:
dev_dbg(dev, "unknown ci_hdrc event\n");
break;
}
}
static int ci_hdrc_msm_probe(struct platform_device *pdev)
{
struct platform_device *plat_ci;
struct usb_phy *phy;
dev_dbg(&pdev->dev, "ci_hdrc_msm_probe\n");
phy = devm_usb_get_phy_by_phandle(&pdev->dev, "usb-phy", 0);
if (IS_ERR(phy))
return PTR_ERR(phy);
ci_hdrc_msm_platdata.phy = phy;
plat_ci = ci_hdrc_add_device(&pdev->dev,
pdev->resource, pdev->num_resources,
&ci_hdrc_msm_platdata);
if (IS_ERR(plat_ci)) {
dev_err(&pdev->dev, "ci_hdrc_add_device failed!\n");
return PTR_ERR(plat_ci);
}
platform_set_drvdata(pdev, plat_ci);
pm_runtime_no_callbacks(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return 0;
}
static int ci_hdrc_msm_remove(struct platform_device *pdev)
{
struct platform_device *plat_ci = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
ci_hdrc_remove_device(plat_ci);
return 0;
}
