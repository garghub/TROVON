static u64 read_rtc(void)
{
int result;
u64 rtc_val;
u64 tb_val;
result = lv1_get_rtc(&rtc_val, &tb_val);
BUG_ON(result);
return rtc_val;
}
static int ps3_get_time(struct device *dev, struct rtc_time *tm)
{
rtc_time_to_tm(read_rtc() + ps3_os_area_get_rtc_diff(), tm);
return rtc_valid_tm(tm);
}
static int ps3_set_time(struct device *dev, struct rtc_time *tm)
{
unsigned long now;
rtc_tm_to_time(tm, &now);
ps3_os_area_set_rtc_diff(now - read_rtc());
return 0;
}
static int __init ps3_rtc_probe(struct platform_device *dev)
{
struct rtc_device *rtc;
rtc = devm_rtc_device_register(&dev->dev, "rtc-ps3", &ps3_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
platform_set_drvdata(dev, rtc);
return 0;
}
static int __exit ps3_rtc_remove(struct platform_device *dev)
{
return 0;
}
