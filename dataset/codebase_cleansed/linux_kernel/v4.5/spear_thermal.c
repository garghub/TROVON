static inline int thermal_get_temp(struct thermal_zone_device *thermal,
int *temp)
{
struct spear_thermal_dev *stdev = thermal->devdata;
*temp = (readl_relaxed(stdev->thermal_base) & 0x7F) * MD_FACTOR;
return 0;
}
static int __maybe_unused spear_thermal_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct thermal_zone_device *spear_thermal = platform_get_drvdata(pdev);
struct spear_thermal_dev *stdev = spear_thermal->devdata;
unsigned int actual_mask = 0;
actual_mask = readl_relaxed(stdev->thermal_base);
writel_relaxed(actual_mask & ~stdev->flags, stdev->thermal_base);
clk_disable(stdev->clk);
dev_info(dev, "Suspended.\n");
return 0;
}
static int __maybe_unused spear_thermal_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct thermal_zone_device *spear_thermal = platform_get_drvdata(pdev);
struct spear_thermal_dev *stdev = spear_thermal->devdata;
unsigned int actual_mask = 0;
int ret = 0;
ret = clk_enable(stdev->clk);
if (ret) {
dev_err(&pdev->dev, "Can't enable clock\n");
return ret;
}
actual_mask = readl_relaxed(stdev->thermal_base);
writel_relaxed(actual_mask | stdev->flags, stdev->thermal_base);
dev_info(dev, "Resumed.\n");
return 0;
}
static int spear_thermal_probe(struct platform_device *pdev)
{
struct thermal_zone_device *spear_thermal = NULL;
struct spear_thermal_dev *stdev;
struct device_node *np = pdev->dev.of_node;
struct resource *res;
int ret = 0, val;
if (!np || !of_property_read_u32(np, "st,thermal-flags", &val)) {
dev_err(&pdev->dev, "Failed: DT Pdata not passed\n");
return -EINVAL;
}
stdev = devm_kzalloc(&pdev->dev, sizeof(*stdev), GFP_KERNEL);
if (!stdev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
stdev->thermal_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(stdev->thermal_base))
return PTR_ERR(stdev->thermal_base);
stdev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(stdev->clk)) {
dev_err(&pdev->dev, "Can't get clock\n");
return PTR_ERR(stdev->clk);
}
ret = clk_enable(stdev->clk);
if (ret) {
dev_err(&pdev->dev, "Can't enable clock\n");
return ret;
}
stdev->flags = val;
writel_relaxed(stdev->flags, stdev->thermal_base);
spear_thermal = thermal_zone_device_register("spear_thermal", 0, 0,
stdev, &ops, NULL, 0, 0);
if (IS_ERR(spear_thermal)) {
dev_err(&pdev->dev, "thermal zone device is NULL\n");
ret = PTR_ERR(spear_thermal);
goto disable_clk;
}
platform_set_drvdata(pdev, spear_thermal);
dev_info(&spear_thermal->device, "Thermal Sensor Loaded at: 0x%p.\n",
stdev->thermal_base);
return 0;
disable_clk:
clk_disable(stdev->clk);
return ret;
}
static int spear_thermal_exit(struct platform_device *pdev)
{
unsigned int actual_mask = 0;
struct thermal_zone_device *spear_thermal = platform_get_drvdata(pdev);
struct spear_thermal_dev *stdev = spear_thermal->devdata;
thermal_zone_device_unregister(spear_thermal);
actual_mask = readl_relaxed(stdev->thermal_base);
writel_relaxed(actual_mask & ~stdev->flags, stdev->thermal_base);
clk_disable(stdev->clk);
return 0;
}
