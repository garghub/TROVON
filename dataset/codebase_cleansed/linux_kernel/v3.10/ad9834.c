static unsigned int ad9834_calc_freqreg(unsigned long mclk, unsigned long fout)
{
unsigned long long freqreg = (u64) fout * (u64) (1 << AD9834_FREQ_BITS);
do_div(freqreg, mclk);
return freqreg;
}
static int ad9834_write_frequency(struct ad9834_state *st,
unsigned long addr, unsigned long fout)
{
unsigned long regval;
if (fout > (st->mclk / 2))
return -EINVAL;
regval = ad9834_calc_freqreg(st->mclk, fout);
st->freq_data[0] = cpu_to_be16(addr | (regval &
RES_MASK(AD9834_FREQ_BITS / 2)));
st->freq_data[1] = cpu_to_be16(addr | ((regval >>
(AD9834_FREQ_BITS / 2)) &
RES_MASK(AD9834_FREQ_BITS / 2)));
return spi_sync(st->spi, &st->freq_msg);
}
static int ad9834_write_phase(struct ad9834_state *st,
unsigned long addr, unsigned long phase)
{
if (phase > (1 << AD9834_PHASE_BITS))
return -EINVAL;
st->data = cpu_to_be16(addr | phase);
return spi_sync(st->spi, &st->msg);
}
static ssize_t ad9834_write(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad9834_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret;
long val;
ret = strict_strtoul(buf, 10, &val);
if (ret)
goto error_ret;
mutex_lock(&indio_dev->mlock);
switch ((u32) this_attr->address) {
case AD9834_REG_FREQ0:
case AD9834_REG_FREQ1:
ret = ad9834_write_frequency(st, this_attr->address, val);
break;
case AD9834_REG_PHASE0:
case AD9834_REG_PHASE1:
ret = ad9834_write_phase(st, this_attr->address, val);
break;
case AD9834_OPBITEN:
if (st->control & AD9834_MODE) {
ret = -EINVAL;
break;
}
if (val)
st->control |= AD9834_OPBITEN;
else
st->control &= ~AD9834_OPBITEN;
st->data = cpu_to_be16(AD9834_REG_CMD | st->control);
ret = spi_sync(st->spi, &st->msg);
break;
case AD9834_PIN_SW:
if (val)
st->control |= AD9834_PIN_SW;
else
st->control &= ~AD9834_PIN_SW;
st->data = cpu_to_be16(AD9834_REG_CMD | st->control);
ret = spi_sync(st->spi, &st->msg);
break;
case AD9834_FSEL:
case AD9834_PSEL:
if (val == 0)
st->control &= ~(this_attr->address | AD9834_PIN_SW);
else if (val == 1) {
st->control |= this_attr->address;
st->control &= ~AD9834_PIN_SW;
} else {
ret = -EINVAL;
break;
}
st->data = cpu_to_be16(AD9834_REG_CMD | st->control);
ret = spi_sync(st->spi, &st->msg);
break;
case AD9834_RESET:
if (val)
st->control &= ~AD9834_RESET;
else
st->control |= AD9834_RESET;
st->data = cpu_to_be16(AD9834_REG_CMD | st->control);
ret = spi_sync(st->spi, &st->msg);
break;
default:
ret = -ENODEV;
}
mutex_unlock(&indio_dev->mlock);
error_ret:
return ret ? ret : len;
}
static ssize_t ad9834_store_wavetype(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad9834_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret = 0;
bool is_ad9833_7 = (st->devid == ID_AD9833) || (st->devid == ID_AD9837);
mutex_lock(&indio_dev->mlock);
switch ((u32) this_attr->address) {
case 0:
if (sysfs_streq(buf, "sine")) {
st->control &= ~AD9834_MODE;
if (is_ad9833_7)
st->control &= ~AD9834_OPBITEN;
} else if (sysfs_streq(buf, "triangle")) {
if (is_ad9833_7) {
st->control &= ~AD9834_OPBITEN;
st->control |= AD9834_MODE;
} else if (st->control & AD9834_OPBITEN) {
ret = -EINVAL;
} else {
st->control |= AD9834_MODE;
}
} else if (is_ad9833_7 && sysfs_streq(buf, "square")) {
st->control &= ~AD9834_MODE;
st->control |= AD9834_OPBITEN;
} else {
ret = -EINVAL;
}
break;
case 1:
if (sysfs_streq(buf, "square") &&
!(st->control & AD9834_MODE)) {
st->control &= ~AD9834_MODE;
st->control |= AD9834_OPBITEN;
} else {
ret = -EINVAL;
}
break;
default:
ret = -EINVAL;
break;
}
if (!ret) {
st->data = cpu_to_be16(AD9834_REG_CMD | st->control);
ret = spi_sync(st->spi, &st->msg);
}
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static ssize_t ad9834_show_out0_wavetype_available(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad9834_state *st = iio_priv(indio_dev);
char *str;
if ((st->devid == ID_AD9833) || (st->devid == ID_AD9837))
str = "sine triangle square";
else if (st->control & AD9834_OPBITEN)
str = "sine";
else
str = "sine triangle";
return sprintf(buf, "%s\n", str);
}
static ssize_t ad9834_show_out1_wavetype_available(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad9834_state *st = iio_priv(indio_dev);
char *str;
if (st->control & AD9834_MODE)
str = "";
else
str = "square";
return sprintf(buf, "%s\n", str);
}
static int ad9834_probe(struct spi_device *spi)
{
struct ad9834_platform_data *pdata = spi->dev.platform_data;
struct ad9834_state *st;
struct iio_dev *indio_dev;
struct regulator *reg;
int ret;
if (!pdata) {
dev_dbg(&spi->dev, "no platform data?\n");
return -ENODEV;
}
reg = regulator_get(&spi->dev, "vcc");
if (!IS_ERR(reg)) {
ret = regulator_enable(reg);
if (ret)
goto error_put_reg;
}
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_disable_reg;
}
spi_set_drvdata(spi, indio_dev);
st = iio_priv(indio_dev);
st->mclk = pdata->mclk;
st->spi = spi;
st->devid = spi_get_device_id(spi)->driver_data;
st->reg = reg;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
switch (st->devid) {
case ID_AD9833:
case ID_AD9837:
indio_dev->info = &ad9833_info;
break;
default:
indio_dev->info = &ad9834_info;
break;
}
indio_dev->modes = INDIO_DIRECT_MODE;
st->xfer.tx_buf = &st->data;
st->xfer.len = 2;
spi_message_init(&st->msg);
spi_message_add_tail(&st->xfer, &st->msg);
st->freq_xfer[0].tx_buf = &st->freq_data[0];
st->freq_xfer[0].len = 2;
st->freq_xfer[0].cs_change = 1;
st->freq_xfer[1].tx_buf = &st->freq_data[1];
st->freq_xfer[1].len = 2;
spi_message_init(&st->freq_msg);
spi_message_add_tail(&st->freq_xfer[0], &st->freq_msg);
spi_message_add_tail(&st->freq_xfer[1], &st->freq_msg);
st->control = AD9834_B28 | AD9834_RESET;
if (!pdata->en_div2)
st->control |= AD9834_DIV2;
if (!pdata->en_signbit_msb_out && (st->devid == ID_AD9834))
st->control |= AD9834_SIGN_PIB;
st->data = cpu_to_be16(AD9834_REG_CMD | st->control);
ret = spi_sync(st->spi, &st->msg);
if (ret) {
dev_err(&spi->dev, "device init failed\n");
goto error_free_device;
}
ret = ad9834_write_frequency(st, AD9834_REG_FREQ0, pdata->freq0);
if (ret)
goto error_free_device;
ret = ad9834_write_frequency(st, AD9834_REG_FREQ1, pdata->freq1);
if (ret)
goto error_free_device;
ret = ad9834_write_phase(st, AD9834_REG_PHASE0, pdata->phase0);
if (ret)
goto error_free_device;
ret = ad9834_write_phase(st, AD9834_REG_PHASE1, pdata->phase1);
if (ret)
goto error_free_device;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_device;
return 0;
error_free_device:
iio_device_free(indio_dev);
error_disable_reg:
if (!IS_ERR(reg))
regulator_disable(reg);
error_put_reg:
if (!IS_ERR(reg))
regulator_put(reg);
return ret;
}
static int ad9834_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad9834_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (!IS_ERR(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
iio_device_free(indio_dev);
return 0;
}
