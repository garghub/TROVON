static int r8a7740_pd_a4s_suspend(void)
{
return -EBUSY;
}
static int r8a7740_pd_a3sp_suspend(void)
{
return console_suspend_enabled ? 0 : -EBUSY;
}
