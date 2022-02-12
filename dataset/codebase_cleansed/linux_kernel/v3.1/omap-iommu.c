static int __init omap_iommu_init(void)
{
int i, err;
struct resource res[] = {
{ .flags = IORESOURCE_MEM },
{ .flags = IORESOURCE_IRQ },
};
if (cpu_is_omap34xx()) {
devices = omap3_devices;
omap_iommu_pdev = omap3_iommu_pdev;
num_iommu_devices = NR_OMAP3_IOMMU_DEVICES;
} else if (cpu_is_omap44xx()) {
devices = omap4_devices;
omap_iommu_pdev = omap4_iommu_pdev;
num_iommu_devices = NR_OMAP4_IOMMU_DEVICES;
} else
return -ENODEV;
for (i = 0; i < num_iommu_devices; i++) {
struct platform_device *pdev;
const struct iommu_device *d = &devices[i];
pdev = platform_device_alloc("omap-iommu", i);
if (!pdev) {
err = -ENOMEM;
goto err_out;
}
res[0].start = d->base;
res[0].end = d->base + MMU_REG_SIZE - 1;
res[1].start = res[1].end = d->irq;
err = platform_device_add_resources(pdev, res,
ARRAY_SIZE(res));
if (err)
goto err_out;
err = platform_device_add_data(pdev, &d->pdata,
sizeof(d->pdata));
if (err)
goto err_out;
err = platform_device_add(pdev);
if (err)
goto err_out;
omap_iommu_pdev[i] = pdev;
}
return 0;
err_out:
while (i--)
platform_device_put(omap_iommu_pdev[i]);
return err;
}
static void __exit omap_iommu_exit(void)
{
int i;
for (i = 0; i < num_iommu_devices; i++)
platform_device_unregister(omap_iommu_pdev[i]);
}
