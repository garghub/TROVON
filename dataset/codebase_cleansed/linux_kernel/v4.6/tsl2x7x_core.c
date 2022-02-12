static int
tsl2x7x_i2c_read(struct i2c_client *client, u8 reg, u8 *val)
{
int ret;
ret = i2c_smbus_write_byte(client, (TSL2X7X_CMD_REG | reg));
if (ret < 0) {
dev_err(&client->dev, "failed to write register %x\n", reg);
return ret;
}
ret = i2c_smbus_read_byte(client);
if (ret >= 0)
*val = (u8)ret;
else
dev_err(&client->dev, "failed to read register %x\n", reg);
return ret;
}
static int tsl2x7x_get_lux(struct iio_dev *indio_dev)
{
u16 ch0, ch1;
u32 lux;
u64 lux64;
u32 ratio;
u8 buf[4];
struct tsl2x7x_lux *p;
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
int i, ret;
u32 ch0lux = 0;
u32 ch1lux = 0;
if (mutex_trylock(&chip->als_mutex) == 0)
return chip->als_cur_info.lux;
if (chip->tsl2x7x_chip_status != TSL2X7X_CHIP_WORKING) {
dev_err(&chip->client->dev, "%s: device is not enabled\n",
__func__);
ret = -EBUSY;
goto out_unlock;
}
ret = tsl2x7x_i2c_read(chip->client,
(TSL2X7X_CMD_REG | TSL2X7X_STATUS), &buf[0]);
if (ret < 0) {
dev_err(&chip->client->dev,
"%s: Failed to read STATUS Reg\n", __func__);
goto out_unlock;
}
if (!(buf[0] & TSL2X7X_STA_ADC_VALID)) {
dev_err(&chip->client->dev,
"%s: data not valid yet\n", __func__);
ret = chip->als_cur_info.lux;
goto out_unlock;
}
for (i = 0; i < 4; i++) {
ret = tsl2x7x_i2c_read(chip->client,
(TSL2X7X_CMD_REG | (TSL2X7X_ALS_CHAN0LO + i)),
&buf[i]);
if (ret < 0) {
dev_err(&chip->client->dev,
"failed to read. err=%x\n", ret);
goto out_unlock;
}
}
ret = i2c_smbus_write_byte(chip->client,
(TSL2X7X_CMD_REG |
TSL2X7X_CMD_SPL_FN |
TSL2X7X_CMD_ALS_INT_CLR));
if (ret < 0) {
dev_err(&chip->client->dev,
"i2c_write_command failed - err = %d\n", ret);
goto out_unlock;
}
ch0 = le16_to_cpup((const __le16 *)&buf[0]);
ch1 = le16_to_cpup((const __le16 *)&buf[2]);
chip->als_cur_info.als_ch0 = ch0;
chip->als_cur_info.als_ch1 = ch1;
if ((ch0 >= chip->als_saturation) || (ch1 >= chip->als_saturation)) {
lux = TSL2X7X_LUX_CALC_OVER_FLOW;
goto return_max;
}
if (!ch0) {
ret = chip->als_cur_info.lux;
goto out_unlock;
}
ratio = (ch1 << 15) / ch0;
p = (struct tsl2x7x_lux *) chip->tsl2x7x_device_lux;
while (p->ratio != 0 && p->ratio < ratio)
p++;
if (p->ratio == 0) {
lux = 0;
} else {
ch0lux = DIV_ROUND_UP(ch0 * p->ch0,
tsl2X7X_als_gainadj[chip->tsl2x7x_settings.als_gain]);
ch1lux = DIV_ROUND_UP(ch1 * p->ch1,
tsl2X7X_als_gainadj[chip->tsl2x7x_settings.als_gain]);
lux = ch0lux - ch1lux;
}
if (ch1lux > ch0lux) {
dev_dbg(&chip->client->dev, "ch1lux > ch0lux-return last value\n");
ret = chip->als_cur_info.lux;
goto out_unlock;
}
if (chip->als_time_scale == 0)
lux = 0;
else
lux = (lux + (chip->als_time_scale >> 1)) /
chip->als_time_scale;
lux64 = lux;
lux64 = lux64 * chip->tsl2x7x_settings.als_gain_trim;
lux64 >>= 8;
lux = lux64;
lux = (lux + 500) / 1000;
if (lux > TSL2X7X_LUX_CALC_OVER_FLOW)
lux = TSL2X7X_LUX_CALC_OVER_FLOW;
return_max:
chip->als_cur_info.lux = lux;
ret = lux;
out_unlock:
mutex_unlock(&chip->als_mutex);
return ret;
}
static int tsl2x7x_get_prox(struct iio_dev *indio_dev)
{
int i;
int ret;
u8 status;
u8 chdata[2];
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
if (mutex_trylock(&chip->prox_mutex) == 0) {
dev_err(&chip->client->dev,
"%s: Can't get prox mutex\n", __func__);
return -EBUSY;
}
ret = tsl2x7x_i2c_read(chip->client,
(TSL2X7X_CMD_REG | TSL2X7X_STATUS), &status);
if (ret < 0) {
dev_err(&chip->client->dev, "i2c err=%d\n", ret);
goto prox_poll_err;
}
switch (chip->id) {
case tsl2571:
case tsl2671:
case tmd2671:
case tsl2771:
case tmd2771:
if (!(status & TSL2X7X_STA_ADC_VALID))
goto prox_poll_err;
break;
case tsl2572:
case tsl2672:
case tmd2672:
case tsl2772:
case tmd2772:
if (!(status & TSL2X7X_STA_PRX_VALID))
goto prox_poll_err;
break;
}
for (i = 0; i < 2; i++) {
ret = tsl2x7x_i2c_read(chip->client,
(TSL2X7X_CMD_REG |
(TSL2X7X_PRX_LO + i)), &chdata[i]);
if (ret < 0)
goto prox_poll_err;
}
chip->prox_data =
le16_to_cpup((const __le16 *)&chdata[0]);
prox_poll_err:
mutex_unlock(&chip->prox_mutex);
return chip->prox_data;
}
static void tsl2x7x_defaults(struct tsl2X7X_chip *chip)
{
if (chip->pdata && chip->pdata->platform_default_settings)
memcpy(&(chip->tsl2x7x_settings),
chip->pdata->platform_default_settings,
sizeof(tsl2x7x_default_settings));
else
memcpy(&(chip->tsl2x7x_settings),
&tsl2x7x_default_settings,
sizeof(tsl2x7x_default_settings));
if (chip->pdata && chip->pdata->platform_lux_table[0].ratio != 0)
memcpy(chip->tsl2x7x_device_lux,
chip->pdata->platform_lux_table,
sizeof(chip->pdata->platform_lux_table));
else
memcpy(chip->tsl2x7x_device_lux,
(struct tsl2x7x_lux *)tsl2x7x_default_lux_table_group[chip->id],
MAX_DEFAULT_TABLE_BYTES);
}
static int tsl2x7x_als_calibrate(struct iio_dev *indio_dev)
{
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
u8 reg_val;
int gain_trim_val;
int ret;
int lux_val;
ret = i2c_smbus_write_byte(chip->client,
(TSL2X7X_CMD_REG | TSL2X7X_CNTRL));
if (ret < 0) {
dev_err(&chip->client->dev,
"failed to write CNTRL register, ret=%d\n", ret);
return ret;
}
reg_val = i2c_smbus_read_byte(chip->client);
if ((reg_val & (TSL2X7X_CNTL_ADC_ENBL | TSL2X7X_CNTL_PWR_ON))
!= (TSL2X7X_CNTL_ADC_ENBL | TSL2X7X_CNTL_PWR_ON)) {
dev_err(&chip->client->dev,
"%s: failed: ADC not enabled\n", __func__);
return -1;
}
ret = i2c_smbus_write_byte(chip->client,
(TSL2X7X_CMD_REG | TSL2X7X_CNTRL));
if (ret < 0) {
dev_err(&chip->client->dev,
"failed to write ctrl reg: ret=%d\n", ret);
return ret;
}
reg_val = i2c_smbus_read_byte(chip->client);
if ((reg_val & TSL2X7X_STA_ADC_VALID) != TSL2X7X_STA_ADC_VALID) {
dev_err(&chip->client->dev,
"%s: failed: STATUS - ADC not valid.\n", __func__);
return -ENODATA;
}
lux_val = tsl2x7x_get_lux(indio_dev);
if (lux_val < 0) {
dev_err(&chip->client->dev,
"%s: failed to get lux\n", __func__);
return lux_val;
}
gain_trim_val = ((chip->tsl2x7x_settings.als_cal_target)
* chip->tsl2x7x_settings.als_gain_trim) / lux_val;
if ((gain_trim_val < 250) || (gain_trim_val > 4000))
return -ERANGE;
chip->tsl2x7x_settings.als_gain_trim = gain_trim_val;
dev_info(&chip->client->dev,
"%s als_calibrate completed\n", chip->client->name);
return (int) gain_trim_val;
}
static int tsl2x7x_chip_on(struct iio_dev *indio_dev)
{
int i;
int ret = 0;
u8 *dev_reg;
u8 utmp;
int als_count;
int als_time;
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
u8 reg_val = 0;
if (chip->pdata && chip->pdata->power_on)
chip->pdata->power_on(indio_dev);
chip->tsl2x7x_config[TSL2X7X_PRX_TIME] =
chip->tsl2x7x_settings.prx_time;
chip->tsl2x7x_config[TSL2X7X_WAIT_TIME] =
chip->tsl2x7x_settings.wait_time;
chip->tsl2x7x_config[TSL2X7X_PRX_CONFIG] =
chip->tsl2x7x_settings.prox_config;
chip->tsl2x7x_config[TSL2X7X_ALS_MINTHRESHLO] =
(chip->tsl2x7x_settings.als_thresh_low) & 0xFF;
chip->tsl2x7x_config[TSL2X7X_ALS_MINTHRESHHI] =
(chip->tsl2x7x_settings.als_thresh_low >> 8) & 0xFF;
chip->tsl2x7x_config[TSL2X7X_ALS_MAXTHRESHLO] =
(chip->tsl2x7x_settings.als_thresh_high) & 0xFF;
chip->tsl2x7x_config[TSL2X7X_ALS_MAXTHRESHHI] =
(chip->tsl2x7x_settings.als_thresh_high >> 8) & 0xFF;
chip->tsl2x7x_config[TSL2X7X_PERSISTENCE] =
chip->tsl2x7x_settings.persistence;
chip->tsl2x7x_config[TSL2X7X_PRX_COUNT] =
chip->tsl2x7x_settings.prox_pulse_count;
chip->tsl2x7x_config[TSL2X7X_PRX_MINTHRESHLO] =
(chip->tsl2x7x_settings.prox_thres_low) & 0xFF;
chip->tsl2x7x_config[TSL2X7X_PRX_MINTHRESHHI] =
(chip->tsl2x7x_settings.prox_thres_low >> 8) & 0xFF;
chip->tsl2x7x_config[TSL2X7X_PRX_MAXTHRESHLO] =
(chip->tsl2x7x_settings.prox_thres_high) & 0xFF;
chip->tsl2x7x_config[TSL2X7X_PRX_MAXTHRESHHI] =
(chip->tsl2x7x_settings.prox_thres_high >> 8) & 0xFF;
if (chip->tsl2x7x_chip_status == TSL2X7X_CHIP_WORKING) {
dev_info(&chip->client->dev, "device is already enabled\n");
return -EINVAL;
}
als_count = (chip->tsl2x7x_settings.als_time * 100 + 135) / 270;
if (!als_count)
als_count = 1;
als_time = (als_count * 27 + 5) / 10;
chip->tsl2x7x_config[TSL2X7X_ALS_TIME] = 256 - als_count;
chip->tsl2x7x_config[TSL2X7X_GAIN] =
chip->tsl2x7x_settings.als_gain |
(TSL2X7X_mA100 | TSL2X7X_DIODE1)
| ((chip->tsl2x7x_settings.prox_gain) << 2);
chip->als_saturation = als_count * 922;
chip->als_time_scale = (als_time + 25) / 50;
utmp = TSL2X7X_CNTL_PWR_ON;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2X7X_CMD_REG | TSL2X7X_CNTRL, utmp);
if (ret < 0) {
dev_err(&chip->client->dev,
"%s: failed on CNTRL reg.\n", __func__);
return ret;
}
for (i = 0, dev_reg = chip->tsl2x7x_config;
i < TSL2X7X_MAX_CONFIG_REG; i++) {
ret = i2c_smbus_write_byte_data(chip->client,
TSL2X7X_CMD_REG + i, *dev_reg++);
if (ret < 0) {
dev_err(&chip->client->dev,
"failed on write to reg %d.\n", i);
return ret;
}
}
mdelay(3);
utmp = TSL2X7X_CNTL_PWR_ON |
TSL2X7X_CNTL_ADC_ENBL |
TSL2X7X_CNTL_PROX_DET_ENBL;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2X7X_CMD_REG | TSL2X7X_CNTRL, utmp);
if (ret < 0) {
dev_err(&chip->client->dev,
"%s: failed on 2nd CTRL reg.\n", __func__);
return ret;
}
chip->tsl2x7x_chip_status = TSL2X7X_CHIP_WORKING;
if (chip->tsl2x7x_settings.interrupts_en != 0) {
dev_info(&chip->client->dev, "Setting Up Interrupt(s)\n");
reg_val = TSL2X7X_CNTL_PWR_ON | TSL2X7X_CNTL_ADC_ENBL;
if ((chip->tsl2x7x_settings.interrupts_en == 0x20) ||
(chip->tsl2x7x_settings.interrupts_en == 0x30))
reg_val |= TSL2X7X_CNTL_PROX_DET_ENBL;
reg_val |= chip->tsl2x7x_settings.interrupts_en;
ret = i2c_smbus_write_byte_data(chip->client,
(TSL2X7X_CMD_REG | TSL2X7X_CNTRL), reg_val);
if (ret < 0)
dev_err(&chip->client->dev,
"%s: failed in tsl2x7x_IOCTL_INT_SET.\n",
__func__);
ret = i2c_smbus_write_byte(chip->client,
TSL2X7X_CMD_REG | TSL2X7X_CMD_SPL_FN |
TSL2X7X_CMD_PROXALS_INT_CLR);
if (ret < 0) {
dev_err(&chip->client->dev,
"%s: Failed to clear Int status\n",
__func__);
return ret;
}
}
return ret;
}
static int tsl2x7x_chip_off(struct iio_dev *indio_dev)
{
int ret;
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
chip->tsl2x7x_chip_status = TSL2X7X_CHIP_SUSPENDED;
ret = i2c_smbus_write_byte_data(chip->client,
TSL2X7X_CMD_REG | TSL2X7X_CNTRL, 0x00);
if (chip->pdata && chip->pdata->power_off)
chip->pdata->power_off(chip->client);
return ret;
}
static
int tsl2x7x_invoke_change(struct iio_dev *indio_dev)
{
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
int device_status = chip->tsl2x7x_chip_status;
mutex_lock(&chip->als_mutex);
mutex_lock(&chip->prox_mutex);
if (device_status == TSL2X7X_CHIP_WORKING)
tsl2x7x_chip_off(indio_dev);
tsl2x7x_chip_on(indio_dev);
if (device_status != TSL2X7X_CHIP_WORKING)
tsl2x7x_chip_off(indio_dev);
mutex_unlock(&chip->prox_mutex);
mutex_unlock(&chip->als_mutex);
return 0;
}
static
void tsl2x7x_prox_calculate(int *data, int length,
struct tsl2x7x_prox_stat *statP)
{
int i;
int sample_sum;
int tmp;
if (!length)
length = 1;
sample_sum = 0;
statP->min = INT_MAX;
statP->max = INT_MIN;
for (i = 0; i < length; i++) {
sample_sum += data[i];
statP->min = min(statP->min, data[i]);
statP->max = max(statP->max, data[i]);
}
statP->mean = sample_sum / length;
sample_sum = 0;
for (i = 0; i < length; i++) {
tmp = data[i] - statP->mean;
sample_sum += tmp * tmp;
}
statP->stddev = int_sqrt((long)sample_sum)/length;
}
static void tsl2x7x_prox_cal(struct iio_dev *indio_dev)
{
int prox_history[MAX_SAMPLES_CAL + 1];
int i;
struct tsl2x7x_prox_stat prox_stat_data[2];
struct tsl2x7x_prox_stat *calP;
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
u8 tmp_irq_settings;
u8 current_state = chip->tsl2x7x_chip_status;
if (chip->tsl2x7x_settings.prox_max_samples_cal > MAX_SAMPLES_CAL) {
dev_err(&chip->client->dev,
"max prox samples cal is too big: %d\n",
chip->tsl2x7x_settings.prox_max_samples_cal);
chip->tsl2x7x_settings.prox_max_samples_cal = MAX_SAMPLES_CAL;
}
tsl2x7x_chip_off(indio_dev);
tmp_irq_settings = chip->tsl2x7x_settings.interrupts_en;
chip->tsl2x7x_settings.interrupts_en |= TSL2X7X_CNTL_PROX_INT_ENBL;
tsl2x7x_chip_on(indio_dev);
for (i = 0; i < chip->tsl2x7x_settings.prox_max_samples_cal; i++) {
mdelay(15);
tsl2x7x_get_prox(indio_dev);
prox_history[i] = chip->prox_data;
dev_info(&chip->client->dev, "2 i=%d prox data= %d\n",
i, chip->prox_data);
}
tsl2x7x_chip_off(indio_dev);
calP = &prox_stat_data[PROX_STAT_CAL];
tsl2x7x_prox_calculate(prox_history,
chip->tsl2x7x_settings.prox_max_samples_cal, calP);
chip->tsl2x7x_settings.prox_thres_high = (calP->max << 1) - calP->mean;
dev_info(&chip->client->dev, " cal min=%d mean=%d max=%d\n",
calP->min, calP->mean, calP->max);
dev_info(&chip->client->dev,
"%s proximity threshold set to %d\n",
chip->client->name, chip->tsl2x7x_settings.prox_thres_high);
chip->tsl2x7x_settings.interrupts_en = tmp_irq_settings;
if (current_state == TSL2X7X_CHIP_WORKING)
tsl2x7x_chip_on(indio_dev);
}
static ssize_t tsl2x7x_power_state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tsl2X7X_chip *chip = iio_priv(dev_to_iio_dev(dev));
return snprintf(buf, PAGE_SIZE, "%d\n", chip->tsl2x7x_chip_status);
}
static ssize_t tsl2x7x_power_state_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
bool value;
if (strtobool(buf, &value))
return -EINVAL;
if (value)
tsl2x7x_chip_on(indio_dev);
else
tsl2x7x_chip_off(indio_dev);
return len;
}
static ssize_t tsl2x7x_gain_available_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tsl2X7X_chip *chip = iio_priv(dev_to_iio_dev(dev));
switch (chip->id) {
case tsl2571:
case tsl2671:
case tmd2671:
case tsl2771:
case tmd2771:
return snprintf(buf, PAGE_SIZE, "%s\n", "1 8 16 128");
}
return snprintf(buf, PAGE_SIZE, "%s\n", "1 8 16 120");
}
static ssize_t tsl2x7x_prox_gain_available_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", "1 2 4 8");
}
static ssize_t tsl2x7x_als_time_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tsl2X7X_chip *chip = iio_priv(dev_to_iio_dev(dev));
int y, z;
y = (TSL2X7X_MAX_TIMER_CNT - (u8)chip->tsl2x7x_settings.als_time) + 1;
z = y * TSL2X7X_MIN_ITIME;
y /= 1000;
z %= 1000;
return snprintf(buf, PAGE_SIZE, "%d.%03d\n", y, z);
}
static ssize_t tsl2x7x_als_time_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
struct tsl2x7x_parse_result result;
int ret;
ret = iio_str_to_fixpoint(buf, 100, &result.integer, &result.fract);
if (ret)
return ret;
result.fract /= 3;
chip->tsl2x7x_settings.als_time =
TSL2X7X_MAX_TIMER_CNT - (u8)result.fract;
dev_info(&chip->client->dev, "%s: als time = %d",
__func__, chip->tsl2x7x_settings.als_time);
tsl2x7x_invoke_change(indio_dev);
return IIO_VAL_INT_PLUS_MICRO;
}
static ssize_t tsl2x7x_als_cal_target_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tsl2X7X_chip *chip = iio_priv(dev_to_iio_dev(dev));
return snprintf(buf, PAGE_SIZE, "%d\n",
chip->tsl2x7x_settings.als_cal_target);
}
static ssize_t tsl2x7x_als_cal_target_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
unsigned long value;
if (kstrtoul(buf, 0, &value))
return -EINVAL;
if (value)
chip->tsl2x7x_settings.als_cal_target = value;
tsl2x7x_invoke_change(indio_dev);
return len;
}
static ssize_t tsl2x7x_als_persistence_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tsl2X7X_chip *chip = iio_priv(dev_to_iio_dev(dev));
int y, z, filter_delay;
y = (TSL2X7X_MAX_TIMER_CNT - (u8)chip->tsl2x7x_settings.als_time) + 1;
z = y * TSL2X7X_MIN_ITIME;
filter_delay = z * (chip->tsl2x7x_settings.persistence & 0x0F);
y = filter_delay / 1000;
z = filter_delay % 1000;
return snprintf(buf, PAGE_SIZE, "%d.%03d\n", y, z);
}
static ssize_t tsl2x7x_als_persistence_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
struct tsl2x7x_parse_result result;
int y, z, filter_delay;
int ret;
ret = iio_str_to_fixpoint(buf, 100, &result.integer, &result.fract);
if (ret)
return ret;
y = (TSL2X7X_MAX_TIMER_CNT - (u8)chip->tsl2x7x_settings.als_time) + 1;
z = y * TSL2X7X_MIN_ITIME;
filter_delay =
DIV_ROUND_UP((result.integer * 1000) + result.fract, z);
chip->tsl2x7x_settings.persistence &= 0xF0;
chip->tsl2x7x_settings.persistence |= (filter_delay & 0x0F);
dev_info(&chip->client->dev, "%s: als persistence = %d",
__func__, filter_delay);
tsl2x7x_invoke_change(indio_dev);
return IIO_VAL_INT_PLUS_MICRO;
}
static ssize_t tsl2x7x_prox_persistence_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tsl2X7X_chip *chip = iio_priv(dev_to_iio_dev(dev));
int y, z, filter_delay;
y = (TSL2X7X_MAX_TIMER_CNT - (u8)chip->tsl2x7x_settings.prx_time) + 1;
z = y * TSL2X7X_MIN_ITIME;
filter_delay = z * ((chip->tsl2x7x_settings.persistence & 0xF0) >> 4);
y = filter_delay / 1000;
z = filter_delay % 1000;
return snprintf(buf, PAGE_SIZE, "%d.%03d\n", y, z);
}
static ssize_t tsl2x7x_prox_persistence_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
struct tsl2x7x_parse_result result;
int y, z, filter_delay;
int ret;
ret = iio_str_to_fixpoint(buf, 100, &result.integer, &result.fract);
if (ret)
return ret;
y = (TSL2X7X_MAX_TIMER_CNT - (u8)chip->tsl2x7x_settings.prx_time) + 1;
z = y * TSL2X7X_MIN_ITIME;
filter_delay =
DIV_ROUND_UP((result.integer * 1000) + result.fract, z);
chip->tsl2x7x_settings.persistence &= 0x0F;
chip->tsl2x7x_settings.persistence |= ((filter_delay << 4) & 0xF0);
dev_info(&chip->client->dev, "%s: prox persistence = %d",
__func__, filter_delay);
tsl2x7x_invoke_change(indio_dev);
return IIO_VAL_INT_PLUS_MICRO;
}
static ssize_t tsl2x7x_do_calibrate(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
bool value;
if (strtobool(buf, &value))
return -EINVAL;
if (value)
tsl2x7x_als_calibrate(indio_dev);
tsl2x7x_invoke_change(indio_dev);
return len;
}
static ssize_t tsl2x7x_luxtable_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tsl2X7X_chip *chip = iio_priv(dev_to_iio_dev(dev));
int i = 0;
int offset = 0;
while (i < (TSL2X7X_MAX_LUX_TABLE_SIZE * 3)) {
offset += snprintf(buf + offset, PAGE_SIZE, "%u,%u,%u,",
chip->tsl2x7x_device_lux[i].ratio,
chip->tsl2x7x_device_lux[i].ch0,
chip->tsl2x7x_device_lux[i].ch1);
if (chip->tsl2x7x_device_lux[i].ratio == 0) {
offset--;
break;
}
i++;
}
offset += snprintf(buf + offset, PAGE_SIZE, "\n");
return offset;
}
static ssize_t tsl2x7x_luxtable_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
int value[ARRAY_SIZE(chip->tsl2x7x_device_lux)*3 + 1];
int n;
get_options(buf, ARRAY_SIZE(value), value);
n = value[0];
if ((n % 3) || n < 6 ||
n > ((ARRAY_SIZE(chip->tsl2x7x_device_lux) - 1) * 3)) {
dev_info(dev, "LUX TABLE INPUT ERROR 1 Value[0]=%d\n", n);
return -EINVAL;
}
if ((value[(n - 2)] | value[(n - 1)] | value[n]) != 0) {
dev_info(dev, "LUX TABLE INPUT ERROR 2 Value[0]=%d\n", n);
return -EINVAL;
}
if (chip->tsl2x7x_chip_status == TSL2X7X_CHIP_WORKING)
tsl2x7x_chip_off(indio_dev);
memset(chip->tsl2x7x_device_lux, 0, sizeof(chip->tsl2x7x_device_lux));
memcpy(chip->tsl2x7x_device_lux, &value[1], (value[0] * 4));
tsl2x7x_invoke_change(indio_dev);
return len;
}
static ssize_t tsl2x7x_do_prox_calibrate(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
bool value;
if (strtobool(buf, &value))
return -EINVAL;
if (value)
tsl2x7x_prox_cal(indio_dev);
tsl2x7x_invoke_change(indio_dev);
return len;
}
static int tsl2x7x_read_interrupt_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
int ret;
if (chan->type == IIO_INTENSITY)
ret = !!(chip->tsl2x7x_settings.interrupts_en & 0x10);
else
ret = !!(chip->tsl2x7x_settings.interrupts_en & 0x20);
return ret;
}
static int tsl2x7x_write_interrupt_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int val)
{
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
if (chan->type == IIO_INTENSITY) {
if (val)
chip->tsl2x7x_settings.interrupts_en |= 0x10;
else
chip->tsl2x7x_settings.interrupts_en &= 0x20;
} else {
if (val)
chip->tsl2x7x_settings.interrupts_en |= 0x20;
else
chip->tsl2x7x_settings.interrupts_en &= 0x10;
}
tsl2x7x_invoke_change(indio_dev);
return 0;
}
static int tsl2x7x_write_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
if (chan->type == IIO_INTENSITY) {
switch (dir) {
case IIO_EV_DIR_RISING:
chip->tsl2x7x_settings.als_thresh_high = val;
break;
case IIO_EV_DIR_FALLING:
chip->tsl2x7x_settings.als_thresh_low = val;
break;
default:
return -EINVAL;
}
} else {
switch (dir) {
case IIO_EV_DIR_RISING:
chip->tsl2x7x_settings.prox_thres_high = val;
break;
case IIO_EV_DIR_FALLING:
chip->tsl2x7x_settings.prox_thres_low = val;
break;
default:
return -EINVAL;
}
}
tsl2x7x_invoke_change(indio_dev);
return 0;
}
static int tsl2x7x_read_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
if (chan->type == IIO_INTENSITY) {
switch (dir) {
case IIO_EV_DIR_RISING:
*val = chip->tsl2x7x_settings.als_thresh_high;
break;
case IIO_EV_DIR_FALLING:
*val = chip->tsl2x7x_settings.als_thresh_low;
break;
default:
return -EINVAL;
}
} else {
switch (dir) {
case IIO_EV_DIR_RISING:
*val = chip->tsl2x7x_settings.prox_thres_high;
break;
case IIO_EV_DIR_FALLING:
*val = chip->tsl2x7x_settings.prox_thres_low;
break;
default:
return -EINVAL;
}
}
return IIO_VAL_INT;
}
static int tsl2x7x_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
int ret = -EINVAL;
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
switch (chan->type) {
case IIO_LIGHT:
tsl2x7x_get_lux(indio_dev);
*val = chip->als_cur_info.lux;
ret = IIO_VAL_INT;
break;
default:
return -EINVAL;
}
break;
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_INTENSITY:
tsl2x7x_get_lux(indio_dev);
if (chan->channel == 0)
*val = chip->als_cur_info.als_ch0;
else
*val = chip->als_cur_info.als_ch1;
ret = IIO_VAL_INT;
break;
case IIO_PROXIMITY:
tsl2x7x_get_prox(indio_dev);
*val = chip->prox_data;
ret = IIO_VAL_INT;
break;
default:
return -EINVAL;
}
break;
case IIO_CHAN_INFO_CALIBSCALE:
if (chan->type == IIO_LIGHT)
*val =
tsl2X7X_als_gainadj[chip->tsl2x7x_settings.als_gain];
else
*val =
tsl2X7X_prx_gainadj[chip->tsl2x7x_settings.prox_gain];
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_CALIBBIAS:
*val = chip->tsl2x7x_settings.als_gain_trim;
ret = IIO_VAL_INT;
break;
default:
ret = -EINVAL;
}
return ret;
}
static int tsl2x7x_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_CALIBSCALE:
if (chan->type == IIO_INTENSITY) {
switch (val) {
case 1:
chip->tsl2x7x_settings.als_gain = 0;
break;
case 8:
chip->tsl2x7x_settings.als_gain = 1;
break;
case 16:
chip->tsl2x7x_settings.als_gain = 2;
break;
case 120:
switch (chip->id) {
case tsl2572:
case tsl2672:
case tmd2672:
case tsl2772:
case tmd2772:
return -EINVAL;
}
chip->tsl2x7x_settings.als_gain = 3;
break;
case 128:
switch (chip->id) {
case tsl2571:
case tsl2671:
case tmd2671:
case tsl2771:
case tmd2771:
return -EINVAL;
}
chip->tsl2x7x_settings.als_gain = 3;
break;
default:
return -EINVAL;
}
} else {
switch (val) {
case 1:
chip->tsl2x7x_settings.prox_gain = 0;
break;
case 2:
chip->tsl2x7x_settings.prox_gain = 1;
break;
case 4:
chip->tsl2x7x_settings.prox_gain = 2;
break;
case 8:
chip->tsl2x7x_settings.prox_gain = 3;
break;
default:
return -EINVAL;
}
}
break;
case IIO_CHAN_INFO_CALIBBIAS:
chip->tsl2x7x_settings.als_gain_trim = val;
break;
default:
return -EINVAL;
}
tsl2x7x_invoke_change(indio_dev);
return 0;
}
static int tsl2x7x_device_id(unsigned char *id, int target)
{
switch (target) {
case tsl2571:
case tsl2671:
case tsl2771:
return (*id & 0xf0) == TRITON_ID;
case tmd2671:
case tmd2771:
return (*id & 0xf0) == HALIBUT_ID;
case tsl2572:
case tsl2672:
case tmd2672:
case tsl2772:
case tmd2772:
return (*id & 0xf0) == SWORDFISH_ID;
}
return -EINVAL;
}
static irqreturn_t tsl2x7x_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
s64 timestamp = iio_get_time_ns();
int ret;
u8 value;
value = i2c_smbus_read_byte_data(chip->client,
TSL2X7X_CMD_REG | TSL2X7X_STATUS);
if (value & TSL2X7X_STA_PRX_INTR) {
tsl2x7x_get_prox(indio_dev);
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_PROXIMITY,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_EITHER),
timestamp);
}
if (value & TSL2X7X_STA_ALS_INTR) {
tsl2x7x_get_lux(indio_dev);
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_LIGHT,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_EITHER),
timestamp);
}
ret = i2c_smbus_write_byte(chip->client,
TSL2X7X_CMD_REG | TSL2X7X_CMD_SPL_FN |
TSL2X7X_CMD_PROXALS_INT_CLR);
if (ret < 0)
dev_err(&chip->client->dev,
"Failed to clear irq from event handler. err = %d\n",
ret);
return IRQ_HANDLED;
}
static int tsl2x7x_probe(struct i2c_client *clientp,
const struct i2c_device_id *id)
{
int ret;
unsigned char device_id;
struct iio_dev *indio_dev;
struct tsl2X7X_chip *chip;
indio_dev = devm_iio_device_alloc(&clientp->dev, sizeof(*chip));
if (!indio_dev)
return -ENOMEM;
chip = iio_priv(indio_dev);
chip->client = clientp;
i2c_set_clientdata(clientp, indio_dev);
ret = tsl2x7x_i2c_read(chip->client,
TSL2X7X_CHIPID, &device_id);
if (ret < 0)
return ret;
if ((!tsl2x7x_device_id(&device_id, id->driver_data)) ||
(tsl2x7x_device_id(&device_id, id->driver_data) == -EINVAL)) {
dev_info(&chip->client->dev,
"%s: i2c device found does not match expected id\n",
__func__);
return -EINVAL;
}
ret = i2c_smbus_write_byte(clientp, (TSL2X7X_CMD_REG | TSL2X7X_CNTRL));
if (ret < 0) {
dev_err(&clientp->dev, "write to cmd reg failed. err = %d\n",
ret);
return ret;
}
mutex_init(&chip->als_mutex);
mutex_init(&chip->prox_mutex);
chip->tsl2x7x_chip_status = TSL2X7X_CHIP_UNKNOWN;
chip->pdata = dev_get_platdata(&clientp->dev);
chip->id = id->driver_data;
chip->chip_info =
&tsl2x7x_chip_info_tbl[device_channel_config[id->driver_data]];
indio_dev->info = chip->chip_info->info;
indio_dev->dev.parent = &clientp->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->name = chip->client->name;
indio_dev->channels = chip->chip_info->channel;
indio_dev->num_channels = chip->chip_info->chan_table_elements;
if (clientp->irq) {
ret = devm_request_threaded_irq(&clientp->dev, clientp->irq,
NULL,
&tsl2x7x_event_handler,
IRQF_TRIGGER_RISING |
IRQF_ONESHOT,
"TSL2X7X_event",
indio_dev);
if (ret) {
dev_err(&clientp->dev,
"%s: irq request failed", __func__);
return ret;
}
}
tsl2x7x_defaults(chip);
tsl2x7x_chip_on(indio_dev);
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&clientp->dev,
"%s: iio registration failed\n", __func__);
return ret;
}
dev_info(&clientp->dev, "%s Light sensor found.\n", id->name);
return 0;
}
static int tsl2x7x_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
int ret = 0;
if (chip->tsl2x7x_chip_status == TSL2X7X_CHIP_WORKING) {
ret = tsl2x7x_chip_off(indio_dev);
chip->tsl2x7x_chip_status = TSL2X7X_CHIP_SUSPENDED;
}
if (chip->pdata && chip->pdata->platform_power) {
pm_message_t pmm = {PM_EVENT_SUSPEND};
chip->pdata->platform_power(dev, pmm);
}
return ret;
}
static int tsl2x7x_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct tsl2X7X_chip *chip = iio_priv(indio_dev);
int ret = 0;
if (chip->pdata && chip->pdata->platform_power) {
pm_message_t pmm = {PM_EVENT_RESUME};
chip->pdata->platform_power(dev, pmm);
}
if (chip->tsl2x7x_chip_status == TSL2X7X_CHIP_SUSPENDED)
ret = tsl2x7x_chip_on(indio_dev);
return ret;
}
static int tsl2x7x_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
tsl2x7x_chip_off(indio_dev);
iio_device_unregister(indio_dev);
return 0;
}
