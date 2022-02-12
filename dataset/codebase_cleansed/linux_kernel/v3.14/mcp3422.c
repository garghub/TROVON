static int mcp3422_update_config(struct mcp3422 *adc, u8 newconfig)
{
int ret;
mutex_lock(&adc->lock);
ret = i2c_master_send(adc->i2c, &newconfig, 1);
if (ret > 0) {
adc->config = newconfig;
ret = 0;
}
mutex_unlock(&adc->lock);
return ret;
}
static int mcp3422_read(struct mcp3422 *adc, int *value, u8 *config)
{
int ret = 0;
u8 sample_rate = MCP3422_SAMPLE_RATE(adc->config);
u8 buf[4] = {0, 0, 0, 0};
u32 temp;
if (sample_rate == MCP3422_SRATE_3) {
ret = i2c_master_recv(adc->i2c, buf, 4);
temp = buf[0] << 16 | buf[1] << 8 | buf[2];
*config = buf[3];
} else {
ret = i2c_master_recv(adc->i2c, buf, 3);
temp = buf[0] << 8 | buf[1];
*config = buf[2];
}
*value = sign_extend32(temp, mcp3422_sign_extend[sample_rate]);
return ret;
}
static int mcp3422_read_channel(struct mcp3422 *adc,
struct iio_chan_spec const *channel, int *value)
{
int ret;
u8 config;
u8 req_channel = channel->channel;
if (req_channel != MCP3422_CHANNEL(adc->config)) {
config = adc->config;
config &= ~MCP3422_CHANNEL_MASK;
config |= MCP3422_CHANNEL_VALUE(req_channel);
config &= ~MCP3422_PGA_MASK;
config |= MCP3422_PGA_VALUE(adc->pga[req_channel]);
ret = mcp3422_update_config(adc, config);
if (ret < 0)
return ret;
msleep(mcp3422_read_times[MCP3422_SAMPLE_RATE(adc->config)]);
}
return mcp3422_read(adc, value, &config);
}
static int mcp3422_read_raw(struct iio_dev *iio,
struct iio_chan_spec const *channel, int *val1,
int *val2, long mask)
{
struct mcp3422 *adc = iio_priv(iio);
int err;
u8 sample_rate = MCP3422_SAMPLE_RATE(adc->config);
u8 pga = MCP3422_PGA(adc->config);
switch (mask) {
case IIO_CHAN_INFO_RAW:
err = mcp3422_read_channel(adc, channel, val1);
if (err < 0)
return -EINVAL;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val1 = 0;
*val2 = mcp3422_scales[sample_rate][pga];
return IIO_VAL_INT_PLUS_NANO;
case IIO_CHAN_INFO_SAMP_FREQ:
*val1 = mcp3422_sample_rates[MCP3422_SAMPLE_RATE(adc->config)];
return IIO_VAL_INT;
default:
break;
}
return -EINVAL;
}
static int mcp3422_write_raw(struct iio_dev *iio,
struct iio_chan_spec const *channel, int val1,
int val2, long mask)
{
struct mcp3422 *adc = iio_priv(iio);
u8 temp;
u8 config = adc->config;
u8 req_channel = channel->channel;
u8 sample_rate = MCP3422_SAMPLE_RATE(config);
u8 i;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
if (val1 != 0)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(mcp3422_scales[0]); i++) {
if (val2 == mcp3422_scales[sample_rate][i]) {
adc->pga[req_channel] = i;
config &= ~MCP3422_CHANNEL_MASK;
config |= MCP3422_CHANNEL_VALUE(req_channel);
config &= ~MCP3422_PGA_MASK;
config |= MCP3422_PGA_VALUE(adc->pga[req_channel]);
return mcp3422_update_config(adc, config);
}
}
return -EINVAL;
case IIO_CHAN_INFO_SAMP_FREQ:
switch (val1) {
case 240:
temp = MCP3422_SRATE_240;
break;
case 60:
temp = MCP3422_SRATE_60;
break;
case 15:
temp = MCP3422_SRATE_15;
break;
case 3:
temp = MCP3422_SRATE_3;
break;
default:
return -EINVAL;
}
config &= ~MCP3422_CHANNEL_MASK;
config |= MCP3422_CHANNEL_VALUE(req_channel);
config &= ~MCP3422_SRATE_MASK;
config |= MCP3422_SAMPLE_RATE_VALUE(temp);
return mcp3422_update_config(adc, config);
default:
break;
}
return -EINVAL;
}
static int mcp3422_write_raw_get_fmt(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, long mask)
{
switch (mask) {
case IIO_CHAN_INFO_SCALE:
return IIO_VAL_INT_PLUS_NANO;
case IIO_CHAN_INFO_SAMP_FREQ:
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static ssize_t mcp3422_show_scales(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mcp3422 *adc = iio_priv(dev_to_iio_dev(dev));
u8 sample_rate = MCP3422_SAMPLE_RATE(adc->config);
return sprintf(buf, "0.%09u 0.%09u 0.%09u 0.%09u\n",
mcp3422_scales[sample_rate][0],
mcp3422_scales[sample_rate][1],
mcp3422_scales[sample_rate][2],
mcp3422_scales[sample_rate][3]);
}
static int mcp3422_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct mcp3422 *adc;
int err;
u8 config;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*adc));
if (!indio_dev)
return -ENOMEM;
adc = iio_priv(indio_dev);
adc->i2c = client;
mutex_init(&adc->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->name = dev_name(&client->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &mcp3422_info;
switch ((unsigned int)(id->driver_data)) {
case 2:
case 3:
indio_dev->channels = mcp3422_channels;
indio_dev->num_channels = ARRAY_SIZE(mcp3422_channels);
break;
case 4:
indio_dev->channels = mcp3424_channels;
indio_dev->num_channels = ARRAY_SIZE(mcp3424_channels);
break;
}
config = (MCP3422_CONT_SAMPLING
| MCP3422_CHANNEL_VALUE(1)
| MCP3422_PGA_VALUE(MCP3422_PGA_1)
| MCP3422_SAMPLE_RATE_VALUE(MCP3422_SRATE_240));
mcp3422_update_config(adc, config);
err = devm_iio_device_register(&client->dev, indio_dev);
if (err < 0)
return err;
i2c_set_clientdata(client, indio_dev);
return 0;
}
