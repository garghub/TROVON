struct platform_device __init __maybe_unused *imx_add_imx_dma(void)
{
return platform_device_register_resndata(&mxc_ahb_bus,
"imx-dma", -1, NULL, 0, NULL, 0);
}
struct platform_device __init __maybe_unused *imx_add_imx_sdma(char *name,
resource_size_t iobase, int irq, struct sdma_platform_data *pdata)
{
struct resource res[] = {
{
.start = iobase,
.end = iobase + SZ_16K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = irq,
.end = irq,
.flags = IORESOURCE_IRQ,
},
};
return platform_device_register_resndata(&mxc_ahb_bus, name,
-1, res, ARRAY_SIZE(res), pdata, sizeof(*pdata));
}
