static void __init u5500_uart_init(void)
{
db5500_add_uart0(NULL);
db5500_add_uart1(NULL);
db5500_add_uart2(NULL);
}
static void __init u5500_init_machine(void)
{
u5500_init_devices();
u5500_sdi_init();
u5500_uart_init();
}
