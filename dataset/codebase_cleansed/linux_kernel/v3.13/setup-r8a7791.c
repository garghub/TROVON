static inline void r8a7791_register_scif(int idx)
{
platform_device_register_data(&platform_bus, "sh-sci", idx, &scif[idx],
sizeof(struct plat_sci_port));
}
void __init r8a7791_add_dt_devices(void)
{
r8a7791_register_scif(SCIFA0);
r8a7791_register_scif(SCIFA1);
r8a7791_register_scif(SCIFB0);
r8a7791_register_scif(SCIFB1);
r8a7791_register_scif(SCIFB2);
r8a7791_register_scif(SCIFA2);
r8a7791_register_scif(SCIF0);
r8a7791_register_scif(SCIF1);
r8a7791_register_scif(SCIF2);
r8a7791_register_scif(SCIF3);
r8a7791_register_scif(SCIF4);
r8a7791_register_scif(SCIF5);
r8a7791_register_scif(SCIFA3);
r8a7791_register_scif(SCIFA4);
r8a7791_register_scif(SCIFA5);
r8a7791_register_cmt(00);
}
void __init r8a7791_add_standard_devices(void)
{
r8a7791_add_dt_devices();
r8a7791_register_irqc(0);
}
void __init r8a7791_init_early(void)
{
#ifndef CONFIG_ARM_ARCH_TIMER
shmobile_setup_delay(1300, 2, 4);
#endif
}
