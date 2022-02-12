static int pem_read_block(struct i2c_client *client, u8 command, u8 *data,
int data_len)
{
u8 block_buffer[I2C_SMBUS_BLOCK_MAX];
int result;
result = i2c_smbus_read_block_data(client, command, block_buffer);
if (unlikely(result < 0))
goto abort;
if (unlikely(result == 0xff || result != data_len)) {
result = -EIO;
goto abort;
}
memcpy(data, block_buffer, data_len);
result = 0;
abort:
return result;
}
static struct pem_data *pem_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct pem_data *data = i2c_get_clientdata(client);
struct pem_data *ret = data;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
int result;
result = pem_read_block(client, PEM_READ_DATA_STRING,
data->data_string,
sizeof(data->data_string));
if (unlikely(result < 0)) {
ret = ERR_PTR(result);
goto abort;
}
if (data->input_length) {
result = pem_read_block(client, PEM_READ_INPUT_STRING,
data->input_string,
data->input_length);
if (unlikely(result < 0)) {
ret = ERR_PTR(result);
goto abort;
}
}
if (data->fans_supported) {
result = pem_read_block(client, PEM_READ_FAN_SPEED,
data->fan_speed,
sizeof(data->fan_speed));
if (unlikely(result < 0)) {
ret = ERR_PTR(result);
goto abort;
}
}
i2c_smbus_write_byte(client, PEM_CLEAR_INFO_FLAGS);
data->last_updated = jiffies;
data->valid = 1;
}
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static long pem_get_data(u8 *data, int len, int index)
{
long val;
switch (index) {
case PEM_DATA_VOUT_LSB:
val = (data[index] + (data[index+1] << 8)) * 5 / 2;
break;
case PEM_DATA_CURRENT:
val = data[index] * 200;
break;
case PEM_DATA_TEMP:
val = data[index] * 1000;
break;
case PEM_DATA_TEMP_MAX:
val = 97 * 1000;
break;
case PEM_DATA_TEMP_CRIT:
val = 107 * 1000;
break;
default:
WARN_ON_ONCE(1);
val = 0;
}
return val;
}
static long pem_get_input(u8 *data, int len, int index)
{
long val;
switch (index) {
case PEM_INPUT_VOLTAGE:
if (len == INPUT_STRING_LEN)
val = (data[index] + (data[index+1] << 8) - 75) * 1000;
else
val = (data[index] - 75) * 1000;
break;
case PEM_INPUT_POWER_LSB:
if (len == INPUT_STRING_LEN)
index++;
val = (data[index] + (data[index+1] << 8)) * 1000000L;
break;
default:
WARN_ON_ONCE(1);
val = 0;
}
return val;
}
static long pem_get_fan(u8 *data, int len, int index)
{
long val;
switch (index) {
case PEM_FAN_FAN1:
case PEM_FAN_FAN2:
case PEM_FAN_FAN3:
val = data[index] * 100;
break;
default:
WARN_ON_ONCE(1);
val = 0;
}
return val;
}
static ssize_t pem_show_bool(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(da);
struct pem_data *data = pem_update_device(dev);
u8 status;
if (IS_ERR(data))
return PTR_ERR(data);
status = data->data_string[attr->nr] & attr->index;
return snprintf(buf, PAGE_SIZE, "%d\n", !!status);
}
static ssize_t pem_show_data(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct pem_data *data = pem_update_device(dev);
long value;
if (IS_ERR(data))
return PTR_ERR(data);
value = pem_get_data(data->data_string, sizeof(data->data_string),
attr->index);
return snprintf(buf, PAGE_SIZE, "%ld\n", value);
}
static ssize_t pem_show_input(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct pem_data *data = pem_update_device(dev);
long value;
if (IS_ERR(data))
return PTR_ERR(data);
value = pem_get_input(data->input_string, sizeof(data->input_string),
attr->index);
return snprintf(buf, PAGE_SIZE, "%ld\n", value);
}
static ssize_t pem_show_fan(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct pem_data *data = pem_update_device(dev);
long value;
if (IS_ERR(data))
return PTR_ERR(data);
value = pem_get_fan(data->fan_speed, sizeof(data->fan_speed),
attr->index);
return snprintf(buf, PAGE_SIZE, "%ld\n", value);
}
static int pem_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct pem_data *data;
int ret;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BLOCK_DATA
| I2C_FUNC_SMBUS_WRITE_BYTE))
return -ENODEV;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
ret = pem_read_block(client, PEM_READ_FIRMWARE_REV,
data->firmware_rev, sizeof(data->firmware_rev));
if (ret < 0)
goto out_kfree;
ret = i2c_smbus_write_byte(client, PEM_CLEAR_INFO_FLAGS);
if (ret < 0)
goto out_kfree;
dev_info(&client->dev, "Firmware revision %d.%d.%d\n",
data->firmware_rev[0], data->firmware_rev[1],
data->firmware_rev[2]);
ret = sysfs_create_group(&client->dev.kobj, &pem_group);
if (ret)
goto out_kfree;
ret = pem_read_block(client, PEM_READ_INPUT_STRING,
data->input_string,
sizeof(data->input_string) - 1);
if (!ret && (data->input_string[0] || data->input_string[1] ||
data->input_string[2]))
data->input_length = sizeof(data->input_string) - 1;
else if (ret < 0) {
ret = pem_read_block(client, PEM_READ_INPUT_STRING,
data->input_string,
sizeof(data->input_string));
if (!ret && (data->input_string[0] || data->input_string[1] ||
data->input_string[2] || data->input_string[3]))
data->input_length = sizeof(data->input_string);
}
ret = 0;
if (data->input_length) {
ret = sysfs_create_group(&client->dev.kobj, &pem_input_group);
if (ret)
goto out_remove_groups;
}
ret = pem_read_block(client, PEM_READ_FAN_SPEED,
data->fan_speed,
sizeof(data->fan_speed));
if (!ret && (data->fan_speed[0] || data->fan_speed[1] ||
data->fan_speed[2] || data->fan_speed[3])) {
data->fans_supported = true;
ret = sysfs_create_group(&client->dev.kobj, &pem_fan_group);
if (ret)
goto out_remove_groups;
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
goto out_remove_groups;
}
return 0;
out_remove_groups:
sysfs_remove_group(&client->dev.kobj, &pem_input_group);
sysfs_remove_group(&client->dev.kobj, &pem_fan_group);
sysfs_remove_group(&client->dev.kobj, &pem_group);
out_kfree:
kfree(data);
return ret;
}
static int pem_remove(struct i2c_client *client)
{
struct pem_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &pem_input_group);
sysfs_remove_group(&client->dev.kobj, &pem_fan_group);
sysfs_remove_group(&client->dev.kobj, &pem_group);
kfree(data);
return 0;
}
static int __init pem_init(void)
{
return i2c_add_driver(&pem_driver);
}
static void __exit pem_exit(void)
{
i2c_del_driver(&pem_driver);
}
