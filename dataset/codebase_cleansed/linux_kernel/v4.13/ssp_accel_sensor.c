static int ssp_accel_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
u32 t;
struct ssp_data *data = dev_get_drvdata(indio_dev->dev.parent->parent);
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
t = ssp_get_sensor_delay(data, SSP_ACCELEROMETER_SENSOR);
ssp_convert_to_freq(t, val, val2);
return IIO_VAL_INT_PLUS_MICRO;
default:
break;
}
return -EINVAL;
}
static int ssp_accel_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val,
int val2, long mask)
{
int ret;
struct ssp_data *data = dev_get_drvdata(indio_dev->dev.parent->parent);
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
ret = ssp_convert_to_time(val, val2);
ret = ssp_change_delay(data, SSP_ACCELEROMETER_SENSOR, ret);
if (ret < 0)
dev_err(&indio_dev->dev, "accel sensor enable fail\n");
return ret;
default:
break;
}
return -EINVAL;
}
static int ssp_process_accel_data(struct iio_dev *indio_dev, void *buf,
int64_t timestamp)
{
return ssp_common_process_data(indio_dev, buf, SSP_ACCELEROMETER_SIZE,
timestamp);
}
static int ssp_accel_probe(struct platform_device *pdev)
{
int ret;
struct iio_dev *indio_dev;
struct ssp_sensor_data *spd;
struct iio_buffer *buffer;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*spd));
if (!indio_dev)
return -ENOMEM;
spd = iio_priv(indio_dev);
spd->process_data = ssp_process_accel_data;
spd->type = SSP_ACCELEROMETER_SENSOR;
indio_dev->name = ssp_accel_device_name;
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->info = &ssp_accel_iio_info;
indio_dev->modes = INDIO_BUFFER_SOFTWARE;
indio_dev->channels = ssp_acc_channels;
indio_dev->num_channels = ARRAY_SIZE(ssp_acc_channels);
indio_dev->available_scan_masks = ssp_accel_scan_mask;
buffer = devm_iio_kfifo_allocate(&pdev->dev);
if (!buffer)
return -ENOMEM;
iio_device_attach_buffer(indio_dev, buffer);
indio_dev->setup_ops = &ssp_accel_buffer_ops;
platform_set_drvdata(pdev, indio_dev);
ret = devm_iio_device_register(&pdev->dev, indio_dev);
if (ret < 0)
return ret;
ssp_register_consumer(indio_dev, SSP_ACCELEROMETER_SENSOR);
return 0;
}
