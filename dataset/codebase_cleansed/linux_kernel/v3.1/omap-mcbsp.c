static void omap_mcbsp_set_threshold(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct omap_mcbsp_data *mcbsp_data = snd_soc_dai_get_drvdata(cpu_dai);
struct omap_pcm_dma_data *dma_data;
int dma_op_mode = omap_mcbsp_get_dma_op_mode(mcbsp_data->bus_id);
int words;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (dma_op_mode == MCBSP_DMA_MODE_THRESHOLD)
if (dma_data->packet_size)
words = dma_data->packet_size;
else
words = snd_pcm_lib_period_bytes(substream) /
(mcbsp_data->wlen / 8);
else
words = 1;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
omap_mcbsp_set_tx_threshold(mcbsp_data->bus_id, words);
else
omap_mcbsp_set_rx_threshold(mcbsp_data->bus_id, words);
}
static int omap_mcbsp_hwrule_min_buffersize(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct snd_interval *buffer_size = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_BUFFER_SIZE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
struct omap_mcbsp_data *mcbsp_data = rule->private;
struct snd_interval frames;
int size;
snd_interval_any(&frames);
size = omap_mcbsp_get_fifo_size(mcbsp_data->bus_id);
frames.min = size / channels->min;
frames.integer = 1;
return snd_interval_refine(buffer_size, &frames);
}
static int omap_mcbsp_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct omap_mcbsp_data *mcbsp_data = snd_soc_dai_get_drvdata(cpu_dai);
int bus_id = mcbsp_data->bus_id;
int err = 0;
if (!cpu_dai->active)
err = omap_mcbsp_request(bus_id);
if (cpu_is_omap34xx() || cpu_is_omap44xx()) {
snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
omap_mcbsp_hwrule_min_buffersize,
mcbsp_data,
SNDRV_PCM_HW_PARAM_BUFFER_SIZE, -1);
snd_pcm_hw_constraint_step(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE, 2);
}
return err;
}
static void omap_mcbsp_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct omap_mcbsp_data *mcbsp_data = snd_soc_dai_get_drvdata(cpu_dai);
if (!cpu_dai->active) {
omap_mcbsp_free(mcbsp_data->bus_id);
mcbsp_data->configured = 0;
}
}
static int omap_mcbsp_dai_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *cpu_dai)
{
struct omap_mcbsp_data *mcbsp_data = snd_soc_dai_get_drvdata(cpu_dai);
int err = 0, play = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
mcbsp_data->active++;
omap_mcbsp_start(mcbsp_data->bus_id, play, !play);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
omap_mcbsp_stop(mcbsp_data->bus_id, play, !play);
mcbsp_data->active--;
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
struct omap_mcbsp_data *mcbsp_data = snd_soc_dai_get_drvdata(cpu_dai);
u16 fifo_use;
snd_pcm_sframes_t delay;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
fifo_use = omap_mcbsp_get_tx_delay(mcbsp_data->bus_id);
else
fifo_use = omap_mcbsp_get_rx_delay(mcbsp_data->bus_id);
delay = fifo_use / substream->runtime->channels;
return delay;
}
static int omap_mcbsp_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct omap_mcbsp_data *mcbsp_data = snd_soc_dai_get_drvdata(cpu_dai);
struct omap_mcbsp_reg_cfg *regs = &mcbsp_data->regs;
struct omap_pcm_dma_data *dma_data;
int dma, bus_id = mcbsp_data->bus_id;
int wlen, channels, wpf, sync_mode = OMAP_DMA_SYNC_ELEMENT;
int pkt_size = 0;
unsigned long port;
unsigned int format, div, framesize, master;
dma_data = &omap_mcbsp_dai_dma_params[cpu_dai->id][substream->stream];
dma = omap_mcbsp_dma_ch_params(bus_id, substream->stream);
port = omap_mcbsp_dma_reg_params(bus_id, substream->stream);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
dma_data->data_type = OMAP_DMA_DATA_TYPE_S16;
wlen = 16;
break;
case SNDRV_PCM_FORMAT_S32_LE:
dma_data->data_type = OMAP_DMA_DATA_TYPE_S32;
wlen = 32;
break;
default:
return -EINVAL;
}
if (cpu_is_omap34xx()) {
dma_data->set_threshold = omap_mcbsp_set_threshold;
if (omap_mcbsp_get_dma_op_mode(bus_id) ==
MCBSP_DMA_MODE_THRESHOLD) {
int period_words, max_thrsh;
period_words = params_period_bytes(params) / (wlen / 8);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
max_thrsh = omap_mcbsp_get_max_tx_threshold(
mcbsp_data->bus_id);
else
max_thrsh = omap_mcbsp_get_max_rx_threshold(
mcbsp_data->bus_id);
if (period_words > max_thrsh) {
int divider = 0;
divider = period_words / max_thrsh;
if (period_words % max_thrsh)
divider++;
while (period_words % divider &&
divider < period_words)
divider++;
if (divider == period_words)
return -EINVAL;
pkt_size = period_words / divider;
sync_mode = OMAP_DMA_SYNC_PACKET;
} else {
sync_mode = OMAP_DMA_SYNC_FRAME;
}
}
}
dma_data->name = substream->stream ? "Audio Capture" : "Audio Playback";
dma_data->dma_req = dma;
dma_data->port_addr = port;
dma_data->sync_mode = sync_mode;
dma_data->packet_size = pkt_size;
snd_soc_dai_set_dma_data(cpu_dai, substream, dma_data);
if (mcbsp_data->configured) {
return 0;
}
format = mcbsp_data->fmt & SND_SOC_DAIFMT_FORMAT_MASK;
wpf = channels = params_channels(params);
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
master = mcbsp_data->fmt & SND_SOC_DAIFMT_MASTER_MASK;
if (master == SND_SOC_DAIFMT_CBS_CFS) {
div = mcbsp_data->clk_div ? mcbsp_data->clk_div : 1;
framesize = (mcbsp_data->in_freq / div) / params_rate(params);
if (framesize < wlen * channels) {
printk(KERN_ERR "%s: not enough bandwidth for desired rate and "
"channels\n", __func__);
return -EINVAL;
}
} else
framesize = wlen * channels;
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
omap_mcbsp_config(bus_id, &mcbsp_data->regs);
mcbsp_data->wlen = wlen;
mcbsp_data->configured = 1;
return 0;
}
static int omap_mcbsp_dai_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct omap_mcbsp_data *mcbsp_data = snd_soc_dai_get_drvdata(cpu_dai);
struct omap_mcbsp_reg_cfg *regs = &mcbsp_data->regs;
unsigned int temp_fmt = fmt;
if (mcbsp_data->configured)
return 0;
mcbsp_data->fmt = fmt;
memset(regs, 0, sizeof(*regs));
regs->spcr2 |= XINTM(3) | FREE;
regs->spcr1 |= RINTM(3);
if (!cpu_is_omap34xx() && !cpu_is_omap44xx()) {
regs->rcr2 |= RFIG;
regs->xcr2 |= XFIG;
}
if (cpu_is_omap2430() || cpu_is_omap34xx() || cpu_is_omap44xx()) {
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
temp_fmt ^= SND_SOC_DAIFMT_NB_IF;
break;
case SND_SOC_DAIFMT_DSP_A:
regs->rcr2 |= RDATDLY(1);
regs->xcr2 |= XDATDLY(1);
temp_fmt ^= SND_SOC_DAIFMT_NB_IF;
break;
case SND_SOC_DAIFMT_DSP_B:
regs->rcr2 |= RDATDLY(0);
regs->xcr2 |= XDATDLY(0);
temp_fmt ^= SND_SOC_DAIFMT_NB_IF;
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
switch (temp_fmt & SND_SOC_DAIFMT_INV_MASK) {
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
return 0;
}
static int omap_mcbsp_dai_set_clkdiv(struct snd_soc_dai *cpu_dai,
int div_id, int div)
{
struct omap_mcbsp_data *mcbsp_data = snd_soc_dai_get_drvdata(cpu_dai);
struct omap_mcbsp_reg_cfg *regs = &mcbsp_data->regs;
if (div_id != OMAP_MCBSP_CLKGDV)
return -ENODEV;
mcbsp_data->clk_div = div;
regs->srgr1 |= CLKGDV(div - 1);
return 0;
}
static int omap_mcbsp_dai_set_dai_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq,
int dir)
{
struct omap_mcbsp_data *mcbsp_data = snd_soc_dai_get_drvdata(cpu_dai);
struct omap_mcbsp_reg_cfg *regs = &mcbsp_data->regs;
int err = 0;
if (mcbsp_data->active)
if (freq == mcbsp_data->in_freq)
return 0;
else
return -EBUSY;
if (clk_id == OMAP_MCBSP_CLKR_SRC_CLKR ||
clk_id == OMAP_MCBSP_CLKR_SRC_CLKX ||
clk_id == OMAP_MCBSP_FSR_SRC_FSR ||
clk_id == OMAP_MCBSP_FSR_SRC_FSX)
if (cpu_class_is_omap1() || mcbsp_data->bus_id != 0)
return -EINVAL;
mcbsp_data->in_freq = freq;
switch (clk_id) {
case OMAP_MCBSP_SYSCLK_CLK:
regs->srgr2 |= CLKSM;
break;
case OMAP_MCBSP_SYSCLK_CLKS_FCLK:
if (cpu_class_is_omap1()) {
err = -EINVAL;
break;
}
err = omap2_mcbsp_set_clks_src(mcbsp_data->bus_id,
MCBSP_CLKS_PRCM_SRC);
break;
case OMAP_MCBSP_SYSCLK_CLKS_EXT:
if (cpu_class_is_omap1()) {
err = 0;
break;
}
err = omap2_mcbsp_set_clks_src(mcbsp_data->bus_id,
MCBSP_CLKS_PAD_SRC);
break;
case OMAP_MCBSP_SYSCLK_CLKX_EXT:
regs->srgr2 |= CLKSM;
case OMAP_MCBSP_SYSCLK_CLKR_EXT:
regs->pcr0 |= SCLKME;
break;
case OMAP_MCBSP_CLKR_SRC_CLKR:
if (cpu_class_is_omap1())
break;
omap2_mcbsp1_mux_clkr_src(CLKR_SRC_CLKR);
break;
case OMAP_MCBSP_CLKR_SRC_CLKX:
if (cpu_class_is_omap1())
break;
omap2_mcbsp1_mux_clkr_src(CLKR_SRC_CLKX);
break;
case OMAP_MCBSP_FSR_SRC_FSR:
if (cpu_class_is_omap1())
break;
omap2_mcbsp1_mux_fsr_src(FSR_SRC_FSR);
break;
case OMAP_MCBSP_FSR_SRC_FSX:
if (cpu_class_is_omap1())
break;
omap2_mcbsp1_mux_fsr_src(FSR_SRC_FSX);
break;
default:
err = -ENODEV;
}
return err;
}
static int mcbsp_dai_probe(struct snd_soc_dai *dai)
{
mcbsp_data[dai->id].bus_id = dai->id;
snd_soc_dai_set_drvdata(dai, &mcbsp_data[dai->id].bus_id);
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
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
u8 value = ucontrol->value.integer.value[0];
if (value == omap_st_is_enabled(mc->reg))
return 0;
if (value)
omap_st_enable(mc->reg);
else
omap_st_disable(mc->reg);
return 1;
}
static int omap_mcbsp_st_get_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
ucontrol->value.integer.value[0] = omap_st_is_enabled(mc->reg);
return 0;
}
int omap_mcbsp_st_add_controls(struct snd_soc_codec *codec, int mcbsp_id)
{
if (!cpu_is_omap34xx())
return -ENODEV;
switch (mcbsp_id) {
case 1:
return snd_soc_add_controls(codec, omap_mcbsp2_st_controls,
ARRAY_SIZE(omap_mcbsp2_st_controls));
case 2:
return snd_soc_add_controls(codec, omap_mcbsp3_st_controls,
ARRAY_SIZE(omap_mcbsp3_st_controls));
default:
break;
}
return -EINVAL;
}
static __devinit int asoc_mcbsp_probe(struct platform_device *pdev)
{
return snd_soc_register_dai(&pdev->dev, &omap_mcbsp_dai);
}
static int __devexit asoc_mcbsp_remove(struct platform_device *pdev)
{
snd_soc_unregister_dai(&pdev->dev);
return 0;
}
static int __init snd_omap_mcbsp_init(void)
{
return platform_driver_register(&asoc_mcbsp_driver);
}
static void __exit snd_omap_mcbsp_exit(void)
{
platform_driver_unregister(&asoc_mcbsp_driver);
}
