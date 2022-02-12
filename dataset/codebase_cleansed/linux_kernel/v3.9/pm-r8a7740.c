static int r8a7740_pd_a4s_suspend(void)
{
return -EBUSY;
}
static int r8a7740_pd_a3sp_suspend(void)
{
return console_suspend_enabled ? 0 : -EBUSY;
}
void __init r8a7740_init_pm_domains(void)
{
rmobile_init_domains(r8a7740_pm_domains, ARRAY_SIZE(r8a7740_pm_domains));
pm_genpd_add_subdomain_names("A4S", "A3SP");
}
static int r8a7740_enter_suspend(suspend_state_t suspend_state)
{
cpu_do_idle();
return 0;
}
static void r8a7740_suspend_init(void)
{
shmobile_suspend_ops.enter = r8a7740_enter_suspend;
}
static void r8a7740_suspend_init(void) {}
void __init r8a7740_pm_init(void)
{
r8a7740_suspend_init();
}
