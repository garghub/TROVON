static int odroidx2_late_probe(struct snd_soc_card *card)
{
struct snd_soc_dai *codec_dai = card->rtd[0].codec_dai;
struct snd_soc_dai *cpu_dai = card->rtd[0].cpu_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 0, MAX98090_MCLK,
SND_SOC_CLOCK_IN);
if (ret < 0 || of_find_property(odroidx2_dai[0].codec_of_node,
"clocks", NULL))
return ret;
return snd_soc_dai_set_sysclk(cpu_dai, SAMSUNG_I2S_CDCLK,
0, SND_SOC_CLOCK_OUT);
}
static int odroidx2_audio_probe(struct platform_device *pdev)
{
struct device_node *snd_node = pdev->dev.of_node;
struct snd_soc_card *card = &odroidx2;
struct device_node *i2s_node, *codec_node;
struct odroidx2_drv_data *dd;
const struct of_device_id *of_id;
int ret;
of_id = of_match_node(odroidx2_audio_of_match, snd_node);
dd = (struct odroidx2_drv_data *)of_id->data;
card->num_dapm_widgets = dd->num_dapm_widgets;
card->dapm_widgets = dd->dapm_widgets;
card->dev = &pdev->dev;
ret = snd_soc_of_parse_card_name(card, "samsung,model");
if (ret < 0)
return ret;
ret = snd_soc_of_parse_audio_routing(card, "samsung,audio-routing");
if (ret < 0)
return ret;
codec_node = of_parse_phandle(snd_node, "samsung,audio-codec", 0);
if (!codec_node) {
dev_err(&pdev->dev,
"Failed parsing samsung,i2s-codec property\n");
return -EINVAL;
}
i2s_node = of_parse_phandle(snd_node, "samsung,i2s-controller", 0);
if (!i2s_node) {
dev_err(&pdev->dev,
"Failed parsing samsung,i2s-controller property\n");
ret = -EINVAL;
goto err_put_codec_n;
}
odroidx2_dai[0].codec_of_node = codec_node;
odroidx2_dai[0].cpu_of_node = i2s_node;
odroidx2_dai[0].platform_of_node = i2s_node;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
goto err_put_i2s_n;
}
return 0;
err_put_i2s_n:
of_node_put(i2s_node);
err_put_codec_n:
of_node_put(codec_node);
return ret;
}
static int odroidx2_audio_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
of_node_put(odroidx2_dai[0].cpu_of_node);
of_node_put(odroidx2_dai[0].codec_of_node);
return 0;
}
