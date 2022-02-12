static int sun4i_i2s_get_bclk_div(struct sun4i_i2s *i2s,
unsigned int oversample_rate,
unsigned int word_size)
{
int div = oversample_rate / word_size / 2;
int i;
for (i = 0; i < ARRAY_SIZE(sun4i_i2s_bclk_div); i++) {
const struct sun4i_i2s_clk_div *bdiv = &sun4i_i2s_bclk_div[i];
if (bdiv->div == div)
return bdiv->val;
}
return -EINVAL;
}
static int sun4i_i2s_get_mclk_div(struct sun4i_i2s *i2s,
unsigned int oversample_rate,
unsigned int module_rate,
unsigned int sampling_rate)
{
int div = module_rate / sampling_rate / oversample_rate;
int i;
for (i = 0; i < ARRAY_SIZE(sun4i_i2s_mclk_div); i++) {
const struct sun4i_i2s_clk_div *mdiv = &sun4i_i2s_mclk_div[i];
if (mdiv->div == div)
return mdiv->val;
}
return -EINVAL;
}
static int sun4i_i2s_set_clk_rate(struct sun4i_i2s *i2s,
unsigned int rate,
unsigned int word_size)
{
unsigned int clk_rate;
int bclk_div, mclk_div;
int ret, i;
switch (rate) {
case 176400:
case 88200:
case 44100:
case 22050:
case 11025:
clk_rate = 22579200;
break;
case 192000:
case 128000:
case 96000:
case 64000:
case 48000:
case 32000:
case 24000:
case 16000:
case 12000:
case 8000:
clk_rate = 24576000;
break;
default:
return -EINVAL;
}
ret = clk_set_rate(i2s->mod_clk, clk_rate);
if (ret)
return ret;
for (i = (ARRAY_SIZE(sun4i_i2s_oversample_rates) - 1); i >= 0; i--) {
unsigned int oversample_rate = sun4i_i2s_oversample_rates[i];
bclk_div = sun4i_i2s_get_bclk_div(i2s, oversample_rate,
word_size);
mclk_div = sun4i_i2s_get_mclk_div(i2s, oversample_rate,
clk_rate,
rate);
if ((bclk_div >= 0) && (mclk_div >= 0))
break;
}
if ((bclk_div < 0) || (mclk_div < 0))
return -EINVAL;
regmap_write(i2s->regmap, SUN4I_I2S_CLK_DIV_REG,
SUN4I_I2S_CLK_DIV_BCLK(bclk_div) |
SUN4I_I2S_CLK_DIV_MCLK(mclk_div) |
SUN4I_I2S_CLK_DIV_MCLK_EN);
return 0;
}
static int sun4i_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct sun4i_i2s *i2s = snd_soc_dai_get_drvdata(dai);
int sr, wss;
u32 width;
if (params_channels(params) != 2)
return -EINVAL;
switch (params_physical_width(params)) {
case 16:
width = DMA_SLAVE_BUSWIDTH_2_BYTES;
break;
default:
return -EINVAL;
}
i2s->playback_dma_data.addr_width = width;
switch (params_width(params)) {
case 16:
sr = 0;
wss = 0;
break;
default:
return -EINVAL;
}
regmap_update_bits(i2s->regmap, SUN4I_I2S_FMT0_REG,
SUN4I_I2S_FMT0_WSS_MASK | SUN4I_I2S_FMT0_SR_MASK,
SUN4I_I2S_FMT0_WSS(wss) | SUN4I_I2S_FMT0_SR(sr));
return sun4i_i2s_set_clk_rate(i2s, params_rate(params),
params_width(params));
}
static int sun4i_i2s_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct sun4i_i2s *i2s = snd_soc_dai_get_drvdata(dai);
u32 val;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
val = SUN4I_I2S_FMT0_FMT_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
val = SUN4I_I2S_FMT0_FMT_LEFT_J;
break;
case SND_SOC_DAIFMT_RIGHT_J:
val = SUN4I_I2S_FMT0_FMT_RIGHT_J;
break;
default:
return -EINVAL;
}
regmap_update_bits(i2s->regmap, SUN4I_I2S_FMT0_REG,
SUN4I_I2S_FMT0_FMT_MASK,
val);
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_IF:
val = SUN4I_I2S_FMT0_BCLK_POLARITY_INVERTED |
SUN4I_I2S_FMT0_LRCLK_POLARITY_INVERTED;
break;
case SND_SOC_DAIFMT_IB_NF:
val = SUN4I_I2S_FMT0_BCLK_POLARITY_INVERTED |
SUN4I_I2S_FMT0_LRCLK_POLARITY_NORMAL;
break;
case SND_SOC_DAIFMT_NB_IF:
val = SUN4I_I2S_FMT0_LRCLK_POLARITY_INVERTED |
SUN4I_I2S_FMT0_BCLK_POLARITY_NORMAL;
break;
case SND_SOC_DAIFMT_NB_NF:
val = SUN4I_I2S_FMT0_BCLK_POLARITY_NORMAL |
SUN4I_I2S_FMT0_LRCLK_POLARITY_NORMAL;
break;
default:
return -EINVAL;
}
regmap_update_bits(i2s->regmap, SUN4I_I2S_FMT0_REG,
SUN4I_I2S_FMT0_BCLK_POLARITY_MASK |
SUN4I_I2S_FMT0_LRCLK_POLARITY_MASK,
val);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
val = SUN4I_I2S_CTRL_MODE_MASTER;
break;
case SND_SOC_DAIFMT_CBM_CFM:
val = SUN4I_I2S_CTRL_MODE_SLAVE;
break;
default:
return -EINVAL;
}
regmap_update_bits(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN4I_I2S_CTRL_MODE_MASK,
val);
regmap_update_bits(i2s->regmap, SUN4I_I2S_FIFO_CTRL_REG,
SUN4I_I2S_FIFO_CTRL_TX_MODE_MASK |
SUN4I_I2S_FIFO_CTRL_RX_MODE_MASK,
SUN4I_I2S_FIFO_CTRL_TX_MODE(1) |
SUN4I_I2S_FIFO_CTRL_RX_MODE(1));
return 0;
}
static void sun4i_i2s_start_playback(struct sun4i_i2s *i2s)
{
regmap_update_bits(i2s->regmap, SUN4I_I2S_FIFO_CTRL_REG,
SUN4I_I2S_FIFO_CTRL_FLUSH_TX,
SUN4I_I2S_FIFO_CTRL_FLUSH_TX);
regmap_write(i2s->regmap, SUN4I_I2S_TX_CNT_REG, 0);
regmap_update_bits(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN4I_I2S_CTRL_TX_EN,
SUN4I_I2S_CTRL_TX_EN);
regmap_update_bits(i2s->regmap, SUN4I_I2S_DMA_INT_CTRL_REG,
SUN4I_I2S_DMA_INT_CTRL_TX_DRQ_EN,
SUN4I_I2S_DMA_INT_CTRL_TX_DRQ_EN);
}
static void sun4i_i2s_stop_playback(struct sun4i_i2s *i2s)
{
regmap_update_bits(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN4I_I2S_CTRL_TX_EN,
0);
regmap_update_bits(i2s->regmap, SUN4I_I2S_DMA_INT_CTRL_REG,
SUN4I_I2S_DMA_INT_CTRL_TX_DRQ_EN,
0);
}
static int sun4i_i2s_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct sun4i_i2s *i2s = snd_soc_dai_get_drvdata(dai);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
sun4i_i2s_start_playback(i2s);
else
return -EINVAL;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
sun4i_i2s_stop_playback(i2s);
else
return -EINVAL;
break;
default:
return -EINVAL;
}
return 0;
}
static int sun4i_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sun4i_i2s *i2s = snd_soc_dai_get_drvdata(dai);
regmap_write(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN4I_I2S_CTRL_GL_EN);
regmap_update_bits(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN4I_I2S_CTRL_SDO_EN_MASK,
SUN4I_I2S_CTRL_SDO_EN(0));
regmap_write(i2s->regmap, SUN4I_I2S_TX_CHAN_SEL_REG,
SUN4I_I2S_TX_CHAN_SEL(2));
regmap_write(i2s->regmap, SUN4I_I2S_TX_CHAN_MAP_REG,
SUN4I_I2S_TX_CHAN_MAP(0, 0) | SUN4I_I2S_TX_CHAN_MAP(1, 1));
return clk_prepare_enable(i2s->mod_clk);
}
static void sun4i_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sun4i_i2s *i2s = snd_soc_dai_get_drvdata(dai);
clk_disable_unprepare(i2s->mod_clk);
regmap_update_bits(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN4I_I2S_CTRL_SDO_EN_MASK, 0);
regmap_write(i2s->regmap, SUN4I_I2S_CTRL_REG, 0);
}
static int sun4i_i2s_dai_probe(struct snd_soc_dai *dai)
{
struct sun4i_i2s *i2s = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_init_dma_data(dai, &i2s->playback_dma_data, NULL);
snd_soc_dai_set_drvdata(dai, i2s);
return 0;
}
static bool sun4i_i2s_rd_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case SUN4I_I2S_FIFO_TX_REG:
return false;
default:
return true;
}
}
static bool sun4i_i2s_wr_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case SUN4I_I2S_FIFO_RX_REG:
case SUN4I_I2S_FIFO_STA_REG:
return false;
default:
return true;
}
}
static bool sun4i_i2s_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case SUN4I_I2S_FIFO_RX_REG:
case SUN4I_I2S_INT_STA_REG:
case SUN4I_I2S_RX_CNT_REG:
case SUN4I_I2S_TX_CNT_REG:
return true;
default:
return false;
}
}
static int sun4i_i2s_runtime_resume(struct device *dev)
{
struct sun4i_i2s *i2s = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(i2s->bus_clk);
if (ret) {
dev_err(dev, "Failed to enable bus clock\n");
return ret;
}
regcache_cache_only(i2s->regmap, false);
regcache_mark_dirty(i2s->regmap);
ret = regcache_sync(i2s->regmap);
if (ret) {
dev_err(dev, "Failed to sync regmap cache\n");
goto err_disable_clk;
}
return 0;
err_disable_clk:
clk_disable_unprepare(i2s->bus_clk);
return ret;
}
static int sun4i_i2s_runtime_suspend(struct device *dev)
{
struct sun4i_i2s *i2s = dev_get_drvdata(dev);
regcache_cache_only(i2s->regmap, true);
clk_disable_unprepare(i2s->bus_clk);
return 0;
}
static int sun4i_i2s_probe(struct platform_device *pdev)
{
struct sun4i_i2s *i2s;
struct resource *res;
void __iomem *regs;
int irq, ret;
i2s = devm_kzalloc(&pdev->dev, sizeof(*i2s), GFP_KERNEL);
if (!i2s)
return -ENOMEM;
platform_set_drvdata(pdev, i2s);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "Can't retrieve our interrupt\n");
return irq;
}
i2s->bus_clk = devm_clk_get(&pdev->dev, "apb");
if (IS_ERR(i2s->bus_clk)) {
dev_err(&pdev->dev, "Can't get our bus clock\n");
return PTR_ERR(i2s->bus_clk);
}
i2s->regmap = devm_regmap_init_mmio(&pdev->dev, regs,
&sun4i_i2s_regmap_config);
if (IS_ERR(i2s->regmap)) {
dev_err(&pdev->dev, "Regmap initialisation failed\n");
return PTR_ERR(i2s->regmap);
}
i2s->mod_clk = devm_clk_get(&pdev->dev, "mod");
if (IS_ERR(i2s->mod_clk)) {
dev_err(&pdev->dev, "Can't get our mod clock\n");
return PTR_ERR(i2s->mod_clk);
}
i2s->playback_dma_data.addr = res->start + SUN4I_I2S_FIFO_TX_REG;
i2s->playback_dma_data.maxburst = 4;
pm_runtime_enable(&pdev->dev);
if (!pm_runtime_enabled(&pdev->dev)) {
ret = sun4i_i2s_runtime_resume(&pdev->dev);
if (ret)
goto err_pm_disable;
}
ret = devm_snd_soc_register_component(&pdev->dev,
&sun4i_i2s_component,
&sun4i_i2s_dai, 1);
if (ret) {
dev_err(&pdev->dev, "Could not register DAI\n");
goto err_suspend;
}
ret = snd_dmaengine_pcm_register(&pdev->dev, NULL, 0);
if (ret) {
dev_err(&pdev->dev, "Could not register PCM\n");
goto err_suspend;
}
return 0;
err_suspend:
if (!pm_runtime_status_suspended(&pdev->dev))
sun4i_i2s_runtime_suspend(&pdev->dev);
err_pm_disable:
pm_runtime_disable(&pdev->dev);
return ret;
}
static int sun4i_i2s_remove(struct platform_device *pdev)
{
snd_dmaengine_pcm_unregister(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
sun4i_i2s_runtime_suspend(&pdev->dev);
return 0;
}
