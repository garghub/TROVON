static void *tc35876x_platform_data(void *data)
{
static struct tc35876x_platform_data pdata;
pdata.gpio_bridge_reset = get_gpio_by_name("LCMB_RXEN");
pdata.gpio_panel_bl_en = get_gpio_by_name("6S6P_BL_EN");
pdata.gpio_panel_vadd = get_gpio_by_name("EN_VREG_LCD_V3P3");
return &pdata;
}
