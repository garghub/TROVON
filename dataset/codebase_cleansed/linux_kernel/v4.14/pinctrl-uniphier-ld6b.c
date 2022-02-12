static int uniphier_ld6b_get_gpio_muxval(unsigned int pin,
unsigned int gpio_offset)
{
if (gpio_offset >= 120 && gpio_offset <= 143)
return 14;
return 15;
}
static int uniphier_ld6b_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &uniphier_ld6b_pindata);
}
