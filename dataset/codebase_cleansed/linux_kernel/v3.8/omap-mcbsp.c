static void omap_mcbsp_set_threshold(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(cpu_dai);
struct omap_pcm_dma_data *dma_data;
int words;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (dma_data->packet_size)
words = dma_data->packet_size;
else
words = 1;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
omap_mcbsp_set_tx_threshold(mcbsp, words);
else
omap_mcbsp_set_rx_threshold(mcbsp, words);
}
static int omap_mcbsp_hwrule_min_buffersize(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct snd_interval *buffer_size = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_BUFFER_SIZE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
struct omap_mcbsp *mcbsp = rule->private;
struct snd_interval frames;
int size;
snd_interval_any(&frames);
size = mcbsp->pdata->buffer_size;
frames.min = size / channels->min;
frames.integer = 1;
return snd_interval_refine(buffer_size, &frames);
}
static int omap_mcbsp_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(cpu_dai);
int err = 0;
if (!cpu_dai->active)
err = omap_mcbsp_request(mcbsp);
if (mcbsp->pdata->buffer_size) {
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_BUFFER_SIZE,
omap_mcbsp_hwrule_min_buffersize,
mcbsp,
SNDRV_PCM_HW_PARAM_CHANNELS, -1);
snd_pcm_hw_constraint_step(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE, 2);
}
snd_soc_dai_set_dma_data(cpu_dai, substream,
&mcbsp->dma_data[substream->stream]);
return err;
}
static void omap_mcbsp_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(cpu_dai);
if (!cpu_dai->active) {
omap_mcbsp_free(mcbsp);
mcbsp->configured = 0;
}
}
static int omap_mcbsp_dai_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *cpu_dai)
{
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(cpu_dai);
int err = 0, play = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
mcbsp->active++;
omap_mcbsp_start(mcbsp, play, !play);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
omap_mcbsp_stop(mcbsp, play, !play);
mcbsp->active--;
break;
default:
err = -EINVAL;
}
return err;
}
static snd_pcm_sframes_t omap_mcbsp_dai_delay(
struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(cpu_dai);
u16 fifo_use;
snd_pcm_sframes_t delay;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
fifo_use = omap_mcbsp_get_tx_delay(mcbsp);
else
fifo_use = omap_mcbsp_get_rx_delay(mcbsp);
delay = fifo_use / substream->runtime->channels;
return delay;
}
static int omap_mcbsp_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(cpu_dai);
struct omap_mcbsp_reg_cfg *regs = &mcbsp->cfg_regs;
struct omap_pcm_dma_data *dma_data;
int wlen, channels, wpf;
int pkt_size = 0;
unsigned int format, div, framesize, master;
dma_data = snd_soc_dai_get_dma_data(cpu_dai, substream);
channels = params_channels(params);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
wlen = 16;
break;
case SNDRV_PCM_FORMAT_S32_LE:
wlen = 32;
break;
default:
return -EINVAL;
}
if (mcbsp->pdata->buffer_size) {
dma_data->set_threshold = omap_mcbsp_set_threshold;
if (mcbsp->dma_op_mode == MCBSP_DMA_MODE_THRESHOLD) {
int period_words, max_thrsh;
int divider = 0;
period_words = params_period_bytes(params) / (wlen / 8);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
max_thrsh = mcbsp->max_tx_thres;
else
max_thrsh = mcbsp->max_rx_thres;
divider = period_words / max_thrsh;
if (period_words % max_thrsh)
divider++;
while (period_words % divider &&
divider < period_words)
divider++;
if (divider == period_words)
return -EINVAL;
pkt_size = period_words / divider;
} else if (channels > 1) {
pkt_size = channels;
}
}
dma_data->packet_size = pkt_size;
if (mcbsp->configured) {
return 0;
}
regs->rcr2 &= ~(RPHASE | RFRLEN2(0x7f) | RWDLEN2(7));
regs->xcr2 &= ~(RPHASE | XFRLEN2(0x7f) | XWDLEN2(7));
regs->rcr1 &= ~(RFRLEN1(0x7f) | RWDLEN1(7));
regs->xcr1 &= ~(XFRLEN1(0x7f) | XWDLEN1(7));
format = mcbsp->fmt & SND_SOC_DAIFMT_FORMAT_MASK;
wpf = channels;
if (channels == 2 && (format == SND_SOC_DAIFMT_I2S ||
format == SND_SOC_DAIFMT_LEFT_J)) {
regs->rcr2 |= RPHASE;
regs->xcr2 |= XPHASE;
wpf--;
regs->rcr2 |= RFRLEN2(wpf - 1);
regs->xcr2 |= XFRLEN2(wpf - 1);
}
regs->rcr1 |= RFRLEN1(wpf - 1);
regs->xcr1 |= XFRLEN1(wpf - 1);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
regs->rcr2 |= RWDLEN2(OMAP_MCBSP_WORD_16);
regs->rcr1 |= RWDLEN1(OMAP_MCBSP_WORD_16);
regs->xcr2 |= XWDLEN2(OMAP_MCBSP_WORD_16);
regs->xcr1 |= XWDLEN1(OMAP_MCBSP_WORD_16);
break;
case SNDRV_PCM_FORMAT_S32_LE:
regs->rcr2 |= RWDLEN2(OMAP_MCBSP_WORD_32);
regs->rcr1 |= RWDLEN1(OMAP_MCBSP_WORD_32);
regs->xcr2 |= XWDLEN2(OMAP_MCBSP_WORD_32);
regs->xcr1 |= XWDLEN1(OMAP_MCBSP_WORD_32);
break;
default:
return -EINVAL;
}
master = mcbsp->fmt & SND_SOC_DAIFMT_MASTER_MASK;
if (master == SND_SOC_DAIFMT_CBS_CFS) {
div = mcbsp->clk_div ? mcbsp->clk_div : 1;
framesize = (mcbsp->in_freq / div) / params_rate(params);
if (framesize < wlen * channels) {
printk(KERN_ERR "%s: not enough bandwidth for desired rate and "
"channels\n", __func__);
return -EINVAL;
}
} else
framesize = wlen * channels;
regs->srgr2 &= ~FPER(0xfff);
regs->srgr1 &= ~FWID(0xff);
switch (format) {
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_LEFT_J:
regs->srgr2 |= FPER(framesize - 1);
regs->srgr1 |= FWID((framesize >> 1) - 1);
break;
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
regs->srgr2 |= FPER(framesize - 1);
regs->srgr1 |= FWID(0);
break;
}
omap_mcbsp_config(mcbsp, &mcbsp->cfg_regs);
mcbsp->wlen = wlen;
mcbsp->configured = 1;
return 0;
}
static int omap_mcbsp_dai_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(cpu_dai);
struct omap_mcbsp_reg_cfg *regs = &mcbsp->cfg_regs;
bool inv_fs = false;
if (mcbsp->configured)
return 0;
mcbsp->fmt = fmt;
memset(regs, 0, sizeof(*regs));
regs->spcr2 |= XINTM(3) | FREE;
regs->spcr1 |= RINTM(3);
if (!mcbsp->pdata->has_ccr) {
regs->rcr2 |= RFIG;
regs->xcr2 |= XFIG;
}
if (mcbsp->pdata->has_ccr) {
regs->xccr = DXENDLY(1) | XDMAEN | XDISABLE;
regs->rccr = RFULL_CYCLE | RDMAEN | RDISABLE;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
regs->rcr2 |= RDATDLY(1);
regs->xcr2 |= XDATDLY(1);
break;
case SND_SOC_DAIFMT_LEFT_J:
regs->rcr2 |= RDATDLY(0);
regs->xcr2 |= XDATDLY(0);
regs->spcr1 |= RJUST(2);
inv_fs = true;
break;
case SND_SOC_DAIFMT_DSP_A:
regs->rcr2 |= RDATDLY(1);
regs->xcr2 |= XDATDLY(1);
inv_fs = true;
break;
case SND_SOC_DAIFMT_DSP_B:
regs->rcr2 |= RDATDLY(0);
regs->xcr2 |= XDATDLY(0);
inv_fs = true;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
regs->pcr0 |= FSXM | FSRM |
CLKXM | CLKRM;
regs->srgr2 |= FSGM;
break;
case SND_SOC_DAIFMT_CBM_CFM:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
regs->pcr0 |= FSXP | FSRP |
CLKXP | CLKRP;
break;
case SND_SOC_DAIFMT_NB_IF:
regs->pcr0 |= CLKXP | CLKRP;
break;
case SND_SOC_DAIFMT_IB_NF:
regs->pcr0 |= FSXP | FSRP;
break;
case SND_SOC_DAIFMT_IB_IF:
break;
default:
return -EINVAL;
}
if (inv_fs == true)
regs->pcr0 ^= FSXP | FSRP;
return 0;
}
static int omap_mcbsp_dai_set_clkdiv(struct snd_soc_dai *cpu_dai,
int div_id, int div)
{
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(cpu_dai);
struct omap_mcbsp_reg_cfg *regs = &mcbsp->cfg_regs;
if (div_id != OMAP_MCBSP_CLKGDV)
return -ENODEV;
mcbsp->clk_div = div;
regs->srgr1 &= ~CLKGDV(0xff);
regs->srgr1 |= CLKGDV(div - 1);
return 0;
}
static int omap_mcbsp_dai_set_dai_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq,
int dir)
{
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(cpu_dai);
struct omap_mcbsp_reg_cfg *regs = &mcbsp->cfg_regs;
int err = 0;
if (mcbsp->active) {
if (freq == mcbsp->in_freq)
return 0;
else
return -EBUSY;
}
mcbsp->in_freq = freq;
regs->srgr2 &= ~CLKSM;
regs->pcr0 &= ~SCLKME;
switch (clk_id) {
case OMAP_MCBSP_SYSCLK_CLK:
regs->srgr2 |= CLKSM;
break;
case OMAP_MCBSP_SYSCLK_CLKS_FCLK:
if (mcbsp_omap1()) {
err = -EINVAL;
break;
}
err = omap2_mcbsp_set_clks_src(mcbsp,
MCBSP_CLKS_PRCM_SRC);
break;
case OMAP_MCBSP_SYSCLK_CLKS_EXT:
if (mcbsp_omap1()) {
err = 0;
break;
}
err = omap2_mcbsp_set_clks_src(mcbsp,
MCBSP_CLKS_PAD_SRC);
break;
case OMAP_MCBSP_SYSCLK_CLKX_EXT:
regs->srgr2 |= CLKSM;
case OMAP_MCBSP_SYSCLK_CLKR_EXT:
regs->pcr0 |= SCLKME;
break;
default:
err = -ENODEV;
}
return err;
}
static int omap_mcbsp_probe(struct snd_soc_dai *dai)
{
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(dai);
pm_runtime_enable(mcbsp->dev);
return 0;
}
static int omap_mcbsp_remove(struct snd_soc_dai *dai)
{
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(dai);
pm_runtime_disable(mcbsp->dev);
return 0;
}
static int omap_mcbsp_st_info_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
int max = mc->max;
int min = mc->min;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = min;
uinfo->value.integer.max = max;
return 0;
}
static int omap_mcbsp_st_put_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dai *cpu_dai = snd_kcontrol_chip(kcontrol);
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(cpu_dai);
u8 value = ucontrol->value.integer.value[0];
if (value == omap_st_is_enabled(mcbsp))
return 0;
if (value)
omap_st_enable(mcbsp);
else
omap_st_disable(mcbsp);
return 1;
}
static int omap_mcbsp_st_get_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dai *cpu_dai = snd_kcontrol_chip(kcontrol);
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(cpu_dai);
ucontrol->value.integer.value[0] = omap_st_is_enabled(mcbsp);
return 0;
}
int omap_mcbsp_st_add_controls(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct omap_mcbsp *mcbsp = snd_soc_dai_get_drvdata(cpu_dai);
if (!mcbsp->st_data) {
dev_warn(mcbsp->dev, "No sidetone data for port\n");
return 0;
}
switch (mcbsp->id) {
case 2:
return snd_soc_add_dai_controls(cpu_dai,
omap_mcbsp2_st_controls,
ARRAY_SIZE(omap_mcbsp2_st_controls));
case 3:
return snd_soc_add_dai_controls(cpu_dai,
omap_mcbsp3_st_controls,
ARRAY_SIZE(omap_mcbsp3_st_controls));
default:
break;
}
return -EINVAL;
}
static int asoc_mcbsp_probe(struct platform_device *pdev)
{
struct omap_mcbsp_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct omap_mcbsp *mcbsp;
const struct of_device_id *match;
int ret;
match = of_match_device(omap_mcbsp_of_match, &pdev->dev);
if (match) {
struct device_node *node = pdev->dev.of_node;
int buffer_size;
pdata = devm_kzalloc(&pdev->dev,
sizeof(struct omap_mcbsp_platform_data),
GFP_KERNEL);
if (!pdata)
return -ENOMEM;
memcpy(pdata, match->data, sizeof(*pdata));
if (!of_property_read_u32(node, "ti,buffer-size", &buffer_size))
pdata->buffer_size = buffer_size;
} else if (!pdata) {
dev_err(&pdev->dev, "missing platform data.\n");
return -EINVAL;
}
mcbsp = devm_kzalloc(&pdev->dev, sizeof(struct omap_mcbsp), GFP_KERNEL);
if (!mcbsp)
return -ENOMEM;
mcbsp->id = pdev->id;
mcbsp->pdata = pdata;
mcbsp->dev = &pdev->dev;
platform_set_drvdata(pdev, mcbsp);
ret = omap_mcbsp_init(pdev);
if (!ret)
return snd_soc_register_dai(&pdev->dev, &omap_mcbsp_dai);
return ret;
}
static int asoc_mcbsp_remove(struct platform_device *pdev)
{
struct omap_mcbsp *mcbsp = platform_get_drvdata(pdev);
snd_soc_unregister_dai(&pdev->dev);
if (mcbsp->pdata->ops && mcbsp->pdata->ops->free)
mcbsp->pdata->ops->free(mcbsp->id);
omap_mcbsp_sysfs_remove(mcbsp);
clk_put(mcbsp->fclk);
platform_set_drvdata(pdev, NULL);
return 0;
}
