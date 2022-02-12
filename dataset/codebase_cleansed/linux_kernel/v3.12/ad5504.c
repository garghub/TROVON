static int ad5504_spi_write(struct spi_device *spi, u8 addr, u16 val)
{
u16 tmp = cpu_to_be16(AD5504_CMD_WRITE |
AD5504_ADDR(addr) |
(val & AD5504_RES_MASK));
return spi_write(spi, (u8 *)&tmp, 2);
}
static int ad5504_spi_read(struct spi_device *spi, u8 addr)
{
u16 tmp = cpu_to_be16(AD5504_CMD_READ | AD5504_ADDR(addr));
u16 val;
int ret;
struct spi_transfer t = {
.tx_buf = &tmp,
.rx_buf = &val,
.len = 2,
};
ret = spi_sync_transfer(spi, &t, 1);
if (ret < 0)
return ret;
return be16_to_cpu(val) & AD5504_RES_MASK;
}
static int ad5504_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ad5504_state *st = iio_priv(indio_dev);
unsigned long scale_uv;
int ret;
switch (m) {
case IIO_CHAN_INFO_RAW:
ret = ad5504_spi_read(st->spi, chan->address);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
scale_uv = (st->vref_mv * 1000) >> chan->scan_type.realbits;
*val = scale_uv / 1000;
*val2 = (scale_uv % 1000) * 1000;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int ad5504_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct ad5504_state *st = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (val >= (1 << chan->scan_type.realbits) || val < 0)
return -EINVAL;
return ad5504_spi_write(st->spi, chan->address, val);
default:
ret = -EINVAL;
}
return -EINVAL;
}
static int ad5504_get_powerdown_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct ad5504_state *st = iio_priv(indio_dev);
return st->pwr_down_mode;
}
static int ad5504_set_powerdown_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned int mode)
{
struct ad5504_state *st = iio_priv(indio_dev);
st->pwr_down_mode = mode;
return 0;
}
static ssize_t ad5504_read_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
struct ad5504_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n",
!(st->pwr_down_mask & (1 << chan->channel)));
}
static ssize_t ad5504_write_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, const char *buf,
size_t len)
{
bool pwr_down;
int ret;
struct ad5504_state *st = iio_priv(indio_dev);
ret = strtobool(buf, &pwr_down);
if (ret)
return ret;
if (pwr_down)
st->pwr_down_mask |= (1 << chan->channel);
else
st->pwr_down_mask &= ~(1 << chan->channel);
ret = ad5504_spi_write(st->spi, AD5504_ADDR_CTRL,
AD5504_DAC_PWRDWN_MODE(st->pwr_down_mode) |
AD5504_DAC_PWR(st->pwr_down_mask));
ad5504_spi_write(st->spi, AD5504_ADDR_NOOP, 0);
return ret ? ret : len;
}
static irqreturn_t ad5504_event_handler(int irq, void *private)
{
iio_push_event(private,
IIO_UNMOD_EVENT_CODE(IIO_TEMP,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
iio_get_time_ns());
return IRQ_HANDLED;
}
static int ad5504_probe(struct spi_device *spi)
{
struct ad5504_platform_data *pdata = spi->dev.platform_data;
struct iio_dev *indio_dev;
struct ad5504_state *st;
struct regulator *reg;
int ret, voltage_uv = 0;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
reg = devm_regulator_get(&spi->dev, "vcc");
if (!IS_ERR(reg)) {
ret = regulator_enable(reg);
if (ret)
return ret;
ret = regulator_get_voltage(reg);
if (ret < 0)
goto error_disable_reg;
voltage_uv = ret;
}
spi_set_drvdata(spi, indio_dev);
st = iio_priv(indio_dev);
if (voltage_uv)
st->vref_mv = voltage_uv / 1000;
else if (pdata)
st->vref_mv = pdata->vref_mv;
else
dev_warn(&spi->dev, "reference voltage unspecified\n");
st->reg = reg;
st->spi = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(st->spi)->name;
indio_dev->info = &ad5504_info;
if (spi_get_device_id(st->spi)->driver_data == ID_AD5501)
indio_dev->num_channels = 1;
else
indio_dev->num_channels = 4;
indio_dev->channels = ad5504_channels;
indio_dev->modes = INDIO_DIRECT_MODE;
if (spi->irq) {
ret = devm_request_threaded_irq(&spi->dev, spi->irq,
NULL,
&ad5504_event_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
spi_get_device_id(st->spi)->name,
indio_dev);
if (ret)
goto error_disable_reg;
}
ret = iio_device_register(indio_dev);
if (ret)
goto error_disable_reg;
return 0;
error_disable_reg:
if (!IS_ERR(reg))
regulator_disable(reg);
return ret;
}
static int ad5504_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad5504_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
return 0;
}
