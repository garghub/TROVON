static int snow_late_probe(struct snd_soc_card *card)
{
struct snd_soc_dai *codec_dai = card->rtd[0].codec_dai;
struct snd_soc_dai *cpu_dai = card->rtd[0].cpu_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 0,
FIN_PLL_RATE, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, SAMSUNG_I2S_RCLKSRC_0,
0, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
return 0;
}
static int snow_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &snow_snd;
struct device_node *i2s_node, *codec_node;
int i, ret;
i2s_node = of_parse_phandle(pdev->dev.of_node,
"samsung,i2s-controller", 0);
if (!i2s_node) {
dev_err(&pdev->dev,
"Property 'i2s-controller' missing or invalid\n");
return -EINVAL;
}
codec_node = of_parse_phandle(pdev->dev.of_node,
"samsung,audio-codec", 0);
if (!codec_node) {
dev_err(&pdev->dev,
"Property 'audio-codec' missing or invalid\n");
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(snow_dai); i++) {
snow_dai[i].codec_of_node = codec_node;
snow_dai[i].cpu_of_node = i2s_node;
snow_dai[i].platform_of_node = i2s_node;
}
card->dev = &pdev->dev;
snd_soc_of_parse_card_name(card, "samsung,model");
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
return ret;
}
return ret;
}
