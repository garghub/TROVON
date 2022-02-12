static void __init u5500_i2c_init(struct device *parent)
{
db5500_add_i2c2(parent, &u5500_i2c2_data);
i2c_register_board_info(2, ARRAY_AND_SIZE(u5500_i2c2_devices));
}
static void __init u5500_uart_init(struct device *parent)
{
db5500_add_uart0(parent, NULL);
db5500_add_uart1(parent, NULL);
db5500_add_uart2(parent, NULL);
}
static void __init u5500_init_machine(void)
{
struct device *parent = NULL;
int i;
parent = u5500_init_devices();
nmk_config_pins(u5500_pins, ARRAY_SIZE(u5500_pins));
u5500_i2c_init(parent);
u5500_sdi_init(parent);
u5500_uart_init(parent);
for (i = 0; i < ARRAY_SIZE(u5500_platform_devices); i++)
u5500_platform_devices[i]->dev.parent = parent;
platform_add_devices(u5500_platform_devices,
ARRAY_SIZE(u5500_platform_devices));
}
