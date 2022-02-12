static void __init cm_x300_init_dm9000(void)
{
platform_device_register(&dm9000_device);
}
static inline void cm_x300_init_dm9000(void) {}
static void __init cm_x300_init_lcd(void)
{
pxa_set_fb_info(NULL, &cm_x300_lcd);
}
static inline void cm_x300_init_lcd(void) {}
static void cm_x300_init_bl(void)
{
platform_device_register(&cm_x300_backlight_device);
}
static inline void cm_x300_init_bl(void) {}
static void __init cm_x300_init_spi(void)
{
spi_register_board_info(cm_x300_spi_devices,
ARRAY_SIZE(cm_x300_spi_devices));
platform_device_register(&cm_x300_spi_gpio);
}
static inline void cm_x300_init_spi(void) {}
static void __init cm_x300_init_ac97(void)
{
pxa_set_ac97_info(NULL);
}
static inline void cm_x300_init_ac97(void) {}
static void __init cm_x300_init_nand(void)
{
pxa3xx_set_nand_info(&cm_x300_nand_info);
}
static inline void cm_x300_init_nand(void) {}
static int cm_x300_mci2_init(struct device *dev,
irq_handler_t cm_x300_detect_int,
void *data)
{
return 0;
}
static void cm_x300_mci2_exit(struct device *dev, void *data)
{
}
static void __init cm_x300_init_mmc(void)
{
pxa_set_mci_info(&cm_x300_mci_platform_data);
pxa3xx_set_mci2_info(&cm_x300_mci2_platform_data);
}
static inline void cm_x300_init_mmc(void) {}
static int cm_x300_ulpi_phy_reset(void)
{
int err;
err = gpio_request(GPIO_ULPI_PHY_RST, "ulpi reset");
if (err) {
pr_err("%s: failed to request ULPI reset GPIO: %d\n",
__func__, err);
return err;
}
gpio_direction_output(GPIO_ULPI_PHY_RST, 0);
msleep(10);
gpio_set_value(GPIO_ULPI_PHY_RST, 1);
msleep(10);
gpio_free(GPIO_ULPI_PHY_RST);
return 0;
}
static inline int cm_x300_u2d_init(struct device *dev)
{
int err = 0;
if (cpu_is_pxa310()) {
pout_clk = clk_get(NULL, "CLK_POUT");
if (IS_ERR(pout_clk)) {
err = PTR_ERR(pout_clk);
pr_err("%s: failed to get CLK_POUT: %d\n",
__func__, err);
return err;
}
clk_enable(pout_clk);
err = cm_x300_ulpi_phy_reset();
if (err) {
clk_disable(pout_clk);
clk_put(pout_clk);
}
}
return err;
}
static void cm_x300_u2d_exit(struct device *dev)
{
if (cpu_is_pxa310()) {
clk_disable(pout_clk);
clk_put(pout_clk);
}
}
static void cm_x300_init_u2d(void)
{
pxa3xx_set_u2d_info(&cm_x300_u2d_platform_data);
}
static inline void cm_x300_init_u2d(void) {}
static int cm_x300_ohci_init(struct device *dev)
{
if (cpu_is_pxa300())
UP2OCR = UP2OCR_HXS
| UP2OCR_HXOE | UP2OCR_DMPDE | UP2OCR_DPPDE;
return 0;
}
static void __init cm_x300_init_ohci(void)
{
pxa_set_ohci_info(&cm_x300_ohci_platform_data);
}
static inline void cm_x300_init_ohci(void) {}
static void __init cm_x300_init_leds(void)
{
if (system_rev < 130)
cm_x300_leds[0].gpio = 79;
else
cm_x300_leds[0].gpio = 76;
platform_device_register(&cm_x300_led_device);
}
static inline void cm_x300_init_leds(void) {}
static void __init cm_x300_init_i2c(void)
{
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, cm_x300_gpio_ext_info,
ARRAY_SIZE(cm_x300_gpio_ext_info));
}
static inline void cm_x300_init_i2c(void) {}
static void __init cm_x300_init_rtc(void)
{
platform_device_register(&cm_x300_rtc_device);
}
static inline void cm_x300_init_rtc(void) {}
static void cm_x300_battery_low(void)
{
#if defined(CONFIG_APM_EMULATION)
apm_queue_event(APM_LOW_BATTERY);
#endif
}
static void cm_x300_battery_critical(void)
{
#if defined(CONFIG_APM_EMULATION)
apm_queue_event(APM_CRITICAL_SUSPEND);
#endif
}
static void __init cm_x300_init_da9030(void)
{
pxa3xx_set_i2c_power_info(&cm_x300_pwr_i2c_info);
i2c_register_board_info(1, &cm_x300_pmic_info, 1);
irq_set_irq_wake(IRQ_WAKEUP0, 1);
}
static void __init cm_x300_init_wi2wi(void)
{
int bt_reset, wlan_en;
int err;
if (system_rev < 130) {
wlan_en = 77;
bt_reset = 78;
} else {
wlan_en = 71;
bt_reset = 70;
}
err = gpio_request(wlan_en, "wlan en");
if (err) {
pr_err("CM-X300: failed to request wlan en gpio: %d\n", err);
} else {
gpio_direction_output(wlan_en, 1);
gpio_free(wlan_en);
}
err = gpio_request(bt_reset, "bt reset");
if (err) {
pr_err("CM-X300: failed to request bt reset gpio: %d\n", err);
} else {
gpio_direction_output(bt_reset, 1);
udelay(10);
gpio_set_value(bt_reset, 0);
udelay(10);
gpio_set_value(bt_reset, 1);
gpio_free(bt_reset);
}
}
static void __init cm_x300_init_mfp(void)
{
pxa3xx_mfp_config(ARRAY_AND_SIZE(cm_x3xx_mfp_cfg));
if (system_rev < 130)
pxa3xx_mfp_config(ARRAY_AND_SIZE(cm_x3xx_rev_lt130_mfp_cfg));
else
pxa3xx_mfp_config(ARRAY_AND_SIZE(cm_x3xx_rev_ge130_mfp_cfg));
if (cpu_is_pxa310())
pxa3xx_mfp_config(ARRAY_AND_SIZE(cm_x310_mfp_cfg));
}
static void __init cm_x300_init(void)
{
cm_x300_init_mfp();
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
if (cpu_is_pxa300())
pxa_set_ffuart_info(NULL);
cm_x300_init_da9030();
cm_x300_init_dm9000();
cm_x300_init_lcd();
cm_x300_init_u2d();
cm_x300_init_ohci();
cm_x300_init_mmc();
cm_x300_init_nand();
cm_x300_init_leds();
cm_x300_init_i2c();
cm_x300_init_spi();
cm_x300_init_rtc();
cm_x300_init_ac97();
cm_x300_init_wi2wi();
cm_x300_init_bl();
}
static void __init cm_x300_fixup(struct machine_desc *mdesc, struct tag *tags,
char **cmdline, struct meminfo *mi)
{
for (; tags->hdr.size; tags = tag_next(tags))
if (tags->hdr.tag == ATAG_MEM &&
tags->u.mem.start == 0x80000000) {
tags->u.mem.start = 0xa0000000;
break;
}
}
