static int ccs811_start_sensor_application(struct i2c_client *client)
{
int ret;
ret = i2c_smbus_read_byte_data(client, CCS811_STATUS);
if (ret < 0)
return ret;
if ((ret & CCS811_STATUS_APP_VALID_MASK) !=
CCS811_STATUS_APP_VALID_LOADED)
return -EIO;
ret = i2c_smbus_write_byte(client, CCS811_APP_START);
if (ret < 0)
return ret;
ret = i2c_smbus_read_byte_data(client, CCS811_STATUS);
if (ret < 0)
return ret;
if ((ret & CCS811_STATUS_FW_MODE_MASK) !=
CCS811_STATUS_FW_MODE_APPLICATION) {
dev_err(&client->dev, "Application failed to start. Sensor is still in boot mode.\n");
return -EIO;
}
return 0;
}
static int ccs811_setup(struct i2c_client *client)
{
int ret;
ret = ccs811_start_sensor_application(client);
if (ret < 0)
return ret;
return i2c_smbus_write_byte_data(client, CCS811_MEAS_MODE,
CCS811_MODE_IAQ_1SEC);
}
static int ccs811_get_measurement(struct ccs811_data *data)
{
int ret, tries = 11;
while (tries-- > 0) {
ret = i2c_smbus_read_byte_data(data->client, CCS811_STATUS);
if (ret < 0)
return ret;
if ((ret & CCS811_STATUS_DATA_READY) || tries == 0)
break;
msleep(100);
}
if (!(ret & CCS811_STATUS_DATA_READY))
return -EIO;
return i2c_smbus_read_i2c_block_data(data->client,
CCS811_ALG_RESULT_DATA, 8,
(char *)&data->buffer);
}
static int ccs811_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct ccs811_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&data->lock);
ret = ccs811_get_measurement(data);
if (ret < 0) {
mutex_unlock(&data->lock);
return ret;
}
switch (chan->type) {
case IIO_VOLTAGE:
*val = be16_to_cpu(data->buffer.resistance) &
CCS811_VOLTAGE_MASK;
ret = IIO_VAL_INT;
break;
case IIO_CURRENT:
*val = be16_to_cpu(data->buffer.resistance) >> 10;
ret = IIO_VAL_INT;
break;
case IIO_CONCENTRATION:
switch (chan->channel2) {
case IIO_MOD_CO2:
*val = be16_to_cpu(data->buffer.co2);
ret = IIO_VAL_INT;
break;
case IIO_MOD_VOC:
*val = be16_to_cpu(data->buffer.voc);
ret = IIO_VAL_INT;
break;
default:
ret = -EINVAL;
}
break;
default:
ret = -EINVAL;
}
mutex_unlock(&data->lock);
return ret;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_VOLTAGE:
*val = 1;
*val2 = 612903;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CURRENT:
*val = 0;
*val2 = 1000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CONCENTRATION:
switch (chan->channel2) {
case IIO_MOD_CO2:
*val = 0;
*val2 = 12834;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_MOD_VOC:
*val = 0;
*val2 = 84246;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
if (!(chan->type == IIO_CONCENTRATION &&
chan->channel2 == IIO_MOD_CO2))
return -EINVAL;
*val = -400;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static irqreturn_t ccs811_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ccs811_data *data = iio_priv(indio_dev);
struct i2c_client *client = data->client;
s16 buf[8];
int ret;
ret = i2c_smbus_read_i2c_block_data(client, CCS811_ALG_RESULT_DATA, 4,
(u8 *)&buf);
if (ret != 4) {
dev_err(&client->dev, "cannot read sensor data\n");
goto err;
}
iio_push_to_buffers_with_timestamp(indio_dev, buf,
iio_get_time_ns(indio_dev));
err:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int ccs811_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct ccs811_data *data;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WRITE_BYTE
| I2C_FUNC_SMBUS_BYTE_DATA
| I2C_FUNC_SMBUS_READ_I2C_BLOCK))
return -EOPNOTSUPP;
ret = i2c_smbus_read_byte_data(client, CCS811_HW_ID);
if (ret < 0)
return ret;
if (ret != CCS881_HW_ID_VALUE) {
dev_err(&client->dev, "hardware id doesn't match CCS81x\n");
return -ENODEV;
}
ret = i2c_smbus_read_byte_data(client, CCS811_HW_VERSION);
if (ret < 0)
return ret;
if ((ret & CCS811_HW_VERSION_MASK) != CCS811_HW_VERSION_VALUE) {
dev_err(&client->dev, "no CCS811 sensor\n");
return -ENODEV;
}
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
ret = ccs811_setup(client);
if (ret < 0)
return ret;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->name = id->name;
indio_dev->info = &ccs811_info;
indio_dev->channels = ccs811_channels;
indio_dev->num_channels = ARRAY_SIZE(ccs811_channels);
ret = iio_triggered_buffer_setup(indio_dev, NULL,
ccs811_trigger_handler, NULL);
if (ret < 0) {
dev_err(&client->dev, "triggered buffer setup failed\n");
goto err_poweroff;
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "unable to register iio device\n");
goto err_buffer_cleanup;
}
return 0;
err_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
err_poweroff:
i2c_smbus_write_byte_data(client, CCS811_MEAS_MODE, CCS811_MODE_IDLE);
return ret;
}
static int ccs811_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
return i2c_smbus_write_byte_data(client, CCS811_MEAS_MODE,
CCS811_MODE_IDLE);
}
