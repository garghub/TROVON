static int __init hisi_acpu_cpufreq_driver_init(void)
{
struct platform_device *pdev;
if (!of_machine_is_compatible("hisilicon,hi6220"))
return -ENODEV;
pdev = platform_device_register_simple("cpufreq-dt", -1, NULL, 0);
return PTR_ERR_OR_ZERO(pdev);
}
