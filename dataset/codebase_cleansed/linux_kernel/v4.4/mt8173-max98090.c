static int mt8173_max98090_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
return snd_soc_dai_set_sysclk(codec_dai, 0, params_rate(params) * 256,
SND_SOC_CLOCK_IN);
}
static int mt8173_max98090_init(struct snd_soc_pcm_runtime *runtime)
{
int ret;
struct snd_soc_card *card = runtime->card;
struct snd_soc_codec *codec = runtime->codec;
ret = snd_soc_card_jack_new(card, "Headphone", SND_JACK_HEADPHONE,
&mt8173_max98090_jack, NULL, 0);
if (ret) {
dev_err(card->dev, "Can't snd_soc_jack_new %d\n", ret);
return ret;
}
ret = snd_soc_jack_add_pins(&mt8173_max98090_jack,
ARRAY_SIZE(mt8173_max98090_jack_pins),
mt8173_max98090_jack_pins);
if (ret) {
dev_err(card->dev, "Can't snd_soc_jack_add_pins %d\n", ret);
return ret;
}
return max98090_mic_detect(codec, &mt8173_max98090_jack);
}
static int mt8173_max98090_dev_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &mt8173_max98090_card;
struct device_node *codec_node, *platform_node;
int ret, i;
platform_node = of_parse_phandle(pdev->dev.of_node,
"mediatek,platform", 0);
if (!platform_node) {
dev_err(&pdev->dev, "Property 'platform' missing or invalid\n");
return -EINVAL;
}
for (i = 0; i < card->num_links; i++) {
if (mt8173_max98090_dais[i].platform_name)
continue;
mt8173_max98090_dais[i].platform_of_node = platform_node;
}
codec_node = of_parse_phandle(pdev->dev.of_node,
"mediatek,audio-codec", 0);
if (!codec_node) {
dev_err(&pdev->dev,
"Property 'audio-codec' missing or invalid\n");
return -EINVAL;
}
for (i = 0; i < card->num_links; i++) {
if (mt8173_max98090_dais[i].codec_name)
continue;
mt8173_max98090_dais[i].codec_of_node = codec_node;
}
card->dev = &pdev->dev;
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret)
dev_err(&pdev->dev, "%s snd_soc_register_card fail %d\n",
__func__, ret);
return ret;
}
