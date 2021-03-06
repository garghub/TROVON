static int da9052_rtc_enable_alarm(struct da9052_rtc *rtc, bool enable)
{
int ret;
if (enable) {
ret = da9052_reg_update(rtc->da9052, DA9052_ALARM_Y_REG,
DA9052_ALARM_Y_ALARM_ON|DA9052_ALARM_Y_TICK_ON,
DA9052_ALARM_Y_ALARM_ON);
if (ret != 0)
rtc_err(rtc, "Failed to enable ALM: %d\n", ret);
} else {
ret = da9052_reg_update(rtc->da9052, DA9052_ALARM_Y_REG,
DA9052_ALARM_Y_ALARM_ON|DA9052_ALARM_Y_TICK_ON, 0);
if (ret != 0)
rtc_err(rtc, "Write error: %d\n", ret);
}
return ret;
}
static irqreturn_t da9052_rtc_irq(int irq, void *data)
{
struct da9052_rtc *rtc = data;
rtc_update_irq(rtc->rtc, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
static int da9052_read_alarm(struct da9052_rtc *rtc, struct rtc_time *rtc_tm)
{
int ret;
uint8_t v[2][5];
int idx = 1;
int timeout = DA9052_GET_TIME_RETRIES;
ret = da9052_group_read(rtc->da9052, DA9052_ALARM_MI_REG, 5, &v[0][0]);
if (ret) {
rtc_err(rtc, "Failed to group read ALM: %d\n", ret);
return ret;
}
do {
ret = da9052_group_read(rtc->da9052,
DA9052_ALARM_MI_REG, 5, &v[idx][0]);
if (ret) {
rtc_err(rtc, "Failed to group read ALM: %d\n", ret);
return ret;
}
if (memcmp(&v[0][0], &v[1][0], 5) == 0) {
rtc_tm->tm_year = (v[0][4] & DA9052_RTC_YEAR) + 100;
rtc_tm->tm_mon = (v[0][3] & DA9052_RTC_MONTH) - 1;
rtc_tm->tm_mday = v[0][2] & DA9052_RTC_DAY;
rtc_tm->tm_hour = v[0][1] & DA9052_RTC_HOUR;
rtc_tm->tm_min = v[0][0] & DA9052_RTC_MIN;
ret = rtc_valid_tm(rtc_tm);
return ret;
}
idx = (1-idx);
msleep(20);
} while (timeout--);
rtc_err(rtc, "Timed out reading alarm time\n");
return -EIO;
}
static int da9052_set_alarm(struct da9052_rtc *rtc, struct rtc_time *rtc_tm)
{
struct da9052 *da9052 = rtc->da9052;
unsigned long alm_time;
int ret;
uint8_t v[3];
ret = rtc_tm_to_time(rtc_tm, &alm_time);
if (ret != 0)
return ret;
if (rtc_tm->tm_sec > 0) {
alm_time += 60 - rtc_tm->tm_sec;
rtc_time_to_tm(alm_time, rtc_tm);
}
BUG_ON(rtc_tm->tm_sec);
rtc_tm->tm_year -= 100;
rtc_tm->tm_mon += 1;
ret = da9052_reg_update(da9052, DA9052_ALARM_MI_REG,
DA9052_RTC_MIN, rtc_tm->tm_min);
if (ret != 0) {
rtc_err(rtc, "Failed to write ALRM MIN: %d\n", ret);
return ret;
}
v[0] = rtc_tm->tm_hour;
v[1] = rtc_tm->tm_mday;
v[2] = rtc_tm->tm_mon;
ret = da9052_group_write(da9052, DA9052_ALARM_H_REG, 3, v);
if (ret < 0)
return ret;
ret = da9052_reg_update(da9052, DA9052_ALARM_Y_REG,
DA9052_RTC_YEAR, rtc_tm->tm_year);
if (ret != 0)
rtc_err(rtc, "Failed to write ALRM YEAR: %d\n", ret);
return ret;
}
static int da9052_rtc_get_alarm_status(struct da9052_rtc *rtc)
{
int ret;
ret = da9052_reg_read(rtc->da9052, DA9052_ALARM_Y_REG);
if (ret < 0) {
rtc_err(rtc, "Failed to read ALM: %d\n", ret);
return ret;
}
return !!(ret&DA9052_ALARM_Y_ALARM_ON);
}
static int da9052_rtc_read_time(struct device *dev, struct rtc_time *rtc_tm)
{
struct da9052_rtc *rtc = dev_get_drvdata(dev);
int ret;
uint8_t v[2][6];
int idx = 1;
int timeout = DA9052_GET_TIME_RETRIES;
ret = da9052_group_read(rtc->da9052, DA9052_COUNT_S_REG, 6, &v[0][0]);
if (ret) {
rtc_err(rtc, "Failed to read RTC time : %d\n", ret);
return ret;
}
do {
ret = da9052_group_read(rtc->da9052,
DA9052_COUNT_S_REG, 6, &v[idx][0]);
if (ret) {
rtc_err(rtc, "Failed to read RTC time : %d\n", ret);
return ret;
}
if (memcmp(&v[0][0], &v[1][0], 6) == 0) {
rtc_tm->tm_year = (v[0][5] & DA9052_RTC_YEAR) + 100;
rtc_tm->tm_mon = (v[0][4] & DA9052_RTC_MONTH) - 1;
rtc_tm->tm_mday = v[0][3] & DA9052_RTC_DAY;
rtc_tm->tm_hour = v[0][2] & DA9052_RTC_HOUR;
rtc_tm->tm_min = v[0][1] & DA9052_RTC_MIN;
rtc_tm->tm_sec = v[0][0] & DA9052_RTC_SEC;
ret = rtc_valid_tm(rtc_tm);
return ret;
}
idx = (1-idx);
msleep(20);
} while (timeout--);
rtc_err(rtc, "Timed out reading time\n");
return -EIO;
}
static int da9052_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct da9052_rtc *rtc;
uint8_t v[6];
int ret;
if ((tm->tm_year < 100) || (tm->tm_year > 163))
return -EINVAL;
rtc = dev_get_drvdata(dev);
v[0] = tm->tm_sec;
v[1] = tm->tm_min;
v[2] = tm->tm_hour;
v[3] = tm->tm_mday;
v[4] = tm->tm_mon + 1;
v[5] = tm->tm_year - 100;
ret = da9052_group_write(rtc->da9052, DA9052_COUNT_S_REG, 6, v);
if (ret < 0)
rtc_err(rtc, "failed to set RTC time: %d\n", ret);
return ret;
}
static int da9052_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
int ret;
struct rtc_time *tm = &alrm->time;
struct da9052_rtc *rtc = dev_get_drvdata(dev);
ret = da9052_read_alarm(rtc, tm);
if (ret < 0) {
rtc_err(rtc, "failed to read RTC alarm: %d\n", ret);
return ret;
}
alrm->enabled = da9052_rtc_get_alarm_status(rtc);
return 0;
}
static int da9052_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
int ret;
struct rtc_time *tm = &alrm->time;
struct da9052_rtc *rtc = dev_get_drvdata(dev);
if ((tm->tm_year < 100) || (tm->tm_year > 163))
return -EINVAL;
ret = da9052_rtc_enable_alarm(rtc, 0);
if (ret < 0)
return ret;
ret = da9052_set_alarm(rtc, tm);
if (ret < 0)
return ret;
ret = da9052_rtc_enable_alarm(rtc, 1);
return ret;
}
static int da9052_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct da9052_rtc *rtc = dev_get_drvdata(dev);
return da9052_rtc_enable_alarm(rtc, enabled);
}
static int da9052_rtc_probe(struct platform_device *pdev)
{
struct da9052_rtc *rtc;
int ret;
rtc = devm_kzalloc(&pdev->dev, sizeof(struct da9052_rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
rtc->da9052 = dev_get_drvdata(pdev->dev.parent);
platform_set_drvdata(pdev, rtc);
ret = da9052_reg_write(rtc->da9052, DA9052_BBAT_CONT_REG, 0xFE);
if (ret < 0) {
rtc_err(rtc,
"Failed to setup RTC battery charging: %d\n", ret);
return ret;
}
ret = da9052_reg_update(rtc->da9052, DA9052_ALARM_Y_REG,
DA9052_ALARM_Y_TICK_ON, 0);
if (ret != 0)
rtc_err(rtc, "Failed to disable TICKS: %d\n", ret);
device_init_wakeup(&pdev->dev, true);
rtc->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&da9052_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc))
return PTR_ERR(rtc->rtc);
ret = da9052_request_irq(rtc->da9052, DA9052_IRQ_ALARM, "ALM",
da9052_rtc_irq, rtc);
if (ret != 0) {
rtc_err(rtc, "irq registration failed: %d\n", ret);
return ret;
}
return 0;
}
