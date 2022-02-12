static inline u8 channel_cmd_byte(int ch)
{
u8 cmd = (((ch>>1) | (ch&0x01)<<2)<<4);
cmd |= ads7828_cmd_byte;
return cmd;
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
u8 cmd = channel_cmd_byte(ch);
data->adc_input[ch] =
i2c_smbus_read_word_swapped(client, cmd);
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_in(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ads7828_data *data = ads7828_update_device(dev);
return sprintf(buf, "%d\n", (data->adc_input[attr->index] *
ads7828_lsb_resol)/1000);
}
static int ads7828_remove(struct i2c_client *client)
{
struct ads7828_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &ads7828_group);
kfree(i2c_get_clientdata(client));
return 0;
}
static int ads7828_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int ch;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_READ_WORD_DATA))
return -ENODEV;
for (ch = 0; ch < ADS7828_NCH; ch++) {
u16 in_data;
u8 cmd = channel_cmd_byte(ch);
in_data = i2c_smbus_read_word_swapped(client, cmd);
if (in_data & 0xF000) {
pr_debug("%s : Doesn't look like an ads7828 device\n",
__func__);
return -ENODEV;
}
}
strlcpy(info->type, "ads7828", I2C_NAME_SIZE);
return 0;
}
static int ads7828_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ads7828_data *data;
int err;
data = kzalloc(sizeof(struct ads7828_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
err = sysfs_create_group(&client->dev.kobj, &ads7828_group);
if (err)
goto exit_free;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
sysfs_remove_group(&client->dev.kobj, &ads7828_group);
exit_free:
kfree(data);
exit:
return err;
}
static int __init sensors_ads7828_init(void)
{
ads7828_cmd_byte = se_input ?
ADS7828_CMD_SD_SE : ADS7828_CMD_SD_DIFF;
ads7828_cmd_byte |= int_vref ?
ADS7828_CMD_PD3 : ADS7828_CMD_PD1;
ads7828_lsb_resol = (vref_mv*1000)/4096;
return i2c_add_driver(&ads7828_driver);
}
static void __exit sensors_ads7828_exit(void)
{
i2c_del_driver(&ads7828_driver);
}
