static int ac97_analog_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned short reg;
snd_soc_update_bits(codec, AC97_EXTENDED_STATUS, 0x5, 0x1);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
reg = AC97_PCM_FRONT_DAC_RATE;
else
reg = AC97_PCM_LR_ADC_RATE;
return snd_soc_write(codec, reg, runtime->rate);
}
static int ac97_digital_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned short reg;
snd_soc_write(codec, AC97_SPDIF, 0x2002);
snd_soc_update_bits(codec, AC97_EXTENDED_STATUS, 0x5, 0x5);
reg = AC97_PCM_FRONT_DAC_RATE;
return snd_soc_write(codec, reg, runtime->rate);
}
static int stac9766_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
case SND_SOC_BIAS_STANDBY:
snd_soc_write(codec, AC97_POWERDOWN, 0x0000);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, AC97_POWERDOWN, 0xffff);
break;
}
return 0;
}
static int stac9766_codec_resume(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
return snd_ac97_reset(ac97, true, STAC9766_VENDOR_ID,
STAC9766_VENDOR_ID_MASK);
}
static int stac9766_codec_probe(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97;
struct regmap *regmap;
int ret;
ac97 = snd_soc_new_ac97_codec(codec, STAC9766_VENDOR_ID,
STAC9766_VENDOR_ID_MASK);
if (IS_ERR(ac97))
return PTR_ERR(ac97);
regmap = regmap_init_ac97(ac97, &stac9766_regmap_config);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
goto err_free_ac97;
}
snd_soc_codec_init_regmap(codec, regmap);
snd_soc_codec_set_drvdata(codec, ac97);
return 0;
err_free_ac97:
snd_soc_free_ac97_codec(ac97);
return ret;
}
static int stac9766_codec_remove(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
snd_soc_codec_exit_regmap(codec);
snd_soc_free_ac97_codec(ac97);
return 0;
}
static int stac9766_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_stac9766, stac9766_dai, ARRAY_SIZE(stac9766_dai));
}
static int stac9766_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
