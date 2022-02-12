static inline int TEMP_FROM_REG(s16 reg)
{
return reg / 8 * 625 / 10;
}
static inline s16 TEMP_TO_REG(int val)
{
if (val <= -60000)
return -60000 * 10 / 625 * 8;
if (val >= 160000)
return 160000 * 10 / 625 * 8;
return val * 10 / 625 * 8;
}
static inline u8 ALARMS_FROM_REG(s16 reg)
{
return reg & 0x0007;
}
static struct lm92_data *lm92_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm92_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ)
|| !data->valid) {
dev_dbg(&client->dev, "Updating lm92 data\n");
data->temp1_input = i2c_smbus_read_word_swapped(client,
LM92_REG_TEMP);
data->temp1_hyst = i2c_smbus_read_word_swapped(client,
LM92_REG_TEMP_HYST);
data->temp1_crit = i2c_smbus_read_word_swapped(client,
LM92_REG_TEMP_CRIT);
data->temp1_min = i2c_smbus_read_word_swapped(client,
LM92_REG_TEMP_LOW);
data->temp1_max = i2c_smbus_read_word_swapped(client,
LM92_REG_TEMP_HIGH);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_temp1_crit_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm92_data *data = lm92_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp1_crit)
- TEMP_FROM_REG(data->temp1_hyst));
}
static ssize_t show_temp1_max_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm92_data *data = lm92_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp1_max)
- TEMP_FROM_REG(data->temp1_hyst));
}
static ssize_t show_temp1_min_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm92_data *data = lm92_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp1_min)
+ TEMP_FROM_REG(data->temp1_hyst));
}
static ssize_t set_temp1_crit_hyst(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm92_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp1_hyst = TEMP_FROM_REG(data->temp1_crit) - val;
i2c_smbus_write_word_swapped(client, LM92_REG_TEMP_HYST,
TEMP_TO_REG(data->temp1_hyst));
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm92_data *data = lm92_update_device(dev);
return sprintf(buf, "%d\n", ALARMS_FROM_REG(data->temp1_input));
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct lm92_data *data = lm92_update_device(dev);
return sprintf(buf, "%d\n", (data->temp1_input >> bitnr) & 1);
}
static void lm92_init_client(struct i2c_client *client)
{
u8 config;
config = i2c_smbus_read_byte_data(client, LM92_REG_CONFIG);
if (config & 0x01)
i2c_smbus_write_byte_data(client, LM92_REG_CONFIG,
config & 0xFE);
}
static int max6635_check(struct i2c_client *client)
{
u16 temp_low, temp_high, temp_hyst, temp_crit;
u8 conf;
int i;
temp_low = i2c_smbus_read_word_data(client, LM92_REG_TEMP_LOW);
if (i2c_smbus_read_word_data(client, LM92_REG_MAN_ID) != temp_low)
return 0;
temp_high = i2c_smbus_read_word_data(client, LM92_REG_TEMP_HIGH);
if (i2c_smbus_read_word_data(client, LM92_REG_MAN_ID) != temp_high)
return 0;
if ((temp_low & 0x7f00) || (temp_high & 0x7f00))
return 0;
temp_hyst = i2c_smbus_read_word_data(client, LM92_REG_TEMP_HYST);
temp_crit = i2c_smbus_read_word_data(client, LM92_REG_TEMP_CRIT);
if ((temp_hyst & 0x7f00) || (temp_crit & 0x7f00))
return 0;
conf = i2c_smbus_read_byte_data(client, LM92_REG_CONFIG);
for (i = 16; i < 96; i *= 2) {
if (temp_hyst != i2c_smbus_read_word_data(client,
LM92_REG_TEMP_HYST + i - 16)
|| temp_crit != i2c_smbus_read_word_data(client,
LM92_REG_TEMP_CRIT + i)
|| temp_low != i2c_smbus_read_word_data(client,
LM92_REG_TEMP_LOW + i + 16)
|| temp_high != i2c_smbus_read_word_data(client,
LM92_REG_TEMP_HIGH + i + 32)
|| conf != i2c_smbus_read_byte_data(client,
LM92_REG_CONFIG + i))
return 0;
}
return 1;
}
static int lm92_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
u8 config;
u16 man_id;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA
| I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
config = i2c_smbus_read_byte_data(new_client, LM92_REG_CONFIG);
man_id = i2c_smbus_read_word_data(new_client, LM92_REG_MAN_ID);
if ((config & 0xe0) == 0x00 && man_id == 0x0180)
pr_info("lm92: Found National Semiconductor LM92 chip\n");
else if (max6635_check(new_client))
pr_info("lm92: Found Maxim MAX6635 chip\n");
else
return -ENODEV;
strlcpy(info->type, "lm92", I2C_NAME_SIZE);
return 0;
}
static int lm92_probe(struct i2c_client *new_client,
const struct i2c_device_id *id)
{
struct lm92_data *data;
int err;
data = devm_kzalloc(&new_client->dev, sizeof(struct lm92_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(new_client, data);
mutex_init(&data->update_lock);
lm92_init_client(new_client);
err = sysfs_create_group(&new_client->dev.kobj, &lm92_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(&new_client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
sysfs_remove_group(&new_client->dev.kobj, &lm92_group);
return err;
}
static int lm92_remove(struct i2c_client *client)
{
struct lm92_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm92_group);
return 0;
}
