static int tegra20_spdif_runtime_suspend(struct device *dev)
{
struct tegra20_spdif *spdif = dev_get_drvdata(dev);
clk_disable_unprepare(spdif->clk_spdif_out);
return 0;
}
static int tegra20_spdif_runtime_resume(struct device *dev)
{
struct tegra20_spdif *spdif = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(spdif->clk_spdif_out);
if (ret) {
dev_err(dev, "clk_enable failed: %d\n", ret);
return ret;
}
return 0;
}
static int tegra20_spdif_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct device *dev = dai->dev;
struct tegra20_spdif *spdif = snd_soc_dai_get_drvdata(dai);
unsigned int mask, val;
int ret, spdifclock;
mask = TEGRA20_SPDIF_CTRL_PACK |
TEGRA20_SPDIF_CTRL_BIT_MODE_MASK;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
val = TEGRA20_SPDIF_CTRL_PACK |
TEGRA20_SPDIF_CTRL_BIT_MODE_16BIT;
break;
default:
return -EINVAL;
}
regmap_update_bits(spdif->regmap, TEGRA20_SPDIF_CTRL, mask, val);
switch (params_rate(params)) {
case 32000:
spdifclock = 4096000;
break;
case 44100:
spdifclock = 5644800;
break;
case 48000:
spdifclock = 6144000;
break;
case 88200:
spdifclock = 11289600;
break;
case 96000:
spdifclock = 12288000;
break;
case 176400:
spdifclock = 22579200;
break;
case 192000:
spdifclock = 24576000;
break;
default:
return -EINVAL;
}
ret = clk_set_rate(spdif->clk_spdif_out, spdifclock);
if (ret) {
dev_err(dev, "Can't set SPDIF clock rate: %d\n", ret);
return ret;
}
return 0;
}
static void tegra20_spdif_start_playback(struct tegra20_spdif *spdif)
{
regmap_update_bits(spdif->regmap, TEGRA20_SPDIF_CTRL,
TEGRA20_SPDIF_CTRL_TX_EN,
TEGRA20_SPDIF_CTRL_TX_EN);
}
static void tegra20_spdif_stop_playback(struct tegra20_spdif *spdif)
{
regmap_update_bits(spdif->regmap, TEGRA20_SPDIF_CTRL,
TEGRA20_SPDIF_CTRL_TX_EN, 0);
}
static int tegra20_spdif_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct tegra20_spdif *spdif = snd_soc_dai_get_drvdata(dai);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
tegra20_spdif_start_playback(spdif);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
tegra20_spdif_stop_playback(spdif);
break;
default:
return -EINVAL;
}
return 0;
}
static int tegra20_spdif_probe(struct snd_soc_dai *dai)
{
struct tegra20_spdif *spdif = snd_soc_dai_get_drvdata(dai);
dai->capture_dma_data = NULL;
dai->playback_dma_data = &spdif->playback_dma_data;
return 0;
}
static bool tegra20_spdif_wr_rd_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TEGRA20_SPDIF_CTRL:
case TEGRA20_SPDIF_STATUS:
case TEGRA20_SPDIF_STROBE_CTRL:
case TEGRA20_SPDIF_DATA_FIFO_CSR:
case TEGRA20_SPDIF_DATA_OUT:
case TEGRA20_SPDIF_DATA_IN:
case TEGRA20_SPDIF_CH_STA_RX_A:
case TEGRA20_SPDIF_CH_STA_RX_B:
case TEGRA20_SPDIF_CH_STA_RX_C:
case TEGRA20_SPDIF_CH_STA_RX_D:
case TEGRA20_SPDIF_CH_STA_RX_E:
case TEGRA20_SPDIF_CH_STA_RX_F:
case TEGRA20_SPDIF_CH_STA_TX_A:
case TEGRA20_SPDIF_CH_STA_TX_B:
case TEGRA20_SPDIF_CH_STA_TX_C:
case TEGRA20_SPDIF_CH_STA_TX_D:
case TEGRA20_SPDIF_CH_STA_TX_E:
case TEGRA20_SPDIF_CH_STA_TX_F:
case TEGRA20_SPDIF_USR_STA_RX_A:
case TEGRA20_SPDIF_USR_DAT_TX_A:
return true;
default:
return false;
};
}
static bool tegra20_spdif_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TEGRA20_SPDIF_STATUS:
case TEGRA20_SPDIF_DATA_FIFO_CSR:
case TEGRA20_SPDIF_DATA_OUT:
case TEGRA20_SPDIF_DATA_IN:
case TEGRA20_SPDIF_CH_STA_RX_A:
case TEGRA20_SPDIF_CH_STA_RX_B:
case TEGRA20_SPDIF_CH_STA_RX_C:
case TEGRA20_SPDIF_CH_STA_RX_D:
case TEGRA20_SPDIF_CH_STA_RX_E:
case TEGRA20_SPDIF_CH_STA_RX_F:
case TEGRA20_SPDIF_USR_STA_RX_A:
case TEGRA20_SPDIF_USR_DAT_TX_A:
return true;
default:
return false;
};
}
static bool tegra20_spdif_precious_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TEGRA20_SPDIF_DATA_OUT:
case TEGRA20_SPDIF_DATA_IN:
case TEGRA20_SPDIF_USR_STA_RX_A:
case TEGRA20_SPDIF_USR_DAT_TX_A:
return true;
default:
return false;
};
}
static int tegra20_spdif_platform_probe(struct platform_device *pdev)
{
struct tegra20_spdif *spdif;
struct resource *mem, *memregion, *dmareq;
void __iomem *regs;
int ret;
spdif = devm_kzalloc(&pdev->dev, sizeof(struct tegra20_spdif),
GFP_KERNEL);
if (!spdif) {
dev_err(&pdev->dev, "Can't allocate tegra20_spdif\n");
ret = -ENOMEM;
goto err;
}
dev_set_drvdata(&pdev->dev, spdif);
spdif->clk_spdif_out = clk_get(&pdev->dev, "spdif_out");
if (IS_ERR(spdif->clk_spdif_out)) {
pr_err("Can't retrieve spdif clock\n");
ret = PTR_ERR(spdif->clk_spdif_out);
goto err;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "No memory resource\n");
ret = -ENODEV;
goto err_clk_put;
}
dmareq = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!dmareq) {
dev_err(&pdev->dev, "No DMA resource\n");
ret = -ENODEV;
goto err_clk_put;
}
memregion = devm_request_mem_region(&pdev->dev, mem->start,
resource_size(mem), DRV_NAME);
if (!memregion) {
dev_err(&pdev->dev, "Memory region already claimed\n");
ret = -EBUSY;
goto err_clk_put;
}
regs = devm_ioremap(&pdev->dev, mem->start, resource_size(mem));
if (!regs) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto err_clk_put;
}
spdif->regmap = devm_regmap_init_mmio(&pdev->dev, regs,
&tegra20_spdif_regmap_config);
if (IS_ERR(spdif->regmap)) {
dev_err(&pdev->dev, "regmap init failed\n");
ret = PTR_ERR(spdif->regmap);
goto err_clk_put;
}
spdif->playback_dma_data.addr = mem->start + TEGRA20_SPDIF_DATA_OUT;
spdif->playback_dma_data.wrap = 4;
spdif->playback_dma_data.width = 32;
spdif->playback_dma_data.req_sel = dmareq->start;
pm_runtime_enable(&pdev->dev);
if (!pm_runtime_enabled(&pdev->dev)) {
ret = tegra20_spdif_runtime_resume(&pdev->dev);
if (ret)
goto err_pm_disable;
}
ret = snd_soc_register_dai(&pdev->dev, &tegra20_spdif_dai);
if (ret) {
dev_err(&pdev->dev, "Could not register DAI: %d\n", ret);
ret = -ENOMEM;
goto err_suspend;
}
ret = tegra_pcm_platform_register(&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "Could not register PCM: %d\n", ret);
goto err_unregister_dai;
}
return 0;
err_unregister_dai:
snd_soc_unregister_dai(&pdev->dev);
err_suspend:
if (!pm_runtime_status_suspended(&pdev->dev))
tegra20_spdif_runtime_suspend(&pdev->dev);
err_pm_disable:
pm_runtime_disable(&pdev->dev);
err_clk_put:
clk_put(spdif->clk_spdif_out);
err:
return ret;
}
static int tegra20_spdif_platform_remove(struct platform_device *pdev)
{
struct tegra20_spdif *spdif = dev_get_drvdata(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
tegra20_spdif_runtime_suspend(&pdev->dev);
tegra_pcm_platform_unregister(&pdev->dev);
snd_soc_unregister_dai(&pdev->dev);
clk_put(spdif->clk_spdif_out);
return 0;
}
