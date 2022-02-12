static int max77843_chg_init(struct max77843 *max77843)
{
int ret;
max77843->i2c_chg = i2c_new_dummy(max77843->i2c->adapter, I2C_ADDR_CHG);
if (!max77843->i2c_chg) {
dev_err(&max77843->i2c->dev,
"Cannot allocate I2C device for Charger\n");
return PTR_ERR(max77843->i2c_chg);
}
i2c_set_clientdata(max77843->i2c_chg, max77843);
max77843->regmap_chg = devm_regmap_init_i2c(max77843->i2c_chg,
&max77843_charger_regmap_config);
if (IS_ERR(max77843->regmap_chg)) {
ret = PTR_ERR(max77843->regmap_chg);
goto err_chg_i2c;
}
return 0;
err_chg_i2c:
i2c_unregister_device(max77843->i2c_chg);
return ret;
}
static int max77843_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max77843 *max77843;
unsigned int reg_data;
int ret;
max77843 = devm_kzalloc(&i2c->dev, sizeof(*max77843), GFP_KERNEL);
if (!max77843)
return -ENOMEM;
i2c_set_clientdata(i2c, max77843);
max77843->dev = &i2c->dev;
max77843->i2c = i2c;
max77843->irq = i2c->irq;
max77843->regmap = devm_regmap_init_i2c(i2c,
&max77843_regmap_config);
if (IS_ERR(max77843->regmap)) {
dev_err(&i2c->dev, "Failed to allocate topsys register map\n");
return PTR_ERR(max77843->regmap);
}
ret = regmap_add_irq_chip(max77843->regmap, max77843->irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT | IRQF_SHARED,
0, &max77843_irq_chip, &max77843->irq_data);
if (ret) {
dev_err(&i2c->dev, "Failed to add TOPSYS IRQ chip\n");
return ret;
}
ret = regmap_read(max77843->regmap,
MAX77843_SYS_REG_PMICID, &reg_data);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read PMIC ID\n");
goto err_pmic_id;
}
dev_info(&i2c->dev, "device ID: 0x%x\n", reg_data);
ret = max77843_chg_init(max77843);
if (ret) {
dev_err(&i2c->dev, "Failed to init Charger\n");
goto err_pmic_id;
}
ret = regmap_update_bits(max77843->regmap,
MAX77843_SYS_REG_INTSRCMASK,
MAX77843_INTSRC_MASK_MASK,
(unsigned int)~MAX77843_INTSRC_MASK_MASK);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to unmask interrupt source\n");
goto err_pmic_id;
}
ret = mfd_add_devices(max77843->dev, -1, max77843_devs,
ARRAY_SIZE(max77843_devs), NULL, 0, NULL);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to add mfd device\n");
goto err_pmic_id;
}
device_init_wakeup(max77843->dev, true);
return 0;
err_pmic_id:
regmap_del_irq_chip(max77843->irq, max77843->irq_data);
return ret;
}
static int max77843_remove(struct i2c_client *i2c)
{
struct max77843 *max77843 = i2c_get_clientdata(i2c);
mfd_remove_devices(max77843->dev);
regmap_del_irq_chip(max77843->irq, max77843->irq_data);
i2c_unregister_device(max77843->i2c_chg);
return 0;
}
static int __maybe_unused max77843_suspend(struct device *dev)
{
struct i2c_client *i2c = container_of(dev, struct i2c_client, dev);
struct max77843 *max77843 = i2c_get_clientdata(i2c);
disable_irq(max77843->irq);
if (device_may_wakeup(dev))
enable_irq_wake(max77843->irq);
return 0;
}
static int __maybe_unused max77843_resume(struct device *dev)
{
struct i2c_client *i2c = container_of(dev, struct i2c_client, dev);
struct max77843 *max77843 = i2c_get_clientdata(i2c);
if (device_may_wakeup(dev))
disable_irq_wake(max77843->irq);
enable_irq(max77843->irq);
return 0;
}
static int __init max77843_i2c_init(void)
{
return i2c_add_driver(&max77843_i2c_driver);
}
static void __exit max77843_i2c_exit(void)
{
i2c_del_driver(&max77843_i2c_driver);
}
