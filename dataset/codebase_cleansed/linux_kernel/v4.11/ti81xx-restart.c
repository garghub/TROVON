void ti81xx_restart(enum reboot_mode mode, const char *cmd)\r\n{\r\nomap2_prm_set_mod_reg_bits(TI81XX_GLOBAL_RST_COLD, 0,\r\nTI81XX_PRM_DEVICE_RSTCTRL);\r\nwhile (1);\r\n}
