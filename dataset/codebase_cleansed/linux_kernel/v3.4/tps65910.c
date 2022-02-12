static int tps65910_i2c_read(struct tps65910 *tps65910, u8 reg,
int bytes, void *dest)
{
return regmap_bulk_read(tps65910->regmap, reg, dest, bytes);
}
static int tps65910_i2c_write(struct tps65910 *tps65910, u8 reg,
int bytes, void *src)
{
return regmap_bulk_write(tps65910->regmap, reg, src, bytes);
}
int tps65910_set_bits(struct tps65910 *tps65910, u8 reg, u8 mask)
{
return regmap_update_bits(tps65910->regmap, reg, mask, mask);
}
int tps65910_clear_bits(struct tps65910 *tps65910, u8 reg, u8 mask)
{
return regmap_update_bits(tps65910->regmap, reg, mask, 0);
}
static bool is_volatile_reg(struct device *dev, unsigned int reg)
{
struct tps65910 *tps65910 = dev_get_drvdata(dev);
if ((reg >= TPS65910_VIO) && (reg <= TPS65910_VDAC)) {
if (tps65910_chip_id(tps65910) == TPS65910)
if ((reg == TPS65911_VDDCTRL_OP) ||
(reg == TPS65911_VDDCTRL_SR))
return true;
return false;
}
return true;
}
static int tps65910_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct tps65910 *tps65910;
struct tps65910_board *pmic_plat_data;
struct tps65910_platform_data *init_data;
int ret = 0;
pmic_plat_data = dev_get_platdata(&i2c->dev);
if (!pmic_plat_data)
return -EINVAL;
init_data = kzalloc(sizeof(struct tps65910_platform_data), GFP_KERNEL);
if (init_data == NULL)
return -ENOMEM;
tps65910 = kzalloc(sizeof(struct tps65910), GFP_KERNEL);
if (tps65910 == NULL) {
kfree(init_data);
return -ENOMEM;
}
i2c_set_clientdata(i2c, tps65910);
tps65910->dev = &i2c->dev;
tps65910->i2c_client = i2c;
tps65910->id = id->driver_data;
tps65910->read = tps65910_i2c_read;
tps65910->write = tps65910_i2c_write;
mutex_init(&tps65910->io_mutex);
tps65910->regmap = regmap_init_i2c(i2c, &tps65910_regmap_config);
if (IS_ERR(tps65910->regmap)) {
ret = PTR_ERR(tps65910->regmap);
dev_err(&i2c->dev, "regmap initialization failed: %d\n", ret);
goto regmap_err;
}
ret = mfd_add_devices(tps65910->dev, -1,
tps65910s, ARRAY_SIZE(tps65910s),
NULL, 0);
if (ret < 0)
goto err;
init_data->irq = pmic_plat_data->irq;
init_data->irq_base = pmic_plat_data->irq_base;
tps65910_gpio_init(tps65910, pmic_plat_data->gpio_base);
tps65910_irq_init(tps65910, init_data->irq, init_data);
kfree(init_data);
return ret;
err:
regmap_exit(tps65910->regmap);
regmap_err:
kfree(tps65910);
kfree(init_data);
return ret;
}
static int tps65910_i2c_remove(struct i2c_client *i2c)
{
struct tps65910 *tps65910 = i2c_get_clientdata(i2c);
tps65910_irq_exit(tps65910);
mfd_remove_devices(tps65910->dev);
regmap_exit(tps65910->regmap);
kfree(tps65910);
return 0;
}
static int __init tps65910_i2c_init(void)
{
return i2c_add_driver(&tps65910_i2c_driver);
}
static void __exit tps65910_i2c_exit(void)
{
i2c_del_driver(&tps65910_i2c_driver);
}
