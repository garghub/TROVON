bool has_cpuflag(int flag)\r\n{\r\nget_cpuflags();\r\nreturn test_bit(flag, cpu.flags);\r\n}
