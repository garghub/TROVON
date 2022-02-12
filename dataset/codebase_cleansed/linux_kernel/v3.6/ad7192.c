static int __ad7192_write_reg(struct ad7192_state *st, bool locked,
bool cs_change, unsigned char reg,
unsigned size, unsigned val)
{
u8 *data = st->data;
struct spi_transfer t = {
.tx_buf = data,
.len = size + 1,
.cs_change = cs_change,
};
struct spi_message m;
data[0] = AD7192_COMM_WRITE | AD7192_COMM_ADDR(reg);
switch (size) {
case 3:
data[1] = val >> 16;
data[2] = val >> 8;
data[3] = val;
break;
case 2:
data[1] = val >> 8;
data[2] = val;
break;
case 1:
data[1] = val;
break;
default:
return -EINVAL;
}
spi_message_init(&m);
spi_message_add_tail(&t, &m);
if (locked)
return spi_sync_locked(st->spi, &m);
else
return spi_sync(st->spi, &m);
}
static int ad7192_write_reg(struct ad7192_state *st,
unsigned reg, unsigned size, unsigned val)
{
return __ad7192_write_reg(st, false, false, reg, size, val);
}
static int __ad7192_read_reg(struct ad7192_state *st, bool locked,
bool cs_change, unsigned char reg,
int *val, unsigned size)
{
u8 *data = st->data;
int ret;
struct spi_transfer t[] = {
{
.tx_buf = data,
.len = 1,
}, {
.rx_buf = data,
.len = size,
.cs_change = cs_change,
},
};
struct spi_message m;
data[0] = AD7192_COMM_READ | AD7192_COMM_ADDR(reg);
spi_message_init(&m);
spi_message_add_tail(&t[0], &m);
spi_message_add_tail(&t[1], &m);
if (locked)
ret = spi_sync_locked(st->spi, &m);
else
ret = spi_sync(st->spi, &m);
if (ret < 0)
return ret;
switch (size) {
case 3:
*val = data[0] << 16 | data[1] << 8 | data[2];
break;
case 2:
*val = data[0] << 8 | data[1];
break;
case 1:
*val = data[0];
break;
default:
return -EINVAL;
}
return 0;
}
static int ad7192_read_reg(struct ad7192_state *st,
unsigned reg, int *val, unsigned size)
{
return __ad7192_read_reg(st, 0, 0, reg, val, size);
}
static int ad7192_read(struct ad7192_state *st, unsigned ch,
unsigned len, int *val)
{
int ret;
st->conf = (st->conf & ~AD7192_CONF_CHAN(-1)) |
AD7192_CONF_CHAN(1 << ch);
st->mode = (st->mode & ~AD7192_MODE_SEL(-1)) |
AD7192_MODE_SEL(AD7192_MODE_SINGLE);
ad7192_write_reg(st, AD7192_REG_CONF, 3, st->conf);
spi_bus_lock(st->spi->master);
st->done = false;
ret = __ad7192_write_reg(st, 1, 1, AD7192_REG_MODE, 3, st->mode);
if (ret < 0)
goto out;
st->irq_dis = false;
enable_irq(st->spi->irq);
wait_event_interruptible(st->wq_data_avail, st->done);
ret = __ad7192_read_reg(st, 1, 0, AD7192_REG_DATA, val, len);
out:
spi_bus_unlock(st->spi->master);
return ret;
}
static int ad7192_calibrate(struct ad7192_state *st, unsigned mode, unsigned ch)
{
int ret;
st->conf = (st->conf & ~AD7192_CONF_CHAN(-1)) |
AD7192_CONF_CHAN(1 << ch);
st->mode = (st->mode & ~AD7192_MODE_SEL(-1)) | AD7192_MODE_SEL(mode);
ad7192_write_reg(st, AD7192_REG_CONF, 3, st->conf);
spi_bus_lock(st->spi->master);
st->done = false;
ret = __ad7192_write_reg(st, 1, 1, AD7192_REG_MODE, 3,
(st->devid != ID_AD7195) ?
st->mode | AD7192_MODE_CLKDIV :
st->mode);
if (ret < 0)
goto out;
st->irq_dis = false;
enable_irq(st->spi->irq);
wait_event_interruptible(st->wq_data_avail, st->done);
st->mode = (st->mode & ~AD7192_MODE_SEL(-1)) |
AD7192_MODE_SEL(AD7192_MODE_IDLE);
ret = __ad7192_write_reg(st, 1, 0, AD7192_REG_MODE, 3, st->mode);
out:
spi_bus_unlock(st->spi->master);
return ret;
}
static int ad7192_calibrate_all(struct ad7192_state *st)
{
int i, ret;
for (i = 0; i < ARRAY_SIZE(ad7192_calib_arr); i++) {
ret = ad7192_calibrate(st, ad7192_calib_arr[i][0],
ad7192_calib_arr[i][1]);
if (ret)
goto out;
}
return 0;
out:
dev_err(&st->spi->dev, "Calibration failed\n");
return ret;
}
static int ad7192_setup(struct ad7192_state *st)
{
struct iio_dev *indio_dev = spi_get_drvdata(st->spi);
struct ad7192_platform_data *pdata = st->pdata;
unsigned long long scale_uv;
int i, ret, id;
u8 ones[6];
memset(&ones, 0xFF, 6);
ret = spi_write(st->spi, &ones, 6);
if (ret < 0)
goto out;
msleep(1);
ret = ad7192_read_reg(st, AD7192_REG_ID, &id, 1);
if (ret)
goto out;
id &= AD7192_ID_MASK;
if (id != st->devid)
dev_warn(&st->spi->dev, "device ID query failed (0x%X)\n", id);
switch (pdata->clock_source_sel) {
case AD7192_CLK_EXT_MCLK1_2:
case AD7192_CLK_EXT_MCLK2:
st->mclk = AD7192_INT_FREQ_MHz;
break;
case AD7192_CLK_INT:
case AD7192_CLK_INT_CO:
if (pdata->ext_clk_Hz)
st->mclk = pdata->ext_clk_Hz;
else
st->mclk = AD7192_INT_FREQ_MHz;
break;
default:
ret = -EINVAL;
goto out;
}
st->mode = AD7192_MODE_SEL(AD7192_MODE_IDLE) |
AD7192_MODE_CLKSRC(pdata->clock_source_sel) |
AD7192_MODE_RATE(480);
st->conf = AD7192_CONF_GAIN(0);
if (pdata->rej60_en)
st->mode |= AD7192_MODE_REJ60;
if (pdata->sinc3_en)
st->mode |= AD7192_MODE_SINC3;
if (pdata->refin2_en && (st->devid != ID_AD7195))
st->conf |= AD7192_CONF_REFSEL;
if (pdata->chop_en) {
st->conf |= AD7192_CONF_CHOP;
if (pdata->sinc3_en)
st->f_order = 3;
else
st->f_order = 4;
} else {
st->f_order = 1;
}
if (pdata->buf_en)
st->conf |= AD7192_CONF_BUF;
if (pdata->unipolar_en)
st->conf |= AD7192_CONF_UNIPOLAR;
if (pdata->burnout_curr_en)
st->conf |= AD7192_CONF_BURN;
ret = ad7192_write_reg(st, AD7192_REG_MODE, 3, st->mode);
if (ret)
goto out;
ret = ad7192_write_reg(st, AD7192_REG_CONF, 3, st->conf);
if (ret)
goto out;
ret = ad7192_calibrate_all(st);
if (ret)
goto out;
for (i = 0; i < ARRAY_SIZE(st->scale_avail); i++) {
scale_uv = ((u64)st->int_vref_mv * 100000000)
>> (indio_dev->channels[0].scan_type.realbits -
((st->conf & AD7192_CONF_UNIPOLAR) ? 0 : 1));
scale_uv >>= i;
st->scale_avail[i][1] = do_div(scale_uv, 100000000) * 10;
st->scale_avail[i][0] = scale_uv;
}
return 0;
out:
dev_err(&st->spi->dev, "setup failed\n");
return ret;
}
static int ad7192_ring_preenable(struct iio_dev *indio_dev)
{
struct ad7192_state *st = iio_priv(indio_dev);
unsigned channel;
int ret;
if (bitmap_empty(indio_dev->active_scan_mask, indio_dev->masklength))
return -EINVAL;
ret = iio_sw_buffer_preenable(indio_dev);
if (ret < 0)
return ret;
channel = find_first_bit(indio_dev->active_scan_mask,
indio_dev->masklength);
st->mode = (st->mode & ~AD7192_MODE_SEL(-1)) |
AD7192_MODE_SEL(AD7192_MODE_CONT);
st->conf = (st->conf & ~AD7192_CONF_CHAN(-1)) |
AD7192_CONF_CHAN(1 << indio_dev->channels[channel].address);
ad7192_write_reg(st, AD7192_REG_CONF, 3, st->conf);
spi_bus_lock(st->spi->master);
__ad7192_write_reg(st, 1, 1, AD7192_REG_MODE, 3, st->mode);
st->irq_dis = false;
enable_irq(st->spi->irq);
return 0;
}
static int ad7192_ring_postdisable(struct iio_dev *indio_dev)
{
struct ad7192_state *st = iio_priv(indio_dev);
st->mode = (st->mode & ~AD7192_MODE_SEL(-1)) |
AD7192_MODE_SEL(AD7192_MODE_IDLE);
st->done = false;
wait_event_interruptible(st->wq_data_avail, st->done);
if (!st->irq_dis)
disable_irq_nosync(st->spi->irq);
__ad7192_write_reg(st, 1, 0, AD7192_REG_MODE, 3, st->mode);
return spi_bus_unlock(st->spi->master);
}
static irqreturn_t ad7192_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct iio_buffer *ring = indio_dev->buffer;
struct ad7192_state *st = iio_priv(indio_dev);
s64 dat64[2];
s32 *dat32 = (s32 *)dat64;
if (!bitmap_empty(indio_dev->active_scan_mask, indio_dev->masklength))
__ad7192_read_reg(st, 1, 1, AD7192_REG_DATA,
dat32,
indio_dev->channels[0].scan_type.realbits/8);
if (indio_dev->scan_timestamp)
dat64[1] = pf->timestamp;
ring->access->store_to(ring, (u8 *)dat64, pf->timestamp);
iio_trigger_notify_done(indio_dev->trig);
st->irq_dis = false;
enable_irq(st->spi->irq);
return IRQ_HANDLED;
}
static int ad7192_register_ring_funcs_and_init(struct iio_dev *indio_dev)
{
return iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
&ad7192_trigger_handler, &ad7192_ring_setup_ops);
}
static void ad7192_ring_cleanup(struct iio_dev *indio_dev)
{
iio_triggered_buffer_cleanup(indio_dev);
}
static irqreturn_t ad7192_data_rdy_trig_poll(int irq, void *private)
{
struct ad7192_state *st = iio_priv(private);
st->done = true;
wake_up_interruptible(&st->wq_data_avail);
disable_irq_nosync(irq);
st->irq_dis = true;
iio_trigger_poll(st->trig, iio_get_time_ns());
return IRQ_HANDLED;
}
static int ad7192_probe_trigger(struct iio_dev *indio_dev)
{
struct ad7192_state *st = iio_priv(indio_dev);
int ret;
st->trig = iio_trigger_alloc("%s-dev%d",
spi_get_device_id(st->spi)->name,
indio_dev->id);
if (st->trig == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st->trig->ops = &ad7192_trigger_ops;
ret = request_irq(st->spi->irq,
ad7192_data_rdy_trig_poll,
IRQF_TRIGGER_LOW,
spi_get_device_id(st->spi)->name,
indio_dev);
if (ret)
goto error_free_trig;
disable_irq_nosync(st->spi->irq);
st->irq_dis = true;
st->trig->dev.parent = &st->spi->dev;
st->trig->private_data = indio_dev;
ret = iio_trigger_register(st->trig);
indio_dev->trig = st->trig;
if (ret)
goto error_free_irq;
return 0;
error_free_irq:
free_irq(st->spi->irq, indio_dev);
error_free_trig:
iio_trigger_free(st->trig);
error_ret:
return ret;
}
static void ad7192_remove_trigger(struct iio_dev *indio_dev)
{
struct ad7192_state *st = iio_priv(indio_dev);
iio_trigger_unregister(st->trig);
free_irq(st->spi->irq, indio_dev);
iio_trigger_free(st->trig);
}
static ssize_t ad7192_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7192_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n", st->mclk /
(st->f_order * 1024 * AD7192_MODE_RATE(st->mode)));
}
static ssize_t ad7192_write_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7192_state *st = iio_priv(indio_dev);
unsigned long lval;
int div, ret;
ret = strict_strtoul(buf, 10, &lval);
if (ret)
return ret;
if (lval == 0)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev)) {
mutex_unlock(&indio_dev->mlock);
return -EBUSY;
}
div = st->mclk / (lval * st->f_order * 1024);
if (div < 1 || div > 1023) {
ret = -EINVAL;
goto out;
}
st->mode &= ~AD7192_MODE_RATE(-1);
st->mode |= AD7192_MODE_RATE(div);
ad7192_write_reg(st, AD7192_REG_MODE, 3, st->mode);
out:
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static ssize_t ad7192_show_scale_available(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7192_state *st = iio_priv(indio_dev);
int i, len = 0;
for (i = 0; i < ARRAY_SIZE(st->scale_avail); i++)
len += sprintf(buf + len, "%d.%09u ", st->scale_avail[i][0],
st->scale_avail[i][1]);
len += sprintf(buf + len, "\n");
return len;
}
static ssize_t ad7192_show_ac_excitation(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7192_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n", !!(st->mode & AD7192_MODE_ACX));
}
static ssize_t ad7192_show_bridge_switch(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7192_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n", !!(st->gpocon & AD7192_GPOCON_BPDSW));
}
static ssize_t ad7192_set(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7192_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret;
bool val;
ret = strtobool(buf, &val);
if (ret < 0)
return ret;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev)) {
mutex_unlock(&indio_dev->mlock);
return -EBUSY;
}
switch ((u32) this_attr->address) {
case AD7192_REG_GPOCON:
if (val)
st->gpocon |= AD7192_GPOCON_BPDSW;
else
st->gpocon &= ~AD7192_GPOCON_BPDSW;
ad7192_write_reg(st, AD7192_REG_GPOCON, 1, st->gpocon);
break;
case AD7192_REG_MODE:
if (val)
st->mode |= AD7192_MODE_ACX;
else
st->mode &= ~AD7192_MODE_ACX;
ad7192_write_reg(st, AD7192_REG_MODE, 3, st->mode);
break;
default:
ret = -EINVAL;
}
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static unsigned int ad7192_get_temp_scale(bool unipolar)
{
return unipolar ? 2815 * 2 : 2815;
}
static int ad7192_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ad7192_state *st = iio_priv(indio_dev);
int ret, smpl = 0;
bool unipolar = !!(st->conf & AD7192_CONF_UNIPOLAR);
switch (m) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev))
ret = -EBUSY;
else
ret = ad7192_read(st, chan->address,
chan->scan_type.realbits / 8, &smpl);
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
*val = (smpl >> chan->scan_type.shift) &
((1 << (chan->scan_type.realbits)) - 1);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_VOLTAGE:
mutex_lock(&indio_dev->mlock);
*val = st->scale_avail[AD7192_CONF_GAIN(st->conf)][0];
*val2 = st->scale_avail[AD7192_CONF_GAIN(st->conf)][1];
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT_PLUS_NANO;
case IIO_TEMP:
*val = 0;
*val2 = 1000000000 / ad7192_get_temp_scale(unipolar);
return IIO_VAL_INT_PLUS_NANO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
if (!unipolar)
*val = -(1 << (chan->scan_type.realbits - 1));
else
*val = 0;
if (chan->type == IIO_TEMP)
*val -= 273 * ad7192_get_temp_scale(unipolar);
return IIO_VAL_INT;
}
return -EINVAL;
}
static int ad7192_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct ad7192_state *st = iio_priv(indio_dev);
int ret, i;
unsigned int tmp;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev)) {
mutex_unlock(&indio_dev->mlock);
return -EBUSY;
}
switch (mask) {
case IIO_CHAN_INFO_SCALE:
ret = -EINVAL;
for (i = 0; i < ARRAY_SIZE(st->scale_avail); i++)
if (val2 == st->scale_avail[i][1]) {
tmp = st->conf;
st->conf &= ~AD7192_CONF_GAIN(-1);
st->conf |= AD7192_CONF_GAIN(i);
if (tmp != st->conf) {
ad7192_write_reg(st, AD7192_REG_CONF,
3, st->conf);
ad7192_calibrate_all(st);
}
ret = 0;
}
break;
default:
ret = -EINVAL;
}
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad7192_validate_trigger(struct iio_dev *indio_dev,
struct iio_trigger *trig)
{
if (indio_dev->trig != trig)
return -EINVAL;
return 0;
}
static int ad7192_write_raw_get_fmt(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
long mask)
{
return IIO_VAL_INT_PLUS_NANO;
}
static int __devinit ad7192_probe(struct spi_device *spi)
{
struct ad7192_platform_data *pdata = spi->dev.platform_data;
struct ad7192_state *st;
struct iio_dev *indio_dev;
int ret , voltage_uv = 0;
if (!pdata) {
dev_err(&spi->dev, "no platform data?\n");
return -ENODEV;
}
if (!spi->irq) {
dev_err(&spi->dev, "no IRQ?\n");
return -ENODEV;
}
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
st->reg = regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
voltage_uv = regulator_get_voltage(st->reg);
}
st->pdata = pdata;
if (pdata && pdata->vref_mv)
st->int_vref_mv = pdata->vref_mv;
else if (voltage_uv)
st->int_vref_mv = voltage_uv / 1000;
else
dev_warn(&spi->dev, "reference voltage undefined\n");
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
st->devid = spi_get_device_id(spi)->driver_data;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = ad7192_channels;
indio_dev->num_channels = ARRAY_SIZE(ad7192_channels);
if (st->devid == ID_AD7195)
indio_dev->info = &ad7195_info;
else
indio_dev->info = &ad7192_info;
init_waitqueue_head(&st->wq_data_avail);
ret = ad7192_register_ring_funcs_and_init(indio_dev);
if (ret)
goto error_disable_reg;
ret = ad7192_probe_trigger(indio_dev);
if (ret)
goto error_ring_cleanup;
ret = ad7192_setup(st);
if (ret)
goto error_remove_trigger;
ret = iio_device_register(indio_dev);
if (ret < 0)
goto error_remove_trigger;
return 0;
error_remove_trigger:
ad7192_remove_trigger(indio_dev);
error_ring_cleanup:
ad7192_ring_cleanup(indio_dev);
error_disable_reg:
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
error_put_reg:
if (!IS_ERR(st->reg))
regulator_put(st->reg);
iio_device_free(indio_dev);
return ret;
}
static int ad7192_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7192_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
ad7192_remove_trigger(indio_dev);
ad7192_ring_cleanup(indio_dev);
if (!IS_ERR(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
return 0;
}
