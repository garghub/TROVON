static int max8649_enable_time(struct regulator_dev *rdev)
{
struct max8649_regulator_info *info = rdev_get_drvdata(rdev);
int voltage, rate, ret;
unsigned int val;
ret = regmap_read(info->regmap, rdev->desc->vsel_reg, &val);
if (ret != 0)
return ret;
val &= MAX8649_VOL_MASK;
voltage = regulator_list_voltage_linear(rdev, (unsigned char)val);
ret = regmap_read(info->regmap, MAX8649_RAMP, &val);
if (ret != 0)
return ret;
ret = (val & MAX8649_RAMP_MASK) >> 5;
rate = (32 * 1000) >> ret;
return DIV_ROUND_UP(voltage, rate);
}
static int max8649_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
struct max8649_regulator_info *info = rdev_get_drvdata(rdev);
switch (mode) {
case REGULATOR_MODE_FAST:
regmap_update_bits(info->regmap, rdev->desc->vsel_reg,
MAX8649_FORCE_PWM, MAX8649_FORCE_PWM);
break;
case REGULATOR_MODE_NORMAL:
regmap_update_bits(info->regmap, rdev->desc->vsel_reg,
MAX8649_FORCE_PWM, 0);
break;
default:
return -EINVAL;
}
return 0;
}
static unsigned int max8649_get_mode(struct regulator_dev *rdev)
{
struct max8649_regulator_info *info = rdev_get_drvdata(rdev);
unsigned int val;
int ret;
ret = regmap_read(info->regmap, rdev->desc->vsel_reg, &val);
if (ret != 0)
return ret;
if (val & MAX8649_FORCE_PWM)
return REGULATOR_MODE_FAST;
return REGULATOR_MODE_NORMAL;
}
static int max8649_regulator_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max8649_platform_data *pdata = dev_get_platdata(&client->dev);
struct max8649_regulator_info *info = NULL;
struct regulator_config config = { };
unsigned int val;
unsigned char data;
int ret;
info = devm_kzalloc(&client->dev, sizeof(struct max8649_regulator_info),
GFP_KERNEL);
if (!info) {
dev_err(&client->dev, "No enough memory\n");
return -ENOMEM;
}
info->regmap = devm_regmap_init_i2c(client, &max8649_regmap_config);
if (IS_ERR(info->regmap)) {
ret = PTR_ERR(info->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n", ret);
return ret;
}
info->dev = &client->dev;
i2c_set_clientdata(client, info);
info->mode = pdata->mode;
switch (info->mode) {
case 0:
dcdc_desc.vsel_reg = MAX8649_MODE0;
break;
case 1:
dcdc_desc.vsel_reg = MAX8649_MODE1;
break;
case 2:
dcdc_desc.vsel_reg = MAX8649_MODE2;
break;
case 3:
dcdc_desc.vsel_reg = MAX8649_MODE3;
break;
default:
break;
}
ret = regmap_read(info->regmap, MAX8649_CHIP_ID1, &val);
if (ret != 0) {
dev_err(info->dev, "Failed to detect ID of MAX8649:%d\n",
ret);
return ret;
}
dev_info(info->dev, "Detected MAX8649 (ID:%x)\n", val);
regmap_update_bits(info->regmap, MAX8649_CONTROL, MAX8649_VID_MASK, 0);
info->extclk = pdata->extclk;
data = (info->extclk) ? MAX8649_SYNC_EXTCLK : 0;
regmap_update_bits(info->regmap, dcdc_desc.vsel_reg,
MAX8649_SYNC_EXTCLK, data);
if (info->extclk) {
info->extclk_freq = pdata->extclk_freq;
regmap_update_bits(info->regmap, MAX8649_SYNC, MAX8649_EXT_MASK,
info->extclk_freq << 6);
}
if (pdata->ramp_timing) {
info->ramp_timing = pdata->ramp_timing;
regmap_update_bits(info->regmap, MAX8649_RAMP, MAX8649_RAMP_MASK,
info->ramp_timing << 5);
}
info->ramp_down = pdata->ramp_down;
if (info->ramp_down) {
regmap_update_bits(info->regmap, MAX8649_RAMP, MAX8649_RAMP_DOWN,
MAX8649_RAMP_DOWN);
}
config.dev = &client->dev;
config.init_data = pdata->regulator;
config.driver_data = info;
config.regmap = info->regmap;
info->regulator = devm_regulator_register(&client->dev, &dcdc_desc,
&config);
if (IS_ERR(info->regulator)) {
dev_err(info->dev, "failed to register regulator %s\n",
dcdc_desc.name);
return PTR_ERR(info->regulator);
}
return 0;
}
static int __init max8649_init(void)
{
return i2c_add_driver(&max8649_driver);
}
static void __exit max8649_exit(void)
{
i2c_del_driver(&max8649_driver);
}
