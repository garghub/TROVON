struct platform_device *__init mxs_add_auart(
const struct mxs_auart_data *data)
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
return mxs_add_platform_device_dmamask("mxs-auart", data->id,
res, ARRAY_SIZE(res), NULL, 0,
DMA_BIT_MASK(32));
}
