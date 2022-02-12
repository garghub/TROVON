static int sdhci_bcm_kona_sd_reset(struct sdhci_host *host)
{
unsigned int val;
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(100);
val = sdhci_readl(host, KONA_SDHOST_CORECTRL);
val |= KONA_SDHOST_RESET;
sdhci_writel(host, val, KONA_SDHOST_CORECTRL);
while (!(sdhci_readl(host, KONA_SDHOST_CORECTRL) & KONA_SDHOST_RESET)) {
if (time_is_before_jiffies(timeout)) {
pr_err("Error: sd host is stuck in reset!!!\n");
return -EFAULT;
}
}
val = sdhci_readl(host, KONA_SDHOST_CORECTRL);
val &= ~KONA_SDHOST_RESET;
usleep_range(1000, 5000);
sdhci_writel(host, val, KONA_SDHOST_CORECTRL);
return 0;
}
static void sdhci_bcm_kona_sd_init(struct sdhci_host *host)
{
unsigned int val;
val = sdhci_readl(host, KONA_SDHOST_COREIMR);
val |= KONA_SDHOST_IP;
sdhci_writel(host, val, KONA_SDHOST_COREIMR);
val = sdhci_readl(host, KONA_SDHOST_CORECTRL);
val |= KONA_SDHOST_EN;
usleep_range(1000, 5000);
sdhci_writel(host, val, KONA_SDHOST_CORECTRL);
}
static int sdhci_bcm_kona_sd_card_emulate(struct sdhci_host *host, int insert)
{
struct sdhci_pltfm_host *pltfm_priv = sdhci_priv(host);
struct sdhci_bcm_kona_dev *kona_dev = sdhci_pltfm_priv(pltfm_priv);
u32 val;
mutex_lock(&kona_dev->write_lock);
udelay(20);
val = sdhci_readl(host, KONA_SDHOST_CORESTAT);
if (insert) {
int ret;
ret = mmc_gpio_get_ro(host->mmc);
if (ret >= 0)
val = (val & ~KONA_SDHOST_WP) |
((ret) ? KONA_SDHOST_WP : 0);
val |= KONA_SDHOST_CD_SW;
sdhci_writel(host, val, KONA_SDHOST_CORESTAT);
} else {
val &= ~KONA_SDHOST_CD_SW;
sdhci_writel(host, val, KONA_SDHOST_CORESTAT);
}
mutex_unlock(&kona_dev->write_lock);
return 0;
}
static void sdhci_bcm_kona_card_event(struct sdhci_host *host)
{
if (mmc_gpio_get_cd(host->mmc) > 0) {
dev_dbg(mmc_dev(host->mmc),
"card inserted\n");
sdhci_bcm_kona_sd_card_emulate(host, 1);
} else {
dev_dbg(mmc_dev(host->mmc),
"card removed\n");
sdhci_bcm_kona_sd_card_emulate(host, 0);
}
}
static unsigned int sdhci_bcm_kona_get_max_clk(struct sdhci_host *host)
{
struct sdhci_bcm_kona_dev *kona_dev;
struct sdhci_pltfm_host *pltfm_priv = sdhci_priv(host);
kona_dev = sdhci_pltfm_priv(pltfm_priv);
return host->mmc->f_max;
}
static unsigned int sdhci_bcm_kona_get_timeout_clock(struct sdhci_host *host)
{
return sdhci_bcm_kona_get_max_clk(host);
}
static void sdhci_bcm_kona_init_74_clocks(struct sdhci_host *host,
u8 power_mode)
{
if (power_mode != MMC_POWER_OFF)
udelay(740);
}
static int sdhci_bcm_kona_probe(struct platform_device *pdev)
{
struct sdhci_bcm_kona_dev *kona_dev = NULL;
struct sdhci_pltfm_host *pltfm_priv;
struct device *dev = &pdev->dev;
struct sdhci_host *host;
int ret;
ret = 0;
host = sdhci_pltfm_init(pdev, &sdhci_pltfm_data_kona,
sizeof(*kona_dev));
if (IS_ERR(host))
return PTR_ERR(host);
dev_dbg(dev, "%s: inited. IOADDR=%p\n", __func__, host->ioaddr);
pltfm_priv = sdhci_priv(host);
kona_dev = sdhci_pltfm_priv(pltfm_priv);
mutex_init(&kona_dev->write_lock);
ret = mmc_of_parse(host->mmc);
if (ret)
goto err_pltfm_free;
if (!host->mmc->f_max) {
dev_err(&pdev->dev, "Missing max-freq for SDHCI cfg\n");
ret = -ENXIO;
goto err_pltfm_free;
}
kona_dev->external_clk = devm_clk_get(dev, NULL);
if (IS_ERR(kona_dev->external_clk)) {
dev_err(dev, "Failed to get external clock\n");
ret = PTR_ERR(kona_dev->external_clk);
goto err_pltfm_free;
}
if (clk_set_rate(kona_dev->external_clk, host->mmc->f_max) != 0) {
dev_err(dev, "Failed to set rate external clock\n");
goto err_pltfm_free;
}
if (clk_prepare_enable(kona_dev->external_clk) != 0) {
dev_err(dev, "Failed to enable external clock\n");
goto err_pltfm_free;
}
dev_dbg(dev, "non-removable=%c\n",
(host->mmc->caps & MMC_CAP_NONREMOVABLE) ? 'Y' : 'N');
dev_dbg(dev, "cd_gpio %c, wp_gpio %c\n",
(mmc_gpio_get_cd(host->mmc) != -ENOSYS) ? 'Y' : 'N',
(mmc_gpio_get_ro(host->mmc) != -ENOSYS) ? 'Y' : 'N');
if (host->mmc->caps & MMC_CAP_NONREMOVABLE)
host->quirks |= SDHCI_QUIRK_BROKEN_CARD_DETECTION;
dev_dbg(dev, "is_8bit=%c\n",
(host->mmc->caps | MMC_CAP_8_BIT_DATA) ? 'Y' : 'N');
ret = sdhci_bcm_kona_sd_reset(host);
if (ret)
goto err_clk_disable;
sdhci_bcm_kona_sd_init(host);
ret = sdhci_add_host(host);
if (ret) {
dev_err(dev, "Failed sdhci_add_host\n");
goto err_reset;
}
if (host->mmc->caps & MMC_CAP_NONREMOVABLE) {
ret = sdhci_bcm_kona_sd_card_emulate(host, 1);
if (ret) {
dev_err(dev,
"unable to emulate card insertion\n");
goto err_remove_host;
}
}
if (mmc_gpio_get_cd(host->mmc) > 0)
sdhci_bcm_kona_sd_card_emulate(host, 1);
dev_dbg(dev, "initialized properly\n");
return 0;
err_remove_host:
sdhci_remove_host(host, 0);
err_reset:
sdhci_bcm_kona_sd_reset(host);
err_clk_disable:
clk_disable_unprepare(kona_dev->external_clk);
err_pltfm_free:
sdhci_pltfm_free(pdev);
dev_err(dev, "Probing of sdhci-pltfm failed: %d\n", ret);
return ret;
}
static int sdhci_bcm_kona_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_priv = sdhci_priv(host);
struct sdhci_bcm_kona_dev *kona_dev = sdhci_pltfm_priv(pltfm_priv);
int dead = (readl(host->ioaddr + SDHCI_INT_STATUS) == 0xffffffff);
sdhci_remove_host(host, dead);
clk_disable_unprepare(kona_dev->external_clk);
sdhci_pltfm_free(pdev);
return 0;
}
