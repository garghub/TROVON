static int sca3000_write_reg(struct sca3000_state *st, u8 address, u8 val)
{
st->tx[0] = SCA3000_WRITE_REG(address);
st->tx[1] = val;
return spi_write(st->us, st->tx, 2);
}
static int sca3000_read_data_short(struct sca3000_state *st,
u8 reg_address_high,
int len)
{
struct spi_transfer xfer[2] = {
{
.len = 1,
.tx_buf = st->tx,
}, {
.len = len,
.rx_buf = st->rx,
}
};
st->tx[0] = SCA3000_READ_REG(reg_address_high);
return spi_sync_transfer(st->us, xfer, ARRAY_SIZE(xfer));
}
static int sca3000_reg_lock_on(struct sca3000_state *st)
{
int ret;
ret = sca3000_read_data_short(st, SCA3000_REG_STATUS_ADDR, 1);
if (ret < 0)
return ret;
return !(st->rx[0] & SCA3000_LOCKED);
}
static int __sca3000_unlock_reg_lock(struct sca3000_state *st)
{
struct spi_transfer xfer[3] = {
{
.len = 2,
.cs_change = 1,
.tx_buf = st->tx,
}, {
.len = 2,
.cs_change = 1,
.tx_buf = st->tx + 2,
}, {
.len = 2,
.tx_buf = st->tx + 4,
},
};
st->tx[0] = SCA3000_WRITE_REG(SCA3000_REG_UNLOCK_ADDR);
st->tx[1] = 0x00;
st->tx[2] = SCA3000_WRITE_REG(SCA3000_REG_UNLOCK_ADDR);
st->tx[3] = 0x50;
st->tx[4] = SCA3000_WRITE_REG(SCA3000_REG_UNLOCK_ADDR);
st->tx[5] = 0xA0;
return spi_sync_transfer(st->us, xfer, ARRAY_SIZE(xfer));
}
static int sca3000_write_ctrl_reg(struct sca3000_state *st,
u8 sel,
uint8_t val)
{
int ret;
ret = sca3000_reg_lock_on(st);
if (ret < 0)
goto error_ret;
if (ret) {
ret = __sca3000_unlock_reg_lock(st);
if (ret)
goto error_ret;
}
ret = sca3000_write_reg(st, SCA3000_REG_CTRL_SEL_ADDR, sel);
if (ret)
goto error_ret;
ret = sca3000_write_reg(st, SCA3000_REG_CTRL_DATA_ADDR, val);
error_ret:
return ret;
}
static int sca3000_read_ctrl_reg(struct sca3000_state *st,
u8 ctrl_reg)
{
int ret;
ret = sca3000_reg_lock_on(st);
if (ret < 0)
goto error_ret;
if (ret) {
ret = __sca3000_unlock_reg_lock(st);
if (ret)
goto error_ret;
}
ret = sca3000_write_reg(st, SCA3000_REG_CTRL_SEL_ADDR, ctrl_reg);
if (ret)
goto error_ret;
ret = sca3000_read_data_short(st, SCA3000_REG_CTRL_DATA_ADDR, 1);
if (ret)
goto error_ret;
return st->rx[0];
error_ret:
return ret;
}
static int sca3000_print_rev(struct iio_dev *indio_dev)
{
int ret;
struct sca3000_state *st = iio_priv(indio_dev);
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_REVID_ADDR, 1);
if (ret < 0)
goto error_ret;
dev_info(&indio_dev->dev,
"sca3000 revision major=%lu, minor=%lu\n",
st->rx[0] & SCA3000_REG_REVID_MAJOR_MASK,
st->rx[0] & SCA3000_REG_REVID_MINOR_MASK);
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static ssize_t
sca3000_show_available_3db_freqs(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct sca3000_state *st = iio_priv(indio_dev);
int len;
len = sprintf(buf, "%d", st->info->measurement_mode_3db_freq);
if (st->info->option_mode_1)
len += sprintf(buf + len, " %d",
st->info->option_mode_1_3db_freq);
if (st->info->option_mode_2)
len += sprintf(buf + len, " %d",
st->info->option_mode_2_3db_freq);
len += sprintf(buf + len, "\n");
return len;
}
static inline int __sca3000_get_base_freq(struct sca3000_state *st,
const struct sca3000_chip_info *info,
int *base_freq)
{
int ret;
ret = sca3000_read_data_short(st, SCA3000_REG_MODE_ADDR, 1);
if (ret)
goto error_ret;
switch (SCA3000_REG_MODE_MODE_MASK & st->rx[0]) {
case SCA3000_REG_MODE_MEAS_MODE_NORMAL:
*base_freq = info->measurement_mode_freq;
break;
case SCA3000_REG_MODE_MEAS_MODE_OP_1:
*base_freq = info->option_mode_1_freq;
break;
case SCA3000_REG_MODE_MEAS_MODE_OP_2:
*base_freq = info->option_mode_2_freq;
break;
default:
ret = -EINVAL;
}
error_ret:
return ret;
}
static int sca3000_read_raw_samp_freq(struct sca3000_state *st, int *val)
{
int ret;
ret = __sca3000_get_base_freq(st, st->info, val);
if (ret)
return ret;
ret = sca3000_read_ctrl_reg(st, SCA3000_REG_CTRL_SEL_OUT_CTRL);
if (ret < 0)
return ret;
if (*val > 0) {
ret &= SCA3000_REG_OUT_CTRL_BUF_DIV_MASK;
switch (ret) {
case SCA3000_REG_OUT_CTRL_BUF_DIV_2:
*val /= 2;
break;
case SCA3000_REG_OUT_CTRL_BUF_DIV_4:
*val /= 4;
break;
}
}
return 0;
}
static int sca3000_write_raw_samp_freq(struct sca3000_state *st, int val)
{
int ret, base_freq, ctrlval;
ret = __sca3000_get_base_freq(st, st->info, &base_freq);
if (ret)
return ret;
ret = sca3000_read_ctrl_reg(st, SCA3000_REG_CTRL_SEL_OUT_CTRL);
if (ret < 0)
return ret;
ctrlval = ret & ~SCA3000_REG_OUT_CTRL_BUF_DIV_MASK;
if (val == base_freq / 2)
ctrlval |= SCA3000_REG_OUT_CTRL_BUF_DIV_2;
if (val == base_freq / 4)
ctrlval |= SCA3000_REG_OUT_CTRL_BUF_DIV_4;
else if (val != base_freq)
return -EINVAL;
return sca3000_write_ctrl_reg(st, SCA3000_REG_CTRL_SEL_OUT_CTRL,
ctrlval);
}
static int sca3000_read_3db_freq(struct sca3000_state *st, int *val)
{
int ret;
ret = sca3000_read_data_short(st, SCA3000_REG_MODE_ADDR, 1);
if (ret)
return ret;
st->rx[0] &= SCA3000_REG_MODE_MODE_MASK;
switch (st->rx[0]) {
case SCA3000_REG_MODE_MEAS_MODE_NORMAL:
*val = st->info->measurement_mode_3db_freq;
return IIO_VAL_INT;
case SCA3000_REG_MODE_MEAS_MODE_MOT_DET:
return -EBUSY;
case SCA3000_REG_MODE_MEAS_MODE_OP_1:
*val = st->info->option_mode_1_3db_freq;
return IIO_VAL_INT;
case SCA3000_REG_MODE_MEAS_MODE_OP_2:
*val = st->info->option_mode_2_3db_freq;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int sca3000_write_3db_freq(struct sca3000_state *st, int val)
{
int ret;
int mode;
if (val == st->info->measurement_mode_3db_freq)
mode = SCA3000_REG_MODE_MEAS_MODE_NORMAL;
else if (st->info->option_mode_1 &&
(val == st->info->option_mode_1_3db_freq))
mode = SCA3000_REG_MODE_MEAS_MODE_OP_1;
else if (st->info->option_mode_2 &&
(val == st->info->option_mode_2_3db_freq))
mode = SCA3000_REG_MODE_MEAS_MODE_OP_2;
else
return -EINVAL;
ret = sca3000_read_data_short(st, SCA3000_REG_MODE_ADDR, 1);
if (ret)
return ret;
st->rx[0] &= ~SCA3000_REG_MODE_MODE_MASK;
st->rx[0] |= (mode & SCA3000_REG_MODE_MODE_MASK);
return sca3000_write_reg(st, SCA3000_REG_MODE_ADDR, st->rx[0]);
}
static int sca3000_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct sca3000_state *st = iio_priv(indio_dev);
int ret;
u8 address;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&st->lock);
if (chan->type == IIO_ACCEL) {
if (st->mo_det_use_count) {
mutex_unlock(&st->lock);
return -EBUSY;
}
address = sca3000_addresses[chan->address][0];
ret = sca3000_read_data_short(st, address, 2);
if (ret < 0) {
mutex_unlock(&st->lock);
return ret;
}
*val = (be16_to_cpup((__be16 *)st->rx) >> 3) & 0x1FFF;
*val = ((*val) << (sizeof(*val) * 8 - 13)) >>
(sizeof(*val) * 8 - 13);
} else {
ret = sca3000_read_data_short(st,
SCA3000_REG_TEMP_MSB_ADDR,
2);
if (ret < 0) {
mutex_unlock(&st->lock);
return ret;
}
*val = ((st->rx[0] & 0x3F) << 3) |
((st->rx[1] & 0xE0) >> 5);
}
mutex_unlock(&st->lock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
if (chan->type == IIO_ACCEL)
*val2 = st->info->scale;
else
*val2 = 555556;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_OFFSET:
*val = -214;
*val2 = 600000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&st->lock);
ret = sca3000_read_raw_samp_freq(st, val);
mutex_unlock(&st->lock);
return ret ? ret : IIO_VAL_INT;
case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
mutex_lock(&st->lock);
ret = sca3000_read_3db_freq(st, val);
mutex_unlock(&st->lock);
return ret;
default:
return -EINVAL;
}
}
static int sca3000_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct sca3000_state *st = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
if (val2)
return -EINVAL;
mutex_lock(&st->lock);
ret = sca3000_write_raw_samp_freq(st, val);
mutex_unlock(&st->lock);
return ret;
case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
if (val2)
return -EINVAL;
mutex_lock(&st->lock);
ret = sca3000_write_3db_freq(st, val);
mutex_unlock(&st->lock);
default:
return -EINVAL;
}
return ret;
}
static ssize_t sca3000_read_av_freq(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct sca3000_state *st = iio_priv(indio_dev);
int len = 0, ret, val;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_MODE_ADDR, 1);
val = st->rx[0];
mutex_unlock(&st->lock);
if (ret)
goto error_ret;
switch (val & SCA3000_REG_MODE_MODE_MASK) {
case SCA3000_REG_MODE_MEAS_MODE_NORMAL:
len += sprintf(buf + len, "%d %d %d\n",
st->info->measurement_mode_freq,
st->info->measurement_mode_freq / 2,
st->info->measurement_mode_freq / 4);
break;
case SCA3000_REG_MODE_MEAS_MODE_OP_1:
len += sprintf(buf + len, "%d %d %d\n",
st->info->option_mode_1_freq,
st->info->option_mode_1_freq / 2,
st->info->option_mode_1_freq / 4);
break;
case SCA3000_REG_MODE_MEAS_MODE_OP_2:
len += sprintf(buf + len, "%d %d %d\n",
st->info->option_mode_2_freq,
st->info->option_mode_2_freq / 2,
st->info->option_mode_2_freq / 4);
break;
}
return len;
error_ret:
return ret;
}
static int sca3000_read_event_value(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
int ret, i;
struct sca3000_state *st = iio_priv(indio_dev);
switch (info) {
case IIO_EV_INFO_VALUE:
mutex_lock(&st->lock);
ret = sca3000_read_ctrl_reg(st,
sca3000_addresses[chan->address][1]);
mutex_unlock(&st->lock);
if (ret < 0)
return ret;
*val = 0;
if (chan->channel2 == IIO_MOD_Y)
for_each_set_bit(i, (unsigned long *)&ret,
ARRAY_SIZE(st->info->mot_det_mult_y))
*val += st->info->mot_det_mult_y[i];
else
for_each_set_bit(i, (unsigned long *)&ret,
ARRAY_SIZE(st->info->mot_det_mult_xz))
*val += st->info->mot_det_mult_xz[i];
return IIO_VAL_INT;
case IIO_EV_INFO_PERIOD:
*val = 0;
*val2 = 226000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int sca3000_write_event_value(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
struct sca3000_state *st = iio_priv(indio_dev);
int ret;
int i;
u8 nonlinear = 0;
if (chan->channel2 == IIO_MOD_Y) {
i = ARRAY_SIZE(st->info->mot_det_mult_y);
while (i > 0)
if (val >= st->info->mot_det_mult_y[--i]) {
nonlinear |= (1 << i);
val -= st->info->mot_det_mult_y[i];
}
} else {
i = ARRAY_SIZE(st->info->mot_det_mult_xz);
while (i > 0)
if (val >= st->info->mot_det_mult_xz[--i]) {
nonlinear |= (1 << i);
val -= st->info->mot_det_mult_xz[i];
}
}
mutex_lock(&st->lock);
ret = sca3000_write_ctrl_reg(st,
sca3000_addresses[chan->address][1],
nonlinear);
mutex_unlock(&st->lock);
return ret;
}
static int sca3000_read_data(struct sca3000_state *st,
u8 reg_address_high,
u8 *rx,
int len)
{
int ret;
struct spi_transfer xfer[2] = {
{
.len = 1,
.tx_buf = st->tx,
}, {
.len = len,
.rx_buf = rx,
}
};
st->tx[0] = SCA3000_READ_REG(reg_address_high);
ret = spi_sync_transfer(st->us, xfer, ARRAY_SIZE(xfer));
if (ret) {
dev_err(get_device(&st->us->dev), "problem reading register");
return ret;
}
return 0;
}
static void sca3000_ring_int_process(u8 val, struct iio_dev *indio_dev)
{
struct sca3000_state *st = iio_priv(indio_dev);
int ret, i, num_available;
mutex_lock(&st->lock);
if (val & SCA3000_REG_INT_STATUS_HALF) {
ret = sca3000_read_data_short(st, SCA3000_REG_BUF_COUNT_ADDR,
1);
if (ret)
goto error_ret;
num_available = st->rx[0];
ret = sca3000_read_data(st, SCA3000_REG_RING_OUT_ADDR, st->rx,
num_available * 2);
if (ret)
goto error_ret;
for (i = 0; i < num_available / 3; i++) {
iio_push_to_buffers(indio_dev, st->rx + i * 3 * 2);
}
}
error_ret:
mutex_unlock(&st->lock);
}
static irqreturn_t sca3000_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct sca3000_state *st = iio_priv(indio_dev);
int ret, val;
s64 last_timestamp = iio_get_time_ns(indio_dev);
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_INT_STATUS_ADDR, 1);
val = st->rx[0];
mutex_unlock(&st->lock);
if (ret)
goto done;
sca3000_ring_int_process(val, indio_dev);
if (val & SCA3000_INT_STATUS_FREE_FALL)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_X_AND_Y_AND_Z,
IIO_EV_TYPE_MAG,
IIO_EV_DIR_FALLING),
last_timestamp);
if (val & SCA3000_INT_STATUS_Y_TRIGGER)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Y,
IIO_EV_TYPE_MAG,
IIO_EV_DIR_RISING),
last_timestamp);
if (val & SCA3000_INT_STATUS_X_TRIGGER)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_X,
IIO_EV_TYPE_MAG,
IIO_EV_DIR_RISING),
last_timestamp);
if (val & SCA3000_INT_STATUS_Z_TRIGGER)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Z,
IIO_EV_TYPE_MAG,
IIO_EV_DIR_RISING),
last_timestamp);
done:
return IRQ_HANDLED;
}
static int sca3000_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct sca3000_state *st = iio_priv(indio_dev);
int ret;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_MODE_ADDR, 1);
if (ret)
goto error_ret;
switch (chan->channel2) {
case IIO_MOD_X_AND_Y_AND_Z:
ret = !!(st->rx[0] & SCA3000_REG_MODE_FREE_FALL_DETECT);
break;
case IIO_MOD_X:
case IIO_MOD_Y:
case IIO_MOD_Z:
if ((st->rx[0] & SCA3000_REG_MODE_MODE_MASK)
!= SCA3000_REG_MODE_MEAS_MODE_MOT_DET) {
ret = 0;
} else {
ret = sca3000_read_ctrl_reg(st,
SCA3000_REG_CTRL_SEL_MD_CTRL);
if (ret < 0)
goto error_ret;
ret = !!(ret & sca3000_addresses[chan->address][2]);
}
break;
default:
ret = -EINVAL;
}
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static int sca3000_freefall_set_state(struct iio_dev *indio_dev, int state)
{
struct sca3000_state *st = iio_priv(indio_dev);
int ret;
ret = sca3000_read_data_short(st, SCA3000_REG_MODE_ADDR, 1);
if (ret)
return ret;
if (state && !(st->rx[0] & SCA3000_REG_MODE_FREE_FALL_DETECT))
return sca3000_write_reg(st, SCA3000_REG_MODE_ADDR,
st->rx[0] | SCA3000_REG_MODE_FREE_FALL_DETECT);
else if (!state && (st->rx[0] & SCA3000_REG_MODE_FREE_FALL_DETECT))
return sca3000_write_reg(st, SCA3000_REG_MODE_ADDR,
st->rx[0] & ~SCA3000_REG_MODE_FREE_FALL_DETECT);
else
return 0;
}
static int sca3000_motion_detect_set_state(struct iio_dev *indio_dev, int axis,
int state)
{
struct sca3000_state *st = iio_priv(indio_dev);
int ret, ctrlval;
ret = sca3000_read_ctrl_reg(st, SCA3000_REG_CTRL_SEL_MD_CTRL);
if (ret < 0)
return ret;
ctrlval = ret;
if (state && !(ctrlval & sca3000_addresses[axis][2])) {
ret = sca3000_write_ctrl_reg(st,
SCA3000_REG_CTRL_SEL_MD_CTRL,
ctrlval |
sca3000_addresses[axis][2]);
if (ret)
return ret;
st->mo_det_use_count++;
} else if (!state && (ctrlval & sca3000_addresses[axis][2])) {
ret = sca3000_write_ctrl_reg(st,
SCA3000_REG_CTRL_SEL_MD_CTRL,
ctrlval &
~(sca3000_addresses[axis][2]));
if (ret)
return ret;
st->mo_det_use_count--;
}
ret = sca3000_read_data_short(st, SCA3000_REG_MODE_ADDR, 1);
if (ret)
return ret;
if ((st->mo_det_use_count) &&
((st->rx[0] & SCA3000_REG_MODE_MODE_MASK)
!= SCA3000_REG_MODE_MEAS_MODE_MOT_DET))
return sca3000_write_reg(st, SCA3000_REG_MODE_ADDR,
(st->rx[0] & ~SCA3000_REG_MODE_MODE_MASK)
| SCA3000_REG_MODE_MEAS_MODE_MOT_DET);
else if (!(st->mo_det_use_count) &&
((st->rx[0] & SCA3000_REG_MODE_MODE_MASK)
== SCA3000_REG_MODE_MEAS_MODE_MOT_DET))
return sca3000_write_reg(st, SCA3000_REG_MODE_ADDR,
st->rx[0] & SCA3000_REG_MODE_MODE_MASK);
else
return 0;
}
static int sca3000_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
struct sca3000_state *st = iio_priv(indio_dev);
int ret;
mutex_lock(&st->lock);
switch (chan->channel2) {
case IIO_MOD_X_AND_Y_AND_Z:
ret = sca3000_freefall_set_state(indio_dev, state);
break;
case IIO_MOD_X:
case IIO_MOD_Y:
case IIO_MOD_Z:
ret = sca3000_motion_detect_set_state(indio_dev,
chan->address,
state);
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&st->lock);
return ret;
}
static int sca3000_configure_ring(struct iio_dev *indio_dev)
{
struct iio_buffer *buffer;
buffer = iio_kfifo_allocate();
if (!buffer)
return -ENOMEM;
iio_device_attach_buffer(indio_dev, buffer);
indio_dev->modes |= INDIO_BUFFER_SOFTWARE;
return 0;
}
static void sca3000_unconfigure_ring(struct iio_dev *indio_dev)
{
iio_kfifo_free(indio_dev->buffer);
}
static inline
int __sca3000_hw_ring_state_set(struct iio_dev *indio_dev, bool state)
{
struct sca3000_state *st = iio_priv(indio_dev);
int ret;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_MODE_ADDR, 1);
if (ret)
goto error_ret;
if (state) {
dev_info(&indio_dev->dev, "supposedly enabling ring buffer\n");
ret = sca3000_write_reg(st,
SCA3000_REG_MODE_ADDR,
(st->rx[0] | SCA3000_REG_MODE_RING_BUF_ENABLE));
} else
ret = sca3000_write_reg(st,
SCA3000_REG_MODE_ADDR,
(st->rx[0] & ~SCA3000_REG_MODE_RING_BUF_ENABLE));
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static int sca3000_hw_ring_preenable(struct iio_dev *indio_dev)
{
int ret;
struct sca3000_state *st = iio_priv(indio_dev);
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_INT_MASK_ADDR, 1);
if (ret)
goto error_unlock;
ret = sca3000_write_reg(st,
SCA3000_REG_INT_MASK_ADDR,
st->rx[0] | SCA3000_REG_INT_MASK_RING_HALF);
if (ret)
goto error_unlock;
mutex_unlock(&st->lock);
return __sca3000_hw_ring_state_set(indio_dev, 1);
error_unlock:
mutex_unlock(&st->lock);
return ret;
}
static int sca3000_hw_ring_postdisable(struct iio_dev *indio_dev)
{
int ret;
struct sca3000_state *st = iio_priv(indio_dev);
ret = __sca3000_hw_ring_state_set(indio_dev, 0);
if (ret)
return ret;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_INT_MASK_ADDR, 1);
if (ret)
goto unlock;
ret = sca3000_write_reg(st,
SCA3000_REG_INT_MASK_ADDR,
st->rx[0] & ~SCA3000_REG_INT_MASK_RING_HALF);
unlock:
mutex_unlock(&st->lock);
return ret;
}
static int sca3000_clean_setup(struct sca3000_state *st)
{
int ret;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_INT_STATUS_ADDR, 1);
if (ret)
goto error_ret;
ret = sca3000_read_ctrl_reg(st, SCA3000_REG_CTRL_SEL_MD_CTRL);
if (ret < 0)
goto error_ret;
ret = sca3000_write_ctrl_reg(st, SCA3000_REG_CTRL_SEL_MD_CTRL,
ret & SCA3000_MD_CTRL_PROT_MASK);
if (ret)
goto error_ret;
ret = sca3000_read_ctrl_reg(st, SCA3000_REG_CTRL_SEL_OUT_CTRL);
if (ret < 0)
goto error_ret;
ret = sca3000_write_ctrl_reg(st, SCA3000_REG_CTRL_SEL_OUT_CTRL,
(ret & SCA3000_REG_OUT_CTRL_PROT_MASK)
| SCA3000_REG_OUT_CTRL_BUF_X_EN
| SCA3000_REG_OUT_CTRL_BUF_Y_EN
| SCA3000_REG_OUT_CTRL_BUF_Z_EN
| SCA3000_REG_OUT_CTRL_BUF_DIV_4);
if (ret)
goto error_ret;
ret = sca3000_read_data_short(st, SCA3000_REG_INT_MASK_ADDR, 1);
if (ret)
goto error_ret;
ret = sca3000_write_reg(st,
SCA3000_REG_INT_MASK_ADDR,
(ret & SCA3000_REG_INT_MASK_PROT_MASK)
| SCA3000_REG_INT_MASK_ACTIVE_LOW);
if (ret)
goto error_ret;
ret = sca3000_read_data_short(st, SCA3000_REG_MODE_ADDR, 1);
if (ret)
goto error_ret;
ret = sca3000_write_reg(st, SCA3000_REG_MODE_ADDR,
(st->rx[0] & SCA3000_MODE_PROT_MASK));
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static int sca3000_probe(struct spi_device *spi)
{
int ret;
struct sca3000_state *st;
struct iio_dev *indio_dev;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->us = spi;
mutex_init(&st->lock);
st->info = &sca3000_spi_chip_info_tbl[spi_get_device_id(spi)
->driver_data];
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->info = &sca3000_info;
if (st->info->temp_output) {
indio_dev->channels = sca3000_channels_with_temp;
indio_dev->num_channels =
ARRAY_SIZE(sca3000_channels_with_temp);
} else {
indio_dev->channels = sca3000_channels;
indio_dev->num_channels = ARRAY_SIZE(sca3000_channels);
}
indio_dev->modes = INDIO_DIRECT_MODE;
sca3000_configure_ring(indio_dev);
if (spi->irq) {
ret = request_threaded_irq(spi->irq,
NULL,
&sca3000_event_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"sca3000",
indio_dev);
if (ret)
return ret;
}
indio_dev->setup_ops = &sca3000_ring_setup_ops;
ret = sca3000_clean_setup(st);
if (ret)
goto error_free_irq;
ret = sca3000_print_rev(indio_dev);
if (ret)
goto error_free_irq;
return iio_device_register(indio_dev);
error_free_irq:
if (spi->irq)
free_irq(spi->irq, indio_dev);
return ret;
}
static int sca3000_stop_all_interrupts(struct sca3000_state *st)
{
int ret;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_INT_MASK_ADDR, 1);
if (ret)
goto error_ret;
ret = sca3000_write_reg(st, SCA3000_REG_INT_MASK_ADDR,
(st->rx[0] &
~(SCA3000_REG_INT_MASK_RING_THREE_QUARTER |
SCA3000_REG_INT_MASK_RING_HALF |
SCA3000_REG_INT_MASK_ALL_INTS)));
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static int sca3000_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct sca3000_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
sca3000_stop_all_interrupts(st);
if (spi->irq)
free_irq(spi->irq, indio_dev);
sca3000_unconfigure_ring(indio_dev);
return 0;
}
