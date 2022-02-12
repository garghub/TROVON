static int __init sh770x_devices_setup(void)
{
return platform_add_devices(sh770x_devices,
ARRAY_SIZE(sh770x_devices));
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh770x_early_devices,
ARRAY_SIZE(sh770x_early_devices));
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
#if defined(CONFIG_CPU_SUBTYPE_SH7706) || \
defined(CONFIG_CPU_SUBTYPE_SH7707) || \
defined(CONFIG_CPU_SUBTYPE_SH7709)
plat_irq_setup_sh3();
#endif
}
