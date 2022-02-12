static void __init emev2_map_io(void)\r\n{\r\niotable_init(emev2_io_desc, ARRAY_SIZE(emev2_io_desc));\r\n}
