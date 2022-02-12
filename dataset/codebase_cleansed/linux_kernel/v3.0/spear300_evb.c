static void __init spear300_evb_init(void)
{
unsigned int i;
spear300_init(&spear300_photo_frame_mode, pmx_devs,
ARRAY_SIZE(pmx_devs));
platform_add_devices(plat_devs, ARRAY_SIZE(plat_devs));
for (i = 0; i < ARRAY_SIZE(amba_devs); i++)
amba_device_register(amba_devs[i], &iomem_resource);
}
