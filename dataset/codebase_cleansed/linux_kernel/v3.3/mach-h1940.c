static void h1940_latch_control(unsigned int clear, unsigned int set)
{
unsigned long flags;
local_irq_save(flags);
latch_state &= ~clear;
latch_state |= set;
__raw_writel(latch_state, H1940_LATCH);
local_irq_restore(flags);
}
static inline int h1940_gpiolib_to_latch(int offset)
{
return 1 << (offset + 16);
}
static void h1940_gpiolib_latch_set(struct gpio_chip *chip,
unsigned offset, int value)
{
int latch_bit = h1940_gpiolib_to_latch(offset);
h1940_latch_control(value ? 0 : latch_bit,
value ? latch_bit : 0);
}
static int h1940_gpiolib_latch_output(struct gpio_chip *chip,
unsigned offset, int value)
{
h1940_gpiolib_latch_set(chip, offset, value);
return 0;
}
static int h1940_gpiolib_latch_get(struct gpio_chip *chip,
unsigned offset)
{
return (latch_state >> (offset + 16)) & 1;
}
static int power_supply_init(struct device *dev)
{
return gpio_request(S3C2410_GPF(2), "cable plugged");
}
static int h1940_is_ac_online(void)
{
return !gpio_get_value(S3C2410_GPF(2));
}
static void power_supply_exit(struct device *dev)
{
gpio_free(S3C2410_GPF(2));
}
int h1940_bat_init(void)
{
int ret;
ret = gpio_request(H1940_LATCH_SM803_ENABLE, "h1940-charger-enable");
if (ret)
return ret;
gpio_direction_output(H1940_LATCH_SM803_ENABLE, 0);
return 0;
}
void h1940_bat_exit(void)
{
gpio_free(H1940_LATCH_SM803_ENABLE);
}
void h1940_enable_charger(void)
{
gpio_set_value(H1940_LATCH_SM803_ENABLE, 1);
}
void h1940_disable_charger(void)
{
gpio_set_value(H1940_LATCH_SM803_ENABLE, 0);
}
int h1940_led_blink_set(unsigned gpio, int state,
unsigned long *delay_on, unsigned long *delay_off)
{
int blink_gpio, check_gpio1, check_gpio2;
switch (gpio) {
case H1940_LATCH_LED_GREEN:
blink_gpio = S3C2410_GPA(7);
check_gpio1 = S3C2410_GPA(1);
check_gpio2 = S3C2410_GPA(3);
break;
case H1940_LATCH_LED_RED:
blink_gpio = S3C2410_GPA(1);
check_gpio1 = S3C2410_GPA(7);
check_gpio2 = S3C2410_GPA(3);
break;
default:
blink_gpio = S3C2410_GPA(3);
check_gpio1 = S3C2410_GPA(1);
check_gpio1 = S3C2410_GPA(7);
break;
}
if (delay_on && delay_off && !*delay_on && !*delay_off)
*delay_on = *delay_off = 500;
spin_lock(&h1940_blink_spin);
switch (state) {
case GPIO_LED_NO_BLINK_LOW:
case GPIO_LED_NO_BLINK_HIGH:
if (!gpio_get_value(check_gpio1) &&
!gpio_get_value(check_gpio2))
gpio_set_value(H1940_LATCH_LED_FLASH, 0);
gpio_set_value(blink_gpio, 0);
if (gpio_is_valid(gpio))
gpio_set_value(gpio, state);
break;
case GPIO_LED_BLINK:
if (gpio_is_valid(gpio))
gpio_set_value(gpio, 0);
gpio_set_value(H1940_LATCH_LED_FLASH, 1);
gpio_set_value(blink_gpio, 1);
break;
}
spin_unlock(&h1940_blink_spin);
return 0;
}
static void h1940_set_mmc_power(unsigned char power_mode, unsigned short vdd)
{
switch (power_mode) {
case MMC_POWER_OFF:
gpio_set_value(H1940_LATCH_SD_POWER, 0);
break;
case MMC_POWER_UP:
case MMC_POWER_ON:
gpio_set_value(H1940_LATCH_SD_POWER, 1);
break;
default:
break;
};
}
static int h1940_backlight_init(struct device *dev)
{
gpio_request(S3C2410_GPB(0), "Backlight");
gpio_direction_output(S3C2410_GPB(0), 0);
s3c_gpio_setpull(S3C2410_GPB(0), S3C_GPIO_PULL_NONE);
s3c_gpio_cfgpin(S3C2410_GPB(0), S3C2410_GPB0_TOUT0);
gpio_set_value(H1940_LATCH_MAX1698_nSHUTDOWN, 1);
return 0;
}
static int h1940_backlight_notify(struct device *dev, int brightness)
{
if (!brightness) {
gpio_direction_output(S3C2410_GPB(0), 1);
gpio_set_value(H1940_LATCH_MAX1698_nSHUTDOWN, 0);
} else {
gpio_direction_output(S3C2410_GPB(0), 0);
s3c_gpio_setpull(S3C2410_GPB(0), S3C_GPIO_PULL_NONE);
s3c_gpio_cfgpin(S3C2410_GPB(0), S3C2410_GPB0_TOUT0);
gpio_set_value(H1940_LATCH_MAX1698_nSHUTDOWN, 1);
}
return brightness;
}
static void h1940_backlight_exit(struct device *dev)
{
gpio_direction_output(S3C2410_GPB(0), 1);
gpio_set_value(H1940_LATCH_MAX1698_nSHUTDOWN, 0);
}
static void h1940_lcd_power_set(struct plat_lcd_data *pd,
unsigned int power)
{
int value, retries = 100;
if (!power) {
gpio_set_value(S3C2410_GPC(0), 0);
do {
value = gpio_get_value(S3C2410_GPC(6));
} while (value && retries--);
gpio_set_value(H1940_LATCH_LCD_P2, 0);
gpio_set_value(H1940_LATCH_LCD_P3, 0);
gpio_set_value(H1940_LATCH_LCD_P4, 0);
gpio_direction_output(S3C2410_GPC(1), 0);
gpio_direction_output(S3C2410_GPC(4), 0);
gpio_set_value(H1940_LATCH_LCD_P1, 0);
gpio_set_value(H1940_LATCH_LCD_P0, 0);
gpio_set_value(S3C2410_GPC(5), 0);
} else {
gpio_set_value(H1940_LATCH_LCD_P0, 1);
gpio_set_value(H1940_LATCH_LCD_P1, 1);
gpio_direction_input(S3C2410_GPC(1));
gpio_direction_input(S3C2410_GPC(4));
mdelay(10);
s3c_gpio_cfgpin(S3C2410_GPC(1), S3C_GPIO_SFN(2));
s3c_gpio_cfgpin(S3C2410_GPC(4), S3C_GPIO_SFN(2));
gpio_set_value(S3C2410_GPC(5), 1);
gpio_set_value(S3C2410_GPC(0), 1);
gpio_set_value(H1940_LATCH_LCD_P3, 1);
gpio_set_value(H1940_LATCH_LCD_P2, 1);
gpio_set_value(H1940_LATCH_LCD_P4, 1);
}
}
static void __init h1940_map_io(void)
{
s3c24xx_init_io(h1940_iodesc, ARRAY_SIZE(h1940_iodesc));
s3c24xx_init_clocks(0);
s3c24xx_init_uarts(h1940_uartcfgs, ARRAY_SIZE(h1940_uartcfgs));
#ifdef CONFIG_PM_H1940
memcpy(phys_to_virt(H1940_SUSPEND_RESUMEAT), h1940_pm_return, 1024);
#endif
s3c_pm_init();
h1940_latch_control(0, 0);
WARN_ON(gpiochip_add(&h1940_latch_gpiochip));
}
static void __init h1940_reserve(void)
{
memblock_reserve(0x30003000, 0x1000);
memblock_reserve(0x30081000, 0x1000);
}
static void __init h1940_init_irq(void)
{
s3c24xx_init_irq();
}
static void __init h1940_init(void)
{
u32 tmp;
s3c24xx_fb_set_platdata(&h1940_fb_info);
s3c24xx_mci_set_platdata(&h1940_mmc_cfg);
s3c24xx_udc_set_platdata(&h1940_udc_cfg);
s3c24xx_ts_set_platdata(&h1940_ts_cfg);
s3c_i2c0_set_platdata(NULL);
s3c2410_modify_misccr(S3C2410_MISCCR_USBHOST |
S3C2410_MISCCR_USBSUSPND0 |
S3C2410_MISCCR_USBSUSPND1, 0x0);
tmp = (0x78 << S3C24XX_PLL_MDIV_SHIFT)
| (0x02 << S3C24XX_PLL_PDIV_SHIFT)
| (0x03 << S3C24XX_PLL_SDIV_SHIFT);
writel(tmp, S3C2410_UPLLCON);
gpio_request(S3C2410_GPC(0), "LCD power");
gpio_request(S3C2410_GPC(1), "LCD power");
gpio_request(S3C2410_GPC(4), "LCD power");
gpio_request(S3C2410_GPC(5), "LCD power");
gpio_request(S3C2410_GPC(6), "LCD power");
gpio_request(H1940_LATCH_LCD_P0, "LCD power");
gpio_request(H1940_LATCH_LCD_P1, "LCD power");
gpio_request(H1940_LATCH_LCD_P2, "LCD power");
gpio_request(H1940_LATCH_LCD_P3, "LCD power");
gpio_request(H1940_LATCH_LCD_P4, "LCD power");
gpio_request(H1940_LATCH_MAX1698_nSHUTDOWN, "LCD power");
gpio_direction_output(S3C2410_GPC(0), 0);
gpio_direction_output(S3C2410_GPC(1), 0);
gpio_direction_output(S3C2410_GPC(4), 0);
gpio_direction_output(S3C2410_GPC(5), 0);
gpio_direction_input(S3C2410_GPC(6));
gpio_direction_output(H1940_LATCH_LCD_P0, 0);
gpio_direction_output(H1940_LATCH_LCD_P1, 0);
gpio_direction_output(H1940_LATCH_LCD_P2, 0);
gpio_direction_output(H1940_LATCH_LCD_P3, 0);
gpio_direction_output(H1940_LATCH_LCD_P4, 0);
gpio_direction_output(H1940_LATCH_MAX1698_nSHUTDOWN, 0);
gpio_request(H1940_LATCH_SD_POWER, "SD power");
gpio_direction_output(H1940_LATCH_SD_POWER, 0);
platform_add_devices(h1940_devices, ARRAY_SIZE(h1940_devices));
gpio_request(S3C2410_GPA(1), "Red LED blink");
gpio_request(S3C2410_GPA(3), "Blue LED blink");
gpio_request(S3C2410_GPA(7), "Green LED blink");
gpio_request(H1940_LATCH_LED_FLASH, "LED blink");
gpio_direction_output(S3C2410_GPA(1), 0);
gpio_direction_output(S3C2410_GPA(3), 0);
gpio_direction_output(S3C2410_GPA(7), 0);
gpio_direction_output(H1940_LATCH_LED_FLASH, 0);
i2c_register_board_info(0, h1940_i2c_devices,
ARRAY_SIZE(h1940_i2c_devices));
}
