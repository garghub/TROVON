struct device *omap_get_control_dev(void)
{
if (!control_usb)
return ERR_PTR(-ENODEV);
return control_usb->dev;
}
void omap_control_usb3_phy_power(struct device *dev, bool on)
{
u32 val;
unsigned long rate;
struct omap_control_usb *control_usb = dev_get_drvdata(dev);
if (control_usb->type != OMAP_CTRL_DEV_TYPE2)
return;
rate = clk_get_rate(control_usb->sys_clk);
rate = rate/1000000;
val = readl(control_usb->phy_power);
if (on) {
val &= ~(OMAP_CTRL_USB_PWRCTL_CLK_CMD_MASK |
OMAP_CTRL_USB_PWRCTL_CLK_FREQ_MASK);
val |= OMAP_CTRL_USB3_PHY_TX_RX_POWERON <<
OMAP_CTRL_USB_PWRCTL_CLK_CMD_SHIFT;
val |= rate << OMAP_CTRL_USB_PWRCTL_CLK_FREQ_SHIFT;
} else {
val &= ~OMAP_CTRL_USB_PWRCTL_CLK_CMD_MASK;
val |= OMAP_CTRL_USB3_PHY_TX_RX_POWEROFF <<
OMAP_CTRL_USB_PWRCTL_CLK_CMD_SHIFT;
}
writel(val, control_usb->phy_power);
}
void omap_control_usb_phy_power(struct device *dev, int on)
{
u32 val;
struct omap_control_usb *control_usb = dev_get_drvdata(dev);
val = readl(control_usb->dev_conf);
if (on)
val &= ~OMAP_CTRL_DEV_PHY_PD;
else
val |= OMAP_CTRL_DEV_PHY_PD;
writel(val, control_usb->dev_conf);
}
static void omap_control_usb_host_mode(struct omap_control_usb *ctrl_usb)
{
u32 val;
val = readl(ctrl_usb->otghs_control);
val &= ~(OMAP_CTRL_DEV_IDDIG | OMAP_CTRL_DEV_SESSEND);
val |= OMAP_CTRL_DEV_AVALID | OMAP_CTRL_DEV_VBUSVALID;
writel(val, ctrl_usb->otghs_control);
}
static void omap_control_usb_device_mode(struct omap_control_usb *ctrl_usb)
{
u32 val;
val = readl(ctrl_usb->otghs_control);
val &= ~OMAP_CTRL_DEV_SESSEND;
val |= OMAP_CTRL_DEV_IDDIG | OMAP_CTRL_DEV_AVALID |
OMAP_CTRL_DEV_VBUSVALID;
writel(val, ctrl_usb->otghs_control);
}
static void omap_control_usb_set_sessionend(struct omap_control_usb *ctrl_usb)
{
u32 val;
val = readl(ctrl_usb->otghs_control);
val &= ~(OMAP_CTRL_DEV_AVALID | OMAP_CTRL_DEV_VBUSVALID);
val |= OMAP_CTRL_DEV_IDDIG | OMAP_CTRL_DEV_SESSEND;
writel(val, ctrl_usb->otghs_control);
}
void omap_control_usb_set_mode(struct device *dev,
enum omap_control_usb_mode mode)
{
struct omap_control_usb *ctrl_usb;
if (IS_ERR(dev) || control_usb->type != OMAP_CTRL_DEV_TYPE1)
return;
ctrl_usb = dev_get_drvdata(dev);
switch (mode) {
case USB_MODE_HOST:
omap_control_usb_host_mode(ctrl_usb);
break;
case USB_MODE_DEVICE:
omap_control_usb_device_mode(ctrl_usb);
break;
case USB_MODE_DISCONNECT:
omap_control_usb_set_sessionend(ctrl_usb);
break;
default:
dev_vdbg(dev, "invalid omap control usb mode\n");
}
}
static int omap_control_usb_probe(struct platform_device *pdev)
{
struct resource *res;
struct device_node *np = pdev->dev.of_node;
struct omap_control_usb_platform_data *pdata = pdev->dev.platform_data;
control_usb = devm_kzalloc(&pdev->dev, sizeof(*control_usb),
GFP_KERNEL);
if (!control_usb) {
dev_err(&pdev->dev, "unable to alloc memory for control usb\n");
return -ENOMEM;
}
if (np) {
of_property_read_u32(np, "ti,type", &control_usb->type);
} else if (pdata) {
control_usb->type = pdata->type;
} else {
dev_err(&pdev->dev, "no pdata present\n");
return -EINVAL;
}
control_usb->dev = &pdev->dev;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"control_dev_conf");
control_usb->dev_conf = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(control_usb->dev_conf))
return PTR_ERR(control_usb->dev_conf);
if (control_usb->type == OMAP_CTRL_DEV_TYPE1) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"otghs_control");
control_usb->otghs_control = devm_ioremap_resource(
&pdev->dev, res);
if (IS_ERR(control_usb->otghs_control))
return PTR_ERR(control_usb->otghs_control);
}
if (control_usb->type == OMAP_CTRL_DEV_TYPE2) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"phy_power_usb");
control_usb->phy_power = devm_ioremap_resource(
&pdev->dev, res);
if (IS_ERR(control_usb->phy_power))
return PTR_ERR(control_usb->phy_power);
control_usb->sys_clk = devm_clk_get(control_usb->dev,
"sys_clkin");
if (IS_ERR(control_usb->sys_clk)) {
pr_err("%s: unable to get sys_clkin\n", __func__);
return -EINVAL;
}
}
dev_set_drvdata(control_usb->dev, control_usb);
return 0;
}
static int __init omap_control_usb_init(void)
{
return platform_driver_register(&omap_control_usb_driver);
}
static void __exit omap_control_usb_exit(void)
{
platform_driver_unregister(&omap_control_usb_driver);
}
