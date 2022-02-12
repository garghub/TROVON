static int sh73a0_enter_suspend(suspend_state_t suspend_state)
{
cpu_do_idle();
return 0;
}
static void sh73a0_suspend_init(void)
{
shmobile_suspend_ops.enter = sh73a0_enter_suspend;
}
static void sh73a0_suspend_init(void) {}
void __init sh73a0_pm_init(void)
{
sh73a0_suspend_init();
}
