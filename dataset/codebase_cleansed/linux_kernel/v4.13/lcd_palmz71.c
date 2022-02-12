static unsigned long palmz71_panel_get_caps(struct lcd_panel *panel)
{
return OMAPFB_CAPS_SET_BACKLIGHT;
}
static int palmz71_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&palmz71_panel);
return 0;
}
