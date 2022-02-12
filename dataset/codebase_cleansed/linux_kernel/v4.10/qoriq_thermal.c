static void tmu_write(struct qoriq_tmu_data *p, u32 val, void __iomem *addr)
{
if (p->little_endian)
iowrite32(val, addr);
else
iowrite32be(val, addr);
}
static u32 tmu_read(struct qoriq_tmu_data *p, void __iomem *addr)
{
if (p->little_endian)
return ioread32(addr);
else
return ioread32be(addr);
}
static int tmu_get_temp(void *p, int *temp)
{
u32 val;
struct qoriq_tmu_data *data = p;
val = tmu_read(data, &data->regs->site[data->sensor_id].tritsr);
*temp = (val & 0xff) * 1000;
return 0;
}
static int qoriq_tmu_get_sensor_id(void)
{
int ret, id;
struct of_phandle_args sensor_specs;
struct device_node *np, *sensor_np;
np = of_find_node_by_name(NULL, "thermal-zones");
if (!np)
return -ENODEV;
sensor_np = of_get_next_child(np, NULL);
ret = of_parse_phandle_with_args(sensor_np, "thermal-sensors",
"#thermal-sensor-cells",
0, &sensor_specs);
if (ret) {
of_node_put(np);
of_node_put(sensor_np);
return ret;
}
if (sensor_specs.args_count >= 1) {
id = sensor_specs.args[0];
WARN(sensor_specs.args_count > 1,
"%s: too many cells in sensor specifier %d\n",
sensor_specs.np->name, sensor_specs.args_count);
} else {
id = 0;
}
of_node_put(np);
of_node_put(sensor_np);
return id;
}
static int qoriq_tmu_calibration(struct platform_device *pdev)
{
int i, val, len;
u32 range[4];
const u32 *calibration;
struct device_node *np = pdev->dev.of_node;
struct qoriq_tmu_data *data = platform_get_drvdata(pdev);
if (of_property_read_u32_array(np, "fsl,tmu-range", range, 4)) {
dev_err(&pdev->dev, "missing calibration range.\n");
return -ENODEV;
}
tmu_write(data, range[0], &data->regs->ttr0cr);
tmu_write(data, range[1], &data->regs->ttr1cr);
tmu_write(data, range[2], &data->regs->ttr2cr);
tmu_write(data, range[3], &data->regs->ttr3cr);
calibration = of_get_property(np, "fsl,tmu-calibration", &len);
if (calibration == NULL || len % 8) {
dev_err(&pdev->dev, "invalid calibration data.\n");
return -ENODEV;
}
for (i = 0; i < len; i += 8, calibration += 2) {
val = of_read_number(calibration, 1);
tmu_write(data, val, &data->regs->ttcfgr);
val = of_read_number(calibration + 1, 1);
tmu_write(data, val, &data->regs->tscfgr);
}
return 0;
}
static void qoriq_tmu_init_device(struct qoriq_tmu_data *data)
{
tmu_write(data, TIER_DISABLE, &data->regs->tier);
tmu_write(data, TMTMIR_DEFAULT, &data->regs->tmtmir);
tmu_write(data, TMR_DISABLE, &data->regs->tmr);
}
static int qoriq_tmu_probe(struct platform_device *pdev)
{
int ret;
const struct thermal_trip *trip;
struct qoriq_tmu_data *data;
struct device_node *np = pdev->dev.of_node;
u32 site = 0;
if (!np) {
dev_err(&pdev->dev, "Device OF-Node is NULL");
return -ENODEV;
}
data = devm_kzalloc(&pdev->dev, sizeof(struct qoriq_tmu_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
platform_set_drvdata(pdev, data);
data->little_endian = of_property_read_bool(np, "little-endian");
data->sensor_id = qoriq_tmu_get_sensor_id();
if (data->sensor_id < 0) {
dev_err(&pdev->dev, "Failed to get sensor id\n");
ret = -ENODEV;
goto err_iomap;
}
data->regs = of_iomap(np, 0);
if (!data->regs) {
dev_err(&pdev->dev, "Failed to get memory region\n");
ret = -ENODEV;
goto err_iomap;
}
qoriq_tmu_init_device(data);
ret = qoriq_tmu_calibration(pdev);
if (ret < 0)
goto err_tmu;
data->tz = thermal_zone_of_sensor_register(&pdev->dev, data->sensor_id,
data, &tmu_tz_ops);
if (IS_ERR(data->tz)) {
ret = PTR_ERR(data->tz);
dev_err(&pdev->dev,
"Failed to register thermal zone device %d\n", ret);
goto err_tmu;
}
trip = of_thermal_get_trip_points(data->tz);
site |= 0x1 << (15 - data->sensor_id);
tmu_write(data, site | TMR_ME | TMR_ALPF, &data->regs->tmr);
return 0;
err_tmu:
iounmap(data->regs);
err_iomap:
platform_set_drvdata(pdev, NULL);
return ret;
}
static int qoriq_tmu_remove(struct platform_device *pdev)
{
struct qoriq_tmu_data *data = platform_get_drvdata(pdev);
thermal_zone_of_sensor_unregister(&pdev->dev, data->tz);
tmu_write(data, TMR_DISABLE, &data->regs->tmr);
iounmap(data->regs);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int qoriq_tmu_suspend(struct device *dev)
{
u32 tmr;
struct qoriq_tmu_data *data = dev_get_drvdata(dev);
tmr = tmu_read(data, &data->regs->tmr);
tmr &= ~TMR_ME;
tmu_write(data, tmr, &data->regs->tmr);
return 0;
}
static int qoriq_tmu_resume(struct device *dev)
{
u32 tmr;
struct qoriq_tmu_data *data = dev_get_drvdata(dev);
tmr = tmu_read(data, &data->regs->tmr);
tmr |= TMR_ME;
tmu_write(data, tmr, &data->regs->tmr);
return 0;
}
