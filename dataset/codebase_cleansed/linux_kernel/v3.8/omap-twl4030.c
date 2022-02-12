static int omap_twl4030_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_card *card = codec->card;
unsigned int fmt;
int ret;
switch (params_channels(params)) {
case 2:
fmt = SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM;
break;
case 4:
fmt = SND_SOC_DAIFMT_DSP_A |
SND_SOC_DAIFMT_IB_NF |
SND_SOC_DAIFMT_CBM_CFM;
break;
default:
return -EINVAL;
}
ret = snd_soc_dai_set_fmt(codec_dai, fmt);
if (ret < 0) {
dev_err(card->dev, "can't set codec DAI configuration\n");
return ret;
}
ret = snd_soc_dai_set_fmt(cpu_dai, fmt);
if (ret < 0) {
dev_err(card->dev, "can't set cpu DAI configuration\n");
return ret;
}
return 0;
}
static int omap_twl4030_probe(struct platform_device *pdev)
{
struct omap_tw4030_pdata *pdata = dev_get_platdata(&pdev->dev);
struct device_node *node = pdev->dev.of_node;
struct snd_soc_card *card = &omap_twl4030_card;
int ret = 0;
card->dev = &pdev->dev;
if (node) {
struct device_node *dai_node;
if (snd_soc_of_parse_card_name(card, "ti,model")) {
dev_err(&pdev->dev, "Card name is not provided\n");
return -ENODEV;
}
dai_node = of_parse_phandle(node, "ti,mcbsp", 0);
if (!dai_node) {
dev_err(&pdev->dev, "McBSP node is not provided\n");
return -EINVAL;
}
omap_twl4030_dai_links[0].cpu_dai_name = NULL;
omap_twl4030_dai_links[0].cpu_of_node = dai_node;
} else if (pdata) {
if (pdata->card_name) {
card->name = pdata->card_name;
} else {
dev_err(&pdev->dev, "Card name is not provided\n");
return -ENODEV;
}
} else {
dev_err(&pdev->dev, "Missing pdata\n");
return -ENODEV;
}
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
return ret;
}
return 0;
}
static int omap_twl4030_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
