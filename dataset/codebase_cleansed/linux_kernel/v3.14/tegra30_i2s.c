static int tegra30_i2s_runtime_suspend(struct device *dev)
{
struct tegra30_i2s *i2s = dev_get_drvdata(dev);
regcache_cache_only(i2s->regmap, true);
clk_disable_unprepare(i2s->clk_i2s);
return 0;
}
static int tegra30_i2s_runtime_resume(struct device *dev)
{
struct tegra30_i2s *i2s = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(i2s->clk_i2s);
if (ret) {
dev_err(dev, "clk_enable failed: %d\n", ret);
return ret;
}
regcache_cache_only(i2s->regmap, false);
return 0;
}
static int tegra30_i2s_set_fmt(struct snd_soc_dai *dai,
unsigned int fmt)
{
struct tegra30_i2s *i2s = snd_soc_dai_get_drvdata(dai);
unsigned int mask = 0, val = 0;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
default:
return -EINVAL;
}
mask |= TEGRA30_I2S_CTRL_MASTER_ENABLE;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
val |= TEGRA30_I2S_CTRL_MASTER_ENABLE;
break;
case SND_SOC_DAIFMT_CBM_CFM:
break;
default:
return -EINVAL;
}
mask |= TEGRA30_I2S_CTRL_FRAME_FORMAT_MASK |
TEGRA30_I2S_CTRL_LRCK_MASK;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
val |= TEGRA30_I2S_CTRL_FRAME_FORMAT_FSYNC;
val |= TEGRA30_I2S_CTRL_LRCK_L_LOW;
break;
case SND_SOC_DAIFMT_DSP_B:
val |= TEGRA30_I2S_CTRL_FRAME_FORMAT_FSYNC;
val |= TEGRA30_I2S_CTRL_LRCK_R_LOW;
break;
case SND_SOC_DAIFMT_I2S:
val |= TEGRA30_I2S_CTRL_FRAME_FORMAT_LRCK;
val |= TEGRA30_I2S_CTRL_LRCK_L_LOW;
break;
case SND_SOC_DAIFMT_RIGHT_J:
val |= TEGRA30_I2S_CTRL_FRAME_FORMAT_LRCK;
val |= TEGRA30_I2S_CTRL_LRCK_L_LOW;
break;
case SND_SOC_DAIFMT_LEFT_J:
val |= TEGRA30_I2S_CTRL_FRAME_FORMAT_LRCK;
val |= TEGRA30_I2S_CTRL_LRCK_L_LOW;
break;
default:
return -EINVAL;
}
pm_runtime_get_sync(dai->dev);
regmap_update_bits(i2s->regmap, TEGRA30_I2S_CTRL, mask, val);
pm_runtime_put(dai->dev);
return 0;
}
static int tegra30_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct device *dev = dai->dev;
struct tegra30_i2s *i2s = snd_soc_dai_get_drvdata(dai);
unsigned int mask, val, reg;
int ret, sample_size, srate, i2sclock, bitcnt;
struct tegra30_ahub_cif_conf cif_conf;
if (params_channels(params) != 2)
return -EINVAL;
mask = TEGRA30_I2S_CTRL_BIT_SIZE_MASK;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
val = TEGRA30_I2S_CTRL_BIT_SIZE_16;
sample_size = 16;
break;
default:
return -EINVAL;
}
regmap_update_bits(i2s->regmap, TEGRA30_I2S_CTRL, mask, val);
srate = params_rate(params);
i2sclock = srate * params_channels(params) * sample_size * 2;
bitcnt = (i2sclock / (2 * srate)) - 1;
if (bitcnt < 0 || bitcnt > TEGRA30_I2S_TIMING_CHANNEL_BIT_COUNT_MASK_US)
return -EINVAL;
ret = clk_set_rate(i2s->clk_i2s, i2sclock);
if (ret) {
dev_err(dev, "Can't set I2S clock rate: %d\n", ret);
return ret;
}
val = bitcnt << TEGRA30_I2S_TIMING_CHANNEL_BIT_COUNT_SHIFT;
if (i2sclock % (2 * srate))
val |= TEGRA30_I2S_TIMING_NON_SYM_ENABLE;
regmap_write(i2s->regmap, TEGRA30_I2S_TIMING, val);
cif_conf.threshold = 0;
cif_conf.audio_channels = 2;
cif_conf.client_channels = 2;
cif_conf.audio_bits = TEGRA30_AUDIOCIF_BITS_16;
cif_conf.client_bits = TEGRA30_AUDIOCIF_BITS_16;
cif_conf.expand = 0;
cif_conf.stereo_conv = 0;
cif_conf.replicate = 0;
cif_conf.truncate = 0;
cif_conf.mono_conv = 0;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
cif_conf.direction = TEGRA30_AUDIOCIF_DIRECTION_RX;
reg = TEGRA30_I2S_CIF_RX_CTRL;
} else {
cif_conf.direction = TEGRA30_AUDIOCIF_DIRECTION_TX;
reg = TEGRA30_I2S_CIF_TX_CTRL;
}
i2s->soc_data->set_audio_cif(i2s->regmap, reg, &cif_conf);
val = (1 << TEGRA30_I2S_OFFSET_RX_DATA_OFFSET_SHIFT) |
(1 << TEGRA30_I2S_OFFSET_TX_DATA_OFFSET_SHIFT);
regmap_write(i2s->regmap, TEGRA30_I2S_OFFSET, val);
return 0;
}
static void tegra30_i2s_start_playback(struct tegra30_i2s *i2s)
{
tegra30_ahub_enable_tx_fifo(i2s->playback_fifo_cif);
regmap_update_bits(i2s->regmap, TEGRA30_I2S_CTRL,
TEGRA30_I2S_CTRL_XFER_EN_TX,
TEGRA30_I2S_CTRL_XFER_EN_TX);
}
static void tegra30_i2s_stop_playback(struct tegra30_i2s *i2s)
{
tegra30_ahub_disable_tx_fifo(i2s->playback_fifo_cif);
regmap_update_bits(i2s->regmap, TEGRA30_I2S_CTRL,
TEGRA30_I2S_CTRL_XFER_EN_TX, 0);
}
static void tegra30_i2s_start_capture(struct tegra30_i2s *i2s)
{
tegra30_ahub_enable_rx_fifo(i2s->capture_fifo_cif);
regmap_update_bits(i2s->regmap, TEGRA30_I2S_CTRL,
TEGRA30_I2S_CTRL_XFER_EN_RX,
TEGRA30_I2S_CTRL_XFER_EN_RX);
}
static void tegra30_i2s_stop_capture(struct tegra30_i2s *i2s)
{
tegra30_ahub_disable_rx_fifo(i2s->capture_fifo_cif);
regmap_update_bits(i2s->regmap, TEGRA30_I2S_CTRL,
TEGRA30_I2S_CTRL_XFER_EN_RX, 0);
}
static int tegra30_i2s_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct tegra30_i2s *i2s = snd_soc_dai_get_drvdata(dai);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
tegra30_i2s_start_playback(i2s);
else
tegra30_i2s_start_capture(i2s);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
tegra30_i2s_stop_playback(i2s);
else
tegra30_i2s_stop_capture(i2s);
break;
default:
return -EINVAL;
}
return 0;
}
static int tegra30_i2s_probe(struct snd_soc_dai *dai)
{
struct tegra30_i2s *i2s = snd_soc_dai_get_drvdata(dai);
dai->capture_dma_data = &i2s->capture_dma_data;
dai->playback_dma_data = &i2s->playback_dma_data;
return 0;
}
static bool tegra30_i2s_wr_rd_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TEGRA30_I2S_CTRL:
case TEGRA30_I2S_TIMING:
case TEGRA30_I2S_OFFSET:
case TEGRA30_I2S_CH_CTRL:
case TEGRA30_I2S_SLOT_CTRL:
case TEGRA30_I2S_CIF_RX_CTRL:
case TEGRA30_I2S_CIF_TX_CTRL:
case TEGRA30_I2S_FLOWCTL:
case TEGRA30_I2S_TX_STEP:
case TEGRA30_I2S_FLOW_STATUS:
case TEGRA30_I2S_FLOW_TOTAL:
case TEGRA30_I2S_FLOW_OVER:
case TEGRA30_I2S_FLOW_UNDER:
case TEGRA30_I2S_LCOEF_1_4_0:
case TEGRA30_I2S_LCOEF_1_4_1:
case TEGRA30_I2S_LCOEF_1_4_2:
case TEGRA30_I2S_LCOEF_1_4_3:
case TEGRA30_I2S_LCOEF_1_4_4:
case TEGRA30_I2S_LCOEF_1_4_5:
case TEGRA30_I2S_LCOEF_2_4_0:
case TEGRA30_I2S_LCOEF_2_4_1:
case TEGRA30_I2S_LCOEF_2_4_2:
return true;
default:
return false;
}
}
static bool tegra30_i2s_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TEGRA30_I2S_FLOW_STATUS:
case TEGRA30_I2S_FLOW_TOTAL:
case TEGRA30_I2S_FLOW_OVER:
case TEGRA30_I2S_FLOW_UNDER:
return true;
default:
return false;
}
}
static int tegra30_i2s_platform_probe(struct platform_device *pdev)
{
struct tegra30_i2s *i2s;
const struct of_device_id *match;
u32 cif_ids[2];
struct resource *mem, *memregion;
void __iomem *regs;
int ret;
i2s = devm_kzalloc(&pdev->dev, sizeof(struct tegra30_i2s), GFP_KERNEL);
if (!i2s) {
dev_err(&pdev->dev, "Can't allocate tegra30_i2s\n");
ret = -ENOMEM;
goto err;
}
dev_set_drvdata(&pdev->dev, i2s);
match = of_match_device(tegra30_i2s_of_match, &pdev->dev);
if (!match) {
dev_err(&pdev->dev, "Error: No device match found\n");
ret = -ENODEV;
goto err;
}
i2s->soc_data = (struct tegra30_i2s_soc_data *)match->data;
i2s->dai = tegra30_i2s_dai_template;
i2s->dai.name = dev_name(&pdev->dev);
ret = of_property_read_u32_array(pdev->dev.of_node,
"nvidia,ahub-cif-ids", cif_ids,
ARRAY_SIZE(cif_ids));
if (ret < 0)
goto err;
i2s->playback_i2s_cif = cif_ids[0];
i2s->capture_i2s_cif = cif_ids[1];
i2s->clk_i2s = clk_get(&pdev->dev, NULL);
if (IS_ERR(i2s->clk_i2s)) {
dev_err(&pdev->dev, "Can't retrieve i2s clock\n");
ret = PTR_ERR(i2s->clk_i2s);
goto err;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "No memory resource\n");
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
i2s->regmap = devm_regmap_init_mmio(&pdev->dev, regs,
&tegra30_i2s_regmap_config);
if (IS_ERR(i2s->regmap)) {
dev_err(&pdev->dev, "regmap init failed\n");
ret = PTR_ERR(i2s->regmap);
goto err_clk_put;
}
regcache_cache_only(i2s->regmap, true);
pm_runtime_enable(&pdev->dev);
if (!pm_runtime_enabled(&pdev->dev)) {
ret = tegra30_i2s_runtime_resume(&pdev->dev);
if (ret)
goto err_pm_disable;
}
i2s->playback_dma_data.addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
i2s->playback_dma_data.maxburst = 4;
ret = tegra30_ahub_allocate_tx_fifo(&i2s->playback_fifo_cif,
i2s->playback_dma_chan,
sizeof(i2s->playback_dma_chan),
&i2s->playback_dma_data.addr);
if (ret) {
dev_err(&pdev->dev, "Could not alloc TX FIFO: %d\n", ret);
goto err_suspend;
}
ret = tegra30_ahub_set_rx_cif_source(i2s->playback_i2s_cif,
i2s->playback_fifo_cif);
if (ret) {
dev_err(&pdev->dev, "Could not route TX FIFO: %d\n", ret);
goto err_free_tx_fifo;
}
i2s->capture_dma_data.addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
i2s->capture_dma_data.maxburst = 4;
ret = tegra30_ahub_allocate_rx_fifo(&i2s->capture_fifo_cif,
i2s->capture_dma_chan,
sizeof(i2s->capture_dma_chan),
&i2s->capture_dma_data.addr);
if (ret) {
dev_err(&pdev->dev, "Could not alloc RX FIFO: %d\n", ret);
goto err_unroute_tx_fifo;
}
ret = tegra30_ahub_set_rx_cif_source(i2s->capture_fifo_cif,
i2s->capture_i2s_cif);
if (ret) {
dev_err(&pdev->dev, "Could not route TX FIFO: %d\n", ret);
goto err_free_rx_fifo;
}
ret = snd_soc_register_component(&pdev->dev, &tegra30_i2s_component,
&i2s->dai, 1);
if (ret) {
dev_err(&pdev->dev, "Could not register DAI: %d\n", ret);
ret = -ENOMEM;
goto err_unroute_rx_fifo;
}
ret = tegra_pcm_platform_register_with_chan_names(&pdev->dev,
&i2s->dma_config, i2s->playback_dma_chan,
i2s->capture_dma_chan);
if (ret) {
dev_err(&pdev->dev, "Could not register PCM: %d\n", ret);
goto err_unregister_component;
}
return 0;
err_unregister_component:
snd_soc_unregister_component(&pdev->dev);
err_unroute_rx_fifo:
tegra30_ahub_unset_rx_cif_source(i2s->capture_fifo_cif);
err_free_rx_fifo:
tegra30_ahub_free_rx_fifo(i2s->capture_fifo_cif);
err_unroute_tx_fifo:
tegra30_ahub_unset_rx_cif_source(i2s->playback_i2s_cif);
err_free_tx_fifo:
tegra30_ahub_free_tx_fifo(i2s->playback_fifo_cif);
err_suspend:
if (!pm_runtime_status_suspended(&pdev->dev))
tegra30_i2s_runtime_suspend(&pdev->dev);
err_pm_disable:
pm_runtime_disable(&pdev->dev);
err_clk_put:
clk_put(i2s->clk_i2s);
err:
return ret;
}
static int tegra30_i2s_platform_remove(struct platform_device *pdev)
{
struct tegra30_i2s *i2s = dev_get_drvdata(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
tegra30_i2s_runtime_suspend(&pdev->dev);
tegra_pcm_platform_unregister(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
tegra30_ahub_unset_rx_cif_source(i2s->capture_fifo_cif);
tegra30_ahub_free_rx_fifo(i2s->capture_fifo_cif);
tegra30_ahub_unset_rx_cif_source(i2s->playback_i2s_cif);
tegra30_ahub_free_tx_fifo(i2s->playback_fifo_cif);
clk_put(i2s->clk_i2s);
return 0;
}
static int tegra30_i2s_suspend(struct device *dev)
{
struct tegra30_i2s *i2s = dev_get_drvdata(dev);
regcache_mark_dirty(i2s->regmap);
return 0;
}
static int tegra30_i2s_resume(struct device *dev)
{
struct tegra30_i2s *i2s = dev_get_drvdata(dev);
int ret;
ret = pm_runtime_get_sync(dev);
if (ret < 0)
return ret;
ret = regcache_sync(i2s->regmap);
pm_runtime_put(dev);
return ret;
}
