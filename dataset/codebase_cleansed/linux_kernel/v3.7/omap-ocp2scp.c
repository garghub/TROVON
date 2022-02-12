static unsigned _count_resources(struct resource *res)
{
int cnt = 0;
while (res->start != res->end) {
cnt++;
res++;
}
return cnt;
}
static int ocp2scp_remove_devices(struct device *dev, void *c)
{
struct platform_device *pdev = to_platform_device(dev);
platform_device_unregister(pdev);
return 0;
}
static int __devinit omap_ocp2scp_probe(struct platform_device *pdev)
{
int ret;
unsigned res_cnt, i;
struct device_node *np = pdev->dev.of_node;
struct platform_device *pdev_child;
struct omap_ocp2scp_platform_data *pdata = pdev->dev.platform_data;
struct omap_ocp2scp_dev *dev;
if (np) {
ret = of_platform_populate(np, NULL, NULL, &pdev->dev);
if (ret) {
dev_err(&pdev->dev,
"failed to add resources for ocp2scp child\n");
goto err0;
}
} else if (pdata) {
for (i = 0, dev = *pdata->devices; i < pdata->dev_cnt; i++,
dev++) {
res_cnt = _count_resources(dev->res);
pdev_child = platform_device_alloc(dev->drv_name,
PLATFORM_DEVID_AUTO);
if (!pdev_child) {
dev_err(&pdev->dev,
"failed to allocate mem for ocp2scp child\n");
goto err0;
}
ret = platform_device_add_resources(pdev_child,
dev->res, res_cnt);
if (ret) {
dev_err(&pdev->dev,
"failed to add resources for ocp2scp child\n");
goto err1;
}
pdev_child->dev.parent = &pdev->dev;
ret = platform_device_add(pdev_child);
if (ret) {
dev_err(&pdev->dev,
"failed to register ocp2scp child device\n");
goto err1;
}
}
} else {
dev_err(&pdev->dev, "OCP2SCP initialized without plat data\n");
return -EINVAL;
}
pm_runtime_enable(&pdev->dev);
return 0;
err1:
platform_device_put(pdev_child);
err0:
device_for_each_child(&pdev->dev, NULL, ocp2scp_remove_devices);
return ret;
}
static int __devexit omap_ocp2scp_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
device_for_each_child(&pdev->dev, NULL, ocp2scp_remove_devices);
return 0;
}
