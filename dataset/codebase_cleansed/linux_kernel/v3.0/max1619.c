static int temp_from_reg(int val)
{
return (val & 0x80 ? val-0x100 : val) * 1000;
}
static int temp_to_reg(int val)
{
return (val < 0 ? val+0x100*1000 : val) / 1000;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *attr, char *buf)
{
struct max1619_data *data = max1619_update_device(dev);
return sprintf(buf, "%d\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct max1619_data *data = max1619_update_device(dev);
return sprintf(buf, "%d\n", (data->alarms >> bitnr) & 1);
}
static int max1619_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
u8 reg_config, reg_convrate, reg_status, man_id, chip_id;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
reg_config = i2c_smbus_read_byte_data(client, MAX1619_REG_R_CONFIG);
reg_convrate = i2c_smbus_read_byte_data(client, MAX1619_REG_R_CONVRATE);
reg_status = i2c_smbus_read_byte_data(client, MAX1619_REG_R_STATUS);
if ((reg_config & 0x03) != 0x00
|| reg_convrate > 0x07 || (reg_status & 0x61) != 0x00) {
dev_dbg(&adapter->dev, "MAX1619 detection failed at 0x%02x\n",
client->addr);
return -ENODEV;
}
man_id = i2c_smbus_read_byte_data(client, MAX1619_REG_R_MAN_ID);
chip_id = i2c_smbus_read_byte_data(client, MAX1619_REG_R_CHIP_ID);
if (man_id != 0x4D || chip_id != 0x04) {
dev_info(&adapter->dev,
"Unsupported chip (man_id=0x%02X, chip_id=0x%02X).\n",
man_id, chip_id);
return -ENODEV;
}
strlcpy(info->type, "max1619", I2C_NAME_SIZE);
return 0;
}
static int max1619_probe(struct i2c_client *new_client,
const struct i2c_device_id *id)
{
struct max1619_data *data;
int err;
data = kzalloc(sizeof(struct max1619_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(new_client, data);
data->valid = 0;
mutex_init(&data->update_lock);
max1619_init_client(new_client);
if ((err = sysfs_create_group(&new_client->dev.kobj, &max1619_group)))
goto exit_free;
data->hwmon_dev = hwmon_device_register(&new_client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&new_client->dev.kobj, &max1619_group);
exit_free:
kfree(data);
exit:
return err;
}
static void max1619_init_client(struct i2c_client *client)
{
u8 config;
i2c_smbus_write_byte_data(client, MAX1619_REG_W_CONVRATE,
5);
config = i2c_smbus_read_byte_data(client, MAX1619_REG_R_CONFIG);
if (config & 0x40)
i2c_smbus_write_byte_data(client, MAX1619_REG_W_CONFIG,
config & 0xBF);
}
static int max1619_remove(struct i2c_client *client)
{
struct max1619_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &max1619_group);
kfree(data);
return 0;
}
static struct max1619_data *max1619_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct max1619_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ * 2) || !data->valid) {
dev_dbg(&client->dev, "Updating max1619 data.\n");
data->temp_input1 = i2c_smbus_read_byte_data(client,
MAX1619_REG_R_LOCAL_TEMP);
data->temp_input2 = i2c_smbus_read_byte_data(client,
MAX1619_REG_R_REMOTE_TEMP);
data->temp_high2 = i2c_smbus_read_byte_data(client,
MAX1619_REG_R_REMOTE_HIGH);
data->temp_low2 = i2c_smbus_read_byte_data(client,
MAX1619_REG_R_REMOTE_LOW);
data->temp_crit2 = i2c_smbus_read_byte_data(client,
MAX1619_REG_R_REMOTE_CRIT);
data->temp_hyst2 = i2c_smbus_read_byte_data(client,
MAX1619_REG_R_TCRIT_HYST);
data->alarms = i2c_smbus_read_byte_data(client,
MAX1619_REG_R_STATUS);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init sensors_max1619_init(void)
{
return i2c_add_driver(&max1619_driver);
}
static void __exit sensors_max1619_exit(void)
{
i2c_del_driver(&max1619_driver);
}
