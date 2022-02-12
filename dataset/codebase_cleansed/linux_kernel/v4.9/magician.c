static void toppoly_lcd_power(int on, struct fb_var_screeninfo *si)
{
pr_debug("Toppoly LCD power: %s\n", on ? "on" : "off");
if (on) {
gpio_set_value(EGPIO_MAGICIAN_TOPPOLY_POWER, 1);
gpio_set_value(GPIO106_MAGICIAN_LCD_DCDC_NRESET, 1);
udelay(2000);
gpio_set_value(EGPIO_MAGICIAN_LCD_POWER, 1);
udelay(2000);
udelay(2000);
gpio_set_value(GPIO104_MAGICIAN_LCD_VOFF_EN, 1);
udelay(2000);
gpio_set_value(GPIO105_MAGICIAN_LCD_VON_EN, 1);
} else {
msleep(15);
gpio_set_value(GPIO105_MAGICIAN_LCD_VON_EN, 0);
udelay(500);
gpio_set_value(GPIO104_MAGICIAN_LCD_VOFF_EN, 0);
udelay(1000);
gpio_set_value(GPIO106_MAGICIAN_LCD_DCDC_NRESET, 0);
gpio_set_value(EGPIO_MAGICIAN_LCD_POWER, 0);
}
}
static void samsung_lcd_power(int on, struct fb_var_screeninfo *si)
{
pr_debug("Samsung LCD power: %s\n", on ? "on" : "off");
if (on) {
if (system_rev < 3)
gpio_set_value(GPIO75_MAGICIAN_SAMSUNG_POWER, 1);
else
gpio_set_value(EGPIO_MAGICIAN_LCD_POWER, 1);
mdelay(6);
gpio_set_value(GPIO106_MAGICIAN_LCD_DCDC_NRESET, 1);
mdelay(6);
gpio_set_value(GPIO104_MAGICIAN_LCD_VOFF_EN, 1);
mdelay(16);
gpio_set_value(GPIO105_MAGICIAN_LCD_VON_EN, 1);
} else {
gpio_set_value(GPIO105_MAGICIAN_LCD_VON_EN, 0);
mdelay(16);
gpio_set_value(GPIO104_MAGICIAN_LCD_VOFF_EN, 0);
mdelay(6);
gpio_set_value(GPIO106_MAGICIAN_LCD_DCDC_NRESET, 0);
mdelay(6);
if (system_rev < 3)
gpio_set_value(GPIO75_MAGICIAN_SAMSUNG_POWER, 0);
else
gpio_set_value(EGPIO_MAGICIAN_LCD_POWER, 0);
}
}
static int magician_backlight_init(struct device *dev)
{
return gpio_request_array(ARRAY_AND_SIZE(magician_bl_gpios));
}
static int magician_backlight_notify(struct device *dev, int brightness)
{
pr_debug("Brightness = %i\n", brightness);
gpio_set_value(EGPIO_MAGICIAN_BL_POWER, brightness);
if (brightness >= 200) {
gpio_set_value(EGPIO_MAGICIAN_BL_POWER2, 1);
return brightness - 72;
} else {
gpio_set_value(EGPIO_MAGICIAN_BL_POWER2, 0);
return brightness;
}
}
static void magician_backlight_exit(struct device *dev)
{
gpio_free_array(ARRAY_AND_SIZE(magician_bl_gpios));
}
static void magician_udc_command(int cmd)
{
if (cmd == PXA2XX_UDC_CMD_CONNECT)
UP2OCR |= UP2OCR_DPPUE | UP2OCR_DPPUBE;
else if (cmd == PXA2XX_UDC_CMD_DISCONNECT)
UP2OCR &= ~(UP2OCR_DPPUE | UP2OCR_DPPUBE);
}
static int magician_supply_init(struct device *dev)
{
int ret = -1;
ret = gpio_request(EGPIO_MAGICIAN_CABLE_TYPE, "Cable is AC charger");
if (ret) {
pr_err("Cannot request AC/USB charger GPIO (%i)\n", ret);
goto err_ac;
}
ret = gpio_request(EGPIO_MAGICIAN_CABLE_INSERTED, "Cable inserted");
if (ret) {
pr_err("Cannot request cable detection GPIO (%i)\n", ret);
goto err_usb;
}
return 0;
err_usb:
gpio_free(EGPIO_MAGICIAN_CABLE_TYPE);
err_ac:
return ret;
}
static void magician_set_charge(int flags)
{
if (flags & PDA_POWER_CHARGE_AC) {
pr_debug("Charging from AC\n");
gpio_set_value(EGPIO_MAGICIAN_NICD_CHARGE, 1);
} else if (flags & PDA_POWER_CHARGE_USB) {
pr_debug("Charging from USB\n");
gpio_set_value(EGPIO_MAGICIAN_NICD_CHARGE, 1);
} else {
pr_debug("Charging disabled\n");
gpio_set_value(EGPIO_MAGICIAN_NICD_CHARGE, 0);
}
}
static int magician_is_ac_online(void)
{
return gpio_get_value(EGPIO_MAGICIAN_CABLE_INSERTED) &&
gpio_get_value(EGPIO_MAGICIAN_CABLE_TYPE);
}
static int magician_is_usb_online(void)
{
return gpio_get_value(EGPIO_MAGICIAN_CABLE_INSERTED) &&
(!gpio_get_value(EGPIO_MAGICIAN_CABLE_TYPE));
}
static void magician_supply_exit(struct device *dev)
{
gpio_free(EGPIO_MAGICIAN_CABLE_INSERTED);
gpio_free(EGPIO_MAGICIAN_CABLE_TYPE);
}
static int magician_mci_init(struct device *dev,
irq_handler_t detect_irq, void *data)
{
return request_irq(IRQ_MAGICIAN_SD, detect_irq, 0,
"mmc card detect", data);
}
static void magician_mci_exit(struct device *dev, void *data)
{
free_irq(IRQ_MAGICIAN_SD, data);
}
static int magician_flash_init(struct platform_device *pdev)
{
int ret = gpio_request(EGPIO_MAGICIAN_FLASH_VPP, "flash Vpp enable");
if (ret) {
pr_err("Cannot request flash enable GPIO (%i)\n", ret);
return ret;
}
ret = gpio_direction_output(EGPIO_MAGICIAN_FLASH_VPP, 1);
if (ret) {
pr_err("Cannot set direction for flash enable (%i)\n", ret);
gpio_free(EGPIO_MAGICIAN_FLASH_VPP);
}
return ret;
}
static void magician_set_vpp(struct platform_device *pdev, int vpp)
{
gpio_set_value(EGPIO_MAGICIAN_FLASH_VPP, vpp);
}
static void magician_flash_exit(struct platform_device *pdev)
{
gpio_free(EGPIO_MAGICIAN_FLASH_VPP);
}
static void __init magician_init(void)
{
void __iomem *cpld;
int lcd_select;
int err;
pxa2xx_mfp_config(ARRAY_AND_SIZE(magician_pin_config));
err = gpio_request_array(ARRAY_AND_SIZE(magician_global_gpios));
if (err)
pr_err("magician: Failed to request global GPIOs: %d\n", err);
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pwm_add_table(magician_pwm_lookup, ARRAY_SIZE(magician_pwm_lookup));
pxa_set_ficp_info(&magician_ficp_info);
pxa27x_set_i2c_power_info(&magician_i2c_power_info);
pxa_set_i2c_info(&i2c_info);
i2c_register_board_info(1,
ARRAY_AND_SIZE(magician_pwr_i2c_board_info));
pxa_set_mci_info(&magician_mci_info);
pxa_set_ohci_info(&magician_ohci_info);
pxa_set_udc_info(&magician_udc_info);
cpld = ioremap_nocache(PXA_CS3_PHYS, 0x1000);
if (cpld) {
u8 board_id = __raw_readb(cpld + 0x14);
iounmap(cpld);
system_rev = board_id & 0x7;
lcd_select = board_id & 0x8;
pr_info("LCD type: %s\n", lcd_select ? "Samsung" : "Toppoly");
if (lcd_select && (system_rev < 3))
gpio_request_one(GPIO75_MAGICIAN_SAMSUNG_POWER,
GPIOF_OUT_INIT_LOW, "Samsung LCD Power");
pxa_set_fb_info(NULL,
lcd_select ? &samsung_info : &toppoly_info);
} else
pr_err("LCD detection: CPLD mapping failed\n");
regulator_register_always_on(0, "power", pwm_backlight_supply,
ARRAY_SIZE(pwm_backlight_supply), 5000000);
platform_add_devices(ARRAY_AND_SIZE(devices));
}
