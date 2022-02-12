static void __init gesbc9312_init_machine(void)\r\n{\r\nep93xx_init_devices();\r\nep93xx_register_flash(4, EP93XX_CS6_PHYS_BASE, SZ_8M);\r\nep93xx_register_eth(&gesbc9312_eth_data, 0);\r\n}
