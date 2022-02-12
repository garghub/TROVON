static void gyro_3d_adjust_channel_bit_mask(struct iio_chan_spec *channels,
int channel, int size)
{
channels[channel].scan_type.sign = 's';
channels[channel].scan_type.realbits = size * 8;
channels[channel].scan_type.storagebits = sizeof(u32) * 8;
}
static int gyro_3d_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct gyro_3d_state *gyro_state = iio_priv(indio_dev);
int report_id = -1;
u32 address;
int ret_type;
*val = 0;
*val2 = 0;
switch (mask) {
case 0:
hid_sensor_power_state(&gyro_state->common_attributes, true);
report_id = gyro_state->gyro[chan->scan_index].report_id;
address = gyro_3d_addresses[chan->scan_index];
if (report_id >= 0)
*val = sensor_hub_input_attr_get_raw_value(
gyro_state->common_attributes.hsdev,
HID_USAGE_SENSOR_GYRO_3D, address,
report_id);
else {
*val = 0;
hid_sensor_power_state(&gyro_state->common_attributes,
false);
return -EINVAL;
}
hid_sensor_power_state(&gyro_state->common_attributes, false);
ret_type = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
*val = gyro_state->scale_pre_decml;
*val2 = gyro_state->scale_post_decml;
ret_type = gyro_state->scale_precision;
break;
case IIO_CHAN_INFO_OFFSET:
*val = gyro_state->value_offset;
ret_type = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SAMP_FREQ:
ret_type = hid_sensor_read_samp_freq_value(
&gyro_state->common_attributes, val, val2);
break;
case IIO_CHAN_INFO_HYSTERESIS:
ret_type = hid_sensor_read_raw_hyst_value(
&gyro_state->common_attributes, val, val2);
break;
default:
ret_type = -EINVAL;
break;
}
return ret_type;
}
static int gyro_3d_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct gyro_3d_state *gyro_state = iio_priv(indio_dev);
int ret = 0;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
ret = hid_sensor_write_samp_freq_value(
&gyro_state->common_attributes, val, val2);
break;
case IIO_CHAN_INFO_HYSTERESIS:
ret = hid_sensor_write_raw_hyst_value(
&gyro_state->common_attributes, val, val2);
break;
default:
ret = -EINVAL;
}
return ret;
}
static void hid_sensor_push_data(struct iio_dev *indio_dev, const void *data,
int len)
{
dev_dbg(&indio_dev->dev, "hid_sensor_push_data\n");
iio_push_to_buffers(indio_dev, data);
}
static int gyro_3d_proc_event(struct hid_sensor_hub_device *hsdev,
unsigned usage_id,
void *priv)
{
struct iio_dev *indio_dev = platform_get_drvdata(priv);
struct gyro_3d_state *gyro_state = iio_priv(indio_dev);
dev_dbg(&indio_dev->dev, "gyro_3d_proc_event\n");
if (atomic_read(&gyro_state->common_attributes.data_ready))
hid_sensor_push_data(indio_dev,
gyro_state->gyro_val,
sizeof(gyro_state->gyro_val));
return 0;
}
static int gyro_3d_capture_sample(struct hid_sensor_hub_device *hsdev,
unsigned usage_id,
size_t raw_len, char *raw_data,
void *priv)
{
struct iio_dev *indio_dev = platform_get_drvdata(priv);
struct gyro_3d_state *gyro_state = iio_priv(indio_dev);
int offset;
int ret = -EINVAL;
switch (usage_id) {
case HID_USAGE_SENSOR_ANGL_VELOCITY_X_AXIS:
case HID_USAGE_SENSOR_ANGL_VELOCITY_Y_AXIS:
case HID_USAGE_SENSOR_ANGL_VELOCITY_Z_AXIS:
offset = usage_id - HID_USAGE_SENSOR_ANGL_VELOCITY_X_AXIS;
gyro_state->gyro_val[CHANNEL_SCAN_INDEX_X + offset] =
*(u32 *)raw_data;
ret = 0;
break;
default:
break;
}
return ret;
}
static int gyro_3d_parse_report(struct platform_device *pdev,
struct hid_sensor_hub_device *hsdev,
struct iio_chan_spec *channels,
unsigned usage_id,
struct gyro_3d_state *st)
{
int ret;
int i;
for (i = 0; i <= CHANNEL_SCAN_INDEX_Z; ++i) {
ret = sensor_hub_input_get_attribute_info(hsdev,
HID_INPUT_REPORT,
usage_id,
HID_USAGE_SENSOR_ANGL_VELOCITY_X_AXIS + i,
&st->gyro[CHANNEL_SCAN_INDEX_X + i]);
if (ret < 0)
break;
gyro_3d_adjust_channel_bit_mask(channels,
CHANNEL_SCAN_INDEX_X + i,
st->gyro[CHANNEL_SCAN_INDEX_X + i].size);
}
dev_dbg(&pdev->dev, "gyro_3d %x:%x, %x:%x, %x:%x\n",
st->gyro[0].index,
st->gyro[0].report_id,
st->gyro[1].index, st->gyro[1].report_id,
st->gyro[2].index, st->gyro[2].report_id);
st->scale_precision = hid_sensor_format_scale(
HID_USAGE_SENSOR_GYRO_3D,
&st->gyro[CHANNEL_SCAN_INDEX_X],
&st->scale_pre_decml, &st->scale_post_decml);
if (st->common_attributes.sensitivity.index < 0) {
sensor_hub_input_get_attribute_info(hsdev,
HID_FEATURE_REPORT, usage_id,
HID_USAGE_SENSOR_DATA_MOD_CHANGE_SENSITIVITY_ABS |
HID_USAGE_SENSOR_DATA_ANGL_VELOCITY,
&st->common_attributes.sensitivity);
dev_dbg(&pdev->dev, "Sensitivity index:report %d:%d\n",
st->common_attributes.sensitivity.index,
st->common_attributes.sensitivity.report_id);
}
return ret;
}
static int hid_gyro_3d_probe(struct platform_device *pdev)
{
int ret = 0;
static const char *name = "gyro_3d";
struct iio_dev *indio_dev;
struct gyro_3d_state *gyro_state;
struct hid_sensor_hub_device *hsdev = pdev->dev.platform_data;
struct iio_chan_spec *channels;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*gyro_state));
if (!indio_dev)
return -ENOMEM;
platform_set_drvdata(pdev, indio_dev);
gyro_state = iio_priv(indio_dev);
gyro_state->common_attributes.hsdev = hsdev;
gyro_state->common_attributes.pdev = pdev;
ret = hid_sensor_parse_common_attributes(hsdev,
HID_USAGE_SENSOR_GYRO_3D,
&gyro_state->common_attributes);
if (ret) {
dev_err(&pdev->dev, "failed to setup common attributes\n");
return ret;
}
channels = kmemdup(gyro_3d_channels, sizeof(gyro_3d_channels),
GFP_KERNEL);
if (!channels) {
dev_err(&pdev->dev, "failed to duplicate channels\n");
return -ENOMEM;
}
ret = gyro_3d_parse_report(pdev, hsdev, channels,
HID_USAGE_SENSOR_GYRO_3D, gyro_state);
if (ret) {
dev_err(&pdev->dev, "failed to setup attributes\n");
goto error_free_dev_mem;
}
indio_dev->channels = channels;
indio_dev->num_channels = ARRAY_SIZE(gyro_3d_channels);
indio_dev->dev.parent = &pdev->dev;
indio_dev->info = &gyro_3d_info;
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
NULL, NULL);
if (ret) {
dev_err(&pdev->dev, "failed to initialize trigger buffer\n");
goto error_free_dev_mem;
}
atomic_set(&gyro_state->common_attributes.data_ready, 0);
ret = hid_sensor_setup_trigger(indio_dev, name,
&gyro_state->common_attributes);
if (ret < 0) {
dev_err(&pdev->dev, "trigger setup failed\n");
goto error_unreg_buffer_funcs;
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&pdev->dev, "device register failed\n");
goto error_remove_trigger;
}
gyro_state->callbacks.send_event = gyro_3d_proc_event;
gyro_state->callbacks.capture_sample = gyro_3d_capture_sample;
gyro_state->callbacks.pdev = pdev;
ret = sensor_hub_register_callback(hsdev, HID_USAGE_SENSOR_GYRO_3D,
&gyro_state->callbacks);
if (ret < 0) {
dev_err(&pdev->dev, "callback reg failed\n");
goto error_iio_unreg;
}
return ret;
error_iio_unreg:
iio_device_unregister(indio_dev);
error_remove_trigger:
hid_sensor_remove_trigger(&gyro_state->common_attributes);
error_unreg_buffer_funcs:
iio_triggered_buffer_cleanup(indio_dev);
error_free_dev_mem:
kfree(indio_dev->channels);
return ret;
}
static int hid_gyro_3d_remove(struct platform_device *pdev)
{
struct hid_sensor_hub_device *hsdev = pdev->dev.platform_data;
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct gyro_3d_state *gyro_state = iio_priv(indio_dev);
sensor_hub_remove_callback(hsdev, HID_USAGE_SENSOR_GYRO_3D);
iio_device_unregister(indio_dev);
hid_sensor_remove_trigger(&gyro_state->common_attributes);
iio_triggered_buffer_cleanup(indio_dev);
kfree(indio_dev->channels);
return 0;
}
