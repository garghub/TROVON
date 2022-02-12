struct platform_device *__init mxs_add_fec(
const struct mxs_fec_data *data,
const struct fec_platform_data *pdata)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + SZ_16K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irq,
.end = data->irq,
.flags = IORESOURCE_IRQ,
},
};
return mxs_add_platform_device_dmamask("imx28-fec", data->id,
res, ARRAY_SIZE(res), pdata, sizeof(*pdata),
DMA_BIT_MASK(32));
}
