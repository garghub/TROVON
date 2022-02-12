static int sam9x5_wm8731_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct device *dev = rtd->dev;
int ret;
dev_dbg(dev, "ASoC: %s called\n", __func__);
ret = snd_soc_dai_set_sysclk(codec_dai, WM8731_SYSCLK_XTAL,
MCLK_RATE, SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(dev, "ASoC: Failed to set WM8731 SYSCLK: %d\n", ret);
return ret;
}
return 0;
}
static int sam9x5_wm8731_driver_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *codec_np, *cpu_np;
struct snd_soc_card *card;
struct snd_soc_dai_link *dai;
struct sam9x5_drvdata *priv;
int ret;
if (!np) {
dev_err(&pdev->dev, "No device node supplied\n");
return -EINVAL;
}
card = devm_kzalloc(&pdev->dev, sizeof(*card), GFP_KERNEL);
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
dai = devm_kzalloc(&pdev->dev, sizeof(*dai), GFP_KERNEL);
if (!dai || !card || !priv) {
ret = -ENOMEM;
goto out;
}
snd_soc_card_set_drvdata(card, priv);
card->dev = &pdev->dev;
card->owner = THIS_MODULE;
card->dai_link = dai;
card->num_links = 1;
card->dapm_widgets = sam9x5_dapm_widgets;
card->num_dapm_widgets = ARRAY_SIZE(sam9x5_dapm_widgets);
dai->name = "WM8731";
dai->stream_name = "WM8731 PCM";
dai->codec_dai_name = "wm8731-hifi";
dai->init = sam9x5_wm8731_init;
dai->dai_fmt = SND_SOC_DAIFMT_DSP_A | SND_SOC_DAIFMT_NB_NF
| SND_SOC_DAIFMT_CBM_CFM;
ret = snd_soc_of_parse_card_name(card, "atmel,model");
if (ret) {
dev_err(&pdev->dev, "atmel,model node missing\n");
goto out;
}
ret = snd_soc_of_parse_audio_routing(card, "atmel,audio-routing");
if (ret) {
dev_err(&pdev->dev, "atmel,audio-routing node missing\n");
goto out;
}
codec_np = of_parse_phandle(np, "atmel,audio-codec", 0);
if (!codec_np) {
dev_err(&pdev->dev, "atmel,audio-codec node missing\n");
ret = -EINVAL;
goto out;
}
dai->codec_of_node = codec_np;
cpu_np = of_parse_phandle(np, "atmel,ssc-controller", 0);
if (!cpu_np) {
dev_err(&pdev->dev, "atmel,ssc-controller node missing\n");
ret = -EINVAL;
goto out;
}
dai->cpu_of_node = cpu_np;
dai->platform_of_node = cpu_np;
priv->ssc_id = of_alias_get_id(cpu_np, "ssc");
ret = atmel_ssc_set_audio(priv->ssc_id);
if (ret != 0) {
dev_err(&pdev->dev,
"ASoC: Failed to set SSC %d for audio: %d\n",
ret, priv->ssc_id);
goto out;
}
of_node_put(codec_np);
of_node_put(cpu_np);
platform_set_drvdata(pdev, card);
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev,
"ASoC: Platform device allocation failed\n");
goto out_put_audio;
}
dev_dbg(&pdev->dev, "ASoC: %s ok\n", __func__);
return ret;
out_put_audio:
atmel_ssc_put_audio(priv->ssc_id);
out:
return ret;
}
static int sam9x5_wm8731_driver_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct sam9x5_drvdata *priv = card->drvdata;
snd_soc_unregister_card(card);
atmel_ssc_put_audio(priv->ssc_id);
return 0;
}
