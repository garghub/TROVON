static irqreturn_t lis3l02dq_nobuffer(int irq, void *private)
{
return IRQ_WAKE_THREAD;
}
int lis3l02dq_spi_read_reg_8(struct iio_dev *indio_dev,
u8 reg_address, u8 *val)
{
struct lis3l02dq_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer xfer = {
.tx_buf = st->tx,
.rx_buf = st->rx,
.bits_per_word = 8,
.len = 2,
};
mutex_lock(&st->buf_lock);
st->tx[0] = LIS3L02DQ_READ_REG(reg_address);
st->tx[1] = 0;
ret = spi_sync_transfer(st->us, &xfer, 1);
*val = st->rx[1];
mutex_unlock(&st->buf_lock);
return ret;
}
int lis3l02dq_spi_write_reg_8(struct iio_dev *indio_dev,
u8 reg_address,
u8 val)
{
int ret;
struct lis3l02dq_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = LIS3L02DQ_WRITE_REG(reg_address);
st->tx[1] = val;
ret = spi_write(st->us, st->tx, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int lis3l02dq_spi_write_reg_s16(struct iio_dev *indio_dev,
u8 lower_reg_address,
s16 value)
{
int ret;
struct lis3l02dq_state *st = iio_priv(indio_dev);
struct spi_transfer xfers[] = { {
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
}, {
.tx_buf = st->tx + 2,
.bits_per_word = 8,
.len = 2,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = LIS3L02DQ_WRITE_REG(lower_reg_address);
st->tx[1] = value & 0xFF;
st->tx[2] = LIS3L02DQ_WRITE_REG(lower_reg_address + 1);
st->tx[3] = (value >> 8) & 0xFF;
ret = spi_sync_transfer(st->us, xfers, ARRAY_SIZE(xfers));
mutex_unlock(&st->buf_lock);
return ret;
}
static int lis3l02dq_read_reg_s16(struct iio_dev *indio_dev,
u8 lower_reg_address,
int *val)
{
struct lis3l02dq_state *st = iio_priv(indio_dev);
int ret;
s16 tempval;
struct spi_transfer xfers[] = { {
.tx_buf = st->tx,
.rx_buf = st->rx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
}, {
.tx_buf = st->tx + 2,
.rx_buf = st->rx + 2,
.bits_per_word = 8,
.len = 2,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = LIS3L02DQ_READ_REG(lower_reg_address);
st->tx[1] = 0;
st->tx[2] = LIS3L02DQ_READ_REG(lower_reg_address + 1);
st->tx[3] = 0;
ret = spi_sync_transfer(st->us, xfers, ARRAY_SIZE(xfers));
if (ret) {
dev_err(&st->us->dev, "problem when reading 16 bit register");
goto error_ret;
}
tempval = (s16)(st->rx[1]) | ((s16)(st->rx[3]) << 8);
*val = tempval;
error_ret:
mutex_unlock(&st->buf_lock);
return ret;
}
static int lis3l02dq_read_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
int ret;
ret = lis3l02dq_read_reg_s16(indio_dev, LIS3L02DQ_REG_THS_L_ADDR, val);
if (ret)
return ret;
return IIO_VAL_INT;
}
static int lis3l02dq_write_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
u16 value = val;
return lis3l02dq_spi_write_reg_s16(indio_dev,
LIS3L02DQ_REG_THS_L_ADDR,
value);
}
static int lis3l02dq_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
int ret = -EINVAL, reg;
u8 uval;
s8 sval;
switch (mask) {
case IIO_CHAN_INFO_CALIBBIAS:
if (val > 255 || val < -256)
return -EINVAL;
sval = val;
reg = lis3l02dq_axis_map[LIS3L02DQ_BIAS][chan->address];
ret = lis3l02dq_spi_write_reg_8(indio_dev, reg, sval);
break;
case IIO_CHAN_INFO_CALIBSCALE:
if (val & ~0xFF)
return -EINVAL;
uval = val;
reg = lis3l02dq_axis_map[LIS3L02DQ_GAIN][chan->address];
ret = lis3l02dq_spi_write_reg_8(indio_dev, reg, uval);
break;
}
return ret;
}
static int lis3l02dq_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
u8 utemp;
s8 stemp;
ssize_t ret = 0;
u8 reg;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
if (indio_dev->currentmode == INDIO_BUFFER_TRIGGERED) {
ret = -EBUSY;
} else {
reg = lis3l02dq_axis_map
[LIS3L02DQ_ACCEL][chan->address];
ret = lis3l02dq_read_reg_s16(indio_dev, reg, val);
}
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
goto error_ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = 9580;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_CALIBSCALE:
reg = lis3l02dq_axis_map[LIS3L02DQ_GAIN][chan->address];
ret = lis3l02dq_spi_read_reg_8(indio_dev, reg, &utemp);
if (ret)
goto error_ret;
*val = utemp;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBBIAS:
reg = lis3l02dq_axis_map[LIS3L02DQ_BIAS][chan->address];
ret = lis3l02dq_spi_read_reg_8(indio_dev, reg, (u8 *)&stemp);
*val = stemp;
return IIO_VAL_INT;
}
error_ret:
return ret;
}
static ssize_t lis3l02dq_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
int ret, len = 0;
s8 t;
ret = lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_1_ADDR,
(u8 *)&t);
if (ret)
return ret;
t &= LIS3L02DQ_DEC_MASK;
switch (t) {
case LIS3L02DQ_REG_CTRL_1_DF_128:
len = sprintf(buf, "280\n");
break;
case LIS3L02DQ_REG_CTRL_1_DF_64:
len = sprintf(buf, "560\n");
break;
case LIS3L02DQ_REG_CTRL_1_DF_32:
len = sprintf(buf, "1120\n");
break;
case LIS3L02DQ_REG_CTRL_1_DF_8:
len = sprintf(buf, "4480\n");
break;
}
return len;
}
static ssize_t lis3l02dq_write_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
unsigned long val;
int ret;
u8 t;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
mutex_lock(&indio_dev->mlock);
ret = lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_1_ADDR,
&t);
if (ret)
goto error_ret_mutex;
t &= ~LIS3L02DQ_DEC_MASK;
switch (val) {
case 280:
t |= LIS3L02DQ_REG_CTRL_1_DF_128;
break;
case 560:
t |= LIS3L02DQ_REG_CTRL_1_DF_64;
break;
case 1120:
t |= LIS3L02DQ_REG_CTRL_1_DF_32;
break;
case 4480:
t |= LIS3L02DQ_REG_CTRL_1_DF_8;
break;
default:
ret = -EINVAL;
goto error_ret_mutex;
}
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_1_ADDR,
t);
error_ret_mutex:
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int lis3l02dq_initial_setup(struct iio_dev *indio_dev)
{
struct lis3l02dq_state *st = iio_priv(indio_dev);
int ret;
u8 val, valtest;
st->us->mode = SPI_MODE_3;
spi_setup(st->us);
val = LIS3L02DQ_DEFAULT_CTRL1;
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_1_ADDR,
val);
if (ret) {
dev_err(&st->us->dev, "problem with setup control register 1");
goto err_ret;
}
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_1_ADDR,
val);
if (ret) {
dev_err(&st->us->dev, "problem with setup control register 1");
goto err_ret;
}
ret = lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_1_ADDR,
&valtest);
if (ret || (valtest != val)) {
dev_err(&indio_dev->dev,
"device not playing ball %d %d\n", valtest, val);
ret = -EINVAL;
goto err_ret;
}
val = LIS3L02DQ_DEFAULT_CTRL2;
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_2_ADDR,
val);
if (ret) {
dev_err(&st->us->dev, "problem with setup control register 2");
goto err_ret;
}
val = LIS3L02DQ_REG_WAKE_UP_CFG_LATCH_SRC;
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_WAKE_UP_CFG_ADDR,
val);
if (ret)
dev_err(&st->us->dev, "problem with interrupt cfg register");
err_ret:
return ret;
}
static irqreturn_t lis3l02dq_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
u8 t;
s64 timestamp = iio_get_time_ns();
lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_WAKE_UP_SRC_ADDR,
&t);
if (t & LIS3L02DQ_REG_WAKE_UP_SRC_INTERRUPT_Z_HIGH)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Z,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
if (t & LIS3L02DQ_REG_WAKE_UP_SRC_INTERRUPT_Z_LOW)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Z,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
if (t & LIS3L02DQ_REG_WAKE_UP_SRC_INTERRUPT_Y_HIGH)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Y,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
if (t & LIS3L02DQ_REG_WAKE_UP_SRC_INTERRUPT_Y_LOW)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Y,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
if (t & LIS3L02DQ_REG_WAKE_UP_SRC_INTERRUPT_X_HIGH)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_X,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
if (t & LIS3L02DQ_REG_WAKE_UP_SRC_INTERRUPT_X_LOW)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_X,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_WAKE_UP_ACK_ADDR,
&t);
return IRQ_HANDLED;
}
static int lis3l02dq_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
u8 val;
int ret;
u8 mask = (1 << (chan->channel2 * 2 + (dir == IIO_EV_DIR_RISING)));
ret = lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_WAKE_UP_CFG_ADDR,
&val);
if (ret < 0)
return ret;
return !!(val & mask);
}
int lis3l02dq_disable_all_events(struct iio_dev *indio_dev)
{
int ret;
u8 control, val;
ret = lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_2_ADDR,
&control);
control &= ~LIS3L02DQ_REG_CTRL_2_ENABLE_INTERRUPT;
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_2_ADDR,
control);
if (ret)
goto error_ret;
ret = lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_WAKE_UP_CFG_ADDR,
&val);
if (ret)
goto error_ret;
val &= ~0x3f;
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_WAKE_UP_CFG_ADDR,
val);
if (ret)
goto error_ret;
ret = control;
error_ret:
return ret;
}
static int lis3l02dq_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
int ret = 0;
u8 val, control;
u8 currentlyset;
bool changed = false;
u8 mask = (1 << (chan->channel2 * 2 + (dir == IIO_EV_DIR_RISING)));
mutex_lock(&indio_dev->mlock);
ret = lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_2_ADDR,
&control);
if (ret)
goto error_ret;
ret = lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_WAKE_UP_CFG_ADDR,
&val);
if (ret < 0)
goto error_ret;
currentlyset = val & mask;
if (!currentlyset && state) {
changed = true;
val |= mask;
} else if (currentlyset && !state) {
changed = true;
val &= ~mask;
}
if (changed) {
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_WAKE_UP_CFG_ADDR,
val);
if (ret)
goto error_ret;
control = val & 0x3f ?
(control | LIS3L02DQ_REG_CTRL_2_ENABLE_INTERRUPT) :
(control & ~LIS3L02DQ_REG_CTRL_2_ENABLE_INTERRUPT);
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_2_ADDR,
control);
if (ret)
goto error_ret;
}
error_ret:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int lis3l02dq_probe(struct spi_device *spi)
{
int ret;
struct lis3l02dq_state *st;
struct iio_dev *indio_dev;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->us = spi;
st->gpio = of_get_gpio(spi->dev.of_node, 0);
mutex_init(&st->buf_lock);
indio_dev->name = spi->dev.driver->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &lis3l02dq_info;
indio_dev->channels = lis3l02dq_channels;
indio_dev->num_channels = ARRAY_SIZE(lis3l02dq_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = lis3l02dq_configure_buffer(indio_dev);
if (ret)
return ret;
if (spi->irq) {
ret = request_threaded_irq(st->us->irq,
&lis3l02dq_th,
&lis3l02dq_event_handler,
IRQF_TRIGGER_RISING,
"lis3l02dq",
indio_dev);
if (ret)
goto error_unreg_buffer_funcs;
ret = lis3l02dq_probe_trigger(indio_dev);
if (ret)
goto error_free_interrupt;
}
ret = lis3l02dq_initial_setup(indio_dev);
if (ret)
goto error_remove_trigger;
ret = iio_device_register(indio_dev);
if (ret)
goto error_remove_trigger;
return 0;
error_remove_trigger:
if (spi->irq)
lis3l02dq_remove_trigger(indio_dev);
error_free_interrupt:
if (spi->irq)
free_irq(st->us->irq, indio_dev);
error_unreg_buffer_funcs:
lis3l02dq_unconfigure_buffer(indio_dev);
return ret;
}
static int lis3l02dq_stop_device(struct iio_dev *indio_dev)
{
int ret;
struct lis3l02dq_state *st = iio_priv(indio_dev);
u8 val = 0;
mutex_lock(&indio_dev->mlock);
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_1_ADDR,
val);
if (ret) {
dev_err(&st->us->dev, "problem with turning device off: ctrl1");
goto err_ret;
}
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_2_ADDR,
val);
if (ret)
dev_err(&st->us->dev, "problem with turning device off: ctrl2");
err_ret:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int lis3l02dq_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct lis3l02dq_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
lis3l02dq_disable_all_events(indio_dev);
lis3l02dq_stop_device(indio_dev);
if (spi->irq)
free_irq(st->us->irq, indio_dev);
lis3l02dq_remove_trigger(indio_dev);
lis3l02dq_unconfigure_buffer(indio_dev);
return 0;
}
