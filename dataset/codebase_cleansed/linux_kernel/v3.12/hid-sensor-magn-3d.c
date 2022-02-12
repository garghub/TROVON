static void magn_3d_adjust_channel_bit_mask(struct iio_chan_spec *channels,
int channel, int size)
{
channels[channel].scan_type.sign = 's';
channels[channel].scan_type.realbits = size * 8;
channels[channel].scan_type.storagebits = sizeof(u32) * 8;
}
static int magn_3d_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct magn_3d_state *magn_state = iio_priv(indio_dev);
int report_id = -1;
u32 address;
int ret;
int ret_type;
*val = 0;
*val2 = 0;
switch (mask) {
case 0:
report_id =
magn_state->magn[chan->scan_index].report_id;
address = magn_3d_addresses[chan->scan_index];
if (report_id >= 0)
*val = sensor_hub_input_attr_get_raw_value(
magn_state->common_attributes.hsdev,
HID_USAGE_SENSOR_COMPASS_3D, address,
report_id);
else {
*val = 0;
return -EINVAL;
}
ret_type = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
*val = magn_state->magn[CHANNEL_SCAN_INDEX_X].units;
ret_type = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_OFFSET:
*val = hid_sensor_convert_exponent(
magn_state->magn[CHANNEL_SCAN_INDEX_X].unit_expo);
ret_type = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SAMP_FREQ:
ret = hid_sensor_read_samp_freq_value(
&magn_state->common_attributes, val, val2);
ret_type = IIO_VAL_INT_PLUS_MICRO;
break;
case IIO_CHAN_INFO_HYSTERESIS:
ret = hid_sensor_read_raw_hyst_value(
&magn_state->common_attributes, val, val2);
ret_type = IIO_VAL_INT_PLUS_MICRO;
break;
default:
ret_type = -EINVAL;
break;
}
return ret_type;
}
static int magn_3d_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct magn_3d_state *magn_state = iio_priv(indio_dev);
int ret = 0;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
ret = hid_sensor_write_samp_freq_value(
&magn_state->common_attributes, val, val2);
break;
case IIO_CHAN_INFO_HYSTERESIS:
ret = hid_sensor_write_raw_hyst_value(
&magn_state->common_attributes, val, val2);
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
static int magn_3d_proc_event(struct hid_sensor_hub_device *hsdev,
unsigned usage_id,
void *priv)
{
struct iio_dev *indio_dev = platform_get_drvdata(priv);
struct magn_3d_state *magn_state = iio_priv(indio_dev);
dev_dbg(&indio_dev->dev, "magn_3d_proc_event [%d]\n",
magn_state->common_attributes.data_ready);
if (magn_state->common_attributes.data_ready)
hid_sensor_push_data(indio_dev,
(u8 *)magn_state->magn_val,
sizeof(magn_state->magn_val));
return 0;
}
static int magn_3d_capture_sample(struct hid_sensor_hub_device *hsdev,
unsigned usage_id,
size_t raw_len, char *raw_data,
void *priv)
{
struct iio_dev *indio_dev = platform_get_drvdata(priv);
struct magn_3d_state *magn_state = iio_priv(indio_dev);
int offset;
int ret = -EINVAL;
switch (usage_id) {
case HID_USAGE_SENSOR_ORIENT_MAGN_FLUX_X_AXIS:
case HID_USAGE_SENSOR_ORIENT_MAGN_FLUX_Y_AXIS:
case HID_USAGE_SENSOR_ORIENT_MAGN_FLUX_Z_AXIS:
offset = usage_id - HID_USAGE_SENSOR_ORIENT_MAGN_FLUX_X_AXIS;
magn_state->magn_val[CHANNEL_SCAN_INDEX_X + offset] =
*(u32 *)raw_data;
ret = 0;
break;
default:
break;
}
return ret;
}
static int magn_3d_parse_report(struct platform_device *pdev,
struct hid_sensor_hub_device *hsdev,
struct iio_chan_spec *channels,
unsigned usage_id,
struct magn_3d_state *st)
{
int ret;
int i;
for (i = 0; i <= CHANNEL_SCAN_INDEX_Z; ++i) {
ret = sensor_hub_input_get_attribute_info(hsdev,
HID_INPUT_REPORT,
usage_id,
HID_USAGE_SENSOR_ORIENT_MAGN_FLUX_X_AXIS + i,
&st->magn[CHANNEL_SCAN_INDEX_X + i]);
if (ret < 0)
break;
magn_3d_adjust_channel_bit_mask(channels,
CHANNEL_SCAN_INDEX_X + i,
st->magn[CHANNEL_SCAN_INDEX_X + i].size);
}
dev_dbg(&pdev->dev, "magn_3d %x:%x, %x:%x, %x:%x\n",
st->magn[0].index,
st->magn[0].report_id,
st->magn[1].index, st->magn[1].report_id,
st->magn[2].index, st->magn[2].report_id);
return ret;
}
static int hid_magn_3d_probe(struct platform_device *pdev)
{
int ret = 0;
static char *name = "magn_3d";
struct iio_dev *indio_dev;
struct magn_3d_state *magn_state;
struct hid_sensor_hub_device *hsdev = pdev->dev.platform_data;
struct iio_chan_spec *channels;
indio_dev = devm_iio_device_alloc(&pdev->dev,
sizeof(struct magn_3d_state));
if (indio_dev == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, indio_dev);
magn_state = iio_priv(indio_dev);
magn_state->common_attributes.hsdev = hsdev;
magn_state->common_attributes.pdev = pdev;
ret = hid_sensor_parse_common_attributes(hsdev,
HID_USAGE_SENSOR_COMPASS_3D,
&magn_state->common_attributes);
if (ret) {
dev_err(&pdev->dev, "failed to setup common attributes\n");
return ret;
}
channels = kmemdup(magn_3d_channels, sizeof(magn_3d_channels),
GFP_KERNEL);
if (!channels) {
dev_err(&pdev->dev, "failed to duplicate channels\n");
return -ENOMEM;
}
ret = magn_3d_parse_report(pdev, hsdev, channels,
HID_USAGE_SENSOR_COMPASS_3D, magn_state);
if (ret) {
dev_err(&pdev->dev, "failed to setup attributes\n");
goto error_free_dev_mem;
}
indio_dev->channels = channels;
indio_dev->num_channels = ARRAY_SIZE(magn_3d_channels);
indio_dev->dev.parent = &pdev->dev;
indio_dev->info = &magn_3d_info;
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
NULL, NULL);
if (ret) {
dev_err(&pdev->dev, "failed to initialize trigger buffer\n");
goto error_free_dev_mem;
}
magn_state->common_attributes.data_ready = false;
ret = hid_sensor_setup_trigger(indio_dev, name,
&magn_state->common_attributes);
if (ret < 0) {
dev_err(&pdev->dev, "trigger setup failed\n");
goto error_unreg_buffer_funcs;
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&pdev->dev, "device register failed\n");
goto error_remove_trigger;
}
magn_state->callbacks.send_event = magn_3d_proc_event;
magn_state->callbacks.capture_sample = magn_3d_capture_sample;
magn_state->callbacks.pdev = pdev;
ret = sensor_hub_register_callback(hsdev, HID_USAGE_SENSOR_COMPASS_3D,
&magn_state->callbacks);
if (ret < 0) {
dev_err(&pdev->dev, "callback reg failed\n");
goto error_iio_unreg;
}
return ret;
error_iio_unreg:
iio_device_unregister(indio_dev);
error_remove_trigger:
hid_sensor_remove_trigger(indio_dev);
error_unreg_buffer_funcs:
iio_triggered_buffer_cleanup(indio_dev);
error_free_dev_mem:
kfree(indio_dev->channels);
return ret;
}
static int hid_magn_3d_remove(struct platform_device *pdev)
{
struct hid_sensor_hub_device *hsdev = pdev->dev.platform_data;
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
sensor_hub_remove_callback(hsdev, HID_USAGE_SENSOR_COMPASS_3D);
iio_device_unregister(indio_dev);
hid_sensor_remove_trigger(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
kfree(indio_dev->channels);
return 0;
}
