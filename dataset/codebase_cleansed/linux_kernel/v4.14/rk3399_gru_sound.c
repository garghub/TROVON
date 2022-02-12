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
msleep(dmic_wakeup_delay);
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
static int rockchip_sound_cdndp_hw_params(struct snd_pcm_substream *substream,
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
return 0;
}
static int rockchip_sound_dmic_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
unsigned int mclk;
int ret;
mclk = params_rate(params) * SOUND_FS;
ret = snd_soc_dai_set_sysclk(rtd->cpu_dai, 0, mclk, 0);
if (ret) {
dev_err(rtd->card->dev, "%s() error setting sysclk to %u: %d\n",
__func__, mclk, ret);
return ret;
}
msleep(dmic_wakeup_delay);
return 0;
}
static int rockchip_sound_codec_node_match(struct device_node *np_codec)
{
int i;
for (i = 0; i < ARRAY_SIZE(dailink_compat); i++) {
if (of_device_is_compatible(np_codec, dailink_compat[i]))
return i;
}
return -1;
}
static int rockchip_sound_of_parse_dais(struct device *dev,
struct snd_soc_card *card)
{
struct device_node *np_cpu, *np_cpu0, *np_cpu1;
struct device_node *np_codec;
struct snd_soc_dai_link *dai;
int i, index;
card->dai_link = devm_kzalloc(dev, sizeof(rockchip_dais),
GFP_KERNEL);
if (!card->dai_link)
return -ENOMEM;
np_cpu0 = of_parse_phandle(dev->of_node, "rockchip,cpu", 0);
np_cpu1 = of_parse_phandle(dev->of_node, "rockchip,cpu", 1);
card->num_links = 0;
for (i = 0; i < ARRAY_SIZE(rockchip_dais); i++) {
np_codec = of_parse_phandle(dev->of_node,
"rockchip,codec", i);
if (!np_codec)
break;
if (!of_device_is_available(np_codec))
continue;
index = rockchip_sound_codec_node_match(np_codec);
if (index < 0)
continue;
np_cpu = (index == DAILINK_CDNDP) ? np_cpu1 : np_cpu0;
if (!np_cpu) {
dev_err(dev, "Missing 'rockchip,cpu' for %s\n",
rockchip_dais[index].name);
return -EINVAL;
}
dai = &card->dai_link[card->num_links++];
*dai = rockchip_dais[index];
dai->codec_of_node = np_codec;
dai->platform_of_node = np_cpu;
dai->cpu_of_node = np_cpu;
}
return 0;
}
static int rockchip_sound_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &rockchip_sound_card;
int ret;
ret = rockchip_sound_of_parse_dais(&pdev->dev, card);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to parse dais: %d\n", ret);
return ret;
}
ret = device_property_read_u32(&pdev->dev, "dmic-wakeup-delay-ms",
&dmic_wakeup_delay);
if (ret) {
dmic_wakeup_delay = 0;
dev_dbg(&pdev->dev,
"no optional property 'dmic-wakeup-delay-ms' found, default: no delay\n");
}
card->dev = &pdev->dev;
return devm_snd_soc_register_card(&pdev->dev, card);
}
