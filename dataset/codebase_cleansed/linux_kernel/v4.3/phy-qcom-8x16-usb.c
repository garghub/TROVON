static int phy_8x16_regulators_enable(struct phy_8x16 *qphy)
{
int ret;
ret = regulator_set_voltage(qphy->vdd, HSPHY_VDD_MIN, HSPHY_VDD_MAX);
if (ret)
return ret;
ret = regulator_enable(qphy->vdd);
if (ret)
return ret;
ret = regulator_set_voltage(qphy->v3p3, HSPHY_3P3_MIN, HSPHY_3P3_MAX);
if (ret)
goto off_vdd;
ret = regulator_enable(qphy->v3p3);
if (ret)
goto off_vdd;
ret = regulator_set_voltage(qphy->v1p8, HSPHY_1P8_MIN, HSPHY_1P8_MAX);
if (ret)
goto off_3p3;
ret = regulator_enable(qphy->v1p8);
if (ret)
goto off_3p3;
return 0;
off_3p3:
regulator_disable(qphy->v3p3);
off_vdd:
regulator_disable(qphy->vdd);
return ret;
}
static void phy_8x16_regulators_disable(struct phy_8x16 *qphy)
{
regulator_disable(qphy->v1p8);
regulator_disable(qphy->v3p3);
regulator_disable(qphy->vdd);
}
static int phy_8x16_notify_connect(struct usb_phy *phy,
enum usb_device_speed speed)
{
struct phy_8x16 *qphy = container_of(phy, struct phy_8x16, phy);
u32 val;
val = ULPI_MISC_A_VBUSVLDEXTSEL | ULPI_MISC_A_VBUSVLDEXT;
usb_phy_io_write(&qphy->phy, val, ULPI_SET(ULPI_MISC_A));
val = readl(qphy->regs + HSPHY_USBCMD);
val |= HSPHY_SESS_VLD_CTRL;
writel(val, qphy->regs + HSPHY_USBCMD);
return 0;
}
static int phy_8x16_notify_disconnect(struct usb_phy *phy,
enum usb_device_speed speed)
{
struct phy_8x16 *qphy = container_of(phy, struct phy_8x16, phy);
u32 val;
val = ULPI_MISC_A_VBUSVLDEXT | ULPI_MISC_A_VBUSVLDEXTSEL;
usb_phy_io_write(&qphy->phy, val, ULPI_CLR(ULPI_MISC_A));
val = readl(qphy->regs + HSPHY_USBCMD);
val &= ~HSPHY_SESS_VLD_CTRL;
writel(val, qphy->regs + HSPHY_USBCMD);
return 0;
}
static int phy_8x16_vbus_on(struct phy_8x16 *qphy)
{
phy_8x16_notify_connect(&qphy->phy, USB_SPEED_UNKNOWN);
gpiod_set_value_cansleep(qphy->switch_gpio, 0);
return 0;
}
static int phy_8x16_vbus_off(struct phy_8x16 *qphy)
{
phy_8x16_notify_disconnect(&qphy->phy, USB_SPEED_UNKNOWN);
gpiod_set_value_cansleep(qphy->switch_gpio, 1);
return 0;
}
static int phy_8x16_vbus_notify(struct notifier_block *nb, unsigned long event,
void *ptr)
{
struct phy_8x16 *qphy = container_of(nb, struct phy_8x16, vbus_notify);
if (event)
phy_8x16_vbus_on(qphy);
else
phy_8x16_vbus_off(qphy);
return NOTIFY_DONE;
}
static int phy_8x16_init(struct usb_phy *phy)
{
struct phy_8x16 *qphy = container_of(phy, struct phy_8x16, phy);
u32 val, init[] = {0x44, 0x6B, 0x24, 0x13};
u32 addr = ULPI_EXT_VENDOR_SPECIFIC;
int idx, state;
for (idx = 0; idx < ARRAY_SIZE(init); idx++)
usb_phy_io_write(phy, init[idx], addr + idx);
reset_control_reset(qphy->phy_reset);
val = readl(qphy->regs + HSPHY_CTRL);
val |= HSPHY_POR_ASSERT;
writel(val, qphy->regs + HSPHY_CTRL);
usleep_range(12, 15);
val = readl(qphy->regs + HSPHY_CTRL);
val &= ~HSPHY_POR_ASSERT;
writel(val, qphy->regs + HSPHY_CTRL);
usleep_range(10, 15);
writel(0x00, qphy->regs + HSPHY_AHBBURST);
writel(0x08, qphy->regs + HSPHY_AHBMODE);
val = readl(qphy->regs + HSPHY_GENCONFIG);
val &= ~HSPHY_TXFIFO_IDLE_FORCE_DIS;
writel(val, qphy->regs + HSPHY_GENCONFIG);
val = readl(qphy->regs + HSPHY_GENCONFIG_2);
val |= HSPHY_SESS_VLD_CTRL_EN;
writel(val, qphy->regs + HSPHY_GENCONFIG_2);
val = ULPI_PWR_OTG_COMP_DISABLE;
usb_phy_io_write(phy, val, ULPI_SET(ULPI_PWR_CLK_MNG_REG));
state = extcon_get_cable_state(qphy->vbus_cable.edev, "USB");
if (state)
phy_8x16_vbus_on(qphy);
else
phy_8x16_vbus_off(qphy);
val = usb_phy_io_read(&qphy->phy, ULPI_FUNC_CTRL);
val &= ~ULPI_FUNC_CTRL_OPMODE_MASK;
val |= ULPI_FUNC_CTRL_OPMODE_NORMAL;
usb_phy_io_write(&qphy->phy, val, ULPI_FUNC_CTRL);
return 0;
}
static void phy_8x16_shutdown(struct usb_phy *phy)
{
u32 val;
val = usb_phy_io_read(phy, ULPI_FUNC_CTRL);
val &= ~ULPI_FUNC_CTRL_OPMODE_MASK;
val |= ULPI_FUNC_CTRL_OPMODE_NONDRIVING;
usb_phy_io_write(phy, val, ULPI_FUNC_CTRL);
}
static int phy_8x16_read_devicetree(struct phy_8x16 *qphy)
{
struct regulator_bulk_data regs[3];
struct device *dev = qphy->phy.dev;
int ret;
qphy->core_clk = devm_clk_get(dev, "core");
if (IS_ERR(qphy->core_clk))
return PTR_ERR(qphy->core_clk);
qphy->iface_clk = devm_clk_get(dev, "iface");
if (IS_ERR(qphy->iface_clk))
return PTR_ERR(qphy->iface_clk);
regs[0].supply = "v3p3";
regs[1].supply = "v1p8";
regs[2].supply = "vddcx";
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(regs), regs);
if (ret)
return ret;
qphy->v3p3 = regs[0].consumer;
qphy->v1p8 = regs[1].consumer;
qphy->vdd = regs[2].consumer;
qphy->phy_reset = devm_reset_control_get(dev, "phy");
if (IS_ERR(qphy->phy_reset))
return PTR_ERR(qphy->phy_reset);
qphy->switch_gpio = devm_gpiod_get_optional(dev, "switch",
GPIOD_OUT_LOW);
if (IS_ERR(qphy->switch_gpio))
return PTR_ERR(qphy->switch_gpio);
return 0;
}
static int phy_8x16_reboot_notify(struct notifier_block *this,
unsigned long code, void *unused)
{
struct phy_8x16 *qphy;
qphy = container_of(this, struct phy_8x16, reboot_notify);
gpiod_set_value_cansleep(qphy->switch_gpio, 0);
return NOTIFY_DONE;
}
static int phy_8x16_probe(struct platform_device *pdev)
{
struct extcon_dev *edev;
struct phy_8x16 *qphy;
struct resource *res;
struct usb_phy *phy;
int ret;
qphy = devm_kzalloc(&pdev->dev, sizeof(*qphy), GFP_KERNEL);
if (!qphy)
return -ENOMEM;
platform_set_drvdata(pdev, qphy);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
qphy->regs = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!qphy->regs)
return -ENOMEM;
phy = &qphy->phy;
phy->dev = &pdev->dev;
phy->label = dev_name(&pdev->dev);
phy->init = phy_8x16_init;
phy->shutdown = phy_8x16_shutdown;
phy->notify_connect = phy_8x16_notify_connect;
phy->notify_disconnect = phy_8x16_notify_disconnect;
phy->io_priv = qphy->regs + HSPHY_ULPI_VIEWPORT;
phy->io_ops = &ulpi_viewport_access_ops;
phy->type = USB_PHY_TYPE_USB2;
ret = phy_8x16_read_devicetree(qphy);
if (ret < 0)
return ret;
edev = extcon_get_edev_by_phandle(phy->dev, 0);
if (IS_ERR(edev))
return PTR_ERR(edev);
ret = clk_set_rate(qphy->core_clk, INT_MAX);
if (ret < 0)
dev_dbg(phy->dev, "Can't boost core clock\n");
ret = clk_prepare_enable(qphy->core_clk);
if (ret < 0)
return ret;
ret = clk_prepare_enable(qphy->iface_clk);
if (ret < 0)
goto off_core;
ret = phy_8x16_regulators_enable(qphy);
if (0 && ret)
goto off_clks;
qphy->vbus_notify.notifier_call = phy_8x16_vbus_notify;
ret = extcon_register_interest(&qphy->vbus_cable, edev->name,
"USB", &qphy->vbus_notify);
if (ret < 0)
goto off_power;
ret = usb_add_phy_dev(&qphy->phy);
if (ret)
goto off_extcon;
qphy->reboot_notify.notifier_call = phy_8x16_reboot_notify;
register_reboot_notifier(&qphy->reboot_notify);
return 0;
off_extcon:
extcon_unregister_interest(&qphy->vbus_cable);
off_power:
phy_8x16_regulators_disable(qphy);
off_clks:
clk_disable_unprepare(qphy->iface_clk);
off_core:
clk_disable_unprepare(qphy->core_clk);
return ret;
}
static int phy_8x16_remove(struct platform_device *pdev)
{
struct phy_8x16 *qphy = platform_get_drvdata(pdev);
unregister_reboot_notifier(&qphy->reboot_notify);
extcon_unregister_interest(&qphy->vbus_cable);
gpiod_set_value_cansleep(qphy->switch_gpio, 0);
usb_remove_phy(&qphy->phy);
clk_disable_unprepare(qphy->iface_clk);
clk_disable_unprepare(qphy->core_clk);
phy_8x16_regulators_disable(qphy);
return 0;
}
