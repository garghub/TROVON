static void null_prom_display(const char *string, int pos, int clear)
{
}
static void null_prom_monitor(void)
{
}
static void null_prom_putc(char c)
{
}
void prom_putchar(char c)
{
__prom_putc(c);
}
static void setup_prom_vectors(void)
{
u32 version = *(u32 *)(RESET_VECTOR + 0x90);
if (version >= 307) {
prom_display = (void *)PROM_DISPLAY_ADDR;
__prom_putc = (void *)PROM_PUTC_ADDR;
prom_monitor = (void *)PROM_MONITOR_ADDR;
}
printk(KERN_DEBUG "prom vectors set up\n");
}
void __init prom_init(void)
{
int argc = fw_arg0;
char **argv = (char **) fw_arg1;
setup_prom_vectors();
if (IS_LASAT_200()) {
printk(KERN_INFO "LASAT 200 board\n");
lasat_ndelay_divider = LASAT_200_DIVIDER;
at93c = &at93c_defs[1];
} else {
printk(KERN_INFO "LASAT 100 board\n");
lasat_ndelay_divider = LASAT_100_DIVIDER;
at93c = &at93c_defs[0];
}
lasat_init_board_info();
if (argc > 0) {
strncpy(arcs_cmdline, argv[0], COMMAND_LINE_SIZE-1);
arcs_cmdline[COMMAND_LINE_SIZE-1] = '\0';
}
set_io_port_base(KSEG1);
ioport_resource.start = 0;
ioport_resource.end = 0xffffffff;
add_memory_region(0, lasat_board_info.li_memsize, BOOT_MEM_RAM);
}
void __init prom_free_prom_memory(void)
{
}
const char *get_system_type(void)
{
return lasat_board_info.li_bmstr;
}
