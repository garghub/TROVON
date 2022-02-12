static int power_supply_init(struct device *dev)
{
return gpio_request(S3C2410_GPF(2), "cable plugged");
}
static int rx1950_is_ac_online(void)
{
return !gpio_get_value(S3C2410_GPF(2));
}
static void power_supply_exit(struct device *dev)
{
gpio_free(S3C2410_GPF(2));
}
static int rx1950_bat_init(void)
{
int ret;
ret = gpio_request(S3C2410_GPJ(2), "rx1950-charger-enable-1");
if (ret)
goto err_gpio1;
ret = gpio_request(S3C2410_GPJ(3), "rx1950-charger-enable-2");
if (ret)
goto err_gpio2;
return 0;
err_gpio2:
gpio_free(S3C2410_GPJ(2));
err_gpio1:
return ret;
}
static void rx1950_bat_exit(void)
{
gpio_free(S3C2410_GPJ(2));
gpio_free(S3C2410_GPJ(3));
}
static void rx1950_enable_charger(void)
{
gpio_direction_output(S3C2410_GPJ(2), 1);
gpio_direction_output(S3C2410_GPJ(3), 1);
}
static void rx1950_disable_charger(void)
{
gpio_direction_output(S3C2410_GPJ(2), 0);
gpio_direction_output(S3C2410_GPJ(3), 0);
}
static int rx1950_led_blink_set(struct gpio_desc *desc, int state,
unsigned long *delay_on, unsigned long *delay_off)
{
int gpio = desc_to_gpio(desc);
int blink_gpio, check_gpio;
switch (gpio) {
case S3C2410_GPA(6):
blink_gpio = S3C2410_GPA(4);
check_gpio = S3C2410_GPA(3);
break;
case S3C2410_GPA(7):
blink_gpio = S3C2410_GPA(3);
check_gpio = S3C2410_GPA(4);
break;
default:
return -EINVAL;
break;
}
if (delay_on && delay_off && !*delay_on && !*delay_off)
*delay_on = *delay_off = 500;
spin_lock(&rx1950_blink_spin);
switch (state) {
case GPIO_LED_NO_BLINK_LOW:
case GPIO_LED_NO_BLINK_HIGH:
if (!gpio_get_value(check_gpio))
gpio_set_value(S3C2410_GPJ(6), 0);
gpio_set_value(blink_gpio, 0);
gpio_set_value(gpio, state);
break;
case GPIO_LED_BLINK:
gpio_set_value(gpio, 0);
gpio_set_value(S3C2410_GPJ(6), 1);
gpio_set_value(blink_gpio, 1);
break;
}
spin_unlock(&rx1950_blink_spin);
return 0;
}
static void rx1950_lcd_power(int enable)
{
int i;
static int enabled;
if (enabled == enable)
return;
if (!enable) {
for (i = 11; i < 16; i++)
gpio_direction_output(S3C2410_GPC(i), 1);
mdelay(100);
for (i = 2; i < 8; i++)
gpio_direction_output(S3C2410_GPD(i), 1);
for (i = 11; i < 16; i++)
gpio_direction_output(S3C2410_GPD(i), 1);
mdelay(100);
gpio_direction_output(S3C2410_GPB(0), 0);
for (i = 1; i < 5; i++)
gpio_direction_output(S3C2410_GPC(i), 0);
for (i = 11; i < 16; i++)
gpio_direction_output(S3C2410_GPC(i), 0);
for (i = 11; i < 16; i++)
gpio_direction_output(S3C2410_GPD(i), 0);
for (i = 2; i < 8; i++)
gpio_direction_output(S3C2410_GPD(i), 0);
gpio_direction_output(S3C2410_GPC(6), 0);
gpio_direction_output(S3C2410_GPC(7), 0);
gpio_direction_output(S3C2410_GPC(5), 0);
gpio_direction_output(S3C2410_GPB(1), 0);
pwm_config(lcd_pwm, 0, LCD_PWM_PERIOD);
pwm_disable(lcd_pwm);
gpio_direction_output(S3C2410_GPC(0), 0);
gpio_direction_output(S3C2410_GPC(10), 0);
} else {
pwm_config(lcd_pwm, LCD_PWM_DUTY, LCD_PWM_PERIOD);
pwm_enable(lcd_pwm);
gpio_direction_output(S3C2410_GPC(0), 1);
gpio_direction_output(S3C2410_GPC(5), 1);
s3c_gpio_cfgpin(S3C2410_GPB(1), S3C2410_GPB1_TOUT1);
gpio_direction_output(S3C2410_GPC(7), 1);
for (i = 1; i < 5; i++)
s3c_gpio_cfgpin(S3C2410_GPC(i), S3C_GPIO_SFN(2));
for (i = 11; i < 16; i++)
s3c_gpio_cfgpin(S3C2410_GPC(i), S3C_GPIO_SFN(2));
for (i = 2; i < 8; i++)
s3c_gpio_cfgpin(S3C2410_GPD(i), S3C_GPIO_SFN(2));
for (i = 11; i < 16; i++)
s3c_gpio_cfgpin(S3C2410_GPD(i), S3C_GPIO_SFN(2));
gpio_direction_output(S3C2410_GPC(10), 1);
gpio_direction_output(S3C2410_GPC(6), 1);
}
enabled = enable;
}
static void rx1950_bl_power(int enable)
{
static int enabled;
if (enabled == enable)
return;
if (!enable) {
gpio_direction_output(S3C2410_GPB(0), 0);
} else {
gpio_direction_output(S3C2410_GPB(0), 1);
ndelay(48000);
s3c_gpio_cfgpin(S3C2410_GPB(0), S3C2410_GPB0_TOUT0);
}
enabled = enable;
}
static int rx1950_backlight_init(struct device *dev)
{
WARN_ON(gpio_request(S3C2410_GPB(0), "Backlight"));
lcd_pwm = pwm_request(1, "RX1950 LCD");
if (IS_ERR(lcd_pwm)) {
dev_err(dev, "Unable to request PWM for LCD power!\n");
return PTR_ERR(lcd_pwm);
}
rx1950_lcd_power(1);
rx1950_bl_power(1);
return 0;
}
static void rx1950_backlight_exit(struct device *dev)
{
rx1950_bl_power(0);
rx1950_lcd_power(0);
pwm_free(lcd_pwm);
gpio_free(S3C2410_GPB(0));
}
static int rx1950_backlight_notify(struct device *dev, int brightness)
{
if (!brightness) {
rx1950_bl_power(0);
rx1950_lcd_power(0);
} else {
rx1950_lcd_power(1);
rx1950_bl_power(1);
}
return brightness;
}
static void rx1950_set_mmc_power(unsigned char power_mode, unsigned short vdd)
{
switch (power_mode) {
case MMC_POWER_OFF:
gpio_direction_output(S3C2410_GPJ(1), 0);
break;
case MMC_POWER_UP:
case MMC_POWER_ON:
gpio_direction_output(S3C2410_GPJ(1), 1);
break;
default:
break;
}
}
static void __init rx1950_map_io(void)
{
s3c24xx_init_io(rx1950_iodesc, ARRAY_SIZE(rx1950_iodesc));
s3c24xx_init_uarts(rx1950_uartcfgs, ARRAY_SIZE(rx1950_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
#ifdef CONFIG_PM_H1940
memcpy(phys_to_virt(H1940_SUSPEND_RESUMEAT), h1940_pm_return, 8);
#endif
s3c_pm_init();
}
static void __init rx1950_init_time(void)
{
s3c2442_init_clocks(16934000);
samsung_timer_init();
}
static void __init rx1950_init_machine(void)
{
int i;
s3c24xx_fb_set_platdata(&rx1950_lcd_cfg);
s3c24xx_udc_set_platdata(&rx1950_udc_cfg);
s3c24xx_ts_set_platdata(&rx1950_ts_cfg);
s3c24xx_mci_set_platdata(&rx1950_mmc_cfg);
s3c_i2c0_set_platdata(NULL);
s3c_nand_set_platdata(&rx1950_nand_info);
s3c2410_modify_misccr(S3C2410_MISCCR_USBHOST |
S3C2410_MISCCR_USBSUSPND0 |
S3C2410_MISCCR_USBSUSPND1, 0x0);
WARN_ON(gpio_request(S3C2410_GPJ(1), "MMC power"));
gpio_direction_output(S3C2410_GPJ(1), 0);
for (i = 0; i < 8; i++)
WARN_ON(gpio_request(S3C2410_GPC(i), "LCD power"));
for (i = 10; i < 16; i++)
WARN_ON(gpio_request(S3C2410_GPC(i), "LCD power"));
for (i = 2; i < 8; i++)
WARN_ON(gpio_request(S3C2410_GPD(i), "LCD power"));
for (i = 11; i < 16; i++)
WARN_ON(gpio_request(S3C2410_GPD(i), "LCD power"));
WARN_ON(gpio_request(S3C2410_GPB(1), "LCD power"));
WARN_ON(gpio_request(S3C2410_GPA(3), "Red blink"));
WARN_ON(gpio_request(S3C2410_GPA(4), "Green blink"));
WARN_ON(gpio_request(S3C2410_GPJ(6), "LED blink"));
gpio_direction_output(S3C2410_GPA(3), 0);
gpio_direction_output(S3C2410_GPA(4), 0);
gpio_direction_output(S3C2410_GPJ(6), 0);
pwm_add_table(rx1950_pwm_lookup, ARRAY_SIZE(rx1950_pwm_lookup));
platform_add_devices(rx1950_devices, ARRAY_SIZE(rx1950_devices));
i2c_register_board_info(0, rx1950_i2c_devices,
ARRAY_SIZE(rx1950_i2c_devices));
}
static void __init rx1950_reserve(void)
{
memblock_reserve(0x30003000, 0x1000);
memblock_reserve(0x30081000, 0x1000);
}
