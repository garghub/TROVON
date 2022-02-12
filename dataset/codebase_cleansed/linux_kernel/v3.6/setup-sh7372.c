void __init sh7372_map_io(void)
{
iotable_init(sh7372_io_desc, ARRAY_SIZE(sh7372_io_desc));
init_consistent_dma_size(12 << 20);
}
void __init sh7372_add_standard_devices(void)
{
rmobile_init_pm_domain(&sh7372_pd_a4lc);
rmobile_init_pm_domain(&sh7372_pd_a4mp);
rmobile_init_pm_domain(&sh7372_pd_d4);
rmobile_init_pm_domain(&sh7372_pd_a4r);
rmobile_init_pm_domain(&sh7372_pd_a3rv);
rmobile_init_pm_domain(&sh7372_pd_a3ri);
rmobile_init_pm_domain(&sh7372_pd_a4s);
rmobile_init_pm_domain(&sh7372_pd_a3sp);
rmobile_init_pm_domain(&sh7372_pd_a3sg);
rmobile_pm_add_subdomain(&sh7372_pd_a4lc, &sh7372_pd_a3rv);
rmobile_pm_add_subdomain(&sh7372_pd_a4r, &sh7372_pd_a4lc);
rmobile_pm_add_subdomain(&sh7372_pd_a4s, &sh7372_pd_a3sg);
rmobile_pm_add_subdomain(&sh7372_pd_a4s, &sh7372_pd_a3sp);
platform_add_devices(sh7372_early_devices,
ARRAY_SIZE(sh7372_early_devices));
platform_add_devices(sh7372_late_devices,
ARRAY_SIZE(sh7372_late_devices));
rmobile_add_device_to_domain(&sh7372_pd_a3rv, &vpu_device);
rmobile_add_device_to_domain(&sh7372_pd_a4mp, &spu0_device);
rmobile_add_device_to_domain(&sh7372_pd_a4mp, &spu1_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &scif0_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &scif1_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &scif2_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &scif3_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &scif4_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &scif5_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &scif6_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &iic1_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &dma0_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &dma1_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &dma2_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &usb_dma0_device);
rmobile_add_device_to_domain(&sh7372_pd_a3sp, &usb_dma1_device);
rmobile_add_device_to_domain(&sh7372_pd_a4r, &iic0_device);
rmobile_add_device_to_domain(&sh7372_pd_a4r, &veu0_device);
rmobile_add_device_to_domain(&sh7372_pd_a4r, &veu1_device);
rmobile_add_device_to_domain(&sh7372_pd_a4r, &veu2_device);
rmobile_add_device_to_domain(&sh7372_pd_a4r, &veu3_device);
rmobile_add_device_to_domain(&sh7372_pd_a4r, &jpu_device);
rmobile_add_device_to_domain(&sh7372_pd_a4r, &tmu00_device);
rmobile_add_device_to_domain(&sh7372_pd_a4r, &tmu01_device);
}
static void __init sh7372_earlytimer_init(void)
{
sh7372_clock_init();
shmobile_earlytimer_init();
}
void __init sh7372_add_early_devices(void)
{
early_platform_add_devices(sh7372_early_devices,
ARRAY_SIZE(sh7372_early_devices));
shmobile_setup_console();
shmobile_timer.init = sh7372_earlytimer_init;
}
void __init sh7372_add_early_devices_dt(void)
{
shmobile_setup_delay(800, 1, 3);
early_platform_add_devices(sh7372_early_devices,
ARRAY_SIZE(sh7372_early_devices));
shmobile_setup_console();
}
void __init sh7372_add_standard_devices_dt(void)
{
sh7372_clock_init();
platform_add_devices(sh7372_early_devices,
ARRAY_SIZE(sh7372_early_devices));
of_platform_populate(NULL, of_default_bus_match_table,
sh7372_auxdata_lookup, NULL);
}
