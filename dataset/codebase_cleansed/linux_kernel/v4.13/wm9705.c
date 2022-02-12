static int ac97_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
int reg;
snd_soc_update_bits(codec, AC97_EXTENDED_STATUS, 0x1, 0x1);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
reg = AC97_PCM_FRONT_DAC_RATE;
else
reg = AC97_PCM_LR_ADC_RATE;
return snd_soc_write(codec, reg, substream->runtime->rate);
}
static int wm9705_soc_suspend(struct snd_soc_codec *codec)
{
regcache_cache_bypass(codec->component.regmap, true);
snd_soc_write(codec, AC97_POWERDOWN, 0xffff);
regcache_cache_bypass(codec->component.regmap, false);
return 0;
}
static int wm9705_soc_resume(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = snd_ac97_reset(ac97, true, WM9705_VENDOR_ID,
WM9705_VENDOR_ID_MASK);
if (ret < 0)
return ret;
regcache_sync(codec->component.regmap);
return 0;
}
static int wm9705_soc_probe(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97;
struct regmap *regmap;
int ret;
ac97 = snd_soc_new_ac97_codec(codec, WM9705_VENDOR_ID,
WM9705_VENDOR_ID_MASK);
if (IS_ERR(ac97)) {
dev_err(codec->dev, "Failed to register AC97 codec\n");
return PTR_ERR(ac97);
}
regmap = regmap_init_ac97(ac97, &wm9705_regmap_config);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
goto err_free_ac97_codec;
}
snd_soc_codec_set_drvdata(codec, ac97);
snd_soc_codec_init_regmap(codec, regmap);
return 0;
err_free_ac97_codec:
snd_soc_free_ac97_codec(ac97);
return ret;
}
static int wm9705_soc_remove(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
snd_soc_codec_exit_regmap(codec);
snd_soc_free_ac97_codec(ac97);
return 0;
}
static int wm9705_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_wm9705, wm9705_dai, ARRAY_SIZE(wm9705_dai));
}
static int wm9705_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
