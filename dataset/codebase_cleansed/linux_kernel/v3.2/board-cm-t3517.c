static void __init cm_t3517_init_leds(void)
{
platform_device_register(&cm_t3517_led_device);
}
static inline void cm_t3517_init_leds(void) {}
static void cm_t3517_init_hecc(void)
{
platform_device_register(&cm_t3517_hecc_device);
}
static inline void cm_t3517_init_hecc(void) {}
static void __init cm_t3517_init_rtc(void)
{
int err;
err = gpio_request_one(RTC_CS_EN_GPIO, GPIOF_OUT_INIT_HIGH,
"rtc cs en");
if (err) {
pr_err("CM-T3517: rtc cs en gpio request failed: %d\n", err);
return;
}
platform_device_register(&cm_t3517_rtc_device);
}
static inline void cm_t3517_init_rtc(void) {}
static int __init cm_t3517_init_usbh(void)
{
int err;
err = gpio_request_one(USB_HUB_RESET_GPIO, GPIOF_OUT_INIT_LOW,
"usb hub rst");
if (err) {
pr_err("CM-T3517: usb hub rst gpio request failed: %d\n", err);
} else {
udelay(10);
gpio_set_value(USB_HUB_RESET_GPIO, 1);
msleep(1);
}
usbhs_init(&cm_t3517_ehci_pdata);
return 0;
}
static inline int cm_t3517_init_usbh(void)
{
return 0;
}
static void __init cm_t3517_init_nand(void)
{
if (gpmc_nand_init(&cm_t3517_nand_data) < 0)
pr_err("CM-T3517: NAND initialization failed\n");
}
static inline void cm_t3517_init_nand(void) {}
static void __init cm_t3517_init(void)
{
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap_serial_init();
omap_sdrc_init(NULL, NULL);
omap_board_config = cm_t3517_config;
omap_board_config_size = ARRAY_SIZE(cm_t3517_config);
cm_t3517_init_leds();
cm_t3517_init_nand();
cm_t3517_init_rtc();
cm_t3517_init_usbh();
cm_t3517_init_hecc();
}
