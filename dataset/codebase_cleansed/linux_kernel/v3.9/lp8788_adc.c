static int lp8788_get_adc_result(struct lp8788_adc *adc, enum lp8788_adc_id id,
int *val)
{
unsigned int msb;
unsigned int lsb;
unsigned int result;
u8 data;
u8 rawdata[2];
int size = ARRAY_SIZE(rawdata);
int retry = 5;
int ret;
data = (id << 1) | ADC_CONV_START;
ret = lp8788_write_byte(adc->lp, LP8788_ADC_CONF, data);
if (ret)
goto err_io;
data = 0;
while (retry--) {
usleep_range(100, 200);
ret = lp8788_read_byte(adc->lp, LP8788_ADC_DONE, &data);
if (ret)
goto err_io;
if (data)
break;
}
ret = lp8788_read_multi_bytes(adc->lp, LP8788_ADC_RAW, rawdata, size);
if (ret)
goto err_io;
msb = (rawdata[0] << 4) & 0x00000ff0;
lsb = (rawdata[1] >> 4) & 0x0000000f;
result = msb | lsb;
*val = result;
return 0;
err_io:
return ret;
}
static int lp8788_adc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct lp8788_adc *adc = iio_priv(indio_dev);
enum lp8788_adc_id id = chan->channel;
int ret;
mutex_lock(&adc->lock);
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = lp8788_get_adc_result(adc, id, val) ? -EIO : IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
*val = lp8788_scale[id] / 1000000;
*val2 = lp8788_scale[id] % 1000000;
ret = IIO_VAL_INT_PLUS_MICRO;
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&adc->lock);
return ret;
}
static int lp8788_iio_map_register(struct iio_dev *indio_dev,
struct lp8788_platform_data *pdata,
struct lp8788_adc *adc)
{
struct iio_map *map;
int ret;
map = (!pdata || !pdata->adc_pdata) ?
lp8788_default_iio_maps : pdata->adc_pdata;
ret = iio_map_array_register(indio_dev, map);
if (ret) {
dev_err(&indio_dev->dev, "iio map err: %d\n", ret);
return ret;
}
adc->map = map;
return 0;
}
static int lp8788_adc_probe(struct platform_device *pdev)
{
struct lp8788 *lp = dev_get_drvdata(pdev->dev.parent);
struct iio_dev *indio_dev;
struct lp8788_adc *adc;
int ret;
indio_dev = iio_device_alloc(sizeof(*adc));
if (!indio_dev)
return -ENOMEM;
adc = iio_priv(indio_dev);
adc->lp = lp;
platform_set_drvdata(pdev, indio_dev);
indio_dev->dev.of_node = pdev->dev.of_node;
ret = lp8788_iio_map_register(indio_dev, lp->pdata, adc);
if (ret)
goto err_iio_map;
mutex_init(&adc->lock);
indio_dev->dev.parent = &pdev->dev;
indio_dev->name = pdev->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &lp8788_adc_info;
indio_dev->channels = lp8788_adc_channels;
indio_dev->num_channels = ARRAY_SIZE(lp8788_adc_channels);
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&pdev->dev, "iio dev register err: %d\n", ret);
goto err_iio_device;
}
return 0;
err_iio_device:
iio_map_array_unregister(indio_dev);
err_iio_map:
iio_device_free(indio_dev);
return ret;
}
static int lp8788_adc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
iio_device_unregister(indio_dev);
iio_map_array_unregister(indio_dev);
iio_device_free(indio_dev);
return 0;
}
