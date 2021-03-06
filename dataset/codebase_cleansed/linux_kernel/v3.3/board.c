const char *get_system_type(void)\r\n{\r\nreturn "NXP STB22x";\r\n}\r\nstatic inline unsigned long env_or_default(char *env, unsigned long dfl)\r\n{\r\nchar *str = prom_getenv(env);\r\nreturn str ? simple_strtol(str, 0, 0) : dfl;\r\n}\r\nvoid __init prom_init(void)\r\n{\r\nunsigned long memsize;\r\nprom_argc = fw_arg0;\r\nprom_argv = (char **)fw_arg1;\r\nprom_envp = (char **)fw_arg2;\r\nprom_init_cmdline();\r\nmemsize = env_or_default("memsize", 0x02000000);\r\nadd_memory_region(0, memsize, BOOT_MEM_RAM);\r\n}\r\nvoid __init pnx833x_board_setup(void)\r\n{\r\npnx833x_gpio_select_function_alt(4);\r\npnx833x_gpio_select_output(4);\r\npnx833x_gpio_select_function_alt(5);\r\npnx833x_gpio_select_input(5);\r\npnx833x_gpio_select_function_alt(6);\r\npnx833x_gpio_select_input(6);\r\npnx833x_gpio_select_function_alt(7);\r\npnx833x_gpio_select_output(7);\r\npnx833x_gpio_select_function_alt(25);\r\npnx833x_gpio_select_function_alt(26);\r\npnx833x_gpio_select_function_alt(27);\r\npnx833x_gpio_select_function_alt(28);\r\npnx833x_gpio_select_function_alt(29);\r\npnx833x_gpio_select_function_alt(30);\r\npnx833x_gpio_select_function_alt(31);\r\npnx833x_gpio_select_function_alt(32);\r\npnx833x_gpio_select_function_alt(33);\r\n#if defined(CONFIG_MTD_NAND_PLATFORM) || defined(CONFIG_MTD_NAND_PLATFORM_MODULE)\r\nPNX833X_MIU_SEL0 = 0;\r\nPNX833X_MIU_SEL1 = 0;\r\nPNX833X_MIU_SEL0_TIMING = 0x50003081;\r\nPNX833X_MIU_SEL1_TIMING = 0x50003081;\r\npnx833x_gpio_select_function_alt(0);\r\npnx833x_gpio_select_function_io(4);\r\npnx833x_gpio_select_input(4);\r\npnx833x_gpio_select_function_io(5);\r\npnx833x_gpio_select_output(5);\r\npnx833x_gpio_write(1, 5);\r\n#elif defined(CONFIG_MTD_CFI) || defined(CONFIG_MTD_CFI_MODULE)\r\nPNX833X_MIU_SEL0 = 1;\r\nPNX833X_MIU_SEL1 = 1;\r\nPNX833X_MIU_SEL0_TIMING = 0x6A08D082;\r\nPNX833X_MIU_SEL1_TIMING = 0x6A08D082;\r\npnx833x_gpio_select_function_alt(0);\r\n#endif\r\n}
