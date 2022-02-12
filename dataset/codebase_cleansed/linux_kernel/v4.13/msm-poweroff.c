static int do_msm_restart(struct notifier_block *nb, unsigned long action,
void *data)
{
writel(0, msm_ps_hold);
mdelay(10000);
return NOTIFY_DONE;
}
static void do_msm_poweroff(void)
{
do_msm_restart(&restart_nb, 0, NULL);
}
static int msm_restart_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *mem;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
msm_ps_hold = devm_ioremap_resource(dev, mem);
if (IS_ERR(msm_ps_hold))
return PTR_ERR(msm_ps_hold);
register_restart_handler(&restart_nb);
pm_power_off = do_msm_poweroff;
return 0;
}
static int __init msm_restart_init(void)
{
return platform_driver_register(&msm_restart_driver);
}
