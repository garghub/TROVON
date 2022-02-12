static int ssi_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct ssi_priv *ssi = &ssi_cpu_data[dai->id];
if (ssi->inuse) {
pr_debug("ssi: already in use!\n");
return -EBUSY;
} else
ssi->inuse = 1;
return 0;
}
static void ssi_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct ssi_priv *ssi = &ssi_cpu_data[dai->id];
ssi->inuse = 0;
}
static int ssi_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct ssi_priv *ssi = &ssi_cpu_data[dai->id];
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
SSIREG(SSICR) |= CR_DMAEN | CR_EN;
break;
case SNDRV_PCM_TRIGGER_STOP:
SSIREG(SSICR) &= ~(CR_DMAEN | CR_EN);
break;
default:
return -EINVAL;
}
return 0;
}
static int ssi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct ssi_priv *ssi = &ssi_cpu_data[dai->id];
unsigned long ssicr = SSIREG(SSICR);
unsigned int bits, channels, swl, recv, i;
channels = params_channels(params);
bits = params->msbits;
recv = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) ? 0 : 1;
pr_debug("ssi_hw_params() enter\nssicr was %08lx\n", ssicr);
pr_debug("bits: %u channels: %u\n", bits, channels);
ssicr &= ~(CR_TRMD | CR_CHNL_MASK | CR_DWL_MASK | CR_PDTA |
CR_SWL_MASK);
if (!recv)
ssicr |= CR_TRMD;
if ((channels < 2) || (channels > 8) || (channels & 1)) {
pr_debug("ssi: invalid number of channels\n");
return -EINVAL;
}
ssicr |= ((channels >> 1) - 1) << CR_CHNL_SHIFT;
i = 0;
switch (bits) {
case 32: ++i;
case 24: ++i;
case 22: ++i;
case 20: ++i;
case 18: ++i;
case 16: ++i;
ssicr |= i << CR_DWL_SHIFT;
case 8: break;
default:
pr_debug("ssi: invalid sample width\n");
return -EINVAL;
}
if ((bits > 16) && (bits <= 24)) {
bits = 24;
}
i = 0;
swl = (bits * channels) / 2;
switch (swl) {
case 256: ++i;
case 128: ++i;
case 64: ++i;
case 48: ++i;
case 32: ++i;
case 16: ++i;
ssicr |= i << CR_SWL_SHIFT;
case 8: break;
default:
pr_debug("ssi: invalid system word length computed\n");
return -EINVAL;
}
SSIREG(SSICR) = ssicr;
pr_debug("ssi_hw_params() leave\nssicr is now %08lx\n", ssicr);
return 0;
}
static int ssi_set_sysclk(struct snd_soc_dai *cpu_dai, int clk_id,
unsigned int freq, int dir)
{
struct ssi_priv *ssi = &ssi_cpu_data[cpu_dai->id];
ssi->sysclk = freq;
return 0;
}
static int ssi_set_clkdiv(struct snd_soc_dai *dai, int did, int div)
{
struct ssi_priv *ssi = &ssi_cpu_data[dai->id];
unsigned long ssicr;
int i;
i = 0;
ssicr = SSIREG(SSICR) & ~CR_CKDIV_MASK;
switch (div) {
case 16: ++i;
case 8: ++i;
case 4: ++i;
case 2: ++i;
SSIREG(SSICR) = ssicr | (i << CR_CKDIV_SHIFT);
case 1: break;
default:
pr_debug("ssi: invalid sck divider %d\n", div);
return -EINVAL;
}
return 0;
}
static int ssi_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct ssi_priv *ssi = &ssi_cpu_data[dai->id];
unsigned long ssicr = SSIREG(SSICR);
pr_debug("ssi_set_fmt()\nssicr was 0x%08lx\n", ssicr);
ssicr &= ~(CR_DEL | CR_PDTA | CR_BREN | CR_SWSP | CR_SCKP |
CR_SWS_MASTER | CR_SCK_MASTER);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_RIGHT_J:
ssicr |= CR_DEL | CR_PDTA;
break;
case SND_SOC_DAIFMT_LEFT_J:
ssicr |= CR_DEL;
break;
default:
pr_debug("ssi: unsupported format\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_CLOCK_MASK) {
case SND_SOC_DAIFMT_CONT:
break;
case SND_SOC_DAIFMT_GATED:
ssicr |= CR_BREN;
break;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
ssicr |= CR_SCKP;
break;
case SND_SOC_DAIFMT_NB_IF:
ssicr |= CR_SCKP | CR_SWSP;
break;
case SND_SOC_DAIFMT_IB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
ssicr |= CR_SWSP;
break;
default:
pr_debug("ssi: invalid inversion\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
break;
case SND_SOC_DAIFMT_CBS_CFM:
ssicr |= CR_SCK_MASTER;
break;
case SND_SOC_DAIFMT_CBM_CFS:
ssicr |= CR_SWS_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
ssicr |= CR_SWS_MASTER | CR_SCK_MASTER;
break;
default:
pr_debug("ssi: invalid master/slave configuration\n");
return -EINVAL;
}
SSIREG(SSICR) = ssicr;
pr_debug("ssi_set_fmt() leave\nssicr is now 0x%08lx\n", ssicr);
return 0;
}
static int sh4_soc_dai_probe(struct platform_device *pdev)
{
return snd_soc_register_dais(&pdev->dev, sh4_ssi_dai,
ARRAY_SIZE(sh4_ssi_dai));
}
static int sh4_soc_dai_remove(struct platform_device *pdev)
{
snd_soc_unregister_dais(&pdev->dev, ARRAY_SIZE(sh4_ssi_dai));
return 0;
}
