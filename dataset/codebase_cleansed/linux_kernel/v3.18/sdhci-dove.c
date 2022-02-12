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
struct sdhci_dove_priv *priv;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(struct sdhci_dove_priv),
GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "unable to allocate private data");
return -ENOMEM;
}
priv->clk = devm_clk_get(&pdev->dev, NULL);
host = sdhci_pltfm_init(pdev, &sdhci_dove_pdata, 0);
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
pltfm_host->priv = priv;
if (!IS_ERR(priv->clk))
clk_prepare_enable(priv->clk);
ret = mmc_of_parse(host->mmc);
if (ret)
goto err_sdhci_add;
ret = sdhci_add_host(host);
if (ret)
goto err_sdhci_add;
return 0;
err_sdhci_add:
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
sdhci_pltfm_free(pdev);
return ret;
}
static int sdhci_dove_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_dove_priv *priv = pltfm_host->priv;
sdhci_pltfm_unregister(pdev);
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
return 0;
}
