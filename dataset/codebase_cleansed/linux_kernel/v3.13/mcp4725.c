static int mcp4725_suspend(struct device *dev)
{
struct mcp4725_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
u8 outbuf[2];
outbuf[0] = (data->powerdown_mode + 1) << 4;
outbuf[1] = 0;
data->powerdown = true;
return i2c_master_send(data->client, outbuf, 2);
}
static int mcp4725_resume(struct device *dev)
{
struct mcp4725_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
u8 outbuf[2];
outbuf[0] = (data->dac_value >> 8) & 0xf;
outbuf[1] = data->dac_value & 0xff;
data->powerdown = false;
return i2c_master_send(data->client, outbuf, 2);
}
static ssize_t mcp4725_store_eeprom(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct mcp4725_data *data = iio_priv(indio_dev);
int tries = 20;
u8 inoutbuf[3];
bool state;
int ret;
ret = strtobool(buf, &state);
if (ret < 0)
return ret;
if (!state)
return 0;
inoutbuf[0] = 0x60;
inoutbuf[1] = data->dac_value >> 4;
inoutbuf[2] = (data->dac_value & 0xf) << 4;
ret = i2c_master_send(data->client, inoutbuf, 3);
if (ret < 0)
return ret;
else if (ret != 3)
return -EIO;
while (tries--) {
msleep(20);
ret = i2c_master_recv(data->client, inoutbuf, 3);
if (ret < 0)
return ret;
else if (ret != 3)
return -EIO;
if (inoutbuf[0] & 0x80)
break;
}
if (tries < 0) {
dev_err(&data->client->dev,
"mcp4725_store_eeprom() failed, incomplete\n");
return -EIO;
}
return len;
}
static int mcp4725_get_powerdown_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct mcp4725_data *data = iio_priv(indio_dev);
return data->powerdown_mode;
}
static int mcp4725_set_powerdown_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned mode)
{
struct mcp4725_data *data = iio_priv(indio_dev);
data->powerdown_mode = mode;
return 0;
}
static ssize_t mcp4725_read_powerdown(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
struct mcp4725_data *data = iio_priv(indio_dev);
return sprintf(buf, "%d\n", data->powerdown);
}
static ssize_t mcp4725_write_powerdown(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan,
const char *buf, size_t len)
{
struct mcp4725_data *data = iio_priv(indio_dev);
bool state;
int ret;
ret = strtobool(buf, &state);
if (ret)
return ret;
if (state)
ret = mcp4725_suspend(&data->client->dev);
else
ret = mcp4725_resume(&data->client->dev);
if (ret < 0)
return ret;
return len;
}
static int mcp4725_set_value(struct iio_dev *indio_dev, int val)
{
struct mcp4725_data *data = iio_priv(indio_dev);
u8 outbuf[2];
int ret;
if (val >= (1 << 12) || val < 0)
return -EINVAL;
outbuf[0] = (val >> 8) & 0xf;
outbuf[1] = val & 0xff;
ret = i2c_master_send(data->client, outbuf, 2);
if (ret < 0)
return ret;
else if (ret != 2)
return -EIO;
else
return 0;
}
static int mcp4725_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct mcp4725_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
*val = data->dac_value;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = data->vref_mv;
*val2 = 12;
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static int mcp4725_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct mcp4725_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = mcp4725_set_value(indio_dev, val);
data->dac_value = val;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int mcp4725_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mcp4725_data *data;
struct iio_dev *indio_dev;
struct mcp4725_platform_data *platform_data = client->dev.platform_data;
u8 inbuf[3];
u8 pd;
int err;
if (!platform_data || !platform_data->vref_mv) {
dev_err(&client->dev, "invalid platform data");
return -EINVAL;
}
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (indio_dev == NULL)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &mcp4725_info;
indio_dev->channels = &mcp4725_channel;
indio_dev->num_channels = 1;
indio_dev->modes = INDIO_DIRECT_MODE;
data->vref_mv = platform_data->vref_mv;
err = i2c_master_recv(client, inbuf, 3);
if (err < 0) {
dev_err(&client->dev, "failed to read DAC value");
return err;
}
pd = (inbuf[0] >> 1) & 0x3;
data->powerdown = pd > 0 ? true : false;
data->powerdown_mode = pd ? pd-1 : 2;
data->dac_value = (inbuf[1] << 4) | (inbuf[2] >> 4);
return iio_device_register(indio_dev);
}
static int mcp4725_remove(struct i2c_client *client)
{
iio_device_unregister(i2c_get_clientdata(client));
return 0;
}
