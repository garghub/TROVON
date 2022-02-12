int __init msm_add_sdcc(unsigned int controller,
struct msm_mmc_platform_data *plat,
unsigned int stat_irq, unsigned long stat_irq_flags)
{
struct platform_device *pdev;
struct resource *res;
if (controller < 1 || controller > 4)
return -EINVAL;
pdev = msm_sdcc_devices[controller-1];
pdev->dev.platform_data = plat;
res = platform_get_resource_byname(pdev, IORESOURCE_IRQ, "status_irq");
if (!res)
return -EINVAL;
else if (stat_irq) {
res->start = res->end = stat_irq;
res->flags &= ~IORESOURCE_DISABLED;
res->flags |= stat_irq_flags;
}
return platform_device_register(pdev);
}
