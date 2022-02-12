static int rockchip_sound_max98357a_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
unsigned int mclk;
int ret;
switch (params_rate(params)) {
case 8000:
case 16000:
case 48000:
case 96000:
mclk = params_rate(params) * SOUND_FS;
break;
default:
dev_err(rtd->card->dev, "%s() doesn't support this sample rate: %d\n",
__func__, params_rate(params));
return -EINVAL;
}
ret = snd_soc_dai_set_sysclk(rtd->cpu_dai, 0, mclk, 0);
if (ret) {
dev_err(rtd->card->dev, "%s() error setting sysclk to %u: %d\n",
__func__, mclk, ret);
return ret;
}
return 0;
}
static int rockchip_sound_rt5514_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
unsigned int mclk;
int ret;
mclk = params_rate(params) * SOUND_FS;
ret = snd_soc_dai_set_sysclk(cpu_dai, 0, mclk,
SND_SOC_CLOCK_OUT);
if (ret < 0) {
dev_err(rtd->card->dev, "Can't set cpu clock out %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, RT5514_SCLK_S_MCLK,
mclk, SND_SOC_CLOCK_IN);
if (ret) {
dev_err(rtd->card->dev, "%s() error setting sysclk to %u: %d\n",
__func__, params_rate(params) * 512, ret);
return ret;
}
msleep(rt5514_dmic_delay);
return 0;
}
static int rockchip_sound_da7219_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int mclk, ret;
switch (params_rate(params)) {
case 8000:
case 16000:
case 24000:
case 32000:
case 48000:
case 64000:
case 96000:
mclk = 12288000;
break;
case 11025:
case 22050:
case 44100:
case 88200:
mclk = 11289600;
break;
default:
return -EINVAL;
}
ret = snd_soc_dai_set_sysclk(cpu_dai, 0, mclk,
SND_SOC_CLOCK_OUT);
if (ret < 0) {
dev_err(codec_dai->dev, "Can't set cpu clock out %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0, mclk,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(codec_dai->dev, "Can't set codec clock in %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_pll(codec_dai, 0, DA7219_SYSCLK_MCLK, 0, 0);
if (ret < 0) {
dev_err(codec_dai->dev, "Can't set pll sysclk mclk %d\n", ret);
return ret;
}
return 0;
}
static int rockchip_sound_da7219_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec_dais[0]->codec;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 0, 12288000,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(codec_dai->dev, "Init can't set codec clock in %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_pll(codec_dai, 0, DA7219_SYSCLK_MCLK, 0, 0);
if (ret < 0) {
dev_err(codec_dai->dev, "Init can't set pll sysclk mclk %d\n", ret);
return ret;
}
ret = snd_soc_card_jack_new(rtd->card, "Headset Jack",
SND_JACK_HEADSET | SND_JACK_LINEOUT |
SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3,
&rockchip_sound_jack, NULL, 0);
if (ret) {
dev_err(rtd->card->dev, "New Headset Jack failed! (%d)\n", ret);
return ret;
}
snd_jack_set_key(rockchip_sound_jack.jack, SND_JACK_BTN_0, KEY_MEDIA);
snd_jack_set_key(
rockchip_sound_jack.jack, SND_JACK_BTN_1, KEY_VOLUMEUP);
snd_jack_set_key(
rockchip_sound_jack.jack, SND_JACK_BTN_2, KEY_VOLUMEDOWN);
snd_jack_set_key(
rockchip_sound_jack.jack, SND_JACK_BTN_3, KEY_VOICECOMMAND);
da7219_aad_jack_det(codec, &rockchip_sound_jack);
return 0;
}
static int rockchip_sound_match_stub(struct device *dev, void *data)
{
return 1;
}
static int rockchip_sound_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &rockchip_sound_card;
struct device_node *cpu_node;
struct device *dev;
struct device_driver *drv;
int i, ret;
cpu_node = of_parse_phandle(pdev->dev.of_node, "rockchip,cpu", 0);
if (!cpu_node) {
dev_err(&pdev->dev, "Property 'rockchip,cpu' missing or invalid\n");
return -EINVAL;
}
for (i = 0; i < DAILINK_ENTITIES; i++) {
rockchip_dailinks[i].platform_of_node = cpu_node;
rockchip_dailinks[i].cpu_of_node = cpu_node;
rockchip_dailinks[i].codec_of_node =
of_parse_phandle(pdev->dev.of_node, "rockchip,codec", i);
if (!rockchip_dailinks[i].codec_of_node) {
dev_err(&pdev->dev,
"Property[%d] 'rockchip,codec' missing or invalid\n", i);
return -EINVAL;
}
}
drv = driver_find("rt5514", &spi_bus_type);
if (!drv) {
dev_err(&pdev->dev, "Can not find the rt5514 driver at the spi bus\n");
return -EINVAL;
}
dev = driver_find_device(drv, NULL, NULL, rockchip_sound_match_stub);
if (!dev) {
dev_err(&pdev->dev, "Can not find the rt5514 device\n");
return -ENODEV;
}
ret = device_property_read_u32(&pdev->dev, "dmic-delay",
&rt5514_dmic_delay);
if (ret) {
rt5514_dmic_delay = 0;
dev_dbg(&pdev->dev,
"no optional property 'dmic-delay' found, default: no delay\n");
}
rockchip_dailinks[DAILINK_RT5514_DSP].cpu_name = kstrdup_const(dev_name(dev), GFP_KERNEL);
rockchip_dailinks[DAILINK_RT5514_DSP].cpu_dai_name = kstrdup_const(dev_name(dev), GFP_KERNEL);
rockchip_dailinks[DAILINK_RT5514_DSP].platform_name = kstrdup_const(dev_name(dev), GFP_KERNEL);
card->dev = &pdev->dev;
platform_set_drvdata(pdev, card);
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret)
dev_err(&pdev->dev, "%s snd_soc_register_card fail %d\n",
__func__, ret);
return ret;
}
