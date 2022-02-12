static int rk_aif1_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
int ret = 0;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int mclk;
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
dev_err(codec_dai->dev, "Can't set codec clock %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0, mclk,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(codec_dai->dev, "Can't set codec clock %d\n", ret);
return ret;
}
return ret;
}
static int rk_98090_headset_init(struct snd_soc_component *component)
{
int ret;
ret = snd_soc_card_jack_new(&snd_soc_card_rk, "Headset Jack",
SND_JACK_HEADSET |
SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3,
&headset_jack,
headset_jack_pins,
ARRAY_SIZE(headset_jack_pins));
if (ret)
return ret;
ret = ts3a227e_enable_jack_detect(component, &headset_jack);
return ret;
}
static int snd_rk_mc_probe(struct platform_device *pdev)
{
int ret = 0;
struct snd_soc_card *card = &snd_soc_card_rk;
struct device_node *np = pdev->dev.of_node;
card->dev = &pdev->dev;
rk_dailink.codec_of_node = of_parse_phandle(np,
"rockchip,audio-codec", 0);
if (!rk_dailink.codec_of_node) {
dev_err(&pdev->dev,
"Property 'rockchip,audio-codec' missing or invalid\n");
return -EINVAL;
}
rk_dailink.cpu_of_node = of_parse_phandle(np,
"rockchip,i2s-controller", 0);
if (!rk_dailink.cpu_of_node) {
dev_err(&pdev->dev,
"Property 'rockchip,i2s-controller' missing or invalid\n");
return -EINVAL;
}
rk_dailink.platform_of_node = rk_dailink.cpu_of_node;
rk_98090_headset_dev.codec_of_node = of_parse_phandle(np,
"rockchip,headset-codec", 0);
if (!rk_98090_headset_dev.codec_of_node) {
dev_err(&pdev->dev,
"Property 'rockchip,headset-codec' missing/invalid\n");
return -EINVAL;
}
ret = snd_soc_of_parse_card_name(card, "rockchip,model");
if (ret) {
dev_err(&pdev->dev,
"Soc parse card name failed %d\n", ret);
return ret;
}
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret) {
dev_err(&pdev->dev,
"Soc register card failed %d\n", ret);
return ret;
}
return ret;
}
