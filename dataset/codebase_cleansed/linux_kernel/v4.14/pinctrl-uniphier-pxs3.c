static int uniphier_pxs3_get_gpio_muxval(unsigned int pin,
unsigned int gpio_offset)
{
if (gpio_offset >= 120 && gpio_offset <= 143) {
if (pin >= 219 && pin <= 234)
return 0;
return 14;
}
return 15;
}
static int uniphier_pxs3_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &uniphier_pxs3_pindata);
}
