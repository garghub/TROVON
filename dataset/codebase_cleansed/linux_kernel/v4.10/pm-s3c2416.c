static int s3c2416_cpu_suspend(unsigned long arg)
{
__raw_writel(S3C2443_PWRCFG_SLEEP, S3C2443_PWRCFG);
__raw_writel(0x2BED, S3C2443_PWRMODE);
s3c2412_sleep_enter();
pr_info("Failed to suspend the system\n");
return 1;
}
static void s3c2416_pm_prepare(void)
{
__raw_writel(0x2BED, S3C2412_INFORM0);
__raw_writel(virt_to_phys(s3c_cpu_resume), S3C2412_INFORM1);
}
static int s3c2416_pm_add(struct device *dev, struct subsys_interface *sif)
{
pm_cpu_prep = s3c2416_pm_prepare;
pm_cpu_sleep = s3c2416_cpu_suspend;
return 0;
}
static __init int s3c2416_pm_init(void)
{
return subsys_interface_register(&s3c2416_pm_interface);
}
static void s3c2416_pm_resume(void)
{
__raw_writel(0x0, S3C2443_PWRMODE);
__raw_writel(0x0, S3C2412_INFORM0);
__raw_writel(0x0, S3C2412_INFORM1);
}
