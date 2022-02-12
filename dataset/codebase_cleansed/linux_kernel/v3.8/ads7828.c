static inline u8 ads7828_cmd_byte(u8 cmd, int ch)
{
return cmd | (((ch >> 1) | (ch & 0x01) << 2) << 4);
}
static struct ads7828_data *ads7828_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ads7828_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
unsigned int ch;
dev_dbg(&client->dev, "Starting ads7828 update\n");
for (ch = 0; ch < ADS7828_NCH; ch++) {
u8 cmd = ads7828_cmd_byte(data->cmd_byte, ch);
data->adc_input[ch] = data->read_channel(client, cmd);
}
data->last_updated = jiffies;
data->valid = true;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t ads7828_show_in(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ads7828_data *data = ads7828_update_device(dev);
unsigned int value = DIV_ROUND_CLOSEST(data->adc_input[attr->index] *
data->lsb_resol, 1000);
return sprintf(buf, "%d\n", value);
}
static int ads7828_remove(struct i2c_client *client)
{
struct ads7828_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &ads7828_group);
return 0;
}
static int ads7828_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ads7828_platform_data *pdata = client->dev.platform_data;
struct ads7828_data *data;
int err;
data = devm_kzalloc(&client->dev, sizeof(struct ads7828_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
if (pdata) {
data->diff_input = pdata->diff_input;
data->ext_vref = pdata->ext_vref;
if (data->ext_vref)
data->vref_mv = pdata->vref_mv;
}
if (data->vref_mv)
data->vref_mv = SENSORS_LIMIT(data->vref_mv,
ADS7828_EXT_VREF_MV_MIN,
ADS7828_EXT_VREF_MV_MAX);
else
data->vref_mv = ADS7828_INT_VREF_MV;
if (id->driver_data == ads7828) {
data->lsb_resol = DIV_ROUND_CLOSEST(data->vref_mv * 1000, 4096);
data->read_channel = i2c_smbus_read_word_swapped;
} else {
data->lsb_resol = DIV_ROUND_CLOSEST(data->vref_mv * 1000, 256);
data->read_channel = i2c_smbus_read_byte_data;
}
data->cmd_byte = data->ext_vref ? ADS7828_CMD_PD1 : ADS7828_CMD_PD3;
if (!data->diff_input)
data->cmd_byte |= ADS7828_CMD_SD_SE;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
err = sysfs_create_group(&client->dev.kobj, &ads7828_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error;
}
return 0;
error:
sysfs_remove_group(&client->dev.kobj, &ads7828_group);
return err;
}
