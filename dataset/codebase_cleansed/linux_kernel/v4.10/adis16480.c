static ssize_t adis16480_show_firmware_revision(struct file *file,
char __user *userbuf, size_t count, loff_t *ppos)
{
struct adis16480 *adis16480 = file->private_data;
char buf[7];
size_t len;
u16 rev;
int ret;
ret = adis_read_reg_16(&adis16480->adis, ADIS16480_REG_FIRM_REV, &rev);
if (ret < 0)
return ret;
len = scnprintf(buf, sizeof(buf), "%x.%x\n", rev >> 8, rev & 0xff);
return simple_read_from_buffer(userbuf, count, ppos, buf, len);
}
static ssize_t adis16480_show_firmware_date(struct file *file,
char __user *userbuf, size_t count, loff_t *ppos)
{
struct adis16480 *adis16480 = file->private_data;
u16 md, year;
char buf[12];
size_t len;
int ret;
ret = adis_read_reg_16(&adis16480->adis, ADIS16480_REG_FIRM_Y, &year);
if (ret < 0)
return ret;
ret = adis_read_reg_16(&adis16480->adis, ADIS16480_REG_FIRM_DM, &md);
if (ret < 0)
return ret;
len = snprintf(buf, sizeof(buf), "%.2x-%.2x-%.4x\n",
md >> 8, md & 0xff, year);
return simple_read_from_buffer(userbuf, count, ppos, buf, len);
}
static int adis16480_show_serial_number(void *arg, u64 *val)
{
struct adis16480 *adis16480 = arg;
u16 serial;
int ret;
ret = adis_read_reg_16(&adis16480->adis, ADIS16480_REG_SERIAL_NUM,
&serial);
if (ret < 0)
return ret;
*val = serial;
return 0;
}
static int adis16480_show_product_id(void *arg, u64 *val)
{
struct adis16480 *adis16480 = arg;
u16 prod_id;
int ret;
ret = adis_read_reg_16(&adis16480->adis, ADIS16480_REG_PROD_ID,
&prod_id);
if (ret < 0)
return ret;
*val = prod_id;
return 0;
}
static int adis16480_show_flash_count(void *arg, u64 *val)
{
struct adis16480 *adis16480 = arg;
u32 flash_count;
int ret;
ret = adis_read_reg_32(&adis16480->adis, ADIS16480_REG_FLASH_CNT,
&flash_count);
if (ret < 0)
return ret;
*val = flash_count;
return 0;
}
static int adis16480_debugfs_init(struct iio_dev *indio_dev)
{
struct adis16480 *adis16480 = iio_priv(indio_dev);
debugfs_create_file("firmware_revision", 0400,
indio_dev->debugfs_dentry, adis16480,
&adis16480_firmware_revision_fops);
debugfs_create_file("firmware_date", 0400, indio_dev->debugfs_dentry,
adis16480, &adis16480_firmware_date_fops);
debugfs_create_file("serial_number", 0400, indio_dev->debugfs_dentry,
adis16480, &adis16480_serial_number_fops);
debugfs_create_file("product_id", 0400, indio_dev->debugfs_dentry,
adis16480, &adis16480_product_id_fops);
debugfs_create_file("flash_count", 0400, indio_dev->debugfs_dentry,
adis16480, &adis16480_flash_count_fops);
return 0;
}
static int adis16480_debugfs_init(struct iio_dev *indio_dev)
{
return 0;
}
static int adis16480_set_freq(struct iio_dev *indio_dev, int val, int val2)
{
struct adis16480 *st = iio_priv(indio_dev);
unsigned int t;
t = val * 1000 + val2 / 1000;
if (t <= 0)
return -EINVAL;
t = 2460000 / t;
if (t > 2048)
t = 2048;
if (t != 0)
t--;
return adis_write_reg_16(&st->adis, ADIS16480_REG_DEC_RATE, t);
}
static int adis16480_get_freq(struct iio_dev *indio_dev, int *val, int *val2)
{
struct adis16480 *st = iio_priv(indio_dev);
uint16_t t;
int ret;
unsigned freq;
ret = adis_read_reg_16(&st->adis, ADIS16480_REG_DEC_RATE, &t);
if (ret < 0)
return ret;
freq = 2460000 / (t + 1);
*val = freq / 1000;
*val2 = (freq % 1000) * 1000;
return IIO_VAL_INT_PLUS_MICRO;
}
static int adis16480_set_calibbias(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, int bias)
{
unsigned int reg = adis16480_calibbias_regs[chan->scan_index];
struct adis16480 *st = iio_priv(indio_dev);
switch (chan->type) {
case IIO_MAGN:
case IIO_PRESSURE:
if (bias < -0x8000 || bias >= 0x8000)
return -EINVAL;
return adis_write_reg_16(&st->adis, reg, bias);
case IIO_ANGL_VEL:
case IIO_ACCEL:
return adis_write_reg_32(&st->adis, reg, bias);
default:
break;
}
return -EINVAL;
}
static int adis16480_get_calibbias(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, int *bias)
{
unsigned int reg = adis16480_calibbias_regs[chan->scan_index];
struct adis16480 *st = iio_priv(indio_dev);
uint16_t val16;
uint32_t val32;
int ret;
switch (chan->type) {
case IIO_MAGN:
case IIO_PRESSURE:
ret = adis_read_reg_16(&st->adis, reg, &val16);
*bias = sign_extend32(val16, 15);
break;
case IIO_ANGL_VEL:
case IIO_ACCEL:
ret = adis_read_reg_32(&st->adis, reg, &val32);
*bias = sign_extend32(val32, 31);
break;
default:
ret = -EINVAL;
}
if (ret < 0)
return ret;
return IIO_VAL_INT;
}
static int adis16480_set_calibscale(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, int scale)
{
unsigned int reg = adis16480_calibscale_regs[chan->scan_index];
struct adis16480 *st = iio_priv(indio_dev);
if (scale < -0x8000 || scale >= 0x8000)
return -EINVAL;
return adis_write_reg_16(&st->adis, reg, scale);
}
static int adis16480_get_calibscale(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, int *scale)
{
unsigned int reg = adis16480_calibscale_regs[chan->scan_index];
struct adis16480 *st = iio_priv(indio_dev);
uint16_t val16;
int ret;
ret = adis_read_reg_16(&st->adis, reg, &val16);
if (ret < 0)
return ret;
*scale = sign_extend32(val16, 15);
return IIO_VAL_INT;
}
static int adis16480_get_filter_freq(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, int *freq)
{
struct adis16480 *st = iio_priv(indio_dev);
unsigned int enable_mask, offset, reg;
uint16_t val;
int ret;
reg = ad16480_filter_data[chan->scan_index][0];
offset = ad16480_filter_data[chan->scan_index][1];
enable_mask = BIT(offset + 2);
ret = adis_read_reg_16(&st->adis, reg, &val);
if (ret < 0)
return ret;
if (!(val & enable_mask))
*freq = 0;
else
*freq = adis16480_def_filter_freqs[(val >> offset) & 0x3];
return IIO_VAL_INT;
}
static int adis16480_set_filter_freq(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned int freq)
{
struct adis16480 *st = iio_priv(indio_dev);
unsigned int enable_mask, offset, reg;
unsigned int diff, best_diff;
unsigned int i, best_freq;
uint16_t val;
int ret;
reg = ad16480_filter_data[chan->scan_index][0];
offset = ad16480_filter_data[chan->scan_index][1];
enable_mask = BIT(offset + 2);
ret = adis_read_reg_16(&st->adis, reg, &val);
if (ret < 0)
return ret;
if (freq == 0) {
val &= ~enable_mask;
} else {
best_freq = 0;
best_diff = 310;
for (i = 0; i < ARRAY_SIZE(adis16480_def_filter_freqs); i++) {
if (adis16480_def_filter_freqs[i] >= freq) {
diff = adis16480_def_filter_freqs[i] - freq;
if (diff < best_diff) {
best_diff = diff;
best_freq = i;
}
}
}
val &= ~(0x3 << offset);
val |= best_freq << offset;
val |= enable_mask;
}
return adis_write_reg_16(&st->adis, reg, val);
}
static int adis16480_read_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, int *val, int *val2, long info)
{
struct adis16480 *st = iio_priv(indio_dev);
switch (info) {
case IIO_CHAN_INFO_RAW:
return adis_single_conversion(indio_dev, chan, 0, val);
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_ANGL_VEL:
*val = st->chip_info->gyro_max_scale;
*val2 = st->chip_info->gyro_max_val;
return IIO_VAL_FRACTIONAL;
case IIO_ACCEL:
*val = st->chip_info->accel_max_scale;
*val2 = st->chip_info->accel_max_val;
return IIO_VAL_FRACTIONAL;
case IIO_MAGN:
*val = 0;
*val2 = 100;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = 5;
*val2 = 650000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_PRESSURE:
*val = 0;
*val2 = 4000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
*val = 4425;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBBIAS:
return adis16480_get_calibbias(indio_dev, chan, val);
case IIO_CHAN_INFO_CALIBSCALE:
return adis16480_get_calibscale(indio_dev, chan, val);
case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
return adis16480_get_filter_freq(indio_dev, chan, val);
case IIO_CHAN_INFO_SAMP_FREQ:
return adis16480_get_freq(indio_dev, val, val2);
default:
return -EINVAL;
}
}
static int adis16480_write_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, int val, int val2, long info)
{
switch (info) {
case IIO_CHAN_INFO_CALIBBIAS:
return adis16480_set_calibbias(indio_dev, chan, val);
case IIO_CHAN_INFO_CALIBSCALE:
return adis16480_set_calibscale(indio_dev, chan, val);
case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
return adis16480_set_filter_freq(indio_dev, chan, val);
case IIO_CHAN_INFO_SAMP_FREQ:
return adis16480_set_freq(indio_dev, val, val2);
default:
return -EINVAL;
}
}
static int adis16480_stop_device(struct iio_dev *indio_dev)
{
struct adis16480 *st = iio_priv(indio_dev);
int ret;
ret = adis_write_reg_16(&st->adis, ADIS16480_REG_SLP_CNT, BIT(9));
if (ret)
dev_err(&indio_dev->dev,
"Could not power down device: %d\n", ret);
return ret;
}
static int adis16480_enable_irq(struct adis *adis, bool enable)
{
return adis_write_reg_16(adis, ADIS16480_REG_FNCTIO_CTRL,
enable ? BIT(3) : 0);
}
static int adis16480_initial_setup(struct iio_dev *indio_dev)
{
struct adis16480 *st = iio_priv(indio_dev);
uint16_t prod_id;
unsigned int device_id;
int ret;
adis_reset(&st->adis);
msleep(70);
ret = adis_write_reg_16(&st->adis, ADIS16480_REG_GLOB_CMD, BIT(1));
if (ret)
return ret;
msleep(30);
ret = adis_check_status(&st->adis);
if (ret)
return ret;
ret = adis_read_reg_16(&st->adis, ADIS16480_REG_PROD_ID, &prod_id);
if (ret)
return ret;
ret = sscanf(indio_dev->name, "adis%u\n", &device_id);
if (ret != 1)
return -EINVAL;
if (prod_id != device_id)
dev_warn(&indio_dev->dev, "Device ID(%u) and product ID(%u) do not match.",
device_id, prod_id);
return 0;
}
static int adis16480_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct iio_dev *indio_dev;
struct adis16480 *st;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
spi_set_drvdata(spi, indio_dev);
st = iio_priv(indio_dev);
st->chip_info = &adis16480_chip_info[id->driver_data];
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->channels = st->chip_info->channels;
indio_dev->num_channels = st->chip_info->num_channels;
indio_dev->info = &adis16480_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = adis_init(&st->adis, indio_dev, spi, &adis16480_data);
if (ret)
return ret;
ret = adis_setup_buffer_and_trigger(&st->adis, indio_dev, NULL);
if (ret)
return ret;
ret = adis16480_initial_setup(indio_dev);
if (ret)
goto error_cleanup_buffer;
ret = iio_device_register(indio_dev);
if (ret)
goto error_stop_device;
adis16480_debugfs_init(indio_dev);
return 0;
error_stop_device:
adis16480_stop_device(indio_dev);
error_cleanup_buffer:
adis_cleanup_buffer_and_trigger(&st->adis, indio_dev);
return ret;
}
static int adis16480_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct adis16480 *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
adis16480_stop_device(indio_dev);
adis_cleanup_buffer_and_trigger(&st->adis, indio_dev);
return 0;
}
