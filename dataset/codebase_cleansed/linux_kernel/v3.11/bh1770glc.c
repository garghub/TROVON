static inline int bh1770_lux_interrupt_control(struct bh1770_chip *chip,
int lux)
{
chip->int_mode_lux = lux;
return i2c_smbus_write_byte_data(chip->client,
BH1770_INTERRUPT,
(lux << 1) | chip->int_mode_prox);
}
static inline int bh1770_prox_interrupt_control(struct bh1770_chip *chip,
int ps)
{
chip->int_mode_prox = ps;
return i2c_smbus_write_byte_data(chip->client,
BH1770_INTERRUPT,
(chip->int_mode_lux << 1) | (ps << 0));
}
static int bh1770_lux_rate(struct bh1770_chip *chip, int rate_index)
{
if (pm_runtime_suspended(&chip->client->dev))
return 0;
if (chip->prox_enable_count)
rate_index = 0;
return i2c_smbus_write_byte_data(chip->client,
BH1770_ALS_MEAS_RATE,
rate_index);
}
static int bh1770_prox_rate(struct bh1770_chip *chip, int mode)
{
int rate;
rate = (mode == PROX_ABOVE_THRESHOLD) ?
chip->prox_rate_threshold : chip->prox_rate;
return i2c_smbus_write_byte_data(chip->client,
BH1770_PS_MEAS_RATE,
rate);
}
static inline int bh1770_led_cfg(struct bh1770_chip *chip)
{
return i2c_smbus_write_byte_data(chip->client,
BH1770_I_LED,
(BH1770_LED1 << 6) |
(BH1770_LED_5mA << 3) |
chip->prox_led);
}
static inline u8 bh1770_psraw_to_adjusted(struct bh1770_chip *chip, u8 psraw)
{
u16 adjusted;
adjusted = (u16)(((u32)(psraw + chip->prox_const) * chip->prox_coef) /
BH1770_COEF_SCALER);
if (adjusted > BH1770_PROX_RANGE)
adjusted = BH1770_PROX_RANGE;
return adjusted;
}
static inline u8 bh1770_psadjusted_to_raw(struct bh1770_chip *chip, u8 ps)
{
u16 raw;
raw = (((u32)ps * BH1770_COEF_SCALER) / chip->prox_coef);
if (raw > chip->prox_const)
raw = raw - chip->prox_const;
else
raw = 0;
return raw;
}
static int bh1770_prox_set_threshold(struct bh1770_chip *chip)
{
u8 tmp = 0;
if (pm_runtime_suspended(&chip->client->dev))
return 0;
tmp = bh1770_psadjusted_to_raw(chip, chip->prox_threshold);
chip->prox_threshold_hw = tmp;
return i2c_smbus_write_byte_data(chip->client, BH1770_PS_TH_LED1,
tmp);
}
static inline u16 bh1770_lux_raw_to_adjusted(struct bh1770_chip *chip, u16 raw)
{
u32 lux;
lux = ((u32)raw * chip->lux_corr) / BH1770_LUX_CORR_SCALE;
return min(lux, (u32)BH1770_LUX_RANGE);
}
static inline u16 bh1770_lux_adjusted_to_raw(struct bh1770_chip *chip,
u16 adjusted)
{
return (u32)adjusted * BH1770_LUX_CORR_SCALE / chip->lux_corr;
}
static int bh1770_lux_update_thresholds(struct bh1770_chip *chip,
u16 threshold_hi, u16 threshold_lo)
{
u8 data[4];
int ret;
if (pm_runtime_suspended(&chip->client->dev))
return 0;
if (threshold_hi != BH1770_LUX_RANGE && threshold_hi != 0)
threshold_hi = bh1770_lux_adjusted_to_raw(chip, threshold_hi);
if (threshold_lo != BH1770_LUX_RANGE && threshold_lo != 0)
threshold_lo = bh1770_lux_adjusted_to_raw(chip, threshold_lo);
if (chip->lux_thres_hi_onchip == threshold_hi &&
chip->lux_thres_lo_onchip == threshold_lo)
return 0;
chip->lux_thres_hi_onchip = threshold_hi;
chip->lux_thres_lo_onchip = threshold_lo;
data[0] = threshold_hi;
data[1] = threshold_hi >> 8;
data[2] = threshold_lo;
data[3] = threshold_lo >> 8;
ret = i2c_smbus_write_i2c_block_data(chip->client,
BH1770_ALS_TH_UP_0,
ARRAY_SIZE(data),
data);
return ret;
}
static int bh1770_lux_get_result(struct bh1770_chip *chip)
{
u16 data;
int ret;
ret = i2c_smbus_read_byte_data(chip->client, BH1770_ALS_DATA_0);
if (ret < 0)
return ret;
data = ret & 0xff;
ret = i2c_smbus_read_byte_data(chip->client, BH1770_ALS_DATA_1);
if (ret < 0)
return ret;
chip->lux_data_raw = data | ((ret & 0xff) << 8);
return 0;
}
static u32 bh1770_get_corr_value(struct bh1770_chip *chip)
{
u32 tmp;
tmp = (BH1770_LUX_CORR_SCALE * chip->lux_ga) / BH1770_LUX_GA_SCALE;
tmp = (tmp * chip->lux_cf) / BH1770_LUX_CF_SCALE;
tmp = (tmp * chip->lux_calib) / BH1770_CALIB_SCALER;
return tmp;
}
static int bh1770_lux_read_result(struct bh1770_chip *chip)
{
bh1770_lux_get_result(chip);
return bh1770_lux_raw_to_adjusted(chip, chip->lux_data_raw);
}
static int bh1770_chip_on(struct bh1770_chip *chip)
{
int ret = regulator_bulk_enable(ARRAY_SIZE(chip->regs),
chip->regs);
if (ret < 0)
return ret;
usleep_range(BH1770_STARTUP_DELAY, BH1770_STARTUP_DELAY * 2);
i2c_smbus_write_byte_data(chip->client, BH1770_ALS_CONTROL,
BH1770_SWRESET);
usleep_range(BH1770_RESET_TIME, BH1770_RESET_TIME * 2);
chip->lux_data_raw = 0;
chip->prox_data = 0;
ret = i2c_smbus_write_byte_data(chip->client,
BH1770_ALS_CONTROL, BH1770_STANDALONE);
chip->lux_thres_hi_onchip = BH1770_LUX_RANGE;
chip->lux_thres_lo_onchip = 0;
return ret;
}
static void bh1770_chip_off(struct bh1770_chip *chip)
{
i2c_smbus_write_byte_data(chip->client,
BH1770_INTERRUPT, BH1770_DISABLE);
i2c_smbus_write_byte_data(chip->client,
BH1770_ALS_CONTROL, BH1770_STANDBY);
i2c_smbus_write_byte_data(chip->client,
BH1770_PS_CONTROL, BH1770_STANDBY);
regulator_bulk_disable(ARRAY_SIZE(chip->regs), chip->regs);
}
static int bh1770_prox_mode_control(struct bh1770_chip *chip)
{
if (chip->prox_enable_count) {
chip->prox_force_update = true;
bh1770_lux_rate(chip, chip->lux_rate_index);
bh1770_prox_set_threshold(chip);
bh1770_led_cfg(chip);
bh1770_prox_rate(chip, PROX_BELOW_THRESHOLD);
bh1770_prox_interrupt_control(chip, BH1770_ENABLE);
i2c_smbus_write_byte_data(chip->client,
BH1770_PS_CONTROL, BH1770_STANDALONE);
} else {
chip->prox_data = 0;
bh1770_lux_rate(chip, chip->lux_rate_index);
bh1770_prox_interrupt_control(chip, BH1770_DISABLE);
i2c_smbus_write_byte_data(chip->client,
BH1770_PS_CONTROL, BH1770_STANDBY);
}
return 0;
}
static int bh1770_prox_read_result(struct bh1770_chip *chip)
{
int ret;
bool above;
u8 mode;
ret = i2c_smbus_read_byte_data(chip->client, BH1770_PS_DATA_LED1);
if (ret < 0)
goto out;
if (ret > chip->prox_threshold_hw)
above = true;
else
above = false;
if (chip->lux_data_raw > PROX_IGNORE_LUX_LIMIT)
ret = 0;
chip->prox_data = bh1770_psraw_to_adjusted(chip, ret);
if (chip->prox_data >= chip->prox_abs_thres ||
chip->prox_force_update)
chip->prox_persistence_counter = chip->prox_persistence;
chip->prox_force_update = false;
if (likely(above)) {
if (chip->prox_persistence_counter < chip->prox_persistence) {
chip->prox_persistence_counter++;
ret = -ENODATA;
} else {
mode = PROX_ABOVE_THRESHOLD;
ret = 0;
}
} else {
chip->prox_persistence_counter = 0;
mode = PROX_BELOW_THRESHOLD;
chip->prox_data = 0;
ret = 0;
}
if (ret == 0) {
bh1770_prox_rate(chip, mode);
sysfs_notify(&chip->client->dev.kobj, NULL, "prox0_raw");
}
out:
return ret;
}
static int bh1770_detect(struct bh1770_chip *chip)
{
struct i2c_client *client = chip->client;
s32 ret;
u8 manu, part;
ret = i2c_smbus_read_byte_data(client, BH1770_MANUFACT_ID);
if (ret < 0)
goto error;
manu = (u8)ret;
ret = i2c_smbus_read_byte_data(client, BH1770_PART_ID);
if (ret < 0)
goto error;
part = (u8)ret;
chip->revision = (part & BH1770_REV_MASK) >> BH1770_REV_SHIFT;
chip->prox_coef = BH1770_COEF_SCALER;
chip->prox_const = 0;
chip->lux_cf = BH1770_NEUTRAL_CF;
if ((manu == BH1770_MANUFACT_ROHM) &&
((part & BH1770_PART_MASK) == BH1770_PART)) {
snprintf(chip->chipname, sizeof(chip->chipname), "BH1770GLC");
return 0;
}
if ((manu == BH1770_MANUFACT_OSRAM) &&
((part & BH1770_PART_MASK) == BH1770_PART)) {
snprintf(chip->chipname, sizeof(chip->chipname), "SFH7770");
chip->prox_coef = 819;
chip->prox_const = 40;
return 0;
}
ret = -ENODEV;
error:
dev_dbg(&client->dev, "BH1770 or SFH7770 not found\n");
return ret;
}
static void bh1770_prox_work(struct work_struct *work)
{
struct bh1770_chip *chip =
container_of(work, struct bh1770_chip, prox_work.work);
mutex_lock(&chip->mutex);
bh1770_prox_read_result(chip);
mutex_unlock(&chip->mutex);
}
static irqreturn_t bh1770_irq(int irq, void *data)
{
struct bh1770_chip *chip = data;
int status;
int rate = 0;
mutex_lock(&chip->mutex);
status = i2c_smbus_read_byte_data(chip->client, BH1770_ALS_PS_STATUS);
i2c_smbus_read_byte_data(chip->client, BH1770_INTERRUPT);
if (status & BH1770_INT_ALS_DATA) {
bh1770_lux_get_result(chip);
if (unlikely(chip->lux_wait_result)) {
chip->lux_wait_result = false;
wake_up(&chip->wait);
bh1770_lux_update_thresholds(chip,
chip->lux_threshold_hi,
chip->lux_threshold_lo);
}
}
i2c_smbus_write_byte_data(chip->client, BH1770_INTERRUPT,
(0 << 1) | (0 << 0));
if ((status & BH1770_INT_ALS_INT))
sysfs_notify(&chip->client->dev.kobj, NULL, "lux0_input");
if (chip->int_mode_prox && (status & BH1770_INT_LEDS_INT)) {
rate = prox_rates_ms[chip->prox_rate_threshold];
bh1770_prox_read_result(chip);
}
i2c_smbus_write_byte_data(chip->client, BH1770_INTERRUPT,
(chip->int_mode_lux << 1) |
(chip->int_mode_prox << 0));
mutex_unlock(&chip->mutex);
if (rate) {
cancel_delayed_work_sync(&chip->prox_work);
schedule_delayed_work(&chip->prox_work,
msecs_to_jiffies(rate + 50));
}
return IRQ_HANDLED;
}
static ssize_t bh1770_power_state_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
unsigned long value;
ssize_t ret;
ret = kstrtoul(buf, 0, &value);
if (ret)
return ret;
mutex_lock(&chip->mutex);
if (value) {
pm_runtime_get_sync(dev);
ret = bh1770_lux_rate(chip, chip->lux_rate_index);
if (ret < 0) {
pm_runtime_put(dev);
goto leave;
}
ret = bh1770_lux_interrupt_control(chip, BH1770_ENABLE);
if (ret < 0) {
pm_runtime_put(dev);
goto leave;
}
bh1770_lux_update_thresholds(chip, BH1770_LUX_DEF_THRES,
BH1770_LUX_DEF_THRES);
chip->lux_wait_result = true;
bh1770_prox_mode_control(chip);
} else if (!pm_runtime_suspended(dev)) {
pm_runtime_put(dev);
}
ret = count;
leave:
mutex_unlock(&chip->mutex);
return ret;
}
static ssize_t bh1770_power_state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", !pm_runtime_suspended(dev));
}
static ssize_t bh1770_lux_result_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
ssize_t ret;
long timeout;
if (pm_runtime_suspended(dev))
return -EIO;
timeout = wait_event_interruptible_timeout(chip->wait,
!chip->lux_wait_result,
msecs_to_jiffies(BH1770_TIMEOUT));
if (!timeout)
return -EIO;
mutex_lock(&chip->mutex);
ret = sprintf(buf, "%d\n", bh1770_lux_read_result(chip));
mutex_unlock(&chip->mutex);
return ret;
}
static ssize_t bh1770_lux_range_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", BH1770_LUX_RANGE);
}
static ssize_t bh1770_prox_enable_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
unsigned long value;
int ret;
ret = kstrtoul(buf, 0, &value);
if (ret)
return ret;
mutex_lock(&chip->mutex);
if (!chip->prox_enable_count)
chip->prox_data = 0;
if (value)
chip->prox_enable_count++;
else if (chip->prox_enable_count > 0)
chip->prox_enable_count--;
else
goto leave;
if (!pm_runtime_suspended(dev))
bh1770_prox_mode_control(chip);
leave:
mutex_unlock(&chip->mutex);
return count;
}
static ssize_t bh1770_prox_enable_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
ssize_t len;
mutex_lock(&chip->mutex);
len = sprintf(buf, "%d\n", chip->prox_enable_count);
mutex_unlock(&chip->mutex);
return len;
}
static ssize_t bh1770_prox_result_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
ssize_t ret;
mutex_lock(&chip->mutex);
if (chip->prox_enable_count && !pm_runtime_suspended(dev))
ret = sprintf(buf, "%d\n", chip->prox_data);
else
ret = -EIO;
mutex_unlock(&chip->mutex);
return ret;
}
static ssize_t bh1770_prox_range_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", BH1770_PROX_RANGE);
}
static ssize_t bh1770_get_prox_rate_avail(struct device *dev,
struct device_attribute *attr, char *buf)
{
int i;
int pos = 0;
for (i = 0; i < ARRAY_SIZE(prox_rates_hz); i++)
pos += sprintf(buf + pos, "%d ", prox_rates_hz[i]);
sprintf(buf + pos - 1, "\n");
return pos;
}
static ssize_t bh1770_get_prox_rate_above(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", prox_rates_hz[chip->prox_rate_threshold]);
}
static ssize_t bh1770_get_prox_rate_below(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", prox_rates_hz[chip->prox_rate]);
}
static int bh1770_prox_rate_validate(int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(prox_rates_hz) - 1; i++)
if (rate >= prox_rates_hz[i])
break;
return i;
}
static ssize_t bh1770_set_prox_rate_above(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
unsigned long value;
int ret;
ret = kstrtoul(buf, 0, &value);
if (ret)
return ret;
mutex_lock(&chip->mutex);
chip->prox_rate_threshold = bh1770_prox_rate_validate(value);
mutex_unlock(&chip->mutex);
return count;
}
static ssize_t bh1770_set_prox_rate_below(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
unsigned long value;
int ret;
ret = kstrtoul(buf, 0, &value);
if (ret)
return ret;
mutex_lock(&chip->mutex);
chip->prox_rate = bh1770_prox_rate_validate(value);
mutex_unlock(&chip->mutex);
return count;
}
static ssize_t bh1770_get_prox_thres(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", chip->prox_threshold);
}
static ssize_t bh1770_set_prox_thres(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
unsigned long value;
int ret;
ret = kstrtoul(buf, 0, &value);
if (ret)
return ret;
if (value > BH1770_PROX_RANGE)
return -EINVAL;
mutex_lock(&chip->mutex);
chip->prox_threshold = value;
ret = bh1770_prox_set_threshold(chip);
mutex_unlock(&chip->mutex);
if (ret < 0)
return ret;
return count;
}
static ssize_t bh1770_prox_persistence_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", chip->prox_persistence);
}
static ssize_t bh1770_prox_persistence_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
unsigned long value;
int ret;
ret = kstrtoul(buf, 0, &value);
if (ret)
return ret;
if (value > BH1770_PROX_MAX_PERSISTENCE)
return -EINVAL;
chip->prox_persistence = value;
return len;
}
static ssize_t bh1770_prox_abs_thres_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", chip->prox_abs_thres);
}
static ssize_t bh1770_prox_abs_thres_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
unsigned long value;
int ret;
ret = kstrtoul(buf, 0, &value);
if (ret)
return ret;
if (value > BH1770_PROX_RANGE)
return -EINVAL;
chip->prox_abs_thres = value;
return len;
}
static ssize_t bh1770_chip_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
return sprintf(buf, "%s rev %d\n", chip->chipname, chip->revision);
}
static ssize_t bh1770_lux_calib_default_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", BH1770_CALIB_SCALER);
}
static ssize_t bh1770_lux_calib_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
ssize_t len;
mutex_lock(&chip->mutex);
len = sprintf(buf, "%u\n", chip->lux_calib);
mutex_unlock(&chip->mutex);
return len;
}
static ssize_t bh1770_lux_calib_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
unsigned long value;
u32 old_calib;
u32 new_corr;
int ret;
ret = kstrtoul(buf, 0, &value);
if (ret)
return ret;
mutex_lock(&chip->mutex);
old_calib = chip->lux_calib;
chip->lux_calib = value;
new_corr = bh1770_get_corr_value(chip);
if (new_corr == 0) {
chip->lux_calib = old_calib;
mutex_unlock(&chip->mutex);
return -EINVAL;
}
chip->lux_corr = new_corr;
bh1770_lux_update_thresholds(chip, chip->lux_threshold_hi,
chip->lux_threshold_lo);
mutex_unlock(&chip->mutex);
return len;
}
static ssize_t bh1770_get_lux_rate_avail(struct device *dev,
struct device_attribute *attr, char *buf)
{
int i;
int pos = 0;
for (i = 0; i < ARRAY_SIZE(lux_rates_hz); i++)
pos += sprintf(buf + pos, "%d ", lux_rates_hz[i]);
sprintf(buf + pos - 1, "\n");
return pos;
}
static ssize_t bh1770_get_lux_rate(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", lux_rates_hz[chip->lux_rate_index]);
}
static ssize_t bh1770_set_lux_rate(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
unsigned long rate_hz;
int ret, i;
ret = kstrtoul(buf, 0, &rate_hz);
if (ret)
return ret;
for (i = 0; i < ARRAY_SIZE(lux_rates_hz) - 1; i++)
if (rate_hz >= lux_rates_hz[i])
break;
mutex_lock(&chip->mutex);
chip->lux_rate_index = i;
ret = bh1770_lux_rate(chip, i);
mutex_unlock(&chip->mutex);
if (ret < 0)
return ret;
return count;
}
static ssize_t bh1770_get_lux_thresh_above(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", chip->lux_threshold_hi);
}
static ssize_t bh1770_get_lux_thresh_below(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", chip->lux_threshold_lo);
}
static ssize_t bh1770_set_lux_thresh(struct bh1770_chip *chip, u16 *target,
const char *buf)
{
unsigned long thresh;
int ret;
ret = kstrtoul(buf, 0, &thresh);
if (ret)
return ret;
if (thresh > BH1770_LUX_RANGE)
return -EINVAL;
mutex_lock(&chip->mutex);
*target = thresh;
if (!chip->lux_wait_result)
ret = bh1770_lux_update_thresholds(chip,
chip->lux_threshold_hi,
chip->lux_threshold_lo);
mutex_unlock(&chip->mutex);
return ret;
}
static ssize_t bh1770_set_lux_thresh_above(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
int ret = bh1770_set_lux_thresh(chip, &chip->lux_threshold_hi, buf);
if (ret < 0)
return ret;
return len;
}
static ssize_t bh1770_set_lux_thresh_below(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct bh1770_chip *chip = dev_get_drvdata(dev);
int ret = bh1770_set_lux_thresh(chip, &chip->lux_threshold_lo, buf);
if (ret < 0)
return ret;
return len;
}
static int bh1770_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct bh1770_chip *chip;
int err;
chip = kzalloc(sizeof *chip, GFP_KERNEL);
if (!chip)
return -ENOMEM;
i2c_set_clientdata(client, chip);
chip->client = client;
mutex_init(&chip->mutex);
init_waitqueue_head(&chip->wait);
INIT_DELAYED_WORK(&chip->prox_work, bh1770_prox_work);
if (client->dev.platform_data == NULL) {
dev_err(&client->dev, "platform data is mandatory\n");
err = -EINVAL;
goto fail1;
}
chip->pdata = client->dev.platform_data;
chip->lux_calib = BH1770_LUX_NEUTRAL_CALIB_VALUE;
chip->lux_rate_index = BH1770_LUX_DEFAULT_RATE;
chip->lux_threshold_lo = BH1770_LUX_DEF_THRES;
chip->lux_threshold_hi = BH1770_LUX_DEF_THRES;
if (chip->pdata->glass_attenuation == 0)
chip->lux_ga = BH1770_NEUTRAL_GA;
else
chip->lux_ga = chip->pdata->glass_attenuation;
chip->prox_threshold = BH1770_PROX_DEF_THRES;
chip->prox_led = chip->pdata->led_def_curr;
chip->prox_abs_thres = BH1770_PROX_DEF_ABS_THRES;
chip->prox_persistence = BH1770_DEFAULT_PERSISTENCE;
chip->prox_rate_threshold = BH1770_PROX_DEF_RATE_THRESH;
chip->prox_rate = BH1770_PROX_DEFAULT_RATE;
chip->prox_data = 0;
chip->regs[0].supply = reg_vcc;
chip->regs[1].supply = reg_vleds;
err = regulator_bulk_get(&client->dev,
ARRAY_SIZE(chip->regs), chip->regs);
if (err < 0) {
dev_err(&client->dev, "Cannot get regulators\n");
goto fail1;
}
err = regulator_bulk_enable(ARRAY_SIZE(chip->regs),
chip->regs);
if (err < 0) {
dev_err(&client->dev, "Cannot enable regulators\n");
goto fail2;
}
usleep_range(BH1770_STARTUP_DELAY, BH1770_STARTUP_DELAY * 2);
err = bh1770_detect(chip);
if (err < 0)
goto fail3;
bh1770_chip_on(chip);
pm_runtime_set_active(&client->dev);
pm_runtime_enable(&client->dev);
chip->lux_corr = bh1770_get_corr_value(chip);
if (chip->lux_corr == 0) {
dev_err(&client->dev, "Improper correction values\n");
err = -EINVAL;
goto fail3;
}
if (chip->pdata->setup_resources) {
err = chip->pdata->setup_resources();
if (err) {
err = -EINVAL;
goto fail3;
}
}
err = sysfs_create_group(&chip->client->dev.kobj,
&bh1770_attribute_group);
if (err < 0) {
dev_err(&chip->client->dev, "Sysfs registration failed\n");
goto fail4;
}
err = request_threaded_irq(client->irq, NULL,
bh1770_irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT |
IRQF_TRIGGER_LOW,
"bh1770", chip);
if (err) {
dev_err(&client->dev, "could not get IRQ %d\n",
client->irq);
goto fail5;
}
regulator_bulk_disable(ARRAY_SIZE(chip->regs), chip->regs);
return err;
fail5:
sysfs_remove_group(&chip->client->dev.kobj,
&bh1770_attribute_group);
fail4:
if (chip->pdata->release_resources)
chip->pdata->release_resources();
fail3:
regulator_bulk_disable(ARRAY_SIZE(chip->regs), chip->regs);
fail2:
regulator_bulk_free(ARRAY_SIZE(chip->regs), chip->regs);
fail1:
kfree(chip);
return err;
}
static int bh1770_remove(struct i2c_client *client)
{
struct bh1770_chip *chip = i2c_get_clientdata(client);
free_irq(client->irq, chip);
sysfs_remove_group(&chip->client->dev.kobj,
&bh1770_attribute_group);
if (chip->pdata->release_resources)
chip->pdata->release_resources();
cancel_delayed_work_sync(&chip->prox_work);
if (!pm_runtime_suspended(&client->dev))
bh1770_chip_off(chip);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
regulator_bulk_free(ARRAY_SIZE(chip->regs), chip->regs);
kfree(chip);
return 0;
}
static int bh1770_suspend(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct bh1770_chip *chip = i2c_get_clientdata(client);
bh1770_chip_off(chip);
return 0;
}
static int bh1770_resume(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct bh1770_chip *chip = i2c_get_clientdata(client);
int ret = 0;
bh1770_chip_on(chip);
if (!pm_runtime_suspended(dev)) {
ret = bh1770_lux_rate(chip, chip->lux_rate_index);
ret |= bh1770_lux_interrupt_control(chip, BH1770_ENABLE);
bh1770_lux_update_thresholds(chip, BH1770_LUX_DEF_THRES,
BH1770_LUX_DEF_THRES);
chip->lux_wait_result = true;
bh1770_prox_mode_control(chip);
}
return ret;
}
static int bh1770_runtime_suspend(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct bh1770_chip *chip = i2c_get_clientdata(client);
bh1770_chip_off(chip);
return 0;
}
static int bh1770_runtime_resume(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct bh1770_chip *chip = i2c_get_clientdata(client);
bh1770_chip_on(chip);
return 0;
}
