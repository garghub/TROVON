static irqreturn_t st_mmap_thermal_trip_handler(int irq, void *sdata)
{
struct st_thermal_sensor *sensor = sdata;
thermal_zone_device_update(sensor->thermal_dev,
THERMAL_EVENT_UNSPECIFIED);
return IRQ_HANDLED;
}
static int st_mmap_power_ctrl(struct st_thermal_sensor *sensor,
enum st_thermal_power_state power_state)
{
const unsigned int mask = (THERMAL_PDN | THERMAL_SRSTN);
const unsigned int val = power_state ? mask : 0;
return regmap_update_bits(sensor->regmap, STIH416_MPE_CONF, mask, val);
}
static int st_mmap_alloc_regfields(struct st_thermal_sensor *sensor)
{
struct device *dev = sensor->dev;
struct regmap *regmap = sensor->regmap;
const struct reg_field *reg_fields = sensor->cdata->reg_fields;
sensor->int_thresh_hi = devm_regmap_field_alloc(dev, regmap,
reg_fields[INT_THRESH_HI]);
sensor->int_enable = devm_regmap_field_alloc(dev, regmap,
reg_fields[INT_ENABLE]);
if (IS_ERR(sensor->int_thresh_hi) || IS_ERR(sensor->int_enable)) {
dev_err(dev, "failed to alloc mmap regfields\n");
return -EINVAL;
}
return 0;
}
static int st_mmap_enable_irq(struct st_thermal_sensor *sensor)
{
int ret;
ret = regmap_field_write(sensor->int_thresh_hi,
sensor->cdata->crit_temp -
sensor->cdata->temp_adjust_val);
if (ret)
return ret;
return regmap_field_write(sensor->int_enable, 1);
}
static int st_mmap_register_enable_irq(struct st_thermal_sensor *sensor)
{
struct device *dev = sensor->dev;
struct platform_device *pdev = to_platform_device(dev);
int ret;
sensor->irq = platform_get_irq(pdev, 0);
if (sensor->irq < 0) {
dev_err(dev, "failed to register IRQ\n");
return sensor->irq;
}
ret = devm_request_threaded_irq(dev, sensor->irq,
NULL, st_mmap_thermal_trip_handler,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
dev->driver->name, sensor);
if (ret) {
dev_err(dev, "failed to register IRQ %d\n", sensor->irq);
return ret;
}
return st_mmap_enable_irq(sensor);
}
static int st_mmap_regmap_init(struct st_thermal_sensor *sensor)
{
struct device *dev = sensor->dev;
struct platform_device *pdev = to_platform_device(dev);
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "no memory resources defined\n");
return -ENODEV;
}
sensor->mmio_base = devm_ioremap_resource(dev, res);
if (IS_ERR(sensor->mmio_base)) {
dev_err(dev, "failed to remap IO\n");
return PTR_ERR(sensor->mmio_base);
}
sensor->regmap = devm_regmap_init_mmio(dev, sensor->mmio_base,
&st_416mpe_regmap_config);
if (IS_ERR(sensor->regmap)) {
dev_err(dev, "failed to initialise regmap\n");
return PTR_ERR(sensor->regmap);
}
return 0;
}
static int st_mmap_probe(struct platform_device *pdev)
{
return st_thermal_register(pdev, st_mmap_thermal_of_match);
}
static int st_mmap_remove(struct platform_device *pdev)
{
return st_thermal_unregister(pdev);
}
