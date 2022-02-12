void __init r8a7779_add_standard_devices(void)
{
r8a7779_pm_init();
r8a7779_init_pm_domain(&r8a7779_sh4a);
r8a7779_init_pm_domain(&r8a7779_sgx);
r8a7779_init_pm_domain(&r8a7779_vdp1);
r8a7779_init_pm_domain(&r8a7779_impx3);
platform_add_devices(r8a7779_early_devices,
ARRAY_SIZE(r8a7779_early_devices));
platform_add_devices(r8a7779_late_devices,
ARRAY_SIZE(r8a7779_late_devices));
}
void __init r8a7779_add_early_devices(void)
{
early_platform_add_devices(r8a7779_early_devices,
ARRAY_SIZE(r8a7779_early_devices));
}
