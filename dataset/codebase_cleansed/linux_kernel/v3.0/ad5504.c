static int ad5504_spi_write(struct spi_device *spi, u8 addr, u16 val)
{
u16 tmp = cpu_to_be16(AD5504_CMD_WRITE |
AD5504_ADDR(addr) |
(val & AD5504_RES_MASK));
return spi_write(spi, (u8 *)&tmp, 2);
}
static int ad5504_spi_read(struct spi_device *spi, u8 addr, u16 *val)
{
u16 tmp = cpu_to_be16(AD5504_CMD_READ | AD5504_ADDR(addr));
int ret;
struct spi_transfer t = {
.tx_buf = &tmp,
.rx_buf = val,
.len = 2,
};
struct spi_message m;
spi_message_init(&m);
spi_message_add_tail(&t, &m);
ret = spi_sync(spi, &m);
*val = be16_to_cpu(*val) & AD5504_RES_MASK;
return ret;
}
static ssize_t ad5504_write_dac(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5504_state *st = iio_dev_get_devdata(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
long readin;
int ret;
ret = strict_strtol(buf, 10, &readin);
if (ret)
return ret;
ret = ad5504_spi_write(st->spi, this_attr->address, readin);
return ret ? ret : len;
}
static ssize_t ad5504_read_dac(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5504_state *st = iio_dev_get_devdata(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret;
u16 val;
ret = ad5504_spi_read(st->spi, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%d\n", val);
}
static ssize_t ad5504_read_powerdown_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5504_state *st = iio_dev_get_devdata(indio_dev);
const char mode[][14] = {"20kohm_to_gnd", "three_state"};
return sprintf(buf, "%s\n", mode[st->pwr_down_mode]);
}
static ssize_t ad5504_write_powerdown_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5504_state *st = iio_dev_get_devdata(indio_dev);
int ret;
if (sysfs_streq(buf, "20kohm_to_gnd"))
st->pwr_down_mode = AD5504_DAC_PWRDN_20K;
else if (sysfs_streq(buf, "three_state"))
st->pwr_down_mode = AD5504_DAC_PWRDN_3STATE;
else
ret = -EINVAL;
return ret ? ret : len;
}
static ssize_t ad5504_read_dac_powerdown(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5504_state *st = iio_dev_get_devdata(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
return sprintf(buf, "%d\n",
!(st->pwr_down_mask & (1 << this_attr->address)));
}
static ssize_t ad5504_write_dac_powerdown(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
long readin;
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5504_state *st = iio_dev_get_devdata(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = strict_strtol(buf, 10, &readin);
if (ret)
return ret;
if (readin == 0)
st->pwr_down_mask |= (1 << this_attr->address);
else if (readin == 1)
st->pwr_down_mask &= ~(1 << this_attr->address);
else
ret = -EINVAL;
ret = ad5504_spi_write(st->spi, AD5504_ADDR_CTRL,
AD5504_DAC_PWRDWN_MODE(st->pwr_down_mode) |
AD5504_DAC_PWR(st->pwr_down_mask));
ad5504_spi_write(st->spi, AD5504_ADDR_NOOP, 0);
return ret ? ret : len;
}
static ssize_t ad5504_show_scale(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5504_state *st = iio_dev_get_devdata(indio_dev);
unsigned int scale_uv = (st->vref_mv * 1000) >> AD5505_BITS;
return sprintf(buf, "%d.%03d\n", scale_uv / 1000, scale_uv % 1000);
}
static irqreturn_t ad5504_event_handler(int irq, void *private)
{
iio_push_event(private, 0,
IIO_UNMOD_EVENT_CODE(IIO_EV_CLASS_TEMP,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
iio_get_time_ns());
return IRQ_HANDLED;
}
static int __devinit ad5504_probe(struct spi_device *spi)
{
struct ad5504_platform_data *pdata = spi->dev.platform_data;
struct ad5504_state *st;
int ret, voltage_uv = 0;
st = kzalloc(sizeof(*st), GFP_KERNEL);
if (st == NULL) {
ret = -ENOMEM;
goto error_ret;
}
spi_set_drvdata(spi, st);
st->reg = regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
voltage_uv = regulator_get_voltage(st->reg);
}
if (voltage_uv)
st->vref_mv = voltage_uv / 1000;
else if (pdata)
st->vref_mv = pdata->vref_mv;
else
dev_warn(&spi->dev, "reference voltage unspecified\n");
st->spi = spi;
st->indio_dev = iio_allocate_device(0);
if (st->indio_dev == NULL) {
ret = -ENOMEM;
goto error_disable_reg;
}
st->indio_dev->dev.parent = &spi->dev;
st->indio_dev->name = spi_get_device_id(st->spi)->name;
if (spi_get_device_id(st->spi)->driver_data == ID_AD5501)
st->indio_dev->info = &ad5501_info;
else
st->indio_dev->info = &ad5504_info;
st->indio_dev->dev_data = (void *)(st);
st->indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(st->indio_dev);
if (ret)
goto error_free_dev;
if (spi->irq) {
ret = request_threaded_irq(spi->irq,
NULL,
&ad5504_event_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
spi_get_device_id(st->spi)->name,
st->indio_dev);
if (ret)
goto error_unreg_iio_device;
}
return 0;
error_unreg_iio_device:
iio_device_unregister(st->indio_dev);
error_free_dev:
iio_free_device(st->indio_dev);
error_disable_reg:
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
error_put_reg:
if (!IS_ERR(st->reg))
regulator_put(st->reg);
kfree(st);
error_ret:
return ret;
}
static int __devexit ad5504_remove(struct spi_device *spi)
{
struct ad5504_state *st = spi_get_drvdata(spi);
if (spi->irq)
free_irq(spi->irq, st->indio_dev);
iio_device_unregister(st->indio_dev);
if (!IS_ERR(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
kfree(st);
return 0;
}
static __init int ad5504_spi_init(void)
{
return spi_register_driver(&ad5504_driver);
}
static __exit void ad5504_spi_exit(void)
{
spi_unregister_driver(&ad5504_driver);
}
