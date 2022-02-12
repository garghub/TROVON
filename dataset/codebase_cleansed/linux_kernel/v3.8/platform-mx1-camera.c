struct platform_device *__init imx_add_mx1_camera(
const struct imx_mx1_camera_data *data,
const struct mx1_camera_pdata *pdata)
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
return imx_add_platform_device_dmamask("mx1-camera", 0,
res, ARRAY_SIZE(res),
pdata, sizeof(*pdata), DMA_BIT_MASK(32));
}
