static int stac9766_ac97_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int val)
{
u16 *cache = codec->reg_cache;
if (reg > AC97_STAC_PAGE0) {
stac9766_ac97_write(codec, AC97_INT_PAGING, 0);
soc_ac97_ops.write(codec->ac97, reg, val);
stac9766_ac97_write(codec, AC97_INT_PAGING, 1);
return 0;
}
if (reg / 2 >= ARRAY_SIZE(stac9766_reg))
return -EIO;
soc_ac97_ops.write(codec->ac97, reg, val);
cache[reg / 2] = val;
return 0;
}
static unsigned int stac9766_ac97_read(struct snd_soc_codec *codec,
unsigned int reg)
{
u16 val = 0, *cache = codec->reg_cache;
if (reg > AC97_STAC_PAGE0) {
stac9766_ac97_write(codec, AC97_INT_PAGING, 0);
val = soc_ac97_ops.read(codec->ac97, reg - AC97_STAC_PAGE0);
stac9766_ac97_write(codec, AC97_INT_PAGING, 1);
return val;
}
if (reg / 2 >= ARRAY_SIZE(stac9766_reg))
return -EIO;
if (reg == AC97_RESET || reg == AC97_GPIO_STATUS ||
reg == AC97_INT_PAGING || reg == AC97_VENDOR_ID1 ||
reg == AC97_VENDOR_ID2) {
val = soc_ac97_ops.read(codec->ac97, reg);
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
codec->dapm.bias_level = level;
return 0;
}
static int stac9766_reset(struct snd_soc_codec *codec, int try_warm)
{
if (try_warm && soc_ac97_ops.warm_reset) {
soc_ac97_ops.warm_reset(codec->ac97);
if (stac9766_ac97_read(codec, 0) == stac9766_reg[0])
return 1;
}
soc_ac97_ops.reset(codec->ac97);
if (soc_ac97_ops.warm_reset)
soc_ac97_ops.warm_reset(codec->ac97);
if (stac9766_ac97_read(codec, 0) != stac9766_reg[0])
return -EIO;
return 0;
}
static int stac9766_codec_suspend(struct snd_soc_codec *codec,
pm_message_t state)
{
stac9766_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int stac9766_codec_resume(struct snd_soc_codec *codec)
{
u16 id, reset;
reset = 0;
reset:
if (reset > 5) {
printk(KERN_ERR "stac9766 failed to resume");
return -EIO;
}
codec->ac97->bus->ops->warm_reset(codec->ac97);
id = soc_ac97_ops.read(codec->ac97, AC97_VENDOR_ID2);
if (id != 0x4c13) {
stac9766_reset(codec, 0);
reset++;
goto reset;
}
stac9766_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int stac9766_codec_probe(struct snd_soc_codec *codec)
{
int ret = 0;
printk(KERN_INFO "STAC9766 SoC Audio Codec %s\n", STAC9766_VERSION);
ret = snd_soc_new_ac97_codec(codec, &soc_ac97_ops, 0);
if (ret < 0)
goto codec_err;
stac9766_reset(codec, 0);
ret = stac9766_reset(codec, 1);
if (ret < 0) {
printk(KERN_ERR "Failed to reset STAC9766: AC97 link error\n");
goto codec_err;
}
stac9766_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_add_controls(codec, stac9766_snd_ac97_controls,
ARRAY_SIZE(stac9766_snd_ac97_controls));
return 0;
codec_err:
snd_soc_free_ac97_codec(codec);
return ret;
}
static int stac9766_codec_remove(struct snd_soc_codec *codec)
{
snd_soc_free_ac97_codec(codec);
return 0;
}
static __devinit int stac9766_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_stac9766, stac9766_dai, ARRAY_SIZE(stac9766_dai));
}
static int __devexit stac9766_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
static int __init stac9766_init(void)
{
return platform_driver_register(&stac9766_codec_driver);
}
static void __exit stac9766_exit(void)
{
platform_driver_unregister(&stac9766_codec_driver);
}
