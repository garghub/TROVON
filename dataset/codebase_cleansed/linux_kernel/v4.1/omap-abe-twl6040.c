static int omap_abe_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_card *card = rtd->card;
struct abe_twl6040 *priv = snd_soc_card_get_drvdata(card);
int clk_id, freq;
int ret;
clk_id = twl6040_get_clk_id(rtd->codec);
if (clk_id == TWL6040_SYSCLK_SEL_HPPLL)
freq = priv->mclk_freq;
else if (clk_id == TWL6040_SYSCLK_SEL_LPPLL)
freq = 32768;
else
return -EINVAL;
ret = snd_soc_dai_set_sysclk(codec_dai, clk_id, freq,
SND_SOC_CLOCK_IN);
if (ret) {
printk(KERN_ERR "can't set codec system clock\n");
return ret;
}
return ret;
}
static int omap_abe_dmic_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret = 0;
ret = snd_soc_dai_set_sysclk(cpu_dai, OMAP_DMIC_SYSCLK_PAD_CLKS,
19200000, SND_SOC_CLOCK_IN);
if (ret < 0) {
printk(KERN_ERR "can't set DMIC cpu system clock\n");
return ret;
}
ret = snd_soc_dai_set_sysclk(cpu_dai, OMAP_DMIC_ABE_DMIC_CLK, 2400000,
SND_SOC_CLOCK_OUT);
if (ret < 0) {
printk(KERN_ERR "can't set DMIC output clock\n");
return ret;
}
return 0;
}
static int omap_abe_twl6040_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_card *card = rtd->card;
struct abe_twl6040 *priv = snd_soc_card_get_drvdata(card);
int hs_trim;
int ret = 0;
hs_trim = twl6040_get_trim_value(codec, TWL6040_TRIM_HSOTRIM);
omap_mcpdm_configure_dn_offsets(rtd, TWL6040_HSF_TRIM_LEFT(hs_trim),
TWL6040_HSF_TRIM_RIGHT(hs_trim));
if (priv->jack_detection) {
ret = snd_soc_card_jack_new(rtd->card, "Headset Jack",
SND_JACK_HEADSET, &hs_jack,
hs_jack_pins,
ARRAY_SIZE(hs_jack_pins));
if (ret)
return ret;
twl6040_hs_jack_detect(codec, &hs_jack, SND_JACK_HEADSET);
}
return 0;
}
static int omap_abe_dmic_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dapm_context *dapm = &rtd->card->dapm;
return snd_soc_dapm_add_routes(dapm, dmic_audio_map,
ARRAY_SIZE(dmic_audio_map));
}
static int omap_abe_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct snd_soc_card *card = &omap_abe_card;
struct device_node *dai_node;
struct abe_twl6040 *priv;
int num_links = 0;
int ret = 0;
if (!node) {
dev_err(&pdev->dev, "of node is missing.\n");
return -ENODEV;
}
card->dev = &pdev->dev;
priv = devm_kzalloc(&pdev->dev, sizeof(struct abe_twl6040), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
priv->dmic_codec_dev = ERR_PTR(-EINVAL);
if (snd_soc_of_parse_card_name(card, "ti,model")) {
dev_err(&pdev->dev, "Card name is not provided\n");
return -ENODEV;
}
ret = snd_soc_of_parse_audio_routing(card, "ti,audio-routing");
if (ret) {
dev_err(&pdev->dev, "Error while parsing DAPM routing\n");
return ret;
}
dai_node = of_parse_phandle(node, "ti,mcpdm", 0);
if (!dai_node) {
dev_err(&pdev->dev, "McPDM node is not provided\n");
return -EINVAL;
}
abe_twl6040_dai_links[0].cpu_of_node = dai_node;
abe_twl6040_dai_links[0].platform_of_node = dai_node;
dai_node = of_parse_phandle(node, "ti,dmic", 0);
if (dai_node) {
num_links = 2;
abe_twl6040_dai_links[1].cpu_of_node = dai_node;
abe_twl6040_dai_links[1].platform_of_node = dai_node;
priv->dmic_codec_dev = platform_device_register_simple(
"dmic-codec", -1, NULL, 0);
if (IS_ERR(priv->dmic_codec_dev)) {
dev_err(&pdev->dev, "Can't instantiate dmic-codec\n");
return PTR_ERR(priv->dmic_codec_dev);
}
} else {
num_links = 1;
}
priv->jack_detection = of_property_read_bool(node, "ti,jack-detection");
of_property_read_u32(node, "ti,mclk-freq", &priv->mclk_freq);
if (!priv->mclk_freq) {
dev_err(&pdev->dev, "MCLK frequency not provided\n");
ret = -EINVAL;
goto err_unregister;
}
card->fully_routed = 1;
if (!priv->mclk_freq) {
dev_err(&pdev->dev, "MCLK frequency missing\n");
ret = -ENODEV;
goto err_unregister;
}
card->dai_link = abe_twl6040_dai_links;
card->num_links = num_links;
snd_soc_card_set_drvdata(card, priv);
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
goto err_unregister;
}
return 0;
err_unregister:
if (!IS_ERR(priv->dmic_codec_dev))
platform_device_unregister(priv->dmic_codec_dev);
return ret;
}
static int omap_abe_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct abe_twl6040 *priv = snd_soc_card_get_drvdata(card);
snd_soc_unregister_card(card);
if (!IS_ERR(priv->dmic_codec_dev))
platform_device_unregister(priv->dmic_codec_dev);
return 0;
}
