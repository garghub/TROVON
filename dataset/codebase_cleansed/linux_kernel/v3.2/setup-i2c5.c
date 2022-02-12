void s3c_i2c5_cfg_gpio(struct platform_device *dev)\r\n{\r\ns3c_gpio_cfgall_range(EXYNOS4_GPB(6), 2,\r\nS3C_GPIO_SFN(3), S3C_GPIO_PULL_UP);\r\n}
