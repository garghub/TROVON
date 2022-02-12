static int tmio_mmc_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
const struct mfd_cell *cell = mfd_get_cell(pdev);
int ret;
ret = pm_runtime_force_suspend(dev);
if (!ret && cell->disable)
cell->disable(pdev);
return ret;
}
static int tmio_mmc_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
const struct mfd_cell *cell = mfd_get_cell(pdev);
int ret = 0;
if (cell->resume)
ret = cell->resume(pdev);
if (!ret)
ret = pm_runtime_force_resume(dev);
return ret;
}
static int tmio_mmc_probe(struct platform_device *pdev)
{
const struct mfd_cell *cell = mfd_get_cell(pdev);
struct tmio_mmc_data *pdata;
struct tmio_mmc_host *host;
struct resource *res;
int ret = -EINVAL, irq;
if (pdev->num_resources != 2)
goto out;
pdata = pdev->dev.platform_data;
if (!pdata || !pdata->hclk)
goto out;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = irq;
goto out;
}
if (cell->enable) {
ret = cell->enable(pdev);
if (ret)
goto out;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -EINVAL;
goto cell_disable;
}
pdata->flags |= TMIO_MMC_HAVE_HIGH_REG;
host = tmio_mmc_host_alloc(pdev);
if (!host)
goto cell_disable;
host->bus_shift = resource_size(res) >> 10;
ret = tmio_mmc_host_probe(host, pdata);
if (ret)
goto host_free;
ret = devm_request_irq(&pdev->dev, irq, tmio_mmc_irq,
IRQF_TRIGGER_FALLING,
dev_name(&pdev->dev), host);
if (ret)
goto host_remove;
pr_info("%s at 0x%08lx irq %d\n", mmc_hostname(host->mmc),
(unsigned long)host->ctl, irq);
return 0;
host_remove:
tmio_mmc_host_remove(host);
host_free:
tmio_mmc_host_free(host);
cell_disable:
if (cell->disable)
cell->disable(pdev);
out:
return ret;
}
static int tmio_mmc_remove(struct platform_device *pdev)
{
const struct mfd_cell *cell = mfd_get_cell(pdev);
struct mmc_host *mmc = platform_get_drvdata(pdev);
if (mmc) {
struct tmio_mmc_host *host = mmc_priv(mmc);
tmio_mmc_host_remove(host);
if (cell->disable)
cell->disable(pdev);
}
return 0;
}
