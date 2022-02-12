static int s3c2412_cpu_suspend(unsigned long arg)
{
unsigned long tmp;
tmp = __raw_readl(S3C2412_PWRCFG);
tmp |= S3C2412_PWRCFG_STANDBYWFI_SLEEP;
__raw_writel(tmp, S3C2412_PWRCFG);
s3c2412_sleep_enter();
pr_info("Failed to suspend the system\n");
return 1;
}
static void s3c2412_pm_prepare(void)
{
samsung_sync_wakemask(S3C2412_PWRCFG,
wake_irqs, ARRAY_SIZE(wake_irqs));
}
static int s3c2412_pm_add(struct device *dev, struct subsys_interface *sif)
{
pm_cpu_prep = s3c2412_pm_prepare;
pm_cpu_sleep = s3c2412_cpu_suspend;
return 0;
}
static __init int s3c2412_pm_init(void)
{
return subsys_interface_register(&s3c2412_pm_interface);
}
static int s3c2412_pm_suspend(void)
{
s3c_pm_do_save(s3c2412_sleep, ARRAY_SIZE(s3c2412_sleep));
return 0;
}
static void s3c2412_pm_resume(void)
{
unsigned long tmp;
tmp = __raw_readl(S3C2412_PWRCFG);
tmp &= ~S3C2412_PWRCFG_STANDBYWFI_MASK;
tmp |= S3C2412_PWRCFG_STANDBYWFI_IDLE;
__raw_writel(tmp, S3C2412_PWRCFG);
s3c_pm_do_restore(s3c2412_sleep, ARRAY_SIZE(s3c2412_sleep));
}
