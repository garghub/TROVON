struct platform_device *__init imx_add_spi_imx(
const struct imx_spi_imx_data *data,
const struct spi_imx_master *pdata)
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
return imx_add_platform_device(data->devid, data->id,
res, ARRAY_SIZE(res), pdata, sizeof(*pdata));
}
