void __init sh7372_add_standard_devices(void)
{
sh7372_init_pm_domain(&sh7372_a4lc);
sh7372_init_pm_domain(&sh7372_a4mp);
sh7372_init_pm_domain(&sh7372_d4);
sh7372_init_pm_domain(&sh7372_a4r);
sh7372_init_pm_domain(&sh7372_a3rv);
sh7372_init_pm_domain(&sh7372_a3ri);
sh7372_init_pm_domain(&sh7372_a3sg);
sh7372_init_pm_domain(&sh7372_a3sp);
sh7372_pm_add_subdomain(&sh7372_a4lc, &sh7372_a3rv);
sh7372_pm_add_subdomain(&sh7372_a4r, &sh7372_a4lc);
platform_add_devices(sh7372_early_devices,
ARRAY_SIZE(sh7372_early_devices));
platform_add_devices(sh7372_late_devices,
ARRAY_SIZE(sh7372_late_devices));
sh7372_add_device_to_domain(&sh7372_a3rv, &vpu_device);
sh7372_add_device_to_domain(&sh7372_a4mp, &spu0_device);
sh7372_add_device_to_domain(&sh7372_a4mp, &spu1_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &scif0_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &scif1_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &scif2_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &scif3_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &scif4_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &scif5_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &scif6_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &iic1_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &dma0_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &dma1_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &dma2_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &usb_dma0_device);
sh7372_add_device_to_domain(&sh7372_a3sp, &usb_dma1_device);
sh7372_add_device_to_domain(&sh7372_a4r, &iic0_device);
sh7372_add_device_to_domain(&sh7372_a4r, &veu0_device);
sh7372_add_device_to_domain(&sh7372_a4r, &veu1_device);
sh7372_add_device_to_domain(&sh7372_a4r, &veu2_device);
sh7372_add_device_to_domain(&sh7372_a4r, &veu3_device);
sh7372_add_device_to_domain(&sh7372_a4r, &jpu_device);
}
void __init sh7372_add_early_devices(void)
{
early_platform_add_devices(sh7372_early_devices,
ARRAY_SIZE(sh7372_early_devices));
}
