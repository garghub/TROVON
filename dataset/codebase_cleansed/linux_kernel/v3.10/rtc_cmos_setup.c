static int __init add_rtc(void)
{
struct device_node *np;
struct platform_device *pd;
struct resource res[2];
unsigned int num_res = 1;
int ret;
memset(&res, 0, sizeof(res));
np = of_find_compatible_node(NULL, NULL, "pnpPNP,b00");
if (!np)
return -ENODEV;
ret = of_address_to_resource(np, 0, &res[0]);
of_node_put(np);
if (ret)
return ret;
if (res[0].start != RTC_PORT(0))
return -EINVAL;
np = of_find_compatible_node(NULL, NULL, "chrp,iic");
if (!np)
np = of_find_compatible_node(NULL, NULL, "pnpPNP,000");
if (np) {
of_node_put(np);
res[1].start = 8;
res[1].end = 8;
res[1].flags = IORESOURCE_IRQ;
num_res++;
}
pd = platform_device_register_simple("rtc_cmos", -1,
&res[0], num_res);
return PTR_RET(pd);
}
