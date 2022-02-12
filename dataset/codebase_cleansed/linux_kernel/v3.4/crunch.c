void crunch_task_release(struct thread_info *thread)
{
local_irq_disable();
if (crunch_owner == &thread->crunchstate)
crunch_owner = NULL;
local_irq_enable();
}
static int crunch_enabled(u32 devcfg)
{
return !!(devcfg & EP93XX_SYSCON_DEVCFG_CPENA);
}
static int crunch_do(struct notifier_block *self, unsigned long cmd, void *t)
{
struct thread_info *thread = (struct thread_info *)t;
struct crunch_state *crunch_state;
u32 devcfg;
crunch_state = &thread->crunchstate;
switch (cmd) {
case THREAD_NOTIFY_FLUSH:
memset(crunch_state, 0, sizeof(*crunch_state));
case THREAD_NOTIFY_EXIT:
crunch_task_release(thread);
break;
case THREAD_NOTIFY_SWITCH:
devcfg = __raw_readl(EP93XX_SYSCON_DEVCFG);
if (crunch_enabled(devcfg) || crunch_owner == crunch_state) {
devcfg ^= EP93XX_SYSCON_DEVCFG_CPENA;
__raw_writel(0xaa, EP93XX_SYSCON_SWLOCK);
__raw_writel(devcfg, EP93XX_SYSCON_DEVCFG);
}
break;
}
return NOTIFY_DONE;
}
static int __init crunch_init(void)
{
thread_register_notifier(&crunch_notifier_block);
elf_hwcap |= HWCAP_CRUNCH;
return 0;
}
