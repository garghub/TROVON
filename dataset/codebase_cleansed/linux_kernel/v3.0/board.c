const char *get_system_type(void)
{
return "NXP STB22x";
}
static inline unsigned long env_or_default(char *env, unsigned long dfl)
{
char *str = prom_getenv(env);
return str ? simple_strtol(str, 0, 0) : dfl;
}
void __init prom_init(void)
{
unsigned long memsize;
prom_argc = fw_arg0;
prom_argv = (char **)fw_arg1;
prom_envp = (char **)fw_arg2;
prom_init_cmdline();
memsize = env_or_default("memsize", 0x02000000);
add_memory_region(0, memsize, BOOT_MEM_RAM);
}
void __init pnx833x_board_setup(void)
{
pnx833x_gpio_select_function_alt(4);
pnx833x_gpio_select_output(4);
pnx833x_gpio_select_function_alt(5);
pnx833x_gpio_select_input(5);
pnx833x_gpio_select_function_alt(6);
pnx833x_gpio_select_input(6);
pnx833x_gpio_select_function_alt(7);
pnx833x_gpio_select_output(7);
pnx833x_gpio_select_function_alt(25);
pnx833x_gpio_select_function_alt(26);
pnx833x_gpio_select_function_alt(27);
pnx833x_gpio_select_function_alt(28);
pnx833x_gpio_select_function_alt(29);
pnx833x_gpio_select_function_alt(30);
pnx833x_gpio_select_function_alt(31);
pnx833x_gpio_select_function_alt(32);
pnx833x_gpio_select_function_alt(33);
#if defined(CONFIG_MTD_NAND_PLATFORM) || defined(CONFIG_MTD_NAND_PLATFORM_MODULE)
PNX833X_MIU_SEL0 = 0;
PNX833X_MIU_SEL1 = 0;
PNX833X_MIU_SEL0_TIMING = 0x50003081;
PNX833X_MIU_SEL1_TIMING = 0x50003081;
pnx833x_gpio_select_function_alt(0);
pnx833x_gpio_select_function_io(4);
pnx833x_gpio_select_input(4);
pnx833x_gpio_select_function_io(5);
pnx833x_gpio_select_output(5);
pnx833x_gpio_write(1, 5);
#elif defined(CONFIG_MTD_CFI) || defined(CONFIG_MTD_CFI_MODULE)
PNX833X_MIU_SEL0 = 1;
PNX833X_MIU_SEL1 = 1;
PNX833X_MIU_SEL0_TIMING = 0x6A08D082;
PNX833X_MIU_SEL1_TIMING = 0x6A08D082;
pnx833x_gpio_select_function_alt(0);
#endif
}
