static int r8a7740_pd_a3sm_suspend(void)
{
return -EBUSY;
}
static int r8a7740_pd_a3sp_suspend(void)
{
return console_suspend_enabled ? 0 : -EBUSY;
}
static int r8a7740_pd_d4_suspend(void)
{
return -EBUSY;
}
void __init r8a7740_init_pm_domains(void)
{
rmobile_init_domains(r8a7740_pm_domains, ARRAY_SIZE(r8a7740_pm_domains));
pm_genpd_add_subdomain_names("A4R", "A3RV");
pm_genpd_add_subdomain_names("A4S", "A3SP");
pm_genpd_add_subdomain_names("A4S", "A3SM");
pm_genpd_add_subdomain_names("A4S", "A3SG");
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
