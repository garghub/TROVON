static unsigned int get_pdm_clk(unsigned int sr)
{
unsigned int i, count, clk, div;
clk = 0;
if (!sr)
return clk;
count = ARRAY_SIZE(clkref);
for (i = 0; i < count; i++) {
if (sr % clkref[i].sr)
continue;
div = sr / clkref[i].sr;
if ((div & (div - 1)) == 0) {
clk = clkref[i].clk;
break;
}
}
return clk;
}
static inline struct rk_pdm_dev *to_info(struct snd_soc_dai *dai)
{
return snd_soc_dai_get_drvdata(dai);
}
static void rockchip_pdm_rxctrl(struct rk_pdm_dev *pdm, int on)
{
if (on) {
regmap_update_bits(pdm->regmap, PDM_DMA_CTRL,
PDM_DMA_RD_MSK, PDM_DMA_RD_EN);
regmap_update_bits(pdm->regmap, PDM_SYSCONFIG,
PDM_RX_MASK, PDM_RX_START);
} else {
regmap_update_bits(pdm->regmap, PDM_DMA_CTRL,
PDM_DMA_RD_MSK, PDM_DMA_RD_DIS);
regmap_update_bits(pdm->regmap, PDM_SYSCONFIG,
PDM_RX_MASK | PDM_RX_CLR_MASK,
PDM_RX_STOP | PDM_RX_CLR_WR);
}
}
static int rockchip_pdm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct rk_pdm_dev *pdm = to_info(dai);
unsigned int val = 0;
unsigned int clk_rate, clk_div, samplerate;
int ret;
samplerate = params_rate(params);
clk_rate = get_pdm_clk(samplerate);
if (!clk_rate)
return -EINVAL;
ret = clk_set_rate(pdm->clk, clk_rate);
if (ret)
return -EINVAL;
clk_div = DIV_ROUND_CLOSEST(clk_rate, samplerate);
switch (clk_div) {
case 320:
val = PDM_CLK_320FS;
break;
case 640:
val = PDM_CLK_640FS;
break;
case 1280:
val = PDM_CLK_1280FS;
break;
case 2560:
val = PDM_CLK_2560FS;
break;
case 5120:
val = PDM_CLK_5120FS;
break;
default:
dev_err(pdm->dev, "unsupported div: %d\n", clk_div);
return -EINVAL;
}
regmap_update_bits(pdm->regmap, PDM_CLK_CTRL, PDM_DS_RATIO_MSK, val);
regmap_update_bits(pdm->regmap, PDM_HPF_CTRL,
PDM_HPF_CF_MSK, PDM_HPF_60HZ);
regmap_update_bits(pdm->regmap, PDM_HPF_CTRL,
PDM_HPF_LE | PDM_HPF_RE, PDM_HPF_LE | PDM_HPF_RE);
regmap_update_bits(pdm->regmap, PDM_CLK_CTRL, PDM_CLK_EN, PDM_CLK_EN);
val = 0;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
val |= PDM_VDW(8);
break;
case SNDRV_PCM_FORMAT_S16_LE:
val |= PDM_VDW(16);
break;
case SNDRV_PCM_FORMAT_S20_3LE:
val |= PDM_VDW(20);
break;
case SNDRV_PCM_FORMAT_S24_LE:
val |= PDM_VDW(24);
break;
case SNDRV_PCM_FORMAT_S32_LE:
val |= PDM_VDW(32);
break;
default:
return -EINVAL;
}
switch (params_channels(params)) {
case 8:
val |= PDM_PATH3_EN;
case 6:
val |= PDM_PATH2_EN;
case 4:
val |= PDM_PATH1_EN;
case 2:
val |= PDM_PATH0_EN;
break;
default:
dev_err(pdm->dev, "invalid channel: %d\n",
params_channels(params));
return -EINVAL;
}
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE) {
regmap_update_bits(pdm->regmap, PDM_CTRL0,
PDM_PATH_MSK | PDM_VDW_MSK,
val);
regmap_update_bits(pdm->regmap, PDM_DMA_CTRL, PDM_DMA_RDL_MSK,
PDM_DMA_RDL(16));
regmap_update_bits(pdm->regmap, PDM_SYSCONFIG,
PDM_RX_MASK | PDM_RX_CLR_MASK,
PDM_RX_STOP | PDM_RX_CLR_WR);
}
return 0;
}
static int rockchip_pdm_set_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct rk_pdm_dev *pdm = to_info(cpu_dai);
unsigned int mask = 0, val = 0;
mask = PDM_CKP_MSK;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
val = PDM_CKP_NORMAL;
break;
case SND_SOC_DAIFMT_IB_NF:
val = PDM_CKP_INVERTED;
break;
default:
return -EINVAL;
}
regmap_update_bits(pdm->regmap, PDM_CLK_CTRL, mask, val);
return 0;
}
static int rockchip_pdm_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct rk_pdm_dev *pdm = to_info(dai);
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
rockchip_pdm_rxctrl(pdm, 1);
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
rockchip_pdm_rxctrl(pdm, 0);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int rockchip_pdm_dai_probe(struct snd_soc_dai *dai)
{
struct rk_pdm_dev *pdm = to_info(dai);
dai->capture_dma_data = &pdm->capture_dma_data;
return 0;
}
static int rockchip_pdm_runtime_suspend(struct device *dev)
{
struct rk_pdm_dev *pdm = dev_get_drvdata(dev);
clk_disable_unprepare(pdm->clk);
clk_disable_unprepare(pdm->hclk);
return 0;
}
static int rockchip_pdm_runtime_resume(struct device *dev)
{
struct rk_pdm_dev *pdm = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(pdm->clk);
if (ret) {
dev_err(pdm->dev, "clock enable failed %d\n", ret);
return ret;
}
ret = clk_prepare_enable(pdm->hclk);
if (ret) {
dev_err(pdm->dev, "hclock enable failed %d\n", ret);
return ret;
}
return 0;
}
static bool rockchip_pdm_wr_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case PDM_SYSCONFIG:
case PDM_CTRL0:
case PDM_CTRL1:
case PDM_CLK_CTRL:
case PDM_HPF_CTRL:
case PDM_FIFO_CTRL:
case PDM_DMA_CTRL:
case PDM_INT_EN:
case PDM_INT_CLR:
case PDM_DATA_VALID:
return true;
default:
return false;
}
}
static bool rockchip_pdm_rd_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case PDM_SYSCONFIG:
case PDM_CTRL0:
case PDM_CTRL1:
case PDM_CLK_CTRL:
case PDM_HPF_CTRL:
case PDM_FIFO_CTRL:
case PDM_DMA_CTRL:
case PDM_INT_EN:
case PDM_INT_CLR:
case PDM_INT_ST:
case PDM_DATA_VALID:
case PDM_VERSION:
return true;
default:
return false;
}
}
static bool rockchip_pdm_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case PDM_SYSCONFIG:
case PDM_INT_CLR:
case PDM_INT_ST:
return true;
default:
return false;
}
}
static int rockchip_pdm_probe(struct platform_device *pdev)
{
struct rk_pdm_dev *pdm;
struct resource *res;
void __iomem *regs;
int ret;
pdm = devm_kzalloc(&pdev->dev, sizeof(*pdm), GFP_KERNEL);
if (!pdm)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
pdm->regmap = devm_regmap_init_mmio(&pdev->dev, regs,
&rockchip_pdm_regmap_config);
if (IS_ERR(pdm->regmap))
return PTR_ERR(pdm->regmap);
pdm->capture_dma_data.addr = res->start + PDM_RXFIFO_DATA;
pdm->capture_dma_data.addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
pdm->capture_dma_data.maxburst = PDM_DMA_BURST_SIZE;
pdm->dev = &pdev->dev;
dev_set_drvdata(&pdev->dev, pdm);
pdm->clk = devm_clk_get(&pdev->dev, "pdm_clk");
if (IS_ERR(pdm->clk))
return PTR_ERR(pdm->clk);
pdm->hclk = devm_clk_get(&pdev->dev, "pdm_hclk");
if (IS_ERR(pdm->hclk))
return PTR_ERR(pdm->hclk);
ret = clk_prepare_enable(pdm->hclk);
if (ret)
return ret;
pm_runtime_enable(&pdev->dev);
if (!pm_runtime_enabled(&pdev->dev)) {
ret = rockchip_pdm_runtime_resume(&pdev->dev);
if (ret)
goto err_pm_disable;
}
ret = devm_snd_soc_register_component(&pdev->dev,
&rockchip_pdm_component,
&rockchip_pdm_dai, 1);
if (ret) {
dev_err(&pdev->dev, "could not register dai: %d\n", ret);
goto err_suspend;
}
ret = devm_snd_dmaengine_pcm_register(&pdev->dev, NULL, 0);
if (ret) {
dev_err(&pdev->dev, "could not register pcm: %d\n", ret);
goto err_suspend;
}
return 0;
err_suspend:
if (!pm_runtime_status_suspended(&pdev->dev))
rockchip_pdm_runtime_suspend(&pdev->dev);
err_pm_disable:
pm_runtime_disable(&pdev->dev);
clk_disable_unprepare(pdm->hclk);
return ret;
}
static int rockchip_pdm_remove(struct platform_device *pdev)
{
struct rk_pdm_dev *pdm = dev_get_drvdata(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
rockchip_pdm_runtime_suspend(&pdev->dev);
clk_disable_unprepare(pdm->clk);
clk_disable_unprepare(pdm->hclk);
return 0;
}
static int rockchip_pdm_suspend(struct device *dev)
{
struct rk_pdm_dev *pdm = dev_get_drvdata(dev);
regcache_mark_dirty(pdm->regmap);
return 0;
}
static int rockchip_pdm_resume(struct device *dev)
{
struct rk_pdm_dev *pdm = dev_get_drvdata(dev);
int ret;
ret = pm_runtime_get_sync(dev);
if (ret < 0)
return ret;
ret = regcache_sync(pdm->regmap);
pm_runtime_put(dev);
return ret;
}
