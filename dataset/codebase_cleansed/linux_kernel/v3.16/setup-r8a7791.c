void __init r8a7791_pinmux_init(void)
{
r8a7791_register_pfc();
r8a7791_register_gpio(0);
r8a7791_register_gpio(1);
r8a7791_register_gpio(2);
r8a7791_register_gpio(3);
r8a7791_register_gpio(4);
r8a7791_register_gpio(5);
r8a7791_register_gpio(6);
r8a7791_register_gpio(7);
}
void __init r8a7791_add_dt_devices(void)
{
r8a7791_register_cmt(0);
}
void __init r8a7791_add_standard_devices(void)
{
r8a7791_register_scif(0);
r8a7791_register_scif(1);
r8a7791_register_scif(2);
r8a7791_register_scif(3);
r8a7791_register_scif(4);
r8a7791_register_scif(5);
r8a7791_register_scif(6);
r8a7791_register_scif(7);
r8a7791_register_scif(8);
r8a7791_register_scif(9);
r8a7791_register_scif(10);
r8a7791_register_scif(11);
r8a7791_register_scif(12);
r8a7791_register_scif(13);
r8a7791_register_scif(14);
r8a7791_add_dt_devices();
r8a7791_register_irqc(0);
r8a7791_register_thermal();
}
