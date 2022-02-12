static void __init sama5d4_map_io(void)\r\n{\r\niotable_init(at91_io_desc, ARRAY_SIZE(at91_io_desc));\r\nat91_init_sram(0, SAMA5D4_NS_SRAM_BASE, SAMA5D4_NS_SRAM_SIZE);\r\n}
