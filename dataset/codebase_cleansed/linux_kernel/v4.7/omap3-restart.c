void omap3xxx_restart(enum reboot_mode mode, const char *cmd)\r\n{\r\nomap3_ctrl_write_boot_mode((cmd ? (u8)*cmd : 0));\r\nomap_prm_reset_system();\r\n}
