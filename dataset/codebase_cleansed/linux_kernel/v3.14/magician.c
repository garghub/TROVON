static void toppoly_lcd_power(int on, struct fb_var_screeninfo *si)
{
pr_debug("Toppoly LCD power\n");
if (on) {
pr_debug("on\n");
gpio_set_value(EGPIO_MAGICIAN_TOPPOLY_POWER, 1);
gpio_set_value(GPIO106_MAGICIAN_LCD_POWER_3, 1);
udelay(2000);
gpio_set_value(EGPIO_MAGICIAN_LCD_POWER, 1);
udelay(2000);
udelay(2000);
gpio_set_value(GPIO104_MAGICIAN_LCD_POWER_1, 1);
udelay(2000);
gpio_set_value(GPIO105_MAGICIAN_LCD_POWER_2, 1);
} else {
pr_debug("off\n");
msleep(15);
gpio_set_value(GPIO105_MAGICIAN_LCD_POWER_2, 0);
udelay(500);
gpio_set_value(GPIO104_MAGICIAN_LCD_POWER_1, 0);
udelay(1000);
gpio_set_value(GPIO106_MAGICIAN_LCD_POWER_3, 0);
gpio_set_value(EGPIO_MAGICIAN_LCD_POWER, 0);
}
}
static void samsung_lcd_power(int on, struct fb_var_screeninfo *si)
{
pr_debug("Samsung LCD power\n");
if (on) {
pr_debug("on\n");
if (system_rev < 3)
gpio_set_value(GPIO75_MAGICIAN_SAMSUNG_POWER, 1);
else
gpio_set_value(EGPIO_MAGICIAN_LCD_POWER, 1);
mdelay(10);
gpio_set_value(GPIO106_MAGICIAN_LCD_POWER_3, 1);
mdelay(10);
gpio_set_value(GPIO104_MAGICIAN_LCD_POWER_1, 1);
mdelay(30);
gpio_set_value(GPIO105_MAGICIAN_LCD_POWER_2, 1);
mdelay(10);
} else {
pr_debug("off\n");
mdelay(10);
gpio_set_value(GPIO105_MAGICIAN_LCD_POWER_2, 0);
mdelay(30);
gpio_set_value(GPIO104_MAGICIAN_LCD_POWER_1, 0);
mdelay(10);
gpio_set_value(GPIO106_MAGICIAN_LCD_POWER_3, 0);
mdelay(10);
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
static int power_supply_init(struct device *dev)
{
return gpio_request(EGPIO_MAGICIAN_CABLE_STATE_AC, "CABLE_STATE_AC");
}
static int magician_is_ac_online(void)
{
return gpio_get_value(EGPIO_MAGICIAN_CABLE_STATE_AC);
}
static void power_supply_exit(struct device *dev)
{
gpio_free(EGPIO_MAGICIAN_CABLE_STATE_AC);
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
static void magician_set_vpp(struct platform_device *pdev, int vpp)
{
gpio_set_value(EGPIO_MAGICIAN_FLASH_VPP, vpp);
}
static void __init magician_init(void)
{
void __iomem *cpld;
int lcd_select;
int err;
pxa2xx_mfp_config(ARRAY_AND_SIZE(magician_pin_config));
err = gpio_request_array(ARRAY_AND_SIZE(magician_global_gpios));
if (err)
pr_err("magician: Failed to request GPIOs: %d\n", err);
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
platform_add_devices(ARRAY_AND_SIZE(devices));
pxa_set_ficp_info(&magician_ficp_info);
pxa27x_set_i2c_power_info(NULL);
pxa_set_i2c_info(&i2c_info);
pxa_set_mci_info(&magician_mci_info);
pxa_set_ohci_info(&magician_ohci_info);
cpld = ioremap_nocache(PXA_CS3_PHYS, 0x1000);
if (cpld) {
u8 board_id = __raw_readb(cpld+0x14);
iounmap(cpld);
system_rev = board_id & 0x7;
lcd_select = board_id & 0x8;
pr_info("LCD type: %s\n", lcd_select ? "Samsung" : "Toppoly");
if (lcd_select && (system_rev < 3))
gpio_request_one(GPIO75_MAGICIAN_SAMSUNG_POWER,
GPIOF_OUT_INIT_LOW, "SAMSUNG_POWER");
pxa_set_fb_info(NULL, lcd_select ? &samsung_info : &toppoly_info);
} else
pr_err("LCD detection: CPLD mapping failed\n");
}
