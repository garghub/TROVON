static void s3c2410_pm_prepare(void)
{
__raw_writel(virt_to_phys(s3c_cpu_resume), S3C2410_GSTATUS3);
S3C_PMDBG("GSTATUS3 0x%08x\n", __raw_readl(S3C2410_GSTATUS3));
S3C_PMDBG("GSTATUS4 0x%08x\n", __raw_readl(S3C2410_GSTATUS4));
if (machine_is_h1940()) {
void *base = phys_to_virt(H1940_SUSPEND_CHECK);
unsigned long ptr;
unsigned long calc = 0;
for (ptr = 0; ptr < 0x40000; ptr += 0x400)
calc += __raw_readl(base+ptr);
__raw_writel(calc, phys_to_virt(H1940_SUSPEND_CHECKSUM));
}
if (machine_is_rx3715() || machine_is_rx1950()) {
void *base = phys_to_virt(H1940_SUSPEND_CHECK);
unsigned long ptr;
unsigned long calc = 0;
for (ptr = 0; ptr < 0x40000; ptr += 0x4)
calc += __raw_readl(base+ptr);
__raw_writel(calc, phys_to_virt(H1940_SUSPEND_CHECKSUM));
}
if ( machine_is_aml_m5900() )
s3c2410_gpio_setpin(S3C2410_GPF(2), 1);
if (machine_is_rx1950()) {
s3c_gpio_cfgpin(S3C2410_GPG(13), S3C2410_GPIO_INPUT);
s3c_gpio_cfgpin(S3C2410_GPG(14), S3C2410_GPIO_INPUT);
s3c_gpio_cfgpin(S3C2410_GPG(15), S3C2410_GPIO_INPUT);
}
}
static void s3c2410_pm_resume(void)
{
unsigned long tmp;
tmp = __raw_readl(S3C2410_GSTATUS2);
tmp &= S3C2410_GSTATUS2_OFFRESET;
__raw_writel(tmp, S3C2410_GSTATUS2);
if ( machine_is_aml_m5900() )
s3c2410_gpio_setpin(S3C2410_GPF(2), 0);
}
static int s3c2410_pm_add(struct device *dev, struct subsys_interface *sif)
{
pm_cpu_prep = s3c2410_pm_prepare;
pm_cpu_sleep = s3c2410_cpu_suspend;
return 0;
}
static int __init s3c2410_pm_drvinit(void)
{
return subsys_interface_register(&s3c2410_pm_interface);
}
static int __init s3c2410a_pm_drvinit(void)
{
return subsys_interface_register(&s3c2410a_pm_interface);
}
static int __init s3c2440_pm_drvinit(void)
{
return subsys_interface_register(&s3c2440_pm_interface);
}
static int __init s3c2442_pm_drvinit(void)
{
return subsys_interface_register(&s3c2442_pm_interface);
}
