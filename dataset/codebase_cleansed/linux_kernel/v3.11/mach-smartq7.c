static void __init smartq7_machine_init(void)\r\n{\r\ns3c_fb_set_platdata(&smartq7_lcd_pdata);\r\nsmartq_machine_init();\r\nplatform_add_devices(smartq7_devices, ARRAY_SIZE(smartq7_devices));\r\n}
