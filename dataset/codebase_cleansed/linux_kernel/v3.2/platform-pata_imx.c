struct platform_device *__init imx_add_pata_imx(
const struct imx_pata_imx_data *data)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + data->iosize - 1,
.flags = IORESOURCE_MEM,
},
{
.start = data->irq,
.end = data->irq,
.flags = IORESOURCE_IRQ,
},
};
return imx_add_platform_device("pata_imx", -1,
res, ARRAY_SIZE(res), NULL, 0);
}
