struct platform_device *__init imx_add_imx2_wdt(
const struct imx_imx2_wdt_data *data)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + data->iosize - 1,
.flags = IORESOURCE_MEM,
},
};
return imx_add_platform_device("imx2-wdt", data->id,
res, ARRAY_SIZE(res), NULL, 0);
}
