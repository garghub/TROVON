struct platform_device *__init mxs_add_mxs_mmc(
const struct mxs_mxs_mmc_data *data,
const struct mxs_mmc_platform_data *pdata)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + SZ_8K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->dma,
.end = data->dma,
.flags = IORESOURCE_DMA,
}, {
.start = data->irq_err,
.end = data->irq_err,
.flags = IORESOURCE_IRQ,
}, {
.start = data->irq_dma,
.end = data->irq_dma,
.flags = IORESOURCE_IRQ,
},
};
return mxs_add_platform_device("mxs-mmc", data->id,
res, ARRAY_SIZE(res), pdata, sizeof(*pdata));
}
