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
static int atmel_ssc_hw_rule_rate(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct atmel_ssc_info *ssc_p = rule->private;
struct ssc_device *ssc = ssc_p->ssc;
struct snd_interval *i = hw_param_interval(params, rule->var);
struct snd_interval t;
struct snd_ratnum r = {
.den_min = 1,
.den_max = 4095,
.den_step = 1,
};
unsigned int num = 0, den = 0;
int frame_size;
int mck_div = 2;
int ret;
frame_size = snd_soc_params_to_frame_size(params);
if (frame_size < 0)
return frame_size;
switch (ssc_p->daifmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFS:
if ((ssc_p->dir_mask & SSC_DIR_MASK_CAPTURE)
&& ssc->clk_from_rk_pin)
mck_div = 3;
break;
case SND_SOC_DAIFMT_CBM_CFM:
if ((ssc_p->dir_mask & SSC_DIR_MASK_PLAYBACK)
&& !ssc->clk_from_rk_pin)
mck_div = 6;
break;
}
switch (ssc_p->daifmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
r.num = ssc_p->mck_rate / mck_div / frame_size;
ret = snd_interval_ratnum(i, 1, &r, &num, &den);
if (ret >= 0 && den && rule->var == SNDRV_PCM_HW_PARAM_RATE) {
params->rate_num = num;
params->rate_den = den;
}
break;
case SND_SOC_DAIFMT_CBM_CFS:
case SND_SOC_DAIFMT_CBM_CFM:
t.min = 8000;
t.max = ssc_p->mck_rate / mck_div / frame_size;
t.openmin = t.openmax = 0;
t.integer = 0;
ret = snd_interval_refine(i, &t);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int atmel_ssc_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct platform_device *pdev = to_platform_device(dai->dev);
struct atmel_ssc_info *ssc_p = &ssc_info[pdev->id];
struct atmel_pcm_dma_params *dma_params;
int dir, dir_mask;
int ret;
pr_debug("atmel_ssc_startup: SSC_SR=0x%x\n",
ssc_readl(ssc_p->ssc->regs, SR));
pr_debug("atmel_ssc_dai: Starting clock\n");
clk_enable(ssc_p->ssc->clk);
ssc_p->mck_rate = clk_get_rate(ssc_p->ssc->clk);
ssc_writel(ssc_p->ssc->regs, CR, SSC_BIT(CR_SWRST));
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
dir = 0;
dir_mask = SSC_DIR_MASK_PLAYBACK;
} else {
dir = 1;
dir_mask = SSC_DIR_MASK_CAPTURE;
}
ret = snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
atmel_ssc_hw_rule_rate,
ssc_p,
SNDRV_PCM_HW_PARAM_FRAME_BITS,
SNDRV_PCM_HW_PARAM_CHANNELS, -1);
if (ret < 0) {
dev_err(dai->dev, "Failed to specify rate rule: %d\n", ret);
return ret;
}
dma_params = &ssc_dma_params[dai->id][dir];
dma_params->ssc = ssc_p->ssc;
dma_params->substream = substream;
ssc_p->dma_params[dir] = dma_params;
snd_soc_dai_set_dma_data(dai, substream, dma_params);
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
struct platform_device *pdev = to_platform_device(dai->dev);
struct atmel_ssc_info *ssc_p = &ssc_info[pdev->id];
struct atmel_pcm_dma_params *dma_params;
int dir, dir_mask;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dir = 0;
else
dir = 1;
dma_params = ssc_p->dma_params[dir];
if (dma_params != NULL) {
dma_params->ssc = NULL;
dma_params->substream = NULL;
ssc_p->dma_params[dir] = NULL;
}
dir_mask = 1 << dir;
spin_lock_irq(&ssc_p->lock);
ssc_p->dir_mask &= ~dir_mask;
if (!ssc_p->dir_mask) {
if (ssc_p->initialized) {
free_irq(ssc_p->ssc->irq, ssc_p);
ssc_p->initialized = 0;
}
ssc_writel(ssc_p->ssc->regs, CR, SSC_BIT(CR_SWRST));
ssc_p->cmr_div = ssc_p->tcmr_period = ssc_p->rcmr_period = 0;
}
spin_unlock_irq(&ssc_p->lock);
pr_debug("atmel_ssc_dai: Stopping clock\n");
clk_disable(ssc_p->ssc->clk);
}
static int atmel_ssc_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct platform_device *pdev = to_platform_device(cpu_dai->dev);
struct atmel_ssc_info *ssc_p = &ssc_info[pdev->id];
ssc_p->daifmt = fmt;
return 0;
}
static int atmel_ssc_set_dai_clkdiv(struct snd_soc_dai *cpu_dai,
int div_id, int div)
{
struct platform_device *pdev = to_platform_device(cpu_dai->dev);
struct atmel_ssc_info *ssc_p = &ssc_info[pdev->id];
switch (div_id) {
case ATMEL_SSC_CMR_DIV:
if (ssc_p->dir_mask !=
(SSC_DIR_MASK_PLAYBACK | SSC_DIR_MASK_CAPTURE))
ssc_p->cmr_div = div;
else if (ssc_p->cmr_div == 0)
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
struct platform_device *pdev = to_platform_device(dai->dev);
int id = pdev->id;
struct atmel_ssc_info *ssc_p = &ssc_info[id];
struct ssc_device *ssc = ssc_p->ssc;
struct atmel_pcm_dma_params *dma_params;
int dir, channels, bits;
u32 tfmr, rfmr, tcmr, rcmr;
int ret;
int fslen, fslen_ext;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dir = 0;
else
dir = 1;
dma_params = ssc_p->dma_params[dir];
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
switch (ssc_p->daifmt
& (SND_SOC_DAIFMT_FORMAT_MASK | SND_SOC_DAIFMT_MASTER_MASK)) {
case SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_CBS_CFS:
if (bits > 16 && !ssc->pdata->has_fslen_ext) {
dev_err(dai->dev,
"sample size %d is too large for SSC device\n",
bits);
return -EINVAL;
}
fslen_ext = (bits - 1) / 16;
fslen = (bits - 1) % 16;
rcmr = SSC_BF(RCMR_PERIOD, ssc_p->rcmr_period)
| SSC_BF(RCMR_STTDLY, START_DELAY)
| SSC_BF(RCMR_START, SSC_START_FALLING_RF)
| SSC_BF(RCMR_CKI, SSC_CKI_RISING)
| SSC_BF(RCMR_CKO, SSC_CKO_NONE)
| SSC_BF(RCMR_CKS, SSC_CKS_DIV);
rfmr = SSC_BF(RFMR_FSLEN_EXT, fslen_ext)
| SSC_BF(RFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(RFMR_FSOS, SSC_FSOS_NEGATIVE)
| SSC_BF(RFMR_FSLEN, fslen)
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
tfmr = SSC_BF(TFMR_FSLEN_EXT, fslen_ext)
| SSC_BF(TFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(TFMR_FSDEN, 0)
| SSC_BF(TFMR_FSOS, SSC_FSOS_NEGATIVE)
| SSC_BF(TFMR_FSLEN, fslen)
| SSC_BF(TFMR_DATNB, (channels - 1))
| SSC_BIT(TFMR_MSBF)
| SSC_BF(TFMR_DATDEF, 0)
| SSC_BF(TFMR_DATLEN, (bits - 1));
break;
case SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_CBM_CFM:
rcmr = SSC_BF(RCMR_PERIOD, 0)
| SSC_BF(RCMR_STTDLY, START_DELAY)
| SSC_BF(RCMR_START, SSC_START_FALLING_RF)
| SSC_BF(RCMR_CKI, SSC_CKI_RISING)
| SSC_BF(RCMR_CKO, SSC_CKO_NONE)
| SSC_BF(RCMR_CKS, ssc->clk_from_rk_pin ?
SSC_CKS_PIN : SSC_CKS_CLOCK);
rfmr = SSC_BF(RFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(RFMR_FSOS, SSC_FSOS_NONE)
| SSC_BF(RFMR_FSLEN, 0)
| SSC_BF(RFMR_DATNB, (channels - 1))
| SSC_BIT(RFMR_MSBF)
| SSC_BF(RFMR_LOOP, 0)
| SSC_BF(RFMR_DATLEN, (bits - 1));
tcmr = SSC_BF(TCMR_PERIOD, 0)
| SSC_BF(TCMR_STTDLY, START_DELAY)
| SSC_BF(TCMR_START, SSC_START_FALLING_RF)
| SSC_BF(TCMR_CKI, SSC_CKI_FALLING)
| SSC_BF(TCMR_CKO, SSC_CKO_NONE)
| SSC_BF(TCMR_CKS, ssc->clk_from_rk_pin ?
SSC_CKS_CLOCK : SSC_CKS_PIN);
tfmr = SSC_BF(TFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(TFMR_FSDEN, 0)
| SSC_BF(TFMR_FSOS, SSC_FSOS_NONE)
| SSC_BF(TFMR_FSLEN, 0)
| SSC_BF(TFMR_DATNB, (channels - 1))
| SSC_BIT(TFMR_MSBF)
| SSC_BF(TFMR_DATDEF, 0)
| SSC_BF(TFMR_DATLEN, (bits - 1));
break;
case SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_CBM_CFS:
if (bits > 16 && !ssc->pdata->has_fslen_ext) {
dev_err(dai->dev,
"sample size %d is too large for SSC device\n",
bits);
return -EINVAL;
}
fslen_ext = (bits - 1) / 16;
fslen = (bits - 1) % 16;
rcmr = SSC_BF(RCMR_PERIOD, ssc_p->rcmr_period)
| SSC_BF(RCMR_STTDLY, START_DELAY)
| SSC_BF(RCMR_START, SSC_START_FALLING_RF)
| SSC_BF(RCMR_CKI, SSC_CKI_RISING)
| SSC_BF(RCMR_CKO, SSC_CKO_NONE)
| SSC_BF(RCMR_CKS, ssc->clk_from_rk_pin ?
SSC_CKS_PIN : SSC_CKS_CLOCK);
rfmr = SSC_BF(RFMR_FSLEN_EXT, fslen_ext)
| SSC_BF(RFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(RFMR_FSOS, SSC_FSOS_NEGATIVE)
| SSC_BF(RFMR_FSLEN, fslen)
| SSC_BF(RFMR_DATNB, (channels - 1))
| SSC_BIT(RFMR_MSBF)
| SSC_BF(RFMR_LOOP, 0)
| SSC_BF(RFMR_DATLEN, (bits - 1));
tcmr = SSC_BF(TCMR_PERIOD, ssc_p->tcmr_period)
| SSC_BF(TCMR_STTDLY, START_DELAY)
| SSC_BF(TCMR_START, SSC_START_FALLING_RF)
| SSC_BF(TCMR_CKI, SSC_CKI_FALLING)
| SSC_BF(TCMR_CKO, SSC_CKO_NONE)
| SSC_BF(TCMR_CKS, ssc->clk_from_rk_pin ?
SSC_CKS_CLOCK : SSC_CKS_PIN);
tfmr = SSC_BF(TFMR_FSLEN_EXT, fslen_ext)
| SSC_BF(TFMR_FSEDGE, SSC_FSEDGE_NEGATIVE)
| SSC_BF(TFMR_FSDEN, 0)
| SSC_BF(TFMR_FSOS, SSC_FSOS_NEGATIVE)
| SSC_BF(TFMR_FSLEN, fslen)
| SSC_BF(TFMR_DATNB, (channels - 1))
| SSC_BIT(TFMR_MSBF)
| SSC_BF(TFMR_DATDEF, 0)
| SSC_BF(TFMR_DATLEN, (bits - 1));
break;
case SND_SOC_DAIFMT_DSP_A | SND_SOC_DAIFMT_CBS_CFS:
rcmr = SSC_BF(RCMR_PERIOD, ssc_p->rcmr_period)
| SSC_BF(RCMR_STTDLY, 1)
| SSC_BF(RCMR_START, SSC_START_RISING_RF)
| SSC_BF(RCMR_CKI, SSC_CKI_FALLING)
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
| SSC_BF(TCMR_CKI, SSC_CKI_FALLING)
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
rcmr = SSC_BF(RCMR_PERIOD, 0)
| SSC_BF(RCMR_STTDLY, START_DELAY)
| SSC_BF(RCMR_START, SSC_START_RISING_RF)
| SSC_BF(RCMR_CKI, SSC_CKI_FALLING)
| SSC_BF(RCMR_CKO, SSC_CKO_NONE)
| SSC_BF(RCMR_CKS, ssc->clk_from_rk_pin ?
SSC_CKS_PIN : SSC_CKS_CLOCK);
rfmr = SSC_BF(RFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(RFMR_FSOS, SSC_FSOS_NONE)
| SSC_BF(RFMR_FSLEN, 0)
| SSC_BF(RFMR_DATNB, (channels - 1))
| SSC_BIT(RFMR_MSBF)
| SSC_BF(RFMR_LOOP, 0)
| SSC_BF(RFMR_DATLEN, (bits - 1));
tcmr = SSC_BF(TCMR_PERIOD, 0)
| SSC_BF(TCMR_STTDLY, START_DELAY)
| SSC_BF(TCMR_START, SSC_START_RISING_RF)
| SSC_BF(TCMR_CKI, SSC_CKI_FALLING)
| SSC_BF(TCMR_CKO, SSC_CKO_NONE)
| SSC_BF(RCMR_CKS, ssc->clk_from_rk_pin ?
SSC_CKS_CLOCK : SSC_CKS_PIN);
tfmr = SSC_BF(TFMR_FSEDGE, SSC_FSEDGE_POSITIVE)
| SSC_BF(TFMR_FSDEN, 0)
| SSC_BF(TFMR_FSOS, SSC_FSOS_NONE)
| SSC_BF(TFMR_FSLEN, 0)
| SSC_BF(TFMR_DATNB, (channels - 1))
| SSC_BIT(TFMR_MSBF)
| SSC_BF(TFMR_DATDEF, 0)
| SSC_BF(TFMR_DATLEN, (bits - 1));
break;
default:
printk(KERN_WARNING "atmel_ssc_dai: unsupported DAI format 0x%x\n",
ssc_p->daifmt);
return -EINVAL;
}
pr_debug("atmel_ssc_hw_params: "
"RCMR=%08x RFMR=%08x TCMR=%08x TFMR=%08x\n",
rcmr, rfmr, tcmr, tfmr);
if (!ssc_p->initialized) {
if (!ssc_p->ssc->pdata->use_dma) {
ssc_writel(ssc_p->ssc->regs, PDC_RPR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_RCR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_RNPR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_RNCR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_TPR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_TCR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_TNPR, 0);
ssc_writel(ssc_p->ssc->regs, PDC_TNCR, 0);
}
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
struct platform_device *pdev = to_platform_device(dai->dev);
struct atmel_ssc_info *ssc_p = &ssc_info[pdev->id];
struct atmel_pcm_dma_params *dma_params;
int dir;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dir = 0;
else
dir = 1;
dma_params = ssc_p->dma_params[dir];
ssc_writel(ssc_p->ssc->regs, CR, dma_params->mask->ssc_disable);
ssc_writel(ssc_p->ssc->regs, IDR, dma_params->mask->ssc_error);
pr_debug("%s enabled SSC_SR=0x%08x\n",
dir ? "receive" : "transmit",
ssc_readl(ssc_p->ssc->regs, SR));
return 0;
}
static int atmel_ssc_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
struct platform_device *pdev = to_platform_device(dai->dev);
struct atmel_ssc_info *ssc_p = &ssc_info[pdev->id];
struct atmel_pcm_dma_params *dma_params;
int dir;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dir = 0;
else
dir = 1;
dma_params = ssc_p->dma_params[dir];
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
ssc_writel(ssc_p->ssc->regs, CR, dma_params->mask->ssc_enable);
break;
default:
ssc_writel(ssc_p->ssc->regs, CR, dma_params->mask->ssc_disable);
break;
}
return 0;
}
static int atmel_ssc_suspend(struct snd_soc_dai *cpu_dai)
{
struct atmel_ssc_info *ssc_p;
struct platform_device *pdev = to_platform_device(cpu_dai->dev);
if (!cpu_dai->active)
return 0;
ssc_p = &ssc_info[pdev->id];
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
struct platform_device *pdev = to_platform_device(cpu_dai->dev);
u32 cr;
if (!cpu_dai->active)
return 0;
ssc_p = &ssc_info[pdev->id];
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
static int asoc_ssc_init(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct ssc_device *ssc = platform_get_drvdata(pdev);
int ret;
ret = snd_soc_register_component(dev, &atmel_ssc_component,
&atmel_ssc_dai, 1);
if (ret) {
dev_err(dev, "Could not register DAI: %d\n", ret);
goto err;
}
if (ssc->pdata->use_dma)
ret = atmel_pcm_dma_platform_register(dev);
else
ret = atmel_pcm_pdc_platform_register(dev);
if (ret) {
dev_err(dev, "Could not register PCM: %d\n", ret);
goto err_unregister_dai;
}
return 0;
err_unregister_dai:
snd_soc_unregister_component(dev);
err:
return ret;
}
static void asoc_ssc_exit(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct ssc_device *ssc = platform_get_drvdata(pdev);
if (ssc->pdata->use_dma)
atmel_pcm_dma_platform_unregister(dev);
else
atmel_pcm_pdc_platform_unregister(dev);
snd_soc_unregister_component(dev);
}
int atmel_ssc_set_audio(int ssc_id)
{
struct ssc_device *ssc;
int ret;
ssc = ssc_request(ssc_id);
if (IS_ERR(ssc)) {
pr_err("Unable to parent ASoC SSC DAI on SSC: %ld\n",
PTR_ERR(ssc));
return PTR_ERR(ssc);
} else {
ssc_info[ssc_id].ssc = ssc;
}
ret = asoc_ssc_init(&ssc->pdev->dev);
return ret;
}
void atmel_ssc_put_audio(int ssc_id)
{
struct ssc_device *ssc = ssc_info[ssc_id].ssc;
asoc_ssc_exit(&ssc->pdev->dev);
ssc_free(ssc);
}
