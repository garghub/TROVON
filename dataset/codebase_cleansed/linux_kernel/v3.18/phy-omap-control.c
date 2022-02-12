void omap_control_pcie_pcs(struct device *dev, u8 id, u8 delay)
{
u32 val;
struct omap_control_phy *control_phy;
if (IS_ERR(dev) || !dev) {
pr_err("%s: invalid device\n", __func__);
return;
}
control_phy = dev_get_drvdata(dev);
if (!control_phy) {
dev_err(dev, "%s: invalid control phy device\n", __func__);
return;
}
if (control_phy->type != OMAP_CTRL_TYPE_PCIE) {
dev_err(dev, "%s: unsupported operation\n", __func__);
return;
}
val = readl(control_phy->pcie_pcs);
val &= ~(OMAP_CTRL_PCIE_PCS_MASK <<
(id * OMAP_CTRL_PCIE_PCS_DELAY_COUNT_SHIFT));
val |= delay << (id * OMAP_CTRL_PCIE_PCS_DELAY_COUNT_SHIFT);
writel(val, control_phy->pcie_pcs);
}
void omap_control_phy_power(struct device *dev, int on)
{
u32 val;
unsigned long rate;
struct omap_control_phy *control_phy;
if (IS_ERR(dev) || !dev) {
pr_err("%s: invalid device\n", __func__);
return;
}
control_phy = dev_get_drvdata(dev);
if (!control_phy) {
dev_err(dev, "%s: invalid control phy device\n", __func__);
return;
}
if (control_phy->type == OMAP_CTRL_TYPE_OTGHS)
return;
val = readl(control_phy->power);
switch (control_phy->type) {
case OMAP_CTRL_TYPE_USB2:
if (on)
val &= ~OMAP_CTRL_DEV_PHY_PD;
else
val |= OMAP_CTRL_DEV_PHY_PD;
break;
case OMAP_CTRL_TYPE_PCIE:
case OMAP_CTRL_TYPE_PIPE3:
rate = clk_get_rate(control_phy->sys_clk);
rate = rate/1000000;
if (on) {
val &= ~(OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_CMD_MASK |
OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_FREQ_MASK);
val |= OMAP_CTRL_PIPE3_PHY_TX_RX_POWERON <<
OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_CMD_SHIFT;
val |= rate <<
OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_FREQ_SHIFT;
} else {
val &= ~OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_CMD_MASK;
val |= OMAP_CTRL_PIPE3_PHY_TX_RX_POWEROFF <<
OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_CMD_SHIFT;
}
break;
case OMAP_CTRL_TYPE_DRA7USB2:
if (on)
val &= ~OMAP_CTRL_USB2_PHY_PD;
else
val |= OMAP_CTRL_USB2_PHY_PD;
break;
case OMAP_CTRL_TYPE_AM437USB2:
if (on) {
val &= ~(AM437X_CTRL_USB2_PHY_PD |
AM437X_CTRL_USB2_OTG_PD);
val |= (AM437X_CTRL_USB2_OTGVDET_EN |
AM437X_CTRL_USB2_OTGSESSEND_EN);
} else {
val &= ~(AM437X_CTRL_USB2_OTGVDET_EN |
AM437X_CTRL_USB2_OTGSESSEND_EN);
val |= (AM437X_CTRL_USB2_PHY_PD |
AM437X_CTRL_USB2_OTG_PD);
}
break;
default:
dev_err(dev, "%s: type %d not recognized\n",
__func__, control_phy->type);
break;
}
writel(val, control_phy->power);
}
static void omap_control_usb_host_mode(struct omap_control_phy *ctrl_phy)
{
u32 val;
val = readl(ctrl_phy->otghs_control);
val &= ~(OMAP_CTRL_DEV_IDDIG | OMAP_CTRL_DEV_SESSEND);
val |= OMAP_CTRL_DEV_AVALID | OMAP_CTRL_DEV_VBUSVALID;
writel(val, ctrl_phy->otghs_control);
}
static void omap_control_usb_device_mode(struct omap_control_phy *ctrl_phy)
{
u32 val;
val = readl(ctrl_phy->otghs_control);
val &= ~OMAP_CTRL_DEV_SESSEND;
val |= OMAP_CTRL_DEV_IDDIG | OMAP_CTRL_DEV_AVALID |
OMAP_CTRL_DEV_VBUSVALID;
writel(val, ctrl_phy->otghs_control);
}
static void omap_control_usb_set_sessionend(struct omap_control_phy *ctrl_phy)
{
u32 val;
val = readl(ctrl_phy->otghs_control);
val &= ~(OMAP_CTRL_DEV_AVALID | OMAP_CTRL_DEV_VBUSVALID);
val |= OMAP_CTRL_DEV_IDDIG | OMAP_CTRL_DEV_SESSEND;
writel(val, ctrl_phy->otghs_control);
}
void omap_control_usb_set_mode(struct device *dev,
enum omap_control_usb_mode mode)
{
struct omap_control_phy *ctrl_phy;
if (IS_ERR(dev) || !dev)
return;
ctrl_phy = dev_get_drvdata(dev);
if (!ctrl_phy) {
dev_err(dev, "Invalid control phy device\n");
return;
}
if (ctrl_phy->type != OMAP_CTRL_TYPE_OTGHS)
return;
switch (mode) {
case USB_MODE_HOST:
omap_control_usb_host_mode(ctrl_phy);
break;
case USB_MODE_DEVICE:
omap_control_usb_device_mode(ctrl_phy);
break;
case USB_MODE_DISCONNECT:
omap_control_usb_set_sessionend(ctrl_phy);
break;
default:
dev_vdbg(dev, "invalid omap control usb mode\n");
}
}
static int omap_control_phy_probe(struct platform_device *pdev)
{
struct resource *res;
const struct of_device_id *of_id;
struct omap_control_phy *control_phy;
of_id = of_match_device(of_match_ptr(omap_control_phy_id_table),
&pdev->dev);
if (!of_id)
return -EINVAL;
control_phy = devm_kzalloc(&pdev->dev, sizeof(*control_phy),
GFP_KERNEL);
if (!control_phy)
return -ENOMEM;
control_phy->dev = &pdev->dev;
control_phy->type = *(enum omap_control_phy_type *)of_id->data;
if (control_phy->type == OMAP_CTRL_TYPE_OTGHS) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"otghs_control");
control_phy->otghs_control = devm_ioremap_resource(
&pdev->dev, res);
if (IS_ERR(control_phy->otghs_control))
return PTR_ERR(control_phy->otghs_control);
} else {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"power");
control_phy->power = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(control_phy->power)) {
dev_err(&pdev->dev, "Couldn't get power register\n");
return PTR_ERR(control_phy->power);
}
}
if (control_phy->type == OMAP_CTRL_TYPE_PIPE3 ||
control_phy->type == OMAP_CTRL_TYPE_PCIE) {
control_phy->sys_clk = devm_clk_get(control_phy->dev,
"sys_clkin");
if (IS_ERR(control_phy->sys_clk)) {
pr_err("%s: unable to get sys_clkin\n", __func__);
return -EINVAL;
}
}
if (control_phy->type == OMAP_CTRL_TYPE_PCIE) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"pcie_pcs");
control_phy->pcie_pcs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(control_phy->pcie_pcs))
return PTR_ERR(control_phy->pcie_pcs);
}
dev_set_drvdata(control_phy->dev, control_phy);
return 0;
}
static int __init omap_control_phy_init(void)
{
return platform_driver_register(&omap_control_phy_driver);
}
static void __exit omap_control_phy_exit(void)
{
platform_driver_unregister(&omap_control_phy_driver);
}
