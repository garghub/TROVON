static int shtc1_update_values(struct i2c_client *client,
struct shtc1_data *data,
char *buf, int bufsize)
{
int ret = i2c_master_send(client, data->command, SHTC1_CMD_LENGTH);
if (ret != SHTC1_CMD_LENGTH) {
dev_err(&client->dev, "failed to send command: %d\n", ret);
return ret < 0 ? ret : -EIO;
}
if (!data->setup.blocking_io)
usleep_range(data->nonblocking_wait_time,
data->nonblocking_wait_time + 1000);
ret = i2c_master_recv(client, buf, bufsize);
if (ret != bufsize) {
dev_err(&client->dev, "failed to read values: %d\n", ret);
return ret < 0 ? ret : -EIO;
}
return 0;
}
static struct shtc1_data *shtc1_update_client(struct device *dev)
{
struct shtc1_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned char buf[SHTC1_RESPONSE_LENGTH];
int val;
int ret = 0;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ / 10) || !data->valid) {
ret = shtc1_update_values(client, data, buf, sizeof(buf));
if (ret)
goto out;
val = be16_to_cpup((__be16 *)buf);
data->temperature = ((21875 * val) >> 13) - 45000;
val = be16_to_cpup((__be16 *)(buf + 3));
data->humidity = ((12500 * val) >> 13);
data->last_updated = jiffies;
data->valid = true;
}
out:
mutex_unlock(&data->update_lock);
return ret == 0 ? data : ERR_PTR(ret);
}
static ssize_t temp1_input_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct shtc1_data *data = shtc1_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", data->temperature);
}
static ssize_t humidity1_input_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct shtc1_data *data = shtc1_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", data->humidity);
}
static void shtc1_select_command(struct shtc1_data *data)
{
if (data->setup.high_precision) {
data->command = data->setup.blocking_io ?
shtc1_cmd_measure_blocking_hpm :
shtc1_cmd_measure_nonblocking_hpm;
data->nonblocking_wait_time = SHTC1_NONBLOCKING_WAIT_TIME_HPM;
} else {
data->command = data->setup.blocking_io ?
shtc1_cmd_measure_blocking_lpm :
shtc1_cmd_measure_nonblocking_lpm;
data->nonblocking_wait_time = SHTC1_NONBLOCKING_WAIT_TIME_LPM;
}
}
static int shtc1_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
char id_reg[2];
struct shtc1_data *data;
struct device *hwmon_dev;
struct i2c_adapter *adap = client->adapter;
struct device *dev = &client->dev;
if (!i2c_check_functionality(adap, I2C_FUNC_I2C)) {
dev_err(dev, "plain i2c transactions not supported\n");
return -ENODEV;
}
ret = i2c_master_send(client, shtc1_cmd_read_id_reg, SHTC1_CMD_LENGTH);
if (ret != SHTC1_CMD_LENGTH) {
dev_err(dev, "could not send read_id_reg command: %d\n", ret);
return ret < 0 ? ret : -ENODEV;
}
ret = i2c_master_recv(client, id_reg, sizeof(id_reg));
if (ret != sizeof(id_reg)) {
dev_err(dev, "could not read ID register: %d\n", ret);
return -ENODEV;
}
if ((id_reg[1] & SHTC1_ID_REG_MASK) != SHTC1_ID) {
dev_err(dev, "ID register doesn't match\n");
return -ENODEV;
}
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->setup.blocking_io = false;
data->setup.high_precision = true;
data->client = client;
if (client->dev.platform_data)
data->setup = *(struct shtc1_platform_data *)dev->platform_data;
shtc1_select_command(data);
mutex_init(&data->update_lock);
hwmon_dev = devm_hwmon_device_register_with_groups(dev,
client->name,
data,
shtc1_groups);
if (IS_ERR(hwmon_dev))
dev_dbg(dev, "unable to register hwmon device\n");
return PTR_ERR_OR_ZERO(hwmon_dev);
}
