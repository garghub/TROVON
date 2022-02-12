static inline u8 FAN_TO_REG(long rpm, int div)
{
long rpmdiv;
if (rpm == 0)
return 0;
rpmdiv = SENSORS_LIMIT(rpm, 1, 960000) * div;
return SENSORS_LIMIT((480000 + rpmdiv / 2) / rpmdiv, 1, 255);
}
static ssize_t show_fan_input(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct gl518_data *data = gl518_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_in[nr],
DIV_FROM_REG(data->fan_div[nr])));
}
static ssize_t show_fan_min(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct gl518_data *data = gl518_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr])));
}
static ssize_t show_fan_div(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct gl518_data *data = gl518_update_device(dev);
return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[nr]));
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct gl518_data *data = i2c_get_clientdata(client);
int nr = to_sensor_dev_attr(attr)->index;
int regvalue;
unsigned long val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
regvalue = gl518_read_value(client, GL518_REG_FAN_LIMIT);
data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
regvalue = (regvalue & (0xff << (8 * nr)))
| (data->fan_min[nr] << (8 * (1 - nr)));
gl518_write_value(client, GL518_REG_FAN_LIMIT, regvalue);
data->beep_mask = gl518_read_value(client, GL518_REG_ALARM);
if (data->fan_min[nr] == 0)
data->alarm_mask &= ~(0x20 << nr);
else
data->alarm_mask |= (0x20 << nr);
data->beep_mask &= data->alarm_mask;
gl518_write_value(client, GL518_REG_ALARM, data->beep_mask);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_fan_div(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct gl518_data *data = i2c_get_clientdata(client);
int nr = to_sensor_dev_attr(attr)->index;
int regvalue;
unsigned long val = simple_strtoul(buf, NULL, 10);
switch (val) {
case 1: val = 0; break;
case 2: val = 1; break;
case 4: val = 2; break;
case 8: val = 3; break;
default:
dev_err(dev, "Invalid fan clock divider %lu, choose one "
"of 1, 2, 4 or 8\n", val);
return -EINVAL;
}
mutex_lock(&data->update_lock);
regvalue = gl518_read_value(client, GL518_REG_MISC);
data->fan_div[nr] = val;
regvalue = (regvalue & ~(0xc0 >> (2 * nr)))
| (data->fan_div[nr] << (6 - 2 * nr));
gl518_write_value(client, GL518_REG_MISC, regvalue);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct gl518_data *data = gl518_update_device(dev);
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static ssize_t show_beep(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct gl518_data *data = gl518_update_device(dev);
return sprintf(buf, "%u\n", (data->beep_mask >> bitnr) & 1);
}
static ssize_t set_beep(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct gl518_data *data = i2c_get_clientdata(client);
int bitnr = to_sensor_dev_attr(attr)->index;
unsigned long bit;
bit = simple_strtoul(buf, NULL, 10);
if (bit & ~1)
return -EINVAL;
mutex_lock(&data->update_lock);
data->beep_mask = gl518_read_value(client, GL518_REG_ALARM);
if (bit)
data->beep_mask |= (1 << bitnr);
else
data->beep_mask &= ~(1 << bitnr);
gl518_write_value(client, GL518_REG_ALARM, data->beep_mask);
mutex_unlock(&data->update_lock);
return count;
}
static int gl518_detect(struct i2c_client *client, struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int rev;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
if ((gl518_read_value(client, GL518_REG_CHIP_ID) != 0x80)
|| (gl518_read_value(client, GL518_REG_CONF) & 0x80))
return -ENODEV;
rev = gl518_read_value(client, GL518_REG_REVISION);
if (rev != 0x00 && rev != 0x80)
return -ENODEV;
strlcpy(info->type, "gl518sm", I2C_NAME_SIZE);
return 0;
}
static int gl518_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct gl518_data *data;
int err, revision;
data = kzalloc(sizeof(struct gl518_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
revision = gl518_read_value(client, GL518_REG_REVISION);
data->type = revision == 0x80 ? gl518sm_r80 : gl518sm_r00;
mutex_init(&data->update_lock);
data->alarm_mask = 0xff;
gl518_init_client(client);
if ((err = sysfs_create_group(&client->dev.kobj, &gl518_group)))
goto exit_free;
if (data->type == gl518sm_r80)
if ((err = sysfs_create_group(&client->dev.kobj,
&gl518_group_r80)))
goto exit_remove_files;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&client->dev.kobj, &gl518_group);
if (data->type == gl518sm_r80)
sysfs_remove_group(&client->dev.kobj, &gl518_group_r80);
exit_free:
kfree(data);
exit:
return err;
}
static void gl518_init_client(struct i2c_client *client)
{
u8 regvalue = gl518_read_value(client, GL518_REG_CONF) & 0x7f;
gl518_write_value(client, GL518_REG_CONF, (regvalue &= 0x37));
gl518_write_value(client, GL518_REG_MASK, 0x00);
gl518_write_value(client, GL518_REG_CONF, 0x20 | regvalue);
gl518_write_value(client, GL518_REG_CONF, 0x40 | regvalue);
}
static int gl518_remove(struct i2c_client *client)
{
struct gl518_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &gl518_group);
if (data->type == gl518sm_r80)
sysfs_remove_group(&client->dev.kobj, &gl518_group_r80);
kfree(data);
return 0;
}
static int gl518_read_value(struct i2c_client *client, u8 reg)
{
if ((reg >= 0x07) && (reg <= 0x0c))
return i2c_smbus_read_word_swapped(client, reg);
else
return i2c_smbus_read_byte_data(client, reg);
}
static int gl518_write_value(struct i2c_client *client, u8 reg, u16 value)
{
if ((reg >= 0x07) && (reg <= 0x0c))
return i2c_smbus_write_word_swapped(client, reg, value);
else
return i2c_smbus_write_byte_data(client, reg, value);
}
static struct gl518_data *gl518_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct gl518_data *data = i2c_get_clientdata(client);
int val;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
dev_dbg(&client->dev, "Starting gl518 update\n");
data->alarms = gl518_read_value(client, GL518_REG_INT);
data->beep_mask = gl518_read_value(client, GL518_REG_ALARM);
val = gl518_read_value(client, GL518_REG_VDD_LIMIT);
data->voltage_min[0] = val & 0xff;
data->voltage_max[0] = (val >> 8) & 0xff;
val = gl518_read_value(client, GL518_REG_VIN1_LIMIT);
data->voltage_min[1] = val & 0xff;
data->voltage_max[1] = (val >> 8) & 0xff;
val = gl518_read_value(client, GL518_REG_VIN2_LIMIT);
data->voltage_min[2] = val & 0xff;
data->voltage_max[2] = (val >> 8) & 0xff;
val = gl518_read_value(client, GL518_REG_VIN3_LIMIT);
data->voltage_min[3] = val & 0xff;
data->voltage_max[3] = (val >> 8) & 0xff;
val = gl518_read_value(client, GL518_REG_FAN_COUNT);
data->fan_in[0] = (val >> 8) & 0xff;
data->fan_in[1] = val & 0xff;
val = gl518_read_value(client, GL518_REG_FAN_LIMIT);
data->fan_min[0] = (val >> 8) & 0xff;
data->fan_min[1] = val & 0xff;
data->temp_in = gl518_read_value(client, GL518_REG_TEMP_IN);
data->temp_max =
gl518_read_value(client, GL518_REG_TEMP_MAX);
data->temp_hyst =
gl518_read_value(client, GL518_REG_TEMP_HYST);
val = gl518_read_value(client, GL518_REG_MISC);
data->fan_div[0] = (val >> 6) & 0x03;
data->fan_div[1] = (val >> 4) & 0x03;
data->fan_auto1 = (val >> 3) & 0x01;
data->alarms &= data->alarm_mask;
val = gl518_read_value(client, GL518_REG_CONF);
data->beep_enable = (val >> 2) & 1;
if (data->type != gl518sm_r00) {
data->voltage_in[0] =
gl518_read_value(client, GL518_REG_VDD);
data->voltage_in[1] =
gl518_read_value(client, GL518_REG_VIN1);
data->voltage_in[2] =
gl518_read_value(client, GL518_REG_VIN2);
}
data->voltage_in[3] =
gl518_read_value(client, GL518_REG_VIN3);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init sensors_gl518sm_init(void)
{
return i2c_add_driver(&gl518_driver);
}
static void __exit sensors_gl518sm_exit(void)
{
i2c_del_driver(&gl518_driver);
}
