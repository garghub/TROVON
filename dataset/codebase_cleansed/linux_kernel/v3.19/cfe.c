static void __noreturn cfe_linux_exit(void *arg)
{
int warm = *(int *)arg;
if (smp_processor_id()) {
static int reboot_smp;
if (!reboot_smp) {
reboot_smp = 1;
smp_call_function(cfe_linux_exit, arg, 0);
}
} else {
printk("Passing control back to CFE...\n");
cfe_exit(warm, 0);
printk("cfe_exit returned??\n");
}
while (1);
}
static void __noreturn cfe_linux_restart(char *command)
{
static const int zero;
cfe_linux_exit((void *)&zero);
}
static void __noreturn cfe_linux_halt(void)
{
static const int one = 1;
cfe_linux_exit((void *)&one);
}
static __init void prom_meminit(void)
{
u64 addr, size, type;
int mem_flags = 0;
unsigned int idx;
int rd_flag;
#ifdef CONFIG_BLK_DEV_INITRD
unsigned long initrd_pstart;
unsigned long initrd_pend;
initrd_pstart = CPHYSADDR(initrd_start);
initrd_pend = CPHYSADDR(initrd_end);
if (initrd_start &&
((initrd_pstart > MAX_RAM_SIZE)
|| (initrd_pend > MAX_RAM_SIZE))) {
panic("initrd out of addressable memory");
}
#endif
for (idx = 0; cfe_enummem(idx, mem_flags, &addr, &size, &type) != CFE_ERR_NOMORE;
idx++) {
rd_flag = 0;
if (type == CFE_MI_AVAILABLE) {
#ifdef CONFIG_BLK_DEV_INITRD
if (initrd_start) {
if ((initrd_pstart > addr) &&
(initrd_pstart < (addr + size))) {
add_memory_region(addr,
initrd_pstart - addr,
BOOT_MEM_RAM);
rd_flag = 1;
}
if ((initrd_pend > addr) &&
(initrd_pend < (addr + size))) {
add_memory_region(initrd_pend,
(addr + size) - initrd_pend,
BOOT_MEM_RAM);
rd_flag = 1;
}
}
#endif
if (!rd_flag) {
if (addr > MAX_RAM_SIZE)
continue;
if (addr+size > MAX_RAM_SIZE)
size = MAX_RAM_SIZE - (addr+size) + 1;
if (size > 512)
size -= 512;
add_memory_region(addr, size, BOOT_MEM_RAM);
}
board_mem_region_addrs[board_mem_region_count] = addr;
board_mem_region_sizes[board_mem_region_count] = size;
board_mem_region_count++;
if (board_mem_region_count ==
SIBYTE_MAX_MEM_REGIONS) {
while(1);
}
}
}
#ifdef CONFIG_BLK_DEV_INITRD
if (initrd_start) {
add_memory_region(initrd_pstart, initrd_pend - initrd_pstart,
BOOT_MEM_RESERVED);
}
#endif
}
static int __init initrd_setup(char *str)
{
char rdarg[64];
int idx;
char *tmp, *endptr;
unsigned long initrd_size;
for (idx = 0; idx < sizeof(rdarg)-1; idx++) {
if (!str[idx] || (str[idx] == ' ')) break;
rdarg[idx] = str[idx];
}
rdarg[idx] = 0;
str = rdarg;
for (tmp = str; *tmp != '@'; tmp++) {
if (!*tmp) {
goto fail;
}
}
*tmp = 0;
tmp++;
if (!*tmp) {
goto fail;
}
initrd_size = simple_strtoul(str, &endptr, 16);
if (*endptr) {
*(tmp-1) = '@';
goto fail;
}
*(tmp-1) = '@';
initrd_start = simple_strtoul(tmp, &endptr, 16);
if (*endptr) {
goto fail;
}
initrd_end = initrd_start + initrd_size;
printk("Found initrd of %lx@%lx\n", initrd_size, initrd_start);
return 1;
fail:
printk("Bad initrd argument. Disabling initrd\n");
initrd_start = 0;
initrd_end = 0;
return 1;
}
void __init prom_init(void)
{
uint64_t cfe_ept, cfe_handle;
unsigned int cfe_eptseal;
int argc = fw_arg0;
char **envp = (char **) fw_arg2;
int *prom_vec = (int *) fw_arg3;
_machine_restart = cfe_linux_restart;
_machine_halt = cfe_linux_halt;
pm_power_off = cfe_linux_halt;
if (argc < 0) {
cfe_handle = (uint64_t)(long)argc;
cfe_ept = (long)envp;
cfe_eptseal = (uint32_t)(unsigned long)prom_vec;
} else {
if ((int32_t)(long)prom_vec < 0) {
cfe_handle = (uint64_t)(long)prom_vec;
cfe_ept = (uint64_t)((int32_t)0x9fc00500);
cfe_eptseal = CFE_EPTSEAL;
} else {
cfe_handle = (uint64_t)((int32_t *)prom_vec)[0];
cfe_ept = (uint64_t)((int32_t *)prom_vec)[2];
cfe_eptseal = (unsigned int)((uint32_t *)prom_vec)[3];
}
}
if (cfe_eptseal != CFE_EPTSEAL) {
printk("CFE's entrypoint seal doesn't match. Spinning.");
while (1) ;
}
cfe_init(cfe_handle, cfe_ept);
cfe_cons_handle = cfe_getstdhandle(CFE_STDHANDLE_CONSOLE);
if (cfe_getenv("LINUX_CMDLINE", arcs_cmdline, COMMAND_LINE_SIZE) < 0) {
if (argc >= 0) {
printk("LINUX_CMDLINE not defined in cfe.");
while (1) ;
}
}
#ifdef CONFIG_BLK_DEV_INITRD
{
char *ptr;
for (ptr = arcs_cmdline; *ptr; ptr++) {
while (*ptr == ' ') {
ptr++;
}
if (!strncmp(ptr, "initrd=", 7)) {
initrd_setup(ptr+7);
break;
} else {
while (*ptr && (*ptr != ' ')) {
ptr++;
}
}
}
}
#endif
arcs_cmdline[COMMAND_LINE_SIZE-1] = 0;
prom_meminit();
#if defined(CONFIG_SIBYTE_BCM112X) || defined(CONFIG_SIBYTE_SB1250)
register_smp_ops(&sb_smp_ops);
#endif
#if defined(CONFIG_SIBYTE_BCM1x55) || defined(CONFIG_SIBYTE_BCM1x80)
register_smp_ops(&bcm1480_smp_ops);
#endif
}
void __init prom_free_prom_memory(void)
{
}
void prom_putchar(char c)
{
int ret;
while ((ret = cfe_write(cfe_cons_handle, &c, 1)) == 0)
;
}
