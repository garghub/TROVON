static int mt8173_rt5650_rt5514_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
int i, ret;
for (i = 0; i < rtd->num_codecs; i++) {
struct snd_soc_dai *codec_dai = rtd->codec_dais[i];
ret = snd_soc_dai_set_pll(codec_dai, 0, 0, MCLK_FOR_CODECS,
params_rate(params) * 512);
if (ret)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 1,
params_rate(params) * 512,
SND_SOC_CLOCK_IN);
if (ret)
return ret;
}
return 0;
}
static int mt8173_rt5650_rt5514_init(struct snd_soc_pcm_runtime *runtime)
{
struct snd_soc_card *card = runtime->card;
struct snd_soc_codec *codec = runtime->codec_dais[0]->codec;
int ret;
rt5645_sel_asrc_clk_src(codec,
RT5645_DA_STEREO_FILTER |
RT5645_AD_STEREO_FILTER,
RT5645_CLK_SEL_I2S1_ASRC);
ret = snd_soc_card_jack_new(card, "Headset Jack",
SND_JACK_HEADPHONE | SND_JACK_MICROPHONE |
SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3,
&mt8173_rt5650_rt5514_jack, NULL, 0);
if (ret) {
dev_err(card->dev, "Can't new Headset Jack %d\n", ret);
return ret;
}
return rt5645_set_jack_detect(codec,
&mt8173_rt5650_rt5514_jack,
&mt8173_rt5650_rt5514_jack,
&mt8173_rt5650_rt5514_jack);
}
static int mt8173_rt5650_rt5514_dev_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &mt8173_rt5650_rt5514_card;
struct device_node *platform_node;
int i, ret;
platform_node = of_parse_phandle(pdev->dev.of_node,
"mediatek,platform", 0);
if (!platform_node) {
dev_err(&pdev->dev, "Property 'platform' missing or invalid\n");
return -EINVAL;
}
for (i = 0; i < card->num_links; i++) {
if (mt8173_rt5650_rt5514_dais[i].platform_name)
continue;
mt8173_rt5650_rt5514_dais[i].platform_of_node = platform_node;
}
mt8173_rt5650_rt5514_codecs[0].of_node =
of_parse_phandle(pdev->dev.of_node, "mediatek,audio-codec", 0);
if (!mt8173_rt5650_rt5514_codecs[0].of_node) {
dev_err(&pdev->dev,
"Property 'audio-codec' missing or invalid\n");
return -EINVAL;
}
mt8173_rt5650_rt5514_codecs[1].of_node =
of_parse_phandle(pdev->dev.of_node, "mediatek,audio-codec", 1);
if (!mt8173_rt5650_rt5514_codecs[1].of_node) {
dev_err(&pdev->dev,
"Property 'audio-codec' missing or invalid\n");
return -EINVAL;
}
mt8173_rt5650_rt5514_codec_conf[0].of_node =
mt8173_rt5650_rt5514_codecs[1].of_node;
card->dev = &pdev->dev;
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret)
dev_err(&pdev->dev, "%s snd_soc_register_card fail %d\n",
__func__, ret);
return ret;
}
