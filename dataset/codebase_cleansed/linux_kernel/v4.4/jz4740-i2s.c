static inline uint32_t jz4740_i2s_read(const struct jz4740_i2s *i2s,
unsigned int reg)
{
return readl(i2s->base + reg);
}
static inline void jz4740_i2s_write(const struct jz4740_i2s *i2s,
unsigned int reg, uint32_t value)
{
writel(value, i2s->base + reg);
}
static int jz4740_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct jz4740_i2s *i2s = snd_soc_dai_get_drvdata(dai);
uint32_t conf, ctrl;
if (dai->active)
return 0;
ctrl = jz4740_i2s_read(i2s, JZ_REG_AIC_CTRL);
ctrl |= JZ_AIC_CTRL_FLUSH;
jz4740_i2s_write(i2s, JZ_REG_AIC_CTRL, ctrl);
clk_prepare_enable(i2s->clk_i2s);
conf = jz4740_i2s_read(i2s, JZ_REG_AIC_CONF);
conf |= JZ_AIC_CONF_ENABLE;
jz4740_i2s_write(i2s, JZ_REG_AIC_CONF, conf);
return 0;
}
static void jz4740_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct jz4740_i2s *i2s = snd_soc_dai_get_drvdata(dai);
uint32_t conf;
if (dai->active)
return;
conf = jz4740_i2s_read(i2s, JZ_REG_AIC_CONF);
conf &= ~JZ_AIC_CONF_ENABLE;
jz4740_i2s_write(i2s, JZ_REG_AIC_CONF, conf);
clk_disable_unprepare(i2s->clk_i2s);
}
static int jz4740_i2s_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct jz4740_i2s *i2s = snd_soc_dai_get_drvdata(dai);
uint32_t ctrl;
uint32_t mask;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
mask = JZ_AIC_CTRL_ENABLE_PLAYBACK | JZ_AIC_CTRL_ENABLE_TX_DMA;
else
mask = JZ_AIC_CTRL_ENABLE_CAPTURE | JZ_AIC_CTRL_ENABLE_RX_DMA;
ctrl = jz4740_i2s_read(i2s, JZ_REG_AIC_CTRL);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
ctrl |= mask;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
ctrl &= ~mask;
break;
default:
return -EINVAL;
}
jz4740_i2s_write(i2s, JZ_REG_AIC_CTRL, ctrl);
return 0;
}
static int jz4740_i2s_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct jz4740_i2s *i2s = snd_soc_dai_get_drvdata(dai);
uint32_t format = 0;
uint32_t conf;
conf = jz4740_i2s_read(i2s, JZ_REG_AIC_CONF);
conf &= ~(JZ_AIC_CONF_BIT_CLK_MASTER | JZ_AIC_CONF_SYNC_CLK_MASTER);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
conf |= JZ_AIC_CONF_BIT_CLK_MASTER | JZ_AIC_CONF_SYNC_CLK_MASTER;
format |= JZ_AIC_I2S_FMT_ENABLE_SYS_CLK;
break;
case SND_SOC_DAIFMT_CBM_CFS:
conf |= JZ_AIC_CONF_SYNC_CLK_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFM:
conf |= JZ_AIC_CONF_BIT_CLK_MASTER;
break;
case SND_SOC_DAIFMT_CBM_CFM:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_MSB:
format |= JZ_AIC_I2S_FMT_MSB;
break;
case SND_SOC_DAIFMT_I2S:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
default:
return -EINVAL;
}
jz4740_i2s_write(i2s, JZ_REG_AIC_CONF, conf);
jz4740_i2s_write(i2s, JZ_REG_AIC_I2S_FMT, format);
return 0;
}
static int jz4740_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct jz4740_i2s *i2s = snd_soc_dai_get_drvdata(dai);
unsigned int sample_size;
uint32_t ctrl, div_reg;
int div;
ctrl = jz4740_i2s_read(i2s, JZ_REG_AIC_CTRL);
div_reg = jz4740_i2s_read(i2s, JZ_REG_AIC_CLK_DIV);
div = clk_get_rate(i2s->clk_i2s) / (64 * params_rate(params));
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
sample_size = 0;
break;
case SNDRV_PCM_FORMAT_S16:
sample_size = 1;
break;
default:
return -EINVAL;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
ctrl &= ~JZ_AIC_CTRL_OUTPUT_SAMPLE_SIZE_MASK;
ctrl |= sample_size << JZ_AIC_CTRL_OUTPUT_SAMPLE_SIZE_OFFSET;
if (params_channels(params) == 1)
ctrl |= JZ_AIC_CTRL_MONO_TO_STEREO;
else
ctrl &= ~JZ_AIC_CTRL_MONO_TO_STEREO;
div_reg &= ~I2SDIV_DV_MASK;
div_reg |= (div - 1) << I2SDIV_DV_SHIFT;
} else {
ctrl &= ~JZ_AIC_CTRL_INPUT_SAMPLE_SIZE_MASK;
ctrl |= sample_size << JZ_AIC_CTRL_INPUT_SAMPLE_SIZE_OFFSET;
if (i2s->version >= JZ_I2S_JZ4780) {
div_reg &= ~I2SDIV_IDV_MASK;
div_reg |= (div - 1) << I2SDIV_IDV_SHIFT;
} else {
div_reg &= ~I2SDIV_DV_MASK;
div_reg |= (div - 1) << I2SDIV_DV_SHIFT;
}
}
jz4740_i2s_write(i2s, JZ_REG_AIC_CTRL, ctrl);
jz4740_i2s_write(i2s, JZ_REG_AIC_CLK_DIV, div_reg);
return 0;
}
static int jz4740_i2s_set_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct jz4740_i2s *i2s = snd_soc_dai_get_drvdata(dai);
struct clk *parent;
int ret = 0;
switch (clk_id) {
case JZ4740_I2S_CLKSRC_EXT:
parent = clk_get(NULL, "ext");
clk_set_parent(i2s->clk_i2s, parent);
break;
case JZ4740_I2S_CLKSRC_PLL:
parent = clk_get(NULL, "pll half");
clk_set_parent(i2s->clk_i2s, parent);
ret = clk_set_rate(i2s->clk_i2s, freq);
break;
default:
return -EINVAL;
}
clk_put(parent);
return ret;
}
static int jz4740_i2s_suspend(struct snd_soc_dai *dai)
{
struct jz4740_i2s *i2s = snd_soc_dai_get_drvdata(dai);
uint32_t conf;
if (dai->active) {
conf = jz4740_i2s_read(i2s, JZ_REG_AIC_CONF);
conf &= ~JZ_AIC_CONF_ENABLE;
jz4740_i2s_write(i2s, JZ_REG_AIC_CONF, conf);
clk_disable_unprepare(i2s->clk_i2s);
}
clk_disable_unprepare(i2s->clk_aic);
return 0;
}
static int jz4740_i2s_resume(struct snd_soc_dai *dai)
{
struct jz4740_i2s *i2s = snd_soc_dai_get_drvdata(dai);
uint32_t conf;
clk_prepare_enable(i2s->clk_aic);
if (dai->active) {
clk_prepare_enable(i2s->clk_i2s);
conf = jz4740_i2s_read(i2s, JZ_REG_AIC_CONF);
conf |= JZ_AIC_CONF_ENABLE;
jz4740_i2s_write(i2s, JZ_REG_AIC_CONF, conf);
}
return 0;
}
static void jz4740_i2c_init_pcm_config(struct jz4740_i2s *i2s)
{
struct snd_dmaengine_dai_dma_data *dma_data;
dma_data = &i2s->playback_dma_data;
dma_data->maxburst = 16;
dma_data->slave_id = JZ4740_DMA_TYPE_AIC_TRANSMIT;
dma_data->addr = i2s->phys_base + JZ_REG_AIC_FIFO;
dma_data = &i2s->capture_dma_data;
dma_data->maxburst = 16;
dma_data->slave_id = JZ4740_DMA_TYPE_AIC_RECEIVE;
dma_data->addr = i2s->phys_base + JZ_REG_AIC_FIFO;
}
static int jz4740_i2s_dai_probe(struct snd_soc_dai *dai)
{
struct jz4740_i2s *i2s = snd_soc_dai_get_drvdata(dai);
uint32_t conf;
clk_prepare_enable(i2s->clk_aic);
jz4740_i2c_init_pcm_config(i2s);
snd_soc_dai_init_dma_data(dai, &i2s->playback_dma_data,
&i2s->capture_dma_data);
if (i2s->version >= JZ_I2S_JZ4780) {
conf = (7 << JZ4780_AIC_CONF_FIFO_RX_THRESHOLD_OFFSET) |
(8 << JZ4780_AIC_CONF_FIFO_TX_THRESHOLD_OFFSET) |
JZ_AIC_CONF_OVERFLOW_PLAY_LAST |
JZ_AIC_CONF_I2S |
JZ_AIC_CONF_INTERNAL_CODEC;
} else {
conf = (7 << JZ_AIC_CONF_FIFO_RX_THRESHOLD_OFFSET) |
(8 << JZ_AIC_CONF_FIFO_TX_THRESHOLD_OFFSET) |
JZ_AIC_CONF_OVERFLOW_PLAY_LAST |
JZ_AIC_CONF_I2S |
JZ_AIC_CONF_INTERNAL_CODEC;
}
jz4740_i2s_write(i2s, JZ_REG_AIC_CONF, JZ_AIC_CONF_RESET);
jz4740_i2s_write(i2s, JZ_REG_AIC_CONF, conf);
return 0;
}
static int jz4740_i2s_dai_remove(struct snd_soc_dai *dai)
{
struct jz4740_i2s *i2s = snd_soc_dai_get_drvdata(dai);
clk_disable_unprepare(i2s->clk_aic);
return 0;
}
static int jz4740_i2s_dev_probe(struct platform_device *pdev)
{
struct jz4740_i2s *i2s;
struct resource *mem;
int ret;
const struct of_device_id *match;
i2s = devm_kzalloc(&pdev->dev, sizeof(*i2s), GFP_KERNEL);
if (!i2s)
return -ENOMEM;
match = of_match_device(jz4740_of_matches, &pdev->dev);
if (match)
i2s->version = (enum jz47xx_i2s_version)match->data;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2s->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(i2s->base))
return PTR_ERR(i2s->base);
i2s->phys_base = mem->start;
i2s->clk_aic = devm_clk_get(&pdev->dev, "aic");
if (IS_ERR(i2s->clk_aic))
return PTR_ERR(i2s->clk_aic);
i2s->clk_i2s = devm_clk_get(&pdev->dev, "i2s");
if (IS_ERR(i2s->clk_i2s))
return PTR_ERR(i2s->clk_i2s);
platform_set_drvdata(pdev, i2s);
if (i2s->version == JZ_I2S_JZ4780)
ret = devm_snd_soc_register_component(&pdev->dev,
&jz4740_i2s_component, &jz4780_i2s_dai, 1);
else
ret = devm_snd_soc_register_component(&pdev->dev,
&jz4740_i2s_component, &jz4740_i2s_dai, 1);
if (ret)
return ret;
return devm_snd_dmaengine_pcm_register(&pdev->dev, NULL,
SND_DMAENGINE_PCM_FLAG_COMPAT);
}
