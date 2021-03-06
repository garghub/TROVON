static void temperature_adjust_channel_bit_mask(struct iio_chan_spec *channels,
int channel, int size)
{
channels[channel].scan_type.sign = 's';
channels[channel].scan_type.realbits = size * 8;
channels[channel].scan_type.storagebits = sizeof(s32) * 8;
}
static int temperature_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct temperature_state *temp_st = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (chan->type != IIO_TEMP)
return -EINVAL;
hid_sensor_power_state(
&temp_st->common_attributes, true);
*val = sensor_hub_input_attr_get_raw_value(
temp_st->common_attributes.hsdev,
HID_USAGE_SENSOR_TEMPERATURE,
HID_USAGE_SENSOR_DATA_ENVIRONMENTAL_TEMPERATURE,
temp_st->temperature_attr.report_id,
SENSOR_HUB_SYNC);
hid_sensor_power_state(
&temp_st->common_attributes,
false);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = temp_st->scale_pre_decml;
*val2 = temp_st->scale_post_decml;
return temp_st->scale_precision;
case IIO_CHAN_INFO_OFFSET:
*val = temp_st->value_offset;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SAMP_FREQ:
return hid_sensor_read_samp_freq_value(
&temp_st->common_attributes, val, val2);
case IIO_CHAN_INFO_HYSTERESIS:
return hid_sensor_read_raw_hyst_value(
&temp_st->common_attributes, val, val2);
default:
return -EINVAL;
}
}
static int temperature_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct temperature_state *temp_st = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
return hid_sensor_write_samp_freq_value(
&temp_st->common_attributes, val, val2);
case IIO_CHAN_INFO_HYSTERESIS:
return hid_sensor_write_raw_hyst_value(
&temp_st->common_attributes, val, val2);
default:
return -EINVAL;
}
}
static int temperature_proc_event(struct hid_sensor_hub_device *hsdev,
unsigned int usage_id, void *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct temperature_state *temp_st = iio_priv(indio_dev);
if (atomic_read(&temp_st->common_attributes.data_ready))
iio_push_to_buffers_with_timestamp(indio_dev,
&temp_st->temperature_data,
iio_get_time_ns(indio_dev));
return 0;
}
static int temperature_capture_sample(struct hid_sensor_hub_device *hsdev,
unsigned int usage_id, size_t raw_len,
char *raw_data, void *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct temperature_state *temp_st = iio_priv(indio_dev);
switch (usage_id) {
case HID_USAGE_SENSOR_DATA_ENVIRONMENTAL_TEMPERATURE:
temp_st->temperature_data = *(s32 *)raw_data;
return 0;
default:
return -EINVAL;
}
}
static int temperature_parse_report(struct platform_device *pdev,
struct hid_sensor_hub_device *hsdev,
struct iio_chan_spec *channels,
unsigned int usage_id,
struct temperature_state *st)
{
int ret;
ret = sensor_hub_input_get_attribute_info(hsdev, HID_INPUT_REPORT,
usage_id,
HID_USAGE_SENSOR_DATA_ENVIRONMENTAL_TEMPERATURE,
&st->temperature_attr);
if (ret < 0)
return ret;
temperature_adjust_channel_bit_mask(channels, 0,
st->temperature_attr.size);
st->scale_precision = hid_sensor_format_scale(
HID_USAGE_SENSOR_TEMPERATURE,
&st->temperature_attr,
&st->scale_pre_decml, &st->scale_post_decml);
if (st->common_attributes.sensitivity.index < 0)
sensor_hub_input_get_attribute_info(hsdev,
HID_FEATURE_REPORT, usage_id,
HID_USAGE_SENSOR_DATA_MOD_CHANGE_SENSITIVITY_ABS |
HID_USAGE_SENSOR_DATA_ENVIRONMENTAL_TEMPERATURE,
&st->common_attributes.sensitivity);
return ret;
}
static int hid_temperature_probe(struct platform_device *pdev)
{
static const char *name = "temperature";
struct iio_dev *indio_dev;
struct temperature_state *temp_st;
struct iio_chan_spec *temp_chans;
struct hid_sensor_hub_device *hsdev = dev_get_platdata(&pdev->dev);
int ret;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*temp_st));
if (!indio_dev)
return -ENOMEM;
temp_st = iio_priv(indio_dev);
temp_st->common_attributes.hsdev = hsdev;
temp_st->common_attributes.pdev = pdev;
ret = hid_sensor_parse_common_attributes(hsdev,
HID_USAGE_SENSOR_TEMPERATURE,
&temp_st->common_attributes);
if (ret)
return ret;
temp_chans = devm_kmemdup(&indio_dev->dev, temperature_channels,
sizeof(temperature_channels), GFP_KERNEL);
if (!temp_chans)
return -ENOMEM;
ret = temperature_parse_report(pdev, hsdev, temp_chans,
HID_USAGE_SENSOR_TEMPERATURE, temp_st);
if (ret)
return ret;
indio_dev->channels = temp_chans;
indio_dev->num_channels = ARRAY_SIZE(temperature_channels);
indio_dev->dev.parent = &pdev->dev;
indio_dev->info = &temperature_info;
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = devm_iio_triggered_buffer_setup(&pdev->dev, indio_dev,
&iio_pollfunc_store_time, NULL, NULL);
if (ret)
return ret;
atomic_set(&temp_st->common_attributes.data_ready, 0);
ret = hid_sensor_setup_trigger(indio_dev, name,
&temp_st->common_attributes);
if (ret)
return ret;
platform_set_drvdata(pdev, indio_dev);
temperature_callbacks.pdev = pdev;
ret = sensor_hub_register_callback(hsdev, HID_USAGE_SENSOR_TEMPERATURE,
&temperature_callbacks);
if (ret)
goto error_remove_trigger;
ret = devm_iio_device_register(indio_dev->dev.parent, indio_dev);
if (ret)
goto error_remove_callback;
return ret;
error_remove_callback:
sensor_hub_remove_callback(hsdev, HID_USAGE_SENSOR_TEMPERATURE);
error_remove_trigger:
hid_sensor_remove_trigger(&temp_st->common_attributes);
return ret;
}
static int hid_temperature_remove(struct platform_device *pdev)
{
struct hid_sensor_hub_device *hsdev = dev_get_platdata(&pdev->dev);
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct temperature_state *temp_st = iio_priv(indio_dev);
sensor_hub_remove_callback(hsdev, HID_USAGE_SENSOR_TEMPERATURE);
hid_sensor_remove_trigger(&temp_st->common_attributes);
return 0;
}
