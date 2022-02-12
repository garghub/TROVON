static unsigned int ac97_read(struct snd_soc_codec *codec, unsigned int reg)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
u16 *cache = codec->reg_cache;
switch (reg) {
case AC97_RESET:
case AC97_VENDOR_ID1:
case AC97_VENDOR_ID2:
return soc_ac97_ops->read(ac97, reg);
default:
reg = reg >> 1;
if (reg >= (ARRAY_SIZE(wm9705_reg)))
return -EIO;
return cache[reg];
}
}
static int ac97_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int val)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
u16 *cache = codec->reg_cache;
soc_ac97_ops->write(ac97, reg, val);
reg = reg >> 1;
if (reg < (ARRAY_SIZE(wm9705_reg)))
cache[reg] = val;
return 0;
}
static int ac97_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
int reg;
u16 vra;
vra = ac97_read(codec, AC97_EXTENDED_STATUS);
ac97_write(codec, AC97_EXTENDED_STATUS, vra | 0x1);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
reg = AC97_PCM_FRONT_DAC_RATE;
else
reg = AC97_PCM_LR_ADC_RATE;
return ac97_write(codec, reg, substream->runtime->rate);
}
static int wm9705_soc_suspend(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
soc_ac97_ops->write(ac97, AC97_POWERDOWN, 0xffff);
return 0;
}
static int wm9705_soc_resume(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
int i, ret;
u16 *cache = codec->reg_cache;
ret = snd_ac97_reset(ac97, true, WM9705_VENDOR_ID,
WM9705_VENDOR_ID_MASK);
if (ret < 0)
return ret;
for (i = 2; i < ARRAY_SIZE(wm9705_reg) << 1; i += 2) {
soc_ac97_ops->write(ac97, i, cache[i>>1]);
}
return 0;
}
static int wm9705_soc_probe(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97;
ac97 = snd_soc_new_ac97_codec(codec, WM9705_VENDOR_ID,
WM9705_VENDOR_ID_MASK);
if (IS_ERR(ac97)) {
dev_err(codec->dev, "Failed to register AC97 codec\n");
return PTR_ERR(ac97);
}
snd_soc_codec_set_drvdata(codec, ac97);
return 0;
}
static int wm9705_soc_remove(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
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
