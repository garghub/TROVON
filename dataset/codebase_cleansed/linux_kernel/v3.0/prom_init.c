const char *get_system_type(void)
{
return "NXP PNX8950/STB810";
}
void __init prom_init(void)
{
unsigned long memsize;
prom_argc = (int) fw_arg0;
prom_argv = (char **) fw_arg1;
prom_envp = (char **) fw_arg2;
prom_init_cmdline();
memsize = 0x08000000;
add_memory_region(0, memsize, BOOT_MEM_RAM);
}
