static int mxc6255_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct mxc6255_data *data = iio_priv(indio_dev);
unsigned int reg;
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = regmap_read(data->regmap, chan->address, &reg);
if (ret < 0) {
dev_err(&data->client->dev,
"Error reading reg %lu\n", chan->address);
return ret;
}
*val = sign_extend32(reg, 7);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = MXC6255_SCALE;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static bool mxc6255_is_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case MXC6255_REG_XOUT:
case MXC6255_REG_YOUT:
case MXC6255_REG_CHIP_ID:
return true;
default:
return false;
}
}
static int mxc6255_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mxc6255_data *data;
struct iio_dev *indio_dev;
struct regmap *regmap;
unsigned int chip_id;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
regmap = devm_regmap_init_i2c(client, &mxc6255_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "Error initializing regmap\n");
return PTR_ERR(regmap);
}
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->regmap = regmap;
indio_dev->name = MXC6255_DRV_NAME;
indio_dev->dev.parent = &client->dev;
indio_dev->channels = mxc6255_channels;
indio_dev->num_channels = ARRAY_SIZE(mxc6255_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &mxc6255_info;
ret = regmap_read(data->regmap, MXC6255_REG_CHIP_ID, &chip_id);
if (ret < 0) {
dev_err(&client->dev, "Error reading chip id %d\n", ret);
return ret;
}
if (chip_id != MXC6255_CHIP_ID) {
dev_err(&client->dev, "Invalid chip id %x\n", chip_id);
return -ENODEV;
}
dev_dbg(&client->dev, "Chip id %x\n", chip_id);
ret = devm_iio_device_register(&client->dev, indio_dev);
if (ret < 0) {
dev_err(&client->dev, "Could not register IIO device\n");
return ret;
}
return 0;
}
