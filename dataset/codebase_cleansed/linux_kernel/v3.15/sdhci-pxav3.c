static int mv_conf_mbus_windows(struct platform_device *pdev,
const struct mbus_dram_target_info *dram)
{
int i;
void __iomem *regs;
struct resource *res;
if (!dram) {
dev_err(&pdev->dev, "no mbus dram info\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res) {
dev_err(&pdev->dev, "cannot get mbus registers\n");
return -EINVAL;
}
regs = ioremap(res->start, resource_size(res));
if (!regs) {
dev_err(&pdev->dev, "cannot map mbus registers\n");
return -ENOMEM;
}
for (i = 0; i < SDHCI_MAX_WIN_NUM; i++) {
writel(0, regs + SDHCI_WINDOW_CTRL(i));
writel(0, regs + SDHCI_WINDOW_BASE(i));
}
for (i = 0; i < dram->num_cs; i++) {
const struct mbus_dram_window *cs = dram->cs + i;
writel(((cs->size - 1) & 0xffff0000) |
(cs->mbus_attr << 8) |
(dram->mbus_dram_target_id << 4) | 1,
regs + SDHCI_WINDOW_CTRL(i));
writel(cs->base, regs + SDHCI_WINDOW_BASE(i));
}
iounmap(regs);
return 0;
}
static void pxav3_set_private_registers(struct sdhci_host *host, u8 mask)
{
struct platform_device *pdev = to_platform_device(mmc_dev(host->mmc));
struct sdhci_pxa_platdata *pdata = pdev->dev.platform_data;
if (mask == SDHCI_RESET_ALL) {
if (pdata && 0 != pdata->clk_delay_cycles) {
u16 tmp;
tmp = readw(host->ioaddr + SD_CLOCK_BURST_SIZE_SETUP);
tmp |= (pdata->clk_delay_cycles & SDCLK_DELAY_MASK)
<< SDCLK_DELAY_SHIFT;
tmp |= SDCLK_SEL;
writew(tmp, host->ioaddr + SD_CLOCK_BURST_SIZE_SETUP);
}
}
}
static void pxav3_gen_init_74_clocks(struct sdhci_host *host, u8 power_mode)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_pxa *pxa = pltfm_host->priv;
u16 tmp;
int count;
if (pxa->power_mode == MMC_POWER_UP
&& power_mode == MMC_POWER_ON) {
dev_dbg(mmc_dev(host->mmc),
"%s: slot->power_mode = %d,"
"ios->power_mode = %d\n",
__func__,
pxa->power_mode,
power_mode);
tmp = readw(host->ioaddr + SD_CE_ATA_2);
tmp |= SDCE_MISC_INT_EN;
writew(tmp, host->ioaddr + SD_CE_ATA_2);
tmp = readw(host->ioaddr + SD_CFG_FIFO_PARAM);
tmp |= SDCFG_GEN_PAD_CLK_ON;
writew(tmp, host->ioaddr + SD_CFG_FIFO_PARAM);
udelay(740);
count = 0;
while (count++ < MAX_WAIT_COUNT) {
if ((readw(host->ioaddr + SD_CE_ATA_2)
& SDCE_MISC_INT) == 0)
break;
udelay(10);
}
if (count == MAX_WAIT_COUNT)
dev_warn(mmc_dev(host->mmc), "74 clock interrupt not cleared\n");
tmp = readw(host->ioaddr + SD_CE_ATA_2);
tmp |= SDCE_MISC_INT;
writew(tmp, host->ioaddr + SD_CE_ATA_2);
}
pxa->power_mode = power_mode;
}
static int pxav3_set_uhs_signaling(struct sdhci_host *host, unsigned int uhs)
{
u16 ctrl_2;
ctrl_2 = sdhci_readw(host, SDHCI_HOST_CONTROL2);
ctrl_2 &= ~SDHCI_CTRL_UHS_MASK;
switch (uhs) {
case MMC_TIMING_UHS_SDR12:
ctrl_2 |= SDHCI_CTRL_UHS_SDR12;
break;
case MMC_TIMING_UHS_SDR25:
ctrl_2 |= SDHCI_CTRL_UHS_SDR25;
break;
case MMC_TIMING_UHS_SDR50:
ctrl_2 |= SDHCI_CTRL_UHS_SDR50 | SDHCI_CTRL_VDD_180;
break;
case MMC_TIMING_UHS_SDR104:
ctrl_2 |= SDHCI_CTRL_UHS_SDR104 | SDHCI_CTRL_VDD_180;
break;
case MMC_TIMING_UHS_DDR50:
ctrl_2 |= SDHCI_CTRL_UHS_DDR50 | SDHCI_CTRL_VDD_180;
break;
}
sdhci_writew(host, ctrl_2, SDHCI_HOST_CONTROL2);
dev_dbg(mmc_dev(host->mmc),
"%s uhs = %d, ctrl_2 = %04X\n",
__func__, uhs, ctrl_2);
return 0;
}
static struct sdhci_pxa_platdata *pxav3_get_mmc_pdata(struct device *dev)
{
struct sdhci_pxa_platdata *pdata;
struct device_node *np = dev->of_node;
u32 clk_delay_cycles;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
of_property_read_u32(np, "mrvl,clk-delay-cycles", &clk_delay_cycles);
if (clk_delay_cycles > 0)
pdata->clk_delay_cycles = clk_delay_cycles;
return pdata;
}
static inline struct sdhci_pxa_platdata *pxav3_get_mmc_pdata(struct device *dev)
{
return NULL;
}
static int sdhci_pxav3_probe(struct platform_device *pdev)
{
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_pxa_platdata *pdata = pdev->dev.platform_data;
struct device *dev = &pdev->dev;
struct device_node *np = pdev->dev.of_node;
struct sdhci_host *host = NULL;
struct sdhci_pxa *pxa = NULL;
const struct of_device_id *match;
int ret;
struct clk *clk;
pxa = kzalloc(sizeof(struct sdhci_pxa), GFP_KERNEL);
if (!pxa)
return -ENOMEM;
host = sdhci_pltfm_init(pdev, &sdhci_pxav3_pdata, 0);
if (IS_ERR(host)) {
kfree(pxa);
return PTR_ERR(host);
}
if (of_device_is_compatible(np, "marvell,armada-380-sdhci")) {
ret = mv_conf_mbus_windows(pdev, mv_mbus_dram_info());
if (ret < 0)
goto err_mbus_win;
}
pltfm_host = sdhci_priv(host);
pltfm_host->priv = pxa;
clk = clk_get(dev, NULL);
if (IS_ERR(clk)) {
dev_err(dev, "failed to get io clock\n");
ret = PTR_ERR(clk);
goto err_clk_get;
}
pltfm_host->clk = clk;
clk_prepare_enable(clk);
host->mmc->caps |= MMC_CAP_1_8V_DDR;
match = of_match_device(of_match_ptr(sdhci_pxav3_of_match), &pdev->dev);
if (match) {
ret = mmc_of_parse(host->mmc);
if (ret)
goto err_of_parse;
sdhci_get_of_property(pdev);
pdata = pxav3_get_mmc_pdata(dev);
} else if (pdata) {
if (pdata->flags & PXA_FLAG_CARD_PERMANENT)
host->mmc->caps |= MMC_CAP_NONREMOVABLE;
if (pdata->flags & PXA_FLAG_SD_8_BIT_CAPABLE_SLOT)
host->mmc->caps |= MMC_CAP_8_BIT_DATA;
if (pdata->quirks)
host->quirks |= pdata->quirks;
if (pdata->quirks2)
host->quirks2 |= pdata->quirks2;
if (pdata->host_caps)
host->mmc->caps |= pdata->host_caps;
if (pdata->host_caps2)
host->mmc->caps2 |= pdata->host_caps2;
if (pdata->pm_caps)
host->mmc->pm_caps |= pdata->pm_caps;
if (gpio_is_valid(pdata->ext_cd_gpio)) {
ret = mmc_gpio_request_cd(host->mmc, pdata->ext_cd_gpio,
0);
if (ret) {
dev_err(mmc_dev(host->mmc),
"failed to allocate card detect gpio\n");
goto err_cd_req;
}
}
}
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev, PXAV3_RPM_DELAY_MS);
pm_runtime_use_autosuspend(&pdev->dev);
pm_suspend_ignore_children(&pdev->dev, 1);
ret = sdhci_add_host(host);
if (ret) {
dev_err(&pdev->dev, "failed to add host\n");
goto err_add_host;
}
platform_set_drvdata(pdev, host);
if (host->mmc->pm_caps & MMC_PM_KEEP_POWER) {
device_init_wakeup(&pdev->dev, 1);
host->mmc->pm_flags |= MMC_PM_WAKE_SDIO_IRQ;
} else {
device_init_wakeup(&pdev->dev, 0);
}
pm_runtime_put_autosuspend(&pdev->dev);
return 0;
err_of_parse:
err_cd_req:
err_add_host:
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
clk_disable_unprepare(clk);
clk_put(clk);
err_clk_get:
err_mbus_win:
sdhci_pltfm_free(pdev);
kfree(pxa);
return ret;
}
static int sdhci_pxav3_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_pxa *pxa = pltfm_host->priv;
pm_runtime_get_sync(&pdev->dev);
sdhci_remove_host(host, 1);
pm_runtime_disable(&pdev->dev);
clk_disable_unprepare(pltfm_host->clk);
clk_put(pltfm_host->clk);
sdhci_pltfm_free(pdev);
kfree(pxa);
return 0;
}
static int sdhci_pxav3_suspend(struct device *dev)
{
int ret;
struct sdhci_host *host = dev_get_drvdata(dev);
pm_runtime_get_sync(dev);
ret = sdhci_suspend_host(host);
pm_runtime_mark_last_busy(dev);
pm_runtime_put_autosuspend(dev);
return ret;
}
static int sdhci_pxav3_resume(struct device *dev)
{
int ret;
struct sdhci_host *host = dev_get_drvdata(dev);
pm_runtime_get_sync(dev);
ret = sdhci_resume_host(host);
pm_runtime_mark_last_busy(dev);
pm_runtime_put_autosuspend(dev);
return ret;
}
static int sdhci_pxav3_runtime_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
unsigned long flags;
if (pltfm_host->clk) {
spin_lock_irqsave(&host->lock, flags);
host->runtime_suspended = true;
spin_unlock_irqrestore(&host->lock, flags);
clk_disable_unprepare(pltfm_host->clk);
}
return 0;
}
static int sdhci_pxav3_runtime_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
unsigned long flags;
if (pltfm_host->clk) {
clk_prepare_enable(pltfm_host->clk);
spin_lock_irqsave(&host->lock, flags);
host->runtime_suspended = false;
spin_unlock_irqrestore(&host->lock, flags);
}
return 0;
}
