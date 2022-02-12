static int palmte_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&palmte_panel);
return 0;
}
