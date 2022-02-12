static int uniphier_ld4_get_gpio_muxval(unsigned int pin,
unsigned int gpio_offset)
{
switch (gpio_offset) {
case 0 ... 22:
case 121 ... 131:
case 134:
return 0;
case 120:
case 132:
case 135:
return 14;
default:
return 15;
}
}
static int uniphier_ld4_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &uniphier_ld4_pindata);
}
