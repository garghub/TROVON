static ssize_t adis16400_show_serial_number(struct file *file,
char __user *userbuf, size_t count, loff_t *ppos)
{
struct adis16400_state *st = file->private_data;
u16 lot1, lot2, serial_number;
char buf[16];
size_t len;
int ret;
ret = adis_read_reg_16(&st->adis, ADIS16334_LOT_ID1, &lot1);
if (ret < 0)
return ret;
ret = adis_read_reg_16(&st->adis, ADIS16334_LOT_ID2, &lot2);
if (ret < 0)
return ret;
ret = adis_read_reg_16(&st->adis, ADIS16334_SERIAL_NUMBER,
&serial_number);
if (ret < 0)
return ret;
len = snprintf(buf, sizeof(buf), "%.4x-%.4x-%.4x\n", lot1, lot2,
serial_number);
return simple_read_from_buffer(userbuf, count, ppos, buf, len);
}
static int adis16400_show_product_id(void *arg, u64 *val)
{
struct adis16400_state *st = arg;
uint16_t prod_id;
int ret;
ret = adis_read_reg_16(&st->adis, ADIS16400_PRODUCT_ID, &prod_id);
if (ret < 0)
return ret;
*val = prod_id;
return 0;
}
static int adis16400_show_flash_count(void *arg, u64 *val)
{
struct adis16400_state *st = arg;
uint16_t flash_count;
int ret;
ret = adis_read_reg_16(&st->adis, ADIS16400_FLASH_CNT, &flash_count);
if (ret < 0)
return ret;
*val = flash_count;
return 0;
}
static int adis16400_debugfs_init(struct iio_dev *indio_dev)
{
struct adis16400_state *st = iio_priv(indio_dev);
if (st->variant->flags & ADIS16400_HAS_SERIAL_NUMBER)
debugfs_create_file("serial_number", 0400,
indio_dev->debugfs_dentry, st,
&adis16400_serial_number_fops);
if (st->variant->flags & ADIS16400_HAS_PROD_ID)
debugfs_create_file("product_id", 0400,
indio_dev->debugfs_dentry, st,
&adis16400_product_id_fops);
debugfs_create_file("flash_count", 0400, indio_dev->debugfs_dentry,
st, &adis16400_flash_count_fops);
return 0;
}
static int adis16400_debugfs_init(struct iio_dev *indio_dev)
{
return 0;
}
static int adis16334_get_freq(struct adis16400_state *st)
{
int ret;
uint16_t t;
ret = adis_read_reg_16(&st->adis, ADIS16400_SMPL_PRD, &t);
if (ret < 0)
return ret;
t >>= ADIS16334_RATE_DIV_SHIFT;
return 819200 >> t;
}
static int adis16334_set_freq(struct adis16400_state *st, unsigned int freq)
{
unsigned int t;
if (freq < 819200)
t = ilog2(819200 / freq);
else
t = 0;
if (t > 0x31)
t = 0x31;
t <<= ADIS16334_RATE_DIV_SHIFT;
t |= ADIS16334_RATE_INT_CLK;
return adis_write_reg_16(&st->adis, ADIS16400_SMPL_PRD, t);
}
static int adis16400_get_freq(struct adis16400_state *st)
{
int sps, ret;
uint16_t t;
ret = adis_read_reg_16(&st->adis, ADIS16400_SMPL_PRD, &t);
if (ret < 0)
return ret;
sps = (t & ADIS16400_SMPL_PRD_TIME_BASE) ? 52851 : 1638404;
sps /= (t & ADIS16400_SMPL_PRD_DIV_MASK) + 1;
return sps;
}
static int adis16400_set_freq(struct adis16400_state *st, unsigned int freq)
{
unsigned int t;
uint8_t val = 0;
t = 1638404 / freq;
if (t >= 128) {
val |= ADIS16400_SMPL_PRD_TIME_BASE;
t = 52851 / freq;
if (t >= 128)
t = 127;
} else if (t != 0) {
t--;
}
val |= t;
if (t >= 0x0A || (val & ADIS16400_SMPL_PRD_TIME_BASE))
st->adis.spi->max_speed_hz = ADIS16400_SPI_SLOW;
else
st->adis.spi->max_speed_hz = ADIS16400_SPI_FAST;
return adis_write_reg_8(&st->adis, ADIS16400_SMPL_PRD, val);
}
static int adis16400_set_filter(struct iio_dev *indio_dev, int sps, int val)
{
struct adis16400_state *st = iio_priv(indio_dev);
uint16_t val16;
int i, ret;
for (i = ARRAY_SIZE(adis16400_3db_divisors) - 1; i >= 1; i--) {
if (sps / adis16400_3db_divisors[i] >= val)
break;
}
ret = adis_read_reg_16(&st->adis, ADIS16400_SENS_AVG, &val16);
if (ret < 0)
return ret;
ret = adis_write_reg_16(&st->adis, ADIS16400_SENS_AVG,
(val16 & ~0x07) | i);
return ret;
}
static int adis16400_stop_device(struct iio_dev *indio_dev)
{
struct adis16400_state *st = iio_priv(indio_dev);
int ret;
ret = adis_write_reg_16(&st->adis, ADIS16400_SLP_CNT,
ADIS16400_SLP_CNT_POWER_OFF);
if (ret)
dev_err(&indio_dev->dev,
"problem with turning device off: SLP_CNT");
return ret;
}
static int adis16400_initial_setup(struct iio_dev *indio_dev)
{
struct adis16400_state *st = iio_priv(indio_dev);
uint16_t prod_id, smp_prd;
unsigned int device_id;
int ret;
if (st->variant->flags & ADIS16400_HAS_SLOW_MODE)
st->adis.spi->max_speed_hz = ADIS16400_SPI_SLOW;
else
st->adis.spi->max_speed_hz = ADIS16400_SPI_FAST;
st->adis.spi->mode = SPI_MODE_3;
spi_setup(st->adis.spi);
ret = adis_initial_startup(&st->adis);
if (ret)
return ret;
if (st->variant->flags & ADIS16400_HAS_PROD_ID) {
ret = adis_read_reg_16(&st->adis,
ADIS16400_PRODUCT_ID, &prod_id);
if (ret)
goto err_ret;
sscanf(indio_dev->name, "adis%u\n", &device_id);
if (prod_id != device_id)
dev_warn(&indio_dev->dev, "Device ID(%u) and product ID(%u) do not match.",
device_id, prod_id);
dev_info(&indio_dev->dev, "%s: prod_id 0x%04x at CS%d (irq %d)\n",
indio_dev->name, prod_id,
st->adis.spi->chip_select, st->adis.spi->irq);
}
if (st->variant->flags & ADIS16400_HAS_SLOW_MODE) {
ret = adis_read_reg_16(&st->adis, ADIS16400_SMPL_PRD, &smp_prd);
if (ret)
goto err_ret;
if ((smp_prd & ADIS16400_SMPL_PRD_DIV_MASK) < 0x0A) {
st->adis.spi->max_speed_hz = ADIS16400_SPI_FAST;
spi_setup(st->adis.spi);
}
}
err_ret:
return ret;
}
static int adis16400_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long info)
{
struct adis16400_state *st = iio_priv(indio_dev);
int ret, sps;
switch (info) {
case IIO_CHAN_INFO_CALIBBIAS:
mutex_lock(&indio_dev->mlock);
ret = adis_write_reg_16(&st->adis,
adis16400_addresses[chan->scan_index], val);
mutex_unlock(&indio_dev->mlock);
return ret;
case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
mutex_lock(&indio_dev->mlock);
st->filt_int = val;
sps = st->variant->get_freq(st);
if (sps < 0) {
mutex_unlock(&indio_dev->mlock);
return sps;
}
ret = adis16400_set_filter(indio_dev, sps,
val * 1000 + val2 / 1000);
mutex_unlock(&indio_dev->mlock);
return ret;
case IIO_CHAN_INFO_SAMP_FREQ:
sps = val * 1000 + val2 / 1000;
if (sps <= 0)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
ret = st->variant->set_freq(st, sps);
mutex_unlock(&indio_dev->mlock);
return ret;
default:
return -EINVAL;
}
}
static int adis16400_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long info)
{
struct adis16400_state *st = iio_priv(indio_dev);
int16_t val16;
int ret;
switch (info) {
case IIO_CHAN_INFO_RAW:
return adis_single_conversion(indio_dev, chan, 0, val);
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_ANGL_VEL:
*val = 0;
*val2 = st->variant->gyro_scale_micro;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_VOLTAGE:
*val = 0;
if (chan->channel == 0) {
*val = 2;
*val2 = 418000;
} else {
*val = 0;
*val2 = 805800;
}
return IIO_VAL_INT_PLUS_MICRO;
case IIO_ACCEL:
*val = 0;
*val2 = st->variant->accel_scale_micro;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_MAGN:
*val = 0;
*val2 = 500;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = st->variant->temp_scale_nano / 1000000;
*val2 = (st->variant->temp_scale_nano % 1000000);
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_CALIBBIAS:
mutex_lock(&indio_dev->mlock);
ret = adis_read_reg_16(&st->adis,
adis16400_addresses[chan->scan_index], &val16);
mutex_unlock(&indio_dev->mlock);
if (ret)
return ret;
val16 = sign_extend32(val16, 11);
*val = val16;
return IIO_VAL_INT;
case IIO_CHAN_INFO_OFFSET:
*val = st->variant->temp_offset;
return IIO_VAL_INT;
case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
mutex_lock(&indio_dev->mlock);
ret = adis_read_reg_16(&st->adis,
ADIS16400_SENS_AVG,
&val16);
if (ret < 0) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
ret = st->variant->get_freq(st);
if (ret >= 0) {
ret /= adis16400_3db_divisors[val16 & 0x07];
*val = ret / 1000;
*val2 = (ret % 1000) * 1000;
}
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
ret = st->variant->get_freq(st);
if (ret < 0)
return ret;
*val = ret / 1000;
*val2 = (ret % 1000) * 1000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int adis16400_probe(struct spi_device *spi)
{
struct adis16400_state *st;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->variant = &adis16400_chips[spi_get_device_id(spi)->driver_data];
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->channels = st->variant->channels;
indio_dev->num_channels = st->variant->num_channels;
indio_dev->info = &adis16400_info;
indio_dev->modes = INDIO_DIRECT_MODE;
if (!(st->variant->flags & ADIS16400_NO_BURST))
indio_dev->available_scan_masks = adis16400_burst_scan_mask;
ret = adis_init(&st->adis, indio_dev, spi, &adis16400_data);
if (ret)
return ret;
ret = adis_setup_buffer_and_trigger(&st->adis, indio_dev,
adis16400_trigger_handler);
if (ret)
return ret;
ret = adis16400_initial_setup(indio_dev);
if (ret)
goto error_cleanup_buffer;
ret = iio_device_register(indio_dev);
if (ret)
goto error_cleanup_buffer;
adis16400_debugfs_init(indio_dev);
return 0;
error_cleanup_buffer:
adis_cleanup_buffer_and_trigger(&st->adis, indio_dev);
return ret;
}
static int adis16400_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct adis16400_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
adis16400_stop_device(indio_dev);
adis_cleanup_buffer_and_trigger(&st->adis, indio_dev);
return 0;
}
