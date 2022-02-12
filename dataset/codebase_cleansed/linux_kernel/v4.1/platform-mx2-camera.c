struct platform_device *__init imx_add_mx2_camera(
const struct imx_mx2_camera_data *data,
const struct mx2_camera_platform_data *pdata)
{
struct resource res[] = {
{
.start = data->iobasecsi,
.end = data->iobasecsi + data->iosizecsi - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irqcsi,
.end = data->irqcsi,
.flags = IORESOURCE_IRQ,
}, {
.start = data->iobaseemmaprp,
.end = data->iobaseemmaprp + data->iosizeemmaprp - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irqemmaprp,
.end = data->irqemmaprp,
.flags = IORESOURCE_IRQ,
},
};
return imx_add_platform_device_dmamask(data->devid, 0,
res, data->iobaseemmaprp ? 4 : 2,
pdata, sizeof(*pdata), DMA_BIT_MASK(32));
}
