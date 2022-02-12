struct platform_device *__init imx_add_mxc_nand(
const struct imx_mxc_nand_data *data,
const struct mxc_nand_platform_data *pdata)
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
.start = data->axibase,
.end = data->axibase + SZ_16K - 1,
.flags = IORESOURCE_MEM,
},
};
return imx_add_platform_device("mxc_nand", data->id,
res, ARRAY_SIZE(res) - !data->axibase,
pdata, sizeof(*pdata));
}
