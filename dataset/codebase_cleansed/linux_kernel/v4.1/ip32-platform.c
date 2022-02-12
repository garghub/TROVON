static int __init uart8250_init(void)
{
return platform_device_register(&uart8250_device);
}
static __init int meth_devinit(void)
{
struct platform_device *pd;
int ret;
pd = platform_device_alloc("meth", -1);
if (!pd)
return -ENOMEM;
ret = platform_device_add(pd);
if (ret)
platform_device_put(pd);
return ret;
}
static __init int sgio2audio_devinit(void)
{
struct platform_device *pd;
int ret;
pd = platform_device_alloc("sgio2audio", -1);
if (!pd)
return -ENOMEM;
ret = platform_device_add(pd);
if (ret)
platform_device_put(pd);
return ret;
}
static __init int sgio2btns_devinit(void)
{
return IS_ERR(platform_device_register_simple("sgibtns", -1, NULL, 0));
}
static __init int sgio2_rtc_devinit(void)
{
return platform_device_register(&ip32_rtc_device);
}
