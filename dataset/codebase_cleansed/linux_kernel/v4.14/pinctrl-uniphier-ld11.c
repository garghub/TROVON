static int uniphier_ld11_get_gpio_muxval(unsigned int pin,
unsigned int gpio_offset)
{
if (gpio_offset == 132 || gpio_offset == 135)
return 13;
if (gpio_offset >= 120 && gpio_offset <= 143)
return 14;
return 15;
}
static int uniphier_ld11_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &uniphier_ld11_pindata);
}
