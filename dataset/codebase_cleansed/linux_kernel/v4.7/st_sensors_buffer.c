int st_sensors_get_buffer_element(struct iio_dev *indio_dev, u8 *buf)
{
int i, len;
int total = 0;
struct st_sensor_data *sdata = iio_priv(indio_dev);
unsigned int num_data_channels = sdata->num_data_channels;
for (i = 0; i < num_data_channels; i++) {
unsigned int bytes_to_read;
if (test_bit(i, indio_dev->active_scan_mask)) {
bytes_to_read = indio_dev->channels[i].scan_type.storagebits >> 3;
len = sdata->tf->read_multiple_byte(&sdata->tb,
sdata->dev, indio_dev->channels[i].address,
bytes_to_read,
buf + total, sdata->multiread_bit);
if (len < bytes_to_read)
return -EIO;
total += len;
}
}
return total;
}
irqreturn_t st_sensors_trigger_handler(int irq, void *p)
{
int len;
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct st_sensor_data *sdata = iio_priv(indio_dev);
s64 timestamp;
if (sdata->hw_irq_trigger)
timestamp = sdata->hw_timestamp;
else
timestamp = iio_get_time_ns();
len = st_sensors_get_buffer_element(indio_dev, sdata->buffer_data);
if (len < 0)
goto st_sensors_get_buffer_element_error;
iio_push_to_buffers_with_timestamp(indio_dev, sdata->buffer_data,
timestamp);
st_sensors_get_buffer_element_error:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
