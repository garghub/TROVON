static unsigned int mpu3050_get_freq(struct mpu3050 *mpu3050)
{
unsigned int freq;
if (mpu3050->lpf == MPU3050_DLPF_CFG_256HZ_NOLPF2)
freq = 8000;
else
freq = 1000;
freq /= (mpu3050->divisor + 1);
return freq;
}
static int mpu3050_start_sampling(struct mpu3050 *mpu3050)
{
__be16 raw_val[3];
int ret;
int i;
ret = regmap_update_bits(mpu3050->map, MPU3050_PWR_MGM,
MPU3050_PWR_MGM_RESET, MPU3050_PWR_MGM_RESET);
if (ret)
return ret;
ret = regmap_update_bits(mpu3050->map, MPU3050_PWR_MGM,
MPU3050_PWR_MGM_CLKSEL_MASK,
MPU3050_PWR_MGM_PLL_Z);
if (ret)
return ret;
for (i = 0; i < 3; i++)
raw_val[i] = cpu_to_be16(mpu3050->calibration[i]);
ret = regmap_bulk_write(mpu3050->map, MPU3050_X_OFFS_USR_H, raw_val,
sizeof(raw_val));
if (ret)
return ret;
ret = regmap_write(mpu3050->map, MPU3050_DLPF_FS_SYNC,
MPU3050_EXT_SYNC_NONE << MPU3050_EXT_SYNC_SHIFT |
mpu3050->fullscale << MPU3050_FS_SHIFT |
mpu3050->lpf << MPU3050_DLPF_CFG_SHIFT);
if (ret)
return ret;
ret = regmap_write(mpu3050->map, MPU3050_SMPLRT_DIV, mpu3050->divisor);
if (ret)
return ret;
msleep(50 + 1000 / mpu3050_get_freq(mpu3050));
return 0;
}
static int mpu3050_set_8khz_samplerate(struct mpu3050 *mpu3050)
{
int ret;
u8 divisor;
enum mpu3050_lpf lpf;
lpf = mpu3050->lpf;
divisor = mpu3050->divisor;
mpu3050->lpf = LPF_256_HZ_NOLPF;
mpu3050->divisor = 0;
ret = mpu3050_start_sampling(mpu3050);
mpu3050->lpf = lpf;
mpu3050->divisor = divisor;
return ret;
}
static int mpu3050_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct mpu3050 *mpu3050 = iio_priv(indio_dev);
int ret;
__be16 raw_val;
switch (mask) {
case IIO_CHAN_INFO_OFFSET:
switch (chan->type) {
case IIO_TEMP:
*val = 23000;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_CALIBBIAS:
switch (chan->type) {
case IIO_ANGL_VEL:
*val = mpu3050->calibration[chan->scan_index-1];
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SAMP_FREQ:
*val = mpu3050_get_freq(mpu3050);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_TEMP:
*val = 1000;
*val2 = 280;
return IIO_VAL_FRACTIONAL;
case IIO_ANGL_VEL:
*val = mpu3050_fs_precision[mpu3050->fullscale] * 2;
*val2 = U16_MAX;
return IIO_VAL_FRACTIONAL;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_RAW:
pm_runtime_get_sync(mpu3050->dev);
mutex_lock(&mpu3050->lock);
ret = mpu3050_set_8khz_samplerate(mpu3050);
if (ret)
goto out_read_raw_unlock;
switch (chan->type) {
case IIO_TEMP:
ret = regmap_bulk_read(mpu3050->map, MPU3050_TEMP_H,
&raw_val, sizeof(raw_val));
if (ret) {
dev_err(mpu3050->dev,
"error reading temperature\n");
goto out_read_raw_unlock;
}
*val = be16_to_cpu(raw_val);
ret = IIO_VAL_INT;
goto out_read_raw_unlock;
case IIO_ANGL_VEL:
ret = regmap_bulk_read(mpu3050->map,
MPU3050_AXIS_REGS(chan->scan_index-1),
&raw_val,
sizeof(raw_val));
if (ret) {
dev_err(mpu3050->dev,
"error reading axis data\n");
goto out_read_raw_unlock;
}
*val = be16_to_cpu(raw_val);
ret = IIO_VAL_INT;
goto out_read_raw_unlock;
default:
ret = -EINVAL;
goto out_read_raw_unlock;
}
default:
break;
}
return -EINVAL;
out_read_raw_unlock:
mutex_unlock(&mpu3050->lock);
pm_runtime_mark_last_busy(mpu3050->dev);
pm_runtime_put_autosuspend(mpu3050->dev);
return ret;
}
static int mpu3050_write_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
int val, int val2, long mask)
{
struct mpu3050 *mpu3050 = iio_priv(indio_dev);
unsigned int fs250 =
DIV_ROUND_CLOSEST(mpu3050_fs_precision[0] * 1000000 * 2,
U16_MAX);
unsigned int fs500 =
DIV_ROUND_CLOSEST(mpu3050_fs_precision[1] * 1000000 * 2,
U16_MAX);
unsigned int fs1000 =
DIV_ROUND_CLOSEST(mpu3050_fs_precision[2] * 1000000 * 2,
U16_MAX);
unsigned int fs2000 =
DIV_ROUND_CLOSEST(mpu3050_fs_precision[3] * 1000000 * 2,
U16_MAX);
switch (mask) {
case IIO_CHAN_INFO_CALIBBIAS:
if (chan->type != IIO_ANGL_VEL)
return -EINVAL;
mpu3050->calibration[chan->scan_index-1] = val;
return 0;
case IIO_CHAN_INFO_SAMP_FREQ:
if (val < 4 || val > 8000)
return -EINVAL;
if (val > 1000) {
mpu3050->lpf = LPF_256_HZ_NOLPF;
mpu3050->divisor = DIV_ROUND_CLOSEST(8000, val) - 1;
return 0;
}
mpu3050->lpf = LPF_188_HZ;
mpu3050->divisor = DIV_ROUND_CLOSEST(1000, val) - 1;
return 0;
case IIO_CHAN_INFO_SCALE:
if (chan->type != IIO_ANGL_VEL)
return -EINVAL;
if (val != 0) {
mpu3050->fullscale = FS_2000_DPS;
return 0;
}
if (val2 <= fs250 ||
val2 < ((fs500 + fs250) / 2))
mpu3050->fullscale = FS_250_DPS;
else if (val2 <= fs500 ||
val2 < ((fs1000 + fs500) / 2))
mpu3050->fullscale = FS_500_DPS;
else if (val2 <= fs1000 ||
val2 < ((fs2000 + fs1000) / 2))
mpu3050->fullscale = FS_1000_DPS;
else
mpu3050->fullscale = FS_2000_DPS;
return 0;
default:
break;
}
return -EINVAL;
}
static irqreturn_t mpu3050_trigger_handler(int irq, void *p)
{
const struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct mpu3050 *mpu3050 = iio_priv(indio_dev);
int ret;
__be16 hw_values[8];
s64 timestamp;
unsigned int datums_from_fifo = 0;
if (iio_trigger_using_own(indio_dev))
timestamp = mpu3050->hw_timestamp;
else
timestamp = iio_get_time_ns(indio_dev);
mutex_lock(&mpu3050->lock);
if (mpu3050->hw_irq_trigger) {
__be16 raw_fifocnt;
u16 fifocnt;
unsigned int bytes_per_datum = 8;
bool fifo_overflow = false;
ret = regmap_bulk_read(mpu3050->map,
MPU3050_FIFO_COUNT_H,
&raw_fifocnt,
sizeof(raw_fifocnt));
if (ret)
goto out_trigger_unlock;
fifocnt = be16_to_cpu(raw_fifocnt);
if (fifocnt == 512) {
dev_info(mpu3050->dev,
"FIFO overflow! Emptying and resetting FIFO\n");
fifo_overflow = true;
ret = regmap_update_bits(mpu3050->map,
MPU3050_USR_CTRL,
MPU3050_USR_CTRL_FIFO_EN |
MPU3050_USR_CTRL_FIFO_RST,
MPU3050_USR_CTRL_FIFO_EN |
MPU3050_USR_CTRL_FIFO_RST);
if (ret) {
dev_info(mpu3050->dev, "error resetting FIFO\n");
goto out_trigger_unlock;
}
mpu3050->pending_fifo_footer = false;
}
if (fifocnt)
dev_dbg(mpu3050->dev,
"%d bytes in the FIFO\n",
fifocnt);
while (!fifo_overflow && fifocnt > bytes_per_datum) {
unsigned int toread;
unsigned int offset;
__be16 fifo_values[5];
if (mpu3050->pending_fifo_footer) {
toread = bytes_per_datum + 2;
offset = 0;
} else {
toread = bytes_per_datum;
offset = 1;
fifo_values[0] = 0xAAAA;
}
ret = regmap_bulk_read(mpu3050->map,
MPU3050_FIFO_R,
&fifo_values[offset],
toread);
dev_dbg(mpu3050->dev,
"%04x %04x %04x %04x %04x\n",
fifo_values[0],
fifo_values[1],
fifo_values[2],
fifo_values[3],
fifo_values[4]);
iio_push_to_buffers_with_timestamp(indio_dev,
&fifo_values[1],
timestamp);
fifocnt -= toread;
datums_from_fifo++;
mpu3050->pending_fifo_footer = true;
if (fifocnt < bytes_per_datum) {
ret = regmap_bulk_read(mpu3050->map,
MPU3050_FIFO_COUNT_H,
&raw_fifocnt,
sizeof(raw_fifocnt));
if (ret)
goto out_trigger_unlock;
fifocnt = be16_to_cpu(raw_fifocnt);
}
if (fifocnt < bytes_per_datum)
dev_dbg(mpu3050->dev,
"%d bytes left in the FIFO\n",
fifocnt);
timestamp = 0;
}
}
if (datums_from_fifo) {
dev_dbg(mpu3050->dev,
"read %d datums from the FIFO\n",
datums_from_fifo);
goto out_trigger_unlock;
}
ret = regmap_bulk_read(mpu3050->map, MPU3050_TEMP_H, &hw_values,
sizeof(hw_values));
if (ret) {
dev_err(mpu3050->dev,
"error reading axis data\n");
goto out_trigger_unlock;
}
iio_push_to_buffers_with_timestamp(indio_dev, hw_values, timestamp);
out_trigger_unlock:
mutex_unlock(&mpu3050->lock);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int mpu3050_buffer_preenable(struct iio_dev *indio_dev)
{
struct mpu3050 *mpu3050 = iio_priv(indio_dev);
pm_runtime_get_sync(mpu3050->dev);
if (!mpu3050->hw_irq_trigger)
return mpu3050_set_8khz_samplerate(mpu3050);
return 0;
}
static int mpu3050_buffer_postdisable(struct iio_dev *indio_dev)
{
struct mpu3050 *mpu3050 = iio_priv(indio_dev);
pm_runtime_mark_last_busy(mpu3050->dev);
pm_runtime_put_autosuspend(mpu3050->dev);
return 0;
}
static const struct iio_mount_matrix *
mpu3050_get_mount_matrix(const struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct mpu3050 *mpu3050 = iio_priv(indio_dev);
return &mpu3050->orientation;
}
static int mpu3050_read_mem(struct mpu3050 *mpu3050,
u8 bank,
u8 addr,
u8 len,
u8 *buf)
{
int ret;
ret = regmap_write(mpu3050->map,
MPU3050_BANK_SEL,
bank);
if (ret)
return ret;
ret = regmap_write(mpu3050->map,
MPU3050_MEM_START_ADDR,
addr);
if (ret)
return ret;
return regmap_bulk_read(mpu3050->map,
MPU3050_MEM_R_W,
buf,
len);
}
static int mpu3050_hw_init(struct mpu3050 *mpu3050)
{
int ret;
u8 otp[8];
ret = regmap_update_bits(mpu3050->map,
MPU3050_PWR_MGM,
MPU3050_PWR_MGM_RESET,
MPU3050_PWR_MGM_RESET);
if (ret)
return ret;
ret = regmap_update_bits(mpu3050->map,
MPU3050_PWR_MGM,
MPU3050_PWR_MGM_CLKSEL_MASK,
MPU3050_PWR_MGM_PLL_Z);
if (ret)
return ret;
ret = regmap_write(mpu3050->map,
MPU3050_INT_CFG,
0);
if (ret)
return ret;
ret = mpu3050_read_mem(mpu3050,
(MPU3050_MEM_PRFTCH |
MPU3050_MEM_USER_BANK |
MPU3050_MEM_OTP_BANK_0),
0,
sizeof(otp),
otp);
if (ret)
return ret;
add_device_randomness(otp, sizeof(otp));
dev_info(mpu3050->dev,
"die ID: %04X, wafer ID: %02X, A lot ID: %04X, "
"W lot ID: %03X, WP ID: %01X, rev ID: %02X\n",
(otp[1] << 8 | otp[0]) & 0x1fff,
((otp[2] << 8 | otp[1]) & 0x03e0) >> 5,
((otp[4] << 16 | otp[3] << 8 | otp[2]) & 0x3fffc) >> 2,
((otp[5] << 8 | otp[4]) & 0x3ffc) >> 2,
((otp[6] << 8 | otp[5]) & 0x0380) >> 7,
otp[6] >> 2);
return 0;
}
static int mpu3050_power_up(struct mpu3050 *mpu3050)
{
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(mpu3050->regs), mpu3050->regs);
if (ret) {
dev_err(mpu3050->dev, "cannot enable regulators\n");
return ret;
}
msleep(200);
ret = regmap_update_bits(mpu3050->map, MPU3050_PWR_MGM,
MPU3050_PWR_MGM_SLEEP, 0);
if (ret) {
dev_err(mpu3050->dev, "error setting power mode\n");
return ret;
}
msleep(10);
return 0;
}
static int mpu3050_power_down(struct mpu3050 *mpu3050)
{
int ret;
ret = regmap_update_bits(mpu3050->map, MPU3050_PWR_MGM,
MPU3050_PWR_MGM_SLEEP, MPU3050_PWR_MGM_SLEEP);
if (ret)
dev_err(mpu3050->dev, "error putting to sleep\n");
ret = regulator_bulk_disable(ARRAY_SIZE(mpu3050->regs), mpu3050->regs);
if (ret)
dev_err(mpu3050->dev, "error disabling regulators\n");
return 0;
}
static irqreturn_t mpu3050_irq_handler(int irq, void *p)
{
struct iio_trigger *trig = p;
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct mpu3050 *mpu3050 = iio_priv(indio_dev);
if (!mpu3050->hw_irq_trigger)
return IRQ_NONE;
mpu3050->hw_timestamp = iio_get_time_ns(indio_dev);
return IRQ_WAKE_THREAD;
}
static irqreturn_t mpu3050_irq_thread(int irq, void *p)
{
struct iio_trigger *trig = p;
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct mpu3050 *mpu3050 = iio_priv(indio_dev);
unsigned int val;
int ret;
ret = regmap_read(mpu3050->map, MPU3050_INT_STATUS, &val);
if (ret) {
dev_err(mpu3050->dev, "error reading IRQ status\n");
return IRQ_HANDLED;
}
if (!(val & MPU3050_INT_STATUS_RAW_RDY))
return IRQ_NONE;
iio_trigger_poll_chained(p);
return IRQ_HANDLED;
}
static int mpu3050_drdy_trigger_set_state(struct iio_trigger *trig,
bool enable)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct mpu3050 *mpu3050 = iio_priv(indio_dev);
unsigned int val;
int ret;
if (!enable) {
ret = regmap_write(mpu3050->map,
MPU3050_INT_CFG,
0);
if (ret)
dev_err(mpu3050->dev, "error disabling IRQ\n");
ret = regmap_read(mpu3050->map, MPU3050_INT_STATUS, &val);
if (ret)
dev_err(mpu3050->dev, "error clearing IRQ status\n");
ret = regmap_write(mpu3050->map, MPU3050_FIFO_EN, 0);
if (ret)
dev_err(mpu3050->dev, "error disabling FIFO\n");
ret = regmap_write(mpu3050->map, MPU3050_USR_CTRL,
MPU3050_USR_CTRL_FIFO_RST);
if (ret)
dev_err(mpu3050->dev, "error resetting FIFO\n");
pm_runtime_mark_last_busy(mpu3050->dev);
pm_runtime_put_autosuspend(mpu3050->dev);
mpu3050->hw_irq_trigger = false;
return 0;
} else {
pm_runtime_get_sync(mpu3050->dev);
mpu3050->hw_irq_trigger = true;
ret = regmap_write(mpu3050->map, MPU3050_FIFO_EN, 0);
if (ret)
return ret;
ret = regmap_update_bits(mpu3050->map, MPU3050_USR_CTRL,
MPU3050_USR_CTRL_FIFO_EN |
MPU3050_USR_CTRL_FIFO_RST,
MPU3050_USR_CTRL_FIFO_EN |
MPU3050_USR_CTRL_FIFO_RST);
if (ret)
return ret;
mpu3050->pending_fifo_footer = false;
ret = regmap_write(mpu3050->map, MPU3050_FIFO_EN,
MPU3050_FIFO_EN_TEMP_OUT |
MPU3050_FIFO_EN_GYRO_XOUT |
MPU3050_FIFO_EN_GYRO_YOUT |
MPU3050_FIFO_EN_GYRO_ZOUT |
MPU3050_FIFO_EN_FOOTER);
if (ret)
return ret;
ret = mpu3050_start_sampling(mpu3050);
if (ret)
return ret;
ret = regmap_read(mpu3050->map, MPU3050_INT_STATUS, &val);
if (ret)
dev_err(mpu3050->dev, "error clearing IRQ status\n");
val = MPU3050_INT_RAW_RDY_EN;
if (mpu3050->irq_actl)
val |= MPU3050_INT_ACTL;
if (mpu3050->irq_latch)
val |= MPU3050_INT_LATCH_EN;
if (mpu3050->irq_opendrain)
val |= MPU3050_INT_OPEN;
ret = regmap_write(mpu3050->map, MPU3050_INT_CFG, val);
if (ret)
return ret;
}
return 0;
}
static int mpu3050_trigger_probe(struct iio_dev *indio_dev, int irq)
{
struct mpu3050 *mpu3050 = iio_priv(indio_dev);
unsigned long irq_trig;
int ret;
mpu3050->trig = devm_iio_trigger_alloc(&indio_dev->dev,
"%s-dev%d",
indio_dev->name,
indio_dev->id);
if (!mpu3050->trig)
return -ENOMEM;
if (of_property_read_bool(mpu3050->dev->of_node, "drive-open-drain"))
mpu3050->irq_opendrain = true;
irq_trig = irqd_get_trigger_type(irq_get_irq_data(irq));
switch (irq_trig) {
case IRQF_TRIGGER_RISING:
dev_info(&indio_dev->dev,
"pulse interrupts on the rising edge\n");
if (mpu3050->irq_opendrain) {
dev_info(&indio_dev->dev,
"rising edge incompatible with open drain\n");
mpu3050->irq_opendrain = false;
}
break;
case IRQF_TRIGGER_FALLING:
mpu3050->irq_actl = true;
dev_info(&indio_dev->dev,
"pulse interrupts on the falling edge\n");
break;
case IRQF_TRIGGER_HIGH:
mpu3050->irq_latch = true;
dev_info(&indio_dev->dev,
"interrupts active high level\n");
if (mpu3050->irq_opendrain) {
dev_info(&indio_dev->dev,
"active high incompatible with open drain\n");
mpu3050->irq_opendrain = false;
}
irq_trig |= IRQF_ONESHOT;
break;
case IRQF_TRIGGER_LOW:
mpu3050->irq_latch = true;
mpu3050->irq_actl = true;
irq_trig |= IRQF_ONESHOT;
dev_info(&indio_dev->dev,
"interrupts active low level\n");
break;
default:
dev_err(&indio_dev->dev,
"unsupported IRQ trigger specified (%lx), enforce "
"rising edge\n", irq_trig);
irq_trig = IRQF_TRIGGER_RISING;
break;
}
if (mpu3050->irq_opendrain)
irq_trig |= IRQF_SHARED;
ret = request_threaded_irq(irq,
mpu3050_irq_handler,
mpu3050_irq_thread,
irq_trig,
mpu3050->trig->name,
mpu3050->trig);
if (ret) {
dev_err(mpu3050->dev,
"can't get IRQ %d, error %d\n", irq, ret);
return ret;
}
mpu3050->irq = irq;
mpu3050->trig->dev.parent = mpu3050->dev;
mpu3050->trig->ops = &mpu3050_trigger_ops;
iio_trigger_set_drvdata(mpu3050->trig, indio_dev);
ret = iio_trigger_register(mpu3050->trig);
if (ret)
return ret;
indio_dev->trig = iio_trigger_get(mpu3050->trig);
return 0;
}
int mpu3050_common_probe(struct device *dev,
struct regmap *map,
int irq,
const char *name)
{
struct iio_dev *indio_dev;
struct mpu3050 *mpu3050;
unsigned int val;
int ret;
indio_dev = devm_iio_device_alloc(dev, sizeof(*mpu3050));
if (!indio_dev)
return -ENOMEM;
mpu3050 = iio_priv(indio_dev);
mpu3050->dev = dev;
mpu3050->map = map;
mutex_init(&mpu3050->lock);
mpu3050->fullscale = FS_2000_DPS;
mpu3050->lpf = MPU3050_DLPF_CFG_188HZ;
mpu3050->divisor = 99;
ret = of_iio_read_mount_matrix(dev, "mount-matrix",
&mpu3050->orientation);
if (ret)
return ret;
mpu3050->regs[0].supply = mpu3050_reg_vdd;
mpu3050->regs[1].supply = mpu3050_reg_vlogic;
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(mpu3050->regs),
mpu3050->regs);
if (ret) {
dev_err(dev, "Cannot get regulators\n");
return ret;
}
ret = mpu3050_power_up(mpu3050);
if (ret)
return ret;
ret = regmap_read(map, MPU3050_CHIP_ID_REG, &val);
if (ret) {
dev_err(dev, "could not read device ID\n");
ret = -ENODEV;
goto err_power_down;
}
if (val != MPU3050_CHIP_ID) {
dev_err(dev, "unsupported chip id %02x\n", (u8)val);
ret = -ENODEV;
goto err_power_down;
}
ret = regmap_read(map, MPU3050_PRODUCT_ID_REG, &val);
if (ret) {
dev_err(dev, "could not read device ID\n");
ret = -ENODEV;
goto err_power_down;
}
dev_info(dev, "found MPU-3050 part no: %d, version: %d\n",
((val >> 4) & 0xf), (val & 0xf));
ret = mpu3050_hw_init(mpu3050);
if (ret)
goto err_power_down;
indio_dev->dev.parent = dev;
indio_dev->channels = mpu3050_channels;
indio_dev->num_channels = ARRAY_SIZE(mpu3050_channels);
indio_dev->info = &mpu3050_info;
indio_dev->available_scan_masks = mpu3050_scan_masks;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->name = name;
ret = iio_triggered_buffer_setup(indio_dev, iio_pollfunc_store_time,
mpu3050_trigger_handler,
&mpu3050_buffer_setup_ops);
if (ret) {
dev_err(dev, "triggered buffer setup failed\n");
goto err_power_down;
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(dev, "device register failed\n");
goto err_cleanup_buffer;
}
dev_set_drvdata(dev, indio_dev);
if (irq) {
ret = mpu3050_trigger_probe(indio_dev, irq);
if (ret)
dev_err(dev, "failed to register trigger\n");
}
pm_runtime_get_noresume(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
pm_runtime_set_autosuspend_delay(dev, 10000);
pm_runtime_use_autosuspend(dev);
pm_runtime_put(dev);
return 0;
err_cleanup_buffer:
iio_triggered_buffer_cleanup(indio_dev);
err_power_down:
mpu3050_power_down(mpu3050);
return ret;
}
int mpu3050_common_remove(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct mpu3050 *mpu3050 = iio_priv(indio_dev);
pm_runtime_get_sync(dev);
pm_runtime_put_noidle(dev);
pm_runtime_disable(dev);
iio_triggered_buffer_cleanup(indio_dev);
if (mpu3050->irq)
free_irq(mpu3050->irq, mpu3050);
iio_device_unregister(indio_dev);
mpu3050_power_down(mpu3050);
return 0;
}
static int mpu3050_runtime_suspend(struct device *dev)
{
return mpu3050_power_down(iio_priv(dev_get_drvdata(dev)));
}
static int mpu3050_runtime_resume(struct device *dev)
{
return mpu3050_power_up(iio_priv(dev_get_drvdata(dev)));
}
