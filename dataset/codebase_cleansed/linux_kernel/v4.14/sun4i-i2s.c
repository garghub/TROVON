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
static bool sun4i_i2s_oversample_is_valid(unsigned int oversample)
{
int i;
for (i = 0; i < ARRAY_SIZE(sun4i_i2s_oversample_rates); i++)
if (sun4i_i2s_oversample_rates[i] == oversample)
return true;
return false;
}
static int sun4i_i2s_set_clk_rate(struct sun4i_i2s *i2s,
unsigned int rate,
unsigned int word_size)
{
unsigned int oversample_rate, clk_rate;
int bclk_div, mclk_div;
int ret;
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
oversample_rate = i2s->mclk_freq / rate;
if (!sun4i_i2s_oversample_is_valid(oversample_rate))
return -EINVAL;
bclk_div = sun4i_i2s_get_bclk_div(i2s, oversample_rate,
word_size);
if (bclk_div < 0)
return -EINVAL;
mclk_div = sun4i_i2s_get_mclk_div(i2s, oversample_rate,
clk_rate, rate);
if (mclk_div < 0)
return -EINVAL;
bclk_div += i2s->variant->bclk_offset;
mclk_div += i2s->variant->mclk_offset;
regmap_write(i2s->regmap, SUN4I_I2S_CLK_DIV_REG,
SUN4I_I2S_CLK_DIV_BCLK(bclk_div) |
SUN4I_I2S_CLK_DIV_MCLK(mclk_div));
regmap_field_write(i2s->field_clkdiv_mclk_en, 1);
if (i2s->variant->has_fmt_set_lrck_period)
regmap_update_bits(i2s->regmap, SUN4I_I2S_FMT0_REG,
SUN8I_I2S_FMT0_LRCK_PERIOD_MASK,
SUN8I_I2S_FMT0_LRCK_PERIOD(32));
return 0;
}
static int sun4i_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct sun4i_i2s *i2s = snd_soc_dai_get_drvdata(dai);
int sr, wss, channels;
u32 width;
channels = params_channels(params);
if (channels != 2)
return -EINVAL;
if (i2s->variant->has_chcfg) {
regmap_update_bits(i2s->regmap, SUN8I_I2S_CHAN_CFG_REG,
SUN8I_I2S_CHAN_CFG_TX_SLOT_NUM_MASK,
SUN8I_I2S_CHAN_CFG_TX_SLOT_NUM(channels));
regmap_update_bits(i2s->regmap, SUN8I_I2S_CHAN_CFG_REG,
SUN8I_I2S_CHAN_CFG_RX_SLOT_NUM_MASK,
SUN8I_I2S_CHAN_CFG_RX_SLOT_NUM(channels));
}
regmap_field_write(i2s->field_txchanmap, 0x76543210);
regmap_field_write(i2s->field_rxchanmap, 0x00003210);
regmap_field_write(i2s->field_txchansel,
SUN4I_I2S_CHAN_SEL(params_channels(params)));
regmap_field_write(i2s->field_rxchansel,
SUN4I_I2S_CHAN_SEL(params_channels(params)));
if (i2s->variant->has_chsel_tx_chen)
regmap_update_bits(i2s->regmap, SUN8I_I2S_TX_CHAN_SEL_REG,
SUN8I_I2S_TX_CHAN_EN_MASK,
SUN8I_I2S_TX_CHAN_EN(channels));
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
regmap_field_write(i2s->field_fmt_wss,
wss + i2s->variant->fmt_offset);
regmap_field_write(i2s->field_fmt_sr,
sr + i2s->variant->fmt_offset);
return sun4i_i2s_set_clk_rate(i2s, params_rate(params),
params_width(params));
}
static int sun4i_i2s_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct sun4i_i2s *i2s = snd_soc_dai_get_drvdata(dai);
u32 val;
u32 offset = 0;
u32 bclk_polarity = SUN4I_I2S_FMT0_POLARITY_NORMAL;
u32 lrclk_polarity = SUN4I_I2S_FMT0_POLARITY_NORMAL;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
val = SUN4I_I2S_FMT0_FMT_I2S;
offset = 1;
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
if (i2s->variant->has_chsel_offset) {
if (offset > 0)
val++;
regmap_update_bits(i2s->regmap, SUN8I_I2S_TX_CHAN_SEL_REG,
SUN8I_I2S_TX_CHAN_OFFSET_MASK,
SUN8I_I2S_TX_CHAN_OFFSET(offset));
}
regmap_field_write(i2s->field_fmt_mode, val);
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_IF:
bclk_polarity = SUN4I_I2S_FMT0_POLARITY_INVERTED;
lrclk_polarity = SUN4I_I2S_FMT0_POLARITY_INVERTED;
break;
case SND_SOC_DAIFMT_IB_NF:
bclk_polarity = SUN4I_I2S_FMT0_POLARITY_INVERTED;
break;
case SND_SOC_DAIFMT_NB_IF:
lrclk_polarity = SUN4I_I2S_FMT0_POLARITY_INVERTED;
break;
case SND_SOC_DAIFMT_NB_NF:
break;
default:
return -EINVAL;
}
regmap_field_write(i2s->field_fmt_bclk, bclk_polarity);
regmap_field_write(i2s->field_fmt_lrclk, lrclk_polarity);
if (i2s->variant->has_slave_select_bit) {
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
} else {
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
val = SUN8I_I2S_CTRL_BCLK_OUT |
SUN8I_I2S_CTRL_LRCK_OUT;
break;
case SND_SOC_DAIFMT_CBM_CFM:
val = 0;
break;
default:
return -EINVAL;
}
regmap_update_bits(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN8I_I2S_CTRL_BCLK_OUT |
SUN8I_I2S_CTRL_LRCK_OUT,
val);
}
regmap_update_bits(i2s->regmap, SUN4I_I2S_FIFO_CTRL_REG,
SUN4I_I2S_FIFO_CTRL_TX_MODE_MASK |
SUN4I_I2S_FIFO_CTRL_RX_MODE_MASK,
SUN4I_I2S_FIFO_CTRL_TX_MODE(1) |
SUN4I_I2S_FIFO_CTRL_RX_MODE(1));
return 0;
}
static void sun4i_i2s_start_capture(struct sun4i_i2s *i2s)
{
regmap_update_bits(i2s->regmap, SUN4I_I2S_FIFO_CTRL_REG,
SUN4I_I2S_FIFO_CTRL_FLUSH_RX,
SUN4I_I2S_FIFO_CTRL_FLUSH_RX);
regmap_write(i2s->regmap, SUN4I_I2S_RX_CNT_REG, 0);
regmap_update_bits(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN4I_I2S_CTRL_RX_EN,
SUN4I_I2S_CTRL_RX_EN);
regmap_update_bits(i2s->regmap, SUN4I_I2S_DMA_INT_CTRL_REG,
SUN4I_I2S_DMA_INT_CTRL_RX_DRQ_EN,
SUN4I_I2S_DMA_INT_CTRL_RX_DRQ_EN);
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
static void sun4i_i2s_stop_capture(struct sun4i_i2s *i2s)
{
regmap_update_bits(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN4I_I2S_CTRL_RX_EN,
0);
regmap_update_bits(i2s->regmap, SUN4I_I2S_DMA_INT_CTRL_REG,
SUN4I_I2S_DMA_INT_CTRL_RX_DRQ_EN,
0);
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
sun4i_i2s_start_capture(i2s);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
sun4i_i2s_stop_playback(i2s);
else
sun4i_i2s_stop_capture(i2s);
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
regmap_update_bits(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN4I_I2S_CTRL_GL_EN, SUN4I_I2S_CTRL_GL_EN);
regmap_update_bits(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN4I_I2S_CTRL_SDO_EN_MASK,
SUN4I_I2S_CTRL_SDO_EN(0));
return clk_prepare_enable(i2s->mod_clk);
}
static void sun4i_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sun4i_i2s *i2s = snd_soc_dai_get_drvdata(dai);
clk_disable_unprepare(i2s->mod_clk);
regmap_update_bits(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN4I_I2S_CTRL_SDO_EN_MASK, 0);
regmap_update_bits(i2s->regmap, SUN4I_I2S_CTRL_REG,
SUN4I_I2S_CTRL_GL_EN, 0);
}
static int sun4i_i2s_set_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct sun4i_i2s *i2s = snd_soc_dai_get_drvdata(dai);
if (clk_id != 0)
return -EINVAL;
i2s->mclk_freq = freq;
return 0;
}
static int sun4i_i2s_dai_probe(struct snd_soc_dai *dai)
{
struct sun4i_i2s *i2s = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_init_dma_data(dai,
&i2s->playback_dma_data,
&i2s->capture_dma_data);
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
static bool sun8i_i2s_rd_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case SUN8I_I2S_FIFO_TX_REG:
return false;
default:
return true;
}
}
static bool sun8i_i2s_volatile_reg(struct device *dev, unsigned int reg)
{
if (reg == SUN8I_I2S_INT_STA_REG)
return true;
if (reg == SUN8I_I2S_FIFO_TX_REG)
return false;
return sun4i_i2s_volatile_reg(dev, reg);
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
static int sun4i_i2s_init_regmap_fields(struct device *dev,
struct sun4i_i2s *i2s)
{
i2s->field_clkdiv_mclk_en =
devm_regmap_field_alloc(dev, i2s->regmap,
i2s->variant->field_clkdiv_mclk_en);
if (IS_ERR(i2s->field_clkdiv_mclk_en))
return PTR_ERR(i2s->field_clkdiv_mclk_en);
i2s->field_fmt_wss =
devm_regmap_field_alloc(dev, i2s->regmap,
i2s->variant->field_fmt_wss);
if (IS_ERR(i2s->field_fmt_wss))
return PTR_ERR(i2s->field_fmt_wss);
i2s->field_fmt_sr =
devm_regmap_field_alloc(dev, i2s->regmap,
i2s->variant->field_fmt_sr);
if (IS_ERR(i2s->field_fmt_sr))
return PTR_ERR(i2s->field_fmt_sr);
i2s->field_fmt_bclk =
devm_regmap_field_alloc(dev, i2s->regmap,
i2s->variant->field_fmt_bclk);
if (IS_ERR(i2s->field_fmt_bclk))
return PTR_ERR(i2s->field_fmt_bclk);
i2s->field_fmt_lrclk =
devm_regmap_field_alloc(dev, i2s->regmap,
i2s->variant->field_fmt_lrclk);
if (IS_ERR(i2s->field_fmt_lrclk))
return PTR_ERR(i2s->field_fmt_lrclk);
i2s->field_fmt_mode =
devm_regmap_field_alloc(dev, i2s->regmap,
i2s->variant->field_fmt_mode);
if (IS_ERR(i2s->field_fmt_mode))
return PTR_ERR(i2s->field_fmt_mode);
i2s->field_txchanmap =
devm_regmap_field_alloc(dev, i2s->regmap,
i2s->variant->field_txchanmap);
if (IS_ERR(i2s->field_txchanmap))
return PTR_ERR(i2s->field_txchanmap);
i2s->field_rxchanmap =
devm_regmap_field_alloc(dev, i2s->regmap,
i2s->variant->field_rxchanmap);
if (IS_ERR(i2s->field_rxchanmap))
return PTR_ERR(i2s->field_rxchanmap);
i2s->field_txchansel =
devm_regmap_field_alloc(dev, i2s->regmap,
i2s->variant->field_txchansel);
if (IS_ERR(i2s->field_txchansel))
return PTR_ERR(i2s->field_txchansel);
i2s->field_rxchansel =
devm_regmap_field_alloc(dev, i2s->regmap,
i2s->variant->field_rxchansel);
return PTR_ERR_OR_ZERO(i2s->field_rxchansel);
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
i2s->variant = of_device_get_match_data(&pdev->dev);
if (!i2s->variant) {
dev_err(&pdev->dev, "Failed to determine the quirks to use\n");
return -ENODEV;
}
i2s->bus_clk = devm_clk_get(&pdev->dev, "apb");
if (IS_ERR(i2s->bus_clk)) {
dev_err(&pdev->dev, "Can't get our bus clock\n");
return PTR_ERR(i2s->bus_clk);
}
i2s->regmap = devm_regmap_init_mmio(&pdev->dev, regs,
i2s->variant->sun4i_i2s_regmap);
if (IS_ERR(i2s->regmap)) {
dev_err(&pdev->dev, "Regmap initialisation failed\n");
return PTR_ERR(i2s->regmap);
}
i2s->mod_clk = devm_clk_get(&pdev->dev, "mod");
if (IS_ERR(i2s->mod_clk)) {
dev_err(&pdev->dev, "Can't get our mod clock\n");
return PTR_ERR(i2s->mod_clk);
}
if (i2s->variant->has_reset) {
i2s->rst = devm_reset_control_get_exclusive(&pdev->dev, NULL);
if (IS_ERR(i2s->rst)) {
dev_err(&pdev->dev, "Failed to get reset control\n");
return PTR_ERR(i2s->rst);
}
}
if (!IS_ERR(i2s->rst)) {
ret = reset_control_deassert(i2s->rst);
if (ret) {
dev_err(&pdev->dev,
"Failed to deassert the reset control\n");
return -EINVAL;
}
}
i2s->playback_dma_data.addr = res->start +
i2s->variant->reg_offset_txdata;
i2s->playback_dma_data.maxburst = 8;
i2s->capture_dma_data.addr = res->start + SUN4I_I2S_FIFO_RX_REG;
i2s->capture_dma_data.maxburst = 8;
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
ret = sun4i_i2s_init_regmap_fields(&pdev->dev, i2s);
if (ret) {
dev_err(&pdev->dev, "Could not initialise regmap fields\n");
goto err_suspend;
}
return 0;
err_suspend:
if (!pm_runtime_status_suspended(&pdev->dev))
sun4i_i2s_runtime_suspend(&pdev->dev);
err_pm_disable:
pm_runtime_disable(&pdev->dev);
if (!IS_ERR(i2s->rst))
reset_control_assert(i2s->rst);
return ret;
}
static int sun4i_i2s_remove(struct platform_device *pdev)
{
struct sun4i_i2s *i2s = dev_get_drvdata(&pdev->dev);
snd_dmaengine_pcm_unregister(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
sun4i_i2s_runtime_suspend(&pdev->dev);
if (!IS_ERR(i2s->rst))
reset_control_assert(i2s->rst);
return 0;
}
