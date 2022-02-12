void omap44xx_restart(enum reboot_mode mode, const char *cmd)\r\n{\r\nomap4_prminst_global_warm_sw_reset();\r\nwhile (1)\r\n;\r\n}
