static int __init iop3xx_pmu_init(void)\r\n{\r\nplatform_device_register(&pmu_device);\r\nreturn 0;\r\n}
