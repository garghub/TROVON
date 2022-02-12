static void humidity_adjust_channel_bit_mask(struct iio_chan_spec *channels,
int channel, int size)
{
channels[channel].scan_type.sign = 's';
channels[channel].scan_type.realbits = size * 8;
channels[channel].scan_type.storagebits = sizeof(s32) * 8;
}
static int humidity_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct hid_humidity_state *humid_st = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (chan->type != IIO_HUMIDITYRELATIVE)
return -EINVAL;
hid_sensor_power_state(&humid_st->common_attributes, true);
*val = sensor_hub_input_attr_get_raw_value(
humid_st->common_attributes.hsdev,
HID_USAGE_SENSOR_HUMIDITY,
HID_USAGE_SENSOR_ATMOSPHERIC_HUMIDITY,
humid_st->humidity_attr.report_id,
SENSOR_HUB_SYNC);
hid_sensor_power_state(&humid_st->common_attributes, false);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = humid_st->scale_pre_decml;
*val2 = humid_st->scale_post_decml;
return humid_st->scale_precision;
case IIO_CHAN_INFO_OFFSET:
*val = humid_st->value_offset;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SAMP_FREQ:
return hid_sensor_read_samp_freq_value(
&humid_st->common_attributes, val, val2);
case IIO_CHAN_INFO_HYSTERESIS:
return hid_sensor_read_raw_hyst_value(
&humid_st->common_attributes, val, val2);
default:
return -EINVAL;
}
}
static int humidity_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct hid_humidity_state *humid_st = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
return hid_sensor_write_samp_freq_value(
&humid_st->common_attributes, val, val2);
case IIO_CHAN_INFO_HYSTERESIS:
return hid_sensor_write_raw_hyst_value(
&humid_st->common_attributes, val, val2);
default:
return -EINVAL;
}
}
static int humidity_proc_event(struct hid_sensor_hub_device *hsdev,
unsigned int usage_id, void *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct hid_humidity_state *humid_st = iio_priv(indio_dev);
if (atomic_read(&humid_st->common_attributes.data_ready))
iio_push_to_buffers_with_timestamp(indio_dev,
&humid_st->humidity_data,
iio_get_time_ns(indio_dev));
return 0;
}
static int humidity_capture_sample(struct hid_sensor_hub_device *hsdev,
unsigned int usage_id, size_t raw_len,
char *raw_data, void *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct hid_humidity_state *humid_st = iio_priv(indio_dev);
switch (usage_id) {
case HID_USAGE_SENSOR_ATMOSPHERIC_HUMIDITY:
humid_st->humidity_data = *(s32 *)raw_data;
return 0;
default:
return -EINVAL;
}
}
static int humidity_parse_report(struct platform_device *pdev,
struct hid_sensor_hub_device *hsdev,
struct iio_chan_spec *channels,
unsigned int usage_id,
struct hid_humidity_state *st)
{
int ret;
ret = sensor_hub_input_get_attribute_info(hsdev, HID_INPUT_REPORT,
usage_id,
HID_USAGE_SENSOR_ATMOSPHERIC_HUMIDITY,
&st->humidity_attr);
if (ret < 0)
return ret;
humidity_adjust_channel_bit_mask(channels, 0, st->humidity_attr.size);
st->scale_precision = hid_sensor_format_scale(
HID_USAGE_SENSOR_HUMIDITY,
&st->humidity_attr,
&st->scale_pre_decml,
&st->scale_post_decml);
if (st->common_attributes.sensitivity.index < 0)
sensor_hub_input_get_attribute_info(hsdev,
HID_FEATURE_REPORT, usage_id,
HID_USAGE_SENSOR_DATA_MOD_CHANGE_SENSITIVITY_ABS |
HID_USAGE_SENSOR_ATMOSPHERIC_HUMIDITY,
&st->common_attributes.sensitivity);
return ret;
}
static int hid_humidity_probe(struct platform_device *pdev)
{
static const char *name = "humidity";
struct iio_dev *indio_dev;
struct hid_humidity_state *humid_st;
struct iio_chan_spec *humid_chans;
struct hid_sensor_hub_device *hsdev = dev_get_platdata(&pdev->dev);
int ret;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*humid_st));
if (!indio_dev)
return -ENOMEM;
humid_st = iio_priv(indio_dev);
humid_st->common_attributes.hsdev = hsdev;
humid_st->common_attributes.pdev = pdev;
ret = hid_sensor_parse_common_attributes(hsdev,
HID_USAGE_SENSOR_HUMIDITY,
&humid_st->common_attributes);
if (ret)
return ret;
humid_chans = devm_kmemdup(&indio_dev->dev, humidity_channels,
sizeof(humidity_channels), GFP_KERNEL);
if (!humid_chans)
return -ENOMEM;
ret = humidity_parse_report(pdev, hsdev, humid_chans,
HID_USAGE_SENSOR_HUMIDITY, humid_st);
if (ret)
return ret;
indio_dev->channels = humid_chans;
indio_dev->num_channels = ARRAY_SIZE(humidity_channels);
indio_dev->dev.parent = &pdev->dev;
indio_dev->info = &humidity_info;
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = devm_iio_triggered_buffer_setup(&pdev->dev, indio_dev,
&iio_pollfunc_store_time, NULL, NULL);
if (ret)
return ret;
atomic_set(&humid_st->common_attributes.data_ready, 0);
ret = hid_sensor_setup_trigger(indio_dev, name,
&humid_st->common_attributes);
if (ret)
return ret;
platform_set_drvdata(pdev, indio_dev);
humidity_callbacks.pdev = pdev;
ret = sensor_hub_register_callback(hsdev, HID_USAGE_SENSOR_HUMIDITY,
&humidity_callbacks);
if (ret)
goto error_remove_trigger;
ret = iio_device_register(indio_dev);
if (ret)
goto error_remove_callback;
return ret;
error_remove_callback:
sensor_hub_remove_callback(hsdev, HID_USAGE_SENSOR_HUMIDITY);
error_remove_trigger:
hid_sensor_remove_trigger(&humid_st->common_attributes);
return ret;
}
static int hid_humidity_remove(struct platform_device *pdev)
{
struct hid_sensor_hub_device *hsdev = dev_get_platdata(&pdev->dev);
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct hid_humidity_state *humid_st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
sensor_hub_remove_callback(hsdev, HID_USAGE_SENSOR_HUMIDITY);
hid_sensor_remove_trigger(&humid_st->common_attributes);
return 0;
}
