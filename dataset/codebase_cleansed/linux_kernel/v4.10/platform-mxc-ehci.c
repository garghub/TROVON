struct platform_device *__init imx_add_mxc_ehci(
const struct imx_mxc_ehci_data *data,
const struct mxc_usbh_platform_data *pdata)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + SZ_512 - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irq,
.end = data->irq,
.flags = IORESOURCE_IRQ,
},
};
return imx_add_platform_device_dmamask("mxc-ehci", data->id,
res, ARRAY_SIZE(res),
pdata, sizeof(*pdata), DMA_BIT_MASK(32));
}
