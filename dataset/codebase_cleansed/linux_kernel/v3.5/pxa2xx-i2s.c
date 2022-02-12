static int pxa2xx_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
if (IS_ERR(clk_i2s))
return PTR_ERR(clk_i2s);
if (!cpu_dai->active)
SACR0 = 0;
return 0;
}
static int pxa_i2s_wait(void)
{
int i;
for(i = 0; i < 16; i++)
SADR;
return 0;
}
static int pxa2xx_i2s_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
pxa_i2s.fmt = 0;
break;
case SND_SOC_DAIFMT_LEFT_J:
pxa_i2s.fmt = SACR1_AMSL;
break;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
pxa_i2s.master = 1;
break;
case SND_SOC_DAIFMT_CBM_CFS:
pxa_i2s.master = 0;
break;
default:
break;
}
return 0;
}
static int pxa2xx_i2s_set_dai_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int dir)
{
if (clk_id != PXA2XX_I2S_SYSCLK)
return -ENODEV;
return 0;
}
static int pxa2xx_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct pxa2xx_pcm_dma_params *dma_data;
BUG_ON(IS_ERR(clk_i2s));
clk_prepare_enable(clk_i2s);
clk_ena = 1;
pxa_i2s_wait();
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dma_data = &pxa2xx_i2s_pcm_stereo_out;
else
dma_data = &pxa2xx_i2s_pcm_stereo_in;
snd_soc_dai_set_dma_data(dai, substream, dma_data);
if (!(SACR0 & SACR0_ENB)) {
SACR0 = 0;
if (pxa_i2s.master)
SACR0 |= SACR0_BCKD;
SACR0 |= SACR0_RFTH(14) | SACR0_TFTH(1);
SACR1 |= pxa_i2s.fmt;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
SAIMR |= SAIMR_TFS;
else
SAIMR |= SAIMR_RFS;
switch (params_rate(params)) {
case 8000:
SADIV = 0x48;
break;
case 11025:
SADIV = 0x34;
break;
case 16000:
SADIV = 0x24;
break;
case 22050:
SADIV = 0x1a;
break;
case 44100:
SADIV = 0xd;
break;
case 48000:
SADIV = 0xc;
break;
case 96000:
SADIV = 0x6;
break;
}
return 0;
}
static int pxa2xx_i2s_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
SACR1 &= ~SACR1_DRPL;
else
SACR1 &= ~SACR1_DREC;
SACR0 |= SACR0_ENB;
break;
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
break;
default:
ret = -EINVAL;
}
return ret;
}
static void pxa2xx_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
SACR1 |= SACR1_DRPL;
SAIMR &= ~SAIMR_TFS;
} else {
SACR1 |= SACR1_DREC;
SAIMR &= ~SAIMR_RFS;
}
if ((SACR1 & (SACR1_DREC | SACR1_DRPL)) == (SACR1_DREC | SACR1_DRPL)) {
SACR0 &= ~SACR0_ENB;
pxa_i2s_wait();
if (clk_ena) {
clk_disable_unprepare(clk_i2s);
clk_ena = 0;
}
}
}
static int pxa2xx_i2s_suspend(struct snd_soc_dai *dai)
{
pxa_i2s.sacr0 = SACR0;
pxa_i2s.sacr1 = SACR1;
pxa_i2s.saimr = SAIMR;
pxa_i2s.sadiv = SADIV;
SACR0 &= ~SACR0_ENB;
pxa_i2s_wait();
return 0;
}
static int pxa2xx_i2s_resume(struct snd_soc_dai *dai)
{
pxa_i2s_wait();
SACR0 = pxa_i2s.sacr0 & ~SACR0_ENB;
SACR1 = pxa_i2s.sacr1;
SAIMR = pxa_i2s.saimr;
SADIV = pxa_i2s.sadiv;
SACR0 = pxa_i2s.sacr0;
return 0;
}
static int pxa2xx_i2s_probe(struct snd_soc_dai *dai)
{
clk_i2s = clk_get(dai->dev, "I2SCLK");
if (IS_ERR(clk_i2s))
return PTR_ERR(clk_i2s);
SACR0 = SACR0_RST;
SACR0 = 0;
SACR1 = SACR1_DRPL | SACR1_DREC;
SAIMR &= ~(SAIMR_RFS | SAIMR_TFS);
return 0;
}
static int pxa2xx_i2s_remove(struct snd_soc_dai *dai)
{
clk_put(clk_i2s);
clk_i2s = ERR_PTR(-ENOENT);
return 0;
}
static int pxa2xx_i2s_drv_probe(struct platform_device *pdev)
{
return snd_soc_register_dai(&pdev->dev, &pxa_i2s_dai);
}
static int __devexit pxa2xx_i2s_drv_remove(struct platform_device *pdev)
{
snd_soc_unregister_dai(&pdev->dev);
return 0;
}
static int __init pxa2xx_i2s_init(void)
{
clk_i2s = ERR_PTR(-ENOENT);
return platform_driver_register(&pxa2xx_i2s_driver);
}
static void __exit pxa2xx_i2s_exit(void)
{
platform_driver_unregister(&pxa2xx_i2s_driver);
}
