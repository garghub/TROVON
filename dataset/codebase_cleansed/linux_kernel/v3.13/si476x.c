static int si476x_codec_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct si476x_core *core = i2c_mfd_cell_to_core(codec_dai->dev);
int err;
u16 format = 0;
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS)
return -EINVAL;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
format |= SI476X_DAUDIO_MODE_DSP_A;
break;
case SND_SOC_DAIFMT_DSP_B:
format |= SI476X_DAUDIO_MODE_DSP_B;
break;
case SND_SOC_DAIFMT_I2S:
format |= SI476X_DAUDIO_MODE_I2S;
break;
case SND_SOC_DAIFMT_RIGHT_J:
format |= SI476X_DAUDIO_MODE_RIGHT_J;
break;
case SND_SOC_DAIFMT_LEFT_J:
format |= SI476X_DAUDIO_MODE_LEFT_J;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
format |= SI476X_DAUDIO_MODE_IB;
break;
default:
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_RIGHT_J:
case SND_SOC_DAIFMT_LEFT_J:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
format |= SI476X_DAUDIO_MODE_IB |
SI476X_DAUDIO_MODE_IF;
break;
case SND_SOC_DAIFMT_IB_NF:
format |= SI476X_DAUDIO_MODE_IB;
break;
case SND_SOC_DAIFMT_NB_IF:
format |= SI476X_DAUDIO_MODE_IF;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
si476x_core_lock(core);
err = snd_soc_update_bits(codec_dai->codec, SI476X_DIGITAL_IO_OUTPUT_FORMAT,
SI476X_DIGITAL_IO_OUTPUT_FORMAT_MASK,
format);
si476x_core_unlock(core);
if (err < 0) {
dev_err(codec_dai->codec->dev, "Failed to set output format\n");
return err;
}
return 0;
}
static int si476x_codec_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct si476x_core *core = i2c_mfd_cell_to_core(dai->dev);
int rate, width, err;
rate = params_rate(params);
if (rate < 32000 || rate > 48000) {
dev_err(dai->codec->dev, "Rate: %d is not supported\n", rate);
return -EINVAL;
}
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
width = SI476X_PCM_FORMAT_S8;
break;
case SNDRV_PCM_FORMAT_S16_LE:
width = SI476X_PCM_FORMAT_S16_LE;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
width = SI476X_PCM_FORMAT_S20_3LE;
break;
case SNDRV_PCM_FORMAT_S24_LE:
width = SI476X_PCM_FORMAT_S24_LE;
break;
default:
return -EINVAL;
}
si476x_core_lock(core);
err = snd_soc_write(dai->codec, SI476X_DIGITAL_IO_OUTPUT_SAMPLE_RATE,
rate);
if (err < 0) {
dev_err(dai->codec->dev, "Failed to set sample rate\n");
goto out;
}
err = snd_soc_update_bits(dai->codec, SI476X_DIGITAL_IO_OUTPUT_FORMAT,
SI476X_DIGITAL_IO_OUTPUT_WIDTH_MASK,
(width << SI476X_DIGITAL_IO_SLOT_SIZE_SHIFT) |
(width << SI476X_DIGITAL_IO_SAMPLE_SIZE_SHIFT));
if (err < 0) {
dev_err(dai->codec->dev, "Failed to set output width\n");
goto out;
}
out:
si476x_core_unlock(core);
return err;
}
static int si476x_codec_probe(struct snd_soc_codec *codec)
{
codec->control_data = dev_get_regmap(codec->dev->parent, NULL);
return 0;
}
static int si476x_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_si476x,
&si476x_dai, 1);
}
static int si476x_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
