struct platform_device *__init imx_add_flexcan(
const struct imx_flexcan_data *data)
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
};
return imx_add_platform_device("flexcan", data->id,
res, ARRAY_SIZE(res), NULL, 0);
}
