void __init sh7372_map_io(void)
{
iotable_init(sh7372_io_desc, ARRAY_SIZE(sh7372_io_desc));
}
void __init sh7372_add_standard_devices(void)
{
struct pm_domain_device domain_devices[] = {
{ "A3RV", &vpu_device, },
{ "A4MP", &spu0_device, },
{ "A4MP", &spu1_device, },
{ "A3SP", &scif0_device, },
{ "A3SP", &scif1_device, },
{ "A3SP", &scif2_device, },
{ "A3SP", &scif3_device, },
{ "A3SP", &scif4_device, },
{ "A3SP", &scif5_device, },
{ "A3SP", &scif6_device, },
{ "A3SP", &iic1_device, },
{ "A3SP", &dma0_device, },
{ "A3SP", &dma1_device, },
{ "A3SP", &dma2_device, },
{ "A3SP", &usb_dma0_device, },
{ "A3SP", &usb_dma1_device, },
{ "A4R", &iic0_device, },
{ "A4R", &veu0_device, },
{ "A4R", &veu1_device, },
{ "A4R", &veu2_device, },
{ "A4R", &veu3_device, },
{ "A4R", &jpu_device, },
{ "A4R", &tmu00_device, },
{ "A4R", &tmu01_device, },
};
sh7372_init_pm_domains();
platform_add_devices(sh7372_early_devices,
ARRAY_SIZE(sh7372_early_devices));
platform_add_devices(sh7372_late_devices,
ARRAY_SIZE(sh7372_late_devices));
rmobile_add_devices_to_domains(domain_devices,
ARRAY_SIZE(domain_devices));
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
