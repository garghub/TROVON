struct platform_device *__init imx_add_mxc_w1(
const struct imx_mxc_w1_data *data)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + SZ_4K - 1,
.flags = IORESOURCE_MEM,
},
};
return imx_add_platform_device("mxc_w1", 0,
res, ARRAY_SIZE(res), NULL, 0);
}
