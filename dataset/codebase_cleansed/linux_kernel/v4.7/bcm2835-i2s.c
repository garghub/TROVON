static void bcm2835_i2s_start_clock(struct bcm2835_i2s_dev *dev)
{
unsigned int master = dev->fmt & SND_SOC_DAIFMT_MASTER_MASK;
if (dev->clk_prepared)
return;
switch (master) {
case SND_SOC_DAIFMT_CBS_CFS:
case SND_SOC_DAIFMT_CBS_CFM:
clk_prepare_enable(dev->clk);
dev->clk_prepared = true;
break;
default:
break;
}
}
static void bcm2835_i2s_stop_clock(struct bcm2835_i2s_dev *dev)
{
if (dev->clk_prepared)
clk_disable_unprepare(dev->clk);
dev->clk_prepared = false;
}
static void bcm2835_i2s_clear_fifos(struct bcm2835_i2s_dev *dev,
bool tx, bool rx)
{
int timeout = 1000;
uint32_t syncval;
uint32_t csreg;
uint32_t i2s_active_state;
bool clk_was_prepared;
uint32_t off;
uint32_t clr;
off = tx ? BCM2835_I2S_TXON : 0;
off |= rx ? BCM2835_I2S_RXON : 0;
clr = tx ? BCM2835_I2S_TXCLR : 0;
clr |= rx ? BCM2835_I2S_RXCLR : 0;
regmap_read(dev->i2s_regmap, BCM2835_I2S_CS_A_REG, &csreg);
i2s_active_state = csreg & (BCM2835_I2S_RXON | BCM2835_I2S_TXON);
clk_was_prepared = dev->clk_prepared;
if (!clk_was_prepared)
bcm2835_i2s_start_clock(dev);
regmap_update_bits(dev->i2s_regmap, BCM2835_I2S_CS_A_REG, off, 0);
regmap_update_bits(dev->i2s_regmap, BCM2835_I2S_CS_A_REG, clr, clr);
regmap_read(dev->i2s_regmap, BCM2835_I2S_CS_A_REG, &syncval);
syncval &= BCM2835_I2S_SYNC;
regmap_update_bits(dev->i2s_regmap, BCM2835_I2S_CS_A_REG,
BCM2835_I2S_SYNC, ~syncval);
while (--timeout) {
regmap_read(dev->i2s_regmap, BCM2835_I2S_CS_A_REG, &csreg);
if ((csreg & BCM2835_I2S_SYNC) != syncval)
break;
}
if (!timeout)
dev_err(dev->dev, "I2S SYNC error!\n");
if (!clk_was_prepared)
bcm2835_i2s_stop_clock(dev);
regmap_update_bits(dev->i2s_regmap, BCM2835_I2S_CS_A_REG,
BCM2835_I2S_RXON | BCM2835_I2S_TXON, i2s_active_state);
}
static int bcm2835_i2s_set_dai_fmt(struct snd_soc_dai *dai,
unsigned int fmt)
{
struct bcm2835_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
dev->fmt = fmt;
return 0;
}
static int bcm2835_i2s_set_dai_bclk_ratio(struct snd_soc_dai *dai,
unsigned int ratio)
{
struct bcm2835_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
dev->bclk_ratio = ratio;
return 0;
}
static int bcm2835_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct bcm2835_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
unsigned int sampling_rate = params_rate(params);
unsigned int data_length, data_delay, bclk_ratio;
unsigned int ch1pos, ch2pos, mode, format;
uint32_t csreg;
regmap_read(dev->i2s_regmap, BCM2835_I2S_CS_A_REG, &csreg);
if (csreg & (BCM2835_I2S_TXON | BCM2835_I2S_RXON))
return 0;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
data_length = 16;
break;
case SNDRV_PCM_FORMAT_S24_LE:
data_length = 24;
break;
case SNDRV_PCM_FORMAT_S32_LE:
data_length = 32;
break;
default:
return -EINVAL;
}
if (dev->bclk_ratio)
bclk_ratio = dev->bclk_ratio;
else
bclk_ratio = 2 * data_length;
switch (dev->fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
case SND_SOC_DAIFMT_CBS_CFM:
clk_set_rate(dev->clk, sampling_rate * bclk_ratio);
break;
default:
break;
}
format = BCM2835_I2S_CHEN;
if (data_length >= 24)
format |= BCM2835_I2S_CHWEX;
format |= BCM2835_I2S_CHWID((data_length-8)&0xf);
switch (dev->fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
data_delay = 1;
break;
default:
dev_err(dev->dev, "%s:bad format\n", __func__);
return -EINVAL;
}
ch1pos = data_delay;
ch2pos = bclk_ratio / 2 + data_delay;
switch (params_channels(params)) {
case 2:
format = BCM2835_I2S_CH1(format) | BCM2835_I2S_CH2(format);
format |= BCM2835_I2S_CH1(BCM2835_I2S_CHPOS(ch1pos));
format |= BCM2835_I2S_CH2(BCM2835_I2S_CHPOS(ch2pos));
break;
default:
return -EINVAL;
}
regmap_write(dev->i2s_regmap, BCM2835_I2S_RXC_A_REG, format);
regmap_write(dev->i2s_regmap, BCM2835_I2S_TXC_A_REG, format);
mode = 0;
if (data_length <= 16) {
mode |= BCM2835_I2S_FTXP | BCM2835_I2S_FRXP;
}
mode |= BCM2835_I2S_FLEN(bclk_ratio - 1);
mode |= BCM2835_I2S_FSLEN(bclk_ratio / 2);
switch (dev->fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBM_CFS:
mode |= BCM2835_I2S_CLKM;
break;
case SND_SOC_DAIFMT_CBS_CFM:
mode |= BCM2835_I2S_FSM;
break;
case SND_SOC_DAIFMT_CBM_CFM:
mode |= BCM2835_I2S_CLKM;
mode |= BCM2835_I2S_FSM;
break;
default:
dev_err(dev->dev, "%s:bad master\n", __func__);
return -EINVAL;
}
switch (dev->fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
mode |= BCM2835_I2S_CLKI;
mode |= BCM2835_I2S_FSI;
break;
case SND_SOC_DAIFMT_IB_IF:
break;
case SND_SOC_DAIFMT_NB_IF:
mode |= BCM2835_I2S_CLKI;
break;
case SND_SOC_DAIFMT_IB_NF:
mode |= BCM2835_I2S_FSI;
break;
default:
return -EINVAL;
}
regmap_write(dev->i2s_regmap, BCM2835_I2S_MODE_A_REG, mode);
regmap_update_bits(dev->i2s_regmap, BCM2835_I2S_CS_A_REG,
BCM2835_I2S_RXTHR(1)
| BCM2835_I2S_TXTHR(1)
| BCM2835_I2S_DMAEN, 0xffffffff);
regmap_update_bits(dev->i2s_regmap, BCM2835_I2S_DREQ_A_REG,
BCM2835_I2S_TX_PANIC(0x10)
| BCM2835_I2S_RX_PANIC(0x30)
| BCM2835_I2S_TX(0x30)
| BCM2835_I2S_RX(0x20), 0xffffffff);
bcm2835_i2s_clear_fifos(dev, true, true);
return 0;
}
static int bcm2835_i2s_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct bcm2835_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
uint32_t cs_reg;
bcm2835_i2s_start_clock(dev);
regmap_read(dev->i2s_regmap, BCM2835_I2S_CS_A_REG, &cs_reg);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK
&& !(cs_reg & BCM2835_I2S_TXE))
bcm2835_i2s_clear_fifos(dev, true, false);
else if (substream->stream == SNDRV_PCM_STREAM_CAPTURE
&& (cs_reg & BCM2835_I2S_RXD))
bcm2835_i2s_clear_fifos(dev, false, true);
return 0;
}
static void bcm2835_i2s_stop(struct bcm2835_i2s_dev *dev,
struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
uint32_t mask;
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
mask = BCM2835_I2S_RXON;
else
mask = BCM2835_I2S_TXON;
regmap_update_bits(dev->i2s_regmap,
BCM2835_I2S_CS_A_REG, mask, 0);
if (!dai->active && !(dev->fmt & SND_SOC_DAIFMT_CONT))
bcm2835_i2s_stop_clock(dev);
}
static int bcm2835_i2s_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct bcm2835_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
uint32_t mask;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
bcm2835_i2s_start_clock(dev);
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
mask = BCM2835_I2S_RXON;
else
mask = BCM2835_I2S_TXON;
regmap_update_bits(dev->i2s_regmap,
BCM2835_I2S_CS_A_REG, mask, mask);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
bcm2835_i2s_stop(dev, substream, dai);
break;
default:
return -EINVAL;
}
return 0;
}
static int bcm2835_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct bcm2835_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
if (dai->active)
return 0;
bcm2835_i2s_stop_clock(dev);
regmap_update_bits(dev->i2s_regmap, BCM2835_I2S_CS_A_REG,
BCM2835_I2S_EN, BCM2835_I2S_EN);
regmap_update_bits(dev->i2s_regmap, BCM2835_I2S_CS_A_REG,
BCM2835_I2S_STBY, BCM2835_I2S_STBY);
return 0;
}
static void bcm2835_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct bcm2835_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
bcm2835_i2s_stop(dev, substream, dai);
if (dai->active)
return;
regmap_update_bits(dev->i2s_regmap, BCM2835_I2S_CS_A_REG,
BCM2835_I2S_EN, 0);
bcm2835_i2s_stop_clock(dev);
}
static int bcm2835_i2s_dai_probe(struct snd_soc_dai *dai)
{
struct bcm2835_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_init_dma_data(dai,
&dev->dma_data[SNDRV_PCM_STREAM_PLAYBACK],
&dev->dma_data[SNDRV_PCM_STREAM_CAPTURE]);
return 0;
}
static bool bcm2835_i2s_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case BCM2835_I2S_CS_A_REG:
case BCM2835_I2S_FIFO_A_REG:
case BCM2835_I2S_INTSTC_A_REG:
case BCM2835_I2S_GRAY_REG:
return true;
default:
return false;
};
}
static bool bcm2835_i2s_precious_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case BCM2835_I2S_FIFO_A_REG:
return true;
default:
return false;
};
}
static int bcm2835_i2s_probe(struct platform_device *pdev)
{
struct bcm2835_i2s_dev *dev;
int ret;
struct resource *mem;
void __iomem *base;
const __be32 *addr;
dma_addr_t dma_base;
dev = devm_kzalloc(&pdev->dev, sizeof(*dev),
GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->clk_prepared = false;
dev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(dev->clk)) {
dev_err(&pdev->dev, "could not get clk: %ld\n",
PTR_ERR(dev->clk));
return PTR_ERR(dev->clk);
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(base))
return PTR_ERR(base);
dev->i2s_regmap = devm_regmap_init_mmio(&pdev->dev, base,
&bcm2835_regmap_config);
if (IS_ERR(dev->i2s_regmap))
return PTR_ERR(dev->i2s_regmap);
addr = of_get_address(pdev->dev.of_node, 0, NULL, NULL);
if (!addr) {
dev_err(&pdev->dev, "could not get DMA-register address\n");
return -EINVAL;
}
dma_base = be32_to_cpup(addr);
dev->dma_data[SNDRV_PCM_STREAM_PLAYBACK].addr =
dma_base + BCM2835_I2S_FIFO_A_REG;
dev->dma_data[SNDRV_PCM_STREAM_CAPTURE].addr =
dma_base + BCM2835_I2S_FIFO_A_REG;
dev->dma_data[SNDRV_PCM_STREAM_PLAYBACK].addr_width =
DMA_SLAVE_BUSWIDTH_4_BYTES;
dev->dma_data[SNDRV_PCM_STREAM_CAPTURE].addr_width =
DMA_SLAVE_BUSWIDTH_4_BYTES;
dev->dma_data[SNDRV_PCM_STREAM_PLAYBACK].maxburst = 2;
dev->dma_data[SNDRV_PCM_STREAM_CAPTURE].maxburst = 2;
dev->dma_data[SNDRV_PCM_STREAM_PLAYBACK].flags =
SND_DMAENGINE_PCM_DAI_FLAG_PACK;
dev->dma_data[SNDRV_PCM_STREAM_CAPTURE].flags =
SND_DMAENGINE_PCM_DAI_FLAG_PACK;
dev->bclk_ratio = 0;
dev->dev = &pdev->dev;
dev_set_drvdata(&pdev->dev, dev);
ret = devm_snd_soc_register_component(&pdev->dev,
&bcm2835_i2s_component, &bcm2835_i2s_dai, 1);
if (ret) {
dev_err(&pdev->dev, "Could not register DAI: %d\n", ret);
return ret;
}
ret = devm_snd_dmaengine_pcm_register(&pdev->dev, NULL, 0);
if (ret) {
dev_err(&pdev->dev, "Could not register PCM: %d\n", ret);
return ret;
}
return 0;
}
