void __init autcpu12_map_io(void)\r\n{\r\nclps711x_map_io();\r\niotable_init(autcpu12_io_desc, ARRAY_SIZE(autcpu12_io_desc));\r\n}
