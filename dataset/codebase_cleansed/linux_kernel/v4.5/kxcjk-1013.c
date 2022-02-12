static int kxcjk1013_set_mode(struct kxcjk1013_data *data,
enum kxcjk1013_mode mode)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
return ret;
}
if (mode == STANDBY)
ret &= ~KXCJK1013_REG_CTRL1_BIT_PC1;
else
ret |= KXCJK1013_REG_CTRL1_BIT_PC1;
ret = i2c_smbus_write_byte_data(data->client,
KXCJK1013_REG_CTRL1, ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_ctrl1\n");
return ret;
}
return 0;
}
static int kxcjk1013_get_mode(struct kxcjk1013_data *data,
enum kxcjk1013_mode *mode)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
return ret;
}
if (ret & KXCJK1013_REG_CTRL1_BIT_PC1)
*mode = OPERATION;
else
*mode = STANDBY;
return 0;
}
static int kxcjk1013_set_range(struct kxcjk1013_data *data, int range_index)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
return ret;
}
ret &= ~(KXCJK1013_REG_CTRL1_BIT_GSEL0 |
KXCJK1013_REG_CTRL1_BIT_GSEL1);
ret |= (KXCJK1013_scale_table[range_index].gsel_0 << 3);
ret |= (KXCJK1013_scale_table[range_index].gsel_1 << 4);
ret = i2c_smbus_write_byte_data(data->client,
KXCJK1013_REG_CTRL1,
ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_ctrl1\n");
return ret;
}
data->range = range_index;
return 0;
}
static int kxcjk1013_chip_init(struct kxcjk1013_data *data)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_WHO_AM_I);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading who_am_i\n");
return ret;
}
dev_dbg(&data->client->dev, "KXCJK1013 Chip Id %x\n", ret);
ret = kxcjk1013_set_mode(data, STANDBY);
if (ret < 0)
return ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
return ret;
}
ret |= KXCJK1013_REG_CTRL1_BIT_RES;
ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_CTRL1,
ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_ctrl\n");
return ret;
}
ret = kxcjk1013_set_range(data, KXCJK1013_RANGE_4G);
if (ret < 0)
return ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_DATA_CTRL);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_data_ctrl\n");
return ret;
}
data->odr_bits = ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_ctrl1\n");
return ret;
}
if (data->active_high_intr)
ret |= KXCJK1013_REG_INT_REG1_BIT_IEA;
else
ret &= ~KXCJK1013_REG_INT_REG1_BIT_IEA;
ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_INT_CTRL1,
ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_ctrl1\n");
return ret;
}
ret = kxcjk1013_set_mode(data, OPERATION);
if (ret < 0)
return ret;
data->wake_thres = KXCJK1013_DEFAULT_WAKE_THRES;
return 0;
}
static int kxcjk1013_get_startup_times(struct kxcjk1013_data *data)
{
int i;
int idx = data->chipset;
for (i = 0; i < ARRAY_SIZE(odr_start_up_times[idx]); ++i) {
if (odr_start_up_times[idx][i].odr_bits == data->odr_bits)
return odr_start_up_times[idx][i].usec;
}
return KXCJK1013_MAX_STARTUP_TIME_US;
}
static int kxcjk1013_set_power_state(struct kxcjk1013_data *data, bool on)
{
#ifdef CONFIG_PM
int ret;
if (on)
ret = pm_runtime_get_sync(&data->client->dev);
else {
pm_runtime_mark_last_busy(&data->client->dev);
ret = pm_runtime_put_autosuspend(&data->client->dev);
}
if (ret < 0) {
dev_err(&data->client->dev,
"Failed: kxcjk1013_set_power_state for %d\n", on);
if (on)
pm_runtime_put_noidle(&data->client->dev);
return ret;
}
#endif
return 0;
}
static int kxcjk1013_chip_update_thresholds(struct kxcjk1013_data *data)
{
int ret;
ret = i2c_smbus_write_byte_data(data->client,
KXCJK1013_REG_WAKE_TIMER,
data->wake_dur);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_wake_timer\n");
return ret;
}
ret = i2c_smbus_write_byte_data(data->client,
KXCJK1013_REG_WAKE_THRES,
data->wake_thres);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_wake_thres\n");
return ret;
}
return 0;
}
static int kxcjk1013_setup_any_motion_interrupt(struct kxcjk1013_data *data,
bool status)
{
int ret;
enum kxcjk1013_mode store_mode;
ret = kxcjk1013_get_mode(data, &store_mode);
if (ret < 0)
return ret;
ret = kxcjk1013_set_mode(data, STANDBY);
if (ret < 0)
return ret;
ret = kxcjk1013_chip_update_thresholds(data);
if (ret < 0)
return ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_ctrl1\n");
return ret;
}
if (status)
ret |= KXCJK1013_REG_INT_REG1_BIT_IEN;
else
ret &= ~KXCJK1013_REG_INT_REG1_BIT_IEN;
ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_INT_CTRL1,
ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_ctrl1\n");
return ret;
}
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
return ret;
}
if (status)
ret |= KXCJK1013_REG_CTRL1_BIT_WUFE;
else
ret &= ~KXCJK1013_REG_CTRL1_BIT_WUFE;
ret = i2c_smbus_write_byte_data(data->client,
KXCJK1013_REG_CTRL1, ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_ctrl1\n");
return ret;
}
if (store_mode == OPERATION) {
ret = kxcjk1013_set_mode(data, OPERATION);
if (ret < 0)
return ret;
}
return 0;
}
static int kxcjk1013_setup_new_data_interrupt(struct kxcjk1013_data *data,
bool status)
{
int ret;
enum kxcjk1013_mode store_mode;
ret = kxcjk1013_get_mode(data, &store_mode);
if (ret < 0)
return ret;
ret = kxcjk1013_set_mode(data, STANDBY);
if (ret < 0)
return ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_ctrl1\n");
return ret;
}
if (status)
ret |= KXCJK1013_REG_INT_REG1_BIT_IEN;
else
ret &= ~KXCJK1013_REG_INT_REG1_BIT_IEN;
ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_INT_CTRL1,
ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_ctrl1\n");
return ret;
}
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
return ret;
}
if (status)
ret |= KXCJK1013_REG_CTRL1_BIT_DRDY;
else
ret &= ~KXCJK1013_REG_CTRL1_BIT_DRDY;
ret = i2c_smbus_write_byte_data(data->client,
KXCJK1013_REG_CTRL1, ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_ctrl1\n");
return ret;
}
if (store_mode == OPERATION) {
ret = kxcjk1013_set_mode(data, OPERATION);
if (ret < 0)
return ret;
}
return 0;
}
static int kxcjk1013_convert_freq_to_bit(int val, int val2)
{
int i;
for (i = 0; i < ARRAY_SIZE(samp_freq_table); ++i) {
if (samp_freq_table[i].val == val &&
samp_freq_table[i].val2 == val2) {
return samp_freq_table[i].odr_bits;
}
}
return -EINVAL;
}
static int kxcjk1013_convert_wake_odr_to_bit(int val, int val2)
{
int i;
for (i = 0; i < ARRAY_SIZE(wake_odr_data_rate_table); ++i) {
if (wake_odr_data_rate_table[i].val == val &&
wake_odr_data_rate_table[i].val2 == val2) {
return wake_odr_data_rate_table[i].odr_bits;
}
}
return -EINVAL;
}
static int kxcjk1013_set_odr(struct kxcjk1013_data *data, int val, int val2)
{
int ret;
int odr_bits;
enum kxcjk1013_mode store_mode;
ret = kxcjk1013_get_mode(data, &store_mode);
if (ret < 0)
return ret;
odr_bits = kxcjk1013_convert_freq_to_bit(val, val2);
if (odr_bits < 0)
return odr_bits;
ret = kxcjk1013_set_mode(data, STANDBY);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_DATA_CTRL,
odr_bits);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing data_ctrl\n");
return ret;
}
data->odr_bits = odr_bits;
odr_bits = kxcjk1013_convert_wake_odr_to_bit(val, val2);
if (odr_bits < 0)
return odr_bits;
ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_CTRL2,
odr_bits);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_ctrl2\n");
return ret;
}
if (store_mode == OPERATION) {
ret = kxcjk1013_set_mode(data, OPERATION);
if (ret < 0)
return ret;
}
return 0;
}
static int kxcjk1013_get_odr(struct kxcjk1013_data *data, int *val, int *val2)
{
int i;
for (i = 0; i < ARRAY_SIZE(samp_freq_table); ++i) {
if (samp_freq_table[i].odr_bits == data->odr_bits) {
*val = samp_freq_table[i].val;
*val2 = samp_freq_table[i].val2;
return IIO_VAL_INT_PLUS_MICRO;
}
}
return -EINVAL;
}
static int kxcjk1013_get_acc_reg(struct kxcjk1013_data *data, int axis)
{
u8 reg = KXCJK1013_REG_XOUT_L + axis * 2;
int ret;
ret = i2c_smbus_read_word_data(data->client, reg);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to read accel_%c registers\n", 'x' + axis);
return ret;
}
return ret;
}
static int kxcjk1013_set_scale(struct kxcjk1013_data *data, int val)
{
int ret, i;
enum kxcjk1013_mode store_mode;
for (i = 0; i < ARRAY_SIZE(KXCJK1013_scale_table); ++i) {
if (KXCJK1013_scale_table[i].scale == val) {
ret = kxcjk1013_get_mode(data, &store_mode);
if (ret < 0)
return ret;
ret = kxcjk1013_set_mode(data, STANDBY);
if (ret < 0)
return ret;
ret = kxcjk1013_set_range(data, i);
if (ret < 0)
return ret;
if (store_mode == OPERATION) {
ret = kxcjk1013_set_mode(data, OPERATION);
if (ret)
return ret;
}
return 0;
}
}
return -EINVAL;
}
static int kxcjk1013_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&data->mutex);
if (iio_buffer_enabled(indio_dev))
ret = -EBUSY;
else {
ret = kxcjk1013_set_power_state(data, true);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = kxcjk1013_get_acc_reg(data, chan->scan_index);
if (ret < 0) {
kxcjk1013_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
*val = sign_extend32(ret >> 4, 11);
ret = kxcjk1013_set_power_state(data, false);
}
mutex_unlock(&data->mutex);
if (ret < 0)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = KXCJK1013_scale_table[data->range].scale;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&data->mutex);
ret = kxcjk1013_get_odr(data, val, val2);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
}
static int kxcjk1013_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val,
int val2, long mask)
{
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&data->mutex);
ret = kxcjk1013_set_odr(data, val, val2);
mutex_unlock(&data->mutex);
break;
case IIO_CHAN_INFO_SCALE:
if (val)
return -EINVAL;
mutex_lock(&data->mutex);
ret = kxcjk1013_set_scale(data, val2);
mutex_unlock(&data->mutex);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int kxcjk1013_read_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
struct kxcjk1013_data *data = iio_priv(indio_dev);
*val2 = 0;
switch (info) {
case IIO_EV_INFO_VALUE:
*val = data->wake_thres;
break;
case IIO_EV_INFO_PERIOD:
*val = data->wake_dur;
break;
default:
return -EINVAL;
}
return IIO_VAL_INT;
}
static int kxcjk1013_write_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
struct kxcjk1013_data *data = iio_priv(indio_dev);
if (data->ev_enable_state)
return -EBUSY;
switch (info) {
case IIO_EV_INFO_VALUE:
data->wake_thres = val;
break;
case IIO_EV_INFO_PERIOD:
data->wake_dur = val;
break;
default:
return -EINVAL;
}
return 0;
}
static int kxcjk1013_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct kxcjk1013_data *data = iio_priv(indio_dev);
return data->ev_enable_state;
}
static int kxcjk1013_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret;
if (state && data->ev_enable_state)
return 0;
mutex_lock(&data->mutex);
if (!state && data->motion_trigger_on) {
data->ev_enable_state = 0;
mutex_unlock(&data->mutex);
return 0;
}
ret = kxcjk1013_set_power_state(data, state);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = kxcjk1013_setup_any_motion_interrupt(data, state);
if (ret < 0) {
kxcjk1013_set_power_state(data, false);
data->ev_enable_state = 0;
mutex_unlock(&data->mutex);
return ret;
}
data->ev_enable_state = state;
mutex_unlock(&data->mutex);
return 0;
}
static int kxcjk1013_buffer_preenable(struct iio_dev *indio_dev)
{
struct kxcjk1013_data *data = iio_priv(indio_dev);
return kxcjk1013_set_power_state(data, true);
}
static int kxcjk1013_buffer_postdisable(struct iio_dev *indio_dev)
{
struct kxcjk1013_data *data = iio_priv(indio_dev);
return kxcjk1013_set_power_state(data, false);
}
static irqreturn_t kxcjk1013_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct kxcjk1013_data *data = iio_priv(indio_dev);
int bit, ret, i = 0;
mutex_lock(&data->mutex);
for_each_set_bit(bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
ret = kxcjk1013_get_acc_reg(data, bit);
if (ret < 0) {
mutex_unlock(&data->mutex);
goto err;
}
data->buffer[i++] = ret;
}
mutex_unlock(&data->mutex);
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
data->timestamp);
err:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int kxcjk1013_trig_try_reen(struct iio_trigger *trig)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_REL);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_rel\n");
return ret;
}
return 0;
}
static int kxcjk1013_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
if (!state && data->ev_enable_state && data->motion_trigger_on) {
data->motion_trigger_on = false;
mutex_unlock(&data->mutex);
return 0;
}
ret = kxcjk1013_set_power_state(data, state);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
if (data->motion_trig == trig)
ret = kxcjk1013_setup_any_motion_interrupt(data, state);
else
ret = kxcjk1013_setup_new_data_interrupt(data, state);
if (ret < 0) {
kxcjk1013_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
if (data->motion_trig == trig)
data->motion_trigger_on = state;
else
data->dready_trigger_on = state;
mutex_unlock(&data->mutex);
return 0;
}
static irqreturn_t kxcjk1013_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_SRC1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_src1\n");
goto ack_intr;
}
if (ret & 0x02) {
ret = i2c_smbus_read_byte_data(data->client,
KXCJK1013_REG_INT_SRC2);
if (ret < 0) {
dev_err(&data->client->dev,
"Error reading reg_int_src2\n");
goto ack_intr;
}
if (ret & KXCJK1013_REG_INT_SRC2_BIT_XN)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_X,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
data->timestamp);
if (ret & KXCJK1013_REG_INT_SRC2_BIT_XP)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_X,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
data->timestamp);
if (ret & KXCJK1013_REG_INT_SRC2_BIT_YN)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Y,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
data->timestamp);
if (ret & KXCJK1013_REG_INT_SRC2_BIT_YP)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Y,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
data->timestamp);
if (ret & KXCJK1013_REG_INT_SRC2_BIT_ZN)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Z,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
data->timestamp);
if (ret & KXCJK1013_REG_INT_SRC2_BIT_ZP)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Z,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
data->timestamp);
}
ack_intr:
if (data->dready_trigger_on)
return IRQ_HANDLED;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_REL);
if (ret < 0)
dev_err(&data->client->dev, "Error reading reg_int_rel\n");
return IRQ_HANDLED;
}
static irqreturn_t kxcjk1013_data_rdy_trig_poll(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct kxcjk1013_data *data = iio_priv(indio_dev);
data->timestamp = iio_get_time_ns();
if (data->dready_trigger_on)
iio_trigger_poll(data->dready_trig);
else if (data->motion_trigger_on)
iio_trigger_poll(data->motion_trig);
if (data->ev_enable_state)
return IRQ_WAKE_THREAD;
else
return IRQ_HANDLED;
}
static const char *kxcjk1013_match_acpi_device(struct device *dev,
enum kx_chipset *chipset,
bool *is_smo8500_device)
{
const struct acpi_device_id *id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return NULL;
if (strcmp(id->id, "SMO8500") == 0)
*is_smo8500_device = true;
*chipset = (enum kx_chipset)id->driver_data;
return dev_name(dev);
}
static int kxcjk1013_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct kxcjk1013_data *data;
struct iio_dev *indio_dev;
struct kxcjk_1013_platform_data *pdata;
const char *name;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
pdata = dev_get_platdata(&client->dev);
if (pdata)
data->active_high_intr = pdata->active_high_intr;
else
data->active_high_intr = true;
if (id) {
data->chipset = (enum kx_chipset)(id->driver_data);
name = id->name;
} else if (ACPI_HANDLE(&client->dev)) {
name = kxcjk1013_match_acpi_device(&client->dev,
&data->chipset,
&data->is_smo8500_device);
} else
return -ENODEV;
ret = kxcjk1013_chip_init(data);
if (ret < 0)
return ret;
mutex_init(&data->mutex);
indio_dev->dev.parent = &client->dev;
indio_dev->channels = kxcjk1013_channels;
indio_dev->num_channels = ARRAY_SIZE(kxcjk1013_channels);
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &kxcjk1013_info;
if (client->irq > 0 && !data->is_smo8500_device) {
ret = devm_request_threaded_irq(&client->dev, client->irq,
kxcjk1013_data_rdy_trig_poll,
kxcjk1013_event_handler,
IRQF_TRIGGER_RISING,
KXCJK1013_IRQ_NAME,
indio_dev);
if (ret)
goto err_poweroff;
data->dready_trig = devm_iio_trigger_alloc(&client->dev,
"%s-dev%d",
indio_dev->name,
indio_dev->id);
if (!data->dready_trig) {
ret = -ENOMEM;
goto err_poweroff;
}
data->motion_trig = devm_iio_trigger_alloc(&client->dev,
"%s-any-motion-dev%d",
indio_dev->name,
indio_dev->id);
if (!data->motion_trig) {
ret = -ENOMEM;
goto err_poweroff;
}
data->dready_trig->dev.parent = &client->dev;
data->dready_trig->ops = &kxcjk1013_trigger_ops;
iio_trigger_set_drvdata(data->dready_trig, indio_dev);
indio_dev->trig = data->dready_trig;
iio_trigger_get(indio_dev->trig);
ret = iio_trigger_register(data->dready_trig);
if (ret)
goto err_poweroff;
data->motion_trig->dev.parent = &client->dev;
data->motion_trig->ops = &kxcjk1013_trigger_ops;
iio_trigger_set_drvdata(data->motion_trig, indio_dev);
ret = iio_trigger_register(data->motion_trig);
if (ret) {
data->motion_trig = NULL;
goto err_trigger_unregister;
}
}
ret = iio_triggered_buffer_setup(indio_dev,
&iio_pollfunc_store_time,
kxcjk1013_trigger_handler,
&kxcjk1013_buffer_setup_ops);
if (ret < 0) {
dev_err(&client->dev, "iio triggered buffer setup failed\n");
goto err_trigger_unregister;
}
ret = pm_runtime_set_active(&client->dev);
if (ret)
goto err_buffer_cleanup;
pm_runtime_enable(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev,
KXCJK1013_SLEEP_DELAY_MS);
pm_runtime_use_autosuspend(&client->dev);
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "unable to register iio device\n");
goto err_buffer_cleanup;
}
return 0;
err_buffer_cleanup:
if (data->dready_trig)
iio_triggered_buffer_cleanup(indio_dev);
err_trigger_unregister:
if (data->dready_trig)
iio_trigger_unregister(data->dready_trig);
if (data->motion_trig)
iio_trigger_unregister(data->motion_trig);
err_poweroff:
kxcjk1013_set_mode(data, STANDBY);
return ret;
}
static int kxcjk1013_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct kxcjk1013_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
if (data->dready_trig) {
iio_triggered_buffer_cleanup(indio_dev);
iio_trigger_unregister(data->dready_trig);
iio_trigger_unregister(data->motion_trig);
}
mutex_lock(&data->mutex);
kxcjk1013_set_mode(data, STANDBY);
mutex_unlock(&data->mutex);
return 0;
}
static int kxcjk1013_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = kxcjk1013_set_mode(data, STANDBY);
mutex_unlock(&data->mutex);
return ret;
}
static int kxcjk1013_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret = 0;
mutex_lock(&data->mutex);
ret = kxcjk1013_set_mode(data, OPERATION);
mutex_unlock(&data->mutex);
return ret;
}
static int kxcjk1013_runtime_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret;
ret = kxcjk1013_set_mode(data, STANDBY);
if (ret < 0) {
dev_err(&data->client->dev, "powering off device failed\n");
return -EAGAIN;
}
return 0;
}
static int kxcjk1013_runtime_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret;
int sleep_val;
ret = kxcjk1013_set_mode(data, OPERATION);
if (ret < 0)
return ret;
sleep_val = kxcjk1013_get_startup_times(data);
if (sleep_val < 20000)
usleep_range(sleep_val, 20000);
else
msleep_interruptible(sleep_val/1000);
return 0;
}
