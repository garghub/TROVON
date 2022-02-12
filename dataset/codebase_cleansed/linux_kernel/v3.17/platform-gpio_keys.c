struct platform_device *__init imx_add_gpio_keys(\r\nconst struct gpio_keys_platform_data *pdata)\r\n{\r\nreturn imx_add_platform_device("gpio-keys", -1, NULL,\r\n0, pdata, sizeof(*pdata));\r\n}
