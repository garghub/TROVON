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
struct sdhci_arasan_data *sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
int ret;
ret = sdhci_suspend_host(host);
if (ret)
return ret;
if (!IS_ERR(sdhci_arasan->phy)) {
ret = phy_power_off(sdhci_arasan->phy);
if (ret) {
dev_err(dev, "Cannot power off phy.\n");
sdhci_resume_host(host);
return ret;
}
}
clk_disable(pltfm_host->clk);
clk_disable(sdhci_arasan->clk_ahb);
return 0;
}
static int sdhci_arasan_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
int ret;
ret = clk_enable(sdhci_arasan->clk_ahb);
if (ret) {
dev_err(dev, "Cannot enable AHB clock.\n");
return ret;
}
ret = clk_enable(pltfm_host->clk);
if (ret) {
dev_err(dev, "Cannot enable SD clock.\n");
return ret;
}
if (!IS_ERR(sdhci_arasan->phy)) {
ret = phy_power_on(sdhci_arasan->phy);
if (ret) {
dev_err(dev, "Cannot power on phy.\n");
return ret;
}
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
host = sdhci_pltfm_init(pdev, &sdhci_arasan_pdata,
sizeof(*sdhci_arasan));
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
sdhci_arasan->clk_ahb = devm_clk_get(&pdev->dev, "clk_ahb");
if (IS_ERR(sdhci_arasan->clk_ahb)) {
dev_err(&pdev->dev, "clk_ahb clock not found.\n");
ret = PTR_ERR(sdhci_arasan->clk_ahb);
goto err_pltfm_free;
}
clk_xin = devm_clk_get(&pdev->dev, "clk_xin");
if (IS_ERR(clk_xin)) {
dev_err(&pdev->dev, "clk_xin clock not found.\n");
ret = PTR_ERR(clk_xin);
goto err_pltfm_free;
}
ret = clk_prepare_enable(sdhci_arasan->clk_ahb);
if (ret) {
dev_err(&pdev->dev, "Unable to enable AHB clock.\n");
goto err_pltfm_free;
}
ret = clk_prepare_enable(clk_xin);
if (ret) {
dev_err(&pdev->dev, "Unable to enable SD clock.\n");
goto clk_dis_ahb;
}
sdhci_get_of_property(pdev);
pltfm_host->clk = clk_xin;
ret = mmc_of_parse(host->mmc);
if (ret) {
dev_err(&pdev->dev, "parsing dt failed (%u)\n", ret);
goto clk_disable_all;
}
sdhci_arasan->phy = ERR_PTR(-ENODEV);
if (of_device_is_compatible(pdev->dev.of_node,
"arasan,sdhci-5.1")) {
sdhci_arasan->phy = devm_phy_get(&pdev->dev,
"phy_arasan");
if (IS_ERR(sdhci_arasan->phy)) {
ret = PTR_ERR(sdhci_arasan->phy);
dev_err(&pdev->dev, "No phy for arasan,sdhci-5.1.\n");
goto clk_disable_all;
}
ret = phy_init(sdhci_arasan->phy);
if (ret < 0) {
dev_err(&pdev->dev, "phy_init err.\n");
goto clk_disable_all;
}
ret = phy_power_on(sdhci_arasan->phy);
if (ret < 0) {
dev_err(&pdev->dev, "phy_power_on err.\n");
goto err_phy_power;
}
}
ret = sdhci_add_host(host);
if (ret)
goto err_add_host;
return 0;
err_add_host:
if (!IS_ERR(sdhci_arasan->phy))
phy_power_off(sdhci_arasan->phy);
err_phy_power:
if (!IS_ERR(sdhci_arasan->phy))
phy_exit(sdhci_arasan->phy);
clk_disable_all:
clk_disable_unprepare(clk_xin);
clk_dis_ahb:
clk_disable_unprepare(sdhci_arasan->clk_ahb);
err_pltfm_free:
sdhci_pltfm_free(pdev);
return ret;
}
static int sdhci_arasan_remove(struct platform_device *pdev)
{
int ret;
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
struct clk *clk_ahb = sdhci_arasan->clk_ahb;
if (!IS_ERR(sdhci_arasan->phy)) {
phy_power_off(sdhci_arasan->phy);
phy_exit(sdhci_arasan->phy);
}
ret = sdhci_pltfm_unregister(pdev);
clk_disable_unprepare(clk_ahb);
return ret;
}
