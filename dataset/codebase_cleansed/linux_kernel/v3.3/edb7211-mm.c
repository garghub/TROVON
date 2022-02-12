void __init edb7211_map_io(void)\r\n{\r\nclps711x_map_io();\r\niotable_init(edb7211_io_desc, ARRAY_SIZE(edb7211_io_desc));\r\n}
