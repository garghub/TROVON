void __init db5500_dma_init(void)
{
int ret;
ret = platform_device_register(&dma40_device);
if (ret)
dev_err(&dma40_device.dev, "unable to register device: %d\n", ret);
}
