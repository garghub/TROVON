static void __init spear320_evb_init(void)
{
unsigned int i;
spear320_init(&spear320_auto_net_mii_mode, pmx_devs,
ARRAY_SIZE(pmx_devs));
platform_add_devices(plat_devs, ARRAY_SIZE(plat_devs));
for (i = 0; i < ARRAY_SIZE(amba_devs); i++)
amba_device_register(amba_devs[i], &iomem_resource);
}
