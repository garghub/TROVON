struct platform_device *__init mxs_add_mxs_i2c(
const struct mxs_mxs_i2c_data *data)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + SZ_8K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->errirq,
.end = data->errirq,
.flags = IORESOURCE_IRQ,
}, {
.start = data->dmairq,
.end = data->dmairq,
.flags = IORESOURCE_IRQ,
},
};
return mxs_add_platform_device("mxs-i2c", data->id, res,
ARRAY_SIZE(res), NULL, 0);
}
