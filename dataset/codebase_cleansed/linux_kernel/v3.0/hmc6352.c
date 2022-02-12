static int compass_command(struct i2c_client *c, u8 cmd)
{
int ret = i2c_master_send(c, &cmd, 1);
if (ret < 0)
dev_warn(&c->dev, "command '%c' failed.\n", cmd);
return ret;
}
static int compass_store(struct device *dev, const char *buf, size_t count,
const char *map)
{
struct i2c_client *c = to_i2c_client(dev);
int ret;
unsigned long val;
if (strict_strtoul(buf, 10, &val))
return -EINVAL;
if (val >= strlen(map))
return -EINVAL;
mutex_lock(&compass_mutex);
ret = compass_command(c, map[val]);
mutex_unlock(&compass_mutex);
if (ret < 0)
return ret;
return count;
}
static ssize_t compass_calibration_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
return compass_store(dev, buf, count, "EC");
}
static ssize_t compass_power_mode_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
return compass_store(dev, buf, count, "SW");
}
static ssize_t compass_heading_data_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned char i2c_data[2];
int ret;
mutex_lock(&compass_mutex);
ret = compass_command(client, 'A');
if (ret != 1) {
mutex_unlock(&compass_mutex);
return ret;
}
msleep(10);
ret = i2c_master_recv(client, i2c_data, 2);
mutex_unlock(&compass_mutex);
if (ret < 0) {
dev_warn(dev, "i2c read data cmd failed\n");
return ret;
}
ret = (i2c_data[0] << 8) | i2c_data[1];
return sprintf(buf, "%d.%d\n", ret/10, ret%10);
}
static int hmc6352_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int res;
res = sysfs_create_group(&client->dev.kobj, &m_compass_gr);
if (res) {
dev_err(&client->dev, "device_create_file failed\n");
return res;
}
dev_info(&client->dev, "%s HMC6352 compass chip found\n",
client->name);
return 0;
}
static int hmc6352_remove(struct i2c_client *client)
{
sysfs_remove_group(&client->dev.kobj, &m_compass_gr);
return 0;
}
static int __init sensor_hmc6352_init(void)
{
return i2c_add_driver(&hmc6352_driver);
}
static void __exit sensor_hmc6352_exit(void)
{
i2c_del_driver(&hmc6352_driver);
}
