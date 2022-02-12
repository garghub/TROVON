void __init palm27x_mmc_init(int detect, int ro, int power,
int power_inverted)
{
palm27x_mci_platform_data.gpio_card_detect = detect;
palm27x_mci_platform_data.gpio_card_ro = ro;
palm27x_mci_platform_data.gpio_power = power;
palm27x_mci_platform_data.gpio_power_invert = power_inverted;
pxa_set_mci_info(&palm27x_mci_platform_data);
}
void __init palm27x_pm_init(unsigned long str_base)
{
static const unsigned long resume[] = {
0xe3a00101,
0xe380060f,
0xe590f008,
};
memcpy(phys_to_virt(str_base), resume, sizeof(resume));
}
static void palm27x_lcd_ctl(int on, struct fb_var_screeninfo *info)
{
gpio_set_value(palm27x_lcd_power, on);
}
void __init palm27x_lcd_init(int power, struct pxafb_mode_info *mode)
{
palm27x_lcd_screen.modes = mode;
if (gpio_is_valid(power)) {
if (!gpio_request(power, "LCD power")) {
pr_err("Palm27x: failed to claim lcd power gpio!\n");
return;
}
if (!gpio_direction_output(power, 1)) {
pr_err("Palm27x: lcd power configuration failed!\n");
return;
}
palm27x_lcd_power = power;
palm27x_lcd_screen.pxafb_lcd_power = palm27x_lcd_ctl;
}
pxa_set_fb_info(NULL, &palm27x_lcd_screen);
}
void __init palm27x_udc_init(int vbus, int pullup, int vbus_inverted)
{
palm27x_udc_info.gpio_vbus = vbus;
palm27x_udc_info.gpio_pullup = pullup;
palm27x_udc_info.gpio_vbus_inverted = vbus_inverted;
if (!gpio_request(pullup, "USB Pullup")) {
gpio_direction_output(pullup,
palm27x_udc_info.gpio_vbus_inverted);
gpio_free(pullup);
} else
return;
platform_device_register(&palm27x_gpio_vbus);
}
void __init palm27x_irda_init(int pwdn)
{
palm27x_ficp_platform_data.gpio_pwdown = pwdn;
pxa_set_ficp_info(&palm27x_ficp_platform_data);
}
void __init palm27x_ac97_init(int minv, int maxv, int jack, int reset)
{
palm27x_ac97_pdata.reset_gpio = reset;
palm27x_asoc_pdata.jack_gpio = jack;
if (minv < 0 || maxv < 0) {
palm27x_ac97_pdata.codec_pdata[0] = NULL;
pxa_set_ac97_info(&palm27x_ac97_pdata);
} else {
palm27x_batt_pdata.min_voltage = minv,
palm27x_batt_pdata.max_voltage = maxv,
pxa_set_ac97_info(&palm27x_ac97_pdata);
platform_device_register(&palm27x_asoc);
}
}
static int palm27x_backlight_init(struct device *dev)
{
int ret;
ret = gpio_request(palm_bl_power, "BL POWER");
if (ret)
goto err;
ret = gpio_direction_output(palm_bl_power, 0);
if (ret)
goto err2;
if (gpio_is_valid(palm_lcd_power)) {
ret = gpio_request(palm_lcd_power, "LCD POWER");
if (ret)
goto err2;
ret = gpio_direction_output(palm_lcd_power, 0);
if (ret)
goto err3;
}
return 0;
err3:
gpio_free(palm_lcd_power);
err2:
gpio_free(palm_bl_power);
err:
return ret;
}
static int palm27x_backlight_notify(struct device *dev, int brightness)
{
gpio_set_value(palm_bl_power, brightness);
if (gpio_is_valid(palm_lcd_power))
gpio_set_value(palm_lcd_power, brightness);
return brightness;
}
static void palm27x_backlight_exit(struct device *dev)
{
gpio_free(palm_bl_power);
if (gpio_is_valid(palm_lcd_power))
gpio_free(palm_lcd_power);
}
void __init palm27x_pwm_init(int bl, int lcd)
{
palm_bl_power = bl;
palm_lcd_power = lcd;
pwm_add_table(palm27x_pwm_lookup, ARRAY_SIZE(palm27x_pwm_lookup));
platform_device_register(&palm27x_backlight);
}
static int palm27x_power_supply_init(struct device *dev)
{
int ret;
ret = gpio_request(palm_ac_state, "AC state");
if (ret)
goto err1;
ret = gpio_direction_input(palm_ac_state);
if (ret)
goto err2;
if (gpio_is_valid(palm_usb_state)) {
ret = gpio_request(palm_usb_state, "USB state");
if (ret)
goto err2;
ret = gpio_direction_input(palm_usb_state);
if (ret)
goto err3;
}
return 0;
err3:
gpio_free(palm_usb_state);
err2:
gpio_free(palm_ac_state);
err1:
return ret;
}
static void palm27x_power_supply_exit(struct device *dev)
{
gpio_free(palm_usb_state);
gpio_free(palm_ac_state);
}
static int palm27x_is_ac_online(void)
{
return gpio_get_value(palm_ac_state);
}
static int palm27x_is_usb_online(void)
{
return !gpio_get_value(palm_usb_state);
}
void __init palm27x_power_init(int ac, int usb)
{
palm_ac_state = ac;
palm_usb_state = usb;
platform_device_register(&palm27x_power_supply);
}
void __init palm27x_pmic_init(void)
{
i2c_register_board_info(1, ARRAY_AND_SIZE(palm27x_pi2c_board_info));
pxa27x_set_i2c_power_info(&palm27x_i2c_power_info);
}
