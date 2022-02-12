static void __init imx31_dt_mach_init(void)\r\n{\r\nplatform_device_register_simple("mxc_rnga", -1, imx31_rnga_res,\r\nARRAY_SIZE(imx31_rnga_res));\r\n}
