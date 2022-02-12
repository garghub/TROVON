static int uniphier_sld8_get_gpio_muxval(unsigned int pin,
unsigned int gpio_offset)
{
switch (gpio_offset) {
case 120 ... 127:
return 0;
case 128 ... 132:
case 134 ... 135:
return 14;
default:
return 15;
}
}
static int uniphier_sld8_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &uniphier_sld8_pindata);
}
