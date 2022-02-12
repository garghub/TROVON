static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm83_data *data = lm83_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[attr->index]));
}
static ssize_t set_temp(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct lm83_data *data = i2c_get_clientdata(client);
long val = simple_strtol(buf, NULL, 10);
int nr = attr->index;
mutex_lock(&data->update_lock);
data->temp[nr] = TEMP_TO_REG(val);
i2c_smbus_write_byte_data(client, LM83_REG_W_HIGH[nr - 4],
data->temp[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *dummy,
char *buf)
{
struct lm83_data *data = lm83_update_device(dev);
return sprintf(buf, "%d\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm83_data *data = lm83_update_device(dev);
int bitnr = attr->index;
return sprintf(buf, "%d\n", (data->alarms >> bitnr) & 1);
}
static int lm83_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
const char *name;
u8 man_id, chip_id;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if ((i2c_smbus_read_byte_data(new_client, LM83_REG_R_STATUS1) & 0xA8) ||
(i2c_smbus_read_byte_data(new_client, LM83_REG_R_STATUS2) & 0x48) ||
(i2c_smbus_read_byte_data(new_client, LM83_REG_R_CONFIG) & 0x41)) {
dev_dbg(&adapter->dev, "LM83 detection failed at 0x%02x\n",
new_client->addr);
return -ENODEV;
}
man_id = i2c_smbus_read_byte_data(new_client, LM83_REG_R_MAN_ID);
if (man_id != 0x01)
return -ENODEV;
chip_id = i2c_smbus_read_byte_data(new_client, LM83_REG_R_CHIP_ID);
switch (chip_id) {
case 0x03:
name = "lm83";
break;
case 0x01:
name = "lm82";
break;
default:
dev_info(&adapter->dev,
"Unsupported chip (man_id=0x%02X, chip_id=0x%02X)\n",
man_id, chip_id);
return -ENODEV;
}
strlcpy(info->type, name, I2C_NAME_SIZE);
return 0;
}
static int lm83_probe(struct i2c_client *new_client,
const struct i2c_device_id *id)
{
struct lm83_data *data;
int err;
data = kzalloc(sizeof(struct lm83_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(new_client, data);
data->valid = 0;
mutex_init(&data->update_lock);
if ((err = sysfs_create_group(&new_client->dev.kobj, &lm83_group)))
goto exit_free;
if (id->driver_data == lm83) {
if ((err = sysfs_create_group(&new_client->dev.kobj,
&lm83_group_opt)))
goto exit_remove_files;
}
data->hwmon_dev = hwmon_device_register(&new_client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&new_client->dev.kobj, &lm83_group);
sysfs_remove_group(&new_client->dev.kobj, &lm83_group_opt);
exit_free:
kfree(data);
exit:
return err;
}
static int lm83_remove(struct i2c_client *client)
{
struct lm83_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm83_group);
sysfs_remove_group(&client->dev.kobj, &lm83_group_opt);
kfree(data);
return 0;
}
static struct lm83_data *lm83_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm83_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ * 2) || !data->valid) {
int nr;
dev_dbg(&client->dev, "Updating lm83 data.\n");
for (nr = 0; nr < 9; nr++) {
data->temp[nr] =
i2c_smbus_read_byte_data(client,
LM83_REG_R_TEMP[nr]);
}
data->alarms =
i2c_smbus_read_byte_data(client, LM83_REG_R_STATUS1)
+ (i2c_smbus_read_byte_data(client, LM83_REG_R_STATUS2)
<< 8);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init sensors_lm83_init(void)
{
return i2c_add_driver(&lm83_driver);
}
static void __exit sensors_lm83_exit(void)
{
i2c_del_driver(&lm83_driver);
}
