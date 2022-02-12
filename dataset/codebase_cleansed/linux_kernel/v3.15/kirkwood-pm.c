static void kirkwood_low_power(void)
{
u32 mem_pm_ctrl;
mem_pm_ctrl = readl(memory_pm_ctrl);
writel_relaxed(~0, memory_pm_ctrl);
writel_relaxed(0x7, ddr_operation_base);
cpu_do_idle();
writel_relaxed(mem_pm_ctrl, memory_pm_ctrl);
}
static int kirkwood_suspend_enter(suspend_state_t state)
{
switch (state) {
case PM_SUSPEND_STANDBY:
kirkwood_low_power();
break;
default:
return -EINVAL;
}
return 0;
}
static int kirkwood_pm_valid_standby(suspend_state_t state)
{
return state == PM_SUSPEND_STANDBY;
}
int __init kirkwood_pm_init(void)
{
ddr_operation_base = ioremap(DDR_OPERATION_BASE, 4);
memory_pm_ctrl = ioremap(MEMORY_PM_CTRL_PHYS, 4);
suspend_set_ops(&kirkwood_suspend_ops);
return 0;
}
