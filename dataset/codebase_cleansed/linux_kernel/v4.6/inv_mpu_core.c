int inv_mpu6050_switch_engine(struct inv_mpu6050_state *st, bool en, u32 mask)
{
unsigned int d, mgmt_1;
int result;
if (mask == INV_MPU6050_BIT_PWR_GYRO_STBY) {
result = regmap_read(st->map, st->reg->pwr_mgmt_1, &mgmt_1);
if (result)
return result;
mgmt_1 &= ~INV_MPU6050_BIT_CLK_MASK;
}
if ((mask == INV_MPU6050_BIT_PWR_GYRO_STBY) && (!en)) {
mgmt_1 |= INV_CLK_INTERNAL;
result = regmap_write(st->map, st->reg->pwr_mgmt_1, mgmt_1);
if (result)
return result;
}
result = regmap_read(st->map, st->reg->pwr_mgmt_2, &d);
if (result)
return result;
if (en)
d &= ~mask;
else
d |= mask;
result = regmap_write(st->map, st->reg->pwr_mgmt_2, d);
if (result)
return result;
if (en) {
msleep(INV_MPU6050_TEMP_UP_TIME);
if (mask == INV_MPU6050_BIT_PWR_GYRO_STBY) {
mgmt_1 |= INV_CLK_PLL;
result = regmap_write(st->map,
st->reg->pwr_mgmt_1, mgmt_1);
if (result)
return result;
}
}
return 0;
}
int inv_mpu6050_set_power_itg(struct inv_mpu6050_state *st, bool power_on)
{
int result = 0;
if (power_on) {
if (!st->powerup_count)
result = regmap_write(st->map, st->reg->pwr_mgmt_1, 0);
if (!result)
st->powerup_count++;
} else {
st->powerup_count--;
if (!st->powerup_count)
result = regmap_write(st->map, st->reg->pwr_mgmt_1,
INV_MPU6050_BIT_SLEEP);
}
if (result)
return result;
if (power_on)
usleep_range(INV_MPU6050_REG_UP_TIME_MIN,
INV_MPU6050_REG_UP_TIME_MAX);
return 0;
}
static int inv_mpu6050_init_config(struct iio_dev *indio_dev)
{
int result;
u8 d;
struct inv_mpu6050_state *st = iio_priv(indio_dev);
result = inv_mpu6050_set_power_itg(st, true);
if (result)
return result;
d = (INV_MPU6050_FSR_2000DPS << INV_MPU6050_GYRO_CONFIG_FSR_SHIFT);
result = regmap_write(st->map, st->reg->gyro_config, d);
if (result)
return result;
d = INV_MPU6050_FILTER_20HZ;
result = regmap_write(st->map, st->reg->lpf, d);
if (result)
return result;
d = INV_MPU6050_ONE_K_HZ / INV_MPU6050_INIT_FIFO_RATE - 1;
result = regmap_write(st->map, st->reg->sample_rate_div, d);
if (result)
return result;
d = (INV_MPU6050_FS_02G << INV_MPU6050_ACCL_CONFIG_FSR_SHIFT);
result = regmap_write(st->map, st->reg->accl_config, d);
if (result)
return result;
memcpy(&st->chip_config, hw_info[st->chip_type].config,
sizeof(struct inv_mpu6050_chip_config));
result = inv_mpu6050_set_power_itg(st, false);
return result;
}
static int inv_mpu6050_sensor_set(struct inv_mpu6050_state *st, int reg,
int axis, int val)
{
int ind, result;
__be16 d = cpu_to_be16(val);
ind = (axis - IIO_MOD_X) * 2;
result = regmap_bulk_write(st->map, reg + ind, (u8 *)&d, 2);
if (result)
return -EINVAL;
return 0;
}
static int inv_mpu6050_sensor_show(struct inv_mpu6050_state *st, int reg,
int axis, int *val)
{
int ind, result;
__be16 d;
ind = (axis - IIO_MOD_X) * 2;
result = regmap_bulk_read(st->map, reg + ind, (u8 *)&d, 2);
if (result)
return -EINVAL;
*val = (short)be16_to_cpup(&d);
return IIO_VAL_INT;
}
static int
inv_mpu6050_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct inv_mpu6050_state *st = iio_priv(indio_dev);
int ret = 0;
switch (mask) {
case IIO_CHAN_INFO_RAW:
{
int result;
ret = IIO_VAL_INT;
result = 0;
mutex_lock(&indio_dev->mlock);
if (!st->chip_config.enable) {
result = inv_mpu6050_set_power_itg(st, true);
if (result)
goto error_read_raw;
}
switch (chan->type) {
case IIO_ANGL_VEL:
if (!st->chip_config.gyro_fifo_enable ||
!st->chip_config.enable) {
result = inv_mpu6050_switch_engine(st, true,
INV_MPU6050_BIT_PWR_GYRO_STBY);
if (result)
goto error_read_raw;
}
ret = inv_mpu6050_sensor_show(st, st->reg->raw_gyro,
chan->channel2, val);
if (!st->chip_config.gyro_fifo_enable ||
!st->chip_config.enable) {
result = inv_mpu6050_switch_engine(st, false,
INV_MPU6050_BIT_PWR_GYRO_STBY);
if (result)
goto error_read_raw;
}
break;
case IIO_ACCEL:
if (!st->chip_config.accl_fifo_enable ||
!st->chip_config.enable) {
result = inv_mpu6050_switch_engine(st, true,
INV_MPU6050_BIT_PWR_ACCL_STBY);
if (result)
goto error_read_raw;
}
ret = inv_mpu6050_sensor_show(st, st->reg->raw_accl,
chan->channel2, val);
if (!st->chip_config.accl_fifo_enable ||
!st->chip_config.enable) {
result = inv_mpu6050_switch_engine(st, false,
INV_MPU6050_BIT_PWR_ACCL_STBY);
if (result)
goto error_read_raw;
}
break;
case IIO_TEMP:
msleep(INV_MPU6050_SENSOR_UP_TIME);
ret = inv_mpu6050_sensor_show(st, st->reg->temperature,
IIO_MOD_X, val);
break;
default:
ret = -EINVAL;
break;
}
error_read_raw:
if (!st->chip_config.enable)
result |= inv_mpu6050_set_power_itg(st, false);
mutex_unlock(&indio_dev->mlock);
if (result)
return result;
return ret;
}
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_ANGL_VEL:
*val = 0;
*val2 = gyro_scale_6050[st->chip_config.fsr];
return IIO_VAL_INT_PLUS_NANO;
case IIO_ACCEL:
*val = 0;
*val2 = accel_scale[st->chip_config.accl_fs];
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = 0;
*val2 = INV_MPU6050_TEMP_SCALE;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
switch (chan->type) {
case IIO_TEMP:
*val = INV_MPU6050_TEMP_OFFSET;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_CALIBBIAS:
switch (chan->type) {
case IIO_ANGL_VEL:
ret = inv_mpu6050_sensor_show(st, st->reg->gyro_offset,
chan->channel2, val);
return IIO_VAL_INT;
case IIO_ACCEL:
ret = inv_mpu6050_sensor_show(st, st->reg->accl_offset,
chan->channel2, val);
return IIO_VAL_INT;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static int inv_mpu6050_write_gyro_scale(struct inv_mpu6050_state *st, int val)
{
int result, i;
u8 d;
for (i = 0; i < ARRAY_SIZE(gyro_scale_6050); ++i) {
if (gyro_scale_6050[i] == val) {
d = (i << INV_MPU6050_GYRO_CONFIG_FSR_SHIFT);
result = regmap_write(st->map, st->reg->gyro_config, d);
if (result)
return result;
st->chip_config.fsr = i;
return 0;
}
}
return -EINVAL;
}
static int inv_write_raw_get_fmt(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, long mask)
{
switch (mask) {
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_ANGL_VEL:
return IIO_VAL_INT_PLUS_NANO;
default:
return IIO_VAL_INT_PLUS_MICRO;
}
default:
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int inv_mpu6050_write_accel_scale(struct inv_mpu6050_state *st, int val)
{
int result, i;
u8 d;
for (i = 0; i < ARRAY_SIZE(accel_scale); ++i) {
if (accel_scale[i] == val) {
d = (i << INV_MPU6050_ACCL_CONFIG_FSR_SHIFT);
result = regmap_write(st->map, st->reg->accl_config, d);
if (result)
return result;
st->chip_config.accl_fs = i;
return 0;
}
}
return -EINVAL;
}
static int inv_mpu6050_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct inv_mpu6050_state *st = iio_priv(indio_dev);
int result;
mutex_lock(&indio_dev->mlock);
if (st->chip_config.enable) {
result = -EBUSY;
goto error_write_raw;
}
result = inv_mpu6050_set_power_itg(st, true);
if (result)
goto error_write_raw;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_ANGL_VEL:
result = inv_mpu6050_write_gyro_scale(st, val2);
break;
case IIO_ACCEL:
result = inv_mpu6050_write_accel_scale(st, val2);
break;
default:
result = -EINVAL;
break;
}
break;
case IIO_CHAN_INFO_CALIBBIAS:
switch (chan->type) {
case IIO_ANGL_VEL:
result = inv_mpu6050_sensor_set(st,
st->reg->gyro_offset,
chan->channel2, val);
break;
case IIO_ACCEL:
result = inv_mpu6050_sensor_set(st,
st->reg->accl_offset,
chan->channel2, val);
break;
default:
result = -EINVAL;
}
default:
result = -EINVAL;
break;
}
error_write_raw:
result |= inv_mpu6050_set_power_itg(st, false);
mutex_unlock(&indio_dev->mlock);
return result;
}
static int inv_mpu6050_set_lpf(struct inv_mpu6050_state *st, int rate)
{
const int hz[] = {188, 98, 42, 20, 10, 5};
const int d[] = {INV_MPU6050_FILTER_188HZ, INV_MPU6050_FILTER_98HZ,
INV_MPU6050_FILTER_42HZ, INV_MPU6050_FILTER_20HZ,
INV_MPU6050_FILTER_10HZ, INV_MPU6050_FILTER_5HZ};
int i, h, result;
u8 data;
h = (rate >> 1);
i = 0;
while ((h < hz[i]) && (i < ARRAY_SIZE(d) - 1))
i++;
data = d[i];
result = regmap_write(st->map, st->reg->lpf, data);
if (result)
return result;
st->chip_config.lpf = data;
return 0;
}
static ssize_t
inv_mpu6050_fifo_rate_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
s32 fifo_rate;
u8 d;
int result;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct inv_mpu6050_state *st = iio_priv(indio_dev);
if (kstrtoint(buf, 10, &fifo_rate))
return -EINVAL;
if (fifo_rate < INV_MPU6050_MIN_FIFO_RATE ||
fifo_rate > INV_MPU6050_MAX_FIFO_RATE)
return -EINVAL;
if (fifo_rate == st->chip_config.fifo_rate)
return count;
mutex_lock(&indio_dev->mlock);
if (st->chip_config.enable) {
result = -EBUSY;
goto fifo_rate_fail;
}
result = inv_mpu6050_set_power_itg(st, true);
if (result)
goto fifo_rate_fail;
d = INV_MPU6050_ONE_K_HZ / fifo_rate - 1;
result = regmap_write(st->map, st->reg->sample_rate_div, d);
if (result)
goto fifo_rate_fail;
st->chip_config.fifo_rate = fifo_rate;
result = inv_mpu6050_set_lpf(st, fifo_rate);
if (result)
goto fifo_rate_fail;
fifo_rate_fail:
result |= inv_mpu6050_set_power_itg(st, false);
mutex_unlock(&indio_dev->mlock);
if (result)
return result;
return count;
}
static ssize_t
inv_fifo_rate_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct inv_mpu6050_state *st = iio_priv(dev_to_iio_dev(dev));
return sprintf(buf, "%d\n", st->chip_config.fifo_rate);
}
static ssize_t inv_attr_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct inv_mpu6050_state *st = iio_priv(dev_to_iio_dev(dev));
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
s8 *m;
switch (this_attr->address) {
case ATTR_GYRO_MATRIX:
case ATTR_ACCL_MATRIX:
m = st->plat_data.orientation;
return sprintf(buf, "%d, %d, %d; %d, %d, %d; %d, %d, %d\n",
m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8]);
default:
return -EINVAL;
}
}
static int inv_mpu6050_validate_trigger(struct iio_dev *indio_dev,
struct iio_trigger *trig)
{
struct inv_mpu6050_state *st = iio_priv(indio_dev);
if (st->trig != trig)
return -EINVAL;
return 0;
}
static int inv_check_and_setup_chip(struct inv_mpu6050_state *st)
{
int result;
st->hw = &hw_info[st->chip_type];
st->reg = hw_info[st->chip_type].reg;
result = regmap_write(st->map, st->reg->pwr_mgmt_1,
INV_MPU6050_BIT_H_RESET);
if (result)
return result;
msleep(INV_MPU6050_POWER_UP_TIME);
result = inv_mpu6050_set_power_itg(st, false);
if (result)
return result;
result = inv_mpu6050_set_power_itg(st, true);
if (result)
return result;
result = inv_mpu6050_switch_engine(st, false,
INV_MPU6050_BIT_PWR_ACCL_STBY);
if (result)
return result;
result = inv_mpu6050_switch_engine(st, false,
INV_MPU6050_BIT_PWR_GYRO_STBY);
if (result)
return result;
return 0;
}
int inv_mpu_core_probe(struct regmap *regmap, int irq, const char *name,
int (*inv_mpu_bus_setup)(struct iio_dev *), int chip_type)
{
struct inv_mpu6050_state *st;
struct iio_dev *indio_dev;
struct inv_mpu6050_platform_data *pdata;
struct device *dev = regmap_get_device(regmap);
int result;
indio_dev = devm_iio_device_alloc(dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
st->chip_type = chip_type;
st->powerup_count = 0;
st->irq = irq;
st->map = regmap;
pdata = dev_get_platdata(dev);
if (pdata)
st->plat_data = *pdata;
result = inv_check_and_setup_chip(st);
if (result)
return result;
if (inv_mpu_bus_setup)
inv_mpu_bus_setup(indio_dev);
result = inv_mpu6050_init_config(indio_dev);
if (result) {
dev_err(dev, "Could not initialize device.\n");
return result;
}
dev_set_drvdata(dev, indio_dev);
indio_dev->dev.parent = dev;
if (name)
indio_dev->name = name;
else
indio_dev->name = dev_name(dev);
indio_dev->channels = inv_mpu_channels;
indio_dev->num_channels = ARRAY_SIZE(inv_mpu_channels);
indio_dev->info = &mpu_info;
indio_dev->modes = INDIO_BUFFER_TRIGGERED;
result = iio_triggered_buffer_setup(indio_dev,
inv_mpu6050_irq_handler,
inv_mpu6050_read_fifo,
NULL);
if (result) {
dev_err(dev, "configure buffer fail %d\n", result);
return result;
}
result = inv_mpu6050_probe_trigger(indio_dev);
if (result) {
dev_err(dev, "trigger probe fail %d\n", result);
goto out_unreg_ring;
}
INIT_KFIFO(st->timestamps);
spin_lock_init(&st->time_stamp_lock);
result = iio_device_register(indio_dev);
if (result) {
dev_err(dev, "IIO register fail %d\n", result);
goto out_remove_trigger;
}
return 0;
out_remove_trigger:
inv_mpu6050_remove_trigger(st);
out_unreg_ring:
iio_triggered_buffer_cleanup(indio_dev);
return result;
}
int inv_mpu_core_remove(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
iio_device_unregister(indio_dev);
inv_mpu6050_remove_trigger(iio_priv(indio_dev));
iio_triggered_buffer_cleanup(indio_dev);
return 0;
}
static int inv_mpu_resume(struct device *dev)
{
return inv_mpu6050_set_power_itg(iio_priv(dev_get_drvdata(dev)), true);
}
static int inv_mpu_suspend(struct device *dev)
{
return inv_mpu6050_set_power_itg(iio_priv(dev_get_drvdata(dev)), false);
}
