static int __maybe_unused rk_spdif_runtime_suspend(struct device *dev)
{
struct rk_spdif_dev *spdif = dev_get_drvdata(dev);
regcache_cache_only(spdif->regmap, true);
clk_disable_unprepare(spdif->mclk);
clk_disable_unprepare(spdif->hclk);
return 0;
}
static int __maybe_unused rk_spdif_runtime_resume(struct device *dev)
{
struct rk_spdif_dev *spdif = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(spdif->mclk);
if (ret) {
dev_err(spdif->dev, "mclk clock enable failed %d\n", ret);
return ret;
}
ret = clk_prepare_enable(spdif->hclk);
if (ret) {
dev_err(spdif->dev, "hclk clock enable failed %d\n", ret);
return ret;
}
regcache_cache_only(spdif->regmap, false);
regcache_mark_dirty(spdif->regmap);
ret = regcache_sync(spdif->regmap);
if (ret) {
clk_disable_unprepare(spdif->mclk);
clk_disable_unprepare(spdif->hclk);
}
return ret;
}
static int rk_spdif_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct rk_spdif_dev *spdif = snd_soc_dai_get_drvdata(dai);
unsigned int val = SPDIF_CFGR_HALFWORD_ENABLE;
int srate, mclk;
int ret;
srate = params_rate(params);
mclk = srate * 128;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
val |= SPDIF_CFGR_VDW_16;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
val |= SPDIF_CFGR_VDW_20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
val |= SPDIF_CFGR_VDW_24;
break;
default:
return -EINVAL;
}
ret = clk_set_rate(spdif->mclk, mclk);
if (ret != 0) {
dev_err(spdif->dev, "Failed to set module clock rate: %d\n",
ret);
return ret;
}
ret = regmap_update_bits(spdif->regmap, SPDIF_CFGR,
SPDIF_CFGR_CLK_DIV_MASK | SPDIF_CFGR_HALFWORD_ENABLE |
SDPIF_CFGR_VDW_MASK,
val);
return ret;
}
static int rk_spdif_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
struct rk_spdif_dev *spdif = snd_soc_dai_get_drvdata(dai);
int ret;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
ret = regmap_update_bits(spdif->regmap, SPDIF_DMACR,
SPDIF_DMACR_TDE_ENABLE |
SPDIF_DMACR_TDL_MASK,
SPDIF_DMACR_TDE_ENABLE |
SPDIF_DMACR_TDL(16));
if (ret != 0)
return ret;
ret = regmap_update_bits(spdif->regmap, SPDIF_XFER,
SPDIF_XFER_TXS_START,
SPDIF_XFER_TXS_START);
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
ret = regmap_update_bits(spdif->regmap, SPDIF_DMACR,
SPDIF_DMACR_TDE_ENABLE,
SPDIF_DMACR_TDE_DISABLE);
if (ret != 0)
return ret;
ret = regmap_update_bits(spdif->regmap, SPDIF_XFER,
SPDIF_XFER_TXS_START,
SPDIF_XFER_TXS_STOP);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int rk_spdif_dai_probe(struct snd_soc_dai *dai)
{
struct rk_spdif_dev *spdif = snd_soc_dai_get_drvdata(dai);
dai->playback_dma_data = &spdif->playback_dma_data;
return 0;
}
static bool rk_spdif_wr_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case SPDIF_CFGR:
case SPDIF_DMACR:
case SPDIF_INTCR:
case SPDIF_XFER:
case SPDIF_SMPDR:
return true;
default:
return false;
}
}
static bool rk_spdif_rd_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case SPDIF_CFGR:
case SPDIF_SDBLR:
case SPDIF_INTCR:
case SPDIF_INTSR:
case SPDIF_XFER:
return true;
default:
return false;
}
}
static bool rk_spdif_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case SPDIF_INTSR:
case SPDIF_SDBLR:
return true;
default:
return false;
}
}
static int rk_spdif_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct rk_spdif_dev *spdif;
const struct of_device_id *match;
struct resource *res;
void __iomem *regs;
int ret;
match = of_match_node(rk_spdif_match, np);
if (match->data == (void *)RK_SPDIF_RK3288) {
struct regmap *grf;
grf = syscon_regmap_lookup_by_phandle(np, "rockchip,grf");
if (IS_ERR(grf)) {
dev_err(&pdev->dev,
"rockchip_spdif missing 'rockchip,grf' \n");
return PTR_ERR(grf);
}
regmap_write(grf, RK3288_GRF_SOC_CON2, BIT(1) << 16);
}
spdif = devm_kzalloc(&pdev->dev, sizeof(*spdif), GFP_KERNEL);
if (!spdif)
return -ENOMEM;
spdif->hclk = devm_clk_get(&pdev->dev, "hclk");
if (IS_ERR(spdif->hclk)) {
dev_err(&pdev->dev, "Can't retrieve rk_spdif bus clock\n");
return PTR_ERR(spdif->hclk);
}
ret = clk_prepare_enable(spdif->hclk);
if (ret) {
dev_err(spdif->dev, "hclock enable failed %d\n", ret);
return ret;
}
spdif->mclk = devm_clk_get(&pdev->dev, "mclk");
if (IS_ERR(spdif->mclk)) {
dev_err(&pdev->dev, "Can't retrieve rk_spdif master clock\n");
return PTR_ERR(spdif->mclk);
}
ret = clk_prepare_enable(spdif->mclk);
if (ret) {
dev_err(spdif->dev, "clock enable failed %d\n", ret);
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
spdif->regmap = devm_regmap_init_mmio_clk(&pdev->dev, "hclk", regs,
&rk_spdif_regmap_config);
if (IS_ERR(spdif->regmap)) {
dev_err(&pdev->dev,
"Failed to initialise managed register map\n");
return PTR_ERR(spdif->regmap);
}
spdif->playback_dma_data.addr = res->start + SPDIF_SMPDR;
spdif->playback_dma_data.addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
spdif->playback_dma_data.maxburst = 4;
spdif->dev = &pdev->dev;
dev_set_drvdata(&pdev->dev, spdif);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
pm_request_idle(&pdev->dev);
ret = devm_snd_soc_register_component(&pdev->dev,
&rk_spdif_component,
&rk_spdif_dai, 1);
if (ret) {
dev_err(&pdev->dev, "Could not register DAI\n");
goto err_pm_runtime;
}
ret = devm_snd_dmaengine_pcm_register(&pdev->dev, NULL, 0);
if (ret) {
dev_err(&pdev->dev, "Could not register PCM\n");
goto err_pm_runtime;
}
return 0;
err_pm_runtime:
pm_runtime_disable(&pdev->dev);
return ret;
}
static int rk_spdif_remove(struct platform_device *pdev)
{
struct rk_spdif_dev *spdif = dev_get_drvdata(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
rk_spdif_runtime_suspend(&pdev->dev);
clk_disable_unprepare(spdif->mclk);
clk_disable_unprepare(spdif->hclk);
return 0;
}
