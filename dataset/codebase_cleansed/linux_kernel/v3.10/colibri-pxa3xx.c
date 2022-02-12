void __init colibri_pxa3xx_init_eth(struct ax_plat_data *plat_data)
{
int i;
u64 serial = ((u64) system_serial_high << 32) | system_serial_low;
for (i = 0; i < ETHER_ADDR_LEN; i++) {
ether_mac_addr[i] = serial & 0xff;
serial >>= 8;
}
if (is_valid_ether_addr(ether_mac_addr)) {
plat_data->flags |= AXFLG_MAC_FROMPLATFORM;
plat_data->mac_addr = ether_mac_addr;
printk(KERN_INFO "%s(): taking MAC from serial boot tag\n",
__func__);
} else {
plat_data->flags |= AXFLG_MAC_FROMDEV;
printk(KERN_INFO "%s(): no valid serial boot tag found, "
"taking MAC from device\n", __func__);
}
}
static void colibri_lcd_backlight(int on)
{
gpio_set_value(lcd_bl_pin, !!on);
}
void __init colibri_pxa3xx_init_lcd(int bl_pin)
{
lcd_bl_pin = bl_pin;
gpio_request(bl_pin, "lcd backlight");
gpio_direction_output(bl_pin, 0);
pxa_set_fb_info(NULL, &sharp_lq43_info);
}
void __init colibri_pxa3xx_init_nand(void)
{
pxa3xx_set_nand_info(&colibri_nand_info);
}
