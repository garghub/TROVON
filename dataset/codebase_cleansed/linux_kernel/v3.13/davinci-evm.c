static int evm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_card *soc_card = codec->card;
int ret = 0;
unsigned sysclk = ((struct snd_soc_card_drvdata_davinci *)
snd_soc_card_get_drvdata(soc_card))->sysclk;
ret = snd_soc_dai_set_fmt(codec_dai, AUDIO_FORMAT);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai, AUDIO_FORMAT);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 0, sysclk, SND_SOC_CLOCK_OUT);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, 0, sysclk, SND_SOC_CLOCK_OUT);
if (ret < 0)
return ret;
return 0;
}
static int evm_spdif_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
return snd_soc_dai_set_fmt(cpu_dai, AUDIO_FORMAT);
}
static int evm_aic3x_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
struct device_node *np = codec->card->dev->of_node;
int ret;
snd_soc_dapm_new_controls(dapm, aic3x_dapm_widgets,
ARRAY_SIZE(aic3x_dapm_widgets));
if (np) {
ret = snd_soc_of_parse_audio_routing(codec->card,
"ti,audio-routing");
if (ret)
return ret;
} else {
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
}
snd_soc_dapm_disable_pin(dapm, "MONO_LOUT");
snd_soc_dapm_disable_pin(dapm, "HPLCOM");
snd_soc_dapm_disable_pin(dapm, "HPRCOM");
snd_soc_dapm_enable_pin(dapm, "Headphone Jack");
snd_soc_dapm_enable_pin(dapm, "Line Out");
snd_soc_dapm_enable_pin(dapm, "Mic Jack");
snd_soc_dapm_enable_pin(dapm, "Line In");
return 0;
}
static int davinci_evm_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *match =
of_match_device(of_match_ptr(davinci_evm_dt_ids), &pdev->dev);
struct snd_soc_dai_link *dai = (struct snd_soc_dai_link *) match->data;
struct snd_soc_card_drvdata_davinci *drvdata = NULL;
int ret = 0;
evm_soc_card.dai_link = dai;
dai->codec_of_node = of_parse_phandle(np, "ti,audio-codec", 0);
if (!dai->codec_of_node)
return -EINVAL;
dai->cpu_of_node = of_parse_phandle(np, "ti,mcasp-controller", 0);
if (!dai->cpu_of_node)
return -EINVAL;
dai->platform_of_node = dai->cpu_of_node;
evm_soc_card.dev = &pdev->dev;
ret = snd_soc_of_parse_card_name(&evm_soc_card, "ti,model");
if (ret)
return ret;
drvdata = devm_kzalloc(&pdev->dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
ret = of_property_read_u32(np, "ti,codec-clock-rate", &drvdata->sysclk);
if (ret < 0)
return -EINVAL;
snd_soc_card_set_drvdata(&evm_soc_card, drvdata);
ret = devm_snd_soc_register_card(&pdev->dev, &evm_soc_card);
if (ret)
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
return ret;
}
static int davinci_evm_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
static int __init evm_init(void)
{
struct snd_soc_card *evm_snd_dev_data;
int index;
int ret;
#if defined(CONFIG_OF)
if (of_have_populated_dt())
return platform_driver_register(&davinci_evm_driver);
#endif
if (machine_is_davinci_evm()) {
evm_snd_dev_data = &dm6446_snd_soc_card_evm;
index = 0;
} else if (machine_is_davinci_dm355_evm()) {
evm_snd_dev_data = &dm355_snd_soc_card_evm;
index = 1;
} else if (machine_is_davinci_dm365_evm()) {
evm_snd_dev_data = &dm365_snd_soc_card_evm;
index = 0;
} else if (machine_is_davinci_dm6467_evm()) {
evm_snd_dev_data = &dm6467_snd_soc_card_evm;
index = 0;
} else if (machine_is_davinci_da830_evm()) {
evm_snd_dev_data = &da830_snd_soc_card;
index = 1;
} else if (machine_is_davinci_da850_evm()) {
evm_snd_dev_data = &da850_snd_soc_card;
index = 0;
} else
return -EINVAL;
evm_snd_device = platform_device_alloc("soc-audio", index);
if (!evm_snd_device)
return -ENOMEM;
platform_set_drvdata(evm_snd_device, evm_snd_dev_data);
ret = platform_device_add(evm_snd_device);
if (ret)
platform_device_put(evm_snd_device);
return ret;
}
static void __exit evm_exit(void)
{
#if defined(CONFIG_OF)
if (of_have_populated_dt()) {
platform_driver_unregister(&davinci_evm_driver);
return;
}
#endif
platform_device_unregister(evm_snd_device);
}
