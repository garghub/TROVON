int ssp_common_buffer_postenable(struct iio_dev *indio_dev)
{
struct ssp_sensor_data *spd = iio_priv(indio_dev);
struct ssp_data *data = dev_get_drvdata(indio_dev->dev.parent->parent);
spd->buffer = kmalloc(indio_dev->scan_bytes, GFP_KERNEL | GFP_DMA);
if (!spd->buffer)
return -ENOMEM;
return ssp_enable_sensor(data, spd->type,
ssp_get_sensor_delay(data, spd->type));
}
int ssp_common_buffer_postdisable(struct iio_dev *indio_dev)
{
int ret;
struct ssp_sensor_data *spd = iio_priv(indio_dev);
struct ssp_data *data = dev_get_drvdata(indio_dev->dev.parent->parent);
ret = ssp_disable_sensor(data, spd->type);
if (ret < 0)
return ret;
kfree(spd->buffer);
return ret;
}
int ssp_common_process_data(struct iio_dev *indio_dev, void *buf,
unsigned int len, int64_t timestamp)
{
__le32 time;
int64_t calculated_time;
struct ssp_sensor_data *spd = iio_priv(indio_dev);
if (indio_dev->scan_bytes == 0)
return 0;
memcpy(spd->buffer, buf, len);
if (indio_dev->scan_timestamp) {
memcpy(&time, &((char *)buf)[len], SSP_TIME_SIZE);
calculated_time =
timestamp + (int64_t)le32_to_cpu(time) * 1000000;
}
return iio_push_to_buffers_with_timestamp(indio_dev, spd->buffer,
calculated_time);
}
