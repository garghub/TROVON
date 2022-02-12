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
return imx_add_platform_device("sdhci-esdhc-imx", data->id, res,
ARRAY_SIZE(res), pdata, sizeof(*pdata));
}
