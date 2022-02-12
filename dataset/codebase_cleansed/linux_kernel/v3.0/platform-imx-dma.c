static struct platform_device __init __maybe_unused *imx_add_imx_sdma(
const struct imx_imx_sdma_data *data)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + SZ_4K - 1,
.flags = IORESOURCE_MEM,
}, {
.start = data->irq,
.end = data->irq,
.flags = IORESOURCE_IRQ,
},
};
return imx_add_platform_device("imx-sdma", -1,
res, ARRAY_SIZE(res),
&data->pdata, sizeof(data->pdata));
}
static struct platform_device __init __maybe_unused *imx_add_imx_dma(void)
{
return imx_add_platform_device("imx-dma", -1, NULL, 0, NULL, 0);
}
static int __init imxXX_add_imx_dma(void)
{
struct platform_device *ret;
#if defined(CONFIG_SOC_IMX21) || defined(CONFIG_SOC_IMX27)
if (cpu_is_mx21() || cpu_is_mx27())
ret = imx_add_imx_dma();
else
#endif
#if defined(CONFIG_SOC_IMX25)
if (cpu_is_mx25()) {
imx25_imx_sdma_data.pdata.script_addrs = &addr_imx25_to1;
ret = imx_add_imx_sdma(&imx25_imx_sdma_data);
} else
#endif
#if defined(CONFIG_SOC_IMX31)
if (cpu_is_mx31()) {
int to_version = mx31_revision() >> 4;
imx31_imx_sdma_data.pdata.to_version = to_version;
if (to_version == 1)
imx31_imx_sdma_data.pdata.script_addrs = &addr_imx31_to1;
else
imx31_imx_sdma_data.pdata.script_addrs = &addr_imx31_to2;
ret = imx_add_imx_sdma(&imx31_imx_sdma_data);
} else
#endif
#if defined(CONFIG_SOC_IMX35)
if (cpu_is_mx35()) {
int to_version = mx35_revision() >> 4;
imx35_imx_sdma_data.pdata.to_version = to_version;
if (to_version == 1)
imx35_imx_sdma_data.pdata.script_addrs = &addr_imx35_to1;
else
imx35_imx_sdma_data.pdata.script_addrs = &addr_imx35_to2;
ret = imx_add_imx_sdma(&imx35_imx_sdma_data);
} else
#endif
#if defined(CONFIG_SOC_IMX51)
if (cpu_is_mx51()) {
int to_version = mx51_revision() >> 4;
imx51_imx_sdma_data.pdata.to_version = to_version;
imx51_imx_sdma_data.pdata.script_addrs = &addr_imx51;
ret = imx_add_imx_sdma(&imx51_imx_sdma_data);
} else
#endif
ret = ERR_PTR(-ENODEV);
if (IS_ERR(ret))
return PTR_ERR(ret);
return 0;
}
