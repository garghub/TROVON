static inline void st_mmcss_set_static_delay(void __iomem *ioaddr)
{
if (!ioaddr)
return;
writel_relaxed(0x0, ioaddr + ST_TOP_MMC_DLY_CTRL);
writel_relaxed(ST_TOP_MMC_DLY_MAX,
ioaddr + ST_TOP_MMC_TX_CLK_DLY);
}
static void st_mmcss_cconfig(struct device_node *np, struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct mmc_host *mhost = host->mmc;
u32 cconf2, cconf3, cconf4, cconf5;
if (!of_device_is_compatible(np, "st,sdhci-stih407"))
return;
cconf2 = ST_MMC_CCONFIG_2_DEFAULT;
cconf3 = ST_MMC_CCONFIG_3_DEFAULT;
cconf4 = ST_MMC_CCONFIG_4_DEFAULT;
cconf5 = ST_MMC_CCONFIG_5_DEFAULT;
writel_relaxed(ST_MMC_CCONFIG_1_DEFAULT,
host->ioaddr + ST_MMC_CCONFIG_REG_1);
switch (mhost->f_max) {
case 200000000:
clk_set_rate(pltfm_host->clk, mhost->f_max);
cconf2 |= BASE_CLK_FREQ_200;
break;
case 100000000:
clk_set_rate(pltfm_host->clk, mhost->f_max);
cconf2 |= BASE_CLK_FREQ_100;
break;
default:
clk_set_rate(pltfm_host->clk, 50000000);
cconf2 |= BASE_CLK_FREQ_50;
}
writel_relaxed(cconf2, host->ioaddr + ST_MMC_CCONFIG_REG_2);
if (!mmc_card_is_removable(mhost))
cconf3 |= ST_MMC_CCONFIG_EMMC_SLOT_TYPE;
else
writel_relaxed(ST_MMC_GP_OUTPUT_CD,
host->ioaddr + ST_MMC_GP_OUTPUT);
if (mhost->caps & MMC_CAP_UHS_SDR50) {
cconf3 |= ST_MMC_CCONFIG_1P8_VOLT;
cconf4 |= ST_MMC_CCONFIG_SDR50;
cconf5 |= ST_MMC_CCONFIG_TUNING_FOR_SDR50;
cconf5 |= RETUNING_TIMER_CNT_MAX;
}
if (mhost->caps & MMC_CAP_UHS_SDR104) {
cconf3 |= ST_MMC_CCONFIG_1P8_VOLT;
cconf4 |= ST_MMC_CCONFIG_SDR104;
cconf5 |= RETUNING_TIMER_CNT_MAX;
}
if (mhost->caps & MMC_CAP_UHS_DDR50)
cconf4 |= ST_MMC_CCONFIG_DDR50;
writel_relaxed(cconf3, host->ioaddr + ST_MMC_CCONFIG_REG_3);
writel_relaxed(cconf4, host->ioaddr + ST_MMC_CCONFIG_REG_4);
writel_relaxed(cconf5, host->ioaddr + ST_MMC_CCONFIG_REG_5);
}
static inline void st_mmcss_set_dll(void __iomem *ioaddr)
{
if (!ioaddr)
return;
writel_relaxed(ST_TOP_MMC_DYN_DLY_CONF, ioaddr + ST_TOP_MMC_DLY_CTRL);
writel_relaxed(ST_TOP_MMC_TX_DLL_STEP_DLY_VALID,
ioaddr + ST_TOP_MMC_TX_DLL_STEP_DLY);
}
static int st_mmcss_lock_dll(void __iomem *ioaddr)
{
unsigned long curr, value;
unsigned long finish = jiffies + HZ;
do {
curr = jiffies;
value = readl(ioaddr + ST_MMC_STATUS_R);
if (value & 0x1)
return 0;
cpu_relax();
} while (!time_after_eq(curr, finish));
return -EBUSY;
}
static int sdhci_st_set_dll_for_clock(struct sdhci_host *host)
{
int ret = 0;
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct st_mmc_platform_data *pdata = sdhci_pltfm_priv(pltfm_host);
if (host->clock > CLK_TO_CHECK_DLL_LOCK) {
st_mmcss_set_dll(pdata->top_ioaddr);
ret = st_mmcss_lock_dll(host->ioaddr);
}
return ret;
}
static void sdhci_st_set_uhs_signaling(struct sdhci_host *host,
unsigned int uhs)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct st_mmc_platform_data *pdata = sdhci_pltfm_priv(pltfm_host);
u16 ctrl_2 = sdhci_readw(host, SDHCI_HOST_CONTROL2);
int ret = 0;
ctrl_2 &= ~SDHCI_CTRL_UHS_MASK;
switch (uhs) {
case MMC_TIMING_UHS_SDR12:
st_mmcss_set_static_delay(pdata->top_ioaddr);
ctrl_2 |= SDHCI_CTRL_UHS_SDR12 | SDHCI_CTRL_VDD_180;
break;
case MMC_TIMING_UHS_SDR25:
st_mmcss_set_static_delay(pdata->top_ioaddr);
ctrl_2 |= SDHCI_CTRL_UHS_SDR25 | SDHCI_CTRL_VDD_180;
break;
case MMC_TIMING_UHS_SDR50:
st_mmcss_set_static_delay(pdata->top_ioaddr);
ctrl_2 |= SDHCI_CTRL_UHS_SDR50 | SDHCI_CTRL_VDD_180;
ret = sdhci_st_set_dll_for_clock(host);
break;
case MMC_TIMING_UHS_SDR104:
case MMC_TIMING_MMC_HS200:
st_mmcss_set_static_delay(pdata->top_ioaddr);
ctrl_2 |= SDHCI_CTRL_UHS_SDR104 | SDHCI_CTRL_VDD_180;
ret = sdhci_st_set_dll_for_clock(host);
break;
case MMC_TIMING_UHS_DDR50:
case MMC_TIMING_MMC_DDR52:
st_mmcss_set_static_delay(pdata->top_ioaddr);
ctrl_2 |= SDHCI_CTRL_UHS_DDR50 | SDHCI_CTRL_VDD_180;
break;
}
if (ret)
dev_warn(mmc_dev(host->mmc), "Error setting dll for clock "
"(uhs %d)\n", uhs);
dev_dbg(mmc_dev(host->mmc), "uhs %d, ctrl_2 %04X\n", uhs, ctrl_2);
sdhci_writew(host, ctrl_2, SDHCI_HOST_CONTROL2);
}
static u32 sdhci_st_readl(struct sdhci_host *host, int reg)
{
u32 ret;
switch (reg) {
case SDHCI_CAPABILITIES:
ret = readl_relaxed(host->ioaddr + reg);
ret &= ~SDHCI_CAN_VDD_300;
break;
default:
ret = readl_relaxed(host->ioaddr + reg);
}
return ret;
}
static int sdhci_st_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct sdhci_host *host;
struct st_mmc_platform_data *pdata;
struct sdhci_pltfm_host *pltfm_host;
struct clk *clk, *icnclk;
int ret = 0;
u16 host_version;
struct resource *res;
struct reset_control *rstc;
clk = devm_clk_get(&pdev->dev, "mmc");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Peripheral clk not found\n");
return PTR_ERR(clk);
}
icnclk = devm_clk_get(&pdev->dev, "icn");
if (IS_ERR(icnclk))
icnclk = NULL;
rstc = devm_reset_control_get_exclusive(&pdev->dev, NULL);
if (IS_ERR(rstc))
rstc = NULL;
else
reset_control_deassert(rstc);
host = sdhci_pltfm_init(pdev, &sdhci_st_pdata, sizeof(*pdata));
if (IS_ERR(host)) {
dev_err(&pdev->dev, "Failed sdhci_pltfm_init\n");
ret = PTR_ERR(host);
goto err_pltfm_init;
}
pltfm_host = sdhci_priv(host);
pdata = sdhci_pltfm_priv(pltfm_host);
pdata->rstc = rstc;
ret = mmc_of_parse(host->mmc);
if (ret) {
dev_err(&pdev->dev, "Failed mmc_of_parse\n");
goto err_of;
}
ret = clk_prepare_enable(clk);
if (ret) {
dev_err(&pdev->dev, "Failed to prepare clock\n");
goto err_of;
}
ret = clk_prepare_enable(icnclk);
if (ret) {
dev_err(&pdev->dev, "Failed to prepare icn clock\n");
goto err_icnclk;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"top-mmc-delay");
pdata->top_ioaddr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pdata->top_ioaddr)) {
dev_warn(&pdev->dev, "FlashSS Top Dly registers not available");
pdata->top_ioaddr = NULL;
}
pltfm_host->clk = clk;
pdata->icnclk = icnclk;
st_mmcss_cconfig(np, host);
ret = sdhci_add_host(host);
if (ret) {
dev_err(&pdev->dev, "Failed sdhci_add_host\n");
goto err_out;
}
host_version = readw_relaxed((host->ioaddr + SDHCI_HOST_VERSION));
dev_info(&pdev->dev, "SDHCI ST Initialised: Host Version: 0x%x Vendor Version 0x%x\n",
((host_version & SDHCI_SPEC_VER_MASK) >> SDHCI_SPEC_VER_SHIFT),
((host_version & SDHCI_VENDOR_VER_MASK) >>
SDHCI_VENDOR_VER_SHIFT));
return 0;
err_out:
clk_disable_unprepare(icnclk);
err_icnclk:
clk_disable_unprepare(clk);
err_of:
sdhci_pltfm_free(pdev);
err_pltfm_init:
if (rstc)
reset_control_assert(rstc);
return ret;
}
static int sdhci_st_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct st_mmc_platform_data *pdata = sdhci_pltfm_priv(pltfm_host);
struct reset_control *rstc = pdata->rstc;
int ret;
ret = sdhci_pltfm_unregister(pdev);
clk_disable_unprepare(pdata->icnclk);
if (rstc)
reset_control_assert(rstc);
return ret;
}
static int sdhci_st_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct st_mmc_platform_data *pdata = sdhci_pltfm_priv(pltfm_host);
int ret;
if (host->tuning_mode != SDHCI_TUNING_MODE_3)
mmc_retune_needed(host->mmc);
ret = sdhci_suspend_host(host);
if (ret)
goto out;
if (pdata->rstc)
reset_control_assert(pdata->rstc);
clk_disable_unprepare(pdata->icnclk);
clk_disable_unprepare(pltfm_host->clk);
out:
return ret;
}
static int sdhci_st_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct st_mmc_platform_data *pdata = sdhci_pltfm_priv(pltfm_host);
struct device_node *np = dev->of_node;
int ret;
ret = clk_prepare_enable(pltfm_host->clk);
if (ret)
return ret;
ret = clk_prepare_enable(pdata->icnclk);
if (ret) {
clk_disable_unprepare(pltfm_host->clk);
return ret;
}
if (pdata->rstc)
reset_control_deassert(pdata->rstc);
st_mmcss_cconfig(np, host);
return sdhci_resume_host(host);
}
