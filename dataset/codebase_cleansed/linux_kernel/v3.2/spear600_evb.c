static void __init spear600_evb_init(void)
{
unsigned int i;
spear600_init();
platform_add_devices(plat_devs, ARRAY_SIZE(plat_devs));
for (i = 0; i < ARRAY_SIZE(amba_devs); i++)
amba_device_register(amba_devs[i], &iomem_resource);
}
