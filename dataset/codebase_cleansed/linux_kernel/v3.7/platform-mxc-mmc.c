struct platform_device *__init imx_add_mxc_mmc(
const struct imx_mxc_mmc_data *data,
const struct imxmmc_platform_data *pdata)
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
}, {
.start = data->dmareq,
.end = data->dmareq,
.flags = IORESOURCE_DMA,
},
};
return imx_add_platform_device_dmamask("mxc-mmc", data->id,
res, ARRAY_SIZE(res),
pdata, sizeof(*pdata), DMA_BIT_MASK(32));
}
