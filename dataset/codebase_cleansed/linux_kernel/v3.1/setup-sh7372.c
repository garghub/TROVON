void __init sh7372_add_standard_devices(void)
{
sh7372_init_pm_domain(&sh7372_a4lc);
sh7372_init_pm_domain(&sh7372_a4mp);
sh7372_init_pm_domain(&sh7372_d4);
sh7372_init_pm_domain(&sh7372_a3rv);
sh7372_init_pm_domain(&sh7372_a3ri);
sh7372_init_pm_domain(&sh7372_a3sg);
platform_add_devices(sh7372_early_devices,
ARRAY_SIZE(sh7372_early_devices));
platform_add_devices(sh7372_late_devices,
ARRAY_SIZE(sh7372_late_devices));
sh7372_add_device_to_domain(&sh7372_a3rv, &vpu_device);
sh7372_add_device_to_domain(&sh7372_a4mp, &spu0_device);
sh7372_add_device_to_domain(&sh7372_a4mp, &spu1_device);
}
void __init sh7372_add_early_devices(void)
{
early_platform_add_devices(sh7372_early_devices,
ARRAY_SIZE(sh7372_early_devices));
}
