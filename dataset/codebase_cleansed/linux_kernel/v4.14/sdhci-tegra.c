static u16 tegra_sdhci_readw(struct sdhci_host *host, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);
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
struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);
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
struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);
const struct sdhci_tegra_soc_data *soc_data = tegra_host->soc_data;
u32 misc_ctrl, clk_ctrl;
sdhci_reset(host, mask);
if (!(mask & SDHCI_RESET_ALL))
return;
misc_ctrl = sdhci_readl(host, SDHCI_TEGRA_VENDOR_MISC_CTRL);
clk_ctrl = sdhci_readl(host, SDHCI_TEGRA_VENDOR_CLOCK_CTRL);
misc_ctrl &= ~(SDHCI_MISC_CTRL_ENABLE_SDHCI_SPEC_300 |
SDHCI_MISC_CTRL_ENABLE_SDR50 |
SDHCI_MISC_CTRL_ENABLE_DDR50 |
SDHCI_MISC_CTRL_ENABLE_SDR104);
clk_ctrl &= ~SDHCI_CLOCK_CTRL_SPI_MODE_CLKEN_OVERRIDE;
if (!IS_ERR(host->mmc->supply.vqmmc)) {
if (soc_data->nvquirks & NVQUIRK_ENABLE_SDHCI_SPEC_300)
misc_ctrl |= SDHCI_MISC_CTRL_ENABLE_SDHCI_SPEC_300;
if (soc_data->nvquirks & NVQUIRK_ENABLE_SDR50)
misc_ctrl |= SDHCI_MISC_CTRL_ENABLE_SDR50;
if (soc_data->nvquirks & NVQUIRK_ENABLE_DDR50)
misc_ctrl |= SDHCI_MISC_CTRL_ENABLE_DDR50;
if (soc_data->nvquirks & NVQUIRK_ENABLE_SDR104)
misc_ctrl |= SDHCI_MISC_CTRL_ENABLE_SDR104;
if (soc_data->nvquirks & SDHCI_MISC_CTRL_ENABLE_SDR50)
clk_ctrl |= SDHCI_CLOCK_CTRL_SDR50_TUNING_OVERRIDE;
}
sdhci_writel(host, misc_ctrl, SDHCI_TEGRA_VENDOR_MISC_CTRL);
sdhci_writel(host, clk_ctrl, SDHCI_TEGRA_VENDOR_CLOCK_CTRL);
if (soc_data->nvquirks & NVQUIRK_HAS_PADCALIB)
tegra_host->pad_calib_required = true;
tegra_host->ddr_signaling = false;
}
static void tegra_sdhci_pad_autocalib(struct sdhci_host *host)
{
u32 val;
mdelay(1);
val = sdhci_readl(host, SDHCI_TEGRA_AUTO_CAL_CONFIG);
val |= SDHCI_AUTO_CAL_ENABLE | SDHCI_AUTO_CAL_START;
sdhci_writel(host,val, SDHCI_TEGRA_AUTO_CAL_CONFIG);
}
static void tegra_sdhci_set_clock(struct sdhci_host *host, unsigned int clock)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);
unsigned long host_clk;
if (!clock)
return sdhci_set_clock(host, clock);
host_clk = tegra_host->ddr_signaling ? clock * 2 : clock;
clk_set_rate(pltfm_host->clk, host_clk);
host->max_clk = clk_get_rate(pltfm_host->clk);
sdhci_set_clock(host, clock);
if (tegra_host->pad_calib_required) {
tegra_sdhci_pad_autocalib(host);
tegra_host->pad_calib_required = false;
}
}
static void tegra_sdhci_set_uhs_signaling(struct sdhci_host *host,
unsigned timing)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);
if (timing == MMC_TIMING_UHS_DDR50)
tegra_host->ddr_signaling = true;
return sdhci_set_uhs_signaling(host, timing);
}
static unsigned int tegra_sdhci_get_max_clock(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
return clk_round_rate(pltfm_host->clk, UINT_MAX) / 2;
}
static void tegra_sdhci_set_tap(struct sdhci_host *host, unsigned int tap)
{
u32 reg;
reg = sdhci_readl(host, SDHCI_TEGRA_VENDOR_CLOCK_CTRL);
reg &= ~SDHCI_CLOCK_CTRL_TAP_MASK;
reg |= tap << SDHCI_CLOCK_CTRL_TAP_SHIFT;
sdhci_writel(host, reg, SDHCI_TEGRA_VENDOR_CLOCK_CTRL);
}
static int tegra_sdhci_execute_tuning(struct sdhci_host *host, u32 opcode)
{
unsigned int min, max;
min = 10;
while (min < 255) {
tegra_sdhci_set_tap(host, min);
if (!mmc_send_tuning(host->mmc, opcode, NULL))
break;
min++;
}
max = min + 1;
while (max < 255) {
tegra_sdhci_set_tap(host, max);
if (mmc_send_tuning(host->mmc, opcode, NULL)) {
max--;
break;
}
max++;
}
tegra_sdhci_set_tap(host, min + ((max - min) * 3 / 4));
return mmc_send_tuning(host->mmc, opcode, NULL);
}
static void tegra_sdhci_voltage_switch(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);
const struct sdhci_tegra_soc_data *soc_data = tegra_host->soc_data;
if (soc_data->nvquirks & NVQUIRK_HAS_PADCALIB)
tegra_host->pad_calib_required = true;
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
host = sdhci_pltfm_init(pdev, soc_data->pdata, sizeof(*tegra_host));
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
tegra_host = sdhci_pltfm_priv(pltfm_host);
tegra_host->ddr_signaling = false;
tegra_host->pad_calib_required = false;
tegra_host->soc_data = soc_data;
rc = mmc_of_parse(host->mmc);
if (rc)
goto err_parse_dt;
if (tegra_host->soc_data->nvquirks & NVQUIRK_ENABLE_DDR50)
host->mmc->caps |= MMC_CAP_1_8V_DDR;
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
tegra_host->rst = devm_reset_control_get_exclusive(&pdev->dev,
"sdhci");
if (IS_ERR(tegra_host->rst)) {
rc = PTR_ERR(tegra_host->rst);
dev_err(&pdev->dev, "failed to get reset control: %d\n", rc);
goto err_rst_get;
}
rc = reset_control_assert(tegra_host->rst);
if (rc)
goto err_rst_get;
usleep_range(2000, 4000);
rc = reset_control_deassert(tegra_host->rst);
if (rc)
goto err_rst_get;
usleep_range(2000, 4000);
rc = sdhci_add_host(host);
if (rc)
goto err_add_host;
return 0;
err_add_host:
reset_control_assert(tegra_host->rst);
err_rst_get:
clk_disable_unprepare(pltfm_host->clk);
err_clk_get:
err_power_req:
err_parse_dt:
sdhci_pltfm_free(pdev);
return rc;
}
static int sdhci_tegra_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);
sdhci_remove_host(host, 0);
reset_control_assert(tegra_host->rst);
usleep_range(2000, 4000);
clk_disable_unprepare(pltfm_host->clk);
sdhci_pltfm_free(pdev);
return 0;
}
