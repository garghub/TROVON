struct platform_device *__init mxs_add_dma(const char *devid,
resource_size_t base)
{
struct resource res[] = {
{
.start = base,
.end = base + SZ_8K - 1,
.flags = IORESOURCE_MEM,
}
};
return mxs_add_platform_device_dmamask(devid, -1,
res, ARRAY_SIZE(res), NULL, 0,
DMA_BIT_MASK(32));
}
