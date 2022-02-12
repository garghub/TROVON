struct platform_device *__init mx23_add_rtc_stmp3xxx(void)
{
struct resource res[] = {
{
.start = MX23_RTC_BASE_ADDR,
.end = MX23_RTC_BASE_ADDR + SZ_8K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = MX23_INT_RTC_ALARM,
.end = MX23_INT_RTC_ALARM,
.flags = IORESOURCE_IRQ,
},
};
return mxs_add_platform_device("stmp3xxx-rtc", 0, res, ARRAY_SIZE(res),
NULL, 0);
}
struct platform_device *__init mx28_add_rtc_stmp3xxx(void)
{
struct resource res[] = {
{
.start = MX28_RTC_BASE_ADDR,
.end = MX28_RTC_BASE_ADDR + SZ_8K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = MX28_INT_RTC_ALARM,
.end = MX28_INT_RTC_ALARM,
.flags = IORESOURCE_IRQ,
},
};
return mxs_add_platform_device("stmp3xxx-rtc", 0, res, ARRAY_SIZE(res),
NULL, 0);
}
