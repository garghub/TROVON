static void idp_backlight_power(int on)
{
if (on) {
IDP_CPLD_LCD |= (1<<1);
} else {
IDP_CPLD_LCD &= ~(1<<1);
}
}
static void idp_vlcd(int on)
{
if (on) {
IDP_CPLD_LCD |= (1<<2);
} else {
IDP_CPLD_LCD &= ~(1<<2);
}
}
static void idp_lcd_power(int on, struct fb_var_screeninfo *var)
{
if (on) {
IDP_CPLD_LCD |= (1<<0);
} else {
IDP_CPLD_LCD &= ~(1<<0);
}
idp_vlcd(on);
}
static void __init idp_init(void)
{
printk("idp_init()\n");
pxa2xx_mfp_config(ARRAY_AND_SIZE(idp_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
platform_device_register(&smc91x_device);
pxa_set_fb_info(NULL, &sharp_lm8v31);
pxa_set_mci_info(&idp_mci_platform_data);
}
static void __init idp_map_io(void)
{
pxa25x_map_io();
iotable_init(idp_io_desc, ARRAY_SIZE(idp_io_desc));
}
