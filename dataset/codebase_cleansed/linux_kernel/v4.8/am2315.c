static u16 am2315_crc(u8 *data, u8 nr_bytes)
{
int i;
u16 crc = 0xffff;
while (nr_bytes--) {
crc ^= *data++;
for (i = 0; i < 8; i++) {
if (crc & 0x01) {
crc >>= 1;
crc ^= 0xA001;
} else {
crc >>= 1;
}
}
}
return crc;
}
static void am2315_ping(struct i2c_client *client)
{
i2c_smbus_read_byte_data(client, AM2315_REG_HUM_MSB);
}
static int am2315_read_data(struct am2315_data *data,
struct am2315_sensor_data *sensor_data)
{
int ret;
u8 tx_buf[3] = { AM2315_FUNCTION_READ, AM2315_REG_HUM_MSB, 4 };
u8 rx_buf[8];
u16 crc;
am2315_ping(data->client);
mutex_lock(&data->lock);
ret = i2c_master_send(data->client, tx_buf, sizeof(tx_buf));
if (ret < 0) {
dev_err(&data->client->dev, "failed to send read request\n");
goto exit_unlock;
}
usleep_range(2000, 3000);
ret = i2c_master_recv(data->client, rx_buf, sizeof(rx_buf));
if (ret < 0) {
dev_err(&data->client->dev, "failed to read sensor data\n");
goto exit_unlock;
}
mutex_unlock(&data->lock);
crc = am2315_crc(rx_buf, sizeof(rx_buf) - 2);
if ((crc & 0xff) != rx_buf[6] || (crc >> 8) != rx_buf[7]) {
dev_err(&data->client->dev, "failed to verify sensor data\n");
return -EIO;
}
sensor_data->hum_data = (rx_buf[AM2315_HUM_OFFSET] << 8) |
rx_buf[AM2315_HUM_OFFSET + 1];
sensor_data->temp_data = (rx_buf[AM2315_TEMP_OFFSET] << 8) |
rx_buf[AM2315_TEMP_OFFSET + 1];
return ret;
exit_unlock:
mutex_unlock(&data->lock);
return ret;
}
static irqreturn_t am2315_trigger_handler(int irq, void *p)
{
int i;
int ret;
int bit;
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct am2315_data *data = iio_priv(indio_dev);
struct am2315_sensor_data sensor_data;
ret = am2315_read_data(data, &sensor_data);
if (ret < 0)
goto err;
mutex_lock(&data->lock);
if (*(indio_dev->active_scan_mask) == AM2315_ALL_CHANNEL_MASK) {
data->buffer[0] = sensor_data.hum_data;
data->buffer[1] = sensor_data.temp_data;
} else {
i = 0;
for_each_set_bit(bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
data->buffer[i] = (bit ? sensor_data.temp_data :
sensor_data.hum_data);
i++;
}
}
mutex_unlock(&data->lock);
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
pf->timestamp);
err:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int am2315_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret;
struct am2315_sensor_data sensor_data;
struct am2315_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = am2315_read_data(data, &sensor_data);
if (ret < 0)
return ret;
*val = (chan->type == IIO_HUMIDITYRELATIVE) ?
sensor_data.hum_data : sensor_data.temp_data;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 100;
return IIO_VAL_INT;
}
return -EINVAL;
}
static int am2315_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct am2315_data *data;
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
indio_dev->info = &am2315_info;
indio_dev->name = AM2315_DRIVER_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = am2315_channels;
indio_dev->num_channels = ARRAY_SIZE(am2315_channels);
ret = iio_triggered_buffer_setup(indio_dev, iio_pollfunc_store_time,
am2315_trigger_handler, NULL);
if (ret < 0) {
dev_err(&client->dev, "iio triggered buffer setup failed\n");
return ret;
}
ret = iio_device_register(indio_dev);
if (ret < 0)
goto err_buffer_cleanup;
return 0;
err_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
return ret;
}
static int am2315_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
return 0;
}
