static int stk8312_otp_init(struct stk8312_data *data)
{
int ret;
int count = 10;
struct i2c_client *client = data->client;
ret = i2c_smbus_write_byte_data(client, STK8312_REG_OTPADDR, 0x70);
if (ret < 0)
goto exit_err;
ret = i2c_smbus_write_byte_data(client, STK8312_REG_OTPCTRL, 0x02);
if (ret < 0)
goto exit_err;
do {
usleep_range(1000, 5000);
ret = i2c_smbus_read_byte_data(client, STK8312_REG_OTPCTRL);
if (ret < 0)
goto exit_err;
count--;
} while (!(ret & 0x80) && count > 0);
if (count == 0)
goto exit_err;
ret = i2c_smbus_read_byte_data(client, STK8312_REG_OTPDATA);
if (ret < 0)
goto exit_err;
ret = i2c_smbus_write_byte_data(data->client,
STK8312_REG_AFECTRL, ret);
if (ret < 0)
goto exit_err;
msleep(150);
return ret;
exit_err:
dev_err(&client->dev, "failed to initialize sensor\n");
return ret;
}
static int stk8312_set_mode(struct stk8312_data *data, u8 mode)
{
int ret;
u8 masked_reg;
struct i2c_client *client = data->client;
if (mode > 1)
return -EINVAL;
else if (mode == data->mode)
return 0;
ret = i2c_smbus_read_byte_data(client, STK8312_REG_MODE);
if (ret < 0) {
dev_err(&client->dev, "failed to change sensor mode\n");
return ret;
}
masked_reg = ret & (~STK8312_MODE_MASK);
masked_reg |= mode;
ret = i2c_smbus_write_byte_data(client,
STK8312_REG_MODE, masked_reg);
if (ret < 0) {
dev_err(&client->dev, "failed to change sensor mode\n");
return ret;
}
data->mode = mode;
if (mode == STK8312_MODE_ACTIVE) {
usleep_range(1000, 5000);
ret = stk8312_otp_init(data);
}
return ret;
}
static int stk8312_set_range(struct stk8312_data *data, u8 range)
{
int ret;
u8 masked_reg;
u8 mode;
struct i2c_client *client = data->client;
if (range != 1 && range != 2)
return -EINVAL;
else if (range == data->range)
return 0;
mode = data->mode;
ret = stk8312_set_mode(data, STK8312_MODE_STANDBY);
if (ret < 0)
return ret;
ret = i2c_smbus_read_byte_data(client, STK8312_REG_STH);
if (ret < 0) {
dev_err(&client->dev, "failed to change sensor range\n");
return ret;
}
masked_reg = ret & (~STK8312_RNG_MASK);
masked_reg |= range << STK8312_RNG_SHIFT;
ret = i2c_smbus_write_byte_data(client, STK8312_REG_STH, masked_reg);
if (ret < 0)
dev_err(&client->dev, "failed to change sensor range\n");
else
data->range = range;
return stk8312_set_mode(data, mode);
}
static int stk8312_read_accel(struct stk8312_data *data, u8 address)
{
int ret;
struct i2c_client *client = data->client;
if (address > 2)
return -EINVAL;
ret = i2c_smbus_read_byte_data(client, address);
if (ret < 0) {
dev_err(&client->dev, "register read failed\n");
return ret;
}
return sign_extend32(ret, 7);
}
static int stk8312_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct stk8312_data *data = iio_priv(indio_dev);
if (chan->type != IIO_ACCEL)
return -EINVAL;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&data->lock);
*val = stk8312_read_accel(data, chan->address);
mutex_unlock(&data->lock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = stk8312_scale_table[data->range - 1][0];
*val2 = stk8312_scale_table[data->range - 1][1];
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int stk8312_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
int i;
int index = -1;
int ret;
struct stk8312_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_SCALE:
for (i = 0; i < ARRAY_SIZE(stk8312_scale_table); i++)
if (val == stk8312_scale_table[i][0] &&
val2 == stk8312_scale_table[i][1]) {
index = i + 1;
break;
}
if (index < 0)
return -EINVAL;
mutex_lock(&data->lock);
ret = stk8312_set_range(data, index);
mutex_unlock(&data->lock);
return ret;
}
return -EINVAL;
}
static int stk8312_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct stk8312_data *data;
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
indio_dev->info = &stk8312_info;
indio_dev->name = STK8312_DRIVER_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = stk8312_channels;
indio_dev->num_channels = ARRAY_SIZE(stk8312_channels);
ret = i2c_smbus_write_byte_data(data->client, STK8312_REG_RESET, 0x00);
if (ret < 0) {
dev_err(&client->dev, "failed to reset sensor\n");
return ret;
}
ret = stk8312_set_range(data, 1);
if (ret < 0)
return ret;
ret = stk8312_set_mode(data, STK8312_MODE_ACTIVE);
if (ret < 0)
return ret;
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "device_register failed\n");
stk8312_set_mode(data, STK8312_MODE_STANDBY);
}
return ret;
}
static int stk8312_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
return stk8312_set_mode(iio_priv(indio_dev), STK8312_MODE_STANDBY);
}
static int stk8312_suspend(struct device *dev)
{
struct stk8312_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
return stk8312_set_mode(data, STK8312_MODE_STANDBY);
}
static int stk8312_resume(struct device *dev)
{
struct stk8312_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
return stk8312_set_mode(data, STK8312_MODE_ACTIVE);
}
