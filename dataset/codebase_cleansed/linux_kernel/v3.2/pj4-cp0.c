static int iwmmxt_do(struct notifier_block *self, unsigned long cmd, void *t)
{
struct thread_info *thread = t;
switch (cmd) {
case THREAD_NOTIFY_FLUSH:
case THREAD_NOTIFY_EXIT:
iwmmxt_task_release(thread);
break;
case THREAD_NOTIFY_SWITCH:
iwmmxt_task_switch(thread);
break;
}
return NOTIFY_DONE;
}
static u32 __init pj4_cp_access_read(void)
{
u32 value;
__asm__ __volatile__ (
"mrc p15, 0, %0, c1, c0, 2\n\t"
: "=r" (value));
return value;
}
static void __init pj4_cp_access_write(u32 value)
{
u32 temp;
__asm__ __volatile__ (
"mcr p15, 0, %1, c1, c0, 2\n\t"
"mrc p15, 0, %0, c1, c0, 2\n\t"
"mov %0, %0\n\t"
"sub pc, pc, #4\n\t"
: "=r" (temp) : "r" (value));
}
static int __init pj4_cp0_init(void)
{
u32 cp_access;
cp_access = pj4_cp_access_read() & ~0xf;
pj4_cp_access_write(cp_access);
printk(KERN_INFO "PJ4 iWMMXt coprocessor enabled.\n");
elf_hwcap |= HWCAP_IWMMXT;
thread_register_notifier(&iwmmxt_notifier_block);
return 0;
}
