void __init *s3c_set_platdata(void *pd, size_t pdsize,
struct platform_device *pdev)
{
void *npd;
if (!pd) {
printk(KERN_ERR "%s: no platform data supplied\n", pdev->name);
return NULL;
}
npd = kmemdup(pd, pdsize, GFP_KERNEL);
if (!npd) {
printk(KERN_ERR "%s: cannot clone platform data\n", pdev->name);
return NULL;
}
pdev->dev.platform_data = npd;
return npd;
}
