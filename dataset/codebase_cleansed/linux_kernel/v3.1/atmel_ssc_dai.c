static irqreturn_t atmel_ssc_interrupt(int irq, void *dev_id)
{
struct atmel_ssc_info *ssc_p = dev_id;
struct atmel_pcm_dma_params *dma_params;
u32 ssc_sr;
u32 ssc_substream_mask;
int i;
ssc_sr = (unsigned long)ssc_readl(ssc_p->ssc->regs, SR)
& (unsigned long)ssc_readl(ssc_p->ssc->regs, IMR);
for (i = 0; i < ARRAY_SIZE(ssc_p->dma_params); i++) {
dma_params = ssc_p->dma_params[i];
if ((dma_params != NULL) &&
(dma_params->dma_intr_handler != NULL)) {
ssc_substream_mask = (dma_params->mask->ssc_endx |
dma_params->mask->ssc_endbuf);
if (ssc_sr & ssc_substream_mask) {
dma_params->dma_intr_handler(ssc_sr,
dma_params->
substream);
}
}
}
return IRQ_HANDLED;
}
static int atmel_ssc_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct atmel_ssc_info *ssc_p = &ssc_info[dai->id];
int dir_mask;
pr_debug("atmel_ssc_startup: SSC_SR=0x%u\n",
ssc_readl(ssc_p->ssc->regs, SR));
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dir_mask = SSC_DIR_MASK_PLAYBACK;
else
dir_mask = SSC_DIR_MASK_CAPTURE;
spin_lock_irq(&ssc_p->lock);
if (ssc_p->dir_mask & dir_mask) {
spin_unlock_irq(&ssc_p->lock);
return -EBUSY;
}
ssc_p->dir_mask |= dir_mask;
spin_unlock_irq(&ssc_p->lock);
return 0;
}
static void atmel_ssc_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct atmel_ssc_info *ssc_p = &ssc_info[dai->id];
struct atmel_pcm_dma_params *dma_params;
int dir, dir_mask;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dir = 0;
else
dir = 1;
dma_params = ssc_p->dma_params[dir];
if (dma_params != NULL) {
ssc_writel(ssc_p->ssc->regs, CR, dma_params->mask->ssc_disable);
pr_debug("atmel_ssc_shutdown: %s disabled SSC_SR=0x%08x\n",
(dir ? "receive" : "transmit"),
ssc_readl(ssc_p->ssc->regs, SR));
dma_params->ssc = NULL;
dma_params->substream = NULL;
ssc_p->dma_params[dir] = NULL;
}
dir_mask = 1 << dir;
spin_lock_irq(&ssc_p->lock);
ssc_p->dir_mask &= ~dir_mask;
if (!ssc_p->dir_mask) {
if (ssc_p->initialized) {
pr_debug("atmel_ssc_dau: Stopping clock\n");
clk_disable(ssc_p->ssc->clk);
free_irq(ssc_p->ssc->irq, ssc_p);
ssc_p->initialized = 0;
}
ssc_writel(ssc_p->ssc->regs, CR, SSC_BIT(CR_SWRST));
ssc_p->cmr_div = ssc_p->tcmr_period = ssc_p->rcmr_period = 0;
}
spin_unlock_irq(&ssc_p->lock);
}
static int atmel_ssc_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct atmel_ssc_info *ssc_p = &ssc_info[cpu_dai->id];
ssc_p->daifmt = fmt;
return 0;
}
static int atmel_ssc_set_dai_clkdiv(struct snd_soc_dai *cpu_dai,
int div_id, int div)
{
struct atmel_ssc_info *ssc_p = &ssc_info[cpu_dai->id];
switch (div_id) {
case ATMEL_SSC_CMR_DIV:
if (ssc_p->cmr_div == 0)
ssc_p->cmr_div = div;
else
if (div != ssc_p->cmr_div)
return -EBUSY;
break;
case ATMEL_SSC_TCMR_PERIOD:
ssc_p->tcmr_period = div;
break;
case ATMEL_SSC_RCMR_PERIOD:
ssc_p->rcmr_period = div;
break;
default:
return -EINVAL;
}
return 0;
}
static int atmel_ssc_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = snd_pcm_substream_chip(substream);
int id = dai->id;
struct atmel_ssc_info *ssc_p = &ssc_info[id];
struct atmel_pcm_dma_params *dma_params;
int dir, channels, bits;
u32 tfmr, rfmr, tcmr, rcmr;
int start_event;
int ret;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dir = 0;
else
dir = 1;
dma_params = &ssc_dma_params[id][dir];
dma_params->ssc = ssc_p->ssc;
dma_params->substream = substream;
ssc_p->dma_params[dir] = dma_params;
snd_soc_dai_set_dma_data(rtd->cpu_dai, substream, dma_params);
channels = params_channels(params);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
bits = 8;
dma_params->pdc_xfer_size = 1;
break;
case SNDRV_PCM_FORMAT_S16_LE:
bits = 16;
dma_params->pdc_xfer_size = 2;
break;
case SNDRV_PCM_FORMAT_S24_LE:
bits = 24;
dma_params->pdc_xfer_size = 4;
break;
case SNDRV_PCM_FORMAT_S32_LE:
bits = 32;
dma_params->pdc_xfer_size = 4;
break;
default:
printk(KERN_WARNING "atmel_ssc_dai: unsupported PCM format");
return -EINVAL;
}
if ((ssc_p->daifmt & SND_SOC_DAIFMT_FORMAT_MASK) == SND_SOC_DAIFMT_I2S
&& bits > 16) {
printk(KERN_WARNING
"atmel_ssc_dai: sample size %d "
"is too large for I2S\n", bits);
return -EINVAL;
}
switch (ssc_p->daifmt
& (SND_SOC_DAIFMT_FORMAT_MASK | SND_SOC_DAIFMT_MASTER_MASK)) {
case SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_CBS_CFS:
rcmr = SSC_BF(RCMR_PERIOD, ssc_p->rcmr_period)
| SSC_BF(RCMR_STTDLY, START_DELAY)
| SSC_BF(RCMR_START, SSC_START_FALLING_RF)
| SSC_BF(RCMR_CKI, SSC_CKI_RISING)
| SSC_BF(RCMR_CKO, SSC_CKO_NONE)
| SSC_BF(RCMR_CKS, SSC_CKS_DIV);
rfmr = SSC_BF(RFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(RFMR_FSOS, SSC_FSOS_NEGATIVE)
| SSC_BF(RFMR_FSLEN, (bits - 1))
| SSC_BF(RFMR_DATNB, (channels - 1))
| SSC_BIT(RFMR_MSBF)
| SSC_BF(RFMR_LOOP, 0)
| SSC_BF(RFMR_DATLEN, (bits - 1));
tcmr = SSC_BF(TCMR_PERIOD, ssc_p->tcmr_period)
| SSC_BF(TCMR_STTDLY, START_DELAY)
| SSC_BF(TCMR_START, SSC_START_FALLING_RF)
| SSC_BF(TCMR_CKI, SSC_CKI_FALLING)
| SSC_BF(TCMR_CKO, SSC_CKO_CONTINUOUS)
| SSC_BF(TCMR_CKS, SSC_CKS_DIV);
tfmr = SSC_BF(TFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(TFMR_FSDEN, 0)
| SSC_BF(TFMR_FSOS, SSC_FSOS_NEGATIVE)
| SSC_BF(TFMR_FSLEN, (bits - 1))
| SSC_BF(TFMR_DATNB, (channels - 1))
| SSC_BIT(TFMR_MSBF)
| SSC_BF(TFMR_DATDEF, 0)
| SSC_BF(TFMR_DATLEN, (bits - 1));
break;
case SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_CBM_CFM:
start_event = ((channels == 1)
? SSC_START_FALLING_RF
: SSC_START_EDGE_RF);
rcmr = SSC_BF(RCMR_PERIOD, 0)
| SSC_BF(RCMR_STTDLY, START_DELAY)
| SSC_BF(RCMR_START, start_event)
| SSC_BF(RCMR_CKI, SSC_CKI_RISING)
| SSC_BF(RCMR_CKO, SSC_CKO_NONE)
| SSC_BF(RCMR_CKS, SSC_CKS_CLOCK);
rfmr = SSC_BF(RFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(RFMR_FSOS, SSC_FSOS_NONE)
| SSC_BF(RFMR_FSLEN, 0)
| SSC_BF(RFMR_DATNB, 0)
| SSC_BIT(RFMR_MSBF)
| SSC_BF(RFMR_LOOP, 0)
| SSC_BF(RFMR_DATLEN, (bits - 1));
tcmr = SSC_BF(TCMR_PERIOD, 0)
| SSC_BF(TCMR_STTDLY, START_DELAY)
| SSC_BF(TCMR_START, start_event)
| SSC_BF(TCMR_CKI, SSC_CKI_FALLING)
| SSC_BF(TCMR_CKO, SSC_CKO_NONE)
| SSC_BF(TCMR_CKS, SSC_CKS_PIN);
tfmr = SSC_BF(TFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(TFMR_FSDEN, 0)
| SSC_BF(TFMR_FSOS, SSC_FSOS_NONE)
| SSC_BF(TFMR_FSLEN, 0)
| SSC_BF(TFMR_DATNB, 0)
| SSC_BIT(TFMR_MSBF)
| SSC_BF(TFMR_DATDEF, 0)
| SSC_BF(TFMR_DATLEN, (bits - 1));
break;
case SND_SOC_DAIFMT_DSP_A | SND_SOC_DAIFMT_CBS_CFS:
rcmr = SSC_BF(RCMR_PERIOD, ssc_p->rcmr_period)
| SSC_BF(RCMR_STTDLY, 1)
| SSC_BF(RCMR_START, SSC_START_RISING_RF)
| SSC_BF(RCMR_CKI, SSC_CKI_RISING)
| SSC_BF(RCMR_CKO, SSC_CKO_NONE)
| SSC_BF(RCMR_CKS, SSC_CKS_DIV);
rfmr = SSC_BF(RFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(RFMR_FSOS, SSC_FSOS_POSITIVE)
| SSC_BF(RFMR_FSLEN, 0)
| SSC_BF(RFMR_DATNB, (channels - 1))
| SSC_BIT(RFMR_MSBF)
| SSC_BF(RFMR_LOOP, 0)
| SSC_BF(RFMR_DATLEN, (bits - 1));
tcmr = SSC_BF(TCMR_PERIOD, ssc_p->tcmr_period)
| SSC_BF(TCMR_STTDLY, 1)
| SSC_BF(TCMR_START, SSC_START_RISING_RF)
| SSC_BF(TCMR_CKI, SSC_CKI_RISING)
| SSC_BF(TCMR_CKO, SSC_CKO_CONTINUOUS)
| SSC_BF(TCMR_CKS, SSC_CKS_DIV);
tfmr = SSC_BF(TFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(TFMR_FSDEN, 0)
| SSC_BF(TFMR_FSOS, SSC_FSOS_POSITIVE)
| SSC_BF(TFMR_FSLEN, 0)
| SSC_BF(TFMR_DATNB, (channels - 1))
| SSC_BIT(TFMR_MSBF)
| SSC_BF(TFMR_DATDEF, 0)
| SSC_BF(TFMR_DATLEN, (bits - 1));
break;
case SND_SOC_DAIFMT_DSP_A | SND_SOC_DAIFMT_CBM_CFM:
default:
printk(KERN_WARNING "atmel_ssc_dai: unsupported DAI format 0x%x\n",
ssc_p->daifmt);
return -EINVAL;
}
pr_debug("atmel_ssc_hw_params: "
"RCMR=%08x RFMR=%08x TCMR=%08x TFMR=%08x\n",
rcmr, rfmr, tcmr, tfmr);
if (!ssc_p->initialized) {
pr_debug("atmel_ssc_dai: Starting clock\n");
clk_enable(ssc_p->ssc->clk);
ssc_writel(ssc_p->ssc->regs, CR, SSC_BIT(CR_SWRST));
ssc_writel(ssc_p->ssc->regs, PDC_RPR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_RCR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_RNPR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_RNCR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_TPR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_TCR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_TNPR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_TNCR, 0);
ret = request_irq(ssc_p->ssc->irq, atmel_ssc_interrupt, 0,
ssc_p->name, ssc_p);
if (ret < 0) {
printk(KERN_WARNING
"atmel_ssc_dai: request_irq failure\n");
pr_debug("Atmel_ssc_dai: Stoping clock\n");
clk_disable(ssc_p->ssc->clk);
return ret;
}
ssc_p->initialized = 1;
}
ssc_writel(ssc_p->ssc->regs, CMR, ssc_p->cmr_div);
ssc_writel(ssc_p->ssc->regs, RCMR, rcmr);
ssc_writel(ssc_p->ssc->regs, RFMR, rfmr);
ssc_writel(ssc_p->ssc->regs, TCMR, tcmr);
ssc_writel(ssc_p->ssc->regs, TFMR, tfmr);
pr_debug("atmel_ssc_dai,hw_params: SSC initialized\n");
return 0;
}
static int atmel_ssc_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct atmel_ssc_info *ssc_p = &ssc_info[dai->id];
struct atmel_pcm_dma_params *dma_params;
int dir;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dir = 0;
else
dir = 1;
dma_params = ssc_p->dma_params[dir];
ssc_writel(ssc_p->ssc->regs, CR, dma_params->mask->ssc_enable);
pr_debug("%s enabled SSC_SR=0x%08x\n",
dir ? "receive" : "transmit",
ssc_readl(ssc_p->ssc->regs, SR));
return 0;
}
static int atmel_ssc_suspend(struct snd_soc_dai *cpu_dai)
{
struct atmel_ssc_info *ssc_p;
if (!cpu_dai->active)
return 0;
ssc_p = &ssc_info[cpu_dai->id];
ssc_p->ssc_state.ssc_sr = ssc_readl(ssc_p->ssc->regs, SR);
ssc_writel(ssc_p->ssc->regs, CR, SSC_BIT(CR_TXDIS) | SSC_BIT(CR_RXDIS));
ssc_p->ssc_state.ssc_imr = ssc_readl(ssc_p->ssc->regs, IMR);
ssc_writel(ssc_p->ssc->regs, IDR, ssc_p->ssc_state.ssc_imr);
ssc_p->ssc_state.ssc_cmr = ssc_readl(ssc_p->ssc->regs, CMR);
ssc_p->ssc_state.ssc_rcmr = ssc_readl(ssc_p->ssc->regs, RCMR);
ssc_p->ssc_state.ssc_rfmr = ssc_readl(ssc_p->ssc->regs, RFMR);
ssc_p->ssc_state.ssc_tcmr = ssc_readl(ssc_p->ssc->regs, TCMR);
ssc_p->ssc_state.ssc_tfmr = ssc_readl(ssc_p->ssc->regs, TFMR);
return 0;
}
static int atmel_ssc_resume(struct snd_soc_dai *cpu_dai)
{
struct atmel_ssc_info *ssc_p;
u32 cr;
if (!cpu_dai->active)
return 0;
ssc_p = &ssc_info[cpu_dai->id];
ssc_writel(ssc_p->ssc->regs, TFMR, ssc_p->ssc_state.ssc_tfmr);
ssc_writel(ssc_p->ssc->regs, TCMR, ssc_p->ssc_state.ssc_tcmr);
ssc_writel(ssc_p->ssc->regs, RFMR, ssc_p->ssc_state.ssc_rfmr);
ssc_writel(ssc_p->ssc->regs, RCMR, ssc_p->ssc_state.ssc_rcmr);
ssc_writel(ssc_p->ssc->regs, CMR, ssc_p->ssc_state.ssc_cmr);
ssc_writel(ssc_p->ssc->regs, IER, ssc_p->ssc_state.ssc_imr);
cr = 0;
cr |=
(ssc_p->ssc_state.ssc_sr & SSC_BIT(SR_RXEN)) ? SSC_BIT(CR_RXEN) : 0;
cr |=
(ssc_p->ssc_state.ssc_sr & SSC_BIT(SR_TXEN)) ? SSC_BIT(CR_TXEN) : 0;
ssc_writel(ssc_p->ssc->regs, CR, cr);
return 0;
}
static int atmel_ssc_probe(struct snd_soc_dai *dai)
{
struct atmel_ssc_info *ssc_p = &ssc_info[dai->id];
int ret = 0;
snd_soc_dai_set_drvdata(dai, ssc_p);
ssc_p->ssc = ssc_request(dai->id);
if (IS_ERR(ssc_p->ssc)) {
printk(KERN_ERR "ASoC: Failed to request SSC %d\n", dai->id);
ret = PTR_ERR(ssc_p->ssc);
}
return ret;
}
static int atmel_ssc_remove(struct snd_soc_dai *dai)
{
struct atmel_ssc_info *ssc_p = snd_soc_dai_get_drvdata(dai);
ssc_free(ssc_p->ssc);
return 0;
}
static __devinit int asoc_ssc_probe(struct platform_device *pdev)
{
BUG_ON(pdev->id < 0);
BUG_ON(pdev->id >= ARRAY_SIZE(atmel_ssc_dai));
return snd_soc_register_dai(&pdev->dev, &atmel_ssc_dai[pdev->id]);
}
static int __devexit asoc_ssc_remove(struct platform_device *pdev)
{
snd_soc_unregister_dai(&pdev->dev);
return 0;
}
int atmel_ssc_set_audio(int ssc_id)
{
struct ssc_device *ssc;
static struct platform_device *dma_pdev;
struct platform_device *ssc_pdev;
int ret;
if (ssc_id < 0 || ssc_id >= ARRAY_SIZE(atmel_ssc_dai))
return -EINVAL;
if (!dma_pdev) {
dma_pdev = platform_device_alloc("atmel-pcm-audio", -1);
if (!dma_pdev)
return -ENOMEM;
ret = platform_device_add(dma_pdev);
if (ret < 0) {
platform_device_put(dma_pdev);
dma_pdev = NULL;
return ret;
}
}
ssc_pdev = platform_device_alloc("atmel-ssc-dai", ssc_id);
if (!ssc_pdev)
return -ENOMEM;
ssc = ssc_request(ssc_id);
if (IS_ERR(ssc))
pr_warn("Unable to parent ASoC SSC DAI on SSC: %ld\n",
PTR_ERR(ssc));
else {
ssc_pdev->dev.parent = &(ssc->pdev->dev);
ssc_free(ssc);
}
ret = platform_device_add(ssc_pdev);
if (ret < 0)
platform_device_put(ssc_pdev);
return ret;
}
static int __init snd_atmel_ssc_init(void)
{
return platform_driver_register(&asoc_ssc_driver);
}
static void __exit snd_atmel_ssc_exit(void)
{
platform_driver_unregister(&asoc_ssc_driver);
}
