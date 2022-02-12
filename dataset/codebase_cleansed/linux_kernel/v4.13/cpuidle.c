static int s3c64xx_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
unsigned long tmp;
tmp = __raw_readl(S3C64XX_PWR_CFG);
tmp &= ~S3C64XX_PWRCFG_CFG_WFI_MASK;
tmp |= S3C64XX_PWRCFG_CFG_WFI_IDLE;
__raw_writel(tmp, S3C64XX_PWR_CFG);
cpu_do_idle();
return index;
}
static int __init s3c64xx_init_cpuidle(void)
{
if (soc_is_s3c64xx())
return cpuidle_register(&s3c64xx_cpuidle_driver, NULL);
return 0;
}
