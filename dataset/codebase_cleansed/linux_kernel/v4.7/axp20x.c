static void axp20x_power_off(void)
{
if (axp20x_pm_power_off->variant == AXP288_ID)
return;
regmap_write(axp20x_pm_power_off->regmap, AXP20X_OFF_CTRL,
AXP20X_OFF);
}
int axp20x_match_device(struct axp20x_dev *axp20x)
{
struct device *dev = axp20x->dev;
const struct acpi_device_id *acpi_id;
const struct of_device_id *of_id;
if (dev->of_node) {
of_id = of_match_device(dev->driver->of_match_table, dev);
if (!of_id) {
dev_err(dev, "Unable to match OF ID\n");
return -ENODEV;
}
axp20x->variant = (long)of_id->data;
} else {
acpi_id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!acpi_id || !acpi_id->driver_data) {
dev_err(dev, "Unable to match ACPI ID and data\n");
return -ENODEV;
}
axp20x->variant = (long)acpi_id->driver_data;
}
switch (axp20x->variant) {
case AXP152_ID:
axp20x->nr_cells = ARRAY_SIZE(axp152_cells);
axp20x->cells = axp152_cells;
axp20x->regmap_cfg = &axp152_regmap_config;
axp20x->regmap_irq_chip = &axp152_regmap_irq_chip;
break;
case AXP202_ID:
case AXP209_ID:
axp20x->nr_cells = ARRAY_SIZE(axp20x_cells);
axp20x->cells = axp20x_cells;
axp20x->regmap_cfg = &axp20x_regmap_config;
axp20x->regmap_irq_chip = &axp20x_regmap_irq_chip;
break;
case AXP221_ID:
case AXP223_ID:
axp20x->nr_cells = ARRAY_SIZE(axp22x_cells);
axp20x->cells = axp22x_cells;
axp20x->regmap_cfg = &axp22x_regmap_config;
axp20x->regmap_irq_chip = &axp22x_regmap_irq_chip;
break;
case AXP288_ID:
axp20x->cells = axp288_cells;
axp20x->nr_cells = ARRAY_SIZE(axp288_cells);
axp20x->regmap_cfg = &axp288_regmap_config;
axp20x->regmap_irq_chip = &axp288_regmap_irq_chip;
break;
case AXP809_ID:
axp20x->nr_cells = ARRAY_SIZE(axp809_cells);
axp20x->cells = axp809_cells;
axp20x->regmap_cfg = &axp22x_regmap_config;
axp20x->regmap_irq_chip = &axp809_regmap_irq_chip;
break;
default:
dev_err(dev, "unsupported AXP20X ID %lu\n", axp20x->variant);
return -EINVAL;
}
dev_info(dev, "AXP20x variant %s found\n",
axp20x_model_names[axp20x->variant]);
return 0;
}
int axp20x_device_probe(struct axp20x_dev *axp20x)
{
int ret;
ret = regmap_add_irq_chip(axp20x->regmap, axp20x->irq,
IRQF_ONESHOT | IRQF_SHARED, -1,
axp20x->regmap_irq_chip,
&axp20x->regmap_irqc);
if (ret) {
dev_err(axp20x->dev, "failed to add irq chip: %d\n", ret);
return ret;
}
ret = mfd_add_devices(axp20x->dev, -1, axp20x->cells,
axp20x->nr_cells, NULL, 0, NULL);
if (ret) {
dev_err(axp20x->dev, "failed to add MFD devices: %d\n", ret);
regmap_del_irq_chip(axp20x->irq, axp20x->regmap_irqc);
return ret;
}
if (!pm_power_off) {
axp20x_pm_power_off = axp20x;
pm_power_off = axp20x_power_off;
}
dev_info(axp20x->dev, "AXP20X driver loaded\n");
return 0;
}
int axp20x_device_remove(struct axp20x_dev *axp20x)
{
if (axp20x == axp20x_pm_power_off) {
axp20x_pm_power_off = NULL;
pm_power_off = NULL;
}
mfd_remove_devices(axp20x->dev);
regmap_del_irq_chip(axp20x->irq, axp20x->regmap_irqc);
return 0;
}
