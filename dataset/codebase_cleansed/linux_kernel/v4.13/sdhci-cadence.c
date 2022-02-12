static int sdhci_cdns_write_phy_reg(struct sdhci_cdns_priv *priv,
u8 addr, u8 data)
{
void __iomem *reg = priv->hrs_addr + SDHCI_CDNS_HRS04;
u32 tmp;
int ret;
tmp = (data << SDHCI_CDNS_HRS04_WDATA_SHIFT) |
(addr << SDHCI_CDNS_HRS04_ADDR_SHIFT);
writel(tmp, reg);
tmp |= SDHCI_CDNS_HRS04_WR;
writel(tmp, reg);
ret = readl_poll_timeout(reg, tmp, tmp & SDHCI_CDNS_HRS04_ACK, 0, 10);
if (ret)
return ret;
tmp &= ~SDHCI_CDNS_HRS04_WR;
writel(tmp, reg);
return 0;
}
static int sdhci_cdns_phy_init(struct device_node *np,
struct sdhci_cdns_priv *priv)
{
u32 val;
int ret, i;
for (i = 0; i < ARRAY_SIZE(sdhci_cdns_phy_cfgs); i++) {
ret = of_property_read_u32(np, sdhci_cdns_phy_cfgs[i].property,
&val);
if (ret)
continue;
ret = sdhci_cdns_write_phy_reg(priv,
sdhci_cdns_phy_cfgs[i].addr,
val);
if (ret)
return ret;
}
return 0;
}
static inline void *sdhci_cdns_priv(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
return sdhci_pltfm_priv(pltfm_host);
}
static unsigned int sdhci_cdns_get_timeout_clock(struct sdhci_host *host)
{
return host->max_clk;
}
static void sdhci_cdns_set_emmc_mode(struct sdhci_cdns_priv *priv, u32 mode)
{
u32 tmp;
tmp = readl(priv->hrs_addr + SDHCI_CDNS_HRS06);
tmp &= ~SDHCI_CDNS_HRS06_MODE_MASK;
tmp |= mode;
writel(tmp, priv->hrs_addr + SDHCI_CDNS_HRS06);
}
static u32 sdhci_cdns_get_emmc_mode(struct sdhci_cdns_priv *priv)
{
u32 tmp;
tmp = readl(priv->hrs_addr + SDHCI_CDNS_HRS06);
return tmp & SDHCI_CDNS_HRS06_MODE_MASK;
}
static void sdhci_cdns_set_uhs_signaling(struct sdhci_host *host,
unsigned int timing)
{
struct sdhci_cdns_priv *priv = sdhci_cdns_priv(host);
u32 mode;
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
if (priv->enhanced_strobe)
mode = SDHCI_CDNS_HRS06_MODE_MMC_HS400ES;
else
mode = SDHCI_CDNS_HRS06_MODE_MMC_HS400;
break;
default:
mode = SDHCI_CDNS_HRS06_MODE_SD;
break;
}
sdhci_cdns_set_emmc_mode(priv, mode);
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
static void sdhci_cdns_hs400_enhanced_strobe(struct mmc_host *mmc,
struct mmc_ios *ios)
{
struct sdhci_host *host = mmc_priv(mmc);
struct sdhci_cdns_priv *priv = sdhci_cdns_priv(host);
u32 mode;
priv->enhanced_strobe = ios->enhanced_strobe;
mode = sdhci_cdns_get_emmc_mode(priv);
if (mode == SDHCI_CDNS_HRS06_MODE_MMC_HS400 && ios->enhanced_strobe)
sdhci_cdns_set_emmc_mode(priv,
SDHCI_CDNS_HRS06_MODE_MMC_HS400ES);
if (mode == SDHCI_CDNS_HRS06_MODE_MMC_HS400ES && !ios->enhanced_strobe)
sdhci_cdns_set_emmc_mode(priv,
SDHCI_CDNS_HRS06_MODE_MMC_HS400);
}
static int sdhci_cdns_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_cdns_priv *priv;
struct clk *clk;
int ret;
struct device *dev = &pdev->dev;
clk = devm_clk_get(dev, NULL);
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
priv->enhanced_strobe = false;
host->ioaddr += SDHCI_CDNS_SRS_BASE;
host->mmc_host_ops.execute_tuning = sdhci_cdns_execute_tuning;
host->mmc_host_ops.hs400_enhanced_strobe =
sdhci_cdns_hs400_enhanced_strobe;
sdhci_get_of_property(pdev);
ret = mmc_of_parse(host->mmc);
if (ret)
goto free;
ret = sdhci_cdns_phy_init(dev->of_node, priv);
if (ret)
goto free;
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
