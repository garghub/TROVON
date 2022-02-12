static void incl_3d_adjust_channel_bit_mask(struct iio_chan_spec *chan,
int size)
{
chan->scan_type.sign = 's';
chan->scan_type.realbits = size * 8;
chan->scan_type.storagebits = sizeof(u32) * 8;
}
static int incl_3d_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct incl_3d_state *incl_state = iio_priv(indio_dev);
int report_id = -1;
u32 address;
int ret_type;
*val = 0;
*val2 = 0;
switch (mask) {
case IIO_CHAN_INFO_RAW:
hid_sensor_power_state(&incl_state->common_attributes, true);
report_id =
incl_state->incl[chan->scan_index].report_id;
address = incl_3d_addresses[chan->scan_index];
if (report_id >= 0)
*val = sensor_hub_input_attr_get_raw_value(
incl_state->common_attributes.hsdev,
HID_USAGE_SENSOR_INCLINOMETER_3D, address,
report_id,
SENSOR_HUB_SYNC);
else {
hid_sensor_power_state(&incl_state->common_attributes,
false);
return -EINVAL;
}
hid_sensor_power_state(&incl_state->common_attributes, false);
ret_type = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
*val = incl_state->scale_pre_decml;
*val2 = incl_state->scale_post_decml;
ret_type = incl_state->scale_precision;
break;
case IIO_CHAN_INFO_OFFSET:
*val = incl_state->value_offset;
ret_type = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SAMP_FREQ:
ret_type = hid_sensor_read_samp_freq_value(
&incl_state->common_attributes, val, val2);
break;
case IIO_CHAN_INFO_HYSTERESIS:
ret_type = hid_sensor_read_raw_hyst_value(
&incl_state->common_attributes, val, val2);
break;
default:
ret_type = -EINVAL;
break;
}
return ret_type;
}
static int incl_3d_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct incl_3d_state *incl_state = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
ret = hid_sensor_write_samp_freq_value(
&incl_state->common_attributes, val, val2);
break;
case IIO_CHAN_INFO_HYSTERESIS:
ret = hid_sensor_write_raw_hyst_value(
&incl_state->common_attributes, val, val2);
break;
default:
ret = -EINVAL;
}
return ret;
}
static void hid_sensor_push_data(struct iio_dev *indio_dev, u8 *data, int len)
{
dev_dbg(&indio_dev->dev, "hid_sensor_push_data\n");
iio_push_to_buffers(indio_dev, (u8 *)data);
}
static int incl_3d_proc_event(struct hid_sensor_hub_device *hsdev,
unsigned usage_id,
void *priv)
{
struct iio_dev *indio_dev = platform_get_drvdata(priv);
struct incl_3d_state *incl_state = iio_priv(indio_dev);
dev_dbg(&indio_dev->dev, "incl_3d_proc_event\n");
if (atomic_read(&incl_state->common_attributes.data_ready))
hid_sensor_push_data(indio_dev,
(u8 *)incl_state->incl_val,
sizeof(incl_state->incl_val));
return 0;
}
static int incl_3d_capture_sample(struct hid_sensor_hub_device *hsdev,
unsigned usage_id,
size_t raw_len, char *raw_data,
void *priv)
{
struct iio_dev *indio_dev = platform_get_drvdata(priv);
struct incl_3d_state *incl_state = iio_priv(indio_dev);
int ret = 0;
switch (usage_id) {
case HID_USAGE_SENSOR_ORIENT_TILT_X:
incl_state->incl_val[CHANNEL_SCAN_INDEX_X] = *(u32 *)raw_data;
break;
case HID_USAGE_SENSOR_ORIENT_TILT_Y:
incl_state->incl_val[CHANNEL_SCAN_INDEX_Y] = *(u32 *)raw_data;
break;
case HID_USAGE_SENSOR_ORIENT_TILT_Z:
incl_state->incl_val[CHANNEL_SCAN_INDEX_Z] = *(u32 *)raw_data;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int incl_3d_parse_report(struct platform_device *pdev,
struct hid_sensor_hub_device *hsdev,
struct iio_chan_spec *channels,
unsigned usage_id,
struct incl_3d_state *st)
{
int ret;
ret = sensor_hub_input_get_attribute_info(hsdev,
HID_INPUT_REPORT,
usage_id,
HID_USAGE_SENSOR_ORIENT_TILT_X,
&st->incl[CHANNEL_SCAN_INDEX_X]);
if (ret)
return ret;
incl_3d_adjust_channel_bit_mask(&channels[CHANNEL_SCAN_INDEX_X],
st->incl[CHANNEL_SCAN_INDEX_X].size);
ret = sensor_hub_input_get_attribute_info(hsdev,
HID_INPUT_REPORT,
usage_id,
HID_USAGE_SENSOR_ORIENT_TILT_Y,
&st->incl[CHANNEL_SCAN_INDEX_Y]);
if (ret)
return ret;
incl_3d_adjust_channel_bit_mask(&channels[CHANNEL_SCAN_INDEX_Y],
st->incl[CHANNEL_SCAN_INDEX_Y].size);
ret = sensor_hub_input_get_attribute_info(hsdev,
HID_INPUT_REPORT,
usage_id,
HID_USAGE_SENSOR_ORIENT_TILT_Z,
&st->incl[CHANNEL_SCAN_INDEX_Z]);
if (ret)
return ret;
incl_3d_adjust_channel_bit_mask(&channels[CHANNEL_SCAN_INDEX_Z],
st->incl[CHANNEL_SCAN_INDEX_Z].size);
dev_dbg(&pdev->dev, "incl_3d %x:%x, %x:%x, %x:%x\n",
st->incl[0].index,
st->incl[0].report_id,
st->incl[1].index, st->incl[1].report_id,
st->incl[2].index, st->incl[2].report_id);
st->scale_precision = hid_sensor_format_scale(
HID_USAGE_SENSOR_INCLINOMETER_3D,
&st->incl[CHANNEL_SCAN_INDEX_X],
&st->scale_pre_decml, &st->scale_post_decml);
if (st->common_attributes.sensitivity.index < 0) {
sensor_hub_input_get_attribute_info(hsdev,
HID_FEATURE_REPORT, usage_id,
HID_USAGE_SENSOR_DATA_MOD_CHANGE_SENSITIVITY_ABS |
HID_USAGE_SENSOR_DATA_ORIENTATION,
&st->common_attributes.sensitivity);
dev_dbg(&pdev->dev, "Sensitivity index:report %d:%d\n",
st->common_attributes.sensitivity.index,
st->common_attributes.sensitivity.report_id);
}
return ret;
}
static int hid_incl_3d_probe(struct platform_device *pdev)
{
int ret;
static char *name = "incli_3d";
struct iio_dev *indio_dev;
struct incl_3d_state *incl_state;
struct hid_sensor_hub_device *hsdev = pdev->dev.platform_data;
indio_dev = devm_iio_device_alloc(&pdev->dev,
sizeof(struct incl_3d_state));
if (indio_dev == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, indio_dev);
incl_state = iio_priv(indio_dev);
incl_state->common_attributes.hsdev = hsdev;
incl_state->common_attributes.pdev = pdev;
ret = hid_sensor_parse_common_attributes(hsdev,
HID_USAGE_SENSOR_INCLINOMETER_3D,
&incl_state->common_attributes);
if (ret) {
dev_err(&pdev->dev, "failed to setup common attributes\n");
return ret;
}
indio_dev->channels = kmemdup(incl_3d_channels,
sizeof(incl_3d_channels), GFP_KERNEL);
if (!indio_dev->channels) {
dev_err(&pdev->dev, "failed to duplicate channels\n");
return -ENOMEM;
}
ret = incl_3d_parse_report(pdev, hsdev,
(struct iio_chan_spec *)indio_dev->channels,
HID_USAGE_SENSOR_INCLINOMETER_3D,
incl_state);
if (ret) {
dev_err(&pdev->dev, "failed to setup attributes\n");
goto error_free_dev_mem;
}
indio_dev->num_channels = ARRAY_SIZE(incl_3d_channels);
indio_dev->dev.parent = &pdev->dev;
indio_dev->info = &incl_3d_info;
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
NULL, NULL);
if (ret) {
dev_err(&pdev->dev, "failed to initialize trigger buffer\n");
goto error_free_dev_mem;
}
atomic_set(&incl_state->common_attributes.data_ready, 0);
ret = hid_sensor_setup_trigger(indio_dev, name,
&incl_state->common_attributes);
if (ret) {
dev_err(&pdev->dev, "trigger setup failed\n");
goto error_unreg_buffer_funcs;
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&pdev->dev, "device register failed\n");
goto error_remove_trigger;
}
incl_state->callbacks.send_event = incl_3d_proc_event;
incl_state->callbacks.capture_sample = incl_3d_capture_sample;
incl_state->callbacks.pdev = pdev;
ret = sensor_hub_register_callback(hsdev,
HID_USAGE_SENSOR_INCLINOMETER_3D,
&incl_state->callbacks);
if (ret) {
dev_err(&pdev->dev, "callback reg failed\n");
goto error_iio_unreg;
}
return 0;
error_iio_unreg:
iio_device_unregister(indio_dev);
error_remove_trigger:
hid_sensor_remove_trigger(&incl_state->common_attributes);
error_unreg_buffer_funcs:
iio_triggered_buffer_cleanup(indio_dev);
error_free_dev_mem:
kfree(indio_dev->channels);
return ret;
}
static int hid_incl_3d_remove(struct platform_device *pdev)
{
struct hid_sensor_hub_device *hsdev = pdev->dev.platform_data;
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct incl_3d_state *incl_state = iio_priv(indio_dev);
sensor_hub_remove_callback(hsdev, HID_USAGE_SENSOR_INCLINOMETER_3D);
iio_device_unregister(indio_dev);
hid_sensor_remove_trigger(&incl_state->common_attributes);
iio_triggered_buffer_cleanup(indio_dev);
kfree(indio_dev->channels);
return 0;
}
