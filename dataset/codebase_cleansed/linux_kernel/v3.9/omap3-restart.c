void omap3xxx_restart(char mode, const char *cmd)\r\n{\r\nomap3_ctrl_write_boot_mode((cmd ? (u8)*cmd : 0));\r\nomap3xxx_prm_dpll3_reset();\r\nwhile (1);\r\n}
