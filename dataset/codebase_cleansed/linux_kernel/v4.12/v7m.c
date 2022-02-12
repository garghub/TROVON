void armv7m_restart(enum reboot_mode mode, const char *cmd)\r\n{\r\ndsb();\r\n__raw_writel(V7M_SCB_AIRCR_VECTKEY | V7M_SCB_AIRCR_SYSRESETREQ,\r\nBASEADDR_V7M_SCB + V7M_SCB_AIRCR);\r\ndsb();\r\n}
