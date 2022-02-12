static unsigned int ac97_read(struct snd_soc_codec *codec, unsigned int reg)
{
u16 *cache = codec->reg_cache;
switch (reg) {
case AC97_RESET:
case AC97_VENDOR_ID1:
case AC97_VENDOR_ID2:
return soc_ac97_ops.read(codec->ac97, reg);
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
u16 *cache = codec->reg_cache;
soc_ac97_ops.write(codec->ac97, reg, val);
reg = reg >> 1;
if (reg < (ARRAY_SIZE(wm9705_reg)))
cache[reg] = val;
return 0;
}
static int ac97_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
int reg;
u16 vra;
vra = ac97_read(codec, AC97_EXTENDED_STATUS);
ac97_write(codec, AC97_EXTENDED_STATUS, vra | 0x1);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
reg = AC97_PCM_FRONT_DAC_RATE;
else
reg = AC97_PCM_LR_ADC_RATE;
return ac97_write(codec, reg, runtime->rate);
}
static int wm9705_reset(struct snd_soc_codec *codec)
{
if (soc_ac97_ops.reset) {
soc_ac97_ops.reset(codec->ac97);
if (ac97_read(codec, 0) == wm9705_reg[0])
return 0;
}
return -EIO;
}
static int wm9705_soc_suspend(struct snd_soc_codec *codec, pm_message_t msg)
{
soc_ac97_ops.write(codec->ac97, AC97_POWERDOWN, 0xffff);
return 0;
}
static int wm9705_soc_resume(struct snd_soc_codec *codec)
{
int i, ret;
u16 *cache = codec->reg_cache;
ret = wm9705_reset(codec);
if (ret < 0) {
printk(KERN_ERR "could not reset AC97 codec\n");
return ret;
}
for (i = 2; i < ARRAY_SIZE(wm9705_reg) << 1; i += 2) {
soc_ac97_ops.write(codec->ac97, i, cache[i>>1]);
}
return 0;
}
static int wm9705_soc_probe(struct snd_soc_codec *codec)
{
int ret = 0;
printk(KERN_INFO "WM9705 SoC Audio Codec\n");
ret = snd_soc_new_ac97_codec(codec, &soc_ac97_ops, 0);
if (ret < 0) {
printk(KERN_ERR "wm9705: failed to register AC97 codec\n");
return ret;
}
ret = wm9705_reset(codec);
if (ret)
goto reset_err;
snd_soc_add_controls(codec, wm9705_snd_ac97_controls,
ARRAY_SIZE(wm9705_snd_ac97_controls));
return 0;
reset_err:
snd_soc_free_ac97_codec(codec);
return ret;
}
static int wm9705_soc_remove(struct snd_soc_codec *codec)
{
snd_soc_free_ac97_codec(codec);
return 0;
}
static __devinit int wm9705_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_wm9705, wm9705_dai, ARRAY_SIZE(wm9705_dai));
}
static int __devexit wm9705_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
static int __init wm9705_init(void)
{
return platform_driver_register(&wm9705_codec_driver);
}
static void __exit wm9705_exit(void)
{
platform_driver_unregister(&wm9705_codec_driver);
}
