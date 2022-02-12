struct platform_device *__init imx_add_mxc_pwm(
const struct imx_mxc_pwm_data *data)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + data->iosize - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irq,
.end = data->irq,
.flags = IORESOURCE_IRQ,
},
};
return imx_add_platform_device("mxc_pwm", data->id,
res, ARRAY_SIZE(res), NULL, 0);
}
