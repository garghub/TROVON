struct platform_device *__init imx_add_sdhci_esdhc_imx(
const struct imx_sdhci_esdhc_imx_data *data,
const struct esdhc_platform_data *pdata)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + SZ_16K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irq,
.end = data->irq,
.flags = IORESOURCE_IRQ,
},
};
if (!pdata)
pdata = &default_esdhc_pdata;
return imx_add_platform_device(data->devid, data->id, res,
ARRAY_SIZE(res), pdata, sizeof(*pdata));
}
