int rtc_set_ntp_time(struct timespec now)
{
struct rtc_device *rtc;
struct rtc_time tm;
int err = -ENODEV;
if (now.tv_nsec < (NSEC_PER_SEC >> 1))
rtc_time_to_tm(now.tv_sec, &tm);
else
rtc_time_to_tm(now.tv_sec + 1, &tm);
rtc = rtc_class_open(CONFIG_RTC_HCTOSYS_DEVICE);
if (rtc) {
if (rtc->ops && (rtc->ops->set_time || rtc->ops->set_mmss))
err = rtc_set_time(rtc, &tm);
rtc_class_close(rtc);
}
return err;
}
