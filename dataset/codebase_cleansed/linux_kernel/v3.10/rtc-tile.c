static int read_rtc_time(struct device *dev, struct rtc_time *tm)
{
HV_RTCTime hvtm = hv_get_rtc();
tm->tm_sec = hvtm.tm_sec;
tm->tm_min = hvtm.tm_min;
tm->tm_hour = hvtm.tm_hour;
tm->tm_mday = hvtm.tm_mday;
tm->tm_mon = hvtm.tm_mon;
tm->tm_year = hvtm.tm_year;
tm->tm_wday = 0;
tm->tm_yday = 0;
tm->tm_isdst = 0;
if (rtc_valid_tm(tm) < 0)
dev_warn(dev, "Read invalid date/time from RTC\n");
return 0;
}
static int set_rtc_time(struct device *dev, struct rtc_time *tm)
{
HV_RTCTime hvtm;
hvtm.tm_sec = tm->tm_sec;
hvtm.tm_min = tm->tm_min;
hvtm.tm_hour = tm->tm_hour;
hvtm.tm_mday = tm->tm_mday;
hvtm.tm_mon = tm->tm_mon;
hvtm.tm_year = tm->tm_year;
hv_set_rtc(hvtm);
return 0;
}
static int tile_rtc_probe(struct platform_device *dev)
{
struct rtc_device *rtc;
rtc = devm_rtc_device_register(&dev->dev, "tile",
&tile_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
platform_set_drvdata(dev, rtc);
return 0;
}
static int tile_rtc_remove(struct platform_device *dev)
{
platform_set_drvdata(dev, NULL);
return 0;
}
static int __init tile_rtc_driver_init(void)
{
int err;
err = platform_driver_register(&tile_rtc_platform_driver);
if (err)
return err;
tile_rtc_platform_device = platform_device_alloc("rtc-tile", 0);
if (tile_rtc_platform_device == NULL) {
err = -ENOMEM;
goto exit_driver_unregister;
}
err = platform_device_add(tile_rtc_platform_device);
if (err)
goto exit_device_put;
return 0;
exit_device_put:
platform_device_put(tile_rtc_platform_device);
exit_driver_unregister:
platform_driver_unregister(&tile_rtc_platform_driver);
return err;
}
static void __exit tile_rtc_driver_exit(void)
{
platform_device_unregister(tile_rtc_platform_device);
platform_driver_unregister(&tile_rtc_platform_driver);
}
