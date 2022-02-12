static int uniphier_pro4_get_gpio_muxval(unsigned int pin,
unsigned int gpio_offset)
{
if (gpio_offset >= 134 && gpio_offset <= 140)
return 2;
return 7;
}
static int uniphier_pro4_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &uniphier_pro4_pindata);
}
