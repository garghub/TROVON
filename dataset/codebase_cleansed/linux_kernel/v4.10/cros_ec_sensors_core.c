int cros_ec_sensors_core_init(struct platform_device *pdev,
struct iio_dev *indio_dev,
bool physical_device)
{
struct device *dev = &pdev->dev;
struct cros_ec_sensors_core_state *state = iio_priv(indio_dev);
struct cros_ec_dev *ec = dev_get_drvdata(pdev->dev.parent);
struct cros_ec_sensor_platform *sensor_platform = dev_get_platdata(dev);
platform_set_drvdata(pdev, indio_dev);
state->ec = ec->ec_dev;
state->msg = devm_kzalloc(&pdev->dev,
max((u16)sizeof(struct ec_params_motion_sense),
state->ec->max_response), GFP_KERNEL);
if (!state->msg)
return -ENOMEM;
state->resp = (struct ec_response_motion_sense *)state->msg->data;
mutex_init(&state->cmd_lock);
state->msg->version = 2;
state->msg->command = EC_CMD_MOTION_SENSE_CMD + ec->cmd_offset;
state->msg->outsize = sizeof(struct ec_params_motion_sense);
indio_dev->dev.parent = &pdev->dev;
indio_dev->name = pdev->name;
if (physical_device) {
indio_dev->modes = INDIO_DIRECT_MODE;
state->param.cmd = MOTIONSENSE_CMD_INFO;
state->param.info.sensor_num = sensor_platform->sensor_num;
if (cros_ec_motion_send_host_cmd(state, 0)) {
dev_warn(dev, "Can not access sensor info\n");
return -EIO;
}
state->type = state->resp->info.type;
state->loc = state->resp->info.location;
}
return 0;
}
int cros_ec_motion_send_host_cmd(struct cros_ec_sensors_core_state *state,
u16 opt_length)
{
int ret;
if (opt_length)
state->msg->insize = min(opt_length, state->ec->max_response);
else
state->msg->insize = state->ec->max_response;
memcpy(state->msg->data, &state->param, sizeof(state->param));
ret = cros_ec_cmd_xfer_status(state->ec, state->msg);
if (ret < 0)
return -EIO;
if (ret &&
state->resp != (struct ec_response_motion_sense *)state->msg->data)
memcpy(state->resp, state->msg->data, ret);
return 0;
}
static ssize_t cros_ec_sensors_calibrate(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan,
const char *buf, size_t len)
{
struct cros_ec_sensors_core_state *st = iio_priv(indio_dev);
int ret, i;
bool calibrate;
ret = strtobool(buf, &calibrate);
if (ret < 0)
return ret;
if (!calibrate)
return -EINVAL;
mutex_lock(&st->cmd_lock);
st->param.cmd = MOTIONSENSE_CMD_PERFORM_CALIB;
ret = cros_ec_motion_send_host_cmd(st, 0);
if (ret != 0) {
dev_warn(&indio_dev->dev, "Unable to calibrate sensor\n");
} else {
for (i = CROS_EC_SENSOR_X; i < CROS_EC_SENSOR_MAX_AXIS; i++)
st->calib[i] = st->resp->perform_calib.offset[i];
}
mutex_unlock(&st->cmd_lock);
return ret ? ret : len;
}
static ssize_t cros_ec_sensors_loc(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan,
char *buf)
{
struct cros_ec_sensors_core_state *st = iio_priv(indio_dev);
return snprintf(buf, PAGE_SIZE, "%s\n", cros_ec_loc[st->loc]);
}
static unsigned int cros_ec_sensors_idx_to_reg(
struct cros_ec_sensors_core_state *st,
unsigned int idx)
{
if (st->type == MOTIONSENSE_TYPE_ACCEL)
return EC_MEMMAP_ACC_DATA + sizeof(u16) *
(1 + idx + st->param.info.sensor_num *
CROS_EC_SENSOR_MAX_AXIS);
return EC_MEMMAP_GYRO_DATA + sizeof(u16) * idx;
}
static int cros_ec_sensors_cmd_read_u8(struct cros_ec_device *ec,
unsigned int offset, u8 *dest)
{
return ec->cmd_readmem(ec, offset, 1, dest);
}
static int cros_ec_sensors_cmd_read_u16(struct cros_ec_device *ec,
unsigned int offset, u16 *dest)
{
__le16 tmp;
int ret = ec->cmd_readmem(ec, offset, 2, &tmp);
if (ret >= 0)
*dest = le16_to_cpu(tmp);
return ret;
}
static int cros_ec_sensors_read_until_not_busy(
struct cros_ec_sensors_core_state *st)
{
struct cros_ec_device *ec = st->ec;
u8 status;
int ret, attempts = 0;
ret = cros_ec_sensors_cmd_read_u8(ec, EC_MEMMAP_ACC_STATUS, &status);
if (ret < 0)
return ret;
while (status & EC_MEMMAP_ACC_STATUS_BUSY_BIT) {
if (attempts++ >= 50)
return -EIO;
if (attempts % 5 == 0)
msleep(25);
ret = cros_ec_sensors_cmd_read_u8(ec, EC_MEMMAP_ACC_STATUS,
&status);
if (ret < 0)
return ret;
}
return status;
}
static int cros_ec_sensors_read_data_unsafe(struct iio_dev *indio_dev,
unsigned long scan_mask, s16 *data)
{
struct cros_ec_sensors_core_state *st = iio_priv(indio_dev);
struct cros_ec_device *ec = st->ec;
unsigned int i;
int ret;
for_each_set_bit(i, &scan_mask, indio_dev->masklength) {
ret = cros_ec_sensors_cmd_read_u16(ec,
cros_ec_sensors_idx_to_reg(st, i),
data);
if (ret < 0)
return ret;
data++;
}
return 0;
}
int cros_ec_sensors_read_lpc(struct iio_dev *indio_dev,
unsigned long scan_mask, s16 *data)
{
struct cros_ec_sensors_core_state *st = iio_priv(indio_dev);
struct cros_ec_device *ec = st->ec;
u8 samp_id = 0xff, status = 0;
int ret, attempts = 0;
while ((status & (EC_MEMMAP_ACC_STATUS_BUSY_BIT |
EC_MEMMAP_ACC_STATUS_SAMPLE_ID_MASK)) != samp_id) {
if (attempts++ >= 5)
return -EIO;
ret = cros_ec_sensors_read_until_not_busy(st);
if (ret < 0)
return ret;
samp_id = ret & EC_MEMMAP_ACC_STATUS_SAMPLE_ID_MASK;
ret = cros_ec_sensors_read_data_unsafe(indio_dev, scan_mask,
data);
if (ret < 0)
return ret;
ret = cros_ec_sensors_cmd_read_u8(ec, EC_MEMMAP_ACC_STATUS,
&status);
if (ret < 0)
return ret;
}
return 0;
}
int cros_ec_sensors_read_cmd(struct iio_dev *indio_dev,
unsigned long scan_mask, s16 *data)
{
struct cros_ec_sensors_core_state *st = iio_priv(indio_dev);
int ret;
unsigned int i;
st->param.cmd = MOTIONSENSE_CMD_DATA;
ret = cros_ec_motion_send_host_cmd(st, sizeof(st->resp->data));
if (ret != 0) {
dev_warn(&indio_dev->dev, "Unable to read sensor data\n");
return ret;
}
for_each_set_bit(i, &scan_mask, indio_dev->masklength) {
*data = st->resp->data.data[i];
data++;
}
return 0;
}
irqreturn_t cros_ec_sensors_capture(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct cros_ec_sensors_core_state *st = iio_priv(indio_dev);
int ret;
mutex_lock(&st->cmd_lock);
memset(st->samples, 0, indio_dev->scan_bytes);
ret = st->read_ec_sensors_data(indio_dev,
*(indio_dev->active_scan_mask),
(s16 *)st->samples);
if (ret < 0)
goto done;
iio_push_to_buffers_with_timestamp(indio_dev, st->samples,
iio_get_time_ns(indio_dev));
done:
iio_trigger_notify_done(indio_dev->trig);
mutex_unlock(&st->cmd_lock);
return IRQ_HANDLED;
}
int cros_ec_sensors_core_read(struct cros_ec_sensors_core_state *st,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret = IIO_VAL_INT;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
st->param.cmd = MOTIONSENSE_CMD_EC_RATE;
st->param.ec_rate.data =
EC_MOTION_SENSE_NO_VALUE;
if (cros_ec_motion_send_host_cmd(st, 0))
ret = -EIO;
else
*val = st->resp->ec_rate.ret;
break;
case IIO_CHAN_INFO_FREQUENCY:
st->param.cmd = MOTIONSENSE_CMD_SENSOR_ODR;
st->param.sensor_odr.data =
EC_MOTION_SENSE_NO_VALUE;
if (cros_ec_motion_send_host_cmd(st, 0))
ret = -EIO;
else
*val = st->resp->sensor_odr.ret;
break;
default:
break;
}
return ret;
}
int cros_ec_sensors_core_write(struct cros_ec_sensors_core_state *st,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
int ret = 0;
switch (mask) {
case IIO_CHAN_INFO_FREQUENCY:
st->param.cmd = MOTIONSENSE_CMD_SENSOR_ODR;
st->param.sensor_odr.data = val;
st->param.sensor_odr.roundup = 1;
if (cros_ec_motion_send_host_cmd(st, 0))
ret = -EIO;
break;
case IIO_CHAN_INFO_SAMP_FREQ:
st->param.cmd = MOTIONSENSE_CMD_EC_RATE;
st->param.ec_rate.data = val;
if (cros_ec_motion_send_host_cmd(st, 0))
ret = -EIO;
else
st->curr_sampl_freq = val;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
