static int au1xpsc_i2s_set_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct au1xpsc_audio_data *pscdata = snd_soc_dai_get_drvdata(cpu_dai);
unsigned long ct;
int ret;
ret = -EINVAL;
ct = pscdata->cfg;
ct &= ~(PSC_I2SCFG_XM | PSC_I2SCFG_MLJ);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
ct |= PSC_I2SCFG_XM;
break;
case SND_SOC_DAIFMT_MSB:
break;
case SND_SOC_DAIFMT_LSB:
ct |= PSC_I2SCFG_MLJ;
break;
default:
goto out;
}
ct &= ~(PSC_I2SCFG_BI | PSC_I2SCFG_WI);
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
ct |= PSC_I2SCFG_BI | PSC_I2SCFG_WI;
break;
case SND_SOC_DAIFMT_NB_IF:
ct |= PSC_I2SCFG_BI;
break;
case SND_SOC_DAIFMT_IB_NF:
ct |= PSC_I2SCFG_WI;
break;
case SND_SOC_DAIFMT_IB_IF:
break;
default:
goto out;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
ct |= PSC_I2SCFG_MS;
break;
case SND_SOC_DAIFMT_CBS_CFS:
ct &= ~PSC_I2SCFG_MS;
break;
default:
goto out;
}
pscdata->cfg = ct;
ret = 0;
out:
return ret;
}
static int au1xpsc_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct au1xpsc_audio_data *pscdata = snd_soc_dai_get_drvdata(dai);
int cfgbits;
unsigned long stat;
stat = __raw_readl(I2S_STAT(pscdata));
if (stat & (PSC_I2SSTAT_TB | PSC_I2SSTAT_RB)) {
cfgbits = __raw_readl(I2S_CFG(pscdata));
if ((PSC_I2SCFG_GET_LEN(cfgbits) != params->msbits) ||
(params_rate(params) != pscdata->rate))
return -EINVAL;
} else {
pscdata->cfg &= ~(0x1f << 4);
pscdata->cfg |= PSC_I2SCFG_SET_LEN(params->msbits);
pscdata->rate = params_rate(params);
}
return 0;
}
static int au1xpsc_i2s_configure(struct au1xpsc_audio_data *pscdata)
{
unsigned long tmo;
__raw_writel(PSC_CTRL_ENABLE, PSC_CTRL(pscdata));
wmb();
tmo = 1000000;
while (!(__raw_readl(I2S_STAT(pscdata)) & PSC_I2SSTAT_SR) && tmo)
tmo--;
if (!tmo)
goto psc_err;
__raw_writel(0, I2S_CFG(pscdata));
wmb();
__raw_writel(pscdata->cfg | PSC_I2SCFG_DE_ENABLE, I2S_CFG(pscdata));
wmb();
tmo = 1000000;
while (!(__raw_readl(I2S_STAT(pscdata)) & PSC_I2SSTAT_DR) && tmo)
tmo--;
if (tmo)
return 0;
psc_err:
__raw_writel(0, I2S_CFG(pscdata));
__raw_writel(PSC_CTRL_SUSPEND, PSC_CTRL(pscdata));
wmb();
return -ETIMEDOUT;
}
static int au1xpsc_i2s_start(struct au1xpsc_audio_data *pscdata, int stype)
{
unsigned long tmo, stat;
int ret;
ret = 0;
stat = __raw_readl(I2S_STAT(pscdata));
if (!(stat & (PSC_I2SSTAT_TB | PSC_I2SSTAT_RB))) {
ret = au1xpsc_i2s_configure(pscdata);
if (ret)
goto out;
}
__raw_writel(I2SPCR_CLRFIFO(stype), I2S_PCR(pscdata));
wmb();
__raw_writel(I2SPCR_START(stype), I2S_PCR(pscdata));
wmb();
tmo = 1000000;
while (!(__raw_readl(I2S_STAT(pscdata)) & I2SSTAT_BUSY(stype)) && tmo)
tmo--;
if (!tmo) {
__raw_writel(I2SPCR_STOP(stype), I2S_PCR(pscdata));
wmb();
ret = -ETIMEDOUT;
}
out:
return ret;
}
static int au1xpsc_i2s_stop(struct au1xpsc_audio_data *pscdata, int stype)
{
unsigned long tmo, stat;
__raw_writel(I2SPCR_STOP(stype), I2S_PCR(pscdata));
wmb();
tmo = 1000000;
while ((__raw_readl(I2S_STAT(pscdata)) & I2SSTAT_BUSY(stype)) && tmo)
tmo--;
stat = __raw_readl(I2S_STAT(pscdata));
if (!(stat & (PSC_I2SSTAT_TB | PSC_I2SSTAT_RB))) {
__raw_writel(0, I2S_CFG(pscdata));
wmb();
__raw_writel(PSC_CTRL_SUSPEND, PSC_CTRL(pscdata));
wmb();
}
return 0;
}
static int au1xpsc_i2s_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct au1xpsc_audio_data *pscdata = snd_soc_dai_get_drvdata(dai);
int ret, stype = substream->stream;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
ret = au1xpsc_i2s_start(pscdata, stype);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
ret = au1xpsc_i2s_stop(pscdata, stype);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int au1xpsc_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct au1xpsc_audio_data *pscdata = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_set_dma_data(dai, substream, &pscdata->dmaids[0]);
return 0;
}
static int au1xpsc_i2s_drvprobe(struct platform_device *pdev)
{
struct resource *iores, *dmares;
unsigned long sel;
int ret;
struct au1xpsc_audio_data *wd;
wd = devm_kzalloc(&pdev->dev, sizeof(struct au1xpsc_audio_data),
GFP_KERNEL);
if (!wd)
return -ENOMEM;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iores)
return -ENODEV;
ret = -EBUSY;
if (!devm_request_mem_region(&pdev->dev, iores->start,
resource_size(iores),
pdev->name))
return -EBUSY;
wd->mmio = devm_ioremap(&pdev->dev, iores->start,
resource_size(iores));
if (!wd->mmio)
return -EBUSY;
dmares = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!dmares)
return -EBUSY;
wd->dmaids[SNDRV_PCM_STREAM_PLAYBACK] = dmares->start;
dmares = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (!dmares)
return -EBUSY;
wd->dmaids[SNDRV_PCM_STREAM_CAPTURE] = dmares->start;
sel = __raw_readl(PSC_SEL(wd)) & PSC_SEL_CLK_MASK;
__raw_writel(PSC_CTRL_DISABLE, PSC_CTRL(wd));
wmb();
__raw_writel(PSC_SEL_PS_I2SMODE | sel, PSC_SEL(wd));
__raw_writel(0, I2S_CFG(wd));
wmb();
wd->cfg |= PSC_I2SCFG_RT_FIFO8 | PSC_I2SCFG_TT_FIFO8;
memcpy(&wd->dai_drv, &au1xpsc_i2s_dai_template,
sizeof(struct snd_soc_dai_driver));
wd->dai_drv.name = dev_name(&pdev->dev);
platform_set_drvdata(pdev, wd);
return snd_soc_register_component(&pdev->dev, &au1xpsc_i2s_component,
&wd->dai_drv, 1);
}
static int au1xpsc_i2s_drvremove(struct platform_device *pdev)
{
struct au1xpsc_audio_data *wd = platform_get_drvdata(pdev);
snd_soc_unregister_component(&pdev->dev);
__raw_writel(0, I2S_CFG(wd));
wmb();
__raw_writel(PSC_CTRL_DISABLE, PSC_CTRL(wd));
wmb();
return 0;
}
static int au1xpsc_i2s_drvsuspend(struct device *dev)
{
struct au1xpsc_audio_data *wd = dev_get_drvdata(dev);
wd->pm[0] = __raw_readl(PSC_SEL(wd));
__raw_writel(0, I2S_CFG(wd));
wmb();
__raw_writel(PSC_CTRL_DISABLE, PSC_CTRL(wd));
wmb();
return 0;
}
static int au1xpsc_i2s_drvresume(struct device *dev)
{
struct au1xpsc_audio_data *wd = dev_get_drvdata(dev);
__raw_writel(PSC_CTRL_DISABLE, PSC_CTRL(wd));
wmb();
__raw_writel(0, PSC_SEL(wd));
wmb();
__raw_writel(wd->pm[0], PSC_SEL(wd));
wmb();
return 0;
}
