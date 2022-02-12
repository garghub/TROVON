static void sh7372_enter_core_standby(void)
{
void __iomem *smfram = (void __iomem *)SMFRAM;
__raw_writel(0, APARMBAREA);
__raw_writel(__pa(sh7372_cpu_resume), SBAR);
__raw_writel(0x10, SYSTBCR);
__raw_writel(0, smfram + 0x3c);
sh7372_cpu_suspend();
cpu_init();
if (__raw_readl(smfram + 0x3c)) {
__raw_writel(__raw_readl(smfram + 0x40),
__va(__raw_readl(smfram + 0x3c)));
flush_tlb_all();
set_cr(__raw_readl(smfram + 0x38));
}
__raw_writel(0, SYSTBCR);
__raw_writel(0, SBAR);
}
static void sh7372_cpuidle_setup(struct cpuidle_device *dev)
{
struct cpuidle_state *state;
int i = dev->state_count;
state = &dev->states[i];
snprintf(state->name, CPUIDLE_NAME_LEN, "C2");
strncpy(state->desc, "Core Standby Mode", CPUIDLE_DESC_LEN);
state->exit_latency = 10;
state->target_residency = 20 + 10;
state->power_usage = 1;
state->flags = 0;
state->flags |= CPUIDLE_FLAG_TIME_VALID;
shmobile_cpuidle_modes[i] = sh7372_enter_core_standby;
dev->state_count = i + 1;
}
static void sh7372_cpuidle_init(void)
{
shmobile_cpuidle_setup = sh7372_cpuidle_setup;
}
static void sh7372_cpuidle_init(void) {}
static int sh7372_enter_suspend(suspend_state_t suspend_state)
{
sh7372_enter_core_standby();
return 0;
}
static void sh7372_suspend_init(void)
{
shmobile_suspend_ops.enter = sh7372_enter_suspend;
}
static void sh7372_suspend_init(void) {}
void __init sh7372_pm_init(void)
{
__raw_writel(0x0000a500, DBGREG9);
__raw_writel(0x0000a501, DBGREG9);
__raw_writel(0x00000000, DBGREG1);
sh7372_suspend_init();
sh7372_cpuidle_init();
}
