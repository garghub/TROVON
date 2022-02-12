u16 pwmss_submodule_state_change(struct device *dev, int set)
{
struct pwmss_info *info = dev_get_drvdata(dev);
u16 val;
mutex_lock(&info->pwmss_lock);
val = readw(info->mmio_base + PWMSS_CLKCONFIG);
val |= set;
writew(val , info->mmio_base + PWMSS_CLKCONFIG);
mutex_unlock(&info->pwmss_lock);
return readw(info->mmio_base + PWMSS_CLKSTATUS);
}
static int pwmss_probe(struct platform_device *pdev)
{
int ret;
struct resource *r;
struct pwmss_info *info;
struct device_node *node = pdev->dev.of_node;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
mutex_init(&info->pwmss_lock);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info->mmio_base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(info->mmio_base))
return PTR_ERR(info->mmio_base);
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
platform_set_drvdata(pdev, info);
ret = of_platform_populate(node, NULL, NULL, &pdev->dev);
if (ret)
dev_err(&pdev->dev, "no child node found\n");
return ret;
}
static int pwmss_remove(struct platform_device *pdev)
{
struct pwmss_info *info = platform_get_drvdata(pdev);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
mutex_destroy(&info->pwmss_lock);
return 0;
}
static int pwmss_suspend(struct device *dev)
{
struct pwmss_info *info = dev_get_drvdata(dev);
info->pwmss_clkconfig = readw(info->mmio_base + PWMSS_CLKCONFIG);
pm_runtime_put_sync(dev);
return 0;
}
static int pwmss_resume(struct device *dev)
{
struct pwmss_info *info = dev_get_drvdata(dev);
pm_runtime_get_sync(dev);
writew(info->pwmss_clkconfig, info->mmio_base + PWMSS_CLKCONFIG);
return 0;
}
