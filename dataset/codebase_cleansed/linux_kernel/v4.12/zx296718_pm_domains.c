static int zx296718_pd_probe(struct platform_device *pdev)
{
return zx2967_pd_probe(pdev,
zx296718_pm_domains,
ARRAY_SIZE(zx296718_pm_domains));
}
static int __init zx296718_pd_init(void)
{
return platform_driver_register(&zx296718_pd_driver);
}
