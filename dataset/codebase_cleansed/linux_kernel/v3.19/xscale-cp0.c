static inline void dsp_save_state(u32 *state)
{
__asm__ __volatile__ (
"mrrc p0, 0, %0, %1, c0\n"
: "=r" (state[0]), "=r" (state[1]));
}
static inline void dsp_load_state(u32 *state)
{
__asm__ __volatile__ (
"mcrr p0, 0, %0, %1, c0\n"
: : "r" (state[0]), "r" (state[1]));
}
static int dsp_do(struct notifier_block *self, unsigned long cmd, void *t)
{
struct thread_info *thread = t;
switch (cmd) {
case THREAD_NOTIFY_FLUSH:
thread->cpu_context.extra[0] = 0;
thread->cpu_context.extra[1] = 0;
break;
case THREAD_NOTIFY_SWITCH:
dsp_save_state(current_thread_info()->cpu_context.extra);
dsp_load_state(thread->cpu_context.extra);
break;
}
return NOTIFY_DONE;
}
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
static u32 __init xscale_cp_access_read(void)
{
u32 value;
__asm__ __volatile__ (
"mrc p15, 0, %0, c15, c1, 0\n\t"
: "=r" (value));
return value;
}
static void __init xscale_cp_access_write(u32 value)
{
u32 temp;
__asm__ __volatile__ (
"mcr p15, 0, %1, c15, c1, 0\n\t"
"mrc p15, 0, %0, c15, c1, 0\n\t"
"mov %0, %0\n\t"
"sub pc, pc, #4\n\t"
: "=r" (temp) : "r" (value));
}
static int __init cpu_has_iwmmxt(void)
{
u32 lo;
u32 hi;
__asm__ __volatile__ (
"mcrr p0, 0, %2, %3, c0\n"
"mrrc p0, 0, %0, %1, c0\n"
: "=r" (lo), "=r" (hi)
: "r" (0), "r" (0x100));
return !!hi;
}
static int __init xscale_cp0_init(void)
{
u32 cp_access;
cp_access = xscale_cp_access_read() & ~3;
xscale_cp_access_write(cp_access | 1);
if (cpu_has_iwmmxt()) {
#ifndef CONFIG_IWMMXT
pr_warn("CAUTION: XScale iWMMXt coprocessor detected, but kernel support is missing.\n");
#else
pr_info("XScale iWMMXt coprocessor detected.\n");
elf_hwcap |= HWCAP_IWMMXT;
thread_register_notifier(&iwmmxt_notifier_block);
#endif
} else {
pr_info("XScale DSP coprocessor detected.\n");
thread_register_notifier(&dsp_notifier_block);
cp_access |= 1;
}
xscale_cp_access_write(cp_access);
return 0;
}
