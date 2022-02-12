static void __init zylonite_detect_lcd_panel(void)
{
unsigned long mfpr_save[ARRAY_SIZE(lcd_detect_pins)];
int i, gpio, id = 0;
for (i = 0; i < ARRAY_SIZE(lcd_detect_pins); i++) {
mfpr_save[i] = pxa3xx_mfp_read(lcd_detect_pins[i]);
pxa3xx_mfp_write(lcd_detect_pins[i], lcd_detect_mfpr[i]);
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
for (i = 0; i < ARRAY_SIZE(lcd_detect_pins); i++)
pxa3xx_mfp_write(lcd_detect_pins[i], mfpr_save[i]);
}
void __init zylonite_pxa320_init(void)
{
if (cpu_is_pxa320()) {
pxa3xx_mfp_config(ARRAY_AND_SIZE(mfp_cfg));
zylonite_detect_lcd_panel();
gpio_eth_irq = mfp_to_gpio(MFP_PIN_GPIO9);
gpio_debug_led1 = mfp_to_gpio(MFP_PIN_GPIO1_2);
gpio_debug_led2 = mfp_to_gpio(MFP_PIN_GPIO4_2);
wm9713_irq = mfp_to_gpio(MFP_PIN_GPIO15);
}
}
