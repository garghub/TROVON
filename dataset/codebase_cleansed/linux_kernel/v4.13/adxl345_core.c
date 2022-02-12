static int adxl345_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct adxl345_data *data = iio_priv(indio_dev);
__le16 regval;
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = regmap_bulk_read(data->regmap, chan->address, &regval,
sizeof(regval));
if (ret < 0)
return ret;
*val = sign_extend32(le16_to_cpu(regval), 12);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = adxl345_uscale;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
int adxl345_core_probe(struct device *dev, struct regmap *regmap,
const char *name)
{
struct adxl345_data *data;
struct iio_dev *indio_dev;
u32 regval;
int ret;
ret = regmap_read(regmap, ADXL345_REG_DEVID, &regval);
if (ret < 0) {
dev_err(dev, "Error reading device ID: %d\n", ret);
return ret;
}
if (regval != ADXL345_DEVID) {
dev_err(dev, "Invalid device ID: %x, expected %x\n",
regval, ADXL345_DEVID);
return -ENODEV;
}
indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
dev_set_drvdata(dev, indio_dev);
data->regmap = regmap;
data->data_range = ADXL345_DATA_FORMAT_FULL_RES;
ret = regmap_write(data->regmap, ADXL345_REG_DATA_FORMAT,
data->data_range);
if (ret < 0) {
dev_err(dev, "Failed to set data range: %d\n", ret);
return ret;
}
indio_dev->dev.parent = dev;
indio_dev->name = name;
indio_dev->info = &adxl345_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = adxl345_channels;
indio_dev->num_channels = ARRAY_SIZE(adxl345_channels);
ret = regmap_write(data->regmap, ADXL345_REG_POWER_CTL,
ADXL345_POWER_CTL_MEASURE);
if (ret < 0) {
dev_err(dev, "Failed to enable measurement mode: %d\n", ret);
return ret;
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(dev, "iio_device_register failed: %d\n", ret);
regmap_write(data->regmap, ADXL345_REG_POWER_CTL,
ADXL345_POWER_CTL_STANDBY);
}
return ret;
}
int adxl345_core_remove(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct adxl345_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
return regmap_write(data->regmap, ADXL345_REG_POWER_CTL,
ADXL345_POWER_CTL_STANDBY);
}
