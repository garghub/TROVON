static void __init u5500_i2c_init(void)
{
db5500_add_i2c2(&u5500_i2c2_data);
i2c_register_board_info(2, ARRAY_AND_SIZE(u5500_i2c2_devices));
}
static void __init u5500_uart_init(void)
{
db5500_add_uart0(NULL);
db5500_add_uart1(NULL);
db5500_add_uart2(NULL);
}
static void __init u5500_init_machine(void)
{
u5500_init_devices();
nmk_config_pins(u5500_pins, ARRAY_SIZE(u5500_pins));
u5500_i2c_init();
u5500_sdi_init();
u5500_uart_init();
platform_add_devices(u5500_platform_devices,
ARRAY_SIZE(u5500_platform_devices));
}
