static int bcm2835_thermal_adc2temp(u32 adc, int offset, int slope)
{
return offset + slope * adc;
}
static int bcm2835_thermal_temp2adc(int temp, int offset, int slope)
{
temp -= offset;
temp /= slope;
if (temp < 0)
temp = 0;
if (temp >= BIT(BCM2835_TS_TSENSSTAT_DATA_BITS))
temp = BIT(BCM2835_TS_TSENSSTAT_DATA_BITS) - 1;
return temp;
}
static int bcm2835_thermal_get_temp(void *d, int *temp)
{
struct bcm2835_thermal_data *data = d;
u32 val = readl(data->regs + BCM2835_TS_TSENSSTAT);
if (!(val & BCM2835_TS_TSENSSTAT_VALID))
return -EIO;
val &= BCM2835_TS_TSENSSTAT_DATA_MASK;
*temp = bcm2835_thermal_adc2temp(
val,
thermal_zone_get_offset(data->tz),
thermal_zone_get_slope(data->tz));
return 0;
}
static void bcm2835_thermal_debugfs(struct platform_device *pdev)
{
struct thermal_zone_device *tz = platform_get_drvdata(pdev);
struct bcm2835_thermal_data *data = tz->devdata;
struct debugfs_regset32 *regset;
data->debugfsdir = debugfs_create_dir("bcm2835_thermal", NULL);
if (!data->debugfsdir)
return;
regset = devm_kzalloc(&pdev->dev, sizeof(*regset), GFP_KERNEL);
if (!regset)
return;
regset->regs = bcm2835_thermal_regs;
regset->nregs = ARRAY_SIZE(bcm2835_thermal_regs);
regset->base = data->regs;
debugfs_create_regset32("regset", 0444, data->debugfsdir, regset);
}
static int bcm2835_thermal_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct thermal_zone_device *tz;
struct bcm2835_thermal_data *data;
struct resource *res;
int err = 0;
u32 val;
unsigned long rate;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
match = of_match_device(bcm2835_thermal_of_match_table,
&pdev->dev);
if (!match)
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->regs)) {
err = PTR_ERR(data->regs);
dev_err(&pdev->dev, "Could not get registers: %d\n", err);
return err;
}
data->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(data->clk)) {
err = PTR_ERR(data->clk);
if (err != -EPROBE_DEFER)
dev_err(&pdev->dev, "Could not get clk: %d\n", err);
return err;
}
err = clk_prepare_enable(data->clk);
if (err)
return err;
rate = clk_get_rate(data->clk);
if ((rate < 1920000) || (rate > 5000000))
dev_warn(&pdev->dev,
"Clock %pCn running at %pCr Hz is outside of the recommended range: 1.92 to 5MHz\n",
data->clk, data->clk);
tz = thermal_zone_of_sensor_register(&pdev->dev, 0, data,
&bcm2835_thermal_ops);
if (IS_ERR(tz)) {
err = PTR_ERR(tz);
dev_err(&pdev->dev,
"Failed to register the thermal device: %d\n",
err);
goto err_clk;
}
val = readl(data->regs + BCM2835_TS_TSENSCTL);
if (!(val & BCM2835_TS_TSENSCTL_RSTB)) {
int trip_temp, offset, slope;
slope = thermal_zone_get_slope(tz);
offset = thermal_zone_get_offset(tz);
err = tz->ops->get_trip_temp(tz, 0, &trip_temp);
if (err < 0) {
dev_err(&pdev->dev,
"Not able to read trip_temp: %d\n",
err);
goto err_tz;
}
val = (BCM2835_TS_TSENSCTL_CTRL_DEFAULT <<
BCM2835_TS_TSENSCTL_CTRL_SHIFT) |
BCM2835_TS_TSENSCTL_REGULEN;
val |= (0xFE << BCM2835_TS_TSENSCTL_RSTDELAY_SHIFT);
val |= bcm2835_thermal_temp2adc(trip_temp,
offset,
slope)
<< BCM2835_TS_TSENSCTL_THOLD_SHIFT;
writel(val, data->regs + BCM2835_TS_TSENSCTL);
val |= BCM2835_TS_TSENSCTL_RSTB;
writel(val, data->regs + BCM2835_TS_TSENSCTL);
}
data->tz = tz;
platform_set_drvdata(pdev, tz);
bcm2835_thermal_debugfs(pdev);
return 0;
err_tz:
thermal_zone_of_sensor_unregister(&pdev->dev, tz);
err_clk:
clk_disable_unprepare(data->clk);
return err;
}
static int bcm2835_thermal_remove(struct platform_device *pdev)
{
struct thermal_zone_device *tz = platform_get_drvdata(pdev);
struct bcm2835_thermal_data *data = tz->devdata;
debugfs_remove_recursive(data->debugfsdir);
thermal_zone_of_sensor_unregister(&pdev->dev, tz);
clk_disable_unprepare(data->clk);
return 0;
}
