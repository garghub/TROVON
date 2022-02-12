static int fan53555_set_suspend_voltage(struct regulator_dev *rdev, int uV)
{
struct fan53555_device_info *di = rdev_get_drvdata(rdev);
int ret;
if (di->sleep_vol_cache == uV)
return 0;
ret = regulator_map_voltage_linear(rdev, uV, uV);
if (ret < 0)
return -EINVAL;
ret = regmap_update_bits(di->regmap, di->sleep_reg,
VSEL_NSEL_MASK, ret);
if (ret < 0)
return -EINVAL;
di->sleep_vol_cache = uV;
return 0;
}
static int fan53555_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
struct fan53555_device_info *di = rdev_get_drvdata(rdev);
switch (mode) {
case REGULATOR_MODE_FAST:
regmap_update_bits(di->regmap, di->vol_reg,
VSEL_MODE, VSEL_MODE);
break;
case REGULATOR_MODE_NORMAL:
regmap_update_bits(di->regmap, di->vol_reg, VSEL_MODE, 0);
break;
default:
return -EINVAL;
}
return 0;
}
static unsigned int fan53555_get_mode(struct regulator_dev *rdev)
{
struct fan53555_device_info *di = rdev_get_drvdata(rdev);
unsigned int val;
int ret = 0;
ret = regmap_read(di->regmap, di->vol_reg, &val);
if (ret < 0)
return ret;
if (val & VSEL_MODE)
return REGULATOR_MODE_FAST;
else
return REGULATOR_MODE_NORMAL;
}
static int fan53555_device_setup(struct fan53555_device_info *di,
struct fan53555_platform_data *pdata)
{
unsigned int reg, data, mask;
switch (pdata->sleep_vsel_id) {
case FAN53555_VSEL_ID_0:
di->sleep_reg = FAN53555_VSEL0;
di->vol_reg = FAN53555_VSEL1;
break;
case FAN53555_VSEL_ID_1:
di->sleep_reg = FAN53555_VSEL1;
di->vol_reg = FAN53555_VSEL0;
break;
default:
dev_err(di->dev, "Invalid VSEL ID!\n");
return -EINVAL;
}
switch (di->chip_id) {
case FAN53555_CHIP_ID_00:
case FAN53555_CHIP_ID_01:
case FAN53555_CHIP_ID_03:
case FAN53555_CHIP_ID_05:
di->vsel_min = 600000;
di->vsel_step = 10000;
break;
case FAN53555_CHIP_ID_04:
di->vsel_min = 603000;
di->vsel_step = 12826;
break;
default:
dev_err(di->dev,
"Chip ID[%d]\n not supported!\n", di->chip_id);
return -EINVAL;
}
if (pdata->slew_rate & 0x7)
di->slew_rate = pdata->slew_rate;
else
di->slew_rate = FAN53555_SLEW_RATE_64MV;
reg = FAN53555_CONTROL;
data = di->slew_rate << CTL_SLEW_SHIFT;
mask = CTL_SLEW_MASK;
return regmap_update_bits(di->regmap, reg, mask, data);
}
static int fan53555_regulator_register(struct fan53555_device_info *di,
struct regulator_config *config)
{
struct regulator_desc *rdesc = &di->desc;
rdesc->name = "fan53555-reg";
rdesc->ops = &fan53555_regulator_ops;
rdesc->type = REGULATOR_VOLTAGE;
rdesc->n_voltages = FAN53555_NVOLTAGES;
rdesc->enable_reg = di->vol_reg;
rdesc->enable_mask = VSEL_BUCK_EN;
rdesc->min_uV = di->vsel_min;
rdesc->uV_step = di->vsel_step;
rdesc->vsel_reg = di->vol_reg;
rdesc->vsel_mask = VSEL_NSEL_MASK;
rdesc->owner = THIS_MODULE;
di->rdev = regulator_register(&di->desc, config);
return PTR_ERR_OR_ZERO(di->rdev);
}
static int fan53555_regulator_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct fan53555_device_info *di;
struct fan53555_platform_data *pdata;
struct regulator_config config = { };
unsigned int val;
int ret;
pdata = dev_get_platdata(&client->dev);
if (!pdata || !pdata->regulator) {
dev_err(&client->dev, "Platform data not found!\n");
return -ENODEV;
}
di = devm_kzalloc(&client->dev, sizeof(struct fan53555_device_info),
GFP_KERNEL);
if (!di) {
dev_err(&client->dev, "Failed to allocate device info data!\n");
return -ENOMEM;
}
di->regmap = devm_regmap_init_i2c(client, &fan53555_regmap_config);
if (IS_ERR(di->regmap)) {
dev_err(&client->dev, "Failed to allocate regmap!\n");
return PTR_ERR(di->regmap);
}
di->dev = &client->dev;
di->regulator = pdata->regulator;
i2c_set_clientdata(client, di);
ret = regmap_read(di->regmap, FAN53555_ID1, &val);
if (ret < 0) {
dev_err(&client->dev, "Failed to get chip ID!\n");
return -ENODEV;
}
di->chip_id = val & DIE_ID;
ret = regmap_read(di->regmap, FAN53555_ID2, &val);
if (ret < 0) {
dev_err(&client->dev, "Failed to get chip Rev!\n");
return -ENODEV;
}
di->chip_rev = val & DIE_REV;
dev_info(&client->dev, "FAN53555 Option[%d] Rev[%d] Detected!\n",
di->chip_id, di->chip_rev);
ret = fan53555_device_setup(di, pdata);
if (ret < 0) {
dev_err(&client->dev, "Failed to setup device!\n");
return ret;
}
config.dev = di->dev;
config.init_data = di->regulator;
config.regmap = di->regmap;
config.driver_data = di;
ret = fan53555_regulator_register(di, &config);
if (ret < 0)
dev_err(&client->dev, "Failed to register regulator!\n");
return ret;
}
static int fan53555_regulator_remove(struct i2c_client *client)
{
struct fan53555_device_info *di = i2c_get_clientdata(client);
regulator_unregister(di->rdev);
return 0;
}
