static int __init emu_init(void)
{
if (!cpu_is_omap34xx())
return -ENODEV;
amba_device_register(&omap3_etb_device, &iomem_resource);
amba_device_register(&omap3_etm_device, &iomem_resource);
return 0;
}
