static bool ms5611_prom_is_valid(u16 *prom, size_t len)
{
int i, j;
uint16_t crc = 0, crc_orig = prom[7] & 0x000F;
prom[7] &= 0xFF00;
for (i = 0; i < len * 2; i++) {
if (i % 2 == 1)
crc ^= prom[i >> 1] & 0x00FF;
else
crc ^= prom[i >> 1] >> 8;
for (j = 0; j < 8; j++) {
if (crc & 0x8000)
crc = (crc << 1) ^ 0x3000;
else
crc <<= 1;
}
}
crc = (crc >> 12) & 0x000F;
return crc_orig != 0x0000 && crc == crc_orig;
}
static int ms5611_read_prom(struct iio_dev *indio_dev)
{
int ret, i;
struct ms5611_state *st = iio_priv(indio_dev);
for (i = 0; i < MS5611_PROM_WORDS_NB; i++) {
ret = st->read_prom_word(&indio_dev->dev,
i, &st->chip_info->prom[i]);
if (ret < 0) {
dev_err(&indio_dev->dev,
"failed to read prom at %d\n", i);
return ret;
}
}
if (!ms5611_prom_is_valid(st->chip_info->prom, MS5611_PROM_WORDS_NB)) {
dev_err(&indio_dev->dev, "PROM integrity check failed\n");
return -ENODEV;
}
return 0;
}
static int ms5611_read_temp_and_pressure(struct iio_dev *indio_dev,
s32 *temp, s32 *pressure)
{
int ret;
struct ms5611_state *st = iio_priv(indio_dev);
ret = st->read_adc_temp_and_pressure(&indio_dev->dev, temp, pressure);
if (ret < 0) {
dev_err(&indio_dev->dev,
"failed to read temperature and pressure\n");
return ret;
}
return st->chip_info->temp_and_pressure_compensate(st->chip_info,
temp, pressure);
}
static int ms5611_temp_and_pressure_compensate(struct ms5611_chip_info *chip_info,
s32 *temp, s32 *pressure)
{
s32 t = *temp, p = *pressure;
s64 off, sens, dt;
dt = t - (chip_info->prom[5] << 8);
off = ((s64)chip_info->prom[2] << 16) + ((chip_info->prom[4] * dt) >> 7);
sens = ((s64)chip_info->prom[1] << 15) + ((chip_info->prom[3] * dt) >> 8);
t = 2000 + ((chip_info->prom[6] * dt) >> 23);
if (t < 2000) {
s64 off2, sens2, t2;
t2 = (dt * dt) >> 31;
off2 = (5 * (t - 2000) * (t - 2000)) >> 1;
sens2 = off2 >> 1;
if (t < -1500) {
s64 tmp = (t + 1500) * (t + 1500);
off2 += 7 * tmp;
sens2 += (11 * tmp) >> 1;
}
t -= t2;
off -= off2;
sens -= sens2;
}
*temp = t;
*pressure = (((p * sens) >> 21) - off) >> 15;
return 0;
}
static int ms5607_temp_and_pressure_compensate(struct ms5611_chip_info *chip_info,
s32 *temp, s32 *pressure)
{
s32 t = *temp, p = *pressure;
s64 off, sens, dt;
dt = t - (chip_info->prom[5] << 8);
off = ((s64)chip_info->prom[2] << 17) + ((chip_info->prom[4] * dt) >> 6);
sens = ((s64)chip_info->prom[1] << 16) + ((chip_info->prom[3] * dt) >> 7);
t = 2000 + ((chip_info->prom[6] * dt) >> 23);
if (t < 2000) {
s64 off2, sens2, t2, tmp;
t2 = (dt * dt) >> 31;
tmp = (t - 2000) * (t - 2000);
off2 = (61 * tmp) >> 4;
sens2 = tmp << 1;
if (t < -1500) {
tmp = (t + 1500) * (t + 1500);
off2 += 15 * tmp;
sens2 += 8 * tmp;
}
t -= t2;
off -= off2;
sens -= sens2;
}
*temp = t;
*pressure = (((p * sens) >> 21) - off) >> 15;
return 0;
}
static int ms5611_reset(struct iio_dev *indio_dev)
{
int ret;
struct ms5611_state *st = iio_priv(indio_dev);
ret = st->reset(&indio_dev->dev);
if (ret < 0) {
dev_err(&indio_dev->dev, "failed to reset device\n");
return ret;
}
usleep_range(3000, 4000);
return 0;
}
static irqreturn_t ms5611_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ms5611_state *st = iio_priv(indio_dev);
s32 buf[4];
int ret;
mutex_lock(&st->lock);
ret = ms5611_read_temp_and_pressure(indio_dev, &buf[1], &buf[0]);
mutex_unlock(&st->lock);
if (ret < 0)
goto err;
iio_push_to_buffers_with_timestamp(indio_dev, buf,
iio_get_time_ns(indio_dev));
err:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int ms5611_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret;
s32 temp, pressure;
struct ms5611_state *st = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
mutex_lock(&st->lock);
ret = ms5611_read_temp_and_pressure(indio_dev,
&temp, &pressure);
mutex_unlock(&st->lock);
if (ret < 0)
return ret;
switch (chan->type) {
case IIO_TEMP:
*val = temp * 10;
return IIO_VAL_INT;
case IIO_PRESSURE:
*val = pressure / 1000;
*val2 = (pressure % 1000) * 1000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_TEMP:
*val = 10;
return IIO_VAL_INT;
case IIO_PRESSURE:
*val = 0;
*val2 = 1000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
if (chan->type != IIO_TEMP && chan->type != IIO_PRESSURE)
break;
mutex_lock(&st->lock);
if (chan->type == IIO_TEMP)
*val = (int)st->temp_osr->rate;
else
*val = (int)st->pressure_osr->rate;
mutex_unlock(&st->lock);
return IIO_VAL_INT;
}
return -EINVAL;
}
static const struct ms5611_osr *ms5611_find_osr(int rate,
const struct ms5611_osr *osr,
size_t count)
{
unsigned int r;
for (r = 0; r < count; r++)
if ((unsigned short)rate == osr[r].rate)
break;
if (r >= count)
return NULL;
return &osr[r];
}
static int ms5611_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct ms5611_state *st = iio_priv(indio_dev);
const struct ms5611_osr *osr = NULL;
if (mask != IIO_CHAN_INFO_OVERSAMPLING_RATIO)
return -EINVAL;
if (chan->type == IIO_TEMP)
osr = ms5611_find_osr(val, ms5611_avail_temp_osr,
ARRAY_SIZE(ms5611_avail_temp_osr));
else if (chan->type == IIO_PRESSURE)
osr = ms5611_find_osr(val, ms5611_avail_pressure_osr,
ARRAY_SIZE(ms5611_avail_pressure_osr));
if (!osr)
return -EINVAL;
mutex_lock(&st->lock);
if (iio_buffer_enabled(indio_dev)) {
mutex_unlock(&st->lock);
return -EBUSY;
}
if (chan->type == IIO_TEMP)
st->temp_osr = osr;
else
st->pressure_osr = osr;
mutex_unlock(&st->lock);
return 0;
}
static int ms5611_init(struct iio_dev *indio_dev)
{
int ret;
struct ms5611_state *st = iio_priv(indio_dev);
st->vdd = devm_regulator_get(indio_dev->dev.parent, "vdd");
if (!IS_ERR(st->vdd)) {
ret = regulator_enable(st->vdd);
if (ret) {
dev_err(indio_dev->dev.parent,
"failed to enable Vdd supply: %d\n", ret);
return ret;
}
} else {
ret = PTR_ERR(st->vdd);
if (ret != -ENODEV)
return ret;
}
ret = ms5611_reset(indio_dev);
if (ret < 0)
goto err_regulator_disable;
ret = ms5611_read_prom(indio_dev);
if (ret < 0)
goto err_regulator_disable;
return 0;
err_regulator_disable:
regulator_disable(st->vdd);
return ret;
}
static void ms5611_fini(const struct iio_dev *indio_dev)
{
const struct ms5611_state *st = iio_priv(indio_dev);
regulator_disable(st->vdd);
}
int ms5611_probe(struct iio_dev *indio_dev, struct device *dev,
const char *name, int type)
{
int ret;
struct ms5611_state *st = iio_priv(indio_dev);
mutex_init(&st->lock);
st->chip_info = &chip_info_tbl[type];
st->temp_osr =
&ms5611_avail_temp_osr[ARRAY_SIZE(ms5611_avail_temp_osr) - 1];
st->pressure_osr =
&ms5611_avail_pressure_osr[ARRAY_SIZE(ms5611_avail_pressure_osr)
- 1];
indio_dev->dev.parent = dev;
indio_dev->name = name;
indio_dev->info = &ms5611_info;
indio_dev->channels = ms5611_channels;
indio_dev->num_channels = ARRAY_SIZE(ms5611_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->available_scan_masks = ms5611_scan_masks;
ret = ms5611_init(indio_dev);
if (ret < 0)
return ret;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
ms5611_trigger_handler, NULL);
if (ret < 0) {
dev_err(dev, "iio triggered buffer setup failed\n");
goto err_fini;
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(dev, "unable to register iio device\n");
goto err_buffer_cleanup;
}
return 0;
err_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
err_fini:
ms5611_fini(indio_dev);
return ret;
}
int ms5611_remove(struct iio_dev *indio_dev)
{
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
ms5611_fini(indio_dev);
return 0;
}
