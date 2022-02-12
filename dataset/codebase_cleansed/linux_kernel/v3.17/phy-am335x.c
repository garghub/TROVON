static int am335x_init(struct usb_phy *phy)
{
struct am335x_phy *am_phy = dev_get_drvdata(phy->dev);
phy_ctrl_power(am_phy->phy_ctrl, am_phy->id, true);
return 0;
}
static void am335x_shutdown(struct usb_phy *phy)
{
struct am335x_phy *am_phy = dev_get_drvdata(phy->dev);
phy_ctrl_power(am_phy->phy_ctrl, am_phy->id, false);
}
static int am335x_phy_probe(struct platform_device *pdev)
{
struct am335x_phy *am_phy;
struct device *dev = &pdev->dev;
int ret;
am_phy = devm_kzalloc(dev, sizeof(*am_phy), GFP_KERNEL);
if (!am_phy)
return -ENOMEM;
am_phy->phy_ctrl = am335x_get_phy_control(dev);
if (!am_phy->phy_ctrl)
return -EPROBE_DEFER;
am_phy->id = of_alias_get_id(pdev->dev.of_node, "phy");
if (am_phy->id < 0) {
dev_err(&pdev->dev, "Missing PHY id: %d\n", am_phy->id);
return am_phy->id;
}
ret = usb_phy_gen_create_phy(dev, &am_phy->usb_phy_gen, NULL);
if (ret)
return ret;
ret = usb_add_phy_dev(&am_phy->usb_phy_gen.phy);
if (ret)
return ret;
am_phy->usb_phy_gen.phy.init = am335x_init;
am_phy->usb_phy_gen.phy.shutdown = am335x_shutdown;
platform_set_drvdata(pdev, am_phy);
device_init_wakeup(dev, true);
device_set_wakeup_enable(dev, false);
phy_ctrl_power(am_phy->phy_ctrl, am_phy->id, false);
return 0;
}
static int am335x_phy_remove(struct platform_device *pdev)
{
struct am335x_phy *am_phy = platform_get_drvdata(pdev);
usb_remove_phy(&am_phy->usb_phy_gen.phy);
return 0;
}
static int am335x_phy_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct am335x_phy *am_phy = platform_get_drvdata(pdev);
if (device_may_wakeup(dev))
phy_ctrl_wkup(am_phy->phy_ctrl, am_phy->id, true);
phy_ctrl_power(am_phy->phy_ctrl, am_phy->id, false);
return 0;
}
static int am335x_phy_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct am335x_phy *am_phy = platform_get_drvdata(pdev);
phy_ctrl_power(am_phy->phy_ctrl, am_phy->id, true);
if (device_may_wakeup(dev))
phy_ctrl_wkup(am_phy->phy_ctrl, am_phy->id, false);
return 0;
}
