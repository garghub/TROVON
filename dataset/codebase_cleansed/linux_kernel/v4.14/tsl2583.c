static void tsl2583_defaults(struct tsl2583_chip *chip)
{
chip->als_settings.als_time = 100;
chip->als_settings.als_gain = 0;
chip->als_settings.als_gain_trim = 1000;
chip->als_settings.als_cal_target = 130;
memcpy(chip->als_settings.als_device_lux, tsl2583_default_lux,
sizeof(tsl2583_default_lux));
}
static int tsl2583_get_lux(struct iio_dev *indio_dev)
{
u16 ch0, ch1;
u32 lux;
u64 lux64;
u32 ratio;
u8 buf[5];
struct tsl2583_lux *p;
struct tsl2583_chip *chip = iio_priv(indio_dev);
int i, ret;
ret = i2c_smbus_read_byte_data(chip->client, TSL2583_CMD_REG);
if (ret < 0) {
dev_err(&chip->client->dev, "%s: failed to read CMD_REG register\n",
__func__);
goto done;
}
if (!(ret & TSL2583_STA_ADC_INTR)) {
dev_err(&chip->client->dev, "%s: data not valid; returning last value\n",
__func__);
ret = chip->als_cur_info.lux;
goto done;
}
for (i = 0; i < 4; i++) {
int reg = TSL2583_CMD_REG | (TSL2583_ALS_CHAN0LO + i);
ret = i2c_smbus_read_byte_data(chip->client, reg);
if (ret < 0) {
dev_err(&chip->client->dev, "%s: failed to read register %x\n",
__func__, reg);
goto done;
}
buf[i] = ret;
}
ret = i2c_smbus_write_byte(chip->client,
(TSL2583_CMD_REG | TSL2583_CMD_SPL_FN |
TSL2583_CMD_ALS_INT_CLR));
if (ret < 0) {
dev_err(&chip->client->dev, "%s: failed to clear the interrupt bit\n",
__func__);
goto done;
}
ch0 = le16_to_cpup((const __le16 *)&buf[0]);
ch1 = le16_to_cpup((const __le16 *)&buf[2]);
chip->als_cur_info.als_ch0 = ch0;
chip->als_cur_info.als_ch1 = ch1;
if ((ch0 >= chip->als_saturation) || (ch1 >= chip->als_saturation))
goto return_max;
if (!ch0) {
ret = 0;
chip->als_cur_info.lux = 0;
goto done;
}
ratio = (ch1 << 15) / ch0;
for (p = (struct tsl2583_lux *)chip->als_settings.als_device_lux;
p->ratio != 0 && p->ratio < ratio; p++)
;
if (p->ratio == 0) {
lux = 0;
} else {
u32 ch0lux, ch1lux;
ch0lux = ((ch0 * p->ch0) +
(gainadj[chip->als_settings.als_gain].ch0 >> 1))
/ gainadj[chip->als_settings.als_gain].ch0;
ch1lux = ((ch1 * p->ch1) +
(gainadj[chip->als_settings.als_gain].ch1 >> 1))
/ gainadj[chip->als_settings.als_gain].ch1;
if (ch1lux > ch0lux) {
dev_dbg(&chip->client->dev, "%s: No Data - Returning 0\n",
__func__);
ret = 0;
chip->als_cur_info.lux = 0;
goto done;
}
lux = ch0lux - ch1lux;
}
if (chip->als_time_scale == 0)
lux = 0;
else
lux = (lux + (chip->als_time_scale >> 1)) /
chip->als_time_scale;
lux64 = lux;
lux64 = lux64 * chip->als_settings.als_gain_trim;
lux64 >>= 13;
lux = lux64;
lux = (lux + 500) / 1000;
if (lux > TSL2583_LUX_CALC_OVER_FLOW) {
return_max:
lux = TSL2583_LUX_CALC_OVER_FLOW;
}
chip->als_cur_info.lux = lux;
ret = lux;
done:
return ret;
}
static int tsl2583_als_calibrate(struct iio_dev *indio_dev)
{
struct tsl2583_chip *chip = iio_priv(indio_dev);
unsigned int gain_trim_val;
int ret;
int lux_val;
ret = i2c_smbus_read_byte_data(chip->client,
TSL2583_CMD_REG | TSL2583_CNTRL);
if (ret < 0) {
dev_err(&chip->client->dev,
"%s: failed to read from the CNTRL register\n",
__func__);
return ret;
}
if ((ret & (TSL2583_CNTL_ADC_ENBL | TSL2583_CNTL_PWR_ON))
!= (TSL2583_CNTL_ADC_ENBL | TSL2583_CNTL_PWR_ON)) {
dev_err(&chip->client->dev,
"%s: Device is not powered on and/or ADC is not enabled\n",
__func__);
return -EINVAL;
} else if ((ret & TSL2583_STA_ADC_VALID) != TSL2583_STA_ADC_VALID) {
dev_err(&chip->client->dev,
"%s: The two ADC channels have not completed an integration cycle\n",
__func__);
return -ENODATA;
}
lux_val = tsl2583_get_lux(indio_dev);
if (lux_val < 0) {
dev_err(&chip->client->dev, "%s: failed to get lux\n",
__func__);
return lux_val;
}
gain_trim_val = (unsigned int)(((chip->als_settings.als_cal_target)
* chip->als_settings.als_gain_trim) / lux_val);
if ((gain_trim_val < 250) || (gain_trim_val > 4000)) {
dev_err(&chip->client->dev,
"%s: trim_val of %d is not within the range [250, 4000]\n",
__func__, gain_trim_val);
return -ENODATA;
}
chip->als_settings.als_gain_trim = (int)gain_trim_val;
return 0;
}
static int tsl2583_set_als_time(struct tsl2583_chip *chip)
{
int als_count, als_time, ret;
u8 val;
als_count = (chip->als_settings.als_time * 100 + 135) / 270;
if (!als_count)
als_count = 1;
als_time = (als_count * 27 + 5) / 10;
val = 256 - als_count;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2583_CMD_REG | TSL2583_ALS_TIME,
val);
if (ret < 0) {
dev_err(&chip->client->dev, "%s: failed to set the als time to %d\n",
__func__, val);
return ret;
}
chip->als_saturation = als_count * 922;
chip->als_time_scale = (als_time + 25) / 50;
return ret;
}
static int tsl2583_set_als_gain(struct tsl2583_chip *chip)
{
int ret;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2583_CMD_REG | TSL2583_GAIN,
chip->als_settings.als_gain);
if (ret < 0)
dev_err(&chip->client->dev,
"%s: failed to set the gain to %d\n", __func__,
chip->als_settings.als_gain);
return ret;
}
static int tsl2583_set_power_state(struct tsl2583_chip *chip, u8 state)
{
int ret;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2583_CMD_REG | TSL2583_CNTRL, state);
if (ret < 0)
dev_err(&chip->client->dev,
"%s: failed to set the power state to %d\n", __func__,
state);
return ret;
}
static int tsl2583_chip_init_and_power_on(struct iio_dev *indio_dev)
{
struct tsl2583_chip *chip = iio_priv(indio_dev);
int ret;
ret = tsl2583_set_power_state(chip, TSL2583_CNTL_PWR_ON);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2583_CMD_REG | TSL2583_INTERRUPT,
TSL2583_INTERRUPT_DISABLED);
if (ret < 0) {
dev_err(&chip->client->dev,
"%s: failed to disable interrupts\n", __func__);
return ret;
}
ret = tsl2583_set_als_time(chip);
if (ret < 0)
return ret;
ret = tsl2583_set_als_gain(chip);
if (ret < 0)
return ret;
usleep_range(3000, 3500);
ret = tsl2583_set_power_state(chip, TSL2583_CNTL_PWR_ON |
TSL2583_CNTL_ADC_ENBL);
if (ret < 0)
return ret;
return ret;
}
static ssize_t in_illuminance_input_target_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct tsl2583_chip *chip = iio_priv(indio_dev);
int ret;
mutex_lock(&chip->als_mutex);
ret = sprintf(buf, "%d\n", chip->als_settings.als_cal_target);
mutex_unlock(&chip->als_mutex);
return ret;
}
static ssize_t in_illuminance_input_target_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct tsl2583_chip *chip = iio_priv(indio_dev);
int value;
if (kstrtoint(buf, 0, &value) || !value)
return -EINVAL;
mutex_lock(&chip->als_mutex);
chip->als_settings.als_cal_target = value;
mutex_unlock(&chip->als_mutex);
return len;
}
static ssize_t in_illuminance_calibrate_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct tsl2583_chip *chip = iio_priv(indio_dev);
int value, ret;
if (kstrtoint(buf, 0, &value) || value != 1)
return -EINVAL;
mutex_lock(&chip->als_mutex);
ret = tsl2583_als_calibrate(indio_dev);
if (ret < 0)
goto done;
ret = len;
done:
mutex_unlock(&chip->als_mutex);
return ret;
}
static ssize_t in_illuminance_lux_table_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct tsl2583_chip *chip = iio_priv(indio_dev);
unsigned int i;
int offset = 0;
for (i = 0; i < ARRAY_SIZE(chip->als_settings.als_device_lux); i++) {
offset += sprintf(buf + offset, "%u,%u,%u,",
chip->als_settings.als_device_lux[i].ratio,
chip->als_settings.als_device_lux[i].ch0,
chip->als_settings.als_device_lux[i].ch1);
if (chip->als_settings.als_device_lux[i].ratio == 0) {
offset--;
break;
}
}
offset += sprintf(buf + offset, "\n");
return offset;
}
static ssize_t in_illuminance_lux_table_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct tsl2583_chip *chip = iio_priv(indio_dev);
const unsigned int max_ints = TSL2583_MAX_LUX_TABLE_ENTRIES * 3;
int value[TSL2583_MAX_LUX_TABLE_ENTRIES * 3 + 1];
int ret = -EINVAL;
unsigned int n;
mutex_lock(&chip->als_mutex);
get_options(buf, ARRAY_SIZE(value), value);
n = value[0];
if ((n % 3) || n < 6 || n > max_ints) {
dev_err(dev,
"%s: The number of entries in the lux table must be a multiple of 3 and within the range [6, %d]\n",
__func__, max_ints);
goto done;
}
if ((value[n - 2] | value[n - 1] | value[n]) != 0) {
dev_err(dev, "%s: The last 3 entries in the lux table must be zeros.\n",
__func__);
goto done;
}
memcpy(chip->als_settings.als_device_lux, &value[1],
value[0] * sizeof(value[1]));
ret = len;
done:
mutex_unlock(&chip->als_mutex);
return ret;
}
static int tsl2583_set_pm_runtime_busy(struct tsl2583_chip *chip, bool on)
{
int ret;
if (on) {
ret = pm_runtime_get_sync(&chip->client->dev);
if (ret < 0)
pm_runtime_put_noidle(&chip->client->dev);
} else {
pm_runtime_mark_last_busy(&chip->client->dev);
ret = pm_runtime_put_autosuspend(&chip->client->dev);
}
return ret;
}
static int tsl2583_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct tsl2583_chip *chip = iio_priv(indio_dev);
int ret, pm_ret;
ret = tsl2583_set_pm_runtime_busy(chip, true);
if (ret < 0)
return ret;
mutex_lock(&chip->als_mutex);
ret = -EINVAL;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (chan->type == IIO_LIGHT) {
ret = tsl2583_get_lux(indio_dev);
if (ret < 0)
goto read_done;
if (chan->channel2 == IIO_MOD_LIGHT_BOTH)
*val = chip->als_cur_info.als_ch0;
else
*val = chip->als_cur_info.als_ch1;
ret = IIO_VAL_INT;
}
break;
case IIO_CHAN_INFO_PROCESSED:
if (chan->type == IIO_LIGHT) {
ret = tsl2583_get_lux(indio_dev);
if (ret < 0)
goto read_done;
*val = ret;
ret = IIO_VAL_INT;
}
break;
case IIO_CHAN_INFO_CALIBBIAS:
if (chan->type == IIO_LIGHT) {
*val = chip->als_settings.als_gain_trim;
ret = IIO_VAL_INT;
}
break;
case IIO_CHAN_INFO_CALIBSCALE:
if (chan->type == IIO_LIGHT) {
*val = gainadj[chip->als_settings.als_gain].mean;
ret = IIO_VAL_INT;
}
break;
case IIO_CHAN_INFO_INT_TIME:
if (chan->type == IIO_LIGHT) {
*val = 0;
*val2 = chip->als_settings.als_time;
ret = IIO_VAL_INT_PLUS_MICRO;
}
break;
default:
break;
}
read_done:
mutex_unlock(&chip->als_mutex);
if (ret < 0)
return ret;
pm_ret = tsl2583_set_pm_runtime_busy(chip, false);
if (pm_ret < 0)
return pm_ret;
return ret;
}
static int tsl2583_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct tsl2583_chip *chip = iio_priv(indio_dev);
int ret;
ret = tsl2583_set_pm_runtime_busy(chip, true);
if (ret < 0)
return ret;
mutex_lock(&chip->als_mutex);
ret = -EINVAL;
switch (mask) {
case IIO_CHAN_INFO_CALIBBIAS:
if (chan->type == IIO_LIGHT) {
chip->als_settings.als_gain_trim = val;
ret = 0;
}
break;
case IIO_CHAN_INFO_CALIBSCALE:
if (chan->type == IIO_LIGHT) {
unsigned int i;
for (i = 0; i < ARRAY_SIZE(gainadj); i++) {
if (gainadj[i].mean == val) {
chip->als_settings.als_gain = i;
ret = tsl2583_set_als_gain(chip);
break;
}
}
}
break;
case IIO_CHAN_INFO_INT_TIME:
if (chan->type == IIO_LIGHT && !val && val2 >= 50 &&
val2 <= 650 && !(val2 % 50)) {
chip->als_settings.als_time = val2;
ret = tsl2583_set_als_time(chip);
}
break;
default:
break;
}
mutex_unlock(&chip->als_mutex);
if (ret < 0)
return ret;
ret = tsl2583_set_pm_runtime_busy(chip, false);
if (ret < 0)
return ret;
return ret;
}
static int tsl2583_probe(struct i2c_client *clientp,
const struct i2c_device_id *idp)
{
int ret;
struct tsl2583_chip *chip;
struct iio_dev *indio_dev;
if (!i2c_check_functionality(clientp->adapter,
I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&clientp->dev, "%s: i2c smbus byte data functionality is unsupported\n",
__func__);
return -EOPNOTSUPP;
}
indio_dev = devm_iio_device_alloc(&clientp->dev, sizeof(*chip));
if (!indio_dev)
return -ENOMEM;
chip = iio_priv(indio_dev);
chip->client = clientp;
i2c_set_clientdata(clientp, indio_dev);
mutex_init(&chip->als_mutex);
ret = i2c_smbus_read_byte_data(clientp,
TSL2583_CMD_REG | TSL2583_CHIPID);
if (ret < 0) {
dev_err(&clientp->dev,
"%s: failed to read the chip ID register\n", __func__);
return ret;
}
if ((ret & TSL2583_CHIP_ID_MASK) != TSL2583_CHIP_ID) {
dev_err(&clientp->dev, "%s: received an unknown chip ID %x\n",
__func__, ret);
return -EINVAL;
}
indio_dev->info = &tsl2583_info;
indio_dev->channels = tsl2583_channels;
indio_dev->num_channels = ARRAY_SIZE(tsl2583_channels);
indio_dev->dev.parent = &clientp->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->name = chip->client->name;
pm_runtime_enable(&clientp->dev);
pm_runtime_set_autosuspend_delay(&clientp->dev,
TSL2583_POWER_OFF_DELAY_MS);
pm_runtime_use_autosuspend(&clientp->dev);
ret = devm_iio_device_register(indio_dev->dev.parent, indio_dev);
if (ret) {
dev_err(&clientp->dev, "%s: iio registration failed\n",
__func__);
return ret;
}
tsl2583_defaults(chip);
dev_info(&clientp->dev, "Light sensor found.\n");
return 0;
}
static int tsl2583_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct tsl2583_chip *chip = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
return tsl2583_set_power_state(chip, TSL2583_CNTL_PWR_OFF);
}
static int __maybe_unused tsl2583_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct tsl2583_chip *chip = iio_priv(indio_dev);
int ret;
mutex_lock(&chip->als_mutex);
ret = tsl2583_set_power_state(chip, TSL2583_CNTL_PWR_OFF);
mutex_unlock(&chip->als_mutex);
return ret;
}
static int __maybe_unused tsl2583_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct tsl2583_chip *chip = iio_priv(indio_dev);
int ret;
mutex_lock(&chip->als_mutex);
ret = tsl2583_chip_init_and_power_on(indio_dev);
mutex_unlock(&chip->als_mutex);
return ret;
}
