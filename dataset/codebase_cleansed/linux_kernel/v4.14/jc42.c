static u16 jc42_temp_to_reg(long temp, bool extended)
{
int ntemp = clamp_val(temp,
extended ? JC42_TEMP_MIN_EXTENDED :
JC42_TEMP_MIN, JC42_TEMP_MAX);
return (ntemp * 2 / 125) & 0x1fff;
}
static int jc42_temp_from_reg(s16 reg)
{
reg = sign_extend32(reg, 12);
return reg * 125 / 2;
}
static struct jc42_data *jc42_update_device(struct device *dev)
{
struct jc42_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
struct jc42_data *ret = data;
int i, val;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
for (i = 0; i < t_num_temp; i++) {
val = i2c_smbus_read_word_swapped(client, temp_regs[i]);
if (val < 0) {
ret = ERR_PTR(val);
goto abort;
}
data->temp[i] = val;
}
data->last_updated = jiffies;
data->valid = true;
}
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static int jc42_read(struct device *dev, enum hwmon_sensor_types type,
u32 attr, int channel, long *val)
{
struct jc42_data *data = jc42_update_device(dev);
int temp, hyst;
if (IS_ERR(data))
return PTR_ERR(data);
switch (attr) {
case hwmon_temp_input:
*val = jc42_temp_from_reg(data->temp[t_input]);
return 0;
case hwmon_temp_min:
*val = jc42_temp_from_reg(data->temp[t_min]);
return 0;
case hwmon_temp_max:
*val = jc42_temp_from_reg(data->temp[t_max]);
return 0;
case hwmon_temp_crit:
*val = jc42_temp_from_reg(data->temp[t_crit]);
return 0;
case hwmon_temp_max_hyst:
temp = jc42_temp_from_reg(data->temp[t_max]);
hyst = jc42_hysteresis[(data->config & JC42_CFG_HYST_MASK)
>> JC42_CFG_HYST_SHIFT];
*val = temp - hyst;
return 0;
case hwmon_temp_crit_hyst:
temp = jc42_temp_from_reg(data->temp[t_crit]);
hyst = jc42_hysteresis[(data->config & JC42_CFG_HYST_MASK)
>> JC42_CFG_HYST_SHIFT];
*val = temp - hyst;
return 0;
case hwmon_temp_min_alarm:
*val = (data->temp[t_input] >> JC42_ALARM_MIN_BIT) & 1;
return 0;
case hwmon_temp_max_alarm:
*val = (data->temp[t_input] >> JC42_ALARM_MAX_BIT) & 1;
return 0;
case hwmon_temp_crit_alarm:
*val = (data->temp[t_input] >> JC42_ALARM_CRIT_BIT) & 1;
return 0;
default:
return -EOPNOTSUPP;
}
}
static int jc42_write(struct device *dev, enum hwmon_sensor_types type,
u32 attr, int channel, long val)
{
struct jc42_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int diff, hyst;
int ret;
mutex_lock(&data->update_lock);
switch (attr) {
case hwmon_temp_min:
data->temp[t_min] = jc42_temp_to_reg(val, data->extended);
ret = i2c_smbus_write_word_swapped(client, temp_regs[t_min],
data->temp[t_min]);
break;
case hwmon_temp_max:
data->temp[t_max] = jc42_temp_to_reg(val, data->extended);
ret = i2c_smbus_write_word_swapped(client, temp_regs[t_max],
data->temp[t_max]);
break;
case hwmon_temp_crit:
data->temp[t_crit] = jc42_temp_to_reg(val, data->extended);
ret = i2c_smbus_write_word_swapped(client, temp_regs[t_crit],
data->temp[t_crit]);
break;
case hwmon_temp_crit_hyst:
val = clamp_val(val, (data->extended ? JC42_TEMP_MIN_EXTENDED
: JC42_TEMP_MIN) - 6000,
JC42_TEMP_MAX);
diff = jc42_temp_from_reg(data->temp[t_crit]) - val;
hyst = 0;
if (diff > 0) {
if (diff < 2250)
hyst = 1;
else if (diff < 4500)
hyst = 2;
else
hyst = 3;
}
data->config = (data->config & ~JC42_CFG_HYST_MASK) |
(hyst << JC42_CFG_HYST_SHIFT);
ret = i2c_smbus_write_word_swapped(data->client,
JC42_REG_CONFIG,
data->config);
break;
default:
ret = -EOPNOTSUPP;
break;
}
mutex_unlock(&data->update_lock);
return ret;
}
static umode_t jc42_is_visible(const void *_data, enum hwmon_sensor_types type,
u32 attr, int channel)
{
const struct jc42_data *data = _data;
unsigned int config = data->config;
umode_t mode = S_IRUGO;
switch (attr) {
case hwmon_temp_min:
case hwmon_temp_max:
if (!(config & JC42_CFG_EVENT_LOCK))
mode |= S_IWUSR;
break;
case hwmon_temp_crit:
if (!(config & JC42_CFG_TCRIT_LOCK))
mode |= S_IWUSR;
break;
case hwmon_temp_crit_hyst:
if (!(config & (JC42_CFG_EVENT_LOCK | JC42_CFG_TCRIT_LOCK)))
mode |= S_IWUSR;
break;
case hwmon_temp_input:
case hwmon_temp_max_hyst:
case hwmon_temp_min_alarm:
case hwmon_temp_max_alarm:
case hwmon_temp_crit_alarm:
break;
default:
mode = 0;
break;
}
return mode;
}
static int jc42_detect(struct i2c_client *client, struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int i, config, cap, manid, devid;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
cap = i2c_smbus_read_word_swapped(client, JC42_REG_CAP);
config = i2c_smbus_read_word_swapped(client, JC42_REG_CONFIG);
manid = i2c_smbus_read_word_swapped(client, JC42_REG_MANID);
devid = i2c_smbus_read_word_swapped(client, JC42_REG_DEVICEID);
if (cap < 0 || config < 0 || manid < 0 || devid < 0)
return -ENODEV;
if ((cap & 0xff00) || (config & 0xf800))
return -ENODEV;
for (i = 0; i < ARRAY_SIZE(jc42_chips); i++) {
struct jc42_chips *chip = &jc42_chips[i];
if (manid == chip->manid &&
(devid & chip->devid_mask) == chip->devid) {
strlcpy(info->type, "jc42", I2C_NAME_SIZE);
return 0;
}
}
return -ENODEV;
}
static int jc42_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct jc42_data *data;
int config, cap;
data = devm_kzalloc(dev, sizeof(struct jc42_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
cap = i2c_smbus_read_word_swapped(client, JC42_REG_CAP);
if (cap < 0)
return cap;
data->extended = !!(cap & JC42_CAP_RANGE);
config = i2c_smbus_read_word_swapped(client, JC42_REG_CONFIG);
if (config < 0)
return config;
data->orig_config = config;
if (config & JC42_CFG_SHUTDOWN) {
config &= ~JC42_CFG_SHUTDOWN;
i2c_smbus_write_word_swapped(client, JC42_REG_CONFIG, config);
}
data->config = config;
hwmon_dev = devm_hwmon_device_register_with_info(dev, client->name,
data, &jc42_chip_info,
NULL);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
static int jc42_remove(struct i2c_client *client)
{
struct jc42_data *data = i2c_get_clientdata(client);
if ((data->config & ~JC42_CFG_HYST_MASK) !=
(data->orig_config & ~JC42_CFG_HYST_MASK)) {
int config;
config = (data->orig_config & ~JC42_CFG_HYST_MASK)
| (data->config & JC42_CFG_HYST_MASK);
i2c_smbus_write_word_swapped(client, JC42_REG_CONFIG, config);
}
return 0;
}
static int jc42_suspend(struct device *dev)
{
struct jc42_data *data = dev_get_drvdata(dev);
data->config |= JC42_CFG_SHUTDOWN;
i2c_smbus_write_word_swapped(data->client, JC42_REG_CONFIG,
data->config);
return 0;
}
static int jc42_resume(struct device *dev)
{
struct jc42_data *data = dev_get_drvdata(dev);
data->config &= ~JC42_CFG_SHUTDOWN;
i2c_smbus_write_word_swapped(data->client, JC42_REG_CONFIG,
data->config);
return 0;
}
