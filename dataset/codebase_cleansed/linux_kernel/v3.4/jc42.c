static int jc42_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct jc42_data *data = i2c_get_clientdata(client);
data->config |= JC42_CFG_SHUTDOWN;
i2c_smbus_write_word_swapped(client, JC42_REG_CONFIG, data->config);
return 0;
}
static int jc42_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct jc42_data *data = i2c_get_clientdata(client);
data->config &= ~JC42_CFG_SHUTDOWN;
i2c_smbus_write_word_swapped(client, JC42_REG_CONFIG, data->config);
return 0;
}
static u16 jc42_temp_to_reg(int temp, bool extended)
{
int ntemp = SENSORS_LIMIT(temp,
extended ? JC42_TEMP_MIN_EXTENDED :
JC42_TEMP_MIN, JC42_TEMP_MAX);
return (ntemp * 2 / 125) & 0x1fff;
}
static int jc42_temp_from_reg(s16 reg)
{
reg &= 0x1fff;
if (reg & 0x1000)
reg |= 0xf000;
return reg * 125 / 2;
}
static ssize_t show_temp_crit_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct jc42_data *data = jc42_update_device(dev);
int temp, hyst;
if (IS_ERR(data))
return PTR_ERR(data);
temp = jc42_temp_from_reg(data->temp_crit);
hyst = jc42_hysteresis[(data->config >> JC42_CFG_HYST_SHIFT)
& JC42_CFG_HYST_MASK];
return sprintf(buf, "%d\n", temp - hyst);
}
static ssize_t show_temp_max_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct jc42_data *data = jc42_update_device(dev);
int temp, hyst;
if (IS_ERR(data))
return PTR_ERR(data);
temp = jc42_temp_from_reg(data->temp_max);
hyst = jc42_hysteresis[(data->config >> JC42_CFG_HYST_SHIFT)
& JC42_CFG_HYST_MASK];
return sprintf(buf, "%d\n", temp - hyst);
}
static ssize_t set_temp_crit_hyst(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct jc42_data *data = i2c_get_clientdata(client);
unsigned long val;
int diff, hyst;
int err;
int ret = count;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
diff = jc42_temp_from_reg(data->temp_crit) - val;
hyst = 0;
if (diff > 0) {
if (diff < 2250)
hyst = 1;
else if (diff < 4500)
hyst = 2;
else
hyst = 3;
}
mutex_lock(&data->update_lock);
data->config = (data->config
& ~(JC42_CFG_HYST_MASK << JC42_CFG_HYST_SHIFT))
| (hyst << JC42_CFG_HYST_SHIFT);
err = i2c_smbus_write_word_swapped(client, JC42_REG_CONFIG,
data->config);
if (err < 0)
ret = err;
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_alarm(struct device *dev,
struct device_attribute *attr, char *buf)
{
u16 bit = to_sensor_dev_attr(attr)->index;
struct jc42_data *data = jc42_update_device(dev);
u16 val;
if (IS_ERR(data))
return PTR_ERR(data);
val = data->temp_input;
if (bit != JC42_ALARM_CRIT_BIT && (data->config & JC42_CFG_CRIT_ONLY))
val = 0;
return sprintf(buf, "%u\n", (val >> bit) & 1);
}
static umode_t jc42_attribute_mode(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct i2c_client *client = to_i2c_client(dev);
struct jc42_data *data = i2c_get_clientdata(client);
unsigned int config = data->config;
bool readonly;
if (attr == &dev_attr_temp1_crit.attr)
readonly = config & JC42_CFG_TCRIT_LOCK;
else if (attr == &dev_attr_temp1_min.attr ||
attr == &dev_attr_temp1_max.attr)
readonly = config & JC42_CFG_EVENT_LOCK;
else if (attr == &dev_attr_temp1_crit_hyst.attr)
readonly = config & (JC42_CFG_EVENT_LOCK | JC42_CFG_TCRIT_LOCK);
else
readonly = true;
return S_IRUGO | (readonly ? 0 : S_IWUSR);
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
struct jc42_data *data;
int config, cap, err;
struct device *dev = &client->dev;
data = devm_kzalloc(dev, sizeof(struct jc42_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
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
err = sysfs_create_group(&dev->kobj, &jc42_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
sysfs_remove_group(&dev->kobj, &jc42_group);
return err;
}
static int jc42_remove(struct i2c_client *client)
{
struct jc42_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &jc42_group);
if (data->config != data->orig_config)
i2c_smbus_write_word_swapped(client, JC42_REG_CONFIG,
data->orig_config);
return 0;
}
static struct jc42_data *jc42_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct jc42_data *data = i2c_get_clientdata(client);
struct jc42_data *ret = data;
int val;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
val = i2c_smbus_read_word_swapped(client, JC42_REG_TEMP);
if (val < 0) {
ret = ERR_PTR(val);
goto abort;
}
data->temp_input = val;
val = i2c_smbus_read_word_swapped(client,
JC42_REG_TEMP_CRITICAL);
if (val < 0) {
ret = ERR_PTR(val);
goto abort;
}
data->temp_crit = val;
val = i2c_smbus_read_word_swapped(client, JC42_REG_TEMP_LOWER);
if (val < 0) {
ret = ERR_PTR(val);
goto abort;
}
data->temp_min = val;
val = i2c_smbus_read_word_swapped(client, JC42_REG_TEMP_UPPER);
if (val < 0) {
ret = ERR_PTR(val);
goto abort;
}
data->temp_max = val;
data->last_updated = jiffies;
data->valid = true;
}
abort:
mutex_unlock(&data->update_lock);
return ret;
}
