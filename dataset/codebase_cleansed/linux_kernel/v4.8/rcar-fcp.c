struct rcar_fcp_device *rcar_fcp_get(const struct device_node *np)
{
struct rcar_fcp_device *fcp;
mutex_lock(&fcp_lock);
list_for_each_entry(fcp, &fcp_devices, list) {
if (fcp->dev->of_node != np)
continue;
if (!try_module_get(fcp->dev->driver->owner))
fcp = NULL;
goto done;
}
fcp = ERR_PTR(-EPROBE_DEFER);
done:
mutex_unlock(&fcp_lock);
return fcp;
}
void rcar_fcp_put(struct rcar_fcp_device *fcp)
{
if (fcp)
module_put(fcp->dev->driver->owner);
}
int rcar_fcp_enable(struct rcar_fcp_device *fcp)
{
int error;
if (!fcp)
return 0;
error = pm_runtime_get_sync(fcp->dev);
if (error < 0)
return error;
return 0;
}
void rcar_fcp_disable(struct rcar_fcp_device *fcp)
{
if (fcp)
pm_runtime_put(fcp->dev);
}
static int rcar_fcp_probe(struct platform_device *pdev)
{
struct rcar_fcp_device *fcp;
fcp = devm_kzalloc(&pdev->dev, sizeof(*fcp), GFP_KERNEL);
if (fcp == NULL)
return -ENOMEM;
fcp->dev = &pdev->dev;
pm_runtime_enable(&pdev->dev);
mutex_lock(&fcp_lock);
list_add_tail(&fcp->list, &fcp_devices);
mutex_unlock(&fcp_lock);
platform_set_drvdata(pdev, fcp);
return 0;
}
static int rcar_fcp_remove(struct platform_device *pdev)
{
struct rcar_fcp_device *fcp = platform_get_drvdata(pdev);
mutex_lock(&fcp_lock);
list_del(&fcp->list);
mutex_unlock(&fcp_lock);
pm_runtime_disable(&pdev->dev);
return 0;
}
