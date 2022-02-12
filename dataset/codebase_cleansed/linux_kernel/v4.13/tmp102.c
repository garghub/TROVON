static inline int tmp102_reg_to_mC(s16 val)
{
return ((val & ~0x01) * 1000) / 128;
}
static inline u16 tmp102_mC_to_reg(int val)
{
return (val * 128) / 1000;
}
static int tmp102_read(struct device *dev, enum hwmon_sensor_types type,
u32 attr, int channel, long *temp)
{
struct tmp102 *tmp102 = dev_get_drvdata(dev);
unsigned int regval;
int err, reg;
switch (attr) {
case hwmon_temp_input:
if (time_before(jiffies, tmp102->ready_time)) {
dev_dbg(dev, "%s: Conversion not ready yet..\n", __func__);
return -EAGAIN;
}
reg = TMP102_TEMP_REG;
break;
case hwmon_temp_max_hyst:
reg = TMP102_TLOW_REG;
break;
case hwmon_temp_max:
reg = TMP102_THIGH_REG;
break;
default:
return -EOPNOTSUPP;
}
err = regmap_read(tmp102->regmap, reg, &regval);
if (err < 0)
return err;
*temp = tmp102_reg_to_mC(regval);
return 0;
}
static int tmp102_write(struct device *dev, enum hwmon_sensor_types type,
u32 attr, int channel, long temp)
{
struct tmp102 *tmp102 = dev_get_drvdata(dev);
int reg;
switch (attr) {
case hwmon_temp_max_hyst:
reg = TMP102_TLOW_REG;
break;
case hwmon_temp_max:
reg = TMP102_THIGH_REG;
break;
default:
return -EOPNOTSUPP;
}
temp = clamp_val(temp, -256000, 255000);
return regmap_write(tmp102->regmap, reg, tmp102_mC_to_reg(temp));
}
static umode_t tmp102_is_visible(const void *data, enum hwmon_sensor_types type,
u32 attr, int channel)
{
if (type != hwmon_temp)
return 0;
switch (attr) {
case hwmon_temp_input:
return S_IRUGO;
case hwmon_temp_max_hyst:
case hwmon_temp_max:
return S_IRUGO | S_IWUSR;
default:
return 0;
}
}
static void tmp102_restore_config(void *data)
{
struct tmp102 *tmp102 = data;
regmap_write(tmp102->regmap, TMP102_CONF_REG, tmp102->config_orig);
}
static bool tmp102_is_writeable_reg(struct device *dev, unsigned int reg)
{
return reg != TMP102_TEMP_REG;
}
static bool tmp102_is_volatile_reg(struct device *dev, unsigned int reg)
{
return reg == TMP102_TEMP_REG;
}
static int tmp102_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct tmp102 *tmp102;
unsigned int regval;
int err;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA)) {
dev_err(dev,
"adapter doesn't support SMBus word transactions\n");
return -ENODEV;
}
tmp102 = devm_kzalloc(dev, sizeof(*tmp102), GFP_KERNEL);
if (!tmp102)
return -ENOMEM;
i2c_set_clientdata(client, tmp102);
tmp102->regmap = devm_regmap_init_i2c(client, &tmp102_regmap_config);
if (IS_ERR(tmp102->regmap))
return PTR_ERR(tmp102->regmap);
err = regmap_read(tmp102->regmap, TMP102_CONF_REG, &regval);
if (err < 0) {
dev_err(dev, "error reading config register\n");
return err;
}
if ((regval & ~TMP102_CONFREG_MASK) !=
(TMP102_CONF_R0 | TMP102_CONF_R1)) {
dev_err(dev, "unexpected config register value\n");
return -ENODEV;
}
tmp102->config_orig = regval;
err = devm_add_action_or_reset(dev, tmp102_restore_config, tmp102);
if (err)
return err;
regval &= ~TMP102_CONFIG_CLEAR;
regval |= TMP102_CONFIG_SET;
err = regmap_write(tmp102->regmap, TMP102_CONF_REG, regval);
if (err < 0) {
dev_err(dev, "error writing config register\n");
return err;
}
tmp102->ready_time = jiffies;
if (tmp102->config_orig & TMP102_CONF_SD) {
tmp102->ready_time += msecs_to_jiffies(CONVERSION_TIME_MS);
}
hwmon_dev = devm_hwmon_device_register_with_info(dev, client->name,
tmp102,
&tmp102_chip_info,
NULL);
if (IS_ERR(hwmon_dev)) {
dev_dbg(dev, "unable to register hwmon device\n");
return PTR_ERR(hwmon_dev);
}
dev_info(dev, "initialized\n");
return 0;
}
static int tmp102_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct tmp102 *tmp102 = i2c_get_clientdata(client);
return regmap_update_bits(tmp102->regmap, TMP102_CONF_REG,
TMP102_CONF_SD, TMP102_CONF_SD);
}
static int tmp102_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct tmp102 *tmp102 = i2c_get_clientdata(client);
int err;
err = regmap_update_bits(tmp102->regmap, TMP102_CONF_REG,
TMP102_CONF_SD, 0);
tmp102->ready_time = jiffies + msecs_to_jiffies(CONVERSION_TIME_MS);
return err;
}
