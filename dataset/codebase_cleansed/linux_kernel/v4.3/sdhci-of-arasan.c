static unsigned int sdhci_arasan_get_timeout_clock(struct sdhci_host *host)
{
u32 div;
unsigned long freq;
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
div = readl(host->ioaddr + SDHCI_ARASAN_CLK_CTRL_OFFSET);
div = (div & CLK_CTRL_TIMEOUT_MASK) >> CLK_CTRL_TIMEOUT_SHIFT;
freq = clk_get_rate(pltfm_host->clk);
freq /= 1 << (CLK_CTRL_TIMEOUT_MIN_EXP + div);
return freq;
}
static int sdhci_arasan_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = pltfm_host->priv;
int ret;
ret = sdhci_suspend_host(host);
if (ret)
return ret;
clk_disable(pltfm_host->clk);
clk_disable(sdhci_arasan->clk_ahb);
return 0;
}
static int sdhci_arasan_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = pltfm_host->priv;
int ret;
ret = clk_enable(sdhci_arasan->clk_ahb);
if (ret) {
dev_err(dev, "Cannot enable AHB clock.\n");
return ret;
}
ret = clk_enable(pltfm_host->clk);
if (ret) {
dev_err(dev, "Cannot enable SD clock.\n");
clk_disable(sdhci_arasan->clk_ahb);
return ret;
}
return sdhci_resume_host(host);
}
static int sdhci_arasan_probe(struct platform_device *pdev)
{
int ret;
struct clk *clk_xin;
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_arasan_data *sdhci_arasan;
sdhci_arasan = devm_kzalloc(&pdev->dev, sizeof(*sdhci_arasan),
GFP_KERNEL);
if (!sdhci_arasan)
return -ENOMEM;
sdhci_arasan->clk_ahb = devm_clk_get(&pdev->dev, "clk_ahb");
if (IS_ERR(sdhci_arasan->clk_ahb)) {
dev_err(&pdev->dev, "clk_ahb clock not found.\n");
return PTR_ERR(sdhci_arasan->clk_ahb);
}
clk_xin = devm_clk_get(&pdev->dev, "clk_xin");
if (IS_ERR(clk_xin)) {
dev_err(&pdev->dev, "clk_xin clock not found.\n");
return PTR_ERR(clk_xin);
}
ret = clk_prepare_enable(sdhci_arasan->clk_ahb);
if (ret) {
dev_err(&pdev->dev, "Unable to enable AHB clock.\n");
return ret;
}
ret = clk_prepare_enable(clk_xin);
if (ret) {
dev_err(&pdev->dev, "Unable to enable SD clock.\n");
goto clk_dis_ahb;
}
host = sdhci_pltfm_init(pdev, &sdhci_arasan_pdata, 0);
if (IS_ERR(host)) {
ret = PTR_ERR(host);
goto clk_disable_all;
}
if (of_device_is_compatible(pdev->dev.of_node, "arasan,sdhci-4.9a")) {
host->quirks |= SDHCI_QUIRK_NO_HISPD_BIT;
host->quirks2 |= SDHCI_QUIRK2_HOST_NO_CMD23;
}
sdhci_get_of_property(pdev);
pltfm_host = sdhci_priv(host);
pltfm_host->priv = sdhci_arasan;
pltfm_host->clk = clk_xin;
ret = mmc_of_parse(host->mmc);
if (ret) {
dev_err(&pdev->dev, "parsing dt failed (%u)\n", ret);
goto clk_disable_all;
}
ret = sdhci_add_host(host);
if (ret)
goto err_pltfm_free;
return 0;
err_pltfm_free:
sdhci_pltfm_free(pdev);
clk_disable_all:
clk_disable_unprepare(clk_xin);
clk_dis_ahb:
clk_disable_unprepare(sdhci_arasan->clk_ahb);
return ret;
}
static int sdhci_arasan_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = pltfm_host->priv;
clk_disable_unprepare(sdhci_arasan->clk_ahb);
return sdhci_pltfm_unregister(pdev);
}
