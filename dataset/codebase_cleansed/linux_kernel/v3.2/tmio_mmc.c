static int tmio_mmc_suspend(struct platform_device *dev, pm_message_t state)
{
const struct mfd_cell *cell = mfd_get_cell(dev);
int ret;
ret = tmio_mmc_host_suspend(&dev->dev);
if (!ret && cell->disable)
cell->disable(dev);
return ret;
}
static int tmio_mmc_resume(struct platform_device *dev)
{
const struct mfd_cell *cell = mfd_get_cell(dev);
int ret = 0;
if (cell->resume)
ret = cell->resume(dev);
if (!ret)
ret = tmio_mmc_host_resume(&dev->dev);
return ret;
}
static int __devinit tmio_mmc_probe(struct platform_device *pdev)
{
const struct mfd_cell *cell = mfd_get_cell(pdev);
struct tmio_mmc_data *pdata;
struct tmio_mmc_host *host;
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
ret = tmio_mmc_host_probe(&host, pdev, pdata);
if (ret)
goto cell_disable;
ret = request_irq(irq, tmio_mmc_irq, IRQF_TRIGGER_FALLING,
dev_name(&pdev->dev), host);
if (ret)
goto host_remove;
pr_info("%s at 0x%08lx irq %d\n", mmc_hostname(host->mmc),
(unsigned long)host->ctl, irq);
return 0;
host_remove:
tmio_mmc_host_remove(host);
cell_disable:
if (cell->disable)
cell->disable(pdev);
out:
return ret;
}
static int __devexit tmio_mmc_remove(struct platform_device *pdev)
{
const struct mfd_cell *cell = mfd_get_cell(pdev);
struct mmc_host *mmc = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
if (mmc) {
struct tmio_mmc_host *host = mmc_priv(mmc);
free_irq(platform_get_irq(pdev, 0), host);
tmio_mmc_host_remove(host);
if (cell->disable)
cell->disable(pdev);
}
return 0;
}
static int __init tmio_mmc_init(void)
{
return platform_driver_register(&tmio_mmc_driver);
}
static void __exit tmio_mmc_exit(void)
{
platform_driver_unregister(&tmio_mmc_driver);
}
