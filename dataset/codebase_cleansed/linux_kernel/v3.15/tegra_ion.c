static int tegra_ion_probe(struct platform_device *pdev)
{
struct ion_platform_data *pdata = pdev->dev.platform_data;
int err;
int i;
num_heaps = pdata->nr;
heaps = devm_kzalloc(&pdev->dev,
sizeof(struct ion_heap *) * pdata->nr,
GFP_KERNEL);
idev = ion_device_create(NULL);
if (IS_ERR_OR_NULL(idev))
return PTR_ERR(idev);
for (i = 0; i < num_heaps; i++) {
struct ion_platform_heap *heap_data = &pdata->heaps[i];
heaps[i] = ion_heap_create(heap_data);
if (IS_ERR_OR_NULL(heaps[i])) {
err = PTR_ERR(heaps[i]);
goto err;
}
ion_device_add_heap(idev, heaps[i]);
}
platform_set_drvdata(pdev, idev);
return 0;
err:
for (i = 0; i < num_heaps; i++) {
if (heaps[i])
ion_heap_destroy(heaps[i]);
}
return err;
}
static int tegra_ion_remove(struct platform_device *pdev)
{
struct ion_device *idev = platform_get_drvdata(pdev);
int i;
ion_device_destroy(idev);
for (i = 0; i < num_heaps; i++)
ion_heap_destroy(heaps[i]);
return 0;
}
