static int au1xtoy_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
unsigned long t;
t = alchemy_rdsys(AU1000_SYS_TOYREAD);
rtc_time_to_tm(t, tm);
return rtc_valid_tm(tm);
}
static int au1xtoy_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
unsigned long t;
rtc_tm_to_time(tm, &t);
alchemy_wrsys(t, AU1000_SYS_TOYWRITE);
while (alchemy_rdsys(AU1000_SYS_CNTRCTRL) & SYS_CNTRL_C0S)
msleep(1);
return 0;
}
static int au1xtoy_rtc_probe(struct platform_device *pdev)
{
struct rtc_device *rtcdev;
unsigned long t;
int ret;
t = alchemy_rdsys(AU1000_SYS_CNTRCTRL);
if (!(t & CNTR_OK)) {
dev_err(&pdev->dev, "counters not working; aborting.\n");
ret = -ENODEV;
goto out_err;
}
ret = -ETIMEDOUT;
if (alchemy_rdsys(AU1000_SYS_TOYTRIM) != 32767) {
t = 0x00100000;
while ((alchemy_rdsys(AU1000_SYS_CNTRCTRL) & SYS_CNTRL_T0S) && --t)
msleep(1);
if (!t) {
dev_err(&pdev->dev, "timeout waiting for access\n");
goto out_err;
}
alchemy_wrsys(32767, AU1000_SYS_TOYTRIM);
}
while (alchemy_rdsys(AU1000_SYS_CNTRCTRL) & SYS_CNTRL_C0S)
msleep(1);
rtcdev = devm_rtc_device_register(&pdev->dev, "rtc-au1xxx",
&au1xtoy_rtc_ops, THIS_MODULE);
if (IS_ERR(rtcdev)) {
ret = PTR_ERR(rtcdev);
goto out_err;
}
platform_set_drvdata(pdev, rtcdev);
return 0;
out_err:
return ret;
}
