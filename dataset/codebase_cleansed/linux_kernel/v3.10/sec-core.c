int sec_reg_read(struct sec_pmic_dev *sec_pmic, u8 reg, void *dest)
{
return regmap_read(sec_pmic->regmap, reg, dest);
}
int sec_bulk_read(struct sec_pmic_dev *sec_pmic, u8 reg, int count, u8 *buf)
{
return regmap_bulk_read(sec_pmic->regmap, reg, buf, count);
}
int sec_reg_write(struct sec_pmic_dev *sec_pmic, u8 reg, u8 value)
{
return regmap_write(sec_pmic->regmap, reg, value);
}
int sec_bulk_write(struct sec_pmic_dev *sec_pmic, u8 reg, int count, u8 *buf)
{
return regmap_raw_write(sec_pmic->regmap, reg, buf, count);
}
int sec_reg_update(struct sec_pmic_dev *sec_pmic, u8 reg, u8 val, u8 mask)
{
return regmap_update_bits(sec_pmic->regmap, reg, mask, val);
}
static struct sec_platform_data *sec_pmic_i2c_parse_dt_pdata(
struct device *dev)
{
struct sec_platform_data *pd;
pd = devm_kzalloc(dev, sizeof(*pd), GFP_KERNEL);
if (!pd) {
dev_err(dev, "could not allocate memory for pdata\n");
return ERR_PTR(-ENOMEM);
}
return pd;
}
static struct sec_platform_data *sec_pmic_i2c_parse_dt_pdata(
struct device *dev)
{
return 0;
}
static inline int sec_i2c_get_driver_data(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
#ifdef CONFIG_OF
if (i2c->dev.of_node) {
const struct of_device_id *match;
match = of_match_node(sec_dt_match, i2c->dev.of_node);
return (int)match->data;
}
#endif
return (int)id->driver_data;
}
static int sec_pmic_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct sec_platform_data *pdata = i2c->dev.platform_data;
struct sec_pmic_dev *sec_pmic;
int ret;
sec_pmic = devm_kzalloc(&i2c->dev, sizeof(struct sec_pmic_dev),
GFP_KERNEL);
if (sec_pmic == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, sec_pmic);
sec_pmic->dev = &i2c->dev;
sec_pmic->i2c = i2c;
sec_pmic->irq = i2c->irq;
sec_pmic->type = sec_i2c_get_driver_data(i2c, id);
if (sec_pmic->dev->of_node) {
pdata = sec_pmic_i2c_parse_dt_pdata(sec_pmic->dev);
if (IS_ERR(pdata)) {
ret = PTR_ERR(pdata);
return ret;
}
pdata->device_type = sec_pmic->type;
}
if (pdata) {
sec_pmic->device_type = pdata->device_type;
sec_pmic->ono = pdata->ono;
sec_pmic->irq_base = pdata->irq_base;
sec_pmic->wakeup = pdata->wakeup;
sec_pmic->pdata = pdata;
}
sec_pmic->regmap = devm_regmap_init_i2c(i2c, &sec_regmap_config);
if (IS_ERR(sec_pmic->regmap)) {
ret = PTR_ERR(sec_pmic->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
sec_pmic->rtc = i2c_new_dummy(i2c->adapter, RTC_I2C_ADDR);
i2c_set_clientdata(sec_pmic->rtc, sec_pmic);
if (pdata && pdata->cfg_pmic_irq)
pdata->cfg_pmic_irq();
sec_irq_init(sec_pmic);
pm_runtime_set_active(sec_pmic->dev);
switch (sec_pmic->device_type) {
case S5M8751X:
ret = mfd_add_devices(sec_pmic->dev, -1, s5m8751_devs,
ARRAY_SIZE(s5m8751_devs), NULL, 0, NULL);
break;
case S5M8763X:
ret = mfd_add_devices(sec_pmic->dev, -1, s5m8763_devs,
ARRAY_SIZE(s5m8763_devs), NULL, 0, NULL);
break;
case S5M8767X:
ret = mfd_add_devices(sec_pmic->dev, -1, s5m8767_devs,
ARRAY_SIZE(s5m8767_devs), NULL, 0, NULL);
break;
case S2MPS11X:
ret = mfd_add_devices(sec_pmic->dev, -1, s2mps11_devs,
ARRAY_SIZE(s2mps11_devs), NULL, 0, NULL);
break;
default:
BUG();
}
if (ret < 0)
goto err;
return ret;
err:
mfd_remove_devices(sec_pmic->dev);
sec_irq_exit(sec_pmic);
i2c_unregister_device(sec_pmic->rtc);
return ret;
}
static int sec_pmic_remove(struct i2c_client *i2c)
{
struct sec_pmic_dev *sec_pmic = i2c_get_clientdata(i2c);
mfd_remove_devices(sec_pmic->dev);
sec_irq_exit(sec_pmic);
i2c_unregister_device(sec_pmic->rtc);
return 0;
}
static int __init sec_pmic_init(void)
{
return i2c_add_driver(&sec_pmic_driver);
}
static void __exit sec_pmic_exit(void)
{
i2c_del_driver(&sec_pmic_driver);
}
