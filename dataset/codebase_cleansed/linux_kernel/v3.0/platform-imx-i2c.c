struct platform_device *__init imx_add_imx_i2c(
const struct imx_imx_i2c_data *data,
const struct imxi2c_platform_data *pdata)
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
return imx_add_platform_device("imx-i2c", data->id,
res, ARRAY_SIZE(res),
pdata, sizeof(*pdata));
}
