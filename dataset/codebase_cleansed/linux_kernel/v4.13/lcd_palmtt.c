static unsigned long palmtt_panel_get_caps(struct lcd_panel *panel)
{
return OMAPFB_CAPS_SET_BACKLIGHT;
}
static int palmtt_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&palmtt_panel);
return 0;
}
