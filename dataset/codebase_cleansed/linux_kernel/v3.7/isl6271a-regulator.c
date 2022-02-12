static int isl6271a_get_voltage_sel(struct regulator_dev *dev)
{
struct isl_pmic *pmic = rdev_get_drvdata(dev);
int idx;
mutex_lock(&pmic->mtx);
idx = i2c_smbus_read_byte(pmic->client);
if (idx < 0)
dev_err(&pmic->client->dev, "Error getting voltage\n");
mutex_unlock(&pmic->mtx);
return idx;
}
static int isl6271a_set_voltage_sel(struct regulator_dev *dev,
unsigned selector)
{
struct isl_pmic *pmic = rdev_get_drvdata(dev);
int err;
mutex_lock(&pmic->mtx);
err = i2c_smbus_write_byte(pmic->client, selector);
if (err < 0)
dev_err(&pmic->client->dev, "Error setting voltage\n");
mutex_unlock(&pmic->mtx);
return err;
}
static int __devinit isl6271a_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct regulator_config config = { };
struct regulator_init_data *init_data = i2c->dev.platform_data;
struct isl_pmic *pmic;
int err, i;
if (!i2c_check_functionality(i2c->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
pmic = devm_kzalloc(&i2c->dev, sizeof(struct isl_pmic), GFP_KERNEL);
if (!pmic)
return -ENOMEM;
pmic->client = i2c;
mutex_init(&pmic->mtx);
for (i = 0; i < 3; i++) {
config.dev = &i2c->dev;
if (i == 0)
config.init_data = init_data;
else
config.init_data = 0;
config.driver_data = pmic;
pmic->rdev[i] = regulator_register(&isl_rd[i], &config);
if (IS_ERR(pmic->rdev[i])) {
dev_err(&i2c->dev, "failed to register %s\n", id->name);
err = PTR_ERR(pmic->rdev[i]);
goto error;
}
}
i2c_set_clientdata(i2c, pmic);
return 0;
error:
while (--i >= 0)
regulator_unregister(pmic->rdev[i]);
return err;
}
static int __devexit isl6271a_remove(struct i2c_client *i2c)
{
struct isl_pmic *pmic = i2c_get_clientdata(i2c);
int i;
for (i = 0; i < 3; i++)
regulator_unregister(pmic->rdev[i]);
return 0;
}
static int __init isl6271a_init(void)
{
return i2c_add_driver(&isl6271a_i2c_driver);
}
static void __exit isl6271a_cleanup(void)
{
i2c_del_driver(&isl6271a_i2c_driver);
}
