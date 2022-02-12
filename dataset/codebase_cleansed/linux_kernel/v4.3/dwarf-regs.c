const char *get_arch_regstr(unsigned int n)\r\n{\r\nreturn (n >= NUM_GPRS) ? NULL : gpr_names[n];\r\n}
