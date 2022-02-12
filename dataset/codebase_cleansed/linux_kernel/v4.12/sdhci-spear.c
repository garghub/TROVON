static void sdhci_probe_config_dt(struct device_node *np,
struct spear_sdhci *host)
{
int cd_gpio;
cd_gpio = of_get_named_gpio(np, "cd-gpios", 0);
if (!gpio_is_valid(cd_gpio))
cd_gpio = -1;
host->card_int_gpio = cd_gpio;
}
static int sdhci_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct resource *iomem;
struct spear_sdhci *sdhci;
struct device *dev;
int ret;
dev = pdev->dev.parent ? pdev->dev.parent : &pdev->dev;
host = sdhci_alloc_host(dev, sizeof(*sdhci));
if (IS_ERR(host)) {
ret = PTR_ERR(host);
dev_dbg(&pdev->dev, "cannot allocate memory for sdhci\n");
goto err;
}
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
host->ioaddr = devm_ioremap_resource(&pdev->dev, iomem);
if (IS_ERR(host->ioaddr)) {
ret = PTR_ERR(host->ioaddr);
dev_dbg(&pdev->dev, "unable to map iomem: %d\n", ret);
goto err_host;
}
host->hw_name = "sdhci";
host->ops = &sdhci_pltfm_ops;
host->irq = platform_get_irq(pdev, 0);
host->quirks = SDHCI_QUIRK_BROKEN_ADMA;
sdhci = sdhci_priv(host);
sdhci->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(sdhci->clk)) {
ret = PTR_ERR(sdhci->clk);
dev_dbg(&pdev->dev, "Error getting clock\n");
goto err_host;
}
ret = clk_prepare_enable(sdhci->clk);
if (ret) {
dev_dbg(&pdev->dev, "Error enabling clock\n");
goto err_host;
}
ret = clk_set_rate(sdhci->clk, 50000000);
if (ret)
dev_dbg(&pdev->dev, "Error setting desired clk, clk=%lu\n",
clk_get_rate(sdhci->clk));
sdhci_probe_config_dt(pdev->dev.of_node, sdhci);
if (sdhci->card_int_gpio >= 0) {
ret = mmc_gpio_request_cd(host->mmc, sdhci->card_int_gpio, 0);
if (ret < 0) {
dev_dbg(&pdev->dev,
"failed to request card-detect gpio%d\n",
sdhci->card_int_gpio);
goto disable_clk;
}
}
ret = sdhci_add_host(host);
if (ret) {
dev_dbg(&pdev->dev, "error adding host\n");
goto disable_clk;
}
platform_set_drvdata(pdev, host);
return 0;
disable_clk:
clk_disable_unprepare(sdhci->clk);
err_host:
sdhci_free_host(host);
err:
dev_err(&pdev->dev, "spear-sdhci probe failed: %d\n", ret);
return ret;
}
static int sdhci_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct spear_sdhci *sdhci = sdhci_priv(host);
int dead = 0;
u32 scratch;
scratch = readl(host->ioaddr + SDHCI_INT_STATUS);
if (scratch == (u32)-1)
dead = 1;
sdhci_remove_host(host, dead);
clk_disable_unprepare(sdhci->clk);
sdhci_free_host(host);
return 0;
}
static int sdhci_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct spear_sdhci *sdhci = sdhci_priv(host);
int ret;
if (host->tuning_mode != SDHCI_TUNING_MODE_3)
mmc_retune_needed(host->mmc);
ret = sdhci_suspend_host(host);
if (!ret)
clk_disable(sdhci->clk);
return ret;
}
static int sdhci_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct spear_sdhci *sdhci = sdhci_priv(host);
int ret;
ret = clk_enable(sdhci->clk);
if (ret) {
dev_dbg(dev, "Resume: Error enabling clock\n");
return ret;
}
return sdhci_resume_host(host);
}
