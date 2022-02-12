static int pl08x_get_xfer_signal(const struct pl08x_channel_data *cd)
{
return cd->min_signal;
}
static void pl08x_put_xfer_signal(const struct pl08x_channel_data *cd, int ch)
{
}
static int __init s3c64xx_pl080_init(void)
{
if (!soc_is_s3c64xx())
return 0;
writel(0xffffff, S3C64XX_SDMA_SEL);
if (of_have_populated_dt())
return 0;
amba_device_register(&s3c64xx_dma0_device, &iomem_resource);
amba_device_register(&s3c64xx_dma1_device, &iomem_resource);
return 0;
}
