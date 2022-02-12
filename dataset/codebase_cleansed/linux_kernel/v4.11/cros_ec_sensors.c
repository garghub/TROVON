static int cros_ec_sensors_read(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct cros_ec_sensors_state *st = iio_priv(indio_dev);
s16 data = 0;
s64 val64;
int i;
int ret;
int idx = chan->scan_index;
mutex_lock(&st->core.cmd_lock);
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = st->core.read_ec_sensors_data(indio_dev, 1 << idx, &data);
if (ret < 0)
break;
ret = IIO_VAL_INT;
*val = data;
break;
case IIO_CHAN_INFO_CALIBBIAS:
st->core.param.cmd = MOTIONSENSE_CMD_SENSOR_OFFSET;
st->core.param.sensor_offset.flags = 0;
ret = cros_ec_motion_send_host_cmd(&st->core, 0);
if (ret < 0)
break;
for (i = CROS_EC_SENSOR_X; i < CROS_EC_SENSOR_MAX_AXIS; i++)
st->core.calib[i] =
st->core.resp->sensor_offset.offset[i];
ret = IIO_VAL_INT;
*val = st->core.calib[idx];
break;
case IIO_CHAN_INFO_SCALE:
st->core.param.cmd = MOTIONSENSE_CMD_SENSOR_RANGE;
st->core.param.sensor_range.data = EC_MOTION_SENSE_NO_VALUE;
ret = cros_ec_motion_send_host_cmd(&st->core, 0);
if (ret < 0)
break;
val64 = st->core.resp->sensor_range.ret;
switch (st->core.type) {
case MOTIONSENSE_TYPE_ACCEL:
*val = div_s64(val64 * 980665, 10);
*val2 = 10000 << (CROS_EC_SENSOR_BITS - 1);
ret = IIO_VAL_FRACTIONAL;
break;
case MOTIONSENSE_TYPE_GYRO:
*val = div_s64(val64 * 314159 + 9000000ULL, 1000);
*val2 = 18000 << (CROS_EC_SENSOR_BITS - 1);
ret = IIO_VAL_FRACTIONAL;
break;
case MOTIONSENSE_TYPE_MAG:
*val = val64;
*val2 = 100 << (CROS_EC_SENSOR_BITS - 1);
ret = IIO_VAL_FRACTIONAL;
break;
default:
ret = -EINVAL;
}
break;
default:
ret = cros_ec_sensors_core_read(&st->core, chan, val, val2,
mask);
break;
}
mutex_unlock(&st->core.cmd_lock);
return ret;
}
static int cros_ec_sensors_write(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct cros_ec_sensors_state *st = iio_priv(indio_dev);
int i;
int ret;
int idx = chan->scan_index;
mutex_lock(&st->core.cmd_lock);
switch (mask) {
case IIO_CHAN_INFO_CALIBBIAS:
st->core.calib[idx] = val;
st->core.param.cmd = MOTIONSENSE_CMD_SENSOR_OFFSET;
st->core.param.sensor_offset.flags =
MOTION_SENSE_SET_OFFSET;
for (i = CROS_EC_SENSOR_X; i < CROS_EC_SENSOR_MAX_AXIS; i++)
st->core.param.sensor_offset.offset[i] =
st->core.calib[i];
st->core.param.sensor_offset.temp =
EC_MOTION_SENSE_INVALID_CALIB_TEMP;
ret = cros_ec_motion_send_host_cmd(&st->core, 0);
break;
case IIO_CHAN_INFO_SCALE:
if (st->core.type == MOTIONSENSE_TYPE_MAG) {
ret = -EINVAL;
break;
}
st->core.param.cmd = MOTIONSENSE_CMD_SENSOR_RANGE;
st->core.param.sensor_range.data = val;
st->core.param.sensor_range.roundup = 1;
ret = cros_ec_motion_send_host_cmd(&st->core, 0);
break;
default:
ret = cros_ec_sensors_core_write(
&st->core, chan, val, val2, mask);
break;
}
mutex_unlock(&st->core.cmd_lock);
return ret;
}
static int cros_ec_sensors_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct cros_ec_dev *ec_dev = dev_get_drvdata(dev->parent);
struct cros_ec_device *ec_device;
struct iio_dev *indio_dev;
struct cros_ec_sensors_state *state;
struct iio_chan_spec *channel;
int ret, i;
if (!ec_dev || !ec_dev->ec_dev) {
dev_warn(&pdev->dev, "No CROS EC device found.\n");
return -EINVAL;
}
ec_device = ec_dev->ec_dev;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*state));
if (!indio_dev)
return -ENOMEM;
ret = cros_ec_sensors_core_init(pdev, indio_dev, true);
if (ret)
return ret;
indio_dev->info = &ec_sensors_info;
state = iio_priv(indio_dev);
for (channel = state->channels, i = CROS_EC_SENSOR_X;
i < CROS_EC_SENSOR_MAX_AXIS; i++, channel++) {
channel->info_mask_separate =
BIT(IIO_CHAN_INFO_RAW) |
BIT(IIO_CHAN_INFO_CALIBBIAS);
channel->info_mask_shared_by_all =
BIT(IIO_CHAN_INFO_SCALE) |
BIT(IIO_CHAN_INFO_FREQUENCY) |
BIT(IIO_CHAN_INFO_SAMP_FREQ);
channel->scan_type.realbits = CROS_EC_SENSOR_BITS;
channel->scan_type.storagebits = CROS_EC_SENSOR_BITS;
channel->scan_index = i;
channel->ext_info = cros_ec_sensors_ext_info;
channel->modified = 1;
channel->channel2 = IIO_MOD_X + i;
channel->scan_type.sign = 's';
switch (state->core.type) {
case MOTIONSENSE_TYPE_ACCEL:
channel->type = IIO_ACCEL;
break;
case MOTIONSENSE_TYPE_GYRO:
channel->type = IIO_ANGL_VEL;
break;
case MOTIONSENSE_TYPE_MAG:
channel->type = IIO_MAGN;
break;
default:
dev_err(&pdev->dev, "Unknown motion sensor\n");
return -EINVAL;
}
}
channel->type = IIO_TIMESTAMP;
channel->channel = -1;
channel->scan_index = CROS_EC_SENSOR_MAX_AXIS;
channel->scan_type.sign = 's';
channel->scan_type.realbits = 64;
channel->scan_type.storagebits = 64;
indio_dev->channels = state->channels;
indio_dev->num_channels = CROS_EC_SENSORS_MAX_CHANNELS;
if ((state->core.ec->cmd_readmem != NULL) &&
(state->core.type != MOTIONSENSE_TYPE_MAG))
state->core.read_ec_sensors_data = cros_ec_sensors_read_lpc;
else
state->core.read_ec_sensors_data = cros_ec_sensors_read_cmd;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
cros_ec_sensors_capture, NULL);
if (ret)
return ret;
ret = iio_device_register(indio_dev);
if (ret)
goto error_uninit_buffer;
return 0;
error_uninit_buffer:
iio_triggered_buffer_cleanup(indio_dev);
return ret;
}
static int cros_ec_sensors_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
return 0;
}
