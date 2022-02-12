static int __init s5p_pmu_init(void)\r\n{\r\nplatform_device_register(&s5p_device_pmu);\r\nreturn 0;\r\n}
