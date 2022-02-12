static int wm8524_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8524_priv *wm8524 = snd_soc_codec_get_drvdata(codec);
if (!wm8524->sysclk) {
dev_err(codec->dev,
"No MCLK configured, call set_sysclk() on init\n");
return -EINVAL;
}
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&wm8524->rate_constraint);
gpiod_set_value_cansleep(wm8524->mute, 1);
return 0;
}
static void wm8524_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8524_priv *wm8524 = snd_soc_codec_get_drvdata(codec);
gpiod_set_value_cansleep(wm8524->mute, 0);
}
static int wm8524_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8524_priv *wm8524 = snd_soc_codec_get_drvdata(codec);
unsigned int val;
int i, j = 0;
wm8524->sysclk = freq;
wm8524->rate_constraint.count = 0;
for (i = 0; i < ARRAY_SIZE(lrclk_ratios); i++) {
val = freq / lrclk_ratios[i].ratio;
switch (val) {
case 8000:
case 32000:
case 44100:
case 48000:
case 88200:
case 96000:
case 176400:
case 192000:
dev_dbg(codec->dev, "Supported sample rate: %dHz\n",
val);
wm8524->rate_constraint_list[j++] = val;
wm8524->rate_constraint.count++;
break;
default:
dev_dbg(codec->dev, "Skipping sample rate: %dHz\n",
val);
}
}
if (wm8524->rate_constraint.count == 0)
return -EINVAL;
return 0;
}
static int wm8524_set_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
fmt &= (SND_SOC_DAIFMT_FORMAT_MASK | SND_SOC_DAIFMT_INV_MASK |
SND_SOC_DAIFMT_MASTER_MASK);
if (fmt != (SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBS_CFS)) {
dev_err(codec_dai->dev, "Invalid DAI format\n");
return -EINVAL;
}
return 0;
}
static int wm8524_mute_stream(struct snd_soc_dai *dai, int mute, int stream)
{
struct wm8524_priv *wm8524 = snd_soc_codec_get_drvdata(dai->codec);
if (wm8524->mute)
gpiod_set_value_cansleep(wm8524->mute, mute);
return 0;
}
static int wm8524_probe(struct snd_soc_codec *codec)
{
struct wm8524_priv *wm8524 = snd_soc_codec_get_drvdata(codec);
wm8524->rate_constraint.list = &wm8524->rate_constraint_list[0];
wm8524->rate_constraint.count =
ARRAY_SIZE(wm8524->rate_constraint_list);
return 0;
}
static int wm8524_codec_probe(struct platform_device *pdev)
{
struct wm8524_priv *wm8524;
int ret;
wm8524 = devm_kzalloc(&pdev->dev, sizeof(struct wm8524_priv),
GFP_KERNEL);
if (wm8524 == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, wm8524);
wm8524->mute = devm_gpiod_get(&pdev->dev, "wlf,mute", GPIOD_OUT_LOW);
if (IS_ERR(wm8524->mute)) {
ret = PTR_ERR(wm8524->mute);
dev_err(&pdev->dev, "Failed to get mute line: %d\n", ret);
return ret;
}
ret = snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_wm8524, &wm8524_dai, 1);
if (ret < 0)
dev_err(&pdev->dev, "Failed to register codec: %d\n", ret);
return ret;
}
static int wm8524_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
