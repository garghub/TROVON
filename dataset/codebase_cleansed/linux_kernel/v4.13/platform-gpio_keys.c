struct platform_device *__init imx_add_gpio_keys(
const struct gpio_keys_platform_data *pdata)
{
return imx_add_platform_device("gpio-keys", -1, NULL,
0, pdata, sizeof(*pdata));
}
