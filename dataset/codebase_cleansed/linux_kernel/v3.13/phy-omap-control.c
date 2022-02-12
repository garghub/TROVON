void omap_control_usb_phy_power(struct device *dev, int on)
{
u32 val;
unsigned long rate;
struct omap_control_usb *control_usb;
if (IS_ERR(dev) || !dev) {
pr_err("%s: invalid device\n", __func__);
return;
}
control_usb = dev_get_drvdata(dev);
if (!control_usb) {
dev_err(dev, "%s: invalid control usb device\n", __func__);
return;
}
if (control_usb->type == OMAP_CTRL_TYPE_OTGHS)
return;
val = readl(control_usb->power);
switch (control_usb->type) {
case OMAP_CTRL_TYPE_USB2:
if (on)
val &= ~OMAP_CTRL_DEV_PHY_PD;
else
val |= OMAP_CTRL_DEV_PHY_PD;
break;
case OMAP_CTRL_TYPE_PIPE3:
rate = clk_get_rate(control_usb->sys_clk);
rate = rate/1000000;
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
break;
case OMAP_CTRL_TYPE_DRA7USB2:
if (on)
val &= ~OMAP_CTRL_USB2_PHY_PD;
else
val |= OMAP_CTRL_USB2_PHY_PD;
break;
default:
dev_err(dev, "%s: type %d not recognized\n",
__func__, control_usb->type);
break;
}
writel(val, control_usb->power);
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
if (IS_ERR(dev) || !dev)
return;
ctrl_usb = dev_get_drvdata(dev);
if (!ctrl_usb) {
dev_err(dev, "Invalid control usb device\n");
return;
}
if (ctrl_usb->type != OMAP_CTRL_TYPE_OTGHS)
return;
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
const struct of_device_id *of_id;
struct omap_control_usb *control_usb;
of_id = of_match_device(of_match_ptr(omap_control_usb_id_table),
&pdev->dev);
if (!of_id)
return -EINVAL;
control_usb = devm_kzalloc(&pdev->dev, sizeof(*control_usb),
GFP_KERNEL);
if (!control_usb) {
dev_err(&pdev->dev, "unable to alloc memory for control usb\n");
return -ENOMEM;
}
control_usb->dev = &pdev->dev;
control_usb->type = *(enum omap_control_usb_type *)of_id->data;
if (control_usb->type == OMAP_CTRL_TYPE_OTGHS) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"otghs_control");
control_usb->otghs_control = devm_ioremap_resource(
&pdev->dev, res);
if (IS_ERR(control_usb->otghs_control))
return PTR_ERR(control_usb->otghs_control);
} else {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"power");
control_usb->power = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(control_usb->power)) {
dev_err(&pdev->dev, "Couldn't get power register\n");
return PTR_ERR(control_usb->power);
}
}
if (control_usb->type == OMAP_CTRL_TYPE_PIPE3) {
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
