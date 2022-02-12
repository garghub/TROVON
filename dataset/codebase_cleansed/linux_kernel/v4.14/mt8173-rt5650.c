static int mt8173_rt5650_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
unsigned int mclk_clock;
int i, ret;
switch (mt8173_rt5650_priv.pll_from) {
case MT8173_RT5650_MCLK_EXTERNAL:
mclk_clock = MCLK_FOR_CODECS;
break;
case MT8173_RT5650_MCLK_INTERNAL:
mclk_clock = params_rate(params) * 256;
break;
default:
mclk_clock = MCLK_FOR_CODECS;
break;
}
for (i = 0; i < rtd->num_codecs; i++) {
struct snd_soc_dai *codec_dai = rtd->codec_dais[i];
ret = snd_soc_dai_set_pll(codec_dai, 0, 0, mclk_clock,
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
static int mt8173_rt5650_init(struct snd_soc_pcm_runtime *runtime)
{
struct snd_soc_card *card = runtime->card;
struct snd_soc_codec *codec = runtime->codec_dais[0]->codec;
const char *codec_capture_dai = runtime->codec_dais[1]->name;
int ret;
rt5645_sel_asrc_clk_src(codec,
RT5645_DA_STEREO_FILTER,
RT5645_CLK_SEL_I2S1_ASRC);
if (!strcmp(codec_capture_dai, "rt5645-aif1")) {
rt5645_sel_asrc_clk_src(codec,
RT5645_AD_STEREO_FILTER,
RT5645_CLK_SEL_I2S1_ASRC);
} else if (!strcmp(codec_capture_dai, "rt5645-aif2")) {
rt5645_sel_asrc_clk_src(codec,
RT5645_AD_STEREO_FILTER,
RT5645_CLK_SEL_I2S2_ASRC);
} else {
dev_warn(card->dev,
"Only one dai codec found in DTS, enabled rt5645 AD filter\n");
rt5645_sel_asrc_clk_src(codec,
RT5645_AD_STEREO_FILTER,
RT5645_CLK_SEL_I2S1_ASRC);
}
ret = snd_soc_card_jack_new(card, "Headset Jack",
SND_JACK_HEADPHONE | SND_JACK_MICROPHONE |
SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3,
&mt8173_rt5650_jack, NULL, 0);
if (ret) {
dev_err(card->dev, "Can't new Headset Jack %d\n", ret);
return ret;
}
return rt5645_set_jack_detect(codec,
&mt8173_rt5650_jack,
&mt8173_rt5650_jack,
&mt8173_rt5650_jack);
}
static int mt8173_rt5650_dev_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &mt8173_rt5650_card;
struct device_node *platform_node;
struct device_node *np;
const char *codec_capture_dai;
int i, ret;
platform_node = of_parse_phandle(pdev->dev.of_node,
"mediatek,platform", 0);
if (!platform_node) {
dev_err(&pdev->dev, "Property 'platform' missing or invalid\n");
return -EINVAL;
}
for (i = 0; i < card->num_links; i++) {
if (mt8173_rt5650_dais[i].platform_name)
continue;
mt8173_rt5650_dais[i].platform_of_node = platform_node;
}
mt8173_rt5650_codecs[0].of_node =
of_parse_phandle(pdev->dev.of_node, "mediatek,audio-codec", 0);
if (!mt8173_rt5650_codecs[0].of_node) {
dev_err(&pdev->dev,
"Property 'audio-codec' missing or invalid\n");
return -EINVAL;
}
mt8173_rt5650_codecs[1].of_node = mt8173_rt5650_codecs[0].of_node;
if (of_find_node_by_name(platform_node, "codec-capture")) {
np = of_get_child_by_name(pdev->dev.of_node, "codec-capture");
if (!np) {
dev_err(&pdev->dev,
"%s: Can't find codec-capture DT node\n",
__func__);
return -EINVAL;
}
ret = snd_soc_of_get_dai_name(np, &codec_capture_dai);
if (ret < 0) {
dev_err(&pdev->dev,
"%s codec_capture_dai name fail %d\n",
__func__, ret);
return ret;
}
mt8173_rt5650_codecs[1].dai_name = codec_capture_dai;
}
if (device_property_present(&pdev->dev, "mediatek,mclk")) {
ret = device_property_read_u32(&pdev->dev,
"mediatek,mclk",
&mt8173_rt5650_priv.pll_from);
if (ret) {
dev_err(&pdev->dev,
"%s snd_soc_register_card fail %d\n",
__func__, ret);
}
}
mt8173_rt5650_dais[DAI_LINK_HDMI_I2S].codec_of_node =
of_parse_phandle(pdev->dev.of_node, "mediatek,audio-codec", 1);
if (!mt8173_rt5650_dais[DAI_LINK_HDMI_I2S].codec_of_node) {
dev_err(&pdev->dev,
"Property 'audio-codec' missing or invalid\n");
return -EINVAL;
}
card->dev = &pdev->dev;
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret)
dev_err(&pdev->dev, "%s snd_soc_register_card fail %d\n",
__func__, ret);
return ret;
}
