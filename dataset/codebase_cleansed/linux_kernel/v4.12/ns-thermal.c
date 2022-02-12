static int ns_thermal_get_temp(void *data, int *temp)
{
struct ns_thermal *ns_thermal = data;
int offset = thermal_zone_get_offset(ns_thermal->tz);
int slope = thermal_zone_get_slope(ns_thermal->tz);
u32 val;
val = readl(ns_thermal->pvtmon + PVTMON_CONTROL0);
if ((val & PVTMON_CONTROL0_SEL_MASK) != PVTMON_CONTROL0_SEL_TEMP_MONITOR) {
val &= ~PVTMON_CONTROL0_SEL_MASK;
val |= PVTMON_CONTROL0_SEL_TEMP_MONITOR;
writel(val, ns_thermal->pvtmon + PVTMON_CONTROL0);
}
val = readl(ns_thermal->pvtmon + PVTMON_STATUS);
*temp = slope * val + offset;
return 0;
}
static int ns_thermal_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ns_thermal *ns_thermal;
ns_thermal = devm_kzalloc(dev, sizeof(*ns_thermal), GFP_KERNEL);
if (!ns_thermal)
return -ENOMEM;
ns_thermal->pvtmon = of_iomap(dev_of_node(dev), 0);
if (WARN_ON(!ns_thermal->pvtmon))
return -ENOENT;
ns_thermal->tz = devm_thermal_zone_of_sensor_register(dev, 0,
ns_thermal,
&ns_thermal_ops);
if (IS_ERR(ns_thermal->tz)) {
iounmap(ns_thermal->pvtmon);
return PTR_ERR(ns_thermal->tz);
}
platform_set_drvdata(pdev, ns_thermal);
return 0;
}
static int ns_thermal_remove(struct platform_device *pdev)
{
struct ns_thermal *ns_thermal = platform_get_drvdata(pdev);
iounmap(ns_thermal->pvtmon);
return 0;
}
