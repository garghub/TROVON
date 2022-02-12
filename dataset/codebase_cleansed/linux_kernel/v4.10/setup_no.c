void __init setup_arch(char **cmdline_p)
{
int bootmap_size;
memory_start = PAGE_ALIGN(_ramstart);
memory_end = _ramend;
init_mm.start_code = (unsigned long) &_stext;
init_mm.end_code = (unsigned long) &_etext;
init_mm.end_data = (unsigned long) &_edata;
init_mm.brk = (unsigned long) 0;
config_BSP(&command_line[0], sizeof(command_line));
#if defined(CONFIG_BOOTPARAM)
strncpy(&command_line[0], CONFIG_BOOTPARAM_STRING, sizeof(command_line));
command_line[sizeof(command_line) - 1] = 0;
#endif
process_uboot_commandline(&command_line[0], sizeof(command_line));
pr_info("uClinux with CPU " CPU_NAME "\n");
#ifdef CONFIG_UCDIMM
pr_info("uCdimm by Lineo, Inc. <www.lineo.com>\n");
#endif
#ifdef CONFIG_M68VZ328
pr_info("M68VZ328 support by Evan Stawnyczy <e@lineo.ca>\n");
#endif
#ifdef CONFIG_COLDFIRE
pr_info("COLDFIRE port done by Greg Ungerer, gerg@snapgear.com\n");
#ifdef CONFIG_M5307
pr_info("Modified for M5307 by Dave Miller, dmiller@intellistor.com\n");
#endif
#ifdef CONFIG_ELITE
pr_info("Modified for M5206eLITE by Rob Scott, rscott@mtrob.fdns.net\n");
#endif
#endif
pr_info("Flat model support (C) 1998,1999 Kenneth Albanowski, D. Jeff Dionne\n");
#if defined( CONFIG_PILOT ) && defined( CONFIG_M68328 )
pr_info("TRG SuperPilot FLASH card support <info@trgnet.com>\n");
#endif
#if defined( CONFIG_PILOT ) && defined( CONFIG_M68EZ328 )
pr_info("PalmV support by Lineo Inc. <jeff@uclinux.com>\n");
#endif
#ifdef CONFIG_DRAGEN2
pr_info("DragonEngine II board support by Georges Menie\n");
#endif
#ifdef CONFIG_M5235EVB
pr_info("Motorola M5235EVB support (C)2005 Syn-tech Systems, Inc. (Jate Sujjavanich)\n");
#endif
pr_debug("KERNEL -> TEXT=0x%p-0x%p DATA=0x%p-0x%p BSS=0x%p-0x%p\n",
_stext, _etext, _sdata, _edata, __bss_start, __bss_stop);
pr_debug("MEMORY -> ROMFS=0x%p-0x%06lx MEM=0x%06lx-0x%06lx\n ",
__bss_stop, memory_start, memory_start, memory_end);
*cmdline_p = &command_line[0];
memcpy(boot_command_line, command_line, COMMAND_LINE_SIZE);
boot_command_line[COMMAND_LINE_SIZE-1] = 0;
#if defined(CONFIG_FRAMEBUFFER_CONSOLE) && defined(CONFIG_DUMMY_CONSOLE)
conswitchp = &dummy_con;
#endif
min_low_pfn = PFN_DOWN(memory_start);
max_pfn = max_low_pfn = PFN_DOWN(memory_end);
bootmap_size = init_bootmem_node(
NODE_DATA(0),
min_low_pfn,
PFN_DOWN(PAGE_OFFSET),
max_pfn);
free_bootmem(memory_start, memory_end - memory_start);
reserve_bootmem(memory_start, bootmap_size, BOOTMEM_DEFAULT);
#if defined(CONFIG_UBOOT) && defined(CONFIG_BLK_DEV_INITRD)
if ((initrd_start > 0) && (initrd_start < initrd_end) &&
(initrd_end < memory_end))
reserve_bootmem(initrd_start, initrd_end - initrd_start,
BOOTMEM_DEFAULT);
#endif
paging_init();
}
static int show_cpuinfo(struct seq_file *m, void *v)
{
char *cpu, *mmu, *fpu;
u_long clockfreq;
cpu = CPU_NAME;
mmu = "none";
fpu = "none";
clockfreq = (loops_per_jiffy * HZ) * CPU_INSTR_PER_JIFFY;
seq_printf(m, "CPU:\t\t%s\n"
"MMU:\t\t%s\n"
"FPU:\t\t%s\n"
"Clocking:\t%lu.%1luMHz\n"
"BogoMips:\t%lu.%02lu\n"
"Calibration:\t%lu loops\n",
cpu, mmu, fpu,
clockfreq / 1000000,
(clockfreq / 100000) % 10,
(loops_per_jiffy * HZ) / 500000,
((loops_per_jiffy * HZ) / 5000) % 100,
(loops_per_jiffy * HZ));
return 0;
}
static void *c_start(struct seq_file *m, loff_t *pos)
{
return *pos < NR_CPUS ? ((void *) 0x12345678) : NULL;
}
static void *c_next(struct seq_file *m, void *v, loff_t *pos)
{
++*pos;
return c_start(m, pos);
}
static void c_stop(struct seq_file *m, void *v)
{
}
