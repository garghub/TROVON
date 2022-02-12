void __init tegra_paz00_wifikill_init(void)\r\n{\r\ngpiod_add_lookup_table(&wifi_gpio_lookup);\r\nplatform_device_register(&wifi_rfkill_device);\r\n}
