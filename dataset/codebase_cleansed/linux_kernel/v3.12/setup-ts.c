void s3c24xx_ts_cfg_gpio(struct platform_device *dev)\r\n{\r\ns3c_gpio_cfgpin_range(S3C2410_GPG(12), 4, S3C_GPIO_SFN(3));\r\n}
