int usbmisc_set_ops(const struct usbmisc_ops *ops)
{
if (usbmisc_ops)
return -EBUSY;
usbmisc_ops = ops;
return 0;
}
void usbmisc_unset_ops(const struct usbmisc_ops *ops)
{
usbmisc_ops = NULL;
}
int usbmisc_get_init_data(struct device *dev, struct usbmisc_usb_device *usbdev)
{
struct device_node *np = dev->of_node;
struct of_phandle_args args;
int ret;
usbdev->dev = dev;
ret = of_parse_phandle_with_args(np, "fsl,usbmisc", "#index-cells",
0, &args);
if (ret) {
dev_err(dev, "Failed to parse property fsl,usbmisc, errno %d\n",
ret);
memset(usbdev, 0, sizeof(*usbdev));
return ret;
}
usbdev->index = args.args[0];
of_node_put(args.np);
if (of_find_property(np, "disable-over-current", NULL))
usbdev->disable_oc = 1;
return 0;
}
static int __devinit ci13xxx_imx_probe(struct platform_device *pdev)
{
struct ci13xxx_imx_data *data;
struct platform_device *plat_ci, *phy_pdev;
struct device_node *phy_np;
struct resource *res;
struct regulator *reg_vbus;
struct pinctrl *pinctrl;
int ret;
if (of_find_property(pdev->dev.of_node, "fsl,usbmisc", NULL)
&& !usbmisc_ops)
return -EPROBE_DEFER;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
dev_err(&pdev->dev, "Failed to allocate CI13xxx-IMX data!\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Can't get device resources!\n");
return -ENOENT;
}
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl))
dev_warn(&pdev->dev, "pinctrl get/select failed, err=%ld\n",
PTR_ERR(pinctrl));
data->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(data->clk)) {
dev_err(&pdev->dev,
"Failed to get clock, err=%ld\n", PTR_ERR(data->clk));
return PTR_ERR(data->clk);
}
ret = clk_prepare_enable(data->clk);
if (ret) {
dev_err(&pdev->dev,
"Failed to prepare or enable clock, err=%d\n", ret);
return ret;
}
phy_np = of_parse_phandle(pdev->dev.of_node, "fsl,usbphy", 0);
if (phy_np) {
data->phy_np = phy_np;
phy_pdev = of_find_device_by_node(phy_np);
if (phy_pdev) {
struct usb_phy *phy;
phy = pdev_to_phy(phy_pdev);
if (phy &&
try_module_get(phy_pdev->dev.driver->owner)) {
usb_phy_init(phy);
data->phy = phy;
}
}
}
reg_vbus = devm_regulator_get(&pdev->dev, "vbus");
if (!IS_ERR(reg_vbus)) {
ret = regulator_enable(reg_vbus);
if (ret) {
dev_err(&pdev->dev,
"Failed to enable vbus regulator, err=%d\n",
ret);
goto put_np;
}
data->reg_vbus = reg_vbus;
} else {
reg_vbus = NULL;
}
ci13xxx_imx_platdata.phy = data->phy;
if (!pdev->dev.dma_mask) {
pdev->dev.dma_mask = devm_kzalloc(&pdev->dev,
sizeof(*pdev->dev.dma_mask), GFP_KERNEL);
if (!pdev->dev.dma_mask) {
ret = -ENOMEM;
dev_err(&pdev->dev, "Failed to alloc dma_mask!\n");
goto err;
}
*pdev->dev.dma_mask = DMA_BIT_MASK(32);
dma_set_coherent_mask(&pdev->dev, *pdev->dev.dma_mask);
}
if (usbmisc_ops && usbmisc_ops->init) {
ret = usbmisc_ops->init(&pdev->dev);
if (ret) {
dev_err(&pdev->dev,
"usbmisc init failed, ret=%d\n", ret);
goto err;
}
}
plat_ci = ci13xxx_add_device(&pdev->dev,
pdev->resource, pdev->num_resources,
&ci13xxx_imx_platdata);
if (IS_ERR(plat_ci)) {
ret = PTR_ERR(plat_ci);
dev_err(&pdev->dev,
"Can't register ci_hdrc platform device, err=%d\n",
ret);
goto err;
}
data->ci_pdev = plat_ci;
platform_set_drvdata(pdev, data);
pm_runtime_no_callbacks(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return 0;
err:
if (reg_vbus)
regulator_disable(reg_vbus);
put_np:
if (phy_np)
of_node_put(phy_np);
clk_disable_unprepare(data->clk);
return ret;
}
static int __devexit ci13xxx_imx_remove(struct platform_device *pdev)
{
struct ci13xxx_imx_data *data = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
ci13xxx_remove_device(data->ci_pdev);
if (data->reg_vbus)
regulator_disable(data->reg_vbus);
if (data->phy) {
usb_phy_shutdown(data->phy);
module_put(data->phy->dev->driver->owner);
}
of_node_put(data->phy_np);
clk_disable_unprepare(data->clk);
platform_set_drvdata(pdev, NULL);
return 0;
}
