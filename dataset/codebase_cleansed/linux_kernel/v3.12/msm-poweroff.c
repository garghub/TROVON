static void do_msm_restart(enum reboot_mode reboot_mode, const char *cmd)
{
writel(0, msm_ps_hold);
mdelay(10000);
}
static void do_msm_poweroff(void)
{
do_msm_restart(REBOOT_HARD, NULL);
}
static int msm_restart_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *mem;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
msm_ps_hold = devm_ioremap_resource(dev, mem);
if (IS_ERR(msm_ps_hold))
return PTR_ERR(msm_ps_hold);
pm_power_off = do_msm_poweroff;
arm_pm_restart = do_msm_restart;
return 0;
}
static int __init msm_restart_init(void)
{
return platform_driver_register(&msm_restart_driver);
}
