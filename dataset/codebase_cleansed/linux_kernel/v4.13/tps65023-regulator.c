static int tps65023_dcdc_get_voltage_sel(struct regulator_dev *dev)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int dcdc = rdev_get_id(dev);
if (dcdc < TPS65023_DCDC_1 || dcdc > TPS65023_DCDC_3)
return -EINVAL;
if (dcdc != tps->driver_data->core_regulator)
return 0;
return regulator_get_voltage_sel_regmap(dev);
}
static int tps65023_dcdc_set_voltage_sel(struct regulator_dev *dev,
unsigned selector)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int dcdc = rdev_get_id(dev);
if (dcdc != tps->driver_data->core_regulator)
return -EINVAL;
return regulator_set_voltage_sel_regmap(dev, selector);
}
static int tps_65023_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regulator_init_data *init_data = dev_get_platdata(&client->dev);
struct regulator_config config = { };
struct tps_pmic *tps;
int i;
int error;
tps = devm_kzalloc(&client->dev, sizeof(*tps), GFP_KERNEL);
if (!tps)
return -ENOMEM;
tps->driver_data = (struct tps_driver_data *)id->driver_data;
tps->regmap = devm_regmap_init_i2c(client, &tps65023_regmap_config);
if (IS_ERR(tps->regmap)) {
error = PTR_ERR(tps->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
error);
return error;
}
config.dev = &client->dev;
config.driver_data = tps;
config.regmap = tps->regmap;
for (i = 0; i < TPS65023_NUM_REGULATOR; i++) {
if (init_data)
config.init_data = &init_data[i];
tps->rdev[i] = devm_regulator_register(&client->dev,
&tps->driver_data->desc[i], &config);
if (IS_ERR(tps->rdev[i])) {
dev_err(&client->dev, "failed to register %s\n",
id->name);
return PTR_ERR(tps->rdev[i]);
}
}
i2c_set_clientdata(client, tps);
regmap_update_bits(tps->regmap, TPS65023_REG_CON_CTRL2,
TPS65023_REG_CTRL2_CORE_ADJ, 0);
return 0;
}
static int __init tps_65023_init(void)
{
return i2c_add_driver(&tps_65023_i2c_driver);
}
static void __exit tps_65023_cleanup(void)
{
i2c_del_driver(&tps_65023_i2c_driver);
}
