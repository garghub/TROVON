static u16 tegra_sdhci_readw(struct sdhci_host *host, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = pltfm_host->priv;
const struct sdhci_tegra_soc_data *soc_data = tegra_host->soc_data;
if (unlikely((soc_data->nvquirks & NVQUIRK_FORCE_SDHCI_SPEC_200) &&
(reg == SDHCI_HOST_VERSION))) {
return SDHCI_SPEC_200;
}
return readw(host->ioaddr + reg);
}
static void tegra_sdhci_writew(struct sdhci_host *host, u16 val, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
switch (reg) {
case SDHCI_TRANSFER_MODE:
pltfm_host->xfer_mode_shadow = val;
return;
case SDHCI_COMMAND:
writel((val << 16) | pltfm_host->xfer_mode_shadow,
host->ioaddr + SDHCI_TRANSFER_MODE);
return;
}
writew(val, host->ioaddr + reg);
}
static void tegra_sdhci_writel(struct sdhci_host *host, u32 val, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = pltfm_host->priv;
const struct sdhci_tegra_soc_data *soc_data = tegra_host->soc_data;
if (unlikely(reg == SDHCI_SIGNAL_ENABLE))
val &= ~(SDHCI_INT_TIMEOUT|SDHCI_INT_CRC);
writel(val, host->ioaddr + reg);
if (unlikely((soc_data->nvquirks & NVQUIRK_ENABLE_BLOCK_GAP_DET) &&
(reg == SDHCI_INT_ENABLE))) {
u8 gap_ctrl = readb(host->ioaddr + SDHCI_BLOCK_GAP_CONTROL);
if (val & SDHCI_INT_CARD_INT)
gap_ctrl |= 0x8;
else
gap_ctrl &= ~0x8;
writeb(gap_ctrl, host->ioaddr + SDHCI_BLOCK_GAP_CONTROL);
}
}
static unsigned int tegra_sdhci_get_ro(struct sdhci_host *host)
{
return mmc_gpio_get_ro(host->mmc);
}
static void tegra_sdhci_reset(struct sdhci_host *host, u8 mask)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = pltfm_host->priv;
const struct sdhci_tegra_soc_data *soc_data = tegra_host->soc_data;
u32 misc_ctrl;
sdhci_reset(host, mask);
if (!(mask & SDHCI_RESET_ALL))
return;
misc_ctrl = sdhci_readw(host, SDHCI_TEGRA_VENDOR_MISC_CTRL);
if (soc_data->nvquirks & NVQUIRK_ENABLE_SDHCI_SPEC_300)
misc_ctrl |= SDHCI_MISC_CTRL_ENABLE_SDHCI_SPEC_300;
if (soc_data->nvquirks & NVQUIRK_DISABLE_SDR50)
misc_ctrl &= ~SDHCI_MISC_CTRL_ENABLE_SDR50;
if (soc_data->nvquirks & NVQUIRK_DISABLE_DDR50)
misc_ctrl &= ~SDHCI_MISC_CTRL_ENABLE_DDR50;
if (soc_data->nvquirks & NVQUIRK_DISABLE_SDR104)
misc_ctrl &= ~SDHCI_MISC_CTRL_ENABLE_SDR104;
sdhci_writew(host, misc_ctrl, SDHCI_TEGRA_VENDOR_MISC_CTRL);
}
static void tegra_sdhci_set_bus_width(struct sdhci_host *host, int bus_width)
{
u32 ctrl;
ctrl = sdhci_readb(host, SDHCI_HOST_CONTROL);
if ((host->mmc->caps & MMC_CAP_8_BIT_DATA) &&
(bus_width == MMC_BUS_WIDTH_8)) {
ctrl &= ~SDHCI_CTRL_4BITBUS;
ctrl |= SDHCI_CTRL_8BITBUS;
} else {
ctrl &= ~SDHCI_CTRL_8BITBUS;
if (bus_width == MMC_BUS_WIDTH_4)
ctrl |= SDHCI_CTRL_4BITBUS;
else
ctrl &= ~SDHCI_CTRL_4BITBUS;
}
sdhci_writeb(host, ctrl, SDHCI_HOST_CONTROL);
}
static int sdhci_tegra_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
const struct sdhci_tegra_soc_data *soc_data;
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_tegra *tegra_host;
struct clk *clk;
int rc;
match = of_match_device(sdhci_tegra_dt_match, &pdev->dev);
if (!match)
return -EINVAL;
soc_data = match->data;
host = sdhci_pltfm_init(pdev, soc_data->pdata, 0);
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
tegra_host = devm_kzalloc(&pdev->dev, sizeof(*tegra_host), GFP_KERNEL);
if (!tegra_host) {
dev_err(mmc_dev(host->mmc), "failed to allocate tegra_host\n");
rc = -ENOMEM;
goto err_alloc_tegra_host;
}
tegra_host->soc_data = soc_data;
pltfm_host->priv = tegra_host;
rc = mmc_of_parse(host->mmc);
if (rc)
goto err_parse_dt;
tegra_host->power_gpio = devm_gpiod_get_optional(&pdev->dev, "power",
GPIOD_OUT_HIGH);
if (IS_ERR(tegra_host->power_gpio)) {
rc = PTR_ERR(tegra_host->power_gpio);
goto err_power_req;
}
clk = devm_clk_get(mmc_dev(host->mmc), NULL);
if (IS_ERR(clk)) {
dev_err(mmc_dev(host->mmc), "clk err\n");
rc = PTR_ERR(clk);
goto err_clk_get;
}
clk_prepare_enable(clk);
pltfm_host->clk = clk;
rc = sdhci_add_host(host);
if (rc)
goto err_add_host;
return 0;
err_add_host:
clk_disable_unprepare(pltfm_host->clk);
err_clk_get:
err_power_req:
err_parse_dt:
err_alloc_tegra_host:
sdhci_pltfm_free(pdev);
return rc;
}
