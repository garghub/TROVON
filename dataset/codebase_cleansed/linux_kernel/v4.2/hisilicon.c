static void __init hi3620_map_io(void)\r\n{\r\ndebug_ll_io_init();\r\niotable_init(hi3620_io_desc, ARRAY_SIZE(hi3620_io_desc));\r\n}
