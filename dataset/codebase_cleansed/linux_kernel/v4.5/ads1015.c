static int ads1015_read_adc(struct i2c_client *client, unsigned int channel)
{
u16 config;
struct ads1015_data *data = i2c_get_clientdata(client);
unsigned int pga = data->channel_data[channel].pga;
unsigned int data_rate = data->channel_data[channel].data_rate;
unsigned int conversion_time_ms;
const unsigned int * const rate_table = data->id == ads1115 ?
data_rate_table_1115 : data_rate_table_1015;
int res;
mutex_lock(&data->update_lock);
res = i2c_smbus_read_word_swapped(client, ADS1015_CONFIG);
if (res < 0)
goto err_unlock;
config = res;
conversion_time_ms = DIV_ROUND_UP(1000, rate_table[data_rate]);
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
err_unlock:
mutex_unlock(&data->update_lock);
return res;
}
static int ads1015_reg_to_mv(struct i2c_client *client, unsigned int channel,
s16 reg)
{
struct ads1015_data *data = i2c_get_clientdata(client);
unsigned int pga = data->channel_data[channel].pga;
int fullscale = fullscale_table[pga];
const int mask = data->id == ads1115 ? 0x7fff : 0x7ff0;
return DIV_ROUND_CLOSEST(reg * fullscale, mask);
}
static ssize_t show_in(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct i2c_client *client = to_i2c_client(dev);
int res;
int index = attr->index;
res = ads1015_read_adc(client, index);
if (res < 0)
return res;
return sprintf(buf, "%d\n", ads1015_reg_to_mv(client, index, res));
}
static int ads1015_remove(struct i2c_client *client)
{
struct ads1015_data *data = i2c_get_clientdata(client);
int k;
hwmon_device_unregister(data->hwmon_dev);
for (k = 0; k < ADS1015_CHANNELS; ++k)
device_remove_file(&client->dev, &ads1015_in[k].dev_attr);
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
u32 pval;
unsigned int channel;
unsigned int pga = ADS1015_DEFAULT_PGA;
unsigned int data_rate = ADS1015_DEFAULT_DATA_RATE;
if (of_property_read_u32(node, "reg", &pval)) {
dev_err(&client->dev, "invalid reg on %s\n",
node->full_name);
continue;
}
channel = pval;
if (channel >= ADS1015_CHANNELS) {
dev_err(&client->dev,
"invalid channel index %d on %s\n",
channel, node->full_name);
continue;
}
if (!of_property_read_u32(node, "ti,gain", &pval)) {
pga = pval;
if (pga > 6) {
dev_err(&client->dev, "invalid gain on %s\n",
node->full_name);
return -EINVAL;
}
}
if (!of_property_read_u32(node, "ti,datarate", &pval)) {
data_rate = pval;
if (data_rate > 7) {
dev_err(&client->dev,
"invalid data_rate on %s\n",
node->full_name);
return -EINVAL;
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
data = devm_kzalloc(&client->dev, sizeof(struct ads1015_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
data->id = id->driver_data;
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
return err;
}
