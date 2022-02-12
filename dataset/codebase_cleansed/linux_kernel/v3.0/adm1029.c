static ssize_t
show_temp(struct device *dev, struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adm1029_data *data = adm1029_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[attr->index]));
}
static ssize_t
show_fan(struct device *dev, struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adm1029_data *data = adm1029_update_device(dev);
u16 val;
if (data->fan[attr->index] == 0
|| (data->fan_div[attr->index] & 0xC0) == 0
|| data->fan[attr->index] == 255) {
return sprintf(buf, "0\n");
}
val = 1880 * 120 / DIV_FROM_REG(data->fan_div[attr->index])
/ data->fan[attr->index];
return sprintf(buf, "%d\n", val);
}
static ssize_t
show_fan_div(struct device *dev, struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adm1029_data *data = adm1029_update_device(dev);
if ((data->fan_div[attr->index] & 0xC0) == 0)
return sprintf(buf, "0\n");
return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[attr->index]));
}
static ssize_t set_fan_div(struct device *dev,
struct device_attribute *devattr, const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1029_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
long val = simple_strtol(buf, NULL, 10);
u8 reg;
mutex_lock(&data->update_lock);
reg = i2c_smbus_read_byte_data(client,
ADM1029_REG_FAN_DIV[attr->index]);
switch (val) {
case 1:
val = 1;
break;
case 2:
val = 2;
break;
case 4:
val = 3;
break;
default:
mutex_unlock(&data->update_lock);
dev_err(&client->dev, "fan_div value %ld not "
"supported. Choose one of 1, 2 or 4!\n", val);
return -EINVAL;
}
reg = (reg & 0x3F) | (val << 6);
i2c_smbus_write_byte_data(client,
ADM1029_REG_FAN_DIV[attr->index], reg);
mutex_unlock(&data->update_lock);
return count;
}
static int adm1029_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
u8 man_id, chip_id, temp_devices_installed, nb_fan_support;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
man_id = i2c_smbus_read_byte_data(client, ADM1029_REG_MAN_ID);
chip_id = i2c_smbus_read_byte_data(client, ADM1029_REG_CHIP_ID);
temp_devices_installed = i2c_smbus_read_byte_data(client,
ADM1029_REG_TEMP_DEVICES_INSTALLED);
nb_fan_support = i2c_smbus_read_byte_data(client,
ADM1029_REG_NB_FAN_SUPPORT);
if (man_id != 0x41 || (temp_devices_installed & 0xf9) != 0x01
|| nb_fan_support != 0x03)
return -ENODEV;
if ((chip_id & 0xF0) != 0x00) {
pr_info("adm1029: Unknown major revision %x, "
"please let us know\n", chip_id);
return -ENODEV;
}
strlcpy(info->type, "adm1029", I2C_NAME_SIZE);
return 0;
}
static int adm1029_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adm1029_data *data;
int err;
data = kzalloc(sizeof(struct adm1029_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
if (adm1029_init_client(client) == 0) {
err = -ENODEV;
goto exit_free;
}
if ((err = sysfs_create_group(&client->dev.kobj, &adm1029_group)))
goto exit_free;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&client->dev.kobj, &adm1029_group);
exit_free:
kfree(data);
exit:
return err;
}
static int adm1029_init_client(struct i2c_client *client)
{
u8 config;
config = i2c_smbus_read_byte_data(client, ADM1029_REG_CONFIG);
if ((config & 0x10) == 0) {
i2c_smbus_write_byte_data(client, ADM1029_REG_CONFIG,
config | 0x10);
}
config = i2c_smbus_read_byte_data(client, ADM1029_REG_CONFIG);
if ((config & 0x10) == 0) {
dev_err(&client->dev, "Initialization failed!\n");
return 0;
}
return 1;
}
static int adm1029_remove(struct i2c_client *client)
{
struct adm1029_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &adm1029_group);
kfree(data);
return 0;
}
static struct adm1029_data *adm1029_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1029_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ * 2)
|| !data->valid) {
int nr;
dev_dbg(&client->dev, "Updating adm1029 data\n");
for (nr = 0; nr < ARRAY_SIZE(ADM1029_REG_TEMP); nr++) {
data->temp[nr] =
i2c_smbus_read_byte_data(client,
ADM1029_REG_TEMP[nr]);
}
for (nr = 0; nr < ARRAY_SIZE(ADM1029_REG_FAN); nr++) {
data->fan[nr] =
i2c_smbus_read_byte_data(client,
ADM1029_REG_FAN[nr]);
}
for (nr = 0; nr < ARRAY_SIZE(ADM1029_REG_FAN_DIV); nr++) {
data->fan_div[nr] =
i2c_smbus_read_byte_data(client,
ADM1029_REG_FAN_DIV[nr]);
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init sensors_adm1029_init(void)
{
return i2c_add_driver(&adm1029_driver);
}
static void __exit sensors_adm1029_exit(void)
{
i2c_del_driver(&adm1029_driver);
}
