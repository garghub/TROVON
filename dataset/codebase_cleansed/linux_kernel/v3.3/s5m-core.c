int s5m_reg_read(struct s5m87xx_dev *s5m87xx, u8 reg, void *dest)
{
return regmap_read(s5m87xx->regmap, reg, dest);
}
int s5m_bulk_read(struct s5m87xx_dev *s5m87xx, u8 reg, int count, u8 *buf)
{
return regmap_bulk_read(s5m87xx->regmap, reg, buf, count);;
}
int s5m_reg_write(struct s5m87xx_dev *s5m87xx, u8 reg, u8 value)
{
return regmap_write(s5m87xx->regmap, reg, value);
}
int s5m_bulk_write(struct s5m87xx_dev *s5m87xx, u8 reg, int count, u8 *buf)
{
return regmap_raw_write(s5m87xx->regmap, reg, buf, count * sizeof(u16));
}
int s5m_reg_update(struct s5m87xx_dev *s5m87xx, u8 reg, u8 val, u8 mask)
{
return regmap_update_bits(s5m87xx->regmap, reg, mask, val);
}
static int s5m87xx_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct s5m_platform_data *pdata = i2c->dev.platform_data;
struct s5m87xx_dev *s5m87xx;
int ret = 0;
int error;
s5m87xx = kzalloc(sizeof(struct s5m87xx_dev), GFP_KERNEL);
if (s5m87xx == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, s5m87xx);
s5m87xx->dev = &i2c->dev;
s5m87xx->i2c = i2c;
s5m87xx->irq = i2c->irq;
s5m87xx->type = id->driver_data;
if (pdata) {
s5m87xx->device_type = pdata->device_type;
s5m87xx->ono = pdata->ono;
s5m87xx->irq_base = pdata->irq_base;
s5m87xx->wakeup = pdata->wakeup;
}
s5m87xx->regmap = regmap_init_i2c(i2c, &s5m_regmap_config);
if (IS_ERR(s5m87xx->regmap)) {
error = PTR_ERR(s5m87xx->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
error);
goto err;
}
s5m87xx->rtc = i2c_new_dummy(i2c->adapter, RTC_I2C_ADDR);
i2c_set_clientdata(s5m87xx->rtc, s5m87xx);
if (pdata && pdata->cfg_pmic_irq)
pdata->cfg_pmic_irq();
s5m_irq_init(s5m87xx);
pm_runtime_set_active(s5m87xx->dev);
ret = mfd_add_devices(s5m87xx->dev, -1,
s5m87xx_devs, ARRAY_SIZE(s5m87xx_devs),
NULL, 0);
if (ret < 0)
goto err;
return ret;
err:
mfd_remove_devices(s5m87xx->dev);
s5m_irq_exit(s5m87xx);
i2c_unregister_device(s5m87xx->rtc);
regmap_exit(s5m87xx->regmap);
kfree(s5m87xx);
return ret;
}
static int s5m87xx_i2c_remove(struct i2c_client *i2c)
{
struct s5m87xx_dev *s5m87xx = i2c_get_clientdata(i2c);
mfd_remove_devices(s5m87xx->dev);
s5m_irq_exit(s5m87xx);
i2c_unregister_device(s5m87xx->rtc);
regmap_exit(s5m87xx->regmap);
kfree(s5m87xx);
return 0;
}
static int __init s5m87xx_i2c_init(void)
{
return i2c_add_driver(&s5m87xx_i2c_driver);
}
static void __exit s5m87xx_i2c_exit(void)
{
i2c_del_driver(&s5m87xx_i2c_driver);
}
