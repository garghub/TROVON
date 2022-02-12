static int sdhci_brcmstb_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
int res;
if (host->tuning_mode != SDHCI_TUNING_MODE_3)
mmc_retune_needed(host->mmc);
res = sdhci_suspend_host(host);
if (res)
return res;
clk_disable_unprepare(pltfm_host->clk);
return res;
}
static int sdhci_brcmstb_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
int err;
err = clk_prepare_enable(pltfm_host->clk);
if (err)
return err;
return sdhci_resume_host(host);
}
static int sdhci_brcmstb_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct clk *clk;
int res;
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Clock not found in Device Tree\n");
clk = NULL;
}
res = clk_prepare_enable(clk);
if (res)
return res;
host = sdhci_pltfm_init(pdev, &sdhci_brcmstb_pdata, 0);
if (IS_ERR(host)) {
res = PTR_ERR(host);
goto err_clk;
}
host->mmc->caps2 |= MMC_CAP2_HC_ERASE_SZ;
sdhci_get_of_property(pdev);
mmc_of_parse(host->mmc);
host->caps = sdhci_readl(host, SDHCI_CAPABILITIES);
if (of_device_is_compatible(pdev->dev.of_node, "brcm,bcm7425-sdhci"))
host->caps &= ~SDHCI_CAN_64BIT;
host->caps1 = sdhci_readl(host, SDHCI_CAPABILITIES_1);
host->caps1 &= ~(SDHCI_SUPPORT_SDR50 | SDHCI_SUPPORT_SDR104 |
SDHCI_SUPPORT_DDR50);
host->quirks |= SDHCI_QUIRK_MISSING_CAPS |
SDHCI_QUIRK_BROKEN_TIMEOUT_VAL;
res = sdhci_add_host(host);
if (res)
goto err;
pltfm_host = sdhci_priv(host);
pltfm_host->clk = clk;
return res;
err:
sdhci_pltfm_free(pdev);
err_clk:
clk_disable_unprepare(clk);
return res;
}
