static ssize_t show_fan(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[attr->index]));
}
static ssize_t set_fan(struct device *dev, struct device_attribute *dummy,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
unsigned long val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->fan[1] = FAN_TO_REG(val);
i2c_smbus_write_byte_data(client, LM63_REG_TACH_LIMIT_LSB,
data->fan[1] & 0xFF);
i2c_smbus_write_byte_data(client, LM63_REG_TACH_LIMIT_MSB,
data->fan[1] >> 8);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm1(struct device *dev, struct device_attribute *dummy,
char *buf)
{
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", data->pwm1_value >= 2 * data->pwm1_freq ?
255 : (data->pwm1_value * 255 + data->pwm1_freq) /
(2 * data->pwm1_freq));
}
static ssize_t set_pwm1(struct device *dev, struct device_attribute *dummy,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
unsigned long val;
if (!(data->config_fan & 0x20))
return -EPERM;
val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->pwm1_value = val <= 0 ? 0 :
val >= 255 ? 2 * data->pwm1_freq :
(val * data->pwm1_freq * 2 + 127) / 255;
i2c_smbus_write_byte_data(client, LM63_REG_PWM_VALUE, data->pwm1_value);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm1_enable(struct device *dev, struct device_attribute *dummy,
char *buf)
{
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", data->config_fan & 0x20 ? 1 : 2);
}
static ssize_t show_local_temp8(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", TEMP8_FROM_REG(data->temp8[attr->index]));
}
static ssize_t show_remote_temp8(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", TEMP8_FROM_REG(data->temp8[attr->index])
+ data->temp2_offset);
}
static ssize_t set_local_temp8(struct device *dev,
struct device_attribute *dummy,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->temp8[1] = TEMP8_TO_REG(val);
i2c_smbus_write_byte_data(client, LM63_REG_LOCAL_HIGH, data->temp8[1]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp11(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", TEMP11_FROM_REG(data->temp11[attr->index])
+ data->temp2_offset);
}
static ssize_t set_temp11(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
static const u8 reg[4] = {
LM63_REG_REMOTE_LOW_MSB,
LM63_REG_REMOTE_LOW_LSB,
LM63_REG_REMOTE_HIGH_MSB,
LM63_REG_REMOTE_HIGH_LSB,
};
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
long val = simple_strtol(buf, NULL, 10);
int nr = attr->index;
mutex_lock(&data->update_lock);
data->temp11[nr] = TEMP11_TO_REG(val - data->temp2_offset);
i2c_smbus_write_byte_data(client, reg[(nr - 1) * 2],
data->temp11[nr] >> 8);
i2c_smbus_write_byte_data(client, reg[(nr - 1) * 2 + 1],
data->temp11[nr] & 0xff);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp2_crit_hyst(struct device *dev, struct device_attribute *dummy,
char *buf)
{
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", TEMP8_FROM_REG(data->temp8[2])
+ data->temp2_offset
- TEMP8_FROM_REG(data->temp2_crit_hyst));
}
static ssize_t set_temp2_crit_hyst(struct device *dev, struct device_attribute *dummy,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
long val = simple_strtol(buf, NULL, 10);
long hyst;
mutex_lock(&data->update_lock);
hyst = TEMP8_FROM_REG(data->temp8[2]) + data->temp2_offset - val;
i2c_smbus_write_byte_data(client, LM63_REG_REMOTE_TCRIT_HYST,
HYST_TO_REG(hyst));
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *dummy,
char *buf)
{
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%u\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
int bitnr = attr->index;
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static int lm63_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
u8 man_id, chip_id, reg_config1, reg_config2;
u8 reg_alert_status, reg_alert_mask;
int address = new_client->addr;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
man_id = i2c_smbus_read_byte_data(new_client, LM63_REG_MAN_ID);
chip_id = i2c_smbus_read_byte_data(new_client, LM63_REG_CHIP_ID);
reg_config1 = i2c_smbus_read_byte_data(new_client,
LM63_REG_CONFIG1);
reg_config2 = i2c_smbus_read_byte_data(new_client,
LM63_REG_CONFIG2);
reg_alert_status = i2c_smbus_read_byte_data(new_client,
LM63_REG_ALERT_STATUS);
reg_alert_mask = i2c_smbus_read_byte_data(new_client,
LM63_REG_ALERT_MASK);
if (man_id != 0x01
|| (reg_config1 & 0x18) != 0x00
|| (reg_config2 & 0xF8) != 0x00
|| (reg_alert_status & 0x20) != 0x00
|| (reg_alert_mask & 0xA4) != 0xA4) {
dev_dbg(&adapter->dev,
"Unsupported chip (man_id=0x%02X, chip_id=0x%02X)\n",
man_id, chip_id);
return -ENODEV;
}
if (chip_id == 0x41 && address == 0x4c)
strlcpy(info->type, "lm63", I2C_NAME_SIZE);
else if (chip_id == 0x51 && (address == 0x18 || address == 0x4e))
strlcpy(info->type, "lm64", I2C_NAME_SIZE);
else
return -ENODEV;
return 0;
}
static int lm63_probe(struct i2c_client *new_client,
const struct i2c_device_id *id)
{
struct lm63_data *data;
int err;
data = kzalloc(sizeof(struct lm63_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(new_client, data);
data->valid = 0;
mutex_init(&data->update_lock);
data->kind = id->driver_data;
if (data->kind == lm64)
data->temp2_offset = 16000;
lm63_init_client(new_client);
if ((err = sysfs_create_group(&new_client->dev.kobj,
&lm63_group)))
goto exit_free;
if (data->config & 0x04) {
if ((err = sysfs_create_group(&new_client->dev.kobj,
&lm63_group_fan1)))
goto exit_remove_files;
}
data->hwmon_dev = hwmon_device_register(&new_client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&new_client->dev.kobj, &lm63_group);
sysfs_remove_group(&new_client->dev.kobj, &lm63_group_fan1);
exit_free:
kfree(data);
exit:
return err;
}
static void lm63_init_client(struct i2c_client *client)
{
struct lm63_data *data = i2c_get_clientdata(client);
data->config = i2c_smbus_read_byte_data(client, LM63_REG_CONFIG1);
data->config_fan = i2c_smbus_read_byte_data(client,
LM63_REG_CONFIG_FAN);
if (data->config & 0x40) {
dev_dbg(&client->dev, "Switching to operational mode\n");
data->config &= 0xA7;
i2c_smbus_write_byte_data(client, LM63_REG_CONFIG1,
data->config);
}
data->pwm1_freq = i2c_smbus_read_byte_data(client, LM63_REG_PWM_FREQ);
if (data->pwm1_freq == 0)
data->pwm1_freq = 1;
dev_dbg(&client->dev, "Alert/tach pin configured for %s\n",
(data->config & 0x04) ? "tachometer input" :
"alert output");
dev_dbg(&client->dev, "PWM clock %s kHz, output frequency %u Hz\n",
(data->config_fan & 0x08) ? "1.4" : "360",
((data->config_fan & 0x08) ? 700 : 180000) / data->pwm1_freq);
dev_dbg(&client->dev, "PWM output active %s, %s mode\n",
(data->config_fan & 0x10) ? "low" : "high",
(data->config_fan & 0x20) ? "manual" : "auto");
}
static int lm63_remove(struct i2c_client *client)
{
struct lm63_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm63_group);
sysfs_remove_group(&client->dev.kobj, &lm63_group_fan1);
kfree(data);
return 0;
}
static struct lm63_data *lm63_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
if (data->config & 0x04) {
data->fan[0] = i2c_smbus_read_byte_data(client,
LM63_REG_TACH_COUNT_LSB) & 0xFC;
data->fan[0] |= i2c_smbus_read_byte_data(client,
LM63_REG_TACH_COUNT_MSB) << 8;
data->fan[1] = (i2c_smbus_read_byte_data(client,
LM63_REG_TACH_LIMIT_LSB) & 0xFC)
| (i2c_smbus_read_byte_data(client,
LM63_REG_TACH_LIMIT_MSB) << 8);
}
data->pwm1_freq = i2c_smbus_read_byte_data(client,
LM63_REG_PWM_FREQ);
if (data->pwm1_freq == 0)
data->pwm1_freq = 1;
data->pwm1_value = i2c_smbus_read_byte_data(client,
LM63_REG_PWM_VALUE);
data->temp8[0] = i2c_smbus_read_byte_data(client,
LM63_REG_LOCAL_TEMP);
data->temp8[1] = i2c_smbus_read_byte_data(client,
LM63_REG_LOCAL_HIGH);
data->temp11[0] = i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_TEMP_MSB) << 8;
data->temp11[0] |= i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_TEMP_LSB);
data->temp11[1] = (i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_LOW_MSB) << 8)
| i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_LOW_LSB);
data->temp11[2] = (i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_HIGH_MSB) << 8)
| i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_HIGH_LSB);
data->temp8[2] = i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_TCRIT);
data->temp2_crit_hyst = i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_TCRIT_HYST);
data->alarms = i2c_smbus_read_byte_data(client,
LM63_REG_ALERT_STATUS) & 0x7F;
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init sensors_lm63_init(void)
{
return i2c_add_driver(&lm63_driver);
}
static void __exit sensors_lm63_exit(void)
{
i2c_del_driver(&lm63_driver);
}
