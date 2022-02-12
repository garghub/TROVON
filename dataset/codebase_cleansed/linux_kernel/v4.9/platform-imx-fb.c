struct platform_device *__init imx_add_imx_fb(
const struct imx_imx_fb_data *data,
const struct imx_fb_platform_data *pdata)
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
return imx_add_platform_device_dmamask(data->devid, 0,
res, ARRAY_SIZE(res),
pdata, sizeof(*pdata), DMA_BIT_MASK(32));
}
