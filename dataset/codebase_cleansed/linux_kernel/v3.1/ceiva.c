static void __init ceiva_map_io(void)\r\n{\r\nclps711x_map_io();\r\niotable_init(ceiva_io_desc, ARRAY_SIZE(ceiva_io_desc));\r\n}
