static void __init smartq5_machine_init(void)\r\n{\r\ns3c_fb_set_platdata(&smartq5_lcd_pdata);\r\nsmartq_machine_init();\r\nplatform_add_devices(smartq5_devices, ARRAY_SIZE(smartq5_devices));\r\n}
