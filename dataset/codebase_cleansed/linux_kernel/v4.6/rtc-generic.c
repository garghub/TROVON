static int generic_get_time(struct device *dev, struct rtc_time *tm)
{
unsigned int ret = get_rtc_time(tm);
if (ret & RTC_BATT_BAD)
return -EOPNOTSUPP;
return rtc_valid_tm(tm);
}
static int generic_set_time(struct device *dev, struct rtc_time *tm)
{
if (set_rtc_time(tm) < 0)
return -EOPNOTSUPP;
return 0;
}
static int __init generic_rtc_probe(struct platform_device *dev)
{
struct rtc_device *rtc;
const struct rtc_class_ops *ops;
ops = dev_get_platdata(&dev->dev);
if (!ops)
ops = &generic_rtc_ops;
rtc = devm_rtc_device_register(&dev->dev, "rtc-generic",
ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
platform_set_drvdata(dev, rtc);
return 0;
}
