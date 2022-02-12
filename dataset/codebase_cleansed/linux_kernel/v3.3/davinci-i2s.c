static inline void davinci_mcbsp_write_reg(struct davinci_mcbsp_dev *dev,
int reg, u32 val)
{
__raw_writel(val, dev->base + reg);
}
static inline u32 davinci_mcbsp_read_reg(struct davinci_mcbsp_dev *dev, int reg)
{
return __raw_readl(dev->base + reg);
}
static void toggle_clock(struct davinci_mcbsp_dev *dev, int playback)
{
u32 m = playback ? DAVINCI_MCBSP_PCR_CLKXP : DAVINCI_MCBSP_PCR_CLKRP;
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_PCR_REG, dev->pcr ^ m);
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_PCR_REG, dev->pcr);
}
static void davinci_mcbsp_start(struct davinci_mcbsp_dev *dev,
struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_platform *platform = rtd->platform;
int playback = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK);
u32 spcr;
u32 mask = playback ? DAVINCI_MCBSP_SPCR_XRST : DAVINCI_MCBSP_SPCR_RRST;
spcr = davinci_mcbsp_read_reg(dev, DAVINCI_MCBSP_SPCR_REG);
if (spcr & mask) {
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_SPCR_REG,
spcr & ~mask);
toggle_clock(dev, playback);
}
if (dev->pcr & (DAVINCI_MCBSP_PCR_FSXM | DAVINCI_MCBSP_PCR_FSRM |
DAVINCI_MCBSP_PCR_CLKXM | DAVINCI_MCBSP_PCR_CLKRM)) {
spcr |= DAVINCI_MCBSP_SPCR_GRST;
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_SPCR_REG, spcr);
}
if (playback) {
if (platform->driver->ops->trigger) {
int ret = platform->driver->ops->trigger(substream,
SNDRV_PCM_TRIGGER_STOP);
if (ret < 0)
printk(KERN_DEBUG "Playback DMA stop failed\n");
}
spcr = davinci_mcbsp_read_reg(dev, DAVINCI_MCBSP_SPCR_REG);
spcr |= DAVINCI_MCBSP_SPCR_XRST;
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_SPCR_REG, spcr);
udelay(100);
spcr = davinci_mcbsp_read_reg(dev, DAVINCI_MCBSP_SPCR_REG);
spcr &= ~DAVINCI_MCBSP_SPCR_XRST;
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_SPCR_REG, spcr);
toggle_clock(dev, playback);
if (platform->driver->ops->trigger) {
int ret = platform->driver->ops->trigger(substream,
SNDRV_PCM_TRIGGER_START);
if (ret < 0)
printk(KERN_DEBUG "Playback DMA start failed\n");
}
}
spcr = davinci_mcbsp_read_reg(dev, DAVINCI_MCBSP_SPCR_REG);
spcr |= mask;
if (dev->pcr & (DAVINCI_MCBSP_PCR_FSXM | DAVINCI_MCBSP_PCR_FSRM)) {
spcr |= DAVINCI_MCBSP_SPCR_FRST;
}
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_SPCR_REG, spcr);
}
static void davinci_mcbsp_stop(struct davinci_mcbsp_dev *dev, int playback)
{
u32 spcr;
spcr = davinci_mcbsp_read_reg(dev, DAVINCI_MCBSP_SPCR_REG);
spcr &= ~(DAVINCI_MCBSP_SPCR_GRST | DAVINCI_MCBSP_SPCR_FRST);
spcr &= playback ? ~DAVINCI_MCBSP_SPCR_XRST : ~DAVINCI_MCBSP_SPCR_RRST;
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_SPCR_REG, spcr);
toggle_clock(dev, playback);
}
static int davinci_i2s_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct davinci_mcbsp_dev *dev = snd_soc_dai_get_drvdata(cpu_dai);
unsigned int pcr;
unsigned int srgr;
bool inv_fs = false;
srgr = DAVINCI_MCBSP_SRGR_FSGM |
DAVINCI_MCBSP_SRGR_FPER(DEFAULT_BITPERSAMPLE * 2 - 1) |
DAVINCI_MCBSP_SRGR_FWID(DEFAULT_BITPERSAMPLE - 1);
dev->fmt = fmt;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
pcr = DAVINCI_MCBSP_PCR_FSXM |
DAVINCI_MCBSP_PCR_FSRM |
DAVINCI_MCBSP_PCR_CLKXM |
DAVINCI_MCBSP_PCR_CLKRM;
break;
case SND_SOC_DAIFMT_CBM_CFS:
pcr = DAVINCI_MCBSP_PCR_FSRM | DAVINCI_MCBSP_PCR_FSXM;
switch (dev->clk_input_pin) {
case MCBSP_CLKS:
pcr |= DAVINCI_MCBSP_PCR_CLKXM |
DAVINCI_MCBSP_PCR_CLKRM;
break;
case MCBSP_CLKR:
pcr |= DAVINCI_MCBSP_PCR_SCLKME;
break;
default:
dev_err(dev->dev, "bad clk_input_pin\n");
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_CBM_CFM:
pcr = 0;
break;
default:
printk(KERN_ERR "%s:bad master\n", __func__);
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
inv_fs = true;
case SND_SOC_DAIFMT_DSP_A:
dev->mode = MOD_DSP_A;
break;
case SND_SOC_DAIFMT_DSP_B:
dev->mode = MOD_DSP_B;
break;
default:
printk(KERN_ERR "%s:bad format\n", __func__);
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
pcr |= (DAVINCI_MCBSP_PCR_CLKXP | DAVINCI_MCBSP_PCR_CLKRP);
break;
case SND_SOC_DAIFMT_IB_IF:
pcr |= (DAVINCI_MCBSP_PCR_FSXP | DAVINCI_MCBSP_PCR_FSRP);
break;
case SND_SOC_DAIFMT_NB_IF:
pcr |= (DAVINCI_MCBSP_PCR_CLKXP | DAVINCI_MCBSP_PCR_CLKRP |
DAVINCI_MCBSP_PCR_FSXP | DAVINCI_MCBSP_PCR_FSRP);
break;
case SND_SOC_DAIFMT_IB_NF:
break;
default:
return -EINVAL;
}
if (inv_fs == true)
pcr ^= (DAVINCI_MCBSP_PCR_FSXP | DAVINCI_MCBSP_PCR_FSRP);
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_SRGR_REG, srgr);
dev->pcr = pcr;
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_PCR_REG, pcr);
return 0;
}
static int davinci_i2s_dai_set_clkdiv(struct snd_soc_dai *cpu_dai,
int div_id, int div)
{
struct davinci_mcbsp_dev *dev = snd_soc_dai_get_drvdata(cpu_dai);
if (div_id != DAVINCI_MCBSP_CLKGDV)
return -ENODEV;
dev->clk_div = div;
return 0;
}
static int davinci_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct davinci_mcbsp_dev *dev = snd_soc_dai_get_drvdata(dai);
struct davinci_pcm_dma_params *dma_params =
&dev->dma_params[substream->stream];
struct snd_interval *i = NULL;
int mcbsp_word_length, master;
unsigned int rcr, xcr, srgr, clk_div, freq, framesize;
u32 spcr;
snd_pcm_format_t fmt;
unsigned element_cnt = 1;
spcr = davinci_mcbsp_read_reg(dev, DAVINCI_MCBSP_SPCR_REG);
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE) {
spcr |= DAVINCI_MCBSP_SPCR_RINTM(3) | DAVINCI_MCBSP_SPCR_FREE;
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_SPCR_REG, spcr);
} else {
spcr |= DAVINCI_MCBSP_SPCR_XINTM(3) | DAVINCI_MCBSP_SPCR_FREE;
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_SPCR_REG, spcr);
}
master = dev->fmt & SND_SOC_DAIFMT_MASTER_MASK;
fmt = params_format(params);
mcbsp_word_length = asp_word_length[fmt];
switch (master) {
case SND_SOC_DAIFMT_CBS_CFS:
freq = clk_get_rate(dev->clk);
srgr = DAVINCI_MCBSP_SRGR_FSGM |
DAVINCI_MCBSP_SRGR_CLKSM;
srgr |= DAVINCI_MCBSP_SRGR_FWID(mcbsp_word_length *
8 - 1);
if (dev->i2s_accurate_sck) {
clk_div = 256;
do {
framesize = (freq / (--clk_div)) /
params->rate_num *
params->rate_den;
} while (((framesize < 33) || (framesize > 4095)) &&
(clk_div));
clk_div--;
srgr |= DAVINCI_MCBSP_SRGR_FPER(framesize - 1);
} else {
clk_div = freq / (mcbsp_word_length * 16) /
params->rate_num * params->rate_den;
srgr |= DAVINCI_MCBSP_SRGR_FPER(mcbsp_word_length *
16 - 1);
}
clk_div &= 0xFF;
srgr |= clk_div;
break;
case SND_SOC_DAIFMT_CBM_CFS:
srgr = DAVINCI_MCBSP_SRGR_FSGM;
clk_div = dev->clk_div - 1;
srgr |= DAVINCI_MCBSP_SRGR_FWID(mcbsp_word_length * 8 - 1);
srgr |= DAVINCI_MCBSP_SRGR_FPER(mcbsp_word_length * 16 - 1);
clk_div &= 0xFF;
srgr |= clk_div;
break;
case SND_SOC_DAIFMT_CBM_CFM:
i = hw_param_interval(params, SNDRV_PCM_HW_PARAM_SAMPLE_BITS);
srgr = DAVINCI_MCBSP_SRGR_FSGM;
srgr |= DAVINCI_MCBSP_SRGR_FWID(snd_interval_value(i) - 1);
pr_debug("%s - %d FWID set: re-read srgr = %X\n",
__func__, __LINE__, snd_interval_value(i) - 1);
i = hw_param_interval(params, SNDRV_PCM_HW_PARAM_FRAME_BITS);
srgr |= DAVINCI_MCBSP_SRGR_FPER(snd_interval_value(i) - 1);
break;
default:
return -EINVAL;
}
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_SRGR_REG, srgr);
rcr = DAVINCI_MCBSP_RCR_RFIG;
xcr = DAVINCI_MCBSP_XCR_XFIG;
if (dev->mode == MOD_DSP_B) {
rcr |= DAVINCI_MCBSP_RCR_RDATDLY(0);
xcr |= DAVINCI_MCBSP_XCR_XDATDLY(0);
} else {
rcr |= DAVINCI_MCBSP_RCR_RDATDLY(1);
xcr |= DAVINCI_MCBSP_XCR_XDATDLY(1);
}
fmt = params_format(params);
if ((fmt > SNDRV_PCM_FORMAT_S32_LE) || !data_type[fmt]) {
printk(KERN_WARNING "davinci-i2s: unsupported PCM format\n");
return -EINVAL;
}
if (params_channels(params) == 2) {
element_cnt = 2;
if (double_fmt[fmt] && dev->enable_channel_combine) {
element_cnt = 1;
fmt = double_fmt[fmt];
}
switch (master) {
case SND_SOC_DAIFMT_CBS_CFS:
case SND_SOC_DAIFMT_CBS_CFM:
rcr |= DAVINCI_MCBSP_RCR_RFRLEN2(0);
xcr |= DAVINCI_MCBSP_XCR_XFRLEN2(0);
rcr |= DAVINCI_MCBSP_RCR_RPHASE;
xcr |= DAVINCI_MCBSP_XCR_XPHASE;
break;
case SND_SOC_DAIFMT_CBM_CFM:
case SND_SOC_DAIFMT_CBM_CFS:
rcr |= DAVINCI_MCBSP_RCR_RFRLEN2(element_cnt - 1);
xcr |= DAVINCI_MCBSP_XCR_XFRLEN2(element_cnt - 1);
break;
default:
return -EINVAL;
}
}
dma_params->acnt = dma_params->data_type = data_type[fmt];
dma_params->fifo_level = 0;
mcbsp_word_length = asp_word_length[fmt];
switch (master) {
case SND_SOC_DAIFMT_CBS_CFS:
case SND_SOC_DAIFMT_CBS_CFM:
rcr |= DAVINCI_MCBSP_RCR_RFRLEN1(0);
xcr |= DAVINCI_MCBSP_XCR_XFRLEN1(0);
break;
case SND_SOC_DAIFMT_CBM_CFM:
case SND_SOC_DAIFMT_CBM_CFS:
rcr |= DAVINCI_MCBSP_RCR_RFRLEN1(element_cnt - 1);
xcr |= DAVINCI_MCBSP_XCR_XFRLEN1(element_cnt - 1);
break;
default:
return -EINVAL;
}
rcr |= DAVINCI_MCBSP_RCR_RWDLEN1(mcbsp_word_length) |
DAVINCI_MCBSP_RCR_RWDLEN2(mcbsp_word_length);
xcr |= DAVINCI_MCBSP_XCR_XWDLEN1(mcbsp_word_length) |
DAVINCI_MCBSP_XCR_XWDLEN2(mcbsp_word_length);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_XCR_REG, xcr);
else
davinci_mcbsp_write_reg(dev, DAVINCI_MCBSP_RCR_REG, rcr);
pr_debug("%s - %d srgr=%X\n", __func__, __LINE__, srgr);
pr_debug("%s - %d xcr=%X\n", __func__, __LINE__, xcr);
pr_debug("%s - %d rcr=%X\n", __func__, __LINE__, rcr);
return 0;
}
static int davinci_i2s_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct davinci_mcbsp_dev *dev = snd_soc_dai_get_drvdata(dai);
int playback = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK);
davinci_mcbsp_stop(dev, playback);
return 0;
}
static int davinci_i2s_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct davinci_mcbsp_dev *dev = snd_soc_dai_get_drvdata(dai);
int ret = 0;
int playback = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
davinci_mcbsp_start(dev, substream);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
davinci_mcbsp_stop(dev, playback);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int davinci_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct davinci_mcbsp_dev *dev = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_set_dma_data(dai, substream, dev->dma_params);
return 0;
}
static void davinci_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct davinci_mcbsp_dev *dev = snd_soc_dai_get_drvdata(dai);
int playback = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK);
davinci_mcbsp_stop(dev, playback);
}
static int davinci_i2s_probe(struct platform_device *pdev)
{
struct snd_platform_data *pdata = pdev->dev.platform_data;
struct davinci_mcbsp_dev *dev;
struct resource *mem, *ioarea, *res;
enum dma_event_q asp_chan_q = EVENTQ_0;
enum dma_event_q ram_chan_q = EVENTQ_1;
int ret;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "no mem resource?\n");
return -ENODEV;
}
ioarea = devm_request_mem_region(&pdev->dev, mem->start,
resource_size(mem),
pdev->name);
if (!ioarea) {
dev_err(&pdev->dev, "McBSP region already claimed\n");
return -EBUSY;
}
dev = devm_kzalloc(&pdev->dev, sizeof(struct davinci_mcbsp_dev),
GFP_KERNEL);
if (!dev)
return -ENOMEM;
if (pdata) {
dev->enable_channel_combine = pdata->enable_channel_combine;
dev->dma_params[SNDRV_PCM_STREAM_PLAYBACK].sram_size =
pdata->sram_size_playback;
dev->dma_params[SNDRV_PCM_STREAM_CAPTURE].sram_size =
pdata->sram_size_capture;
dev->clk_input_pin = pdata->clk_input_pin;
dev->i2s_accurate_sck = pdata->i2s_accurate_sck;
asp_chan_q = pdata->asp_chan_q;
ram_chan_q = pdata->ram_chan_q;
}
dev->dma_params[SNDRV_PCM_STREAM_PLAYBACK].asp_chan_q = asp_chan_q;
dev->dma_params[SNDRV_PCM_STREAM_PLAYBACK].ram_chan_q = ram_chan_q;
dev->dma_params[SNDRV_PCM_STREAM_CAPTURE].asp_chan_q = asp_chan_q;
dev->dma_params[SNDRV_PCM_STREAM_CAPTURE].ram_chan_q = ram_chan_q;
dev->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(dev->clk))
return -ENODEV;
clk_enable(dev->clk);
dev->base = devm_ioremap(&pdev->dev, mem->start, resource_size(mem));
if (!dev->base) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto err_release_clk;
}
dev->dma_params[SNDRV_PCM_STREAM_PLAYBACK].dma_addr =
(dma_addr_t)(mem->start + DAVINCI_MCBSP_DXR_REG);
dev->dma_params[SNDRV_PCM_STREAM_CAPTURE].dma_addr =
(dma_addr_t)(mem->start + DAVINCI_MCBSP_DRR_REG);
res = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!res) {
dev_err(&pdev->dev, "no DMA resource\n");
ret = -ENXIO;
goto err_release_clk;
}
dev->dma_params[SNDRV_PCM_STREAM_PLAYBACK].channel = res->start;
res = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (!res) {
dev_err(&pdev->dev, "no DMA resource\n");
ret = -ENXIO;
goto err_release_clk;
}
dev->dma_params[SNDRV_PCM_STREAM_CAPTURE].channel = res->start;
dev->dev = &pdev->dev;
dev_set_drvdata(&pdev->dev, dev);
ret = snd_soc_register_dai(&pdev->dev, &davinci_i2s_dai);
if (ret != 0)
goto err_release_clk;
return 0;
err_release_clk:
clk_disable(dev->clk);
clk_put(dev->clk);
return ret;
}
static int davinci_i2s_remove(struct platform_device *pdev)
{
struct davinci_mcbsp_dev *dev = dev_get_drvdata(&pdev->dev);
snd_soc_unregister_dai(&pdev->dev);
clk_disable(dev->clk);
clk_put(dev->clk);
dev->clk = NULL;
return 0;
}
