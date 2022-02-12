int sca3000_write_reg(struct sca3000_state *st, u8 address, u8 val)
{
st->tx[0] = SCA3000_WRITE_REG(address);
st->tx[1] = val;
return spi_write(st->us, st->tx, 2);
}
int sca3000_read_data_short(struct sca3000_state *st,
uint8_t reg_address_high,
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
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_STATUS, 1);
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
st->tx[0] = SCA3000_WRITE_REG(SCA3000_REG_ADDR_UNLOCK);
st->tx[1] = 0x00;
st->tx[2] = SCA3000_WRITE_REG(SCA3000_REG_ADDR_UNLOCK);
st->tx[3] = 0x50;
st->tx[4] = SCA3000_WRITE_REG(SCA3000_REG_ADDR_UNLOCK);
st->tx[5] = 0xA0;
return spi_sync_transfer(st->us, xfer, ARRAY_SIZE(xfer));
}
static int sca3000_write_ctrl_reg(struct sca3000_state *st,
uint8_t sel,
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
ret = sca3000_write_reg(st, SCA3000_REG_ADDR_CTRL_SEL, sel);
if (ret)
goto error_ret;
ret = sca3000_write_reg(st, SCA3000_REG_ADDR_CTRL_DATA, val);
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
ret = sca3000_write_reg(st, SCA3000_REG_ADDR_CTRL_SEL, ctrl_reg);
if (ret)
goto error_ret;
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_CTRL_DATA, 1);
if (ret)
goto error_ret;
else
return st->rx[0];
error_ret:
return ret;
}
static int sca3000_check_status(struct device *dev)
{
int ret;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct sca3000_state *st = iio_priv(indio_dev);
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_STATUS, 1);
if (ret < 0)
goto error_ret;
if (st->rx[0] & SCA3000_EEPROM_CS_ERROR)
dev_err(dev, "eeprom error\n");
if (st->rx[0] & SCA3000_SPI_FRAME_ERROR)
dev_err(dev, "Previous SPI Frame was corrupt\n");
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static ssize_t sca3000_show_rev(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int len = 0, ret;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct sca3000_state *st = iio_priv(indio_dev);
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_REVID, 1);
if (ret < 0)
goto error_ret;
len += sprintf(buf + len,
"major=%d, minor=%d\n",
st->rx[0] & SCA3000_REVID_MAJOR_MASK,
st->rx[0] & SCA3000_REVID_MINOR_MASK);
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static ssize_t
sca3000_show_available_measurement_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct sca3000_state *st = iio_priv(indio_dev);
int len = 0;
len += sprintf(buf + len, "0 - normal mode");
switch (st->info->option_mode_1) {
case SCA3000_OP_MODE_NARROW:
len += sprintf(buf + len, ", 1 - narrow mode");
break;
case SCA3000_OP_MODE_BYPASS:
len += sprintf(buf + len, ", 1 - bypass mode");
break;
}
switch (st->info->option_mode_2) {
case SCA3000_OP_MODE_WIDE:
len += sprintf(buf + len, ", 2 - wide mode");
break;
}
len += sprintf(buf + len, " 3 - motion detection\n");
return len;
}
static ssize_t
sca3000_show_measurement_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct sca3000_state *st = iio_priv(indio_dev);
int len = 0, ret;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_MODE, 1);
if (ret)
goto error_ret;
st->rx[0] &= 0x03;
switch (st->rx[0]) {
case SCA3000_MEAS_MODE_NORMAL:
len += sprintf(buf + len, "0 - normal mode\n");
break;
case SCA3000_MEAS_MODE_MOT_DET:
len += sprintf(buf + len, "3 - motion detection\n");
break;
case SCA3000_MEAS_MODE_OP_1:
switch (st->info->option_mode_1) {
case SCA3000_OP_MODE_NARROW:
len += sprintf(buf + len, "1 - narrow mode\n");
break;
case SCA3000_OP_MODE_BYPASS:
len += sprintf(buf + len, "1 - bypass mode\n");
break;
}
break;
case SCA3000_MEAS_MODE_OP_2:
switch (st->info->option_mode_2) {
case SCA3000_OP_MODE_WIDE:
len += sprintf(buf + len, "2 - wide mode\n");
break;
}
break;
}
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static ssize_t
sca3000_store_measurement_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct sca3000_state *st = iio_priv(indio_dev);
int ret;
u8 mask = 0x03;
u8 val;
mutex_lock(&st->lock);
ret = kstrtou8(buf, 10, &val);
if (ret)
goto error_ret;
if (val > 3) {
ret = -EINVAL;
goto error_ret;
}
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_MODE, 1);
if (ret)
goto error_ret;
st->rx[0] &= ~mask;
st->rx[0] |= (val & mask);
ret = sca3000_write_reg(st, SCA3000_REG_ADDR_MODE, st->rx[0]);
if (ret)
goto error_ret;
mutex_unlock(&st->lock);
return len;
error_ret:
mutex_unlock(&st->lock);
return ret;
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
*val = ((*val) << (sizeof(*val)*8 - 13)) >>
(sizeof(*val)*8 - 13);
} else {
ret = sca3000_read_data_short(st,
SCA3000_REG_ADDR_TEMP_MSB, 2);
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
default:
return -EINVAL;
}
}
static ssize_t sca3000_read_av_freq(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct sca3000_state *st = iio_priv(indio_dev);
int len = 0, ret, val;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_MODE, 1);
val = st->rx[0];
mutex_unlock(&st->lock);
if (ret)
goto error_ret;
switch (val & 0x03) {
case SCA3000_MEAS_MODE_NORMAL:
len += sprintf(buf + len, "%d %d %d\n",
st->info->measurement_mode_freq,
st->info->measurement_mode_freq/2,
st->info->measurement_mode_freq/4);
break;
case SCA3000_MEAS_MODE_OP_1:
len += sprintf(buf + len, "%d %d %d\n",
st->info->option_mode_1_freq,
st->info->option_mode_1_freq/2,
st->info->option_mode_1_freq/4);
break;
case SCA3000_MEAS_MODE_OP_2:
len += sprintf(buf + len, "%d %d %d\n",
st->info->option_mode_2_freq,
st->info->option_mode_2_freq/2,
st->info->option_mode_2_freq/4);
break;
}
return len;
error_ret:
return ret;
}
static inline int __sca3000_get_base_freq(struct sca3000_state *st,
const struct sca3000_chip_info *info,
int *base_freq)
{
int ret;
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_MODE, 1);
if (ret)
goto error_ret;
switch (0x03 & st->rx[0]) {
case SCA3000_MEAS_MODE_NORMAL:
*base_freq = info->measurement_mode_freq;
break;
case SCA3000_MEAS_MODE_OP_1:
*base_freq = info->option_mode_1_freq;
break;
case SCA3000_MEAS_MODE_OP_2:
*base_freq = info->option_mode_2_freq;
break;
}
error_ret:
return ret;
}
static ssize_t sca3000_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct sca3000_state *st = iio_priv(indio_dev);
int ret, len = 0, base_freq = 0, val;
mutex_lock(&st->lock);
ret = __sca3000_get_base_freq(st, st->info, &base_freq);
if (ret)
goto error_ret_mut;
ret = sca3000_read_ctrl_reg(st, SCA3000_REG_CTRL_SEL_OUT_CTRL);
mutex_unlock(&st->lock);
if (ret)
goto error_ret;
val = ret;
if (base_freq > 0)
switch (val & 0x03) {
case 0x00:
case 0x03:
len = sprintf(buf, "%d\n", base_freq);
break;
case 0x01:
len = sprintf(buf, "%d\n", base_freq/2);
break;
case 0x02:
len = sprintf(buf, "%d\n", base_freq/4);
break;
}
return len;
error_ret_mut:
mutex_unlock(&st->lock);
error_ret:
return ret;
}
static ssize_t sca3000_set_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct sca3000_state *st = iio_priv(indio_dev);
int ret, base_freq = 0;
int ctrlval;
int val;
ret = kstrtoint(buf, 10, &val);
if (ret)
return ret;
mutex_lock(&st->lock);
ret = __sca3000_get_base_freq(st, st->info, &base_freq);
if (ret)
goto error_free_lock;
ret = sca3000_read_ctrl_reg(st, SCA3000_REG_CTRL_SEL_OUT_CTRL);
if (ret < 0)
goto error_free_lock;
ctrlval = ret;
ctrlval &= ~0x03;
if (val == base_freq/2) {
ctrlval |= SCA3000_OUT_CTRL_BUF_DIV_2;
} else if (val == base_freq/4) {
ctrlval |= SCA3000_OUT_CTRL_BUF_DIV_4;
} else if (val != base_freq) {
ret = -EINVAL;
goto error_free_lock;
}
ret = sca3000_write_ctrl_reg(st, SCA3000_REG_CTRL_SEL_OUT_CTRL,
ctrlval);
error_free_lock:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static int sca3000_read_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
int ret, i;
struct sca3000_state *st = iio_priv(indio_dev);
int num = chan->channel2;
mutex_lock(&st->lock);
ret = sca3000_read_ctrl_reg(st, sca3000_addresses[num][1]);
mutex_unlock(&st->lock);
if (ret < 0)
return ret;
*val = 0;
if (num == 1)
for_each_set_bit(i, (unsigned long *)&ret,
ARRAY_SIZE(st->info->mot_det_mult_y))
*val += st->info->mot_det_mult_y[i];
else
for_each_set_bit(i, (unsigned long *)&ret,
ARRAY_SIZE(st->info->mot_det_mult_xz))
*val += st->info->mot_det_mult_xz[i];
return IIO_VAL_INT;
}
static int sca3000_write_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
struct sca3000_state *st = iio_priv(indio_dev);
int num = chan->channel2;
int ret;
int i;
u8 nonlinear = 0;
if (num == 1) {
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
ret = sca3000_write_ctrl_reg(st, sca3000_addresses[num][1], nonlinear);
mutex_unlock(&st->lock);
return ret;
}
static irqreturn_t sca3000_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct sca3000_state *st = iio_priv(indio_dev);
int ret, val;
s64 last_timestamp = iio_get_time_ns();
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_INT_STATUS, 1);
val = st->rx[0];
mutex_unlock(&st->lock);
if (ret)
goto done;
sca3000_ring_int_process(val, indio_dev->buffer);
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
u8 protect_mask = 0x03;
int num = chan->channel2;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_MODE, 1);
if (ret)
goto error_ret;
if ((st->rx[0] & protect_mask) != SCA3000_MEAS_MODE_MOT_DET)
ret = 0;
else {
ret = sca3000_read_ctrl_reg(st, SCA3000_REG_CTRL_SEL_MD_CTRL);
if (ret < 0)
goto error_ret;
ret = !!(ret & sca3000_addresses[num][2]);
}
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static ssize_t sca3000_query_free_fall_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret, len;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct sca3000_state *st = iio_priv(indio_dev);
int val;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_MODE, 1);
val = st->rx[0];
mutex_unlock(&st->lock);
if (ret < 0)
return ret;
len = sprintf(buf, "%d\n",
!!(val & SCA3000_FREE_FALL_DETECT));
return len;
}
static ssize_t sca3000_set_free_fall_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct sca3000_state *st = iio_priv(indio_dev);
u8 val;
int ret;
u8 protect_mask = SCA3000_FREE_FALL_DETECT;
mutex_lock(&st->lock);
ret = kstrtou8(buf, 10, &val);
if (ret)
goto error_ret;
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_MODE, 1);
if (ret)
goto error_ret;
if (val && !(st->rx[0] & protect_mask))
ret = sca3000_write_reg(st, SCA3000_REG_ADDR_MODE,
(st->rx[0] | SCA3000_FREE_FALL_DETECT));
else if (!val && (st->rx[0] & protect_mask))
ret = sca3000_write_reg(st, SCA3000_REG_ADDR_MODE,
(st->rx[0] & ~protect_mask));
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static int sca3000_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
struct sca3000_state *st = iio_priv(indio_dev);
int ret, ctrlval;
u8 protect_mask = 0x03;
int num = chan->channel2;
mutex_lock(&st->lock);
ret = sca3000_read_ctrl_reg(st, SCA3000_REG_CTRL_SEL_MD_CTRL);
if (ret < 0)
goto exit_point;
ctrlval = ret;
if (state && !(ctrlval & sca3000_addresses[num][2])) {
ret = sca3000_write_ctrl_reg(st,
SCA3000_REG_CTRL_SEL_MD_CTRL,
ctrlval |
sca3000_addresses[num][2]);
if (ret)
goto exit_point;
st->mo_det_use_count++;
} else if (!state && (ctrlval & sca3000_addresses[num][2])) {
ret = sca3000_write_ctrl_reg(st,
SCA3000_REG_CTRL_SEL_MD_CTRL,
ctrlval &
~(sca3000_addresses[num][2]));
if (ret)
goto exit_point;
st->mo_det_use_count--;
}
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_MODE, 1);
if (ret)
goto exit_point;
if ((st->mo_det_use_count)
&& ((st->rx[0] & protect_mask) != SCA3000_MEAS_MODE_MOT_DET))
ret = sca3000_write_reg(st, SCA3000_REG_ADDR_MODE,
(st->rx[0] & ~protect_mask)
| SCA3000_MEAS_MODE_MOT_DET);
else if (!(st->mo_det_use_count)
&& ((st->rx[0] & protect_mask) == SCA3000_MEAS_MODE_MOT_DET))
ret = sca3000_write_reg(st, SCA3000_REG_ADDR_MODE,
(st->rx[0] & ~protect_mask));
exit_point:
mutex_unlock(&st->lock);
return ret;
}
static int sca3000_clean_setup(struct sca3000_state *st)
{
int ret;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_INT_STATUS, 1);
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
ret = sca3000_write_ctrl_reg(st, SCA3000_REG_CTRL_SEL_OUT_CTRL,
(ret & SCA3000_OUT_CTRL_PROT_MASK)
| SCA3000_OUT_CTRL_BUF_X_EN
| SCA3000_OUT_CTRL_BUF_Y_EN
| SCA3000_OUT_CTRL_BUF_Z_EN
| SCA3000_OUT_CTRL_BUF_DIV_4);
if (ret)
goto error_ret;
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_INT_MASK, 1);
if (ret)
goto error_ret;
ret = sca3000_write_reg(st,
SCA3000_REG_ADDR_INT_MASK,
(ret & SCA3000_INT_MASK_PROT_MASK)
| SCA3000_INT_MASK_ACTIVE_LOW);
if (ret)
goto error_ret;
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_MODE, 1);
if (ret)
goto error_ret;
ret = sca3000_write_reg(st, SCA3000_REG_ADDR_MODE,
(st->rx[0] & SCA3000_MODE_PROT_MASK));
st->bpse = 11;
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
ret = iio_device_register(indio_dev);
if (ret < 0)
return ret;
ret = iio_buffer_register(indio_dev,
sca3000_channels,
ARRAY_SIZE(sca3000_channels));
if (ret < 0)
goto error_unregister_dev;
if (indio_dev->buffer) {
iio_scan_mask_set(indio_dev, indio_dev->buffer, 0);
iio_scan_mask_set(indio_dev, indio_dev->buffer, 1);
iio_scan_mask_set(indio_dev, indio_dev->buffer, 2);
}
if (spi->irq) {
ret = request_threaded_irq(spi->irq,
NULL,
&sca3000_event_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"sca3000",
indio_dev);
if (ret)
goto error_unregister_ring;
}
sca3000_register_ring_funcs(indio_dev);
ret = sca3000_clean_setup(st);
if (ret)
goto error_free_irq;
return 0;
error_free_irq:
if (spi->irq)
free_irq(spi->irq, indio_dev);
error_unregister_ring:
iio_buffer_unregister(indio_dev);
error_unregister_dev:
iio_device_unregister(indio_dev);
return ret;
}
static int sca3000_stop_all_interrupts(struct sca3000_state *st)
{
int ret;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_INT_MASK, 1);
if (ret)
goto error_ret;
ret = sca3000_write_reg(st, SCA3000_REG_ADDR_INT_MASK,
(st->rx[0] &
~(SCA3000_INT_MASK_RING_THREE_QUARTER |
SCA3000_INT_MASK_RING_HALF |
SCA3000_INT_MASK_ALL_INTS)));
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static int sca3000_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct sca3000_state *st = iio_priv(indio_dev);
sca3000_stop_all_interrupts(st);
if (spi->irq)
free_irq(spi->irq, indio_dev);
iio_device_unregister(indio_dev);
iio_buffer_unregister(indio_dev);
sca3000_unconfigure_ring(indio_dev);
return 0;
}
