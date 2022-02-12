static inline unsigned char str2hexnum(unsigned char c)
{
if (c >= '0' && c <= '9')
return c - '0';
if (c >= 'a' && c <= 'f')
return c - 'a' + 10;
return 0;
}
static inline void str2eaddr(unsigned char *ea, unsigned char *str)
{
int i;
for (i = 0; i < 6; i++) {
unsigned char num;
if(*str == ':')
str++;
num = str2hexnum(*str++) << 4;
num |= (str2hexnum(*str++));
ea[i] = num;
}
}
void __init plat_time_init(void)
{
printk(KERN_INFO "Calibrating system timer... ");
write_c0_count(0);
crime->timer = 0;
while (crime->timer < CRIME_MASTER_FREQ * WAIT_MS / 1000) ;
mips_hpt_frequency = read_c0_count() * 1000 / WAIT_MS;
printk("%d MHz CPU detected\n", mips_hpt_frequency * 2 / 1000000);
}
void __init plat_mem_setup(void)
{
board_be_init = ip32_be_init;
#ifdef CONFIG_SGI_O2MACE_ETH
{
char *mac = ArcGetEnvironmentVariable("eaddr");
str2eaddr(o2meth_eaddr, mac);
}
#endif
#if defined(CONFIG_SERIAL_CORE_CONSOLE)
{
char* con = ArcGetEnvironmentVariable("console");
if (con && *con == 'd') {
static char options[8] __initdata;
char *baud = ArcGetEnvironmentVariable("dbaud");
if (baud)
strcpy(options, baud);
add_preferred_console("ttyS", *(con + 1) == '2' ? 1 : 0,
baud ? options : NULL);
}
}
#endif
}
