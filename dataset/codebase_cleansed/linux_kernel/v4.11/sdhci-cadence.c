static void sdhci_cdns_write_phy_reg(struct sdhci_cdns_priv *priv,
u8 addr, u8 data)
{
void __iomem *reg = priv->hrs_addr + SDHCI_CDNS_HRS04;
u32 tmp;
tmp = (data << SDHCI_CDNS_HRS04_WDATA_SHIFT) |
(addr << SDHCI_CDNS_HRS04_ADDR_SHIFT);
writel(tmp, reg);
tmp |= SDHCI_CDNS_HRS04_WR;
writel(tmp, reg);
tmp &= ~SDHCI_CDNS_HRS04_WR;
writel(tmp, reg);
}
static void sdhci_cdns_phy_init(struct sdhci_cdns_priv *priv)
{
sdhci_cdns_write_phy_reg(priv, SDHCI_CDNS_PHY_DLY_SD_HS, 4);
sdhci_cdns_write_phy_reg(priv, SDHCI_CDNS_PHY_DLY_SD_DEFAULT, 4);
sdhci_cdns_write_phy_reg(priv, SDHCI_CDNS_PHY_DLY_EMMC_LEGACY, 9);
sdhci_cdns_write_phy_reg(priv, SDHCI_CDNS_PHY_DLY_EMMC_SDR, 2);
sdhci_cdns_write_phy_reg(priv, SDHCI_CDNS_PHY_DLY_EMMC_DDR, 3);
}
static inline void *sdhci_cdns_priv(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
return sdhci_pltfm_priv(pltfm_host);
}
static unsigned int sdhci_cdns_get_timeout_clock(struct sdhci_host *host)
{
return host->max_clk / 1000;
}
static void sdhci_cdns_set_uhs_signaling(struct sdhci_host *host,
unsigned int timing)
{
struct sdhci_cdns_priv *priv = sdhci_cdns_priv(host);
u32 mode, tmp;
switch (timing) {
case MMC_TIMING_MMC_HS:
mode = SDHCI_CDNS_HRS06_MODE_MMC_SDR;
break;
case MMC_TIMING_MMC_DDR52:
mode = SDHCI_CDNS_HRS06_MODE_MMC_DDR;
break;
case MMC_TIMING_MMC_HS200:
mode = SDHCI_CDNS_HRS06_MODE_MMC_HS200;
break;
case MMC_TIMING_MMC_HS400:
mode = SDHCI_CDNS_HRS06_MODE_MMC_HS400;
break;
default:
mode = SDHCI_CDNS_HRS06_MODE_SD;
break;
}
tmp = readl(priv->hrs_addr + SDHCI_CDNS_HRS06);
tmp &= ~SDHCI_CDNS_HRS06_MODE_MASK;
tmp |= mode;
writel(tmp, priv->hrs_addr + SDHCI_CDNS_HRS06);
if (mode == SDHCI_CDNS_HRS06_MODE_SD)
sdhci_set_uhs_signaling(host, timing);
}
static int sdhci_cdns_set_tune_val(struct sdhci_host *host, unsigned int val)
{
struct sdhci_cdns_priv *priv = sdhci_cdns_priv(host);
void __iomem *reg = priv->hrs_addr + SDHCI_CDNS_HRS06;
u32 tmp;
if (WARN_ON(val > SDHCI_CDNS_HRS06_TUNE_MASK))
return -EINVAL;
tmp = readl(reg);
tmp &= ~(SDHCI_CDNS_HRS06_TUNE_MASK << SDHCI_CDNS_HRS06_TUNE_SHIFT);
tmp |= val << SDHCI_CDNS_HRS06_TUNE_SHIFT;
tmp |= SDHCI_CDNS_HRS06_TUNE_UP;
writel(tmp, reg);
return readl_poll_timeout(reg, tmp, !(tmp & SDHCI_CDNS_HRS06_TUNE_UP),
0, 1);
}
static int sdhci_cdns_execute_tuning(struct mmc_host *mmc, u32 opcode)
{
struct sdhci_host *host = mmc_priv(mmc);
int cur_streak = 0;
int max_streak = 0;
int end_of_streak = 0;
int i;
if (host->timing != MMC_TIMING_MMC_HS200)
return sdhci_execute_tuning(mmc, opcode);
if (WARN_ON(opcode != MMC_SEND_TUNING_BLOCK_HS200))
return -EINVAL;
for (i = 0; i < SDHCI_CDNS_MAX_TUNING_LOOP; i++) {
if (sdhci_cdns_set_tune_val(host, i) ||
mmc_send_tuning(host->mmc, opcode, NULL)) {
cur_streak = 0;
} else {
cur_streak++;
if (cur_streak > max_streak) {
max_streak = cur_streak;
end_of_streak = i;
}
}
}
if (!max_streak) {
dev_err(mmc_dev(host->mmc), "no tuning point found\n");
return -EIO;
}
return sdhci_cdns_set_tune_val(host, end_of_streak - max_streak / 2);
}
static int sdhci_cdns_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_cdns_priv *priv;
struct clk *clk;
int ret;
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
ret = clk_prepare_enable(clk);
if (ret)
return ret;
host = sdhci_pltfm_init(pdev, &sdhci_cdns_pltfm_data, sizeof(*priv));
if (IS_ERR(host)) {
ret = PTR_ERR(host);
goto disable_clk;
}
pltfm_host = sdhci_priv(host);
pltfm_host->clk = clk;
priv = sdhci_cdns_priv(host);
priv->hrs_addr = host->ioaddr;
host->ioaddr += SDHCI_CDNS_SRS_BASE;
host->mmc_host_ops.execute_tuning = sdhci_cdns_execute_tuning;
ret = mmc_of_parse(host->mmc);
if (ret)
goto free;
sdhci_cdns_phy_init(priv);
ret = sdhci_add_host(host);
if (ret)
goto free;
return 0;
free:
sdhci_pltfm_free(pdev);
disable_clk:
clk_disable_unprepare(clk);
return ret;
}
