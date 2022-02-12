void __init r7s72100_add_dt_devices(void)
{
r7s72100_register_scif(0);
r7s72100_register_scif(1);
r7s72100_register_scif(2);
r7s72100_register_scif(3);
r7s72100_register_scif(4);
r7s72100_register_scif(5);
r7s72100_register_scif(6);
r7s72100_register_scif(7);
r7s72100_register_mtu2(0);
}
void __init r7s72100_init_early(void)
{
shmobile_setup_delay(400, 1, 3);
}
