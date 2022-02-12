struct platform_device *__init imx_add_mxc_rtc(
const struct imx_mxc_rtc_data *data)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + SZ_16K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irq,
.end = data->irq,
.flags = IORESOURCE_IRQ,
},
};
return imx_add_platform_device("mxc_rtc", -1,
res, ARRAY_SIZE(res), NULL, 0);
}
