static void sdhci_at91_set_clock(struct sdhci_host *host, unsigned int clock)
{
u16 clk;
unsigned long timeout;
host->mmc->actual_clock = 0;
clk = sdhci_readw(host, SDHCI_CLOCK_CONTROL);
clk &= SDHCI_CLOCK_INT_EN;
sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);
if (clock == 0)
return;
clk = sdhci_calc_clk(host, clock, &host->mmc->actual_clock);
clk |= SDHCI_CLOCK_INT_EN;
sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);
timeout = 20;
while (!((clk = sdhci_readw(host, SDHCI_CLOCK_CONTROL))
& SDHCI_CLOCK_INT_STABLE)) {
if (timeout == 0) {
pr_err("%s: Internal clock never stabilised.\n",
mmc_hostname(host->mmc));
return;
}
timeout--;
mdelay(1);
}
clk |= SDHCI_CLOCK_CARD_EN;
sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);
}
static int sdhci_at91_runtime_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_at91_priv *priv = sdhci_pltfm_priv(pltfm_host);
int ret;
ret = sdhci_runtime_suspend_host(host);
clk_disable_unprepare(priv->gck);
clk_disable_unprepare(priv->hclock);
clk_disable_unprepare(priv->mainck);
return ret;
}
static int sdhci_at91_runtime_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_at91_priv *priv = sdhci_pltfm_priv(pltfm_host);
int ret;
ret = clk_prepare_enable(priv->mainck);
if (ret) {
dev_err(dev, "can't enable mainck\n");
return ret;
}
ret = clk_prepare_enable(priv->hclock);
if (ret) {
dev_err(dev, "can't enable hclock\n");
return ret;
}
ret = clk_prepare_enable(priv->gck);
if (ret) {
dev_err(dev, "can't enable gck\n");
return ret;
}
return sdhci_runtime_resume_host(host);
}
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
unsigned int preset_div;
match = of_match_device(sdhci_at91_dt_match, &pdev->dev);
if (!match)
return -EINVAL;
soc_data = match->data;
host = sdhci_pltfm_init(pdev, soc_data, sizeof(*priv));
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
priv = sdhci_pltfm_priv(pltfm_host);
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
preset_div = DIV_ROUND_UP(real_gck_rate, 24000000) - 1;
writew(SDHCI_AT91_PRESET_COMMON_CONF | preset_div,
host->ioaddr + SDHCI_PRESET_FOR_SDR12);
preset_div = DIV_ROUND_UP(real_gck_rate, 50000000) - 1;
writew(SDHCI_AT91_PRESET_COMMON_CONF | preset_div,
host->ioaddr + SDHCI_PRESET_FOR_SDR25);
preset_div = DIV_ROUND_UP(real_gck_rate, 100000000) - 1;
writew(SDHCI_AT91_PRESET_COMMON_CONF | preset_div,
host->ioaddr + SDHCI_PRESET_FOR_SDR50);
preset_div = DIV_ROUND_UP(real_gck_rate, 120000000) - 1;
writew(SDHCI_AT91_PRESET_COMMON_CONF | preset_div,
host->ioaddr + SDHCI_PRESET_FOR_SDR104);
preset_div = DIV_ROUND_UP(real_gck_rate, 50000000) - 1;
writew(SDHCI_AT91_PRESET_COMMON_CONF | preset_div,
host->ioaddr + SDHCI_PRESET_FOR_DDR50);
clk_prepare_enable(priv->mainck);
clk_prepare_enable(priv->gck);
ret = mmc_of_parse(host->mmc);
if (ret)
goto clocks_disable_unprepare;
sdhci_get_of_property(pdev);
pm_runtime_get_noresume(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev, 50);
pm_runtime_use_autosuspend(&pdev->dev);
ret = sdhci_add_host(host);
if (ret)
goto pm_runtime_disable;
if (mmc_card_is_removable(host->mmc) &&
mmc_gpio_get_cd(host->mmc) < 0) {
host->mmc->caps |= MMC_CAP_NEEDS_POLL;
host->quirks &= ~SDHCI_QUIRK_BROKEN_CARD_DETECTION;
}
pm_runtime_put_autosuspend(&pdev->dev);
return 0;
pm_runtime_disable:
pm_runtime_disable(&pdev->dev);
pm_runtime_set_suspended(&pdev->dev);
pm_runtime_put_noidle(&pdev->dev);
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
struct sdhci_at91_priv *priv = sdhci_pltfm_priv(pltfm_host);
struct clk *gck = priv->gck;
struct clk *hclock = priv->hclock;
struct clk *mainck = priv->mainck;
pm_runtime_get_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
pm_runtime_put_noidle(&pdev->dev);
sdhci_pltfm_unregister(pdev);
clk_disable_unprepare(gck);
clk_disable_unprepare(hclock);
clk_disable_unprepare(mainck);
return 0;
}
