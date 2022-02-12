static int ls1x_rtc_read_time(struct device *dev, struct rtc_time *rtm)
{
unsigned long v, t;
v = readl(SYS_TOYREAD0);
t = readl(SYS_TOYREAD1);
memset(rtm, 0, sizeof(struct rtc_time));
t = mktime((t & LS1X_YEAR_MASK), ls1x_get_month(v),
ls1x_get_day(v), ls1x_get_hour(v),
ls1x_get_min(v), ls1x_get_sec(v));
rtc_time_to_tm(t, rtm);
return rtc_valid_tm(rtm);
}
static int ls1x_rtc_set_time(struct device *dev, struct rtc_time *rtm)
{
unsigned long v, t, c;
int ret = -ETIMEDOUT;
v = ((rtm->tm_mon + 1) << LS1X_MONTH_OFFSET)
| (rtm->tm_mday << LS1X_DAY_OFFSET)
| (rtm->tm_hour << LS1X_HOUR_OFFSET)
| (rtm->tm_min << LS1X_MIN_OFFSET)
| (rtm->tm_sec << LS1X_SEC_OFFSET);
writel(v, SYS_TOYWRITE0);
c = 0x10000;
while ((readl(SYS_COUNTER_CNTRL) & SYS_CNTRL_TS) && --c)
usleep_range(1000, 3000);
if (!c) {
dev_err(dev, "set time timeout!\n");
goto err;
}
t = rtm->tm_year + 1900;
writel(t, SYS_TOYWRITE1);
c = 0x10000;
while ((readl(SYS_COUNTER_CNTRL) & SYS_CNTRL_TS) && --c)
usleep_range(1000, 3000);
if (!c) {
dev_err(dev, "set time timeout!\n");
goto err;
}
return 0;
err:
return ret;
}
static int ls1x_rtc_probe(struct platform_device *pdev)
{
struct rtc_device *rtcdev;
unsigned long v;
int ret;
v = readl(SYS_COUNTER_CNTRL);
if (!(v & RTC_CNTR_OK)) {
dev_err(&pdev->dev, "rtc counters not working\n");
ret = -ENODEV;
goto err;
}
ret = -ETIMEDOUT;
if (readl(SYS_TOYTRIM) != 32767) {
v = 0x100000;
while ((readl(SYS_COUNTER_CNTRL) & SYS_CNTRL_TTS) && --v)
usleep_range(1000, 3000);
if (!v) {
dev_err(&pdev->dev, "time out\n");
goto err;
}
writel(32767, SYS_TOYTRIM);
}
while (readl(SYS_COUNTER_CNTRL) & SYS_CNTRL_TTS)
usleep_range(1000, 3000);
rtcdev = devm_rtc_device_register(&pdev->dev, "ls1x-rtc",
&ls1x_rtc_ops , THIS_MODULE);
if (IS_ERR(rtcdev)) {
ret = PTR_ERR(rtcdev);
goto err;
}
platform_set_drvdata(pdev, rtcdev);
return 0;
err:
return ret;
}
