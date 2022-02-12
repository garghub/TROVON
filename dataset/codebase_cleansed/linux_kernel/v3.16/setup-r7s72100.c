void __init r7s72100_add_dt_devices(void)
{
r7s72100_register_mtu2();
}
void __init r7s72100_init_early(void)
{
shmobile_setup_delay(400, 1, 3);
}
