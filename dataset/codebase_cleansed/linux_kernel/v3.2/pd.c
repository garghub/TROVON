static int samsung_pd_probe(struct platform_device *pdev)
{
struct samsung_pd_info *pdata = pdev->dev.platform_data;
struct device *dev = &pdev->dev;
if (!pdata) {
dev_err(dev, "no device data specified\n");
return -ENOENT;
}
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
dev_info(dev, "power domain registered\n");
return 0;
}
static int __devexit samsung_pd_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
pm_runtime_disable(dev);
return 0;
}
static int samsung_pd_runtime_suspend(struct device *dev)
{
struct samsung_pd_info *pdata = dev->platform_data;
int ret = 0;
if (pdata->disable)
ret = pdata->disable(dev);
dev_dbg(dev, "suspended\n");
return ret;
}
static int samsung_pd_runtime_resume(struct device *dev)
{
struct samsung_pd_info *pdata = dev->platform_data;
int ret = 0;
if (pdata->enable)
ret = pdata->enable(dev);
dev_dbg(dev, "resumed\n");
return ret;
}
static int __init samsung_pd_init(void)
{
int ret;
ret = platform_driver_register(&samsung_pd_driver);
if (ret)
printk(KERN_ERR "%s: failed to add PD driver\n", __func__);
return ret;
}
