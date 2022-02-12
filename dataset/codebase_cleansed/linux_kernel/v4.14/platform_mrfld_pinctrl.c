static int __init mrfld_pinctrl_init(void)\r\n{\r\nif (intel_mid_identify_cpu() == INTEL_MID_CPU_CHIP_TANGIER)\r\nreturn platform_device_register(&mrfld_pinctrl_device);\r\nreturn -ENODEV;\r\n}
