static ssize_t als_sensing_range_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
int val;
val = i2c_smbus_read_byte_data(client, 0x00);
if (val < 0)
return val;
return sprintf(buf, "%d000\n", 1 << (2 * (val & 3)));
}
static ssize_t als_lux_input_data_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
int ret_val, val;
unsigned long int lux;
int temp;
pm_runtime_get_sync(dev);
msleep(100);
mutex_lock(&mutex);
temp = i2c_smbus_read_byte_data(client, 0x02);
if (temp < 0) {
pm_runtime_put_sync(dev);
mutex_unlock(&mutex);
return temp;
}
ret_val = i2c_smbus_read_byte_data(client, 0x01);
mutex_unlock(&mutex);
if (ret_val < 0) {
pm_runtime_put_sync(dev);
return ret_val;
}
ret_val |= temp << 8;
val = i2c_smbus_read_byte_data(client, 0x00);
pm_runtime_put_sync(dev);
if (val < 0)
return val;
lux = ((((1 << (2 * (val & 3))))*1000) * ret_val) / 65536;
return sprintf(buf, "%ld\n", lux);
}
static ssize_t als_sensing_range_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
int ret_val;
unsigned long val;
ret_val = kstrtoul(buf, 10, &val);
if (ret_val)
return ret_val;
if (val < 1 || val > 64000)
return -EINVAL;
if (val <= 1000)
val = 1;
else if (val <= 4000)
val = 2;
else if (val <= 16000)
val = 3;
else
val = 4;
ret_val = i2c_smbus_read_byte_data(client, 0x00);
if (ret_val < 0)
return ret_val;
ret_val &= 0xFC;
ret_val |= val - 1;
ret_val = i2c_smbus_write_byte_data(client, 0x00, ret_val);
if (ret_val < 0)
return ret_val;
return count;
}
static void als_set_power_state(struct i2c_client *client, int enable)
{
int ret_val;
ret_val = i2c_smbus_read_byte_data(client, 0x00);
if (ret_val < 0)
return;
if (enable)
ret_val |= 0x80;
else
ret_val &= 0x7F;
i2c_smbus_write_byte_data(client, 0x00, ret_val);
}
static int als_set_default_config(struct i2c_client *client)
{
int retval;
retval = i2c_smbus_write_byte_data(client, 0x00, 0xc0);
if (retval < 0) {
dev_err(&client->dev, "default write failed.");
return retval;
}
return 0;
}
static int isl29020_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int res;
res = als_set_default_config(client);
if (res < 0)
return res;
res = sysfs_create_group(&client->dev.kobj, &m_als_gr);
if (res) {
dev_err(&client->dev, "isl29020: device create file failed\n");
return res;
}
dev_info(&client->dev, "%s isl29020: ALS chip found\n", client->name);
als_set_power_state(client, 0);
pm_runtime_enable(&client->dev);
return res;
}
static int isl29020_remove(struct i2c_client *client)
{
sysfs_remove_group(&client->dev.kobj, &m_als_gr);
return 0;
}
static int isl29020_runtime_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
als_set_power_state(client, 0);
return 0;
}
static int isl29020_runtime_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
als_set_power_state(client, 1);
return 0;
}
