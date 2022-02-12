int max77693_read_reg(struct regmap *map, u8 reg, u8 *dest)
{
unsigned int val;
int ret;
ret = regmap_read(map, reg, &val);
*dest = val;
return ret;
}
int max77693_bulk_read(struct regmap *map, u8 reg, int count, u8 *buf)
{
int ret;
ret = regmap_bulk_read(map, reg, buf, count);
return ret;
}
int max77693_write_reg(struct regmap *map, u8 reg, u8 value)
{
int ret;
ret = regmap_write(map, reg, value);
return ret;
}
int max77693_bulk_write(struct regmap *map, u8 reg, int count, u8 *buf)
{
int ret;
ret = regmap_bulk_write(map, reg, buf, count);
return ret;
}
int max77693_update_reg(struct regmap *map, u8 reg, u8 val, u8 mask)
{
int ret;
ret = regmap_update_bits(map, reg, mask, val);
return ret;
}
static int max77693_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max77693_dev *max77693;
struct max77693_platform_data *pdata = i2c->dev.platform_data;
u8 reg_data;
int ret = 0;
max77693 = devm_kzalloc(&i2c->dev,
sizeof(struct max77693_dev), GFP_KERNEL);
if (max77693 == NULL)
return -ENOMEM;
max77693->regmap = devm_regmap_init_i2c(i2c, &max77693_regmap_config);
if (IS_ERR(max77693->regmap)) {
ret = PTR_ERR(max77693->regmap);
dev_err(max77693->dev,"failed to allocate register map: %d\n",
ret);
goto err_regmap;
}
i2c_set_clientdata(i2c, max77693);
max77693->dev = &i2c->dev;
max77693->i2c = i2c;
max77693->irq = i2c->irq;
max77693->type = id->driver_data;
if (!pdata)
goto err_regmap;
max77693->wakeup = pdata->wakeup;
if (max77693_read_reg(max77693->regmap,
MAX77693_PMIC_REG_PMIC_ID2, &reg_data) < 0) {
dev_err(max77693->dev, "device not found on this channel\n");
ret = -ENODEV;
goto err_regmap;
} else
dev_info(max77693->dev, "device ID: 0x%x\n", reg_data);
max77693->muic = i2c_new_dummy(i2c->adapter, I2C_ADDR_MUIC);
i2c_set_clientdata(max77693->muic, max77693);
max77693->haptic = i2c_new_dummy(i2c->adapter, I2C_ADDR_HAPTIC);
i2c_set_clientdata(max77693->haptic, max77693);
max77693->regmap_muic = devm_regmap_init_i2c(max77693->muic,
&max77693_regmap_config);
if (IS_ERR(max77693->regmap_muic)) {
ret = PTR_ERR(max77693->regmap_muic);
dev_err(max77693->dev,
"failed to allocate register map: %d\n", ret);
goto err_regmap;
}
ret = max77693_irq_init(max77693);
if (ret < 0)
goto err_irq;
pm_runtime_set_active(max77693->dev);
ret = mfd_add_devices(max77693->dev, -1, max77693_devs,
ARRAY_SIZE(max77693_devs), NULL, 0, NULL);
if (ret < 0)
goto err_mfd;
device_init_wakeup(max77693->dev, pdata->wakeup);
return ret;
err_mfd:
max77693_irq_exit(max77693);
err_irq:
i2c_unregister_device(max77693->muic);
i2c_unregister_device(max77693->haptic);
err_regmap:
return ret;
}
static int max77693_i2c_remove(struct i2c_client *i2c)
{
struct max77693_dev *max77693 = i2c_get_clientdata(i2c);
mfd_remove_devices(max77693->dev);
max77693_irq_exit(max77693);
i2c_unregister_device(max77693->muic);
i2c_unregister_device(max77693->haptic);
return 0;
}
static int max77693_suspend(struct device *dev)
{
struct i2c_client *i2c = container_of(dev, struct i2c_client, dev);
struct max77693_dev *max77693 = i2c_get_clientdata(i2c);
if (device_may_wakeup(dev))
irq_set_irq_wake(max77693->irq, 1);
return 0;
}
static int max77693_resume(struct device *dev)
{
struct i2c_client *i2c = container_of(dev, struct i2c_client, dev);
struct max77693_dev *max77693 = i2c_get_clientdata(i2c);
if (device_may_wakeup(dev))
irq_set_irq_wake(max77693->irq, 0);
return max77693_irq_resume(max77693);
}
static int __init max77693_i2c_init(void)
{
return i2c_add_driver(&max77693_i2c_driver);
}
static void __exit max77693_i2c_exit(void)
{
i2c_del_driver(&max77693_i2c_driver);
}
