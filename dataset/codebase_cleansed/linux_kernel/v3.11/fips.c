static int fips_enable(char *str)\r\n{\r\nfips_enabled = !!simple_strtol(str, NULL, 0);\r\nprintk(KERN_INFO "fips mode: %s\n",\r\nfips_enabled ? "enabled" : "disabled");\r\nreturn 1;\r\n}
