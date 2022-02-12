void harmony_pinmux_init(void)\r\n{\r\ntegra_pinmux_config_table(harmony_pinmux, ARRAY_SIZE(harmony_pinmux));\r\ntegra_gpio_config(gpio_table, ARRAY_SIZE(gpio_table));\r\n}
