static int uniphier_pro5_get_gpio_muxval(unsigned int pin,
unsigned int gpio_offset)
{
if (gpio_offset >= 120 && gpio_offset <= 141)
return 14;
return 15;
}
static int uniphier_pro5_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &uniphier_pro5_pindata);
}
