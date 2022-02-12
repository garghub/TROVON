void __init emev2_map_io(void)
{
iotable_init(emev2_io_desc, ARRAY_SIZE(emev2_io_desc));
}
void __init emev2_add_standard_devices(void)
{
if (!IS_ENABLED(CONFIG_COMMON_CLK))
emev2_clock_init();
emev2_register_uart(0);
emev2_register_uart(1);
emev2_register_uart(2);
emev2_register_uart(3);
emev2_register_sti();
emev2_register_gio(0);
emev2_register_gio(1);
emev2_register_gio(2);
emev2_register_gio(3);
emev2_register_gio(4);
emev2_register_pmu();
}
void __init emev2_init_delay(void)
{
shmobile_setup_delay(533, 1, 3);
}
