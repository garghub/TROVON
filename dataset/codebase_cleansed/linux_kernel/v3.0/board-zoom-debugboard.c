static inline void __init zoom_init_smsc911x(void)
{
gpmc_smsc911x_init(&zoom_smsc911x_cfg);
}
static inline void __init zoom_init_quaduart(void)
{
int quart_cs;
unsigned long cs_mem_base;
int quart_gpio = 0;
quart_cs = ZOOM_QUADUART_CS;
if (gpmc_cs_request(quart_cs, SZ_1M, &cs_mem_base) < 0) {
printk(KERN_ERR "Failed to request GPMC mem"
"for Quad UART(TL16CP754C)\n");
return;
}
quart_gpio = ZOOM_QUADUART_GPIO;
if (gpio_request_one(quart_gpio, GPIOF_IN, "TL16CP754C GPIO") < 0)
printk(KERN_ERR "Failed to request GPIO%d for TL16CP754C\n",
quart_gpio);
}
static inline int omap_zoom_debugboard_detect(void)
{
int debug_board_detect = 0;
int ret = 1;
debug_board_detect = ZOOM_SMSC911X_GPIO;
if (gpio_request_one(debug_board_detect, GPIOF_IN,
"Zoom debug board detect") < 0) {
printk(KERN_ERR "Failed to request GPIO%d for Zoom debug"
"board detect\n", debug_board_detect);
return 0;
}
if (!gpio_get_value(debug_board_detect)) {
ret = 0;
}
gpio_free(debug_board_detect);
return ret;
}
int __init zoom_debugboard_init(void)
{
if (!omap_zoom_debugboard_detect())
return 0;
zoom_init_smsc911x();
zoom_init_quaduart();
return platform_add_devices(zoom_devices, ARRAY_SIZE(zoom_devices));
}
