static int stac9766_ac97_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int val)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
u16 *cache = codec->reg_cache;
if (reg > AC97_STAC_PAGE0) {
stac9766_ac97_write(codec, AC97_INT_PAGING, 0);
soc_ac97_ops->write(ac97, reg, val);
stac9766_ac97_write(codec, AC97_INT_PAGING, 1);
return 0;
}
if (reg / 2 >= ARRAY_SIZE(stac9766_reg))
return -EIO;
soc_ac97_ops->write(ac97, reg, val);
cache[reg / 2] = val;
return 0;
}
static unsigned int stac9766_ac97_read(struct snd_soc_codec *codec,
unsigned int reg)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
u16 val = 0, *cache = codec->reg_cache;
if (reg > AC97_STAC_PAGE0) {
stac9766_ac97_write(codec, AC97_INT_PAGING, 0);
val = soc_ac97_ops->read(ac97, reg - AC97_STAC_PAGE0);
stac9766_ac97_write(codec, AC97_INT_PAGING, 1);
return val;
}
if (reg / 2 >= ARRAY_SIZE(stac9766_reg))
return -EIO;
if (reg == AC97_RESET || reg == AC97_GPIO_STATUS ||
reg == AC97_INT_PAGING || reg == AC97_VENDOR_ID1 ||
reg == AC97_VENDOR_ID2) {
val = soc_ac97_ops->read(ac97, reg);
return val;
}
return cache[reg / 2];
}
static int ac97_analog_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned short reg, vra;
vra = stac9766_ac97_read(codec, AC97_EXTENDED_STATUS);
vra |= 0x1;
vra &= ~0x4;
stac9766_ac97_write(codec, AC97_EXTENDED_STATUS, vra);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
reg = AC97_PCM_FRONT_DAC_RATE;
else
reg = AC97_PCM_LR_ADC_RATE;
return stac9766_ac97_write(codec, reg, runtime->rate);
}
static int ac97_digital_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned short reg, vra;
stac9766_ac97_write(codec, AC97_SPDIF, 0x2002);
vra = stac9766_ac97_read(codec, AC97_EXTENDED_STATUS);
vra |= 0x5;
stac9766_ac97_write(codec, AC97_EXTENDED_STATUS, vra);
reg = AC97_PCM_FRONT_DAC_RATE;
return stac9766_ac97_write(codec, reg, runtime->rate);
}
static int stac9766_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
case SND_SOC_BIAS_STANDBY:
stac9766_ac97_write(codec, AC97_POWERDOWN, 0x0000);
break;
case SND_SOC_BIAS_OFF:
stac9766_ac97_write(codec, AC97_POWERDOWN, 0xffff);
break;
}
return 0;
}
static int stac9766_reset(struct snd_soc_codec *codec, int try_warm)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
if (try_warm && soc_ac97_ops->warm_reset) {
soc_ac97_ops->warm_reset(ac97);
if (stac9766_ac97_read(codec, 0) == stac9766_reg[0])
return 1;
}
soc_ac97_ops->reset(ac97);
if (soc_ac97_ops->warm_reset)
soc_ac97_ops->warm_reset(ac97);
if (stac9766_ac97_read(codec, 0) != stac9766_reg[0])
return -EIO;
return 0;
}
static int stac9766_codec_resume(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
u16 id, reset;
reset = 0;
reset:
if (reset > 5) {
dev_err(codec->dev, "Failed to resume\n");
return -EIO;
}
ac97->bus->ops->warm_reset(ac97);
id = soc_ac97_ops->read(ac97, AC97_VENDOR_ID2);
if (id != 0x4c13) {
stac9766_reset(codec, 0);
reset++;
goto reset;
}
return 0;
}
static int stac9766_codec_probe(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97;
int ret = 0;
ac97 = snd_soc_new_ac97_codec(codec);
if (IS_ERR(ac97))
return PTR_ERR(ac97);
snd_soc_codec_set_drvdata(codec, ac97);
stac9766_reset(codec, 0);
ret = stac9766_reset(codec, 1);
if (ret < 0) {
dev_err(codec->dev, "Failed to reset: AC97 link error\n");
goto codec_err;
}
return 0;
codec_err:
snd_soc_free_ac97_codec(ac97);
return ret;
}
static int stac9766_codec_remove(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
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
