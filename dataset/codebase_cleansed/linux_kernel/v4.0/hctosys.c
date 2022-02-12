static int __init rtc_hctosys(void)
{
int err = -ENODEV;
struct rtc_time tm;
struct timespec64 tv64 = {
.tv_nsec = NSEC_PER_SEC >> 1,
};
struct rtc_device *rtc = rtc_class_open(CONFIG_RTC_HCTOSYS_DEVICE);
if (rtc == NULL) {
pr_err("%s: unable to open rtc device (%s)\n",
__FILE__, CONFIG_RTC_HCTOSYS_DEVICE);
goto err_open;
}
err = rtc_read_time(rtc, &tm);
if (err) {
dev_err(rtc->dev.parent,
"hctosys: unable to read the hardware clock\n");
goto err_read;
}
tv64.tv_sec = rtc_tm_to_time64(&tm);
err = do_settimeofday64(&tv64);
dev_info(rtc->dev.parent,
"setting system clock to "
"%d-%02d-%02d %02d:%02d:%02d UTC (%lld)\n",
tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
tm.tm_hour, tm.tm_min, tm.tm_sec,
(long long) tv64.tv_sec);
err_read:
rtc_class_close(rtc);
err_open:
rtc_hctosys_ret = err;
return err;
}
