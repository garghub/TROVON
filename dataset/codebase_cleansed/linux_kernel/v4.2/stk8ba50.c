static int stk8ba50_read_accel(struct stk8ba50_data *data, u8 reg)
{
int ret;
struct i2c_client *client = data->client;
ret = i2c_smbus_read_word_data(client, reg);
if (ret < 0) {
dev_err(&client->dev, "register read failed\n");
return ret;
}
return sign_extend32(ret >> STK8BA50_DATA_SHIFT, 9);
}
static int stk8ba50_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct stk8ba50_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&data->lock);
*val = stk8ba50_read_accel(data, chan->address);
mutex_unlock(&data->lock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = stk8ba50_scale_table[data->range][1];
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int stk8ba50_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
int ret;
int i;
int index = -1;
struct stk8ba50_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_SCALE:
if (val != 0)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(stk8ba50_scale_table); i++)
if (val2 == stk8ba50_scale_table[i][1]) {
index = i;
break;
}
if (index < 0)
return -EINVAL;
ret = i2c_smbus_write_byte_data(data->client,
STK8BA50_REG_RANGE,
stk8ba50_scale_table[index][0]);
if (ret < 0)
dev_err(&data->client->dev,
"failed to set measurement range\n");
else
data->range = index;
return ret;
}
return -EINVAL;
}
static int stk8ba50_set_power(struct stk8ba50_data *data, bool mode)
{
int ret;
u8 masked_reg;
struct i2c_client *client = data->client;
ret = i2c_smbus_read_byte_data(client, STK8BA50_REG_POWMODE);
if (ret < 0)
goto exit_err;
if (mode)
masked_reg = ret | STK8BA50_MODE_POWERBIT;
else
masked_reg = ret & (~STK8BA50_MODE_POWERBIT);
ret = i2c_smbus_write_byte_data(client, STK8BA50_REG_POWMODE,
masked_reg);
if (ret < 0)
goto exit_err;
return ret;
exit_err:
dev_err(&client->dev, "failed to change sensor mode\n");
return ret;
}
static int stk8ba50_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct stk8ba50_data *data;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev) {
dev_err(&client->dev, "iio allocation failed!\n");
return -ENOMEM;
}
data = iio_priv(indio_dev);
data->client = client;
i2c_set_clientdata(client, indio_dev);
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &stk8ba50_info;
indio_dev->name = STK8BA50_DRIVER_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = stk8ba50_channels;
indio_dev->num_channels = ARRAY_SIZE(stk8ba50_channels);
ret = i2c_smbus_write_byte_data(client,
STK8BA50_REG_SWRST, STK8BA50_RESET_CMD);
if (ret < 0) {
dev_err(&client->dev, "failed to reset sensor\n");
return ret;
}
data->range = 0;
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "device_register failed\n");
stk8ba50_set_power(data, STK8BA50_MODE_SUSPEND);
}
return ret;
}
static int stk8ba50_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
return stk8ba50_set_power(iio_priv(indio_dev), STK8BA50_MODE_SUSPEND);
}
static int stk8ba50_suspend(struct device *dev)
{
struct stk8ba50_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
return stk8ba50_set_power(data, STK8BA50_MODE_SUSPEND);
}
static int stk8ba50_resume(struct device *dev)
{
struct stk8ba50_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
return stk8ba50_set_power(data, STK8BA50_MODE_NORMAL);
}
