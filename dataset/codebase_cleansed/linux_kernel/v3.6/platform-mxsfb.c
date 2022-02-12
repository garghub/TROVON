struct platform_device *__init mx23_add_mxsfb(
const struct mxsfb_platform_data *pdata)
{
struct resource res[] = {
{
.start = MX23_LCDIF_BASE_ADDR,
.end = MX23_LCDIF_BASE_ADDR + SZ_8K - 1,
.flags = IORESOURCE_MEM,
},
};
return mxs_add_platform_device_dmamask("imx23-fb", -1,
res, ARRAY_SIZE(res), pdata, sizeof(*pdata), DMA_BIT_MASK(32));
}
struct platform_device *__init mx28_add_mxsfb(
const struct mxsfb_platform_data *pdata)
{
struct resource res[] = {
{
.start = MX28_LCDIF_BASE_ADDR,
.end = MX28_LCDIF_BASE_ADDR + SZ_8K - 1,
.flags = IORESOURCE_MEM,
},
};
return mxs_add_platform_device_dmamask("imx28-fb", -1,
res, ARRAY_SIZE(res), pdata, sizeof(*pdata), DMA_BIT_MASK(32));
}
