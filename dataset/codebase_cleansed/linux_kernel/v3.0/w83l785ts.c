static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct w83l785ts_data *data = w83l785ts_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[attr->index]));
}
static int w83l785ts_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
u16 man_id;
u8 chip_id;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if ((w83l785ts_read_value(client, W83L785TS_REG_CONFIG, 0) & 0x80)
|| (w83l785ts_read_value(client, W83L785TS_REG_TYPE, 0) & 0xFC)) {
dev_dbg(&adapter->dev,
"W83L785TS-S detection failed at 0x%02x\n",
client->addr);
return -ENODEV;
}
man_id = (w83l785ts_read_value(client, W83L785TS_REG_MAN_ID1, 0) << 8)
+ w83l785ts_read_value(client, W83L785TS_REG_MAN_ID2, 0);
chip_id = w83l785ts_read_value(client, W83L785TS_REG_CHIP_ID, 0);
if (man_id != 0x5CA3
|| chip_id != 0x70) {
dev_dbg(&adapter->dev,
"Unsupported chip (man_id=0x%04X, chip_id=0x%02X)\n",
man_id, chip_id);
return -ENODEV;
}
strlcpy(info->type, "w83l785ts", I2C_NAME_SIZE);
return 0;
}
static int w83l785ts_probe(struct i2c_client *new_client,
const struct i2c_device_id *id)
{
struct w83l785ts_data *data;
int err = 0;
data = kzalloc(sizeof(struct w83l785ts_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(new_client, data);
data->valid = 0;
mutex_init(&data->update_lock);
data->temp[1] = data->temp[0] = 0;
err = device_create_file(&new_client->dev,
&sensor_dev_attr_temp1_input.dev_attr);
if (err)
goto exit_remove;
err = device_create_file(&new_client->dev,
&sensor_dev_attr_temp1_max.dev_attr);
if (err)
goto exit_remove;
data->hwmon_dev = hwmon_device_register(&new_client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
device_remove_file(&new_client->dev,
&sensor_dev_attr_temp1_input.dev_attr);
device_remove_file(&new_client->dev,
&sensor_dev_attr_temp1_max.dev_attr);
kfree(data);
exit:
return err;
}
static int w83l785ts_remove(struct i2c_client *client)
{
struct w83l785ts_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
device_remove_file(&client->dev,
&sensor_dev_attr_temp1_input.dev_attr);
device_remove_file(&client->dev,
&sensor_dev_attr_temp1_max.dev_attr);
kfree(data);
return 0;
}
static u8 w83l785ts_read_value(struct i2c_client *client, u8 reg, u8 defval)
{
int value, i;
struct device *dev;
const char *prefix;
if (i2c_get_clientdata(client)) {
dev = &client->dev;
prefix = "";
} else {
dev = &client->adapter->dev;
prefix = "w83l785ts: ";
}
for (i = 1; i <= MAX_RETRIES; i++) {
value = i2c_smbus_read_byte_data(client, reg);
if (value >= 0) {
dev_dbg(dev, "%sRead 0x%02x from register 0x%02x.\n",
prefix, value, reg);
return value;
}
dev_dbg(dev, "%sRead failed, will retry in %d.\n", prefix, i);
msleep(i);
}
dev_err(dev, "%sCouldn't read value from register 0x%02x.\n", prefix,
reg);
return defval;
}
static struct w83l785ts_data *w83l785ts_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83l785ts_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (!data->valid || time_after(jiffies, data->last_updated + HZ * 2)) {
dev_dbg(&client->dev, "Updating w83l785ts data.\n");
data->temp[0] = w83l785ts_read_value(client,
W83L785TS_REG_TEMP, data->temp[0]);
data->temp[1] = w83l785ts_read_value(client,
W83L785TS_REG_TEMP_OVER, data->temp[1]);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init sensors_w83l785ts_init(void)
{
return i2c_add_driver(&w83l785ts_driver);
}
static void __exit sensors_w83l785ts_exit(void)
{
i2c_del_driver(&w83l785ts_driver);
}
