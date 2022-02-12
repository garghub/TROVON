static void isl12057_rtc_regs_to_tm(struct rtc_time *tm, u8 *regs)
{
tm->tm_sec = bcd2bin(regs[ISL12057_REG_RTC_SC]);
tm->tm_min = bcd2bin(regs[ISL12057_REG_RTC_MN]);
if (regs[ISL12057_REG_RTC_HR] & ISL12057_REG_RTC_HR_MIL) {
tm->tm_hour = bcd2bin(regs[ISL12057_REG_RTC_HR] & 0x1f);
if (regs[ISL12057_REG_RTC_HR] & ISL12057_REG_RTC_HR_PM)
tm->tm_hour += 12;
} else {
tm->tm_hour = bcd2bin(regs[ISL12057_REG_RTC_HR] & 0x3f);
}
tm->tm_mday = bcd2bin(regs[ISL12057_REG_RTC_DT]);
tm->tm_wday = bcd2bin(regs[ISL12057_REG_RTC_DW]) - 1;
tm->tm_mon = bcd2bin(regs[ISL12057_REG_RTC_MO] & 0x1f) - 1;
tm->tm_year = bcd2bin(regs[ISL12057_REG_RTC_YR]) + 100;
if (regs[ISL12057_REG_RTC_MO] & ISL12057_REG_RTC_MO_CEN)
tm->tm_year += 100;
}
static int isl12057_rtc_tm_to_regs(u8 *regs, struct rtc_time *tm)
{
u8 century_bit;
if (tm->tm_year < 100 || tm->tm_year > 299)
return -EINVAL;
century_bit = (tm->tm_year > 199) ? ISL12057_REG_RTC_MO_CEN : 0;
regs[ISL12057_REG_RTC_SC] = bin2bcd(tm->tm_sec);
regs[ISL12057_REG_RTC_MN] = bin2bcd(tm->tm_min);
regs[ISL12057_REG_RTC_HR] = bin2bcd(tm->tm_hour);
regs[ISL12057_REG_RTC_DT] = bin2bcd(tm->tm_mday);
regs[ISL12057_REG_RTC_MO] = bin2bcd(tm->tm_mon + 1) | century_bit;
regs[ISL12057_REG_RTC_YR] = bin2bcd(tm->tm_year % 100);
regs[ISL12057_REG_RTC_DW] = bin2bcd(tm->tm_wday + 1);
return 0;
}
static int isl12057_i2c_validate_chip(struct regmap *regmap)
{
u8 regs[ISL12057_MEM_MAP_LEN];
static const u8 mask[ISL12057_MEM_MAP_LEN] = { 0x80, 0x80, 0x80, 0xf8,
0xc0, 0x60, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x60, 0x7c };
int ret, i;
ret = regmap_bulk_read(regmap, 0, regs, ISL12057_MEM_MAP_LEN);
if (ret)
return ret;
for (i = 0; i < ISL12057_MEM_MAP_LEN; ++i) {
if (regs[i] & mask[i])
return -ENODEV;
}
return 0;
}
static int _isl12057_rtc_clear_alarm(struct device *dev)
{
struct isl12057_rtc_data *data = dev_get_drvdata(dev);
int ret;
ret = regmap_update_bits(data->regmap, ISL12057_REG_SR,
ISL12057_REG_SR_A1F, 0);
if (ret)
dev_err(dev, "%s: clearing alarm failed (%d)\n", __func__, ret);
return ret;
}
static int _isl12057_rtc_update_alarm(struct device *dev, int enable)
{
struct isl12057_rtc_data *data = dev_get_drvdata(dev);
int ret;
ret = regmap_update_bits(data->regmap, ISL12057_REG_INT,
ISL12057_REG_INT_A1IE,
enable ? ISL12057_REG_INT_A1IE : 0);
if (ret)
dev_err(dev, "%s: changing alarm interrupt flag failed (%d)\n",
__func__, ret);
return ret;
}
static int _isl12057_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct isl12057_rtc_data *data = dev_get_drvdata(dev);
u8 regs[ISL12057_RTC_SEC_LEN];
unsigned int sr;
int ret;
ret = regmap_read(data->regmap, ISL12057_REG_SR, &sr);
if (ret) {
dev_err(dev, "%s: unable to read oscillator status flag (%d)\n",
__func__, ret);
goto out;
} else {
if (sr & ISL12057_REG_SR_OSF) {
ret = -ENODATA;
goto out;
}
}
ret = regmap_bulk_read(data->regmap, ISL12057_REG_RTC_SC, regs,
ISL12057_RTC_SEC_LEN);
if (ret)
dev_err(dev, "%s: unable to read RTC time section (%d)\n",
__func__, ret);
out:
if (ret)
return ret;
isl12057_rtc_regs_to_tm(tm, regs);
return rtc_valid_tm(tm);
}
static int isl12057_rtc_update_alarm(struct device *dev, int enable)
{
struct isl12057_rtc_data *data = dev_get_drvdata(dev);
int ret;
mutex_lock(&data->lock);
ret = _isl12057_rtc_update_alarm(dev, enable);
mutex_unlock(&data->lock);
return ret;
}
static int isl12057_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct isl12057_rtc_data *data = dev_get_drvdata(dev);
struct rtc_time rtc_tm, *alarm_tm = &alarm->time;
unsigned long rtc_secs, alarm_secs;
u8 regs[ISL12057_A1_SEC_LEN];
unsigned int ir;
int ret;
mutex_lock(&data->lock);
ret = regmap_bulk_read(data->regmap, ISL12057_REG_A1_SC, regs,
ISL12057_A1_SEC_LEN);
if (ret) {
dev_err(dev, "%s: reading alarm section failed (%d)\n",
__func__, ret);
goto err_unlock;
}
alarm_tm->tm_sec = bcd2bin(regs[0] & 0x7f);
alarm_tm->tm_min = bcd2bin(regs[1] & 0x7f);
alarm_tm->tm_hour = bcd2bin(regs[2] & 0x3f);
alarm_tm->tm_mday = bcd2bin(regs[3] & 0x3f);
alarm_tm->tm_wday = -1;
ret = _isl12057_rtc_read_time(dev, &rtc_tm);
if (ret)
goto err_unlock;
alarm_tm->tm_year = rtc_tm.tm_year;
alarm_tm->tm_mon = rtc_tm.tm_mon;
ret = rtc_tm_to_time(&rtc_tm, &rtc_secs);
if (ret)
goto err_unlock;
ret = rtc_tm_to_time(alarm_tm, &alarm_secs);
if (ret)
goto err_unlock;
if (alarm_secs < rtc_secs) {
if (alarm_tm->tm_mon == 11) {
alarm_tm->tm_mon = 0;
alarm_tm->tm_year += 1;
} else {
alarm_tm->tm_mon += 1;
}
}
ret = regmap_read(data->regmap, ISL12057_REG_INT, &ir);
if (ret) {
dev_err(dev, "%s: reading alarm interrupt flag failed (%d)\n",
__func__, ret);
goto err_unlock;
}
alarm->enabled = !!(ir & ISL12057_REG_INT_A1IE);
err_unlock:
mutex_unlock(&data->lock);
return ret;
}
static int isl12057_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct isl12057_rtc_data *data = dev_get_drvdata(dev);
struct rtc_time *alarm_tm = &alarm->time;
unsigned long rtc_secs, alarm_secs;
u8 regs[ISL12057_A1_SEC_LEN];
struct rtc_time rtc_tm;
int ret, enable = 1;
mutex_lock(&data->lock);
ret = _isl12057_rtc_read_time(dev, &rtc_tm);
if (ret)
goto err_unlock;
ret = rtc_tm_to_time(&rtc_tm, &rtc_secs);
if (ret)
goto err_unlock;
ret = rtc_tm_to_time(alarm_tm, &alarm_secs);
if (ret)
goto err_unlock;
if (!alarm->enabled || alarm_secs <= rtc_secs) {
enable = 0;
} else {
if (rtc_tm.tm_mon == 11) {
rtc_tm.tm_mon = 0;
rtc_tm.tm_year += 1;
} else {
rtc_tm.tm_mon += 1;
}
ret = rtc_tm_to_time(&rtc_tm, &rtc_secs);
if (ret)
goto err_unlock;
if (alarm_secs > rtc_secs) {
dev_err(dev, "%s: max for alarm is one month (%d)\n",
__func__, ret);
ret = -EINVAL;
goto err_unlock;
}
}
ret = _isl12057_rtc_update_alarm(dev, 0);
if (ret < 0) {
dev_err(dev, "%s: unable to disable the alarm (%d)\n",
__func__, ret);
goto err_unlock;
}
regs[0] = bin2bcd(alarm_tm->tm_sec) & 0x7f;
regs[1] = bin2bcd(alarm_tm->tm_min) & 0x7f;
regs[2] = bin2bcd(alarm_tm->tm_hour) & 0x3f;
regs[3] = bin2bcd(alarm_tm->tm_mday) & 0x3f;
ret = regmap_bulk_write(data->regmap, ISL12057_REG_A1_SC, regs,
ISL12057_A1_SEC_LEN);
if (ret < 0) {
dev_err(dev, "%s: writing alarm section failed (%d)\n",
__func__, ret);
goto err_unlock;
}
ret = _isl12057_rtc_update_alarm(dev, enable);
err_unlock:
mutex_unlock(&data->lock);
return ret;
}
static int isl12057_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct isl12057_rtc_data *data = dev_get_drvdata(dev);
u8 regs[ISL12057_RTC_SEC_LEN];
int ret;
ret = isl12057_rtc_tm_to_regs(regs, tm);
if (ret)
return ret;
mutex_lock(&data->lock);
ret = regmap_bulk_write(data->regmap, ISL12057_REG_RTC_SC, regs,
ISL12057_RTC_SEC_LEN);
if (ret) {
dev_err(dev, "%s: unable to write RTC time section (%d)\n",
__func__, ret);
goto out;
}
ret = regmap_update_bits(data->regmap, ISL12057_REG_SR,
ISL12057_REG_SR_OSF, 0);
if (ret < 0)
dev_err(dev, "%s: unable to clear osc. failure bit (%d)\n",
__func__, ret);
out:
mutex_unlock(&data->lock);
return ret;
}
static int isl12057_check_rtc_status(struct device *dev, struct regmap *regmap)
{
int ret;
ret = regmap_update_bits(regmap, ISL12057_REG_INT,
ISL12057_REG_INT_EOSC, 0);
if (ret < 0) {
dev_err(dev, "%s: unable to enable oscillator (%d)\n",
__func__, ret);
return ret;
}
ret = regmap_update_bits(regmap, ISL12057_REG_SR,
ISL12057_REG_SR_A1F, 0);
if (ret < 0) {
dev_err(dev, "%s: unable to clear alarm bit (%d)\n",
__func__, ret);
return ret;
}
return 0;
}
static bool isl12057_can_wakeup_machine(struct device *dev)
{
struct isl12057_rtc_data *data = dev_get_drvdata(dev);
return (data->irq || of_property_read_bool(dev->of_node,
"isil,irq2-can-wakeup-machine"));
}
static bool isl12057_can_wakeup_machine(struct device *dev)
{
struct isl12057_rtc_data *data = dev_get_drvdata(dev);
return !!data->irq;
}
static int isl12057_rtc_alarm_irq_enable(struct device *dev,
unsigned int enable)
{
struct isl12057_rtc_data *rtc_data = dev_get_drvdata(dev);
int ret = -ENOTTY;
if (rtc_data->irq)
ret = isl12057_rtc_update_alarm(dev, enable);
return ret;
}
static irqreturn_t isl12057_rtc_interrupt(int irq, void *data)
{
struct i2c_client *client = data;
struct isl12057_rtc_data *rtc_data = dev_get_drvdata(&client->dev);
struct rtc_device *rtc = rtc_data->rtc;
int ret, handled = IRQ_NONE;
unsigned int sr;
ret = regmap_read(rtc_data->regmap, ISL12057_REG_SR, &sr);
if (!ret && (sr & ISL12057_REG_SR_A1F)) {
dev_dbg(&client->dev, "RTC alarm!\n");
rtc_update_irq(rtc, 1, RTC_IRQF | RTC_AF);
_isl12057_rtc_clear_alarm(&client->dev);
_isl12057_rtc_update_alarm(&client->dev, 0);
handled = IRQ_HANDLED;
}
return handled;
}
static int isl12057_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct isl12057_rtc_data *data;
struct regmap *regmap;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C |
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK))
return -ENODEV;
regmap = devm_regmap_init_i2c(client, &isl12057_rtc_regmap_config);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
dev_err(dev, "%s: regmap allocation failed (%d)\n",
__func__, ret);
return ret;
}
ret = isl12057_i2c_validate_chip(regmap);
if (ret)
return ret;
ret = isl12057_check_rtc_status(dev, regmap);
if (ret)
return ret;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
mutex_init(&data->lock);
data->regmap = regmap;
dev_set_drvdata(dev, data);
if (client->irq > 0) {
ret = devm_request_threaded_irq(dev, client->irq, NULL,
isl12057_rtc_interrupt,
IRQF_SHARED|IRQF_ONESHOT,
DRV_NAME, client);
if (!ret)
data->irq = client->irq;
else
dev_err(dev, "%s: irq %d unavailable (%d)\n", __func__,
client->irq, ret);
}
if (isl12057_can_wakeup_machine(dev))
device_init_wakeup(dev, true);
data->rtc = devm_rtc_device_register(dev, DRV_NAME, &rtc_ops,
THIS_MODULE);
ret = PTR_ERR_OR_ZERO(data->rtc);
if (ret) {
dev_err(dev, "%s: unable to register RTC device (%d)\n",
__func__, ret);
goto err;
}
if (!data->irq)
data->rtc->uie_unsupported = 1;
err:
return ret;
}
static int isl12057_remove(struct i2c_client *client)
{
if (isl12057_can_wakeup_machine(&client->dev))
device_init_wakeup(&client->dev, false);
return 0;
}
static int isl12057_rtc_suspend(struct device *dev)
{
struct isl12057_rtc_data *rtc_data = dev_get_drvdata(dev);
if (rtc_data->irq && device_may_wakeup(dev))
return enable_irq_wake(rtc_data->irq);
return 0;
}
static int isl12057_rtc_resume(struct device *dev)
{
struct isl12057_rtc_data *rtc_data = dev_get_drvdata(dev);
if (rtc_data->irq && device_may_wakeup(dev))
return disable_irq_wake(rtc_data->irq);
return 0;
}
