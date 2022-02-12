static inline u32 st_dwc3_readl(void __iomem *base, u32 offset)
{
return readl_relaxed(base + offset);
}
static inline void st_dwc3_writel(void __iomem *base, u32 offset, u32 value)
{
writel_relaxed(value, base + offset);
}
static int st_dwc3_drd_init(struct st_dwc3 *dwc3_data)
{
u32 val;
int err;
err = regmap_read(dwc3_data->regmap, dwc3_data->syscfg_reg_off, &val);
if (err)
return err;
val &= USB3_CONTROL_MASK;
switch (dwc3_data->dr_mode) {
case USB_DR_MODE_PERIPHERAL:
val &= ~(USB3_DELAY_VBUSVALID
| USB3_SEL_FORCE_OPMODE | USB3_FORCE_OPMODE(0x3)
| USB3_SEL_FORCE_DPPULLDOWN2 | USB3_FORCE_DPPULLDOWN2
| USB3_SEL_FORCE_DMPULLDOWN2 | USB3_FORCE_DMPULLDOWN2);
val |= USB3_DEVICE_NOT_HOST | USB3_FORCE_VBUSVALID;
break;
case USB_DR_MODE_HOST:
val &= ~(USB3_DEVICE_NOT_HOST | USB3_FORCE_VBUSVALID
| USB3_SEL_FORCE_OPMODE | USB3_FORCE_OPMODE(0x3)
| USB3_SEL_FORCE_DPPULLDOWN2 | USB3_FORCE_DPPULLDOWN2
| USB3_SEL_FORCE_DMPULLDOWN2 | USB3_FORCE_DMPULLDOWN2);
val |= USB3_DELAY_VBUSVALID;
break;
default:
dev_err(dwc3_data->dev, "Unsupported mode of operation %d\n",
dwc3_data->dr_mode);
return -EINVAL;
}
return regmap_write(dwc3_data->regmap, dwc3_data->syscfg_reg_off, val);
}
static void st_dwc3_init(struct st_dwc3 *dwc3_data)
{
u32 reg = st_dwc3_readl(dwc3_data->glue_base, CLKRST_CTRL);
reg |= AUX_CLK_EN | EXT_CFG_RESET_N | XHCI_REVISION;
reg &= ~SW_PIPEW_RESET_N;
st_dwc3_writel(dwc3_data->glue_base, CLKRST_CTRL, reg);
reg = st_dwc3_readl(dwc3_data->glue_base, USB2_VBUS_MNGMNT_SEL1);
reg |= SEL_OVERRIDE_VBUSVALID(USB2_VBUS_UTMIOTG) |
SEL_OVERRIDE_POWERPRESENT(USB2_VBUS_UTMIOTG) |
SEL_OVERRIDE_BVALID(USB2_VBUS_UTMIOTG);
st_dwc3_writel(dwc3_data->glue_base, USB2_VBUS_MNGMNT_SEL1, reg);
reg = st_dwc3_readl(dwc3_data->glue_base, CLKRST_CTRL);
reg |= SW_PIPEW_RESET_N;
st_dwc3_writel(dwc3_data->glue_base, CLKRST_CTRL, reg);
}
static int st_dwc3_probe(struct platform_device *pdev)
{
struct st_dwc3 *dwc3_data;
struct resource *res;
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node, *child;
struct platform_device *child_pdev;
struct regmap *regmap;
int ret;
dwc3_data = devm_kzalloc(dev, sizeof(*dwc3_data), GFP_KERNEL);
if (!dwc3_data)
return -ENOMEM;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "reg-glue");
dwc3_data->glue_base = devm_ioremap_resource(dev, res);
if (IS_ERR(dwc3_data->glue_base))
return PTR_ERR(dwc3_data->glue_base);
regmap = syscon_regmap_lookup_by_phandle(node, "st,syscfg");
if (IS_ERR(regmap))
return PTR_ERR(regmap);
dwc3_data->dev = dev;
dwc3_data->regmap = regmap;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "syscfg-reg");
if (!res) {
ret = -ENXIO;
goto undo_platform_dev_alloc;
}
dwc3_data->syscfg_reg_off = res->start;
dev_vdbg(&pdev->dev, "glue-logic addr 0x%p, syscfg-reg offset 0x%x\n",
dwc3_data->glue_base, dwc3_data->syscfg_reg_off);
dwc3_data->rstc_pwrdn =
devm_reset_control_get_exclusive(dev, "powerdown");
if (IS_ERR(dwc3_data->rstc_pwrdn)) {
dev_err(&pdev->dev, "could not get power controller\n");
ret = PTR_ERR(dwc3_data->rstc_pwrdn);
goto undo_platform_dev_alloc;
}
reset_control_deassert(dwc3_data->rstc_pwrdn);
dwc3_data->rstc_rst =
devm_reset_control_get_shared(dev, "softreset");
if (IS_ERR(dwc3_data->rstc_rst)) {
dev_err(&pdev->dev, "could not get reset controller\n");
ret = PTR_ERR(dwc3_data->rstc_rst);
goto undo_powerdown;
}
reset_control_deassert(dwc3_data->rstc_rst);
child = of_get_child_by_name(node, "dwc3");
if (!child) {
dev_err(&pdev->dev, "failed to find dwc3 core node\n");
ret = -ENODEV;
goto undo_softreset;
}
ret = of_platform_populate(node, NULL, NULL, dev);
if (ret) {
dev_err(dev, "failed to add dwc3 core\n");
goto undo_softreset;
}
child_pdev = of_find_device_by_node(child);
if (!child_pdev) {
dev_err(dev, "failed to find dwc3 core device\n");
ret = -ENODEV;
goto undo_softreset;
}
dwc3_data->dr_mode = usb_get_dr_mode(&child_pdev->dev);
ret = st_dwc3_drd_init(dwc3_data);
if (ret) {
dev_err(dev, "drd initialisation failed\n");
goto undo_softreset;
}
st_dwc3_init(dwc3_data);
platform_set_drvdata(pdev, dwc3_data);
return 0;
undo_softreset:
reset_control_assert(dwc3_data->rstc_rst);
undo_powerdown:
reset_control_assert(dwc3_data->rstc_pwrdn);
undo_platform_dev_alloc:
platform_device_put(pdev);
return ret;
}
static int st_dwc3_remove(struct platform_device *pdev)
{
struct st_dwc3 *dwc3_data = platform_get_drvdata(pdev);
of_platform_depopulate(&pdev->dev);
reset_control_assert(dwc3_data->rstc_pwrdn);
reset_control_assert(dwc3_data->rstc_rst);
return 0;
}
static int st_dwc3_suspend(struct device *dev)
{
struct st_dwc3 *dwc3_data = dev_get_drvdata(dev);
reset_control_assert(dwc3_data->rstc_pwrdn);
reset_control_assert(dwc3_data->rstc_rst);
pinctrl_pm_select_sleep_state(dev);
return 0;
}
static int st_dwc3_resume(struct device *dev)
{
struct st_dwc3 *dwc3_data = dev_get_drvdata(dev);
int ret;
pinctrl_pm_select_default_state(dev);
reset_control_deassert(dwc3_data->rstc_pwrdn);
reset_control_deassert(dwc3_data->rstc_rst);
ret = st_dwc3_drd_init(dwc3_data);
if (ret) {
dev_err(dev, "drd initialisation failed\n");
return ret;
}
st_dwc3_init(dwc3_data);
return 0;
}
