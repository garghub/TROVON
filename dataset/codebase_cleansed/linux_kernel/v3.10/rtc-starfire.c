static u32 starfire_get_time(void)
{
static char obp_gettod[32];
static u32 unix_tod;
sprintf(obp_gettod, "h# %08x unix-gettod",
(unsigned int) (long) &unix_tod);
prom_feval(obp_gettod);
return unix_tod;
}
static int starfire_read_time(struct device *dev, struct rtc_time *tm)
{
rtc_time_to_tm(starfire_get_time(), tm);
return rtc_valid_tm(tm);
}
static int __init starfire_rtc_probe(struct platform_device *pdev)
{
struct rtc_device *rtc;
rtc = devm_rtc_device_register(&pdev->dev, "starfire",
&starfire_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
platform_set_drvdata(pdev, rtc);
return 0;
}
static int __exit starfire_rtc_remove(struct platform_device *pdev)
{
return 0;
}
