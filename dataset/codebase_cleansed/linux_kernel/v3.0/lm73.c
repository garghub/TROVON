static ssize_t set_temp(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct i2c_client *client = to_i2c_client(dev);
long temp;
short value;
int status = strict_strtol(buf, 10, &temp);
if (status < 0)
return status;
value = (short) SENSORS_LIMIT(temp/250, (LM73_TEMP_MIN*4),
(LM73_TEMP_MAX*4)) << 5;
i2c_smbus_write_word_data(client, attr->index, swab16(value));
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct i2c_client *client = to_i2c_client(dev);
int temp = ((s16) (swab16(i2c_smbus_read_word_data(client,
attr->index)))*250) / 32;
return sprintf(buf, "%d\n", temp);
}
static int
lm73_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct device *hwmon_dev;
int status;
status = sysfs_create_group(&client->dev.kobj, &lm73_group);
if (status)
return status;
hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(hwmon_dev)) {
status = PTR_ERR(hwmon_dev);
goto exit_remove;
}
i2c_set_clientdata(client, hwmon_dev);
dev_info(&client->dev, "%s: sensor '%s'\n",
dev_name(hwmon_dev), client->name);
return 0;
exit_remove:
sysfs_remove_group(&client->dev.kobj, &lm73_group);
return status;
}
static int lm73_remove(struct i2c_client *client)
{
struct device *hwmon_dev = i2c_get_clientdata(client);
hwmon_device_unregister(hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm73_group);
return 0;
}
static int lm73_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
u16 id;
u8 ctrl;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
id = i2c_smbus_read_word_data(new_client, LM73_REG_ID);
ctrl = i2c_smbus_read_byte_data(new_client, LM73_REG_CTRL);
if ((id != LM73_ID) || (ctrl & 0x10))
return -ENODEV;
strlcpy(info->type, "lm73", I2C_NAME_SIZE);
return 0;
}
static int __init sensors_lm73_init(void)
{
return i2c_add_driver(&lm73_driver);
}
static void __exit sensors_lm73_exit(void)
{
i2c_del_driver(&lm73_driver);
}
