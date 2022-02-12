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
