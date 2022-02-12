void __init ath79_register_uart(void)
{
struct clk *clk;
clk = clk_get(NULL, "uart");
if (IS_ERR(clk))
panic("unable to get UART clock, err=%ld", PTR_ERR(clk));
ath79_uart_data[0].uartclk = clk_get_rate(clk);
platform_device_register(&ath79_uart_device);
}
void __init ath79_register_wdt(void)
{
platform_device_register(&ath79_wdt_device);
}
