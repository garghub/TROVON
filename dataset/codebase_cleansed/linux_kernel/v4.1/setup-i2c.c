void s3c_i2c0_cfg_gpio(struct platform_device *dev)\r\n{\r\ns3c_gpio_cfgpin(S3C2410_GPE(15), S3C2410_GPE15_IICSDA);\r\ns3c_gpio_cfgpin(S3C2410_GPE(14), S3C2410_GPE14_IICSCL);\r\n}
