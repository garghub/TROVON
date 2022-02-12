static int adc081c_read_raw(struct iio_dev *iio,
struct iio_chan_spec const *channel, int *value,
int *shift, long mask)
{
struct adc081c *adc = iio_priv(iio);
int err;
switch (mask) {
case IIO_CHAN_INFO_RAW:
err = i2c_smbus_read_word_swapped(adc->i2c, REG_CONV_RES);
if (err < 0)
return err;
*value = (err >> 4) & 0xff;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
err = regulator_get_voltage(adc->ref);
if (err < 0)
return err;
*value = err / 1000;
*shift = 8;
return IIO_VAL_FRACTIONAL_LOG2;
default:
break;
}
return -EINVAL;
}
static int adc081c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *iio;
struct adc081c *adc;
int err;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
iio = iio_device_alloc(sizeof(*adc));
if (!iio)
return -ENOMEM;
adc = iio_priv(iio);
adc->i2c = client;
adc->ref = regulator_get(&client->dev, "vref");
if (IS_ERR(adc->ref)) {
err = PTR_ERR(adc->ref);
goto iio_free;
}
err = regulator_enable(adc->ref);
if (err < 0)
goto regulator_put;
iio->dev.parent = &client->dev;
iio->name = dev_name(&client->dev);
iio->modes = INDIO_DIRECT_MODE;
iio->info = &adc081c_info;
iio->channels = &adc081c_channel;
iio->num_channels = 1;
err = iio_device_register(iio);
if (err < 0)
goto regulator_disable;
i2c_set_clientdata(client, iio);
return 0;
regulator_disable:
regulator_disable(adc->ref);
regulator_put:
regulator_put(adc->ref);
iio_free:
iio_device_free(iio);
return err;
}
static int adc081c_remove(struct i2c_client *client)
{
struct iio_dev *iio = i2c_get_clientdata(client);
struct adc081c *adc = iio_priv(iio);
iio_device_unregister(iio);
regulator_disable(adc->ref);
regulator_put(adc->ref);
iio_device_free(iio);
return 0;
}
