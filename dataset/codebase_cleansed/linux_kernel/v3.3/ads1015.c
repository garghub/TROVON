static int ads1015_read_value(struct i2c_client *client, unsigned int channel,
int *value)
{
u16 config;
s16 conversion;
struct ads1015_data *data = i2c_get_clientdata(client);
unsigned int pga = data->channel_data[channel].pga;
int fullscale;
unsigned int data_rate = data->channel_data[channel].data_rate;
unsigned int conversion_time_ms;
int res;
mutex_lock(&data->update_lock);
res = i2c_smbus_read_word_swapped(client, ADS1015_CONFIG);
if (res < 0)
goto err_unlock;
config = res;
fullscale = fullscale_table[pga];
conversion_time_ms = DIV_ROUND_UP(1000, data_rate_table[data_rate]);
config &= 0x001f;
config |= (1 << 15) | (1 << 8);
config |= (channel & 0x0007) << 12;
config |= (pga & 0x0007) << 9;
config |= (data_rate & 0x0007) << 5;
res = i2c_smbus_write_word_swapped(client, ADS1015_CONFIG, config);
if (res < 0)
goto err_unlock;
msleep(conversion_time_ms);
res = i2c_smbus_read_word_swapped(client, ADS1015_CONFIG);
if (res < 0)
goto err_unlock;
config = res;
if (!(config & (1 << 15))) {
res = -EIO;
goto err_unlock;
}
res = i2c_smbus_read_word_swapped(client, ADS1015_CONVERSION);
if (res < 0)
goto err_unlock;
conversion = res;
mutex_unlock(&data->update_lock);
*value = DIV_ROUND_CLOSEST(conversion * fullscale, 0x7ff0);
return 0;
err_unlock:
mutex_unlock(&data->update_lock);
return res;
}
static ssize_t show_in(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct i2c_client *client = to_i2c_client(dev);
int in;
int res;
res = ads1015_read_value(client, attr->index, &in);
return (res < 0) ? res : sprintf(buf, "%d\n", in);
}
static int ads1015_remove(struct i2c_client *client)
{
struct ads1015_data *data = i2c_get_clientdata(client);
int k;
hwmon_device_unregister(data->hwmon_dev);
for (k = 0; k < ADS1015_CHANNELS; ++k)
device_remove_file(&client->dev, &ads1015_in[k].dev_attr);
kfree(data);
return 0;
}
static int ads1015_get_channels_config_of(struct i2c_client *client)
{
struct ads1015_data *data = i2c_get_clientdata(client);
struct device_node *node;
if (!client->dev.of_node
|| !of_get_next_child(client->dev.of_node, NULL))
return -EINVAL;
for_each_child_of_node(client->dev.of_node, node) {
const __be32 *property;
int len;
unsigned int channel;
unsigned int pga = ADS1015_DEFAULT_PGA;
unsigned int data_rate = ADS1015_DEFAULT_DATA_RATE;
property = of_get_property(node, "reg", &len);
if (!property || len != sizeof(int)) {
dev_err(&client->dev, "invalid reg on %s\n",
node->full_name);
continue;
}
channel = be32_to_cpup(property);
if (channel > ADS1015_CHANNELS) {
dev_err(&client->dev,
"invalid channel index %d on %s\n",
channel, node->full_name);
continue;
}
property = of_get_property(node, "ti,gain", &len);
if (property && len == sizeof(int)) {
pga = be32_to_cpup(property);
if (pga > 6) {
dev_err(&client->dev,
"invalid gain on %s\n",
node->full_name);
}
}
property = of_get_property(node, "ti,datarate", &len);
if (property && len == sizeof(int)) {
data_rate = be32_to_cpup(property);
if (data_rate > 7) {
dev_err(&client->dev,
"invalid data_rate on %s\n",
node->full_name);
}
}
data->channel_data[channel].enabled = true;
data->channel_data[channel].pga = pga;
data->channel_data[channel].data_rate = data_rate;
}
return 0;
}
static void ads1015_get_channels_config(struct i2c_client *client)
{
unsigned int k;
struct ads1015_data *data = i2c_get_clientdata(client);
struct ads1015_platform_data *pdata = dev_get_platdata(&client->dev);
if (pdata) {
memcpy(data->channel_data, pdata->channel_data,
sizeof(data->channel_data));
return;
}
#ifdef CONFIG_OF
if (!ads1015_get_channels_config_of(client))
return;
#endif
for (k = 0; k < ADS1015_CHANNELS; ++k) {
data->channel_data[k].enabled = true;
data->channel_data[k].pga = ADS1015_DEFAULT_PGA;
data->channel_data[k].data_rate = ADS1015_DEFAULT_DATA_RATE;
}
}
static int ads1015_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ads1015_data *data;
int err;
unsigned int k;
data = kzalloc(sizeof(struct ads1015_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
ads1015_get_channels_config(client);
for (k = 0; k < ADS1015_CHANNELS; ++k) {
if (!data->channel_data[k].enabled)
continue;
err = device_create_file(&client->dev, &ads1015_in[k].dev_attr);
if (err)
goto exit_remove;
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
for (k = 0; k < ADS1015_CHANNELS; ++k)
device_remove_file(&client->dev, &ads1015_in[k].dev_attr);
kfree(data);
exit:
return err;
}
static int __init sensors_ads1015_init(void)
{
return i2c_add_driver(&ads1015_driver);
}
static void __exit sensors_ads1015_exit(void)
{
i2c_del_driver(&ads1015_driver);
}
