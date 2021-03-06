static int wm8350_rtc_readtime(struct device *dev, struct rtc_time *tm)
{
struct wm8350 *wm8350 = dev_get_drvdata(dev);
u16 time1[4], time2[4];
int retries = WM8350_GET_TIME_RETRIES, ret;
do {
ret = wm8350_block_read(wm8350, WM8350_RTC_SECONDS_MINUTES,
4, time1);
if (ret < 0)
return ret;
ret = wm8350_block_read(wm8350, WM8350_RTC_SECONDS_MINUTES,
4, time2);
if (ret < 0)
return ret;
if (memcmp(time1, time2, sizeof(time1)) == 0) {
tm->tm_sec = time1[0] & WM8350_RTC_SECS_MASK;
tm->tm_min = (time1[0] & WM8350_RTC_MINS_MASK)
>> WM8350_RTC_MINS_SHIFT;
tm->tm_hour = time1[1] & WM8350_RTC_HRS_MASK;
tm->tm_wday = ((time1[1] >> WM8350_RTC_DAY_SHIFT)
& 0x7) - 1;
tm->tm_mon = ((time1[2] & WM8350_RTC_MTH_MASK)
>> WM8350_RTC_MTH_SHIFT) - 1;
tm->tm_mday = (time1[2] & WM8350_RTC_DATE_MASK);
tm->tm_year = ((time1[3] & WM8350_RTC_YHUNDREDS_MASK)
>> WM8350_RTC_YHUNDREDS_SHIFT) * 100;
tm->tm_year += time1[3] & WM8350_RTC_YUNITS_MASK;
tm->tm_yday = rtc_year_days(tm->tm_mday, tm->tm_mon,
tm->tm_year);
tm->tm_year -= 1900;
dev_dbg(dev, "Read (%d left): %04x %04x %04x %04x\n",
retries,
time1[0], time1[1], time1[2], time1[3]);
return 0;
}
} while (retries--);
dev_err(dev, "timed out reading RTC time\n");
return -EIO;
}
static int wm8350_rtc_settime(struct device *dev, struct rtc_time *tm)
{
struct wm8350 *wm8350 = dev_get_drvdata(dev);
u16 time[4];
u16 rtc_ctrl;
int ret, retries = WM8350_SET_TIME_RETRIES;
time[0] = tm->tm_sec;
time[0] |= tm->tm_min << WM8350_RTC_MINS_SHIFT;
time[1] = tm->tm_hour;
time[1] |= (tm->tm_wday + 1) << WM8350_RTC_DAY_SHIFT;
time[2] = tm->tm_mday;
time[2] |= (tm->tm_mon + 1) << WM8350_RTC_MTH_SHIFT;
time[3] = ((tm->tm_year + 1900) / 100) << WM8350_RTC_YHUNDREDS_SHIFT;
time[3] |= (tm->tm_year + 1900) % 100;
dev_dbg(dev, "Setting: %04x %04x %04x %04x\n",
time[0], time[1], time[2], time[3]);
ret = wm8350_set_bits(wm8350, WM8350_RTC_TIME_CONTROL, WM8350_RTC_SET);
if (ret < 0)
return ret;
do {
rtc_ctrl = wm8350_reg_read(wm8350, WM8350_RTC_TIME_CONTROL);
schedule_timeout_uninterruptible(msecs_to_jiffies(1));
} while (--retries && !(rtc_ctrl & WM8350_RTC_STS));
if (!retries) {
dev_err(dev, "timed out on set confirmation\n");
return -EIO;
}
ret = wm8350_block_write(wm8350, WM8350_RTC_SECONDS_MINUTES, 4, time);
if (ret < 0)
return ret;
ret = wm8350_clear_bits(wm8350, WM8350_RTC_TIME_CONTROL,
WM8350_RTC_SET);
return ret;
}
static int wm8350_rtc_readalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct wm8350 *wm8350 = dev_get_drvdata(dev);
struct rtc_time *tm = &alrm->time;
u16 time[4];
int ret;
ret = wm8350_block_read(wm8350, WM8350_ALARM_SECONDS_MINUTES, 4, time);
if (ret < 0)
return ret;
tm->tm_sec = time[0] & WM8350_RTC_ALMSECS_MASK;
if (tm->tm_sec == WM8350_RTC_ALMSECS_MASK)
tm->tm_sec = -1;
tm->tm_min = time[0] & WM8350_RTC_ALMMINS_MASK;
if (tm->tm_min == WM8350_RTC_ALMMINS_MASK)
tm->tm_min = -1;
else
tm->tm_min >>= WM8350_RTC_ALMMINS_SHIFT;
tm->tm_hour = time[1] & WM8350_RTC_ALMHRS_MASK;
if (tm->tm_hour == WM8350_RTC_ALMHRS_MASK)
tm->tm_hour = -1;
tm->tm_wday = ((time[1] >> WM8350_RTC_ALMDAY_SHIFT) & 0x7) - 1;
if (tm->tm_wday > 7)
tm->tm_wday = -1;
tm->tm_mon = time[2] & WM8350_RTC_ALMMTH_MASK;
if (tm->tm_mon == WM8350_RTC_ALMMTH_MASK)
tm->tm_mon = -1;
else
tm->tm_mon = (tm->tm_mon >> WM8350_RTC_ALMMTH_SHIFT) - 1;
tm->tm_mday = (time[2] & WM8350_RTC_ALMDATE_MASK);
if (tm->tm_mday == WM8350_RTC_ALMDATE_MASK)
tm->tm_mday = -1;
tm->tm_year = -1;
alrm->enabled = !(time[3] & WM8350_RTC_ALMSTS);
return 0;
}
static int wm8350_rtc_stop_alarm(struct wm8350 *wm8350)
{
int retries = WM8350_SET_ALM_RETRIES;
u16 rtc_ctrl;
int ret;
ret = wm8350_set_bits(wm8350, WM8350_RTC_TIME_CONTROL,
WM8350_RTC_ALMSET);
if (ret < 0)
return ret;
do {
rtc_ctrl = wm8350_reg_read(wm8350, WM8350_RTC_TIME_CONTROL);
schedule_timeout_uninterruptible(msecs_to_jiffies(1));
} while (retries-- && !(rtc_ctrl & WM8350_RTC_ALMSTS));
if (!(rtc_ctrl & WM8350_RTC_ALMSTS))
return -ETIMEDOUT;
return 0;
}
static int wm8350_rtc_start_alarm(struct wm8350 *wm8350)
{
int ret;
int retries = WM8350_SET_ALM_RETRIES;
u16 rtc_ctrl;
ret = wm8350_clear_bits(wm8350, WM8350_RTC_TIME_CONTROL,
WM8350_RTC_ALMSET);
if (ret < 0)
return ret;
do {
rtc_ctrl = wm8350_reg_read(wm8350, WM8350_RTC_TIME_CONTROL);
schedule_timeout_uninterruptible(msecs_to_jiffies(1));
} while (retries-- && rtc_ctrl & WM8350_RTC_ALMSTS);
if (rtc_ctrl & WM8350_RTC_ALMSTS)
return -ETIMEDOUT;
return 0;
}
static int wm8350_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct wm8350 *wm8350 = dev_get_drvdata(dev);
if (enabled)
return wm8350_rtc_start_alarm(wm8350);
else
return wm8350_rtc_stop_alarm(wm8350);
}
static int wm8350_rtc_setalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct wm8350 *wm8350 = dev_get_drvdata(dev);
struct rtc_time *tm = &alrm->time;
u16 time[3];
int ret;
memset(time, 0, sizeof(time));
if (tm->tm_sec != -1)
time[0] |= tm->tm_sec;
else
time[0] |= WM8350_RTC_ALMSECS_MASK;
if (tm->tm_min != -1)
time[0] |= tm->tm_min << WM8350_RTC_ALMMINS_SHIFT;
else
time[0] |= WM8350_RTC_ALMMINS_MASK;
if (tm->tm_hour != -1)
time[1] |= tm->tm_hour;
else
time[1] |= WM8350_RTC_ALMHRS_MASK;
if (tm->tm_wday != -1)
time[1] |= (tm->tm_wday + 1) << WM8350_RTC_ALMDAY_SHIFT;
else
time[1] |= WM8350_RTC_ALMDAY_MASK;
if (tm->tm_mday != -1)
time[2] |= tm->tm_mday;
else
time[2] |= WM8350_RTC_ALMDATE_MASK;
if (tm->tm_mon != -1)
time[2] |= (tm->tm_mon + 1) << WM8350_RTC_ALMMTH_SHIFT;
else
time[2] |= WM8350_RTC_ALMMTH_MASK;
ret = wm8350_rtc_stop_alarm(wm8350);
if (ret < 0)
return ret;
ret = wm8350_block_write(wm8350, WM8350_ALARM_SECONDS_MINUTES,
3, time);
if (ret < 0)
return ret;
if (alrm->enabled)
ret = wm8350_rtc_start_alarm(wm8350);
return ret;
}
static irqreturn_t wm8350_rtc_alarm_handler(int irq, void *data)
{
struct wm8350 *wm8350 = data;
struct rtc_device *rtc = wm8350->rtc.rtc;
int ret;
rtc_update_irq(rtc, 1, RTC_IRQF | RTC_AF);
ret = wm8350_set_bits(wm8350, WM8350_RTC_TIME_CONTROL,
WM8350_RTC_ALMSET);
if (ret != 0) {
dev_err(&(wm8350->rtc.pdev->dev),
"Failed to disable alarm: %d\n", ret);
}
return IRQ_HANDLED;
}
static irqreturn_t wm8350_rtc_update_handler(int irq, void *data)
{
struct wm8350 *wm8350 = data;
struct rtc_device *rtc = wm8350->rtc.rtc;
rtc_update_irq(rtc, 1, RTC_IRQF | RTC_UF);
return IRQ_HANDLED;
}
static int wm8350_rtc_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct wm8350 *wm8350 = dev_get_drvdata(&pdev->dev);
int ret = 0;
u16 reg;
reg = wm8350_reg_read(wm8350, WM8350_RTC_TIME_CONTROL);
if (device_may_wakeup(&wm8350->rtc.pdev->dev) &&
reg & WM8350_RTC_ALMSTS) {
ret = wm8350_rtc_stop_alarm(wm8350);
if (ret != 0)
dev_err(&pdev->dev, "Failed to stop RTC alarm: %d\n",
ret);
}
return ret;
}
static int wm8350_rtc_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct wm8350 *wm8350 = dev_get_drvdata(&pdev->dev);
int ret;
if (wm8350->rtc.alarm_enabled) {
ret = wm8350_rtc_start_alarm(wm8350);
if (ret != 0)
dev_err(&pdev->dev,
"Failed to restart RTC alarm: %d\n", ret);
}
return 0;
}
static int wm8350_rtc_probe(struct platform_device *pdev)
{
struct wm8350 *wm8350 = platform_get_drvdata(pdev);
struct wm8350_rtc *wm_rtc = &wm8350->rtc;
int ret = 0;
u16 timectl, power5;
timectl = wm8350_reg_read(wm8350, WM8350_RTC_TIME_CONTROL);
if (timectl & WM8350_RTC_BCD) {
dev_err(&pdev->dev, "RTC BCD mode not supported\n");
return -EINVAL;
}
if (timectl & WM8350_RTC_12HR) {
dev_err(&pdev->dev, "RTC 12 hour mode not supported\n");
return -EINVAL;
}
power5 = wm8350_reg_read(wm8350, WM8350_POWER_MGMT_5);
if (!(power5 & WM8350_RTC_TICK_ENA)) {
dev_info(wm8350->dev, "Starting RTC\n");
wm8350_reg_unlock(wm8350);
ret = wm8350_set_bits(wm8350, WM8350_POWER_MGMT_5,
WM8350_RTC_TICK_ENA);
if (ret < 0) {
dev_err(&pdev->dev, "failed to enable RTC: %d\n", ret);
return ret;
}
wm8350_reg_lock(wm8350);
}
if (timectl & WM8350_RTC_STS) {
int retries;
ret = wm8350_clear_bits(wm8350, WM8350_RTC_TIME_CONTROL,
WM8350_RTC_SET);
if (ret < 0) {
dev_err(&pdev->dev, "failed to start: %d\n", ret);
return ret;
}
retries = WM8350_SET_TIME_RETRIES;
do {
timectl = wm8350_reg_read(wm8350,
WM8350_RTC_TIME_CONTROL);
} while (timectl & WM8350_RTC_STS && --retries);
if (retries == 0) {
dev_err(&pdev->dev, "failed to start: timeout\n");
return -ENODEV;
}
}
device_init_wakeup(&pdev->dev, 1);
wm_rtc->rtc = rtc_device_register("wm8350", &pdev->dev,
&wm8350_rtc_ops, THIS_MODULE);
if (IS_ERR(wm_rtc->rtc)) {
ret = PTR_ERR(wm_rtc->rtc);
dev_err(&pdev->dev, "failed to register RTC: %d\n", ret);
return ret;
}
wm8350_register_irq(wm8350, WM8350_IRQ_RTC_SEC,
wm8350_rtc_update_handler, 0,
"RTC Seconds", wm8350);
wm8350_mask_irq(wm8350, WM8350_IRQ_RTC_SEC);
wm8350_register_irq(wm8350, WM8350_IRQ_RTC_ALM,
wm8350_rtc_alarm_handler, 0,
"RTC Alarm", wm8350);
return 0;
}
static int __devexit wm8350_rtc_remove(struct platform_device *pdev)
{
struct wm8350 *wm8350 = platform_get_drvdata(pdev);
struct wm8350_rtc *wm_rtc = &wm8350->rtc;
wm8350_free_irq(wm8350, WM8350_IRQ_RTC_SEC, wm8350);
wm8350_free_irq(wm8350, WM8350_IRQ_RTC_ALM, wm8350);
rtc_device_unregister(wm_rtc->rtc);
return 0;
}
