static void __init avengers_lite_init(void)\r\n{\r\nmfp_config(ARRAY_AND_SIZE(avengers_lite_pin_config_V16F));\r\npxa168_add_uart(2);\r\n}
