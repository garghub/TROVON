static int mx5_suspend_prepare(void)
{
return clk_enable(gpc_dvfs_clk);
}
static int mx5_suspend_enter(suspend_state_t state)
{
switch (state) {
case PM_SUSPEND_MEM:
mx5_cpu_lp_set(STOP_POWER_OFF);
break;
case PM_SUSPEND_STANDBY:
mx5_cpu_lp_set(WAIT_UNCLOCKED_POWER_OFF);
break;
default:
return -EINVAL;
}
if (state == PM_SUSPEND_MEM) {
local_flush_tlb_all();
flush_cache_all();
__raw_writel(0, MXC_SRPG_EMPGC0_SRPGCR);
__raw_writel(0, MXC_SRPG_EMPGC1_SRPGCR);
}
cpu_do_idle();
return 0;
}
static void mx5_suspend_finish(void)
{
clk_disable(gpc_dvfs_clk);
}
static int mx5_pm_valid(suspend_state_t state)
{
return (state > PM_SUSPEND_ON && state <= PM_SUSPEND_MAX);
}
static int __init mx5_pm_init(void)
{
if (gpc_dvfs_clk == NULL)
gpc_dvfs_clk = clk_get(NULL, "gpc_dvfs");
if (!IS_ERR(gpc_dvfs_clk)) {
if (cpu_is_mx51())
suspend_set_ops(&mx5_suspend_ops);
} else
return -EPERM;
return 0;
}
