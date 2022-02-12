static void smartq_usb_host_powercontrol(int port, int to)
{
pr_debug("%s(%d, %d)\n", __func__, port, to);
if (port == 0) {
gpio_set_value(S3C64XX_GPL(0), to);
gpio_set_value(S3C64XX_GPL(1), to);
}
}
static irqreturn_t smartq_usb_host_ocirq(int irq, void *pw)
{
struct s3c2410_hcd_info *info = pw;
if (gpio_get_value(S3C64XX_GPL(10)) == 0) {
pr_debug("%s: over-current irq (oc detected)\n", __func__);
s3c2410_usb_report_oc(info, 3);
} else {
pr_debug("%s: over-current irq (oc cleared)\n", __func__);
s3c2410_usb_report_oc(info, 0);
}
return IRQ_HANDLED;
}
static void smartq_usb_host_enableoc(struct s3c2410_hcd_info *info, int on)
{
int ret;
if (machine_is_smartq5())
return;
if (on) {
ret = request_irq(gpio_to_irq(S3C64XX_GPL(10)),
smartq_usb_host_ocirq, IRQF_DISABLED |
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"USB host overcurrent", info);
if (ret != 0)
pr_err("failed to request usb oc irq: %d\n", ret);
} else {
free_irq(gpio_to_irq(S3C64XX_GPL(10)), info);
}
}
static int smartq_bl_init(struct device *dev)
{
s3c_gpio_cfgpin(S3C64XX_GPF(15), S3C_GPIO_SFN(2));
return 0;
}
static int __init smartq_lcd_setup_gpio(void)
{
int ret;
ret = gpio_request(S3C64XX_GPM(3), "LCD power");
if (ret < 0)
return ret;
gpio_direction_output(S3C64XX_GPM(3), 0);
return 0;
}
static void smartq_lcd_power_set(struct plat_lcd_data *pd, unsigned int power)
{
gpio_direction_output(S3C64XX_GPM(3), power);
}
static void __init smartq_lcd_mode_set(void)
{
u32 tmp;
tmp = __raw_readl(S3C64XX_SPCON);
tmp &= ~S3C64XX_SPCON_LCD_SEL_MASK;
tmp |= S3C64XX_SPCON_LCD_SEL_RGB;
__raw_writel(tmp, S3C64XX_SPCON);
tmp = __raw_readl(S3C64XX_MODEM_MIFPCON);
tmp &= ~MIFPCON_LCD_BYPASS;
__raw_writel(tmp, S3C64XX_MODEM_MIFPCON);
}
static void smartq_power_off(void)
{
gpio_direction_output(S3C64XX_GPK(15), 1);
}
static int __init smartq_power_off_init(void)
{
int ret;
ret = gpio_request(S3C64XX_GPK(15), "Power control");
if (ret < 0) {
pr_err("%s: failed to get GPK15\n", __func__);
return ret;
}
gpio_direction_output(S3C64XX_GPK(15), 0);
pm_power_off = smartq_power_off;
return ret;
}
static int __init smartq_usb_host_init(void)
{
int ret;
ret = gpio_request(S3C64XX_GPL(0), "USB power control");
if (ret < 0) {
pr_err("%s: failed to get GPL0\n", __func__);
return ret;
}
ret = gpio_request(S3C64XX_GPL(1), "USB host power control");
if (ret < 0) {
pr_err("%s: failed to get GPL1\n", __func__);
goto err;
}
if (!machine_is_smartq5()) {
ret = gpio_request(S3C64XX_GPL(10), "USB host overcurrent");
if (ret < 0) {
pr_err("%s: failed to get GPL10\n", __func__);
goto err2;
}
}
gpio_direction_output(S3C64XX_GPL(0), 0);
gpio_direction_output(S3C64XX_GPL(1), 0);
if (!machine_is_smartq5())
gpio_direction_input(S3C64XX_GPL(10));
s3c_device_ohci.dev.platform_data = &smartq_usb_host_info;
return 0;
err2:
gpio_free(S3C64XX_GPL(1));
err:
gpio_free(S3C64XX_GPL(0));
return ret;
}
static int __init smartq_wifi_init(void)
{
int ret;
ret = gpio_request(S3C64XX_GPK(1), "wifi control");
if (ret < 0) {
pr_err("%s: failed to get GPK1\n", __func__);
return ret;
}
ret = gpio_request(S3C64XX_GPK(2), "wifi reset");
if (ret < 0) {
pr_err("%s: failed to get GPK2\n", __func__);
gpio_free(S3C64XX_GPK(1));
return ret;
}
gpio_direction_output(S3C64XX_GPK(1), 1);
gpio_direction_output(S3C64XX_GPK(2), 0);
mdelay(100);
gpio_set_value(S3C64XX_GPK(2), 1);
gpio_direction_input(S3C64XX_GPK(2));
return 0;
}
void __init smartq_map_io(void)
{
s3c64xx_init_io(smartq_iodesc, ARRAY_SIZE(smartq_iodesc));
s3c64xx_set_xtal_freq(12000000);
s3c64xx_set_xusbxti_freq(12000000);
s3c24xx_init_uarts(smartq_uartcfgs, ARRAY_SIZE(smartq_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
smartq_lcd_mode_set();
}
void __init smartq_machine_init(void)
{
s3c_i2c0_set_platdata(NULL);
s3c_hsotg_set_platdata(&smartq_hsotg_pdata);
s3c_hwmon_set_platdata(&smartq_hwmon_pdata);
s3c_sdhci1_set_platdata(&smartq_internal_hsmmc_pdata);
s3c_sdhci2_set_platdata(&smartq_internal_hsmmc_pdata);
s3c24xx_ts_set_platdata(&smartq_touchscreen_pdata);
i2c_register_board_info(0, smartq_i2c_devs,
ARRAY_SIZE(smartq_i2c_devs));
WARN_ON(smartq_lcd_setup_gpio());
WARN_ON(smartq_power_off_init());
WARN_ON(smartq_usb_host_init());
WARN_ON(smartq_wifi_init());
platform_add_devices(smartq_devices, ARRAY_SIZE(smartq_devices));
}
