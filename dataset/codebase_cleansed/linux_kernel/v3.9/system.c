void highbank_restart(char mode, const char *cmd)\r\n{\r\nif (mode == 'h')\r\nhighbank_set_pwr_hard_reset();\r\nelse\r\nhighbank_set_pwr_soft_reset();\r\nwhile (1)\r\ncpu_do_idle();\r\n}
