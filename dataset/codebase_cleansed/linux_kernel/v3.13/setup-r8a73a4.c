void __init r8a73a4_pinmux_init(void)
{
platform_device_register_simple("pfc-r8a73a4", -1, pfc_resources,
ARRAY_SIZE(pfc_resources));
}
static inline void r8a73a4_register_scif(int idx)
{
platform_device_register_data(&platform_bus, "sh-sci", idx, &scif[idx],
sizeof(struct plat_sci_port));
}
void __init r8a73a4_add_dt_devices(void)
{
r8a73a4_register_scif(SCIFA0);
r8a73a4_register_scif(SCIFA1);
r8a73a4_register_scif(SCIFB0);
r8a73a4_register_scif(SCIFB1);
r8a73a4_register_scif(SCIFB2);
r8a73a4_register_scif(SCIFB3);
r8a7790_register_cmt(10);
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
