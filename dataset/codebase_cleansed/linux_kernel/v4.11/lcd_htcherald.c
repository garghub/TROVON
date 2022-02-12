static int htcherald_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&htcherald_panel_1);
return 0;
}
