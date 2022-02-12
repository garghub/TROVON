struct platform_device *__init imx_add_imx27_coda(
const struct imx_imx27_coda_data *data)
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
return imx_add_platform_device_dmamask("coda-imx27", 0, res, 2, NULL,
0, DMA_BIT_MASK(32));
}
