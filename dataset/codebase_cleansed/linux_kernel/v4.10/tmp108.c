static inline int tmp108_temp_reg_to_mC(s16 val)
{
return (val & ~0x0f) * 1000 / 256;
}
static inline u16 tmp108_mC_to_temp_reg(int val)
{
return (val * 256) / 1000;
}
static int tmp108_read(struct device *dev, enum hwmon_sensor_types type,
u32 attr, int channel, long *temp)
{
struct tmp108 *tmp108 = dev_get_drvdata(dev);
unsigned int regval;
int err, hyst;
if (type == hwmon_chip) {
if (attr == hwmon_chip_update_interval) {
err = regmap_read(tmp108->regmap, TMP108_REG_CONF,
&regval);
if (err < 0)
return err;
switch (regval & TMP108_CONF_CONVRATE_MASK) {
case TMP108_CONVRATE_0P25HZ:
default:
*temp = 4000;
break;
case TMP108_CONVRATE_1HZ:
*temp = 1000;
break;
case TMP108_CONVRATE_4HZ:
*temp = 250;
break;
case TMP108_CONVRATE_16HZ:
*temp = 63;
break;
}
return 0;
}
return -EOPNOTSUPP;
}
switch (attr) {
case hwmon_temp_input:
if (time_before(jiffies, tmp108->ready_time)) {
dev_dbg(dev, "%s: Conversion not ready yet..\n",
__func__);
return -EAGAIN;
}
err = regmap_read(tmp108->regmap, TMP108_REG_TEMP, &regval);
if (err < 0)
return err;
*temp = tmp108_temp_reg_to_mC(regval);
break;
case hwmon_temp_min:
case hwmon_temp_max:
err = regmap_read(tmp108->regmap, attr == hwmon_temp_min ?
TMP108_REG_TLOW : TMP108_REG_THIGH, &regval);
if (err < 0)
return err;
*temp = tmp108_temp_reg_to_mC(regval);
break;
case hwmon_temp_min_alarm:
case hwmon_temp_max_alarm:
err = regmap_read(tmp108->regmap, TMP108_REG_CONF, &regval);
if (err < 0)
return err;
*temp = !!(regval & (attr == hwmon_temp_min_alarm ?
TMP108_CONF_FL : TMP108_CONF_FH));
break;
case hwmon_temp_min_hyst:
case hwmon_temp_max_hyst:
err = regmap_read(tmp108->regmap, TMP108_REG_CONF, &regval);
if (err < 0)
return err;
switch (regval & TMP108_CONF_HYSTERESIS_MASK) {
case TMP108_HYSTERESIS_0C:
default:
hyst = 0;
break;
case TMP108_HYSTERESIS_1C:
hyst = 1000;
break;
case TMP108_HYSTERESIS_2C:
hyst = 2000;
break;
case TMP108_HYSTERESIS_4C:
hyst = 4000;
break;
}
err = regmap_read(tmp108->regmap, attr == hwmon_temp_min_hyst ?
TMP108_REG_TLOW : TMP108_REG_THIGH, &regval);
if (err < 0)
return err;
*temp = tmp108_temp_reg_to_mC(regval);
if (attr == hwmon_temp_min_hyst)
*temp += hyst;
else
*temp -= hyst;
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int tmp108_write(struct device *dev, enum hwmon_sensor_types type,
u32 attr, int channel, long temp)
{
struct tmp108 *tmp108 = dev_get_drvdata(dev);
u32 regval, mask;
int err;
if (type == hwmon_chip) {
if (attr == hwmon_chip_update_interval) {
if (temp < 156)
mask = TMP108_CONVRATE_16HZ;
else if (temp < 625)
mask = TMP108_CONVRATE_4HZ;
else if (temp < 2500)
mask = TMP108_CONVRATE_1HZ;
else
mask = TMP108_CONVRATE_0P25HZ;
return regmap_update_bits(tmp108->regmap,
TMP108_REG_CONF,
TMP108_CONF_CONVRATE_MASK,
mask);
}
return -EOPNOTSUPP;
}
switch (attr) {
case hwmon_temp_min:
case hwmon_temp_max:
temp = clamp_val(temp, TMP108_TEMP_MIN_MC, TMP108_TEMP_MAX_MC);
return regmap_write(tmp108->regmap,
attr == hwmon_temp_min ?
TMP108_REG_TLOW : TMP108_REG_THIGH,
tmp108_mC_to_temp_reg(temp));
case hwmon_temp_min_hyst:
case hwmon_temp_max_hyst:
temp = clamp_val(temp, TMP108_TEMP_MIN_MC, TMP108_TEMP_MAX_MC);
err = regmap_read(tmp108->regmap,
attr == hwmon_temp_min_hyst ?
TMP108_REG_TLOW : TMP108_REG_THIGH,
&regval);
if (err < 0)
return err;
if (attr == hwmon_temp_min_hyst)
temp -= tmp108_temp_reg_to_mC(regval);
else
temp = tmp108_temp_reg_to_mC(regval) - temp;
if (temp < 500)
mask = TMP108_HYSTERESIS_0C;
else if (temp < 1500)
mask = TMP108_HYSTERESIS_1C;
else if (temp < 3000)
mask = TMP108_HYSTERESIS_2C;
else
mask = TMP108_HYSTERESIS_4C;
return regmap_update_bits(tmp108->regmap, TMP108_REG_CONF,
TMP108_CONF_HYSTERESIS_MASK, mask);
default:
return -EOPNOTSUPP;
}
}
static umode_t tmp108_is_visible(const void *data, enum hwmon_sensor_types type,
u32 attr, int channel)
{
if (type == hwmon_chip && attr == hwmon_chip_update_interval)
return 0644;
if (type != hwmon_temp)
return 0;
switch (attr) {
case hwmon_temp_input:
case hwmon_temp_min_alarm:
case hwmon_temp_max_alarm:
return 0444;
case hwmon_temp_min:
case hwmon_temp_max:
case hwmon_temp_min_hyst:
case hwmon_temp_max_hyst:
return 0644;
default:
return 0;
}
}
static void tmp108_restore_config(void *data)
{
struct tmp108 *tmp108 = data;
regmap_write(tmp108->regmap, TMP108_REG_CONF, tmp108->orig_config);
}
static bool tmp108_is_writeable_reg(struct device *dev, unsigned int reg)
{
return reg != TMP108_REG_TEMP;
}
static bool tmp108_is_volatile_reg(struct device *dev, unsigned int reg)
{
return reg == TMP108_REG_TEMP || reg == TMP108_REG_CONF;
}
static int tmp108_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct tmp108 *tmp108;
int err;
u32 config;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA)) {
dev_err(dev,
"adapter doesn't support SMBus word transactions\n");
return -ENODEV;
}
tmp108 = devm_kzalloc(dev, sizeof(*tmp108), GFP_KERNEL);
if (!tmp108)
return -ENOMEM;
dev_set_drvdata(dev, tmp108);
tmp108->regmap = devm_regmap_init_i2c(client, &tmp108_regmap_config);
if (IS_ERR(tmp108->regmap)) {
err = PTR_ERR(tmp108->regmap);
dev_err(dev, "regmap init failed: %d", err);
return err;
}
err = regmap_read(tmp108->regmap, TMP108_REG_CONF, &config);
if (err < 0) {
dev_err(dev, "error reading config register: %d", err);
return err;
}
tmp108->orig_config = config;
config &= ~TMP108_CONF_MODE_MASK;
config |= TMP108_MODE_CONTINUOUS;
config &= ~TMP108_CONF_TM;
err = regmap_write(tmp108->regmap, TMP108_REG_CONF, config);
if (err < 0) {
dev_err(dev, "error writing config register: %d", err);
return err;
}
tmp108->ready_time = jiffies;
if ((tmp108->orig_config & TMP108_CONF_MODE_MASK) ==
TMP108_MODE_SHUTDOWN)
tmp108->ready_time +=
msecs_to_jiffies(TMP108_CONVERSION_TIME_MS);
err = devm_add_action_or_reset(dev, tmp108_restore_config, tmp108);
if (err) {
dev_err(dev, "add action or reset failed: %d", err);
return err;
}
hwmon_dev = devm_hwmon_device_register_with_info(dev, client->name,
tmp108,
&tmp108_chip_info,
NULL);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
static int __maybe_unused tmp108_suspend(struct device *dev)
{
struct tmp108 *tmp108 = dev_get_drvdata(dev);
return regmap_update_bits(tmp108->regmap, TMP108_REG_CONF,
TMP108_CONF_MODE_MASK, TMP108_MODE_SHUTDOWN);
}
static int __maybe_unused tmp108_resume(struct device *dev)
{
struct tmp108 *tmp108 = dev_get_drvdata(dev);
int err;
err = regmap_update_bits(tmp108->regmap, TMP108_REG_CONF,
TMP108_CONF_MODE_MASK, TMP108_MODE_CONTINUOUS);
tmp108->ready_time = jiffies +
msecs_to_jiffies(TMP108_CONVERSION_TIME_MS);
return err;
}
