static unsigned short au1xpsc_ac97_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct au1xpsc_audio_data *pscdata = ac97_to_pscdata(ac97);
unsigned short retry, tmo;
unsigned long data;
__raw_writel(PSC_AC97EVNT_CD, AC97_EVNT(pscdata));
wmb();
retry = AC97_RW_RETRIES;
do {
mutex_lock(&pscdata->lock);
__raw_writel(PSC_AC97CDC_RD | PSC_AC97CDC_INDX(reg),
AC97_CDC(pscdata));
wmb();
tmo = 20;
do {
udelay(21);
if (__raw_readl(AC97_EVNT(pscdata)) & PSC_AC97EVNT_CD)
break;
} while (--tmo);
data = __raw_readl(AC97_CDC(pscdata));
__raw_writel(PSC_AC97EVNT_CD, AC97_EVNT(pscdata));
wmb();
mutex_unlock(&pscdata->lock);
if (reg != ((data >> 16) & 0x7f))
tmo = 1;
} while (--retry && !tmo);
return retry ? data & 0xffff : 0xffff;
}
static void au1xpsc_ac97_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
struct au1xpsc_audio_data *pscdata = ac97_to_pscdata(ac97);
unsigned int tmo, retry;
__raw_writel(PSC_AC97EVNT_CD, AC97_EVNT(pscdata));
wmb();
retry = AC97_RW_RETRIES;
do {
mutex_lock(&pscdata->lock);
__raw_writel(PSC_AC97CDC_INDX(reg) | (val & 0xffff),
AC97_CDC(pscdata));
wmb();
tmo = 20;
do {
udelay(21);
if (__raw_readl(AC97_EVNT(pscdata)) & PSC_AC97EVNT_CD)
break;
} while (--tmo);
__raw_writel(PSC_AC97EVNT_CD, AC97_EVNT(pscdata));
wmb();
mutex_unlock(&pscdata->lock);
} while (--retry && !tmo);
}
static void au1xpsc_ac97_warm_reset(struct snd_ac97 *ac97)
{
struct au1xpsc_audio_data *pscdata = ac97_to_pscdata(ac97);
__raw_writel(PSC_AC97RST_SNC, AC97_RST(pscdata));
wmb();
msleep(10);
__raw_writel(0, AC97_RST(pscdata));
wmb();
}
static void au1xpsc_ac97_cold_reset(struct snd_ac97 *ac97)
{
struct au1xpsc_audio_data *pscdata = ac97_to_pscdata(ac97);
int i;
__raw_writel(0, AC97_CFG(au1xpsc_ac97_workdata));
wmb();
__raw_writel(PSC_CTRL_DISABLE, PSC_CTRL(pscdata));
wmb();
__raw_writel(PSC_AC97RST_RST, AC97_RST(pscdata));
wmb();
msleep(500);
__raw_writel(0, AC97_RST(pscdata));
wmb();
__raw_writel(PSC_CTRL_ENABLE, PSC_CTRL(pscdata));
wmb();
i = 1000;
while (!((__raw_readl(AC97_STAT(pscdata)) & PSC_AC97STAT_SR)) && (--i))
msleep(1);
if (i == 0) {
printk(KERN_ERR "au1xpsc-ac97: PSC not ready!\n");
return;
}
__raw_writel(pscdata->cfg | PSC_AC97CFG_DE_ENABLE, AC97_CFG(pscdata));
wmb();
i = 1000;
while (!((__raw_readl(AC97_STAT(pscdata)) & PSC_AC97STAT_DR)) && (--i))
msleep(1);
if (i == 0)
printk(KERN_ERR "au1xpsc-ac97: AC97 ctrl not ready\n");
}
static int au1xpsc_ac97_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct au1xpsc_audio_data *pscdata = snd_soc_dai_get_drvdata(dai);
unsigned long r, ro, stat;
int chans, t, stype = substream->stream;
chans = params_channels(params);
r = ro = __raw_readl(AC97_CFG(pscdata));
stat = __raw_readl(AC97_STAT(pscdata));
if (stat & (PSC_AC97STAT_TB | PSC_AC97STAT_RB)) {
if ((PSC_AC97CFG_GET_LEN(r) != params->msbits) ||
(pscdata->rate != params_rate(params)))
return -EINVAL;
} else {
r &= ~PSC_AC97CFG_LEN_MASK;
r |= PSC_AC97CFG_SET_LEN(params->msbits);
if (stype == SNDRV_PCM_STREAM_PLAYBACK) {
r &= ~PSC_AC97CFG_TXSLOT_MASK;
r |= PSC_AC97CFG_TXSLOT_ENA(3);
r |= PSC_AC97CFG_TXSLOT_ENA(4);
} else {
r &= ~PSC_AC97CFG_RXSLOT_MASK;
r |= PSC_AC97CFG_RXSLOT_ENA(3);
r |= PSC_AC97CFG_RXSLOT_ENA(4);
}
if (!(r ^ ro))
goto out;
mutex_lock(&pscdata->lock);
__raw_writel(r & ~PSC_AC97CFG_DE_ENABLE, AC97_CFG(pscdata));
wmb();
t = 100;
while ((__raw_readl(AC97_STAT(pscdata)) & PSC_AC97STAT_DR) && --t)
msleep(1);
if (!t)
printk(KERN_ERR "PSC-AC97: can't disable!\n");
__raw_writel(r, AC97_CFG(pscdata));
wmb();
__raw_writel(r | PSC_AC97CFG_DE_ENABLE, AC97_CFG(pscdata));
wmb();
t = 100;
while ((!(__raw_readl(AC97_STAT(pscdata)) & PSC_AC97STAT_DR)) && --t)
msleep(1);
if (!t)
printk(KERN_ERR "PSC-AC97: can't enable!\n");
mutex_unlock(&pscdata->lock);
pscdata->cfg = r;
pscdata->rate = params_rate(params);
}
out:
return 0;
}
static int au1xpsc_ac97_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
struct au1xpsc_audio_data *pscdata = snd_soc_dai_get_drvdata(dai);
int ret, stype = substream->stream;
ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
__raw_writel(AC97PCR_CLRFIFO(stype), AC97_PCR(pscdata));
wmb();
__raw_writel(AC97PCR_START(stype), AC97_PCR(pscdata));
wmb();
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
__raw_writel(AC97PCR_STOP(stype), AC97_PCR(pscdata));
wmb();
while (__raw_readl(AC97_STAT(pscdata)) & AC97STAT_BUSY(stype))
asm volatile ("nop");
__raw_writel(AC97PCR_CLRFIFO(stype), AC97_PCR(pscdata));
wmb();
break;
default:
ret = -EINVAL;
}
return ret;
}
static int au1xpsc_ac97_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct au1xpsc_audio_data *pscdata = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_set_dma_data(dai, substream, &pscdata->dmaids[0]);
return 0;
}
static int au1xpsc_ac97_probe(struct snd_soc_dai *dai)
{
return au1xpsc_ac97_workdata ? 0 : -ENODEV;
}
static int au1xpsc_ac97_drvprobe(struct platform_device *pdev)
{
int ret;
struct resource *iores, *dmares;
unsigned long sel;
struct au1xpsc_audio_data *wd;
wd = devm_kzalloc(&pdev->dev, sizeof(struct au1xpsc_audio_data),
GFP_KERNEL);
if (!wd)
return -ENOMEM;
mutex_init(&wd->lock);
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wd->mmio = devm_ioremap_resource(&pdev->dev, iores);
if (IS_ERR(wd->mmio))
return PTR_ERR(wd->mmio);
dmares = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!dmares)
return -EBUSY;
wd->dmaids[SNDRV_PCM_STREAM_PLAYBACK] = dmares->start;
dmares = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (!dmares)
return -EBUSY;
wd->dmaids[SNDRV_PCM_STREAM_CAPTURE] = dmares->start;
wd->cfg = PSC_AC97CFG_RT_FIFO8 | PSC_AC97CFG_TT_FIFO8 |
PSC_AC97CFG_DE_ENABLE;
sel = __raw_readl(PSC_SEL(wd)) & PSC_SEL_CLK_MASK;
__raw_writel(PSC_CTRL_DISABLE, PSC_CTRL(wd));
wmb();
__raw_writel(0, PSC_SEL(wd));
wmb();
__raw_writel(PSC_SEL_PS_AC97MODE | sel, PSC_SEL(wd));
wmb();
memcpy(&wd->dai_drv, &au1xpsc_ac97_dai_template,
sizeof(struct snd_soc_dai_driver));
wd->dai_drv.name = dev_name(&pdev->dev);
platform_set_drvdata(pdev, wd);
ret = snd_soc_set_ac97_ops(&psc_ac97_ops);
if (ret)
return ret;
ret = snd_soc_register_component(&pdev->dev, &au1xpsc_ac97_component,
&wd->dai_drv, 1);
if (ret)
return ret;
au1xpsc_ac97_workdata = wd;
return 0;
}
static int au1xpsc_ac97_drvremove(struct platform_device *pdev)
{
struct au1xpsc_audio_data *wd = platform_get_drvdata(pdev);
snd_soc_unregister_component(&pdev->dev);
__raw_writel(0, AC97_CFG(wd));
wmb();
__raw_writel(PSC_CTRL_DISABLE, PSC_CTRL(wd));
wmb();
au1xpsc_ac97_workdata = NULL;
return 0;
}
static int au1xpsc_ac97_drvsuspend(struct device *dev)
{
struct au1xpsc_audio_data *wd = dev_get_drvdata(dev);
wd->pm[0] = __raw_readl(PSC_SEL(wd));
__raw_writel(0, AC97_CFG(wd));
wmb();
__raw_writel(PSC_CTRL_DISABLE, PSC_CTRL(wd));
wmb();
return 0;
}
static int au1xpsc_ac97_drvresume(struct device *dev)
{
struct au1xpsc_audio_data *wd = dev_get_drvdata(dev);
__raw_writel(wd->pm[0] | PSC_SEL_PS_AC97MODE, PSC_SEL(wd));
wmb();
return 0;
}
