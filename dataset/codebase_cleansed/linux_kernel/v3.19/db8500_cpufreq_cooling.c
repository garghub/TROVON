static int db8500_cpufreq_cooling_probe(struct platform_device *pdev)
{
struct thermal_cooling_device *cdev;
cdev = cpufreq_cooling_register(cpu_present_mask);
if (IS_ERR(cdev)) {
int ret = PTR_ERR(cdev);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev,
"Failed to register cooling device %d\n",
ret);
return ret;
}
platform_set_drvdata(pdev, cdev);
dev_info(&pdev->dev, "Cooling device registered: %s\n", cdev->type);
return 0;
}
static int db8500_cpufreq_cooling_remove(struct platform_device *pdev)
{
struct thermal_cooling_device *cdev = platform_get_drvdata(pdev);
cpufreq_cooling_unregister(cdev);
return 0;
}
static int db8500_cpufreq_cooling_suspend(struct platform_device *pdev,
pm_message_t state)
{
return -ENOSYS;
}
static int db8500_cpufreq_cooling_resume(struct platform_device *pdev)
{
return -ENOSYS;
}
static int __init db8500_cpufreq_cooling_init(void)
{
return platform_driver_register(&db8500_cpufreq_cooling_driver);
}
static void __exit db8500_cpufreq_cooling_exit(void)
{
platform_driver_unregister(&db8500_cpufreq_cooling_driver);
}
