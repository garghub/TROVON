static irqreturn_t axp20x_ac_power_irq(int irq, void *devid)
{
struct axp20x_ac_power *power = devid;
power_supply_changed(power->supply);
return IRQ_HANDLED;
}
static int axp20x_ac_power_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct axp20x_ac_power *power = power_supply_get_drvdata(psy);
int ret, reg;
switch (psp) {
case POWER_SUPPLY_PROP_HEALTH:
ret = regmap_read(power->regmap, AXP20X_PWR_INPUT_STATUS, &reg);
if (ret)
return ret;
if (reg & AXP20X_PWR_STATUS_ACIN_PRESENT) {
val->intval = POWER_SUPPLY_HEALTH_GOOD;
return 0;
}
val->intval = POWER_SUPPLY_HEALTH_UNKNOWN;
return 0;
case POWER_SUPPLY_PROP_PRESENT:
ret = regmap_read(power->regmap, AXP20X_PWR_INPUT_STATUS, &reg);
if (ret)
return ret;
val->intval = !!(reg & AXP20X_PWR_STATUS_ACIN_PRESENT);
return 0;
case POWER_SUPPLY_PROP_ONLINE:
ret = regmap_read(power->regmap, AXP20X_PWR_INPUT_STATUS, &reg);
if (ret)
return ret;
val->intval = !!(reg & AXP20X_PWR_STATUS_ACIN_AVAIL);
return 0;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
ret = iio_read_channel_processed(power->acin_v, &val->intval);
if (ret)
return ret;
val->intval *= 1000;
return 0;
case POWER_SUPPLY_PROP_CURRENT_NOW:
ret = iio_read_channel_processed(power->acin_i, &val->intval);
if (ret)
return ret;
val->intval *= 1000;
return 0;
default:
return -EINVAL;
}
return -EINVAL;
}
static int axp20x_ac_power_probe(struct platform_device *pdev)
{
struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
struct power_supply_config psy_cfg = {};
struct axp20x_ac_power *power;
struct axp_data *axp_data;
static const char * const irq_names[] = { "ACIN_PLUGIN", "ACIN_REMOVAL",
NULL };
int i, irq, ret;
if (!of_device_is_available(pdev->dev.of_node))
return -ENODEV;
if (!axp20x) {
dev_err(&pdev->dev, "Parent drvdata not set\n");
return -EINVAL;
}
power = devm_kzalloc(&pdev->dev, sizeof(*power), GFP_KERNEL);
if (!power)
return -ENOMEM;
axp_data = (struct axp_data *)of_device_get_match_data(&pdev->dev);
if (axp_data->acin_adc) {
power->acin_v = devm_iio_channel_get(&pdev->dev, "acin_v");
if (IS_ERR(power->acin_v)) {
if (PTR_ERR(power->acin_v) == -ENODEV)
return -EPROBE_DEFER;
return PTR_ERR(power->acin_v);
}
power->acin_i = devm_iio_channel_get(&pdev->dev, "acin_i");
if (IS_ERR(power->acin_i)) {
if (PTR_ERR(power->acin_i) == -ENODEV)
return -EPROBE_DEFER;
return PTR_ERR(power->acin_i);
}
}
power->regmap = dev_get_regmap(pdev->dev.parent, NULL);
platform_set_drvdata(pdev, power);
psy_cfg.of_node = pdev->dev.of_node;
psy_cfg.drv_data = power;
power->supply = devm_power_supply_register(&pdev->dev,
axp_data->power_desc,
&psy_cfg);
if (IS_ERR(power->supply))
return PTR_ERR(power->supply);
for (i = 0; irq_names[i]; i++) {
irq = platform_get_irq_byname(pdev, irq_names[i]);
if (irq < 0) {
dev_warn(&pdev->dev, "No IRQ for %s: %d\n",
irq_names[i], irq);
continue;
}
irq = regmap_irq_get_virq(axp20x->regmap_irqc, irq);
ret = devm_request_any_context_irq(&pdev->dev, irq,
axp20x_ac_power_irq, 0,
DRVNAME, power);
if (ret < 0)
dev_warn(&pdev->dev, "Error requesting %s IRQ: %d\n",
irq_names[i], ret);
}
return 0;
}
