static int temp_from_reg10(int val)
{
return val * 250;
}
static int temp_from_reg(int val)
{
return val * 1000;
}
static int temp_to_reg(int val)
{
return val / 1000;
}
static void max6642_init_client(struct i2c_client *client)
{
u8 config;
struct max6642_data *data = i2c_get_clientdata(client);
config = i2c_smbus_read_byte_data(client, MAX6642_REG_R_CONFIG);
if (config & 0x40)
i2c_smbus_write_byte_data(client, MAX6642_REG_W_CONFIG,
config & 0xBF);
data->temp_high[0] = i2c_smbus_read_byte_data(client,
MAX6642_REG_R_LOCAL_HIGH);
data->temp_high[1] = i2c_smbus_read_byte_data(client,
MAX6642_REG_R_REMOTE_HIGH);
}
static int max6642_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
u8 reg_config, reg_status, man_id;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
man_id = i2c_smbus_read_byte_data(client, MAX6642_REG_R_MAN_ID);
if (man_id != 0x4D)
return -ENODEV;
if (i2c_smbus_read_byte_data(client, 0x04) != 0x4D
|| i2c_smbus_read_byte_data(client, 0x06) != 0x4D
|| i2c_smbus_read_byte_data(client, 0xff) != 0x4D)
return -ENODEV;
reg_config = i2c_smbus_read_byte_data(client, MAX6642_REG_R_CONFIG);
if ((reg_config & 0x0f) != 0x00)
return -ENODEV;
if (i2c_smbus_read_byte_data(client, 0x04) != reg_config
|| i2c_smbus_read_byte_data(client, 0x06) != reg_config
|| i2c_smbus_read_byte_data(client, 0xff) != reg_config)
return -ENODEV;
reg_status = i2c_smbus_read_byte_data(client, MAX6642_REG_R_STATUS);
if ((reg_status & 0x2b) != 0x00)
return -ENODEV;
strlcpy(info->type, "max6642", I2C_NAME_SIZE);
return 0;
}
static struct max6642_data *max6642_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct max6642_data *data = i2c_get_clientdata(client);
u16 val, tmp;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
dev_dbg(&client->dev, "Updating max6642 data.\n");
val = i2c_smbus_read_byte_data(client,
MAX6642_REG_R_LOCAL_TEMPL);
tmp = (val >> 6) & 3;
val = i2c_smbus_read_byte_data(client,
MAX6642_REG_R_LOCAL_TEMP);
val = (val << 2) | tmp;
data->temp_input[0] = val;
val = i2c_smbus_read_byte_data(client,
MAX6642_REG_R_REMOTE_TEMPL);
tmp = (val >> 6) & 3;
val = i2c_smbus_read_byte_data(client,
MAX6642_REG_R_REMOTE_TEMP);
val = (val << 2) | tmp;
data->temp_input[1] = val;
data->alarms = i2c_smbus_read_byte_data(client,
MAX6642_REG_R_STATUS);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_temp_max10(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct max6642_data *data = max6642_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
return sprintf(buf, "%d\n",
temp_from_reg10(data->temp_input[attr->index]));
}
static ssize_t show_temp_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct max6642_data *data = max6642_update_device(dev);
struct sensor_device_attribute_2 *attr2 = to_sensor_dev_attr_2(attr);
return sprintf(buf, "%d\n", temp_from_reg(data->temp_high[attr2->nr]));
}
static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long val;
int err;
struct i2c_client *client = to_i2c_client(dev);
struct max6642_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute_2 *attr2 = to_sensor_dev_attr_2(attr);
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
mutex_lock(&data->update_lock);
data->temp_high[attr2->nr] = SENSORS_LIMIT(temp_to_reg(val), 0, 255);
i2c_smbus_write_byte_data(client, attr2->index,
data->temp_high[attr2->nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct max6642_data *data = max6642_update_device(dev);
return sprintf(buf, "%d\n", (data->alarms >> bitnr) & 1);
}
static int max6642_probe(struct i2c_client *new_client,
const struct i2c_device_id *id)
{
struct max6642_data *data;
int err;
data = kzalloc(sizeof(struct max6642_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(new_client, data);
mutex_init(&data->update_lock);
max6642_init_client(new_client);
err = sysfs_create_group(&new_client->dev.kobj, &max6642_group);
if (err)
goto exit_free;
data->hwmon_dev = hwmon_device_register(&new_client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&new_client->dev.kobj, &max6642_group);
exit_free:
kfree(data);
exit:
return err;
}
static int max6642_remove(struct i2c_client *client)
{
struct max6642_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &max6642_group);
kfree(data);
return 0;
}
static int __init max6642_init(void)
{
return i2c_add_driver(&max6642_driver);
}
static void __exit max6642_exit(void)
{
i2c_del_driver(&max6642_driver);
}
