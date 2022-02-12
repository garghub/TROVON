int s3c64xx_spi0_cfg_gpio(void)\r\n{\r\ns3c2410_modify_misccr(S3C2416_MISCCR_HSSPI_EN2, 1);\r\ns3c_gpio_cfgall_range(S3C2410_GPE(11), 3,\r\nS3C_GPIO_SFN(2), S3C_GPIO_PULL_UP);\r\nreturn 0;\r\n}
