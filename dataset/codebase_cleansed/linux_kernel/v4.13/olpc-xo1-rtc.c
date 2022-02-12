static void rtc_wake_on(struct device *dev)
{
olpc_xo1_pm_wakeup_set(CS5536_PM_RTC);
}
static void rtc_wake_off(struct device *dev)
{
olpc_xo1_pm_wakeup_clear(CS5536_PM_RTC);
}
static int __init xo1_rtc_init(void)
{
int r;
struct device_node *node;
node = of_find_compatible_node(NULL, NULL, "olpc,xo1-rtc");
if (!node)
return 0;
of_node_put(node);
pr_info("olpc-xo1-rtc: Initializing OLPC XO-1 RTC\n");
rdmsrl(MSR_RTC_DOMA_OFFSET, rtc_info.rtc_day_alarm);
rdmsrl(MSR_RTC_MONA_OFFSET, rtc_info.rtc_mon_alarm);
rdmsrl(MSR_RTC_CEN_OFFSET, rtc_info.rtc_century);
r = platform_device_register(&xo1_rtc_device);
if (r)
return r;
device_init_wakeup(&xo1_rtc_device.dev, 1);
return 0;
}
