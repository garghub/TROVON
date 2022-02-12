void __init ath79_register_uart(void)
{
unsigned long uart_clk_rate;
uart_clk_rate = ath79_get_sys_clk_rate("uart");
if (soc_is_ar71xx() ||
soc_is_ar724x() ||
soc_is_ar913x() ||
soc_is_ar934x() ||
soc_is_qca955x()) {
ath79_uart_data[0].uartclk = uart_clk_rate;
platform_device_register(&ath79_uart_device);
} else if (soc_is_ar933x()) {
platform_device_register(&ar933x_uart_device);
} else {
BUG();
}
}
void __init ath79_register_wdt(void)
{
struct resource res;
memset(&res, 0, sizeof(res));
res.flags = IORESOURCE_MEM;
res.start = AR71XX_RESET_BASE + AR71XX_RESET_REG_WDOG_CTRL;
res.end = res.start + 0x8 - 1;
platform_device_register_simple("ath79-wdt", -1, &res, 1);
}
void __init ath79_gpio_init(void)
{
if (soc_is_ar71xx()) {
ath79_gpio_pdata.ngpios = AR71XX_GPIO_COUNT;
} else if (soc_is_ar7240()) {
ath79_gpio_pdata.ngpios = AR7240_GPIO_COUNT;
} else if (soc_is_ar7241() || soc_is_ar7242()) {
ath79_gpio_pdata.ngpios = AR7241_GPIO_COUNT;
} else if (soc_is_ar913x()) {
ath79_gpio_pdata.ngpios = AR913X_GPIO_COUNT;
} else if (soc_is_ar933x()) {
ath79_gpio_pdata.ngpios = AR933X_GPIO_COUNT;
} else if (soc_is_ar934x()) {
ath79_gpio_pdata.ngpios = AR934X_GPIO_COUNT;
ath79_gpio_pdata.oe_inverted = 1;
} else if (soc_is_qca955x()) {
ath79_gpio_pdata.ngpios = QCA955X_GPIO_COUNT;
ath79_gpio_pdata.oe_inverted = 1;
} else {
BUG();
}
platform_device_register(&ath79_gpio_device);
}
