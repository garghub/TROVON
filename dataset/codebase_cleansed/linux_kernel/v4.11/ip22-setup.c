void __init plat_mem_setup(void)
{
char *ctype;
char *cserial;
board_be_init = ip22_be_init;
sgihpc_init();
sgimc_init();
#ifdef CONFIG_BOARD_SCACHE
indy_sc_init();
#endif
set_io_port_base((unsigned long)ioremap(0x00080000,
0x1fffffff - 0x00080000));
ctype = ArcGetEnvironmentVariable("console");
cserial = ArcGetEnvironmentVariable("ConsoleOut");
if ((ctype && *ctype == 'd') || (cserial && *cserial == 's')) {
static char options[8] __initdata;
char *baud = ArcGetEnvironmentVariable("dbaud");
if (baud)
strcpy(options, baud);
add_preferred_console("ttyS", *(ctype + 1) == '2' ? 1 : 0,
baud ? options : NULL);
} else if (!ctype || *ctype != 'g') {
prom_flags |= PROM_FLAG_USE_AS_CONSOLE;
add_preferred_console("arc", 0, NULL);
}
}
