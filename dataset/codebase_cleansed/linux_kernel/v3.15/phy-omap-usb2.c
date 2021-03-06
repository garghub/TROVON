int omap_usb2_set_comparator(struct phy_companion *comparator)
{
struct omap_usb *phy;
struct usb_phy *x = usb_get_phy(USB_PHY_TYPE_USB2);
if (IS_ERR(x))
return -ENODEV;
phy = phy_to_omapusb(x);
phy->comparator = comparator;
return 0;
}
static int omap_usb_set_vbus(struct usb_otg *otg, bool enabled)
{
struct omap_usb *phy = phy_to_omapusb(otg->phy);
if (!phy->comparator)
return -ENODEV;
return phy->comparator->set_vbus(phy->comparator, enabled);
}
static int omap_usb_start_srp(struct usb_otg *otg)
{
struct omap_usb *phy = phy_to_omapusb(otg->phy);
if (!phy->comparator)
return -ENODEV;
return phy->comparator->start_srp(phy->comparator);
}
static int omap_usb_set_host(struct usb_otg *otg, struct usb_bus *host)
{
struct usb_phy *phy = otg->phy;
otg->host = host;
if (!host)
phy->state = OTG_STATE_UNDEFINED;
return 0;
}
static int omap_usb_set_peripheral(struct usb_otg *otg,
struct usb_gadget *gadget)
{
struct usb_phy *phy = otg->phy;
otg->gadget = gadget;
if (!gadget)
phy->state = OTG_STATE_UNDEFINED;
return 0;
}
static int omap_usb_power_off(struct phy *x)
{
struct omap_usb *phy = phy_get_drvdata(x);
omap_control_phy_power(phy->control_dev, 0);
return 0;
}
static int omap_usb_power_on(struct phy *x)
{
struct omap_usb *phy = phy_get_drvdata(x);
omap_control_phy_power(phy->control_dev, 1);
return 0;
}
static int omap_usb_init(struct phy *x)
{
struct omap_usb *phy = phy_get_drvdata(x);
u32 val;
if (phy->flags & OMAP_USB2_CALIBRATE_FALSE_DISCONNECT) {
val = omap_usb_readl(phy->phy_base, USB2PHY_ANA_CONFIG1);
val |= USB2PHY_DISCON_BYP_LATCH;
omap_usb_writel(phy->phy_base, USB2PHY_ANA_CONFIG1, val);
}
return 0;
}
static int omap_usb2_probe(struct platform_device *pdev)
{
struct omap_usb *phy;
struct phy *generic_phy;
struct resource *res;
struct phy_provider *phy_provider;
struct usb_otg *otg;
struct device_node *node = pdev->dev.of_node;
struct device_node *control_node;
struct platform_device *control_pdev;
const struct of_device_id *of_id;
struct usb_phy_data *phy_data;
of_id = of_match_device(of_match_ptr(omap_usb2_id_table), &pdev->dev);
if (!of_id)
return -EINVAL;
phy_data = (struct usb_phy_data *)of_id->data;
phy = devm_kzalloc(&pdev->dev, sizeof(*phy), GFP_KERNEL);
if (!phy) {
dev_err(&pdev->dev, "unable to allocate memory for USB2 PHY\n");
return -ENOMEM;
}
otg = devm_kzalloc(&pdev->dev, sizeof(*otg), GFP_KERNEL);
if (!otg) {
dev_err(&pdev->dev, "unable to allocate memory for USB OTG\n");
return -ENOMEM;
}
phy->dev = &pdev->dev;
phy->phy.dev = phy->dev;
phy->phy.label = phy_data->label;
phy->phy.otg = otg;
phy->phy.type = USB_PHY_TYPE_USB2;
if (phy_data->flags & OMAP_USB2_CALIBRATE_FALSE_DISCONNECT) {
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
phy->phy_base = devm_ioremap_resource(&pdev->dev, res);
if (!phy->phy_base)
return -ENOMEM;
phy->flags |= OMAP_USB2_CALIBRATE_FALSE_DISCONNECT;
}
control_node = of_parse_phandle(node, "ctrl-module", 0);
if (!control_node) {
dev_err(&pdev->dev, "Failed to get control device phandle\n");
return -EINVAL;
}
control_pdev = of_find_device_by_node(control_node);
if (!control_pdev) {
dev_err(&pdev->dev, "Failed to get control device\n");
return -EINVAL;
}
phy->control_dev = &control_pdev->dev;
omap_control_phy_power(phy->control_dev, 0);
otg->set_host = omap_usb_set_host;
otg->set_peripheral = omap_usb_set_peripheral;
if (phy_data->flags & OMAP_USB2_HAS_SET_VBUS)
otg->set_vbus = omap_usb_set_vbus;
if (phy_data->flags & OMAP_USB2_HAS_START_SRP)
otg->start_srp = omap_usb_start_srp;
otg->phy = &phy->phy;
platform_set_drvdata(pdev, phy);
pm_runtime_enable(phy->dev);
generic_phy = devm_phy_create(phy->dev, &ops, NULL);
if (IS_ERR(generic_phy))
return PTR_ERR(generic_phy);
phy_set_drvdata(generic_phy, phy);
phy_provider = devm_of_phy_provider_register(phy->dev,
of_phy_simple_xlate);
if (IS_ERR(phy_provider))
return PTR_ERR(phy_provider);
phy->wkupclk = devm_clk_get(phy->dev, "usb_phy_cm_clk32k");
if (IS_ERR(phy->wkupclk)) {
dev_err(&pdev->dev, "unable to get usb_phy_cm_clk32k\n");
return PTR_ERR(phy->wkupclk);
}
clk_prepare(phy->wkupclk);
phy->optclk = devm_clk_get(phy->dev, "usb_otg_ss_refclk960m");
if (IS_ERR(phy->optclk))
dev_vdbg(&pdev->dev, "unable to get refclk960m\n");
else
clk_prepare(phy->optclk);
usb_add_phy_dev(&phy->phy);
return 0;
}
static int omap_usb2_remove(struct platform_device *pdev)
{
struct omap_usb *phy = platform_get_drvdata(pdev);
clk_unprepare(phy->wkupclk);
if (!IS_ERR(phy->optclk))
clk_unprepare(phy->optclk);
usb_remove_phy(&phy->phy);
return 0;
}
static int omap_usb2_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct omap_usb *phy = platform_get_drvdata(pdev);
clk_disable(phy->wkupclk);
if (!IS_ERR(phy->optclk))
clk_disable(phy->optclk);
return 0;
}
static int omap_usb2_runtime_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct omap_usb *phy = platform_get_drvdata(pdev);
int ret;
ret = clk_enable(phy->wkupclk);
if (ret < 0) {
dev_err(phy->dev, "Failed to enable wkupclk %d\n", ret);
goto err0;
}
if (!IS_ERR(phy->optclk)) {
ret = clk_enable(phy->optclk);
if (ret < 0) {
dev_err(phy->dev, "Failed to enable optclk %d\n", ret);
goto err1;
}
}
return 0;
err1:
clk_disable(phy->wkupclk);
err0:
return ret;
}
