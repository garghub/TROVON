static inline void r7s72100_register_scif(int idx)
{
platform_device_register_data(&platform_bus, "sh-sci", idx, &scif[idx],
sizeof(struct plat_sci_port));
}
void __init r7s72100_add_dt_devices(void)
{
r7s72100_register_scif(SCIF0);
r7s72100_register_scif(SCIF1);
r7s72100_register_scif(SCIF2);
r7s72100_register_scif(SCIF3);
r7s72100_register_scif(SCIF4);
r7s72100_register_scif(SCIF5);
r7s72100_register_scif(SCIF6);
r7s72100_register_scif(SCIF7);
}
void __init r7s72100_init_early(void)
{
shmobile_setup_delay(400, 1, 3);
}
