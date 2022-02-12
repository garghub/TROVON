void s3c64xx_fb_gpio_setup_24bpp(void)\r\n{\r\ns3c_gpio_cfgrange_nopull(S3C64XX_GPI(0), 16, S3C_GPIO_SFN(2));\r\ns3c_gpio_cfgrange_nopull(S3C64XX_GPJ(0), 12, S3C_GPIO_SFN(2));\r\n}
