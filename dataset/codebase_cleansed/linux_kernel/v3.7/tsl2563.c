static int tsl2563_set_power(struct tsl2563_chip *chip, int on)
{
struct i2c_client *client = chip->client;
u8 cmd;
cmd = on ? TSL2563_CMD_POWER_ON : TSL2563_CMD_POWER_OFF;
return i2c_smbus_write_byte_data(client,
TSL2563_CMD | TSL2563_REG_CTRL, cmd);
}
static int tsl2563_get_power(struct tsl2563_chip *chip)
{
struct i2c_client *client = chip->client;
int ret;
ret = i2c_smbus_read_byte_data(client, TSL2563_CMD | TSL2563_REG_CTRL);
if (ret < 0)
return ret;
return (ret & TSL2563_CTRL_POWER_MASK) == TSL2563_CMD_POWER_ON;
}
static int tsl2563_configure(struct tsl2563_chip *chip)
{
int ret;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2563_CMD | TSL2563_REG_TIMING,
chip->gainlevel->gaintime);
if (ret)
goto error_ret;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2563_CMD | TSL2563_REG_HIGHLOW,
chip->high_thres & 0xFF);
if (ret)
goto error_ret;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2563_CMD | TSL2563_REG_HIGHHIGH,
(chip->high_thres >> 8) & 0xFF);
if (ret)
goto error_ret;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2563_CMD | TSL2563_REG_LOWLOW,
chip->low_thres & 0xFF);
if (ret)
goto error_ret;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2563_CMD | TSL2563_REG_LOWHIGH,
(chip->low_thres >> 8) & 0xFF);
error_ret:
return ret;
}
static void tsl2563_poweroff_work(struct work_struct *work)
{
struct tsl2563_chip *chip =
container_of(work, struct tsl2563_chip, poweroff_work.work);
tsl2563_set_power(chip, 0);
}
static int tsl2563_detect(struct tsl2563_chip *chip)
{
int ret;
ret = tsl2563_set_power(chip, 1);
if (ret)
return ret;
ret = tsl2563_get_power(chip);
if (ret < 0)
return ret;
return ret ? 0 : -ENODEV;
}
static int tsl2563_read_id(struct tsl2563_chip *chip, u8 *id)
{
struct i2c_client *client = chip->client;
int ret;
ret = i2c_smbus_read_byte_data(client, TSL2563_CMD | TSL2563_REG_ID);
if (ret < 0)
return ret;
*id = ret;
return 0;
}
static int adc_shiftbits(u8 timing)
{
int shift = 0;
switch (timing & TSL2563_TIMING_MASK) {
case TSL2563_TIMING_13MS:
shift += 5;
break;
case TSL2563_TIMING_100MS:
shift += 2;
break;
case TSL2563_TIMING_400MS:
break;
}
if (!(timing & TSL2563_TIMING_GAIN16))
shift += 4;
return shift;
}
static u32 normalize_adc(u16 adc, u8 timing)
{
return adc << adc_shiftbits(timing);
}
static void tsl2563_wait_adc(struct tsl2563_chip *chip)
{
unsigned int delay;
switch (chip->gainlevel->gaintime & TSL2563_TIMING_MASK) {
case TSL2563_TIMING_13MS:
delay = 14;
break;
case TSL2563_TIMING_100MS:
delay = 101;
break;
default:
delay = 402;
}
schedule_timeout_interruptible(msecs_to_jiffies(delay) + 2);
}
static int tsl2563_adjust_gainlevel(struct tsl2563_chip *chip, u16 adc)
{
struct i2c_client *client = chip->client;
if (adc > chip->gainlevel->max || adc < chip->gainlevel->min) {
(adc > chip->gainlevel->max) ?
chip->gainlevel++ : chip->gainlevel--;
i2c_smbus_write_byte_data(client,
TSL2563_CMD | TSL2563_REG_TIMING,
chip->gainlevel->gaintime);
tsl2563_wait_adc(chip);
tsl2563_wait_adc(chip);
return 1;
} else
return 0;
}
static int tsl2563_get_adc(struct tsl2563_chip *chip)
{
struct i2c_client *client = chip->client;
u16 adc0, adc1;
int retry = 1;
int ret = 0;
if (chip->suspended)
goto out;
if (!chip->int_enabled) {
cancel_delayed_work(&chip->poweroff_work);
if (!tsl2563_get_power(chip)) {
ret = tsl2563_set_power(chip, 1);
if (ret)
goto out;
ret = tsl2563_configure(chip);
if (ret)
goto out;
tsl2563_wait_adc(chip);
}
}
while (retry) {
ret = i2c_smbus_read_word_data(client,
TSL2563_CMD | TSL2563_REG_DATA0LOW);
if (ret < 0)
goto out;
adc0 = ret;
ret = i2c_smbus_read_word_data(client,
TSL2563_CMD | TSL2563_REG_DATA1LOW);
if (ret < 0)
goto out;
adc1 = ret;
retry = tsl2563_adjust_gainlevel(chip, adc0);
}
chip->data0 = normalize_adc(adc0, chip->gainlevel->gaintime);
chip->data1 = normalize_adc(adc1, chip->gainlevel->gaintime);
if (!chip->int_enabled)
schedule_delayed_work(&chip->poweroff_work, 5 * HZ);
ret = 0;
out:
return ret;
}
static inline int calib_to_sysfs(u32 calib)
{
return (int) (((calib * CALIB_BASE_SYSFS) +
CALIB_FRAC_HALF) >> CALIB_FRAC_BITS);
}
static inline u32 calib_from_sysfs(int value)
{
return (((u32) value) << CALIB_FRAC_BITS) / CALIB_BASE_SYSFS;
}
static unsigned int adc_to_lux(u32 adc0, u32 adc1)
{
const struct tsl2563_lux_coeff *lp = lux_table;
unsigned long ratio, lux, ch0 = adc0, ch1 = adc1;
ratio = ch0 ? ((ch1 << ADC_FRAC_BITS) / ch0) : ULONG_MAX;
while (lp->ch_ratio < ratio)
lp++;
lux = ch0 * lp->ch0_coeff - ch1 * lp->ch1_coeff;
return (unsigned int) (lux >> ADC_FRAC_BITS);
}
static u32 calib_adc(u32 adc, u32 calib)
{
unsigned long scaled = adc;
scaled *= calib;
scaled >>= CALIB_FRAC_BITS;
return (u32) scaled;
}
static int tsl2563_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct tsl2563_chip *chip = iio_priv(indio_dev);
if (chan->channel == IIO_MOD_LIGHT_BOTH)
chip->calib0 = calib_from_sysfs(val);
else
chip->calib1 = calib_from_sysfs(val);
return 0;
}
static int tsl2563_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
int ret = -EINVAL;
u32 calib0, calib1;
struct tsl2563_chip *chip = iio_priv(indio_dev);
mutex_lock(&chip->lock);
switch (m) {
case IIO_CHAN_INFO_RAW:
case IIO_CHAN_INFO_PROCESSED:
switch (chan->type) {
case IIO_LIGHT:
ret = tsl2563_get_adc(chip);
if (ret)
goto error_ret;
calib0 = calib_adc(chip->data0, chip->calib0) *
chip->cover_comp_gain;
calib1 = calib_adc(chip->data1, chip->calib1) *
chip->cover_comp_gain;
*val = adc_to_lux(calib0, calib1);
ret = IIO_VAL_INT;
break;
case IIO_INTENSITY:
ret = tsl2563_get_adc(chip);
if (ret)
goto error_ret;
if (chan->channel == 0)
*val = chip->data0;
else
*val = chip->data1;
ret = IIO_VAL_INT;
break;
default:
break;
}
break;
case IIO_CHAN_INFO_CALIBSCALE:
if (chan->channel == 0)
*val = calib_to_sysfs(chip->calib0);
else
*val = calib_to_sysfs(chip->calib1);
ret = IIO_VAL_INT;
break;
default:
ret = -EINVAL;
goto error_ret;
}
error_ret:
mutex_unlock(&chip->lock);
return ret;
}
static int tsl2563_read_thresh(struct iio_dev *indio_dev,
u64 event_code,
int *val)
{
struct tsl2563_chip *chip = iio_priv(indio_dev);
switch (IIO_EVENT_CODE_EXTRACT_DIR(event_code)) {
case IIO_EV_DIR_RISING:
*val = chip->high_thres;
break;
case IIO_EV_DIR_FALLING:
*val = chip->low_thres;
break;
default:
return -EINVAL;
}
return 0;
}
static int tsl2563_write_thresh(struct iio_dev *indio_dev,
u64 event_code,
int val)
{
struct tsl2563_chip *chip = iio_priv(indio_dev);
int ret;
u8 address;
if (IIO_EVENT_CODE_EXTRACT_DIR(event_code) == IIO_EV_DIR_RISING)
address = TSL2563_REG_HIGHLOW;
else
address = TSL2563_REG_LOWLOW;
mutex_lock(&chip->lock);
ret = i2c_smbus_write_byte_data(chip->client, TSL2563_CMD | address,
val & 0xFF);
if (ret)
goto error_ret;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2563_CMD | (address + 1),
(val >> 8) & 0xFF);
if (IIO_EVENT_CODE_EXTRACT_DIR(event_code) == IIO_EV_DIR_RISING)
chip->high_thres = val;
else
chip->low_thres = val;
error_ret:
mutex_unlock(&chip->lock);
return ret;
}
static irqreturn_t tsl2563_event_handler(int irq, void *private)
{
struct iio_dev *dev_info = private;
struct tsl2563_chip *chip = iio_priv(dev_info);
iio_push_event(dev_info,
IIO_UNMOD_EVENT_CODE(IIO_LIGHT,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_EITHER),
iio_get_time_ns());
i2c_smbus_write_byte(chip->client, TSL2563_CMD | TSL2563_CLEARINT);
return IRQ_HANDLED;
}
static int tsl2563_write_interrupt_config(struct iio_dev *indio_dev,
u64 event_code,
int state)
{
struct tsl2563_chip *chip = iio_priv(indio_dev);
int ret = 0;
mutex_lock(&chip->lock);
if (state && !(chip->intr & 0x30)) {
chip->intr &= ~0x30;
chip->intr |= 0x10;
cancel_delayed_work(&chip->poweroff_work);
if (!tsl2563_get_power(chip)) {
ret = tsl2563_set_power(chip, 1);
if (ret)
goto out;
ret = tsl2563_configure(chip);
if (ret)
goto out;
}
ret = i2c_smbus_write_byte_data(chip->client,
TSL2563_CMD | TSL2563_REG_INT,
chip->intr);
chip->int_enabled = true;
}
if (!state && (chip->intr & 0x30)) {
chip->intr |= ~0x30;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2563_CMD | TSL2563_REG_INT,
chip->intr);
chip->int_enabled = false;
schedule_delayed_work(&chip->poweroff_work, 5 * HZ);
}
out:
mutex_unlock(&chip->lock);
return ret;
}
static int tsl2563_read_interrupt_config(struct iio_dev *indio_dev,
u64 event_code)
{
struct tsl2563_chip *chip = iio_priv(indio_dev);
int ret;
mutex_lock(&chip->lock);
ret = i2c_smbus_read_byte_data(chip->client,
TSL2563_CMD | TSL2563_REG_INT);
mutex_unlock(&chip->lock);
if (ret < 0)
goto error_ret;
ret = !!(ret & 0x30);
error_ret:
return ret;
}
static int __devinit tsl2563_probe(struct i2c_client *client,
const struct i2c_device_id *device_id)
{
struct iio_dev *indio_dev;
struct tsl2563_chip *chip;
struct tsl2563_platform_data *pdata = client->dev.platform_data;
int err = 0;
u8 id = 0;
indio_dev = iio_device_alloc(sizeof(*chip));
if (!indio_dev)
return -ENOMEM;
chip = iio_priv(indio_dev);
i2c_set_clientdata(client, chip);
chip->client = client;
err = tsl2563_detect(chip);
if (err) {
dev_err(&client->dev, "detect error %d\n", -err);
goto fail1;
}
err = tsl2563_read_id(chip, &id);
if (err) {
dev_err(&client->dev, "read id error %d\n", -err);
goto fail1;
}
mutex_init(&chip->lock);
chip->low_thres = 0x0;
chip->high_thres = 0xffff;
chip->gainlevel = tsl2563_gainlevel_table;
chip->intr = TSL2563_INT_PERSIST(4);
chip->calib0 = calib_from_sysfs(CALIB_BASE_SYSFS);
chip->calib1 = calib_from_sysfs(CALIB_BASE_SYSFS);
if (pdata)
chip->cover_comp_gain = pdata->cover_comp_gain;
else
chip->cover_comp_gain = 1;
dev_info(&client->dev, "model %d, rev. %d\n", id >> 4, id & 0x0f);
indio_dev->name = client->name;
indio_dev->channels = tsl2563_channels;
indio_dev->num_channels = ARRAY_SIZE(tsl2563_channels);
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
if (client->irq)
indio_dev->info = &tsl2563_info;
else
indio_dev->info = &tsl2563_info_no_irq;
if (client->irq) {
err = request_threaded_irq(client->irq,
NULL,
&tsl2563_event_handler,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"tsl2563_event",
indio_dev);
if (err) {
dev_err(&client->dev, "irq request error %d\n", -err);
goto fail1;
}
}
err = tsl2563_configure(chip);
if (err) {
dev_err(&client->dev, "configure error %d\n", -err);
goto fail2;
}
INIT_DELAYED_WORK(&chip->poweroff_work, tsl2563_poweroff_work);
schedule_delayed_work(&chip->poweroff_work, 5 * HZ);
err = iio_device_register(indio_dev);
if (err) {
dev_err(&client->dev, "iio registration error %d\n", -err);
goto fail3;
}
return 0;
fail3:
cancel_delayed_work(&chip->poweroff_work);
flush_scheduled_work();
fail2:
if (client->irq)
free_irq(client->irq, indio_dev);
fail1:
iio_device_free(indio_dev);
return err;
}
static int __devexit tsl2563_remove(struct i2c_client *client)
{
struct tsl2563_chip *chip = i2c_get_clientdata(client);
struct iio_dev *indio_dev = iio_priv_to_dev(chip);
iio_device_unregister(indio_dev);
if (!chip->int_enabled)
cancel_delayed_work(&chip->poweroff_work);
chip->intr |= ~0x30;
i2c_smbus_write_byte_data(chip->client, TSL2563_CMD | TSL2563_REG_INT,
chip->intr);
flush_scheduled_work();
tsl2563_set_power(chip, 0);
if (client->irq)
free_irq(client->irq, indio_dev);
iio_device_free(indio_dev);
return 0;
}
static int tsl2563_suspend(struct device *dev)
{
struct tsl2563_chip *chip = i2c_get_clientdata(to_i2c_client(dev));
int ret;
mutex_lock(&chip->lock);
ret = tsl2563_set_power(chip, 0);
if (ret)
goto out;
chip->suspended = true;
out:
mutex_unlock(&chip->lock);
return ret;
}
static int tsl2563_resume(struct device *dev)
{
struct tsl2563_chip *chip = i2c_get_clientdata(to_i2c_client(dev));
int ret;
mutex_lock(&chip->lock);
ret = tsl2563_set_power(chip, 1);
if (ret)
goto out;
ret = tsl2563_configure(chip);
if (ret)
goto out;
chip->suspended = false;
out:
mutex_unlock(&chip->lock);
return ret;
}
