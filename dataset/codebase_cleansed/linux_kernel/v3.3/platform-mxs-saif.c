struct platform_device *__init mxs_add_saif(const struct mxs_saif_data *data,
const struct mxs_saif_platform_data *pdata)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + SZ_4K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irq,
.end = data->irq,
.flags = IORESOURCE_IRQ,
}, {
.start = data->dma,
.end = data->dma,
.flags = IORESOURCE_DMA,
}, {
.start = data->dmairq,
.end = data->dmairq,
.flags = IORESOURCE_IRQ,
},
};
return mxs_add_platform_device("mxs-saif", data->id, res,
ARRAY_SIZE(res), pdata, sizeof(*pdata));
}
