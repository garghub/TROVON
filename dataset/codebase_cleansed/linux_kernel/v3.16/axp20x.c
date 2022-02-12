static void axp20x_power_off(void)
{
regmap_write(axp20x_pm_power_off->regmap, AXP20X_OFF_CTRL,
AXP20X_OFF);
}
static int axp20x_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct axp20x_dev *axp20x;
const struct of_device_id *of_id;
int ret;
axp20x = devm_kzalloc(&i2c->dev, sizeof(*axp20x), GFP_KERNEL);
if (!axp20x)
return -ENOMEM;
of_id = of_match_device(axp20x_of_match, &i2c->dev);
if (!of_id) {
dev_err(&i2c->dev, "Unable to setup AXP20X data\n");
return -ENODEV;
}
axp20x->variant = (long) of_id->data;
axp20x->i2c_client = i2c;
axp20x->dev = &i2c->dev;
dev_set_drvdata(axp20x->dev, axp20x);
axp20x->regmap = devm_regmap_init_i2c(i2c, &axp20x_regmap_config);
if (IS_ERR(axp20x->regmap)) {
ret = PTR_ERR(axp20x->regmap);
dev_err(&i2c->dev, "regmap init failed: %d\n", ret);
return ret;
}
ret = regmap_add_irq_chip(axp20x->regmap, i2c->irq,
IRQF_ONESHOT | IRQF_SHARED, -1,
&axp20x_regmap_irq_chip,
&axp20x->regmap_irqc);
if (ret) {
dev_err(&i2c->dev, "failed to add irq chip: %d\n", ret);
return ret;
}
ret = mfd_add_devices(axp20x->dev, -1, axp20x_cells,
ARRAY_SIZE(axp20x_cells), NULL, 0, NULL);
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
