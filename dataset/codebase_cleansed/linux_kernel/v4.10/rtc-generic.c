static int __init generic_rtc_probe(struct platform_device *dev)
{
struct rtc_device *rtc;
const struct rtc_class_ops *ops = dev_get_platdata(&dev->dev);
rtc = devm_rtc_device_register(&dev->dev, "rtc-generic",
ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
platform_set_drvdata(dev, rtc);
return 0;
}
