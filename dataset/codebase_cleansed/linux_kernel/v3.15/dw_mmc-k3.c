static void dw_mci_k3_set_ios(struct dw_mci *host, struct mmc_ios *ios)
{
int ret;
ret = clk_set_rate(host->ciu_clk, ios->clock);
if (ret)
dev_warn(host->dev, "failed to set rate %uHz\n", ios->clock);
host->bus_hz = clk_get_rate(host->ciu_clk);
}
static int dw_mci_k3_probe(struct platform_device *pdev)
{
const struct dw_mci_drv_data *drv_data;
const struct of_device_id *match;
match = of_match_node(dw_mci_k3_match, pdev->dev.of_node);
drv_data = match->data;
return dw_mci_pltfm_register(pdev, drv_data);
}
static int dw_mci_k3_suspend(struct device *dev)
{
struct dw_mci *host = dev_get_drvdata(dev);
int ret;
ret = dw_mci_suspend(host);
if (!ret)
clk_disable_unprepare(host->ciu_clk);
return ret;
}
static int dw_mci_k3_resume(struct device *dev)
{
struct dw_mci *host = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(host->ciu_clk);
if (ret) {
dev_err(host->dev, "failed to enable ciu clock\n");
return ret;
}
return dw_mci_resume(host);
}
