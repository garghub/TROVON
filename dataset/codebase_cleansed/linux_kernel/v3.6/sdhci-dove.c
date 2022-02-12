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
switch (reg) {
case SDHCI_CAPABILITIES:
ret = readl(host->ioaddr + reg);
ret &= ~SDHCI_CAN_VDD_300;
break;
default:
ret = readl(host->ioaddr + reg);
}
return ret;
}
static int __devinit sdhci_dove_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_dove_priv *priv;
int ret;
ret = sdhci_pltfm_register(pdev, &sdhci_dove_pdata);
if (ret)
goto sdhci_dove_register_fail;
priv = devm_kzalloc(&pdev->dev, sizeof(struct sdhci_dove_priv),
GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "unable to allocate private data");
ret = -ENOMEM;
goto sdhci_dove_allocate_fail;
}
host = platform_get_drvdata(pdev);
pltfm_host = sdhci_priv(host);
pltfm_host->priv = priv;
priv->clk = clk_get(&pdev->dev, NULL);
if (!IS_ERR(priv->clk))
clk_prepare_enable(priv->clk);
return 0;
sdhci_dove_allocate_fail:
sdhci_pltfm_unregister(pdev);
sdhci_dove_register_fail:
return ret;
}
static int __devexit sdhci_dove_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_dove_priv *priv = pltfm_host->priv;
if (priv->clk) {
if (!IS_ERR(priv->clk)) {
clk_disable_unprepare(priv->clk);
clk_put(priv->clk);
}
devm_kfree(&pdev->dev, priv->clk);
}
return sdhci_pltfm_unregister(pdev);
}
