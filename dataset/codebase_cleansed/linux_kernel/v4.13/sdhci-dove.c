static u16 sdhci_dove_readw(struct sdhci_host *host, int reg)
{
u16 ret;
switch (reg) {
case SDHCI_HOST_VERSION:
case SDHCI_SLOT_INT_STATUS:
return 0;
default:
ret = readw(host->ioaddr + reg);
}
return ret;
}
static u32 sdhci_dove_readl(struct sdhci_host *host, int reg)
{
u32 ret;
ret = readl(host->ioaddr + reg);
switch (reg) {
case SDHCI_CAPABILITIES:
ret &= ~SDHCI_CAN_VDD_300;
break;
}
return ret;
}
static int sdhci_dove_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
int ret;
host = sdhci_pltfm_init(pdev, &sdhci_dove_pdata, 0);
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
pltfm_host->clk = devm_clk_get(&pdev->dev, NULL);
if (!IS_ERR(pltfm_host->clk))
clk_prepare_enable(pltfm_host->clk);
ret = mmc_of_parse(host->mmc);
if (ret)
goto err_sdhci_add;
ret = sdhci_add_host(host);
if (ret)
goto err_sdhci_add;
return 0;
err_sdhci_add:
clk_disable_unprepare(pltfm_host->clk);
sdhci_pltfm_free(pdev);
return ret;
}
