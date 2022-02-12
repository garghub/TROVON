static int tps65023_dcdc_get_voltage_sel(struct regulator_dev *dev)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int dcdc = rdev_get_id(dev);
if (dcdc < TPS65023_DCDC_1 || dcdc > TPS65023_DCDC_3)
return -EINVAL;
if (dcdc != tps->core_regulator)
return 0;
return regulator_get_voltage_sel_regmap(dev);
}
static int tps65023_dcdc_set_voltage_sel(struct regulator_dev *dev,
unsigned selector)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int dcdc = rdev_get_id(dev);
if (dcdc != tps->core_regulator)
return -EINVAL;
return regulator_set_voltage_sel_regmap(dev, selector);
}
static int tps_65023_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct tps_driver_data *drv_data = (void *)id->driver_data;
const struct tps_info *info = drv_data->info;
struct regulator_config config = { };
struct regulator_init_data *init_data;
struct regulator_dev *rdev;
struct tps_pmic *tps;
int i;
int error;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
init_data = dev_get_platdata(&client->dev);
if (!init_data)
return -EIO;
tps = devm_kzalloc(&client->dev, sizeof(*tps), GFP_KERNEL);
if (!tps)
return -ENOMEM;
tps->regmap = devm_regmap_init_i2c(client, &tps65023_regmap_config);
if (IS_ERR(tps->regmap)) {
error = PTR_ERR(tps->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
error);
return error;
}
tps->core_regulator = drv_data->core_regulator;
for (i = 0; i < TPS65023_NUM_REGULATOR; i++, info++, init_data++) {
tps->info[i] = info;
tps->desc[i].name = info->name;
tps->desc[i].id = i;
tps->desc[i].n_voltages = info->table_len;
tps->desc[i].volt_table = info->table;
tps->desc[i].ops = (i > TPS65023_DCDC_3 ?
&tps65023_ldo_ops : &tps65023_dcdc_ops);
tps->desc[i].type = REGULATOR_VOLTAGE;
tps->desc[i].owner = THIS_MODULE;
tps->desc[i].enable_reg = TPS65023_REG_REG_CTRL;
switch (i) {
case TPS65023_LDO_1:
tps->desc[i].vsel_reg = TPS65023_REG_LDO_CTRL;
tps->desc[i].vsel_mask = 0x07;
tps->desc[i].enable_mask = 1 << 1;
break;
case TPS65023_LDO_2:
tps->desc[i].vsel_reg = TPS65023_REG_LDO_CTRL;
tps->desc[i].vsel_mask = 0x70;
tps->desc[i].enable_mask = 1 << 2;
break;
default:
tps->desc[i].enable_mask =
1 << (TPS65023_NUM_REGULATOR - i);
tps->desc[i].vsel_reg = TPS65023_REG_DEF_CORE;
tps->desc[i].vsel_mask = info->table_len - 1;
tps->desc[i].apply_reg = TPS65023_REG_CON_CTRL2;
tps->desc[i].apply_bit = TPS65023_REG_CTRL2_GO;
}
config.dev = &client->dev;
config.init_data = init_data;
config.driver_data = tps;
config.regmap = tps->regmap;
rdev = regulator_register(&tps->desc[i], &config);
if (IS_ERR(rdev)) {
dev_err(&client->dev, "failed to register %s\n",
id->name);
error = PTR_ERR(rdev);
goto fail;
}
tps->rdev[i] = rdev;
}
i2c_set_clientdata(client, tps);
regmap_update_bits(tps->regmap, TPS65023_REG_CON_CTRL2,
TPS65023_REG_CTRL2_CORE_ADJ, TPS65023_REG_CTRL2_CORE_ADJ);
return 0;
fail:
while (--i >= 0)
regulator_unregister(tps->rdev[i]);
return error;
}
static int tps_65023_remove(struct i2c_client *client)
{
struct tps_pmic *tps = i2c_get_clientdata(client);
int i;
for (i = 0; i < TPS65023_NUM_REGULATOR; i++)
regulator_unregister(tps->rdev[i]);
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
