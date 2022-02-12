static int storm_ops_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *soc_runtime = substream->private_data;
struct snd_soc_card *card = soc_runtime->card;
snd_pcm_format_t format = params_format(params);
unsigned int rate = params_rate(params);
unsigned int sysclk_freq;
int bitwidth, ret;
bitwidth = snd_pcm_format_width(format);
if (bitwidth < 0) {
dev_err(card->dev, "%s() invalid bit width given: %d\n",
__func__, bitwidth);
return bitwidth;
}
sysclk_freq = rate * bitwidth * 2 * STORM_SYSCLK_MULT;
ret = snd_soc_dai_set_sysclk(soc_runtime->cpu_dai, 0, sysclk_freq, 0);
if (ret) {
dev_err(card->dev, "%s() error setting sysclk to %u: %d\n",
__func__, sysclk_freq, ret);
return ret;
}
return 0;
}
static int storm_parse_of(struct snd_soc_card *card)
{
struct snd_soc_dai_link *dai_link = card->dai_link;
struct device_node *np = card->dev->of_node;
dai_link->cpu_of_node = of_parse_phandle(np, "cpu", 0);
if (!dai_link->cpu_of_node) {
dev_err(card->dev, "%s() error getting cpu phandle\n",
__func__);
return -EINVAL;
}
dai_link->platform_of_node = dai_link->cpu_of_node;
dai_link->codec_of_node = of_parse_phandle(np, "codec", 0);
if (!dai_link->codec_of_node) {
dev_err(card->dev, "%s() error getting codec phandle\n",
__func__);
return -EINVAL;
}
return 0;
}
static int storm_platform_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &storm_soc_card;
int ret;
if (card->dev) {
dev_err(&pdev->dev, "%s() error, existing soundcard\n",
__func__);
return -ENODEV;
}
card->dev = &pdev->dev;
platform_set_drvdata(pdev, card);
ret = snd_soc_of_parse_card_name(card, "qcom,model");
if (ret) {
dev_err(&pdev->dev, "%s() error parsing card name: %d\n",
__func__, ret);
return ret;
}
card->dai_link = &storm_dai_link;
card->num_links = 1;
ret = storm_parse_of(card);
if (ret) {
dev_err(&pdev->dev, "%s() error resolving dai links: %d\n",
__func__, ret);
return ret;
}
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret == -EPROBE_DEFER) {
card->dev = NULL;
return ret;
} else if (ret) {
dev_err(&pdev->dev, "%s() error registering soundcard: %d\n",
__func__, ret);
return ret;
}
return 0;
}
