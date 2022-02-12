static int bmc150_accel_set_mode(struct bmc150_accel_data *data,
enum bmc150_power_modes mode,
int dur_us)
{
struct device *dev = regmap_get_device(data->regmap);
int i;
int ret;
u8 lpw_bits;
int dur_val = -1;
if (dur_us > 0) {
for (i = 0; i < ARRAY_SIZE(bmc150_accel_sleep_value_table);
++i) {
if (bmc150_accel_sleep_value_table[i].sleep_dur ==
dur_us)
dur_val =
bmc150_accel_sleep_value_table[i].reg_value;
}
} else {
dur_val = 0;
}
if (dur_val < 0)
return -EINVAL;
lpw_bits = mode << BMC150_ACCEL_PMU_MODE_SHIFT;
lpw_bits |= (dur_val << BMC150_ACCEL_PMU_BIT_SLEEP_DUR_SHIFT);
dev_dbg(dev, "Set Mode bits %x\n", lpw_bits);
ret = regmap_write(data->regmap, BMC150_ACCEL_REG_PMU_LPW, lpw_bits);
if (ret < 0) {
dev_err(dev, "Error writing reg_pmu_lpw\n");
return ret;
}
return 0;
}
static int bmc150_accel_set_bw(struct bmc150_accel_data *data, int val,
int val2)
{
int i;
int ret;
for (i = 0; i < ARRAY_SIZE(bmc150_accel_samp_freq_table); ++i) {
if (bmc150_accel_samp_freq_table[i].val == val &&
bmc150_accel_samp_freq_table[i].val2 == val2) {
ret = regmap_write(data->regmap,
BMC150_ACCEL_REG_PMU_BW,
bmc150_accel_samp_freq_table[i].bw_bits);
if (ret < 0)
return ret;
data->bw_bits =
bmc150_accel_samp_freq_table[i].bw_bits;
return 0;
}
}
return -EINVAL;
}
static int bmc150_accel_update_slope(struct bmc150_accel_data *data)
{
struct device *dev = regmap_get_device(data->regmap);
int ret;
ret = regmap_write(data->regmap, BMC150_ACCEL_REG_INT_6,
data->slope_thres);
if (ret < 0) {
dev_err(dev, "Error writing reg_int_6\n");
return ret;
}
ret = regmap_update_bits(data->regmap, BMC150_ACCEL_REG_INT_5,
BMC150_ACCEL_SLOPE_DUR_MASK, data->slope_dur);
if (ret < 0) {
dev_err(dev, "Error updating reg_int_5\n");
return ret;
}
dev_dbg(dev, "%s: %x %x\n", __func__, data->slope_thres,
data->slope_dur);
return ret;
}
static int bmc150_accel_any_motion_setup(struct bmc150_accel_trigger *t,
bool state)
{
if (state)
return bmc150_accel_update_slope(t->data);
return 0;
}
static int bmc150_accel_get_bw(struct bmc150_accel_data *data, int *val,
int *val2)
{
int i;
for (i = 0; i < ARRAY_SIZE(bmc150_accel_samp_freq_table); ++i) {
if (bmc150_accel_samp_freq_table[i].bw_bits == data->bw_bits) {
*val = bmc150_accel_samp_freq_table[i].val;
*val2 = bmc150_accel_samp_freq_table[i].val2;
return IIO_VAL_INT_PLUS_MICRO;
}
}
return -EINVAL;
}
static int bmc150_accel_get_startup_times(struct bmc150_accel_data *data)
{
int i;
for (i = 0; i < ARRAY_SIZE(bmc150_accel_sample_upd_time); ++i) {
if (bmc150_accel_sample_upd_time[i].bw_bits == data->bw_bits)
return bmc150_accel_sample_upd_time[i].msec;
}
return BMC150_ACCEL_MAX_STARTUP_TIME_MS;
}
static int bmc150_accel_set_power_state(struct bmc150_accel_data *data, bool on)
{
struct device *dev = regmap_get_device(data->regmap);
int ret;
if (on) {
ret = pm_runtime_get_sync(dev);
} else {
pm_runtime_mark_last_busy(dev);
ret = pm_runtime_put_autosuspend(dev);
}
if (ret < 0) {
dev_err(dev,
"Failed: bmc150_accel_set_power_state for %d\n", on);
if (on)
pm_runtime_put_noidle(dev);
return ret;
}
return 0;
}
static int bmc150_accel_set_power_state(struct bmc150_accel_data *data, bool on)
{
return 0;
}
static void bmc150_accel_interrupts_setup(struct iio_dev *indio_dev,
struct bmc150_accel_data *data)
{
int i;
for (i = 0; i < BMC150_ACCEL_INTERRUPTS; i++)
data->interrupts[i].info = &bmc150_accel_interrupts[i];
}
static int bmc150_accel_set_interrupt(struct bmc150_accel_data *data, int i,
bool state)
{
struct device *dev = regmap_get_device(data->regmap);
struct bmc150_accel_interrupt *intr = &data->interrupts[i];
const struct bmc150_accel_interrupt_info *info = intr->info;
int ret;
if (state) {
if (atomic_inc_return(&intr->users) > 1)
return 0;
} else {
if (atomic_dec_return(&intr->users) > 0)
return 0;
}
ret = bmc150_accel_set_power_state(data, state);
if (ret < 0)
return ret;
ret = regmap_update_bits(data->regmap, info->map_reg, info->map_bitmask,
(state ? info->map_bitmask : 0));
if (ret < 0) {
dev_err(dev, "Error updating reg_int_map\n");
goto out_fix_power_state;
}
ret = regmap_update_bits(data->regmap, info->en_reg, info->en_bitmask,
(state ? info->en_bitmask : 0));
if (ret < 0) {
dev_err(dev, "Error updating reg_int_en\n");
goto out_fix_power_state;
}
return 0;
out_fix_power_state:
bmc150_accel_set_power_state(data, false);
return ret;
}
static int bmc150_accel_set_scale(struct bmc150_accel_data *data, int val)
{
struct device *dev = regmap_get_device(data->regmap);
int ret, i;
for (i = 0; i < ARRAY_SIZE(data->chip_info->scale_table); ++i) {
if (data->chip_info->scale_table[i].scale == val) {
ret = regmap_write(data->regmap,
BMC150_ACCEL_REG_PMU_RANGE,
data->chip_info->scale_table[i].reg_range);
if (ret < 0) {
dev_err(dev, "Error writing pmu_range\n");
return ret;
}
data->range = data->chip_info->scale_table[i].reg_range;
return 0;
}
}
return -EINVAL;
}
static int bmc150_accel_get_temp(struct bmc150_accel_data *data, int *val)
{
struct device *dev = regmap_get_device(data->regmap);
int ret;
unsigned int value;
mutex_lock(&data->mutex);
ret = regmap_read(data->regmap, BMC150_ACCEL_REG_TEMP, &value);
if (ret < 0) {
dev_err(dev, "Error reading reg_temp\n");
mutex_unlock(&data->mutex);
return ret;
}
*val = sign_extend32(value, 7);
mutex_unlock(&data->mutex);
return IIO_VAL_INT;
}
static int bmc150_accel_get_axis(struct bmc150_accel_data *data,
struct iio_chan_spec const *chan,
int *val)
{
struct device *dev = regmap_get_device(data->regmap);
int ret;
int axis = chan->scan_index;
__le16 raw_val;
mutex_lock(&data->mutex);
ret = bmc150_accel_set_power_state(data, true);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = regmap_bulk_read(data->regmap, BMC150_ACCEL_AXIS_TO_REG(axis),
&raw_val, sizeof(raw_val));
if (ret < 0) {
dev_err(dev, "Error reading axis %d\n", axis);
bmc150_accel_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
*val = sign_extend32(le16_to_cpu(raw_val) >> chan->scan_type.shift,
chan->scan_type.realbits - 1);
ret = bmc150_accel_set_power_state(data, false);
mutex_unlock(&data->mutex);
if (ret < 0)
return ret;
return IIO_VAL_INT;
}
static int bmc150_accel_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_TEMP:
return bmc150_accel_get_temp(data, val);
case IIO_ACCEL:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
else
return bmc150_accel_get_axis(data, chan, val);
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
if (chan->type == IIO_TEMP) {
*val = BMC150_ACCEL_TEMP_CENTER_VAL;
return IIO_VAL_INT;
} else {
return -EINVAL;
}
case IIO_CHAN_INFO_SCALE:
*val = 0;
switch (chan->type) {
case IIO_TEMP:
*val2 = 500000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_ACCEL:
{
int i;
const struct bmc150_scale_info *si;
int st_size = ARRAY_SIZE(data->chip_info->scale_table);
for (i = 0; i < st_size; ++i) {
si = &data->chip_info->scale_table[i];
if (si->reg_range == data->range) {
*val2 = si->scale;
return IIO_VAL_INT_PLUS_MICRO;
}
}
return -EINVAL;
}
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&data->mutex);
ret = bmc150_accel_get_bw(data, val, val2);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
}
static int bmc150_accel_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&data->mutex);
ret = bmc150_accel_set_bw(data, val, val2);
mutex_unlock(&data->mutex);
break;
case IIO_CHAN_INFO_SCALE:
if (val)
return -EINVAL;
mutex_lock(&data->mutex);
ret = bmc150_accel_set_scale(data, val2);
mutex_unlock(&data->mutex);
return ret;
default:
ret = -EINVAL;
}
return ret;
}
static int bmc150_accel_read_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
*val2 = 0;
switch (info) {
case IIO_EV_INFO_VALUE:
*val = data->slope_thres;
break;
case IIO_EV_INFO_PERIOD:
*val = data->slope_dur;
break;
default:
return -EINVAL;
}
return IIO_VAL_INT;
}
static int bmc150_accel_write_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
if (data->ev_enable_state)
return -EBUSY;
switch (info) {
case IIO_EV_INFO_VALUE:
data->slope_thres = val & BMC150_ACCEL_SLOPE_THRES_MASK;
break;
case IIO_EV_INFO_PERIOD:
data->slope_dur = val & BMC150_ACCEL_SLOPE_DUR_MASK;
break;
default:
return -EINVAL;
}
return 0;
}
static int bmc150_accel_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
return data->ev_enable_state;
}
static int bmc150_accel_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
if (state == data->ev_enable_state)
return 0;
mutex_lock(&data->mutex);
ret = bmc150_accel_set_interrupt(data, BMC150_ACCEL_INT_ANY_MOTION,
state);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
data->ev_enable_state = state;
mutex_unlock(&data->mutex);
return 0;
}
static int bmc150_accel_validate_trigger(struct iio_dev *indio_dev,
struct iio_trigger *trig)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
int i;
for (i = 0; i < BMC150_ACCEL_TRIGGERS; i++) {
if (data->triggers[i].indio_trig == trig)
return 0;
}
return -EINVAL;
}
static ssize_t bmc150_accel_get_fifo_watermark(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct bmc150_accel_data *data = iio_priv(indio_dev);
int wm;
mutex_lock(&data->mutex);
wm = data->watermark;
mutex_unlock(&data->mutex);
return sprintf(buf, "%d\n", wm);
}
static ssize_t bmc150_accel_get_fifo_state(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct bmc150_accel_data *data = iio_priv(indio_dev);
bool state;
mutex_lock(&data->mutex);
state = data->fifo_mode;
mutex_unlock(&data->mutex);
return sprintf(buf, "%d\n", state);
}
static int bmc150_accel_set_watermark(struct iio_dev *indio_dev, unsigned val)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
if (val > BMC150_ACCEL_FIFO_LENGTH)
val = BMC150_ACCEL_FIFO_LENGTH;
mutex_lock(&data->mutex);
data->watermark = val;
mutex_unlock(&data->mutex);
return 0;
}
static int bmc150_accel_fifo_transfer(struct bmc150_accel_data *data,
char *buffer, int samples)
{
struct device *dev = regmap_get_device(data->regmap);
int sample_length = 3 * 2;
int ret;
int total_length = samples * sample_length;
int i;
size_t step = regmap_get_raw_read_max(data->regmap);
if (!step || step > total_length)
step = total_length;
else if (step < total_length)
step = sample_length;
for (i = 0; i < total_length; i += step) {
ret = regmap_raw_read(data->regmap, BMC150_ACCEL_REG_FIFO_DATA,
&buffer[i], step);
if (ret)
break;
}
if (ret)
dev_err(dev,
"Error transferring data from fifo in single steps of %zu\n",
step);
return ret;
}
static int __bmc150_accel_fifo_flush(struct iio_dev *indio_dev,
unsigned samples, bool irq)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
struct device *dev = regmap_get_device(data->regmap);
int ret, i;
u8 count;
u16 buffer[BMC150_ACCEL_FIFO_LENGTH * 3];
int64_t tstamp;
uint64_t sample_period;
unsigned int val;
ret = regmap_read(data->regmap, BMC150_ACCEL_REG_FIFO_STATUS, &val);
if (ret < 0) {
dev_err(dev, "Error reading reg_fifo_status\n");
return ret;
}
count = val & 0x7F;
if (!count)
return 0;
if (!irq) {
data->old_timestamp = data->timestamp;
data->timestamp = iio_get_time_ns(indio_dev);
}
sample_period = (data->timestamp - data->old_timestamp);
do_div(sample_period, count);
tstamp = data->timestamp - (count - 1) * sample_period;
if (samples && count > samples)
count = samples;
ret = bmc150_accel_fifo_transfer(data, (u8 *)buffer, count);
if (ret)
return ret;
for (i = 0; i < count; i++) {
u16 sample[8];
int j, bit;
j = 0;
for_each_set_bit(bit, indio_dev->active_scan_mask,
indio_dev->masklength)
memcpy(&sample[j++], &buffer[i * 3 + bit], 2);
iio_push_to_buffers_with_timestamp(indio_dev, sample, tstamp);
tstamp += sample_period;
}
return count;
}
static int bmc150_accel_fifo_flush(struct iio_dev *indio_dev, unsigned samples)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = __bmc150_accel_fifo_flush(indio_dev, samples, false);
mutex_unlock(&data->mutex);
return ret;
}
static irqreturn_t bmc150_accel_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = regmap_bulk_read(data->regmap, BMC150_ACCEL_REG_XOUT_L,
data->buffer, AXIS_MAX * 2);
mutex_unlock(&data->mutex);
if (ret < 0)
goto err_read;
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
pf->timestamp);
err_read:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int bmc150_accel_trig_try_reen(struct iio_trigger *trig)
{
struct bmc150_accel_trigger *t = iio_trigger_get_drvdata(trig);
struct bmc150_accel_data *data = t->data;
struct device *dev = regmap_get_device(data->regmap);
int ret;
if (t == &t->data->triggers[BMC150_ACCEL_TRIGGER_DATA_READY])
return 0;
mutex_lock(&data->mutex);
ret = regmap_write(data->regmap, BMC150_ACCEL_REG_INT_RST_LATCH,
BMC150_ACCEL_INT_MODE_LATCH_INT |
BMC150_ACCEL_INT_MODE_LATCH_RESET);
mutex_unlock(&data->mutex);
if (ret < 0) {
dev_err(dev, "Error writing reg_int_rst_latch\n");
return ret;
}
return 0;
}
static int bmc150_accel_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct bmc150_accel_trigger *t = iio_trigger_get_drvdata(trig);
struct bmc150_accel_data *data = t->data;
int ret;
mutex_lock(&data->mutex);
if (t->enabled == state) {
mutex_unlock(&data->mutex);
return 0;
}
if (t->setup) {
ret = t->setup(t, state);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
}
ret = bmc150_accel_set_interrupt(data, t->intr, state);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
t->enabled = state;
mutex_unlock(&data->mutex);
return ret;
}
static int bmc150_accel_handle_roc_event(struct iio_dev *indio_dev)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
struct device *dev = regmap_get_device(data->regmap);
int dir;
int ret;
unsigned int val;
ret = regmap_read(data->regmap, BMC150_ACCEL_REG_INT_STATUS_2, &val);
if (ret < 0) {
dev_err(dev, "Error reading reg_int_status_2\n");
return ret;
}
if (val & BMC150_ACCEL_ANY_MOTION_BIT_SIGN)
dir = IIO_EV_DIR_FALLING;
else
dir = IIO_EV_DIR_RISING;
if (val & BMC150_ACCEL_ANY_MOTION_BIT_X)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_X,
IIO_EV_TYPE_ROC,
dir),
data->timestamp);
if (val & BMC150_ACCEL_ANY_MOTION_BIT_Y)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Y,
IIO_EV_TYPE_ROC,
dir),
data->timestamp);
if (val & BMC150_ACCEL_ANY_MOTION_BIT_Z)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Z,
IIO_EV_TYPE_ROC,
dir),
data->timestamp);
return ret;
}
static irqreturn_t bmc150_accel_irq_thread_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct bmc150_accel_data *data = iio_priv(indio_dev);
struct device *dev = regmap_get_device(data->regmap);
bool ack = false;
int ret;
mutex_lock(&data->mutex);
if (data->fifo_mode) {
ret = __bmc150_accel_fifo_flush(indio_dev,
BMC150_ACCEL_FIFO_LENGTH, true);
if (ret > 0)
ack = true;
}
if (data->ev_enable_state) {
ret = bmc150_accel_handle_roc_event(indio_dev);
if (ret > 0)
ack = true;
}
if (ack) {
ret = regmap_write(data->regmap, BMC150_ACCEL_REG_INT_RST_LATCH,
BMC150_ACCEL_INT_MODE_LATCH_INT |
BMC150_ACCEL_INT_MODE_LATCH_RESET);
if (ret)
dev_err(dev, "Error writing reg_int_rst_latch\n");
ret = IRQ_HANDLED;
} else {
ret = IRQ_NONE;
}
mutex_unlock(&data->mutex);
return ret;
}
static irqreturn_t bmc150_accel_irq_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct bmc150_accel_data *data = iio_priv(indio_dev);
bool ack = false;
int i;
data->old_timestamp = data->timestamp;
data->timestamp = iio_get_time_ns(indio_dev);
for (i = 0; i < BMC150_ACCEL_TRIGGERS; i++) {
if (data->triggers[i].enabled) {
iio_trigger_poll(data->triggers[i].indio_trig);
ack = true;
break;
}
}
if (data->ev_enable_state || data->fifo_mode)
return IRQ_WAKE_THREAD;
if (ack)
return IRQ_HANDLED;
return IRQ_NONE;
}
static void bmc150_accel_unregister_triggers(struct bmc150_accel_data *data,
int from)
{
int i;
for (i = from; i >= 0; i--) {
if (data->triggers[i].indio_trig) {
iio_trigger_unregister(data->triggers[i].indio_trig);
data->triggers[i].indio_trig = NULL;
}
}
}
static int bmc150_accel_triggers_setup(struct iio_dev *indio_dev,
struct bmc150_accel_data *data)
{
struct device *dev = regmap_get_device(data->regmap);
int i, ret;
for (i = 0; i < BMC150_ACCEL_TRIGGERS; i++) {
struct bmc150_accel_trigger *t = &data->triggers[i];
t->indio_trig = devm_iio_trigger_alloc(dev,
bmc150_accel_triggers[i].name,
indio_dev->name,
indio_dev->id);
if (!t->indio_trig) {
ret = -ENOMEM;
break;
}
t->indio_trig->dev.parent = dev;
t->indio_trig->ops = &bmc150_accel_trigger_ops;
t->intr = bmc150_accel_triggers[i].intr;
t->data = data;
t->setup = bmc150_accel_triggers[i].setup;
iio_trigger_set_drvdata(t->indio_trig, t);
ret = iio_trigger_register(t->indio_trig);
if (ret)
break;
}
if (ret)
bmc150_accel_unregister_triggers(data, i - 1);
return ret;
}
static int bmc150_accel_fifo_set_mode(struct bmc150_accel_data *data)
{
struct device *dev = regmap_get_device(data->regmap);
u8 reg = BMC150_ACCEL_REG_FIFO_CONFIG1;
int ret;
ret = regmap_write(data->regmap, reg, data->fifo_mode);
if (ret < 0) {
dev_err(dev, "Error writing reg_fifo_config1\n");
return ret;
}
if (!data->fifo_mode)
return 0;
ret = regmap_write(data->regmap, BMC150_ACCEL_REG_FIFO_CONFIG0,
data->watermark);
if (ret < 0)
dev_err(dev, "Error writing reg_fifo_config0\n");
return ret;
}
static int bmc150_accel_buffer_preenable(struct iio_dev *indio_dev)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
return bmc150_accel_set_power_state(data, true);
}
static int bmc150_accel_buffer_postenable(struct iio_dev *indio_dev)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret = 0;
if (indio_dev->currentmode == INDIO_BUFFER_TRIGGERED)
return iio_triggered_buffer_postenable(indio_dev);
mutex_lock(&data->mutex);
if (!data->watermark)
goto out;
ret = bmc150_accel_set_interrupt(data, BMC150_ACCEL_INT_WATERMARK,
true);
if (ret)
goto out;
data->fifo_mode = BMC150_ACCEL_FIFO_MODE_FIFO;
ret = bmc150_accel_fifo_set_mode(data);
if (ret) {
data->fifo_mode = 0;
bmc150_accel_set_interrupt(data, BMC150_ACCEL_INT_WATERMARK,
false);
}
out:
mutex_unlock(&data->mutex);
return ret;
}
static int bmc150_accel_buffer_predisable(struct iio_dev *indio_dev)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
if (indio_dev->currentmode == INDIO_BUFFER_TRIGGERED)
return iio_triggered_buffer_predisable(indio_dev);
mutex_lock(&data->mutex);
if (!data->fifo_mode)
goto out;
bmc150_accel_set_interrupt(data, BMC150_ACCEL_INT_WATERMARK, false);
__bmc150_accel_fifo_flush(indio_dev, BMC150_ACCEL_FIFO_LENGTH, false);
data->fifo_mode = 0;
bmc150_accel_fifo_set_mode(data);
out:
mutex_unlock(&data->mutex);
return 0;
}
static int bmc150_accel_buffer_postdisable(struct iio_dev *indio_dev)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
return bmc150_accel_set_power_state(data, false);
}
static int bmc150_accel_chip_init(struct bmc150_accel_data *data)
{
struct device *dev = regmap_get_device(data->regmap);
int ret, i;
unsigned int val;
regmap_write(data->regmap, BMC150_ACCEL_REG_RESET,
BMC150_ACCEL_RESET_VAL);
usleep_range(1800, 2500);
ret = regmap_read(data->regmap, BMC150_ACCEL_REG_CHIP_ID, &val);
if (ret < 0) {
dev_err(dev, "Error: Reading chip id\n");
return ret;
}
dev_dbg(dev, "Chip Id %x\n", val);
for (i = 0; i < ARRAY_SIZE(bmc150_accel_chip_info_tbl); i++) {
if (bmc150_accel_chip_info_tbl[i].chip_id == val) {
data->chip_info = &bmc150_accel_chip_info_tbl[i];
break;
}
}
if (!data->chip_info) {
dev_err(dev, "Invalid chip %x\n", val);
return -ENODEV;
}
ret = bmc150_accel_set_mode(data, BMC150_ACCEL_SLEEP_MODE_NORMAL, 0);
if (ret < 0)
return ret;
ret = bmc150_accel_set_bw(data, BMC150_ACCEL_DEF_BW, 0);
if (ret < 0)
return ret;
ret = regmap_write(data->regmap, BMC150_ACCEL_REG_PMU_RANGE,
BMC150_ACCEL_DEF_RANGE_4G);
if (ret < 0) {
dev_err(dev, "Error writing reg_pmu_range\n");
return ret;
}
data->range = BMC150_ACCEL_DEF_RANGE_4G;
data->slope_thres = BMC150_ACCEL_DEF_SLOPE_THRESHOLD;
data->slope_dur = BMC150_ACCEL_DEF_SLOPE_DURATION;
ret = bmc150_accel_update_slope(data);
if (ret < 0)
return ret;
ret = regmap_write(data->regmap, BMC150_ACCEL_REG_INT_RST_LATCH,
BMC150_ACCEL_INT_MODE_LATCH_INT |
BMC150_ACCEL_INT_MODE_LATCH_RESET);
if (ret < 0) {
dev_err(dev, "Error writing reg_int_rst_latch\n");
return ret;
}
return 0;
}
int bmc150_accel_core_probe(struct device *dev, struct regmap *regmap, int irq,
const char *name, bool block_supported)
{
struct bmc150_accel_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
dev_set_drvdata(dev, indio_dev);
data->irq = irq;
data->regmap = regmap;
ret = bmc150_accel_chip_init(data);
if (ret < 0)
return ret;
mutex_init(&data->mutex);
indio_dev->dev.parent = dev;
indio_dev->channels = data->chip_info->channels;
indio_dev->num_channels = data->chip_info->num_channels;
indio_dev->name = name ? name : data->chip_info->name;
indio_dev->available_scan_masks = bmc150_accel_scan_masks;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &bmc150_accel_info;
ret = iio_triggered_buffer_setup(indio_dev,
&iio_pollfunc_store_time,
bmc150_accel_trigger_handler,
&bmc150_accel_buffer_ops);
if (ret < 0) {
dev_err(dev, "Failed: iio triggered buffer setup\n");
return ret;
}
if (data->irq > 0) {
ret = devm_request_threaded_irq(
dev, data->irq,
bmc150_accel_irq_handler,
bmc150_accel_irq_thread_handler,
IRQF_TRIGGER_RISING,
BMC150_ACCEL_IRQ_NAME,
indio_dev);
if (ret)
goto err_buffer_cleanup;
ret = regmap_write(data->regmap, BMC150_ACCEL_REG_INT_RST_LATCH,
BMC150_ACCEL_INT_MODE_LATCH_RESET);
if (ret < 0) {
dev_err(dev, "Error writing reg_int_rst_latch\n");
goto err_buffer_cleanup;
}
bmc150_accel_interrupts_setup(indio_dev, data);
ret = bmc150_accel_triggers_setup(indio_dev, data);
if (ret)
goto err_buffer_cleanup;
if (block_supported) {
indio_dev->modes |= INDIO_BUFFER_SOFTWARE;
indio_dev->info = &bmc150_accel_info_fifo;
iio_buffer_set_attrs(indio_dev->buffer,
bmc150_accel_fifo_attributes);
}
}
ret = pm_runtime_set_active(dev);
if (ret)
goto err_trigger_unregister;
pm_runtime_enable(dev);
pm_runtime_set_autosuspend_delay(dev, BMC150_AUTO_SUSPEND_DELAY_MS);
pm_runtime_use_autosuspend(dev);
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(dev, "Unable to register iio device\n");
goto err_trigger_unregister;
}
return 0;
err_trigger_unregister:
bmc150_accel_unregister_triggers(data, BMC150_ACCEL_TRIGGERS - 1);
err_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
return ret;
}
int bmc150_accel_core_remove(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct bmc150_accel_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
pm_runtime_disable(dev);
pm_runtime_set_suspended(dev);
pm_runtime_put_noidle(dev);
bmc150_accel_unregister_triggers(data, BMC150_ACCEL_TRIGGERS - 1);
iio_triggered_buffer_cleanup(indio_dev);
mutex_lock(&data->mutex);
bmc150_accel_set_mode(data, BMC150_ACCEL_SLEEP_MODE_DEEP_SUSPEND, 0);
mutex_unlock(&data->mutex);
return 0;
}
static int bmc150_accel_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct bmc150_accel_data *data = iio_priv(indio_dev);
mutex_lock(&data->mutex);
bmc150_accel_set_mode(data, BMC150_ACCEL_SLEEP_MODE_SUSPEND, 0);
mutex_unlock(&data->mutex);
return 0;
}
static int bmc150_accel_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct bmc150_accel_data *data = iio_priv(indio_dev);
mutex_lock(&data->mutex);
bmc150_accel_set_mode(data, BMC150_ACCEL_SLEEP_MODE_NORMAL, 0);
bmc150_accel_fifo_set_mode(data);
mutex_unlock(&data->mutex);
return 0;
}
static int bmc150_accel_runtime_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
dev_dbg(dev, __func__);
ret = bmc150_accel_set_mode(data, BMC150_ACCEL_SLEEP_MODE_SUSPEND, 0);
if (ret < 0)
return -EAGAIN;
return 0;
}
static int bmc150_accel_runtime_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
int sleep_val;
dev_dbg(dev, __func__);
ret = bmc150_accel_set_mode(data, BMC150_ACCEL_SLEEP_MODE_NORMAL, 0);
if (ret < 0)
return ret;
ret = bmc150_accel_fifo_set_mode(data);
if (ret < 0)
return ret;
sleep_val = bmc150_accel_get_startup_times(data);
if (sleep_val < 20)
usleep_range(sleep_val * 1000, 20000);
else
msleep_interruptible(sleep_val);
return 0;
}
