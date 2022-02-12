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
*value = (err & 0xFFF) >> (12 - adc->bits);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
err = regulator_get_voltage(adc->ref);
if (err < 0)
return err;
*value = err / 1000;
*shift = adc->bits;
return IIO_VAL_FRACTIONAL_LOG2;
default:
break;
}
return -EINVAL;
}
static irqreturn_t adc081c_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct adc081c *data = iio_priv(indio_dev);
u16 buf[8];
int ret;
ret = i2c_smbus_read_word_swapped(data->i2c, REG_CONV_RES);
if (ret < 0)
goto out;
buf[0] = ret;
iio_push_to_buffers_with_timestamp(indio_dev, buf,
iio_get_time_ns(indio_dev));
out:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int adc081c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *iio;
struct adc081c *adc;
struct adcxx1c_model *model;
int err;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -EOPNOTSUPP;
if (ACPI_COMPANION(&client->dev)) {
const struct acpi_device_id *ad_id;
ad_id = acpi_match_device(client->dev.driver->acpi_match_table,
&client->dev);
if (!ad_id)
return -ENODEV;
model = &adcxx1c_models[ad_id->driver_data];
} else {
model = &adcxx1c_models[id->driver_data];
}
iio = devm_iio_device_alloc(&client->dev, sizeof(*adc));
if (!iio)
return -ENOMEM;
adc = iio_priv(iio);
adc->i2c = client;
adc->bits = model->bits;
adc->ref = devm_regulator_get(&client->dev, "vref");
if (IS_ERR(adc->ref))
return PTR_ERR(adc->ref);
err = regulator_enable(adc->ref);
if (err < 0)
return err;
iio->dev.parent = &client->dev;
iio->dev.of_node = client->dev.of_node;
iio->name = dev_name(&client->dev);
iio->modes = INDIO_DIRECT_MODE;
iio->info = &adc081c_info;
iio->channels = model->channels;
iio->num_channels = ADC081C_NUM_CHANNELS;
err = iio_triggered_buffer_setup(iio, NULL, adc081c_trigger_handler, NULL);
if (err < 0) {
dev_err(&client->dev, "iio triggered buffer setup failed\n");
goto err_regulator_disable;
}
err = iio_device_register(iio);
if (err < 0)
goto err_buffer_cleanup;
i2c_set_clientdata(client, iio);
return 0;
err_buffer_cleanup:
iio_triggered_buffer_cleanup(iio);
err_regulator_disable:
regulator_disable(adc->ref);
return err;
}
static int adc081c_remove(struct i2c_client *client)
{
struct iio_dev *iio = i2c_get_clientdata(client);
struct adc081c *adc = iio_priv(iio);
iio_device_unregister(iio);
iio_triggered_buffer_cleanup(iio);
regulator_disable(adc->ref);
return 0;
}
