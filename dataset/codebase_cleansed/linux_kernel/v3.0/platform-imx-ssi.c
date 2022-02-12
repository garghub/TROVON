struct platform_device *__init imx_add_imx_ssi(
const struct imx_imx_ssi_data *data,
const struct imx_ssi_platform_data *pdata)
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
#define DMARES(_name) { \
.name = #_name, \
.start = data->dma ## _name, \
.end = data->dma ## _name, \
.flags = IORESOURCE_DMA, \
}
DMARES(tx0),
DMARES(rx0),
DMARES(tx1),
DMARES(rx1),
};
return imx_add_platform_device("imx-ssi", data->id,
res, ARRAY_SIZE(res),
pdata, sizeof(*pdata));
}
