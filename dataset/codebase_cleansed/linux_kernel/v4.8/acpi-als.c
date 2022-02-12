static int acpi_als_read_value(struct acpi_als *als, char *prop, s32 *val)
{
unsigned long long temp_val;
acpi_status status;
status = acpi_evaluate_integer(als->device->handle, prop, NULL,
&temp_val);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Error reading ALS %s", prop));
return -EIO;
}
*val = temp_val;
return 0;
}
static void acpi_als_notify(struct acpi_device *device, u32 event)
{
struct iio_dev *indio_dev = acpi_driver_data(device);
struct acpi_als *als = iio_priv(indio_dev);
s32 *buffer = als->evt_buffer;
s64 time_ns = iio_get_time_ns(indio_dev);
s32 val;
int ret;
mutex_lock(&als->lock);
memset(buffer, 0, ACPI_ALS_EVT_BUFFER_SIZE);
switch (event) {
case ACPI_ALS_NOTIFY_ILLUMINANCE:
ret = acpi_als_read_value(als, ACPI_ALS_ILLUMINANCE, &val);
if (ret < 0)
goto out;
*buffer++ = val;
break;
default:
dev_dbg(&device->dev, "Unhandled ACPI ALS event (%08x)!\n",
event);
goto out;
}
iio_push_to_buffers_with_timestamp(indio_dev, als->evt_buffer, time_ns);
out:
mutex_unlock(&als->lock);
}
static int acpi_als_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct acpi_als *als = iio_priv(indio_dev);
s32 temp_val;
int ret;
if ((mask != IIO_CHAN_INFO_PROCESSED) && (mask != IIO_CHAN_INFO_RAW))
return -EINVAL;
if (chan->type != IIO_LIGHT)
return -EINVAL;
ret = acpi_als_read_value(als, ACPI_ALS_ILLUMINANCE, &temp_val);
if (ret < 0)
return ret;
*val = temp_val;
return IIO_VAL_INT;
}
static int acpi_als_add(struct acpi_device *device)
{
struct acpi_als *als;
struct iio_dev *indio_dev;
struct iio_buffer *buffer;
indio_dev = devm_iio_device_alloc(&device->dev, sizeof(*als));
if (!indio_dev)
return -ENOMEM;
als = iio_priv(indio_dev);
device->driver_data = indio_dev;
als->device = device;
mutex_init(&als->lock);
indio_dev->name = ACPI_ALS_DEVICE_NAME;
indio_dev->dev.parent = &device->dev;
indio_dev->info = &acpi_als_info;
indio_dev->modes = INDIO_BUFFER_SOFTWARE;
indio_dev->channels = acpi_als_channels;
indio_dev->num_channels = ARRAY_SIZE(acpi_als_channels);
buffer = devm_iio_kfifo_allocate(&device->dev);
if (!buffer)
return -ENOMEM;
iio_device_attach_buffer(indio_dev, buffer);
return devm_iio_device_register(&device->dev, indio_dev);
}
