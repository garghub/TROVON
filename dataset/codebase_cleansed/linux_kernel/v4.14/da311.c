static int da311_register_mask_write(struct i2c_client *client, u16 addr,
u8 mask, u8 data)
{
int ret;
u8 tmp_data = 0;
if (addr & 0xff00) {
ret = i2c_smbus_write_byte_data(client, DA311_REG_BANK, 0x01);
if (ret < 0)
return ret;
}
if (mask != 0xff) {
ret = i2c_smbus_read_byte_data(client, addr);
if (ret < 0)
return ret;
tmp_data = ret;
}
tmp_data &= ~mask;
tmp_data |= data & mask;
ret = i2c_smbus_write_byte_data(client, addr & 0xff, tmp_data);
if (ret < 0)
return ret;
if (addr & 0xff00) {
ret = i2c_smbus_write_byte_data(client, DA311_REG_BANK, 0x00);
if (ret < 0)
return ret;
}
return 0;
}
static int da311_reset(struct i2c_client *client)
{
static const struct {
u16 addr;
u8 mask;
u8 data;
} init_data[] = {
{ DA311_REG_TEMP_CFG_REG, 0xff, 0x08 },
{ DA311_REG_CTRL_REG5, 0xff, 0x80 },
{ DA311_REG_CTRL_REG4, 0x30, 0x00 },
{ DA311_REG_CTRL_REG1, 0xff, 0x6f },
{ DA311_REG_TEMP_CFG_REG, 0xff, 0x88 },
{ DA311_REG_LDO_REG, 0xff, 0x02 },
{ DA311_REG_OTP_TRIM_OSC, 0xff, 0x27 },
{ DA311_REG_LPF_ABSOLUTE, 0xff, 0x30 },
{ DA311_REG_TEMP_OFF1, 0xff, 0x3f },
{ DA311_REG_TEMP_OFF2, 0xff, 0xff },
{ DA311_REG_TEMP_OFF3, 0xff, 0x0f },
};
int i, ret;
ret = da311_register_mask_write(client, DA311_REG_SOFT_RESET,
0xff, 0xaa);
if (ret < 0)
return ret;
for (i = 0; i < ARRAY_SIZE(init_data); i++) {
ret = da311_register_mask_write(client,
init_data[i].addr,
init_data[i].mask,
init_data[i].data);
if (ret < 0)
return ret;
}
return 0;
}
static int da311_enable(struct i2c_client *client, bool enable)
{
u8 data = enable ? 0x00 : 0x20;
return da311_register_mask_write(client, DA311_REG_TEMP_CFG_REG,
0x20, data);
}
static int da311_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct da311_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = i2c_smbus_read_word_data(data->client, chan->address);
if (ret < 0)
return ret;
*val = (short)ret >> 4;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = da311_nscale;
return IIO_VAL_INT_PLUS_NANO;
default:
return -EINVAL;
}
}
static int da311_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct da311_data *data;
ret = i2c_smbus_read_byte_data(client, DA311_REG_CHIP_ID);
if (ret != DA311_CHIP_ID)
return (ret < 0) ? ret : -ENODEV;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
data->client = client;
i2c_set_clientdata(client, indio_dev);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &da311_info;
indio_dev->name = "da311";
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = da311_channels;
indio_dev->num_channels = ARRAY_SIZE(da311_channels);
ret = da311_reset(client);
if (ret < 0)
return ret;
ret = da311_enable(client, true);
if (ret < 0)
return ret;
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "device_register failed\n");
da311_enable(client, false);
}
return ret;
}
static int da311_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
return da311_enable(client, false);
}
static int da311_suspend(struct device *dev)
{
return da311_enable(to_i2c_client(dev), false);
}
static int da311_resume(struct device *dev)
{
return da311_enable(to_i2c_client(dev), true);
}
