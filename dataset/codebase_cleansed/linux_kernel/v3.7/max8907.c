static bool max8907_gen_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX8907_REG_ON_OFF_IRQ1:
case MAX8907_REG_ON_OFF_STAT:
case MAX8907_REG_ON_OFF_IRQ2:
case MAX8907_REG_CHG_IRQ1:
case MAX8907_REG_CHG_IRQ2:
case MAX8907_REG_CHG_STAT:
return true;
default:
return false;
}
}
static bool max8907_gen_is_precious_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX8907_REG_ON_OFF_IRQ1:
case MAX8907_REG_ON_OFF_IRQ2:
case MAX8907_REG_CHG_IRQ1:
case MAX8907_REG_CHG_IRQ2:
return true;
default:
return false;
}
}
static bool max8907_gen_is_writeable_reg(struct device *dev, unsigned int reg)
{
return !max8907_gen_is_volatile_reg(dev, reg);
}
static bool max8907_rtc_is_volatile_reg(struct device *dev, unsigned int reg)
{
if (reg <= MAX8907_REG_RTC_YEAR2)
return true;
switch (reg) {
case MAX8907_REG_RTC_STATUS:
case MAX8907_REG_RTC_IRQ:
return true;
default:
return false;
}
}
static bool max8907_rtc_is_precious_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX8907_REG_RTC_IRQ:
return true;
default:
return false;
}
}
static bool max8907_rtc_is_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX8907_REG_RTC_STATUS:
case MAX8907_REG_RTC_IRQ:
return false;
default:
return true;
}
}
static void max8907_power_off(void)
{
regmap_update_bits(max8907_pm_off->regmap_gen, MAX8907_REG_RESET_CNFG,
MAX8907_MASK_POWER_OFF, MAX8907_MASK_POWER_OFF);
}
static __devinit int max8907_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max8907 *max8907;
int ret;
struct max8907_platform_data *pdata = dev_get_platdata(&i2c->dev);
bool pm_off = false;
if (pdata)
pm_off = pdata->pm_off;
else if (i2c->dev.of_node)
pm_off = of_property_read_bool(i2c->dev.of_node,
"maxim,system-power-controller");
max8907 = devm_kzalloc(&i2c->dev, sizeof(struct max8907), GFP_KERNEL);
if (!max8907) {
ret = -ENOMEM;
goto err_alloc_drvdata;
}
max8907->dev = &i2c->dev;
dev_set_drvdata(max8907->dev, max8907);
max8907->i2c_gen = i2c;
i2c_set_clientdata(i2c, max8907);
max8907->regmap_gen = devm_regmap_init_i2c(i2c,
&max8907_regmap_gen_config);
if (IS_ERR(max8907->regmap_gen)) {
ret = PTR_ERR(max8907->regmap_gen);
dev_err(&i2c->dev, "gen regmap init failed: %d\n", ret);
goto err_regmap_gen;
}
max8907->i2c_rtc = i2c_new_dummy(i2c->adapter, MAX8907_RTC_I2C_ADDR);
if (!max8907->i2c_rtc) {
ret = -ENOMEM;
goto err_dummy_rtc;
}
i2c_set_clientdata(max8907->i2c_rtc, max8907);
max8907->regmap_rtc = devm_regmap_init_i2c(max8907->i2c_rtc,
&max8907_regmap_rtc_config);
if (IS_ERR(max8907->regmap_rtc)) {
ret = PTR_ERR(max8907->regmap_rtc);
dev_err(&i2c->dev, "rtc regmap init failed: %d\n", ret);
goto err_regmap_rtc;
}
irq_set_status_flags(max8907->i2c_gen->irq, IRQ_NOAUTOEN);
ret = regmap_add_irq_chip(max8907->regmap_gen, max8907->i2c_gen->irq,
IRQF_ONESHOT | IRQF_SHARED, -1,
&max8907_chg_irq_chip,
&max8907->irqc_chg);
if (ret != 0) {
dev_err(&i2c->dev, "failed to add chg irq chip: %d\n", ret);
goto err_irqc_chg;
}
ret = regmap_add_irq_chip(max8907->regmap_gen, max8907->i2c_gen->irq,
IRQF_ONESHOT | IRQF_SHARED, -1,
&max8907_on_off_irq_chip,
&max8907->irqc_on_off);
if (ret != 0) {
dev_err(&i2c->dev, "failed to add on off irq chip: %d\n", ret);
goto err_irqc_on_off;
}
ret = regmap_add_irq_chip(max8907->regmap_rtc, max8907->i2c_gen->irq,
IRQF_ONESHOT | IRQF_SHARED, -1,
&max8907_rtc_irq_chip,
&max8907->irqc_rtc);
if (ret != 0) {
dev_err(&i2c->dev, "failed to add rtc irq chip: %d\n", ret);
goto err_irqc_rtc;
}
enable_irq(max8907->i2c_gen->irq);
ret = mfd_add_devices(max8907->dev, -1, max8907_cells,
ARRAY_SIZE(max8907_cells), NULL, 0, NULL);
if (ret != 0) {
dev_err(&i2c->dev, "failed to add MFD devices %d\n", ret);
goto err_add_devices;
}
if (pm_off && !pm_power_off) {
max8907_pm_off = max8907;
pm_power_off = max8907_power_off;
}
return 0;
err_add_devices:
regmap_del_irq_chip(max8907->i2c_gen->irq, max8907->irqc_rtc);
err_irqc_rtc:
regmap_del_irq_chip(max8907->i2c_gen->irq, max8907->irqc_on_off);
err_irqc_on_off:
regmap_del_irq_chip(max8907->i2c_gen->irq, max8907->irqc_chg);
err_irqc_chg:
err_regmap_rtc:
i2c_unregister_device(max8907->i2c_rtc);
err_dummy_rtc:
err_regmap_gen:
err_alloc_drvdata:
return ret;
}
static __devexit int max8907_i2c_remove(struct i2c_client *i2c)
{
struct max8907 *max8907 = i2c_get_clientdata(i2c);
mfd_remove_devices(max8907->dev);
regmap_del_irq_chip(max8907->i2c_gen->irq, max8907->irqc_rtc);
regmap_del_irq_chip(max8907->i2c_gen->irq, max8907->irqc_on_off);
regmap_del_irq_chip(max8907->i2c_gen->irq, max8907->irqc_chg);
i2c_unregister_device(max8907->i2c_rtc);
return 0;
}
static int __init max8907_i2c_init(void)
{
int ret = -ENODEV;
ret = i2c_add_driver(&max8907_i2c_driver);
if (ret != 0)
pr_err("Failed to register I2C driver: %d\n", ret);
return ret;
}
static void __exit max8907_i2c_exit(void)
{
i2c_del_driver(&max8907_i2c_driver);
}
