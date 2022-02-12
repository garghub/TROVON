static struct platform_device *__init imx_add_mxc_rnga(
const struct imx_mxc_rnga_data *data)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + SZ_16K - 1,
.flags = IORESOURCE_MEM,
},
};
return imx_add_platform_device("mxc_rnga", -1,
res, ARRAY_SIZE(res), NULL, 0);
}
static int __init imxXX_add_mxc_rnga(void)
{
struct platform_device *ret;
#if defined(CONFIG_SOC_IMX31)
if (cpu_is_mx31())
ret = imx_add_mxc_rnga(&imx31_mxc_rnga_data);
else
#endif
ret = ERR_PTR(-ENODEV);
return PTR_ERR_OR_ZERO(ret);
}
