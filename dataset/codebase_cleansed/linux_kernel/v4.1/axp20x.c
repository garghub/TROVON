static void axp20x_power_off(void)
{
if (axp20x_pm_power_off->variant == AXP288_ID)
return;
regmap_write(axp20x_pm_power_off->regmap, AXP20X_OFF_CTRL,
AXP20X_OFF);
}
static int axp20x_match_device(struct axp20x_dev *axp20x, struct device *dev)
{
const struct acpi_device_id *acpi_id;
const struct of_device_id *of_id;
if (dev->of_node) {
of_id = of_match_device(axp20x_of_match, dev);
if (!of_id) {
dev_err(dev, "Unable to match OF ID\n");
return -ENODEV;
}
axp20x->variant = (long) of_id->data;
} else {
acpi_id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!acpi_id || !acpi_id->driver_data) {
dev_err(dev, "Unable to match ACPI ID and data\n");
return -ENODEV;
}
axp20x->variant = (long) acpi_id->driver_data;
}
switch (axp20x->variant) {
case AXP202_ID:
case AXP209_ID:
axp20x->nr_cells = ARRAY_SIZE(axp20x_cells);
axp20x->cells = axp20x_cells;
axp20x->regmap_cfg = &axp20x_regmap_config;
axp20x->regmap_irq_chip = &axp20x_regmap_irq_chip;
break;
case AXP288_ID:
axp20x->cells = axp288_cells;
axp20x->nr_cells = ARRAY_SIZE(axp288_cells);
axp20x->regmap_cfg = &axp288_regmap_config;
axp20x->regmap_irq_chip = &axp288_regmap_irq_chip;
break;
default:
dev_err(dev, "unsupported AXP20X ID %lu\n", axp20x->variant);
return -EINVAL;
}
dev_info(dev, "AXP20x variant %s found\n",
axp20x_model_names[axp20x->variant]);
return 0;
}
static int axp20x_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct axp20x_dev *axp20x;
int ret;
axp20x = devm_kzalloc(&i2c->dev, sizeof(*axp20x), GFP_KERNEL);
if (!axp20x)
return -ENOMEM;
ret = axp20x_match_device(axp20x, &i2c->dev);
if (ret)
return ret;
axp20x->i2c_client = i2c;
axp20x->dev = &i2c->dev;
dev_set_drvdata(axp20x->dev, axp20x);
axp20x->regmap = devm_regmap_init_i2c(i2c, axp20x->regmap_cfg);
if (IS_ERR(axp20x->regmap)) {
ret = PTR_ERR(axp20x->regmap);
dev_err(&i2c->dev, "regmap init failed: %d\n", ret);
return ret;
}
ret = regmap_add_irq_chip(axp20x->regmap, i2c->irq,
IRQF_ONESHOT | IRQF_SHARED, -1,
axp20x->regmap_irq_chip,
&axp20x->regmap_irqc);
if (ret) {
dev_err(&i2c->dev, "failed to add irq chip: %d\n", ret);
return ret;
}
ret = mfd_add_devices(axp20x->dev, -1, axp20x->cells,
axp20x->nr_cells, NULL, 0, NULL);
if (ret) {
dev_err(&i2c->dev, "failed to add MFD devices: %d\n", ret);
regmap_del_irq_chip(i2c->irq, axp20x->regmap_irqc);
return ret;
}
if (!pm_power_off) {
axp20x_pm_power_off = axp20x;
pm_power_off = axp20x_power_off;
}
dev_info(&i2c->dev, "AXP20X driver loaded\n");
return 0;
}
static int axp20x_i2c_remove(struct i2c_client *i2c)
{
struct axp20x_dev *axp20x = i2c_get_clientdata(i2c);
if (axp20x == axp20x_pm_power_off) {
axp20x_pm_power_off = NULL;
pm_power_off = NULL;
}
mfd_remove_devices(axp20x->dev);
regmap_del_irq_chip(axp20x->i2c_client->irq, axp20x->regmap_irqc);
return 0;
}
