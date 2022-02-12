struct platform_device *__init imx_add_imx21_hcd(
const struct imx_imx21_hcd_data *data,
const struct mx21_usbh_platform_data *pdata)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + SZ_8K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irq,
.end = data->irq,
.flags = IORESOURCE_IRQ,
},
};
return imx_add_platform_device_dmamask("imx21-hcd", 0,
res, ARRAY_SIZE(res),
pdata, sizeof(*pdata), DMA_BIT_MASK(32));
}
