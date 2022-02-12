void __init r8a73a4_pinmux_init(void)
{
platform_device_register_simple("pfc-r8a73a4", -1, pfc_resources,
ARRAY_SIZE(pfc_resources));
}
void __init r8a73a4_add_dt_devices(void)
{
r8a73a4_register_scif(0);
r8a73a4_register_scif(1);
r8a73a4_register_scif(2);
r8a73a4_register_scif(3);
r8a73a4_register_scif(4);
r8a73a4_register_scif(5);
r8a7790_register_cmt(1);
}
void __init r8a73a4_add_standard_devices(void)
{
r8a73a4_add_dt_devices();
r8a73a4_register_irqc(0);
r8a73a4_register_irqc(1);
r8a73a4_register_thermal();
r8a73a4_register_dmac();
}
void __init r8a73a4_init_early(void)
{
#ifndef CONFIG_ARM_ARCH_TIMER
shmobile_setup_delay(1500, 2, 4);
#endif
}
