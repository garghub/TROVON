static int h3_panel_enable(struct lcd_panel *panel)
{
int r = 0;
r = tps65010_set_gpio_out_value(GPIO1, HIGH);
if (!r)
r = tps65010_set_gpio_out_value(GPIO2, HIGH);
if (r)
pr_err(MODULE_NAME ": Unable to turn on LCD panel\n");
return r;
}
static void h3_panel_disable(struct lcd_panel *panel)
{
int r = 0;
r = tps65010_set_gpio_out_value(GPIO1, LOW);
if (!r)
tps65010_set_gpio_out_value(GPIO2, LOW);
if (r)
pr_err(MODULE_NAME ": Unable to turn off LCD panel\n");
}
static int h3_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&h3_panel);
return 0;
}
