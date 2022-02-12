static int max77693_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max77693_dev *max77693;
unsigned int reg_data;
int ret = 0;
max77693 = devm_kzalloc(&i2c->dev,
sizeof(struct max77693_dev), GFP_KERNEL);
if (max77693 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, max77693);
max77693->dev = &i2c->dev;
max77693->i2c = i2c;
max77693->irq = i2c->irq;
max77693->type = id->driver_data;
max77693->regmap = devm_regmap_init_i2c(i2c, &max77693_regmap_config);
if (IS_ERR(max77693->regmap)) {
ret = PTR_ERR(max77693->regmap);
dev_err(max77693->dev, "failed to allocate register map: %d\n",
ret);
return ret;
}
ret = regmap_read(max77693->regmap, MAX77693_PMIC_REG_PMIC_ID2,
&reg_data);
if (ret < 0) {
dev_err(max77693->dev, "device not found on this channel\n");
return ret;
} else
dev_info(max77693->dev, "device ID: 0x%x\n", reg_data);
max77693->i2c_muic = i2c_new_dummy(i2c->adapter, I2C_ADDR_MUIC);
if (!max77693->i2c_muic) {
dev_err(max77693->dev, "Failed to allocate I2C device for MUIC\n");
return -ENODEV;
}
i2c_set_clientdata(max77693->i2c_muic, max77693);
max77693->i2c_haptic = i2c_new_dummy(i2c->adapter, I2C_ADDR_HAPTIC);
if (!max77693->i2c_haptic) {
dev_err(max77693->dev, "Failed to allocate I2C device for Haptic\n");
ret = -ENODEV;
goto err_i2c_haptic;
}
i2c_set_clientdata(max77693->i2c_haptic, max77693);
max77693->regmap_haptic = devm_regmap_init_i2c(max77693->i2c_haptic,
&max77693_regmap_haptic_config);
if (IS_ERR(max77693->regmap_haptic)) {
ret = PTR_ERR(max77693->regmap_haptic);
dev_err(max77693->dev,
"failed to initialize haptic register map: %d\n", ret);
goto err_regmap;
}
max77693->regmap_muic = devm_regmap_init_i2c(max77693->i2c_muic,
&max77693_regmap_muic_config);
if (IS_ERR(max77693->regmap_muic)) {
ret = PTR_ERR(max77693->regmap_muic);
dev_err(max77693->dev,
"failed to allocate register map: %d\n", ret);
goto err_regmap;
}
ret = regmap_add_irq_chip(max77693->regmap, max77693->irq,
IRQF_ONESHOT | IRQF_SHARED |
IRQF_TRIGGER_FALLING, 0,
&max77693_led_irq_chip,
&max77693->irq_data_led);
if (ret) {
dev_err(max77693->dev, "failed to add irq chip: %d\n", ret);
goto err_regmap;
}
ret = regmap_add_irq_chip(max77693->regmap, max77693->irq,
IRQF_ONESHOT | IRQF_SHARED |
IRQF_TRIGGER_FALLING, 0,
&max77693_topsys_irq_chip,
&max77693->irq_data_topsys);
if (ret) {
dev_err(max77693->dev, "failed to add irq chip: %d\n", ret);
goto err_irq_topsys;
}
ret = regmap_add_irq_chip(max77693->regmap, max77693->irq,
IRQF_ONESHOT | IRQF_SHARED |
IRQF_TRIGGER_FALLING, 0,
&max77693_charger_irq_chip,
&max77693->irq_data_chg);
if (ret) {
dev_err(max77693->dev, "failed to add irq chip: %d\n", ret);
goto err_irq_charger;
}
ret = regmap_add_irq_chip(max77693->regmap_muic, max77693->irq,
IRQF_ONESHOT | IRQF_SHARED |
IRQF_TRIGGER_FALLING, 0,
&max77693_muic_irq_chip,
&max77693->irq_data_muic);
if (ret) {
dev_err(max77693->dev, "failed to add irq chip: %d\n", ret);
goto err_irq_muic;
}
ret = regmap_update_bits(max77693->regmap,
MAX77693_PMIC_REG_INTSRC_MASK,
SRC_IRQ_ALL, (unsigned int)~SRC_IRQ_ALL);
if (ret < 0) {
dev_err(max77693->dev,
"Could not unmask interrupts in INTSRC: %d\n",
ret);
goto err_intsrc;
}
pm_runtime_set_active(max77693->dev);
ret = mfd_add_devices(max77693->dev, -1, max77693_devs,
ARRAY_SIZE(max77693_devs), NULL, 0, NULL);
if (ret < 0)
goto err_mfd;
return ret;
err_mfd:
mfd_remove_devices(max77693->dev);
err_intsrc:
regmap_del_irq_chip(max77693->irq, max77693->irq_data_muic);
err_irq_muic:
regmap_del_irq_chip(max77693->irq, max77693->irq_data_chg);
err_irq_charger:
regmap_del_irq_chip(max77693->irq, max77693->irq_data_topsys);
err_irq_topsys:
regmap_del_irq_chip(max77693->irq, max77693->irq_data_led);
err_regmap:
i2c_unregister_device(max77693->i2c_haptic);
err_i2c_haptic:
i2c_unregister_device(max77693->i2c_muic);
return ret;
}
static int max77693_i2c_remove(struct i2c_client *i2c)
{
struct max77693_dev *max77693 = i2c_get_clientdata(i2c);
mfd_remove_devices(max77693->dev);
regmap_del_irq_chip(max77693->irq, max77693->irq_data_muic);
regmap_del_irq_chip(max77693->irq, max77693->irq_data_chg);
regmap_del_irq_chip(max77693->irq, max77693->irq_data_topsys);
regmap_del_irq_chip(max77693->irq, max77693->irq_data_led);
i2c_unregister_device(max77693->i2c_muic);
i2c_unregister_device(max77693->i2c_haptic);
return 0;
}
static int max77693_suspend(struct device *dev)
{
struct i2c_client *i2c = to_i2c_client(dev);
struct max77693_dev *max77693 = i2c_get_clientdata(i2c);
if (device_may_wakeup(dev)) {
enable_irq_wake(max77693->irq);
disable_irq(max77693->irq);
}
return 0;
}
static int max77693_resume(struct device *dev)
{
struct i2c_client *i2c = to_i2c_client(dev);
struct max77693_dev *max77693 = i2c_get_clientdata(i2c);
if (device_may_wakeup(dev)) {
disable_irq_wake(max77693->irq);
enable_irq(max77693->irq);
}
return 0;
}
