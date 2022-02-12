static inline unsigned long RD(struct au1xpsc_audio_data *ctx, int reg)
{
return __raw_readl(ctx->mmio + reg);
}
static inline void WR(struct au1xpsc_audio_data *ctx, int reg, unsigned long v)
{
__raw_writel(v, ctx->mmio + reg);
wmb();
}
static int au1xi2s_set_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
struct au1xpsc_audio_data *ctx = snd_soc_dai_get_drvdata(cpu_dai);
unsigned long c;
int ret;
ret = -EINVAL;
c = ctx->cfg;
c &= ~CFG_FM_MASK;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
c |= CFG_FM_I2S;
break;
case SND_SOC_DAIFMT_MSB:
c |= CFG_FM_RJ;
break;
case SND_SOC_DAIFMT_LSB:
c |= CFG_FM_LJ;
break;
default:
goto out;
}
c &= ~(CFG_IC | CFG_ICK);
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
c |= CFG_IC | CFG_ICK;
break;
case SND_SOC_DAIFMT_NB_IF:
c |= CFG_IC;
break;
case SND_SOC_DAIFMT_IB_NF:
c |= CFG_ICK;
break;
case SND_SOC_DAIFMT_IB_IF:
break;
default:
goto out;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
goto out;
}
ret = 0;
ctx->cfg = c;
out:
return ret;
}
static int au1xi2s_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
struct au1xpsc_audio_data *ctx = snd_soc_dai_get_drvdata(dai);
int stype = SUBSTREAM_TYPE(substream);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
WR(ctx, I2S_ENABLE, EN_D | EN_CE);
WR(ctx, I2S_ENABLE, EN_CE);
ctx->cfg |= (stype == PCM_TX) ? CFG_TN : CFG_RN;
WR(ctx, I2S_CFG, ctx->cfg);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
ctx->cfg &= ~((stype == PCM_TX) ? CFG_TN : CFG_RN);
WR(ctx, I2S_CFG, ctx->cfg);
WR(ctx, I2S_ENABLE, EN_D);
break;
default:
return -EINVAL;
}
return 0;
}
static unsigned long msbits_to_reg(int msbits)
{
switch (msbits) {
case 8:
return CFG_SZ_8;
case 16:
return CFG_SZ_16;
case 18:
return CFG_SZ_18;
case 20:
return CFG_SZ_20;
case 24:
return CFG_SZ_24;
}
return 0;
}
static int au1xi2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct au1xpsc_audio_data *ctx = snd_soc_dai_get_drvdata(dai);
unsigned long v;
v = msbits_to_reg(params->msbits);
if (!v)
return -EINVAL;
ctx->cfg &= ~CFG_SZ_MASK;
ctx->cfg |= v;
return 0;
}
static int au1xi2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct au1xpsc_audio_data *ctx = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_set_dma_data(dai, substream, &ctx->dmaids[0]);
return 0;
}
static int au1xi2s_drvprobe(struct platform_device *pdev)
{
struct resource *iores, *dmares;
struct au1xpsc_audio_data *ctx;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iores)
return -ENODEV;
if (!devm_request_mem_region(&pdev->dev, iores->start,
resource_size(iores),
pdev->name))
return -EBUSY;
ctx->mmio = devm_ioremap_nocache(&pdev->dev, iores->start,
resource_size(iores));
if (!ctx->mmio)
return -EBUSY;
dmares = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!dmares)
return -EBUSY;
ctx->dmaids[SNDRV_PCM_STREAM_PLAYBACK] = dmares->start;
dmares = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (!dmares)
return -EBUSY;
ctx->dmaids[SNDRV_PCM_STREAM_CAPTURE] = dmares->start;
platform_set_drvdata(pdev, ctx);
return snd_soc_register_dai(&pdev->dev, &au1xi2s_dai_driver);
}
static int au1xi2s_drvremove(struct platform_device *pdev)
{
struct au1xpsc_audio_data *ctx = platform_get_drvdata(pdev);
snd_soc_unregister_dai(&pdev->dev);
WR(ctx, I2S_ENABLE, EN_D);
return 0;
}
static int au1xi2s_drvsuspend(struct device *dev)
{
struct au1xpsc_audio_data *ctx = dev_get_drvdata(dev);
WR(ctx, I2S_ENABLE, EN_D);
return 0;
}
static int au1xi2s_drvresume(struct device *dev)
{
return 0;
}
