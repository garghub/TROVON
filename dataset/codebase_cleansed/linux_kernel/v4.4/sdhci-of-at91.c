static int sdhci_at91_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
const struct sdhci_pltfm_data *soc_data;
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_at91_priv *priv;
unsigned int caps0, caps1;
unsigned int clk_base, clk_mul;
unsigned int gck_rate, real_gck_rate;
int ret;
match = of_match_device(sdhci_at91_dt_match, &pdev->dev);
if (!match)
return -EINVAL;
soc_data = match->data;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "unable to allocate private data\n");
return -ENOMEM;
}
priv->mainck = devm_clk_get(&pdev->dev, "baseclk");
if (IS_ERR(priv->mainck)) {
dev_err(&pdev->dev, "failed to get baseclk\n");
return PTR_ERR(priv->mainck);
}
priv->hclock = devm_clk_get(&pdev->dev, "hclock");
if (IS_ERR(priv->hclock)) {
dev_err(&pdev->dev, "failed to get hclock\n");
return PTR_ERR(priv->hclock);
}
priv->gck = devm_clk_get(&pdev->dev, "multclk");
if (IS_ERR(priv->gck)) {
dev_err(&pdev->dev, "failed to get multclk\n");
return PTR_ERR(priv->gck);
}
host = sdhci_pltfm_init(pdev, soc_data, 0);
if (IS_ERR(host))
return PTR_ERR(host);
clk_prepare_enable(priv->hclock);
caps0 = readl(host->ioaddr + SDHCI_CAPABILITIES);
caps1 = readl(host->ioaddr + SDHCI_CAPABILITIES_1);
clk_base = (caps0 & SDHCI_CLOCK_V3_BASE_MASK) >> SDHCI_CLOCK_BASE_SHIFT;
clk_mul = (caps1 & SDHCI_CLOCK_MUL_MASK) >> SDHCI_CLOCK_MUL_SHIFT;
gck_rate = clk_base * 1000000 * (clk_mul + 1);
ret = clk_set_rate(priv->gck, gck_rate);
if (ret < 0) {
dev_err(&pdev->dev, "failed to set gck");
goto hclock_disable_unprepare;
}
real_gck_rate = clk_get_rate(priv->gck);
if (real_gck_rate != gck_rate) {
clk_mul = real_gck_rate / (clk_base * 1000000) - 1;
caps1 &= (~SDHCI_CLOCK_MUL_MASK);
caps1 |= ((clk_mul << SDHCI_CLOCK_MUL_SHIFT) & SDHCI_CLOCK_MUL_MASK);
writel(SDMMC_CACR_KEY | SDMMC_CACR_CAPWREN, host->ioaddr + SDMMC_CACR);
writel(caps1, host->ioaddr + SDHCI_CAPABILITIES_1);
writel(0, host->ioaddr + SDMMC_CACR);
dev_info(&pdev->dev, "update clk mul to %u as gck rate is %u Hz\n",
clk_mul, real_gck_rate);
}
clk_prepare_enable(priv->mainck);
clk_prepare_enable(priv->gck);
pltfm_host = sdhci_priv(host);
pltfm_host->priv = priv;
ret = mmc_of_parse(host->mmc);
if (ret)
goto clocks_disable_unprepare;
sdhci_get_of_property(pdev);
ret = sdhci_add_host(host);
if (ret)
goto clocks_disable_unprepare;
return 0;
clocks_disable_unprepare:
clk_disable_unprepare(priv->gck);
clk_disable_unprepare(priv->mainck);
hclock_disable_unprepare:
clk_disable_unprepare(priv->hclock);
sdhci_pltfm_free(pdev);
return ret;
}
static int sdhci_at91_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_at91_priv *priv = pltfm_host->priv;
sdhci_pltfm_unregister(pdev);
clk_disable_unprepare(priv->gck);
clk_disable_unprepare(priv->hclock);
clk_disable_unprepare(priv->mainck);
return 0;
}
