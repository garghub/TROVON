void __msm_gpiomux_write(unsigned gpio, gpiomux_config_t val)\r\n{\r\nwritel(val & ~GPIOMUX_CTL_MASK,\r\nMSM_TLMM_BASE + 0x1000 + (0x10 * gpio));\r\n}
