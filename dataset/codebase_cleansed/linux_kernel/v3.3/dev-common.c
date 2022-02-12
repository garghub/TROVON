void __init ath79_register_uart(void)
{
struct clk *clk;
clk = clk_get(NULL, "uart");
if (IS_ERR(clk))
panic("unable to get UART clock, err=%ld", PTR_ERR(clk));
if (soc_is_ar71xx() ||
soc_is_ar724x() ||
soc_is_ar913x()) {
ath79_uart_data[0].uartclk = clk_get_rate(clk);
platform_device_register(&ath79_uart_device);
} else if (soc_is_ar933x()) {
ar933x_uart_data.uartclk = clk_get_rate(clk);
platform_device_register(&ar933x_uart_device);
} else {
BUG();
}
}
void __init ath79_register_wdt(void)
{
platform_device_register(&ath79_wdt_device);
}
