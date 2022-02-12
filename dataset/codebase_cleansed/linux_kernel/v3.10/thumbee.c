static inline unsigned long teehbr_read(void)
{
unsigned long v;
asm("mrc p14, 6, %0, c1, c0, 0\n" : "=r" (v));
return v;
}
static inline void teehbr_write(unsigned long v)
{
asm("mcr p14, 6, %0, c1, c0, 0\n" : : "r" (v));
}
static int thumbee_notifier(struct notifier_block *self, unsigned long cmd, void *t)
{
struct thread_info *thread = t;
switch (cmd) {
case THREAD_NOTIFY_FLUSH:
thread->thumbee_state = 0;
break;
case THREAD_NOTIFY_SWITCH:
current_thread_info()->thumbee_state = teehbr_read();
teehbr_write(thread->thumbee_state);
break;
}
return NOTIFY_DONE;
}
static int __init thumbee_init(void)
{
unsigned long pfr0;
unsigned int cpu_arch = cpu_architecture();
if (cpu_arch < CPU_ARCH_ARMv7)
return 0;
pfr0 = read_cpuid_ext(CPUID_EXT_PFR0);
if ((pfr0 & 0x0000f000) != 0x00001000)
return 0;
printk(KERN_INFO "ThumbEE CPU extension supported.\n");
elf_hwcap |= HWCAP_THUMBEE;
thread_register_notifier(&thumbee_notifier_block);
return 0;
}
