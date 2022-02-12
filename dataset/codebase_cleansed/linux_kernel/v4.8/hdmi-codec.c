static int hdmi_eld_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct hdmi_codec_priv *hcp = snd_soc_component_get_drvdata(component);
uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
uinfo->count = sizeof(hcp->eld);
return 0;
}
static int hdmi_eld_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct hdmi_codec_priv *hcp = snd_soc_component_get_drvdata(component);
memcpy(ucontrol->value.bytes.data, hcp->eld, sizeof(hcp->eld));
return 0;
}
static int hdmi_codec_new_stream(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct hdmi_codec_priv *hcp = snd_soc_dai_get_drvdata(dai);
int ret = 0;
mutex_lock(&hcp->current_stream_lock);
if (!hcp->current_stream) {
hcp->current_stream = substream;
} else if (hcp->current_stream != substream) {
dev_err(dai->dev, "Only one simultaneous stream supported!\n");
ret = -EINVAL;
}
mutex_unlock(&hcp->current_stream_lock);
return ret;
}
static int hdmi_codec_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct hdmi_codec_priv *hcp = snd_soc_dai_get_drvdata(dai);
int ret = 0;
dev_dbg(dai->dev, "%s()\n", __func__);
ret = hdmi_codec_new_stream(substream, dai);
if (ret)
return ret;
if (hcp->hcd.ops->audio_startup) {
ret = hcp->hcd.ops->audio_startup(dai->dev->parent, hcp->hcd.data);
if (ret) {
mutex_lock(&hcp->current_stream_lock);
hcp->current_stream = NULL;
mutex_unlock(&hcp->current_stream_lock);
return ret;
}
}
if (hcp->hcd.ops->get_eld) {
ret = hcp->hcd.ops->get_eld(dai->dev->parent, hcp->hcd.data,
hcp->eld, sizeof(hcp->eld));
if (!ret) {
ret = snd_pcm_hw_constraint_eld(substream->runtime,
hcp->eld);
if (ret)
return ret;
}
}
return 0;
}
static void hdmi_codec_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct hdmi_codec_priv *hcp = snd_soc_dai_get_drvdata(dai);
dev_dbg(dai->dev, "%s()\n", __func__);
WARN_ON(hcp->current_stream != substream);
hcp->hcd.ops->audio_shutdown(dai->dev->parent, hcp->hcd.data);
mutex_lock(&hcp->current_stream_lock);
hcp->current_stream = NULL;
mutex_unlock(&hcp->current_stream_lock);
}
static int hdmi_codec_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct hdmi_codec_priv *hcp = snd_soc_dai_get_drvdata(dai);
struct hdmi_codec_params hp = {
.iec = {
.status = { 0 },
.subcode = { 0 },
.pad = 0,
.dig_subframe = { 0 },
}
};
int ret;
dev_dbg(dai->dev, "%s() width %d rate %d channels %d\n", __func__,
params_width(params), params_rate(params),
params_channels(params));
if (params_width(params) > 24)
params->msbits = 24;
ret = snd_pcm_create_iec958_consumer_hw_params(params, hp.iec.status,
sizeof(hp.iec.status));
if (ret < 0) {
dev_err(dai->dev, "Creating IEC958 channel status failed %d\n",
ret);
return ret;
}
ret = hdmi_codec_new_stream(substream, dai);
if (ret)
return ret;
hdmi_audio_infoframe_init(&hp.cea);
hp.cea.channels = params_channels(params);
hp.cea.coding_type = HDMI_AUDIO_CODING_TYPE_STREAM;
hp.cea.sample_size = HDMI_AUDIO_SAMPLE_SIZE_STREAM;
hp.cea.sample_frequency = HDMI_AUDIO_SAMPLE_FREQUENCY_STREAM;
hp.sample_width = params_width(params);
hp.sample_rate = params_rate(params);
hp.channels = params_channels(params);
return hcp->hcd.ops->hw_params(dai->dev->parent, hcp->hcd.data,
&hcp->daifmt[dai->id], &hp);
}
static int hdmi_codec_set_fmt(struct snd_soc_dai *dai,
unsigned int fmt)
{
struct hdmi_codec_priv *hcp = snd_soc_dai_get_drvdata(dai);
struct hdmi_codec_daifmt cf = { 0 };
int ret = 0;
dev_dbg(dai->dev, "%s()\n", __func__);
if (dai->id == DAI_ID_SPDIF) {
cf.fmt = HDMI_SPDIF;
} else {
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
cf.bit_clk_master = 1;
cf.frame_clk_master = 1;
break;
case SND_SOC_DAIFMT_CBS_CFM:
cf.frame_clk_master = 1;
break;
case SND_SOC_DAIFMT_CBM_CFS:
cf.bit_clk_master = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
cf.frame_clk_inv = 1;
break;
case SND_SOC_DAIFMT_IB_NF:
cf.bit_clk_inv = 1;
break;
case SND_SOC_DAIFMT_IB_IF:
cf.frame_clk_inv = 1;
cf.bit_clk_inv = 1;
break;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
cf.fmt = HDMI_I2S;
break;
case SND_SOC_DAIFMT_DSP_A:
cf.fmt = HDMI_DSP_A;
break;
case SND_SOC_DAIFMT_DSP_B:
cf.fmt = HDMI_DSP_B;
break;
case SND_SOC_DAIFMT_RIGHT_J:
cf.fmt = HDMI_RIGHT_J;
break;
case SND_SOC_DAIFMT_LEFT_J:
cf.fmt = HDMI_LEFT_J;
break;
case SND_SOC_DAIFMT_AC97:
cf.fmt = HDMI_AC97;
break;
default:
dev_err(dai->dev, "Invalid DAI interface format\n");
return -EINVAL;
}
}
hcp->daifmt[dai->id] = cf;
return ret;
}
static int hdmi_codec_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct hdmi_codec_priv *hcp = snd_soc_dai_get_drvdata(dai);
dev_dbg(dai->dev, "%s()\n", __func__);
if (hcp->hcd.ops->digital_mute)
return hcp->hcd.ops->digital_mute(dai->dev->parent,
hcp->hcd.data, mute);
return 0;
}
static int hdmi_codec_probe(struct platform_device *pdev)
{
struct hdmi_codec_pdata *hcd = pdev->dev.platform_data;
struct device *dev = &pdev->dev;
struct hdmi_codec_priv *hcp;
int dai_count, i = 0;
int ret;
dev_dbg(dev, "%s()\n", __func__);
if (!hcd) {
dev_err(dev, "%s: No plalform data\n", __func__);
return -EINVAL;
}
dai_count = hcd->i2s + hcd->spdif;
if (dai_count < 1 || !hcd->ops || !hcd->ops->hw_params ||
!hcd->ops->audio_shutdown) {
dev_err(dev, "%s: Invalid parameters\n", __func__);
return -EINVAL;
}
hcp = devm_kzalloc(dev, sizeof(*hcp), GFP_KERNEL);
if (!hcp)
return -ENOMEM;
hcp->hcd = *hcd;
mutex_init(&hcp->current_stream_lock);
hcp->daidrv = devm_kzalloc(dev, dai_count * sizeof(*hcp->daidrv),
GFP_KERNEL);
if (!hcp->daidrv)
return -ENOMEM;
if (hcd->i2s) {
hcp->daidrv[i] = hdmi_i2s_dai;
hcp->daidrv[i].playback.channels_max =
hcd->max_i2s_channels;
i++;
}
if (hcd->spdif)
hcp->daidrv[i] = hdmi_spdif_dai;
ret = snd_soc_register_codec(dev, &hdmi_codec, hcp->daidrv,
dai_count);
if (ret) {
dev_err(dev, "%s: snd_soc_register_codec() failed (%d)\n",
__func__, ret);
return ret;
}
dev_set_drvdata(dev, hcp);
return 0;
}
static int hdmi_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
