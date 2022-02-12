static void __init kzm_init(void)\r\n{\r\nsh73a0_add_standard_devices_dt();\r\n#ifdef CONFIG_CACHE_L2X0\r\nl2x0_init(IOMEM(0xf0100000), 0x40460000, 0x82000fff);\r\n#endif\r\n}
