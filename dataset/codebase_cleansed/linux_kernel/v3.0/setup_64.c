static void
prom_console_write(struct console *con, const char *s, unsigned n)
{
prom_write(s, n);
}
static void __init process_switch(char c)
{
switch (c) {
case 'd':
case 's':
break;
case 'h':
prom_printf("boot_flags_init: Halt!\n");
prom_halt();
break;
case 'p':
break;
case 'P':
if (tlb_type != cheetah) {
printk("BOOT: Ignoring P-Cache force option.\n");
break;
}
cheetah_pcache_forced_on = 1;
add_taint(TAINT_MACHINE_CHECK);
cheetah_enable_pcache();
break;
default:
printk("Unknown boot switch (-%c)\n", c);
break;
}
}
static void __init boot_flags_init(char *commands)
{
while (*commands) {
while (*commands && *commands == ' ')
commands++;
if (*commands == '\0')
break;
if (*commands == '-') {
commands++;
while (*commands && *commands != ' ')
process_switch(*commands++);
continue;
}
if (!strncmp(commands, "mem=", 4)) {
cmdline_memory_size = simple_strtoul(commands + 4,
&commands, 0);
if (*commands == 'K' || *commands == 'k') {
cmdline_memory_size <<= 10;
commands++;
} else if (*commands=='M' || *commands=='m') {
cmdline_memory_size <<= 20;
commands++;
}
}
while (*commands && *commands != ' ')
commands++;
}
}
void __init per_cpu_patch(void)
{
struct cpuid_patch_entry *p;
unsigned long ver;
int is_jbus;
if (tlb_type == spitfire && !this_is_starfire)
return;
is_jbus = 0;
if (tlb_type != hypervisor) {
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
is_jbus = ((ver >> 32UL) == __JALAPENO_ID ||
(ver >> 32UL) == __SERRANO_ID);
}
p = &__cpuid_patch;
while (p < &__cpuid_patch_end) {
unsigned long addr = p->addr;
unsigned int *insns;
switch (tlb_type) {
case spitfire:
insns = &p->starfire[0];
break;
case cheetah:
case cheetah_plus:
if (is_jbus)
insns = &p->cheetah_jbus[0];
else
insns = &p->cheetah_safari[0];
break;
case hypervisor:
insns = &p->sun4v[0];
break;
default:
prom_printf("Unknown cpu type, halting.\n");
prom_halt();
}
*(unsigned int *) (addr + 0) = insns[0];
wmb();
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
*(unsigned int *) (addr + 4) = insns[1];
wmb();
__asm__ __volatile__("flush %0" : : "r" (addr + 4));
*(unsigned int *) (addr + 8) = insns[2];
wmb();
__asm__ __volatile__("flush %0" : : "r" (addr + 8));
*(unsigned int *) (addr + 12) = insns[3];
wmb();
__asm__ __volatile__("flush %0" : : "r" (addr + 12));
p++;
}
}
void __init sun4v_patch(void)
{
extern void sun4v_hvapi_init(void);
struct sun4v_1insn_patch_entry *p1;
struct sun4v_2insn_patch_entry *p2;
if (tlb_type != hypervisor)
return;
p1 = &__sun4v_1insn_patch;
while (p1 < &__sun4v_1insn_patch_end) {
unsigned long addr = p1->addr;
*(unsigned int *) (addr + 0) = p1->insn;
wmb();
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
p1++;
}
p2 = &__sun4v_2insn_patch;
while (p2 < &__sun4v_2insn_patch_end) {
unsigned long addr = p2->addr;
*(unsigned int *) (addr + 0) = p2->insns[0];
wmb();
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
*(unsigned int *) (addr + 4) = p2->insns[1];
wmb();
__asm__ __volatile__("flush %0" : : "r" (addr + 4));
p2++;
}
sun4v_hvapi_init();
}
void __init boot_cpu_id_too_large(int cpu)
{
prom_printf("Serious problem, boot cpu id (%d) >= NR_CPUS (%d)\n",
cpu, NR_CPUS);
prom_halt();
}
void __init setup_arch(char **cmdline_p)
{
*cmdline_p = prom_getbootargs();
strcpy(boot_command_line, *cmdline_p);
parse_early_param();
boot_flags_init(*cmdline_p);
#ifdef CONFIG_EARLYFB
if (btext_find_display())
#endif
register_console(&prom_early_console);
if (tlb_type == hypervisor)
printk("ARCH: SUN4V\n");
else
printk("ARCH: SUN4U\n");
#ifdef CONFIG_DUMMY_CONSOLE
conswitchp = &dummy_con;
#endif
idprom_init();
if (!root_flags)
root_mountflags &= ~MS_RDONLY;
ROOT_DEV = old_decode_dev(root_dev);
#ifdef CONFIG_BLK_DEV_RAM
rd_image_start = ram_flags & RAMDISK_IMAGE_START_MASK;
rd_prompt = ((ram_flags & RAMDISK_PROMPT_FLAG) != 0);
rd_doload = ((ram_flags & RAMDISK_LOAD_FLAG) != 0);
#endif
task_thread_info(&init_task)->kregs = &fake_swapper_regs;
#ifdef CONFIG_IP_PNP
if (!ic_set_manually) {
phandle chosen = prom_finddevice("/chosen");
u32 cl, sv, gw;
cl = prom_getintdefault (chosen, "client-ip", 0);
sv = prom_getintdefault (chosen, "server-ip", 0);
gw = prom_getintdefault (chosen, "gateway-ip", 0);
if (cl && sv) {
ic_myaddr = cl;
ic_servaddr = sv;
if (gw)
ic_gateway = gw;
#if defined(CONFIG_IP_PNP_BOOTP) || defined(CONFIG_IP_PNP_RARP)
ic_proto_enabled = 0;
#endif
}
}
#endif
init_cur_cpu_trap(current_thread_info());
paging_init();
}
void sun_do_break(void)
{
if (!stop_a_enabled)
return;
prom_printf("\n");
flush_user_windows();
prom_cmdline();
}
