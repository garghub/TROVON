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
return imx_add_platform_device_dmamask("mx2-camera", 0,
res, data->iobaseemmaprp ? 4 : 2,
pdata, sizeof(*pdata), DMA_BIT_MASK(32));
}
struct platform_device *__init imx_add_mx2_emmaprp(
const struct imx_mx2_camera_data *data)
{
struct resource res[] = {
{
.start = data->iobaseemmaprp,
.end = data->iobaseemmaprp + data->iosizeemmaprp - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irqemmaprp,
.end = data->irqemmaprp,
.flags = IORESOURCE_IRQ,
},
};
return imx_add_platform_device_dmamask("m2m-emmaprp", 0,
res, 2, NULL, 0, DMA_BIT_MASK(32));
}
