void __init highlander_plat_pinmux_setup(void)
{
gpio_request(GPIO_FN_SCIF0_CTS, NULL);
gpio_request(GPIO_FN_SCIF0_RTS, NULL);
gpio_request(GPIO_FN_SCIF0_SCK, NULL);
gpio_request(GPIO_FN_SCIF0_RXD, NULL);
gpio_request(GPIO_FN_SCIF0_TXD, NULL);
}
