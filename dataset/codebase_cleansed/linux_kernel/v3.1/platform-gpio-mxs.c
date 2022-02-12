struct platform_device *__init mxs_add_gpio(
int id, resource_size_t iobase, int irq)
{
struct resource res[] = {
{
.start = iobase,
.end = iobase + SZ_8K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = irq,
.end = irq,
.flags = IORESOURCE_IRQ,
},
};
return platform_device_register_resndata(&mxs_apbh_bus,
"gpio-mxs", id, res, ARRAY_SIZE(res), NULL, 0);
}
static int __init mxs_add_mxs_gpio(void)
{
if (cpu_is_mx23()) {
mxs_add_gpio(0, MX23_PINCTRL_BASE_ADDR, MX23_INT_GPIO0);
mxs_add_gpio(1, MX23_PINCTRL_BASE_ADDR, MX23_INT_GPIO1);
mxs_add_gpio(2, MX23_PINCTRL_BASE_ADDR, MX23_INT_GPIO2);
}
if (cpu_is_mx28()) {
mxs_add_gpio(0, MX28_PINCTRL_BASE_ADDR, MX28_INT_GPIO0);
mxs_add_gpio(1, MX28_PINCTRL_BASE_ADDR, MX28_INT_GPIO1);
mxs_add_gpio(2, MX28_PINCTRL_BASE_ADDR, MX28_INT_GPIO2);
mxs_add_gpio(3, MX28_PINCTRL_BASE_ADDR, MX28_INT_GPIO3);
mxs_add_gpio(4, MX28_PINCTRL_BASE_ADDR, MX28_INT_GPIO4);
}
return 0;
}
