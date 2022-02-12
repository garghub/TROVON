static int mt2701_wm8960_be_ops_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int mclk_rate;
unsigned int rate = params_rate(params);
unsigned int div_mclk_over_bck = rate > 192000 ? 2 : 4;
unsigned int div_bck_over_lrck = 64;
mclk_rate = rate * div_bck_over_lrck * div_mclk_over_bck;
snd_soc_dai_set_sysclk(cpu_dai, 0, mclk_rate, SND_SOC_CLOCK_OUT);
snd_soc_dai_set_sysclk(codec_dai, 0, mclk_rate, SND_SOC_CLOCK_IN);
return 0;
}
static int mt2701_wm8960_machine_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &mt2701_wm8960_card;
struct device_node *platform_node, *codec_node;
int ret, i;
platform_node = of_parse_phandle(pdev->dev.of_node,
"mediatek,platform", 0);
if (!platform_node) {
dev_err(&pdev->dev, "Property 'platform' missing or invalid\n");
return -EINVAL;
}
for (i = 0; i < card->num_links; i++) {
if (mt2701_wm8960_dai_links[i].platform_name)
continue;
mt2701_wm8960_dai_links[i].platform_of_node = platform_node;
}
card->dev = &pdev->dev;
codec_node = of_parse_phandle(pdev->dev.of_node,
"mediatek,audio-codec", 0);
if (!codec_node) {
dev_err(&pdev->dev,
"Property 'audio-codec' missing or invalid\n");
return -EINVAL;
}
for (i = 0; i < card->num_links; i++) {
if (mt2701_wm8960_dai_links[i].codec_name)
continue;
mt2701_wm8960_dai_links[i].codec_of_node = codec_node;
}
ret = snd_soc_of_parse_audio_routing(card, "audio-routing");
if (ret) {
dev_err(&pdev->dev, "failed to parse audio-routing: %d\n", ret);
return ret;
}
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret)
dev_err(&pdev->dev, "%s snd_soc_register_card fail %d\n",
__func__, ret);
return ret;
}
