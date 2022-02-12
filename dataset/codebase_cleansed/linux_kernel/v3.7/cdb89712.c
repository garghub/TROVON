static void __init cdb89712_map_io(void)\r\n{\r\nclps711x_map_io();\r\niotable_init(cdb89712_io_desc, ARRAY_SIZE(cdb89712_io_desc));\r\n}
