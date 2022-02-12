static void __init zylonite_detect_lcd_panel(void)
{
unsigned long mfpr_save[NUM_LCD_DETECT_PINS];
int i, gpio, id = 0;
for (i = 0; i < NUM_LCD_DETECT_PINS; i++) {
mfpr_save[i] = pxa3xx_mfp_read(lcd_detect_pins[i]);
pxa3xx_mfp_write(lcd_detect_pins[i], 0x8440);
}
for (i = 0; i < NUM_LCD_DETECT_PINS; i++) {
id = id << 1;
gpio = mfp_to_gpio(lcd_detect_pins[i]);
gpio_request(gpio, "LCD_ID_PINS");
gpio_direction_input(gpio);
if (gpio_get_value(gpio))
id = id | 0x1;
gpio_free(gpio);
}
lcd_id = id & 0x3d;
lcd_orientation = (id >> 6) & 0x1;
for (i = 0; i < NUM_LCD_DETECT_PINS; i++)
pxa3xx_mfp_write(lcd_detect_pins[i], mfpr_save[i]);
}
static void __init zylonite_init_i2c(void)
{
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(zylonite_i2c_board_info));
}
static inline void zylonite_init_i2c(void) {}
void __init zylonite_pxa300_init(void)
{
if (cpu_is_pxa300() || cpu_is_pxa310()) {
pxa3xx_mfp_config(ARRAY_AND_SIZE(common_mfp_cfg));
zylonite_detect_lcd_panel();
wm9713_irq = mfp_to_gpio(MFP_PIN_GPIO26);
zylonite_init_i2c();
}
if (cpu_is_pxa300()) {
pxa3xx_mfp_config(ARRAY_AND_SIZE(pxa300_mfp_cfg));
gpio_eth_irq = mfp_to_gpio(MFP_PIN_GPIO99);
}
if (cpu_is_pxa310()) {
pxa3xx_mfp_config(ARRAY_AND_SIZE(pxa310_mfp_cfg));
gpio_eth_irq = mfp_to_gpio(MFP_PIN_GPIO102);
}
gpio_debug_led1 = EXT_GPIO(25);
gpio_debug_led2 = EXT_GPIO(26);
}
