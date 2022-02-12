static void __init m68k_parse_bootinfo(const struct bi_record *record)
{
while (record->tag != BI_LAST) {
int unknown = 0;
const unsigned long *data = record->data;
switch (record->tag) {
case BI_MACHTYPE:
case BI_CPUTYPE:
case BI_FPUTYPE:
case BI_MMUTYPE:
break;
case BI_MEMCHUNK:
if (m68k_num_memory < NUM_MEMINFO) {
m68k_memory[m68k_num_memory].addr = data[0];
m68k_memory[m68k_num_memory].size = data[1];
m68k_num_memory++;
} else
printk("m68k_parse_bootinfo: too many memory chunks\n");
break;
case BI_RAMDISK:
m68k_ramdisk.addr = data[0];
m68k_ramdisk.size = data[1];
break;
case BI_COMMAND_LINE:
strlcpy(m68k_command_line, (const char *)data,
sizeof(m68k_command_line));
break;
default:
if (MACH_IS_AMIGA)
unknown = amiga_parse_bootinfo(record);
else if (MACH_IS_ATARI)
unknown = atari_parse_bootinfo(record);
else if (MACH_IS_MAC)
unknown = mac_parse_bootinfo(record);
else if (MACH_IS_Q40)
unknown = q40_parse_bootinfo(record);
else if (MACH_IS_BVME6000)
unknown = bvme6000_parse_bootinfo(record);
else if (MACH_IS_MVME16x)
unknown = mvme16x_parse_bootinfo(record);
else if (MACH_IS_MVME147)
unknown = mvme147_parse_bootinfo(record);
else if (MACH_IS_HP300)
unknown = hp300_parse_bootinfo(record);
else if (MACH_IS_APOLLO)
unknown = apollo_parse_bootinfo(record);
else
unknown = 1;
}
if (unknown)
printk("m68k_parse_bootinfo: unknown tag 0x%04x ignored\n",
record->tag);
record = (struct bi_record *)((unsigned long)record +
record->size);
}
m68k_realnum_memory = m68k_num_memory;
#ifdef CONFIG_SINGLE_MEMORY_CHUNK
if (m68k_num_memory > 1) {
printk("Ignoring last %i chunks of physical memory\n",
(m68k_num_memory - 1));
m68k_num_memory = 1;
}
#endif
}
void __init setup_arch(char **cmdline_p)
{
int i;
m68k_parse_bootinfo((const struct bi_record *)_end);
if (CPU_IS_040)
m68k_is040or060 = 4;
else if (CPU_IS_060)
m68k_is040or060 = 6;
#ifndef CONFIG_M68KFPU_EMU_ONLY
if (m68k_fputype & (FPU_68881|FPU_68882|FPU_68040|FPU_68060)) {
volatile int zero = 0;
asm volatile ("frestore %0" : : "m" (zero));
}
#endif
if (CPU_IS_060) {
u32 pcr;
asm (".chip 68060; movec %%pcr,%0; .chip 68k"
: "=d" (pcr));
if (((pcr >> 8) & 0xff) <= 5) {
printk("Enabling workaround for errata I14\n");
asm (".chip 68060; movec %0,%%pcr; .chip 68k"
: : "d" (pcr | 0x20));
}
}
init_mm.start_code = PAGE_OFFSET;
init_mm.end_code = (unsigned long)_etext;
init_mm.end_data = (unsigned long)_edata;
init_mm.brk = (unsigned long)_end;
*cmdline_p = m68k_command_line;
memcpy(boot_command_line, *cmdline_p, CL_SIZE);
parse_early_param();
#ifdef CONFIG_DUMMY_CONSOLE
conswitchp = &dummy_con;
#endif
switch (m68k_machtype) {
#ifdef CONFIG_AMIGA
case MACH_AMIGA:
config_amiga();
break;
#endif
#ifdef CONFIG_ATARI
case MACH_ATARI:
config_atari();
break;
#endif
#ifdef CONFIG_MAC
case MACH_MAC:
config_mac();
break;
#endif
#ifdef CONFIG_SUN3
case MACH_SUN3:
config_sun3();
break;
#endif
#ifdef CONFIG_APOLLO
case MACH_APOLLO:
config_apollo();
break;
#endif
#ifdef CONFIG_MVME147
case MACH_MVME147:
config_mvme147();
break;
#endif
#ifdef CONFIG_MVME16x
case MACH_MVME16x:
config_mvme16x();
break;
#endif
#ifdef CONFIG_BVME6000
case MACH_BVME6000:
config_bvme6000();
break;
#endif
#ifdef CONFIG_HP300
case MACH_HP300:
config_hp300();
break;
#endif
#ifdef CONFIG_Q40
case MACH_Q40:
config_q40();
break;
#endif
#ifdef CONFIG_SUN3X
case MACH_SUN3X:
config_sun3x();
break;
#endif
default:
panic("No configuration setup");
}
#ifdef CONFIG_NATFEAT
nf_init();
#endif
paging_init();
#ifndef CONFIG_SUN3
for (i = 1; i < m68k_num_memory; i++)
free_bootmem_node(NODE_DATA(i), m68k_memory[i].addr,
m68k_memory[i].size);
#ifdef CONFIG_BLK_DEV_INITRD
if (m68k_ramdisk.size) {
reserve_bootmem_node(__virt_to_node(phys_to_virt(m68k_ramdisk.addr)),
m68k_ramdisk.addr, m68k_ramdisk.size,
BOOTMEM_DEFAULT);
initrd_start = (unsigned long)phys_to_virt(m68k_ramdisk.addr);
initrd_end = initrd_start + m68k_ramdisk.size;
printk("initrd: %08lx - %08lx\n", initrd_start, initrd_end);
}
#endif
#ifdef CONFIG_ATARI
if (MACH_IS_ATARI)
atari_stram_reserve_pages((void *)availmem);
#endif
#ifdef CONFIG_SUN3X
if (MACH_IS_SUN3X) {
dvma_init();
}
#endif
#endif
#if defined(CONFIG_ISA) && defined(MULTI_ISA)
if (MACH_IS_Q40) {
isa_type = ISA_TYPE_Q40;
isa_sex = 0;
}
#ifdef CONFIG_AMIGA_PCMCIA
if (MACH_IS_AMIGA && AMIGAHW_PRESENT(PCMCIA)) {
isa_type = ISA_TYPE_AG;
isa_sex = 1;
}
#endif
#endif
}
static int show_cpuinfo(struct seq_file *m, void *v)
{
const char *cpu, *mmu, *fpu;
unsigned long clockfreq, clockfactor;
#define LOOP_CYCLES_68020 (8)
#define LOOP_CYCLES_68030 (8)
#define LOOP_CYCLES_68040 (3)
#define LOOP_CYCLES_68060 (1)
if (CPU_IS_020) {
cpu = "68020";
clockfactor = LOOP_CYCLES_68020;
} else if (CPU_IS_030) {
cpu = "68030";
clockfactor = LOOP_CYCLES_68030;
} else if (CPU_IS_040) {
cpu = "68040";
clockfactor = LOOP_CYCLES_68040;
} else if (CPU_IS_060) {
cpu = "68060";
clockfactor = LOOP_CYCLES_68060;
} else {
cpu = "680x0";
clockfactor = 0;
}
#ifdef CONFIG_M68KFPU_EMU_ONLY
fpu = "none(soft float)";
#else
if (m68k_fputype & FPU_68881)
fpu = "68881";
else if (m68k_fputype & FPU_68882)
fpu = "68882";
else if (m68k_fputype & FPU_68040)
fpu = "68040";
else if (m68k_fputype & FPU_68060)
fpu = "68060";
else if (m68k_fputype & FPU_SUNFPA)
fpu = "Sun FPA";
else
fpu = "none";
#endif
if (m68k_mmutype & MMU_68851)
mmu = "68851";
else if (m68k_mmutype & MMU_68030)
mmu = "68030";
else if (m68k_mmutype & MMU_68040)
mmu = "68040";
else if (m68k_mmutype & MMU_68060)
mmu = "68060";
else if (m68k_mmutype & MMU_SUN3)
mmu = "Sun-3";
else if (m68k_mmutype & MMU_APOLLO)
mmu = "Apollo";
else
mmu = "unknown";
clockfreq = loops_per_jiffy * HZ * clockfactor;
seq_printf(m, "CPU:\t\t%s\n"
"MMU:\t\t%s\n"
"FPU:\t\t%s\n"
"Clocking:\t%lu.%1luMHz\n"
"BogoMips:\t%lu.%02lu\n"
"Calibration:\t%lu loops\n",
cpu, mmu, fpu,
clockfreq/1000000,(clockfreq/100000)%10,
loops_per_jiffy/(500000/HZ),(loops_per_jiffy/(5000/HZ))%100,
loops_per_jiffy);
return 0;
}
static void *c_start(struct seq_file *m, loff_t *pos)
{
return *pos < 1 ? (void *)1 : NULL;
}
static void *c_next(struct seq_file *m, void *v, loff_t *pos)
{
++*pos;
return NULL;
}
static void c_stop(struct seq_file *m, void *v)
{
}
static int hardware_proc_show(struct seq_file *m, void *v)
{
char model[80];
unsigned long mem;
int i;
if (mach_get_model)
mach_get_model(model);
else
strcpy(model, "Unknown m68k");
seq_printf(m, "Model:\t\t%s\n", model);
for (mem = 0, i = 0; i < m68k_num_memory; i++)
mem += m68k_memory[i].size;
seq_printf(m, "System Memory:\t%ldK\n", mem >> 10);
if (mach_get_hardware_list)
mach_get_hardware_list(m);
return 0;
}
static int hardware_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, hardware_proc_show, NULL);
}
static int __init proc_hardware_init(void)
{
proc_create("hardware", 0, NULL, &hardware_proc_fops);
return 0;
}
void check_bugs(void)
{
#ifndef CONFIG_M68KFPU_EMU
if (m68k_fputype == 0) {
printk(KERN_EMERG "*** YOU DO NOT HAVE A FLOATING POINT UNIT, "
"WHICH IS REQUIRED BY LINUX/M68K ***\n");
printk(KERN_EMERG "Upgrade your hardware or join the FPU "
"emulation project\n");
panic("no FPU");
}
#endif
}
static int __init adb_probe_sync_enable (char *str) {
extern int __adb_probe_sync;
__adb_probe_sync = 1;
return 1;
}
