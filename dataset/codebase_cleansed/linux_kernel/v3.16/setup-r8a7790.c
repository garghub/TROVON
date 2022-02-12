void __init r8a7790_add_dt_devices(void)
{
r8a7790_register_cmt(0);
}
void __init r8a7790_add_standard_devices(void)
{
r8a7790_register_scif(0);
r8a7790_register_scif(1);
r8a7790_register_scif(2);
r8a7790_register_scif(3);
r8a7790_register_scif(4);
r8a7790_register_scif(5);
r8a7790_register_scif(6);
r8a7790_register_scif(7);
r8a7790_register_scif(8);
r8a7790_register_scif(9);
r8a7790_add_dt_devices();
r8a7790_register_irqc(0);
r8a7790_register_thermal();
r8a7790_register_i2c(0);
r8a7790_register_i2c(1);
r8a7790_register_i2c(2);
r8a7790_register_i2c(3);
r8a7790_register_audio_dmac(0);
r8a7790_register_audio_dmac(1);
}
void __init r8a7790_init_early(void)
{
#ifndef CONFIG_ARM_ARCH_TIMER
shmobile_setup_delay(1300, 2, 4);
#endif
}
