static ssize_t als_sensing_range_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
int val;
val = i2c_smbus_read_byte_data(client, 0x81);
if (val < 0)
return val;
if (val & 1)
return sprintf(buf, "4095\n");
else
return sprintf(buf, "65535\n");
}
static int als_wait_for_data_ready(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
int ret;
int retry = 10;
do {
msleep(30);
ret = i2c_smbus_read_byte_data(client, 0x86);
} while (!(ret & 0x80) && retry--);
if (retry < 0) {
dev_warn(dev, "timeout waiting for data ready\n");
return -ETIMEDOUT;
}
return 0;
}
static ssize_t als_lux0_input_data_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct als_data *data = i2c_get_clientdata(client);
int ret_val;
int temp;
pm_runtime_get_sync(dev);
mutex_lock(&data->mutex);
i2c_smbus_write_byte(client, 0x40);
temp = i2c_smbus_read_byte_data(client, 0x81);
i2c_smbus_write_byte_data(client, 0x81, temp | 0x08);
ret_val = als_wait_for_data_ready(dev);
if (ret_val < 0)
goto failed;
temp = i2c_smbus_read_byte_data(client, 0x8C);
if (temp < 0) {
ret_val = temp;
goto failed;
}
ret_val = i2c_smbus_read_byte_data(client, 0x8D);
if (ret_val < 0)
goto failed;
mutex_unlock(&data->mutex);
pm_runtime_put_sync(dev);
temp = (ret_val << 8) | temp;
return sprintf(buf, "%d\n", temp);
failed:
mutex_unlock(&data->mutex);
pm_runtime_put_sync(dev);
return ret_val;
}
static ssize_t als_sensing_range_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct als_data *data = i2c_get_clientdata(client);
int ret_val;
unsigned long val;
if (strict_strtoul(buf, 10, &val))
return -EINVAL;
if (val < 4096)
val = 1;
else if (val < 65536)
val = 2;
else
return -ERANGE;
pm_runtime_get_sync(dev);
mutex_lock(&data->mutex);
ret_val = i2c_smbus_read_byte_data(client, 0x81);
if (ret_val < 0)
goto fail;
ret_val = ret_val & 0xFA;
if (val == 1)
ret_val = (ret_val | 0x01);
else
ret_val = (ret_val | 0x00);
ret_val = i2c_smbus_write_byte_data(client, 0x81, ret_val);
if (ret_val >= 0) {
mutex_unlock(&data->mutex);
pm_runtime_put_sync(dev);
return count;
}
fail:
mutex_unlock(&data->mutex);
pm_runtime_put_sync(dev);
return ret_val;
}
static int als_set_power_state(struct i2c_client *client, bool on_off)
{
int ret_val;
struct als_data *data = i2c_get_clientdata(client);
mutex_lock(&data->mutex);
ret_val = i2c_smbus_read_byte_data(client, 0x80);
if (ret_val < 0)
goto fail;
if (on_off)
ret_val = ret_val | 0x01;
else
ret_val = ret_val & 0xFE;
ret_val = i2c_smbus_write_byte_data(client, 0x80, ret_val);
fail:
mutex_unlock(&data->mutex);
return ret_val;
}
static int als_set_default_config(struct i2c_client *client)
{
int ret_val;
ret_val = i2c_smbus_write_byte_data(client, 0x80, 0x01);
if (ret_val < 0) {
dev_err(&client->dev, "failed default switch on write\n");
return ret_val;
}
ret_val = i2c_smbus_write_byte_data(client, 0x81, 0x08);
if (ret_val < 0)
dev_err(&client->dev, "failed default LUX on write\n");
als_wait_for_data_ready(&client->dev);
return ret_val;
}
static int apds9802als_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int res;
struct als_data *data;
data = kzalloc(sizeof(struct als_data), GFP_KERNEL);
if (data == NULL) {
dev_err(&client->dev, "Memory allocation failed\n");
return -ENOMEM;
}
i2c_set_clientdata(client, data);
res = sysfs_create_group(&client->dev.kobj, &m_als_gr);
if (res) {
dev_err(&client->dev, "device create file failed\n");
goto als_error1;
}
dev_info(&client->dev, "ALS chip found\n");
als_set_default_config(client);
mutex_init(&data->mutex);
pm_runtime_set_active(&client->dev);
pm_runtime_enable(&client->dev);
return res;
als_error1:
kfree(data);
return res;
}
static int apds9802als_remove(struct i2c_client *client)
{
struct als_data *data = i2c_get_clientdata(client);
pm_runtime_get_sync(&client->dev);
als_set_power_state(client, false);
sysfs_remove_group(&client->dev.kobj, &m_als_gr);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
kfree(data);
return 0;
}
static int apds9802als_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
als_set_power_state(client, false);
return 0;
}
static int apds9802als_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
als_set_power_state(client, true);
return 0;
}
