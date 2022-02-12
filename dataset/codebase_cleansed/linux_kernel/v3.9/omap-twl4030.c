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
static inline void twl4030_disconnect_pin(struct snd_soc_dapm_context *dapm,
int connected, char *pin)
{
if (!connected)
snd_soc_dapm_disable_pin(dapm, pin);
}
static int omap_twl4030_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_card *card = codec->card;
struct snd_soc_dapm_context *dapm = &codec->dapm;
struct omap_tw4030_pdata *pdata = dev_get_platdata(card->dev);
struct omap_twl4030 *priv = snd_soc_card_get_drvdata(card);
int ret = 0;
if (priv->jack_detect > 0) {
hs_jack_gpios[0].gpio = priv->jack_detect;
ret = snd_soc_jack_new(codec, "Headset Jack", SND_JACK_HEADSET,
&priv->hs_jack);
if (ret)
return ret;
ret = snd_soc_jack_add_pins(&priv->hs_jack,
ARRAY_SIZE(hs_jack_pins),
hs_jack_pins);
if (ret)
return ret;
ret = snd_soc_jack_add_gpios(&priv->hs_jack,
ARRAY_SIZE(hs_jack_gpios),
hs_jack_gpios);
if (ret)
return ret;
}
if (!pdata || !pdata->custom_routing)
return ret;
twl4030_disconnect_pin(dapm, pdata->has_ear, "Earpiece Spk");
twl4030_disconnect_pin(dapm, pdata->has_hf, "Handsfree Spk");
twl4030_disconnect_pin(dapm, pdata->has_hs, "Headset Stereophone");
twl4030_disconnect_pin(dapm, pdata->has_predriv, "Ext Spk");
twl4030_disconnect_pin(dapm, pdata->has_carkit, "Carkit Spk");
twl4030_disconnect_pin(dapm, pdata->has_mainmic, "Main Mic");
twl4030_disconnect_pin(dapm, pdata->has_submic, "Sub Mic");
twl4030_disconnect_pin(dapm, pdata->has_hsmic, "Headset Mic");
twl4030_disconnect_pin(dapm, pdata->has_carkitmic, "Carkit Mic");
twl4030_disconnect_pin(dapm, pdata->has_digimic0, "Digital0 Mic");
twl4030_disconnect_pin(dapm, pdata->has_digimic1, "Digital1 Mic");
twl4030_disconnect_pin(dapm, pdata->has_linein, "Line In");
return ret;
}
static int omap_twl4030_probe(struct platform_device *pdev)
{
struct omap_tw4030_pdata *pdata = dev_get_platdata(&pdev->dev);
struct device_node *node = pdev->dev.of_node;
struct snd_soc_card *card = &omap_twl4030_card;
struct omap_twl4030 *priv;
int ret = 0;
card->dev = &pdev->dev;
priv = devm_kzalloc(&pdev->dev, sizeof(struct omap_twl4030), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
if (node) {
struct device_node *dai_node;
struct property *prop;
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
dai_node = of_parse_phandle(node, "ti,mcbsp-voice", 0);
if (!dai_node) {
card->num_links = 1;
} else {
omap_twl4030_dai_links[1].cpu_dai_name = NULL;
omap_twl4030_dai_links[1].cpu_of_node = dai_node;
}
priv->jack_detect = of_get_named_gpio(node,
"ti,jack-det-gpio", 0);
prop = of_find_property(node, "ti,audio-routing", NULL);
if (prop) {
ret = snd_soc_of_parse_audio_routing(card,
"ti,audio-routing");
if (ret)
return ret;
card->fully_routed = 1;
}
} else if (pdata) {
if (pdata->card_name) {
card->name = pdata->card_name;
} else {
dev_err(&pdev->dev, "Card name is not provided\n");
return -ENODEV;
}
if (!pdata->voice_connected)
card->num_links = 1;
priv->jack_detect = pdata->jack_detect;
} else {
dev_err(&pdev->dev, "Missing pdata\n");
return -ENODEV;
}
snd_soc_card_set_drvdata(card, priv);
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
struct omap_twl4030 *priv = snd_soc_card_get_drvdata(card);
if (priv->jack_detect > 0)
snd_soc_jack_free_gpios(&priv->hs_jack,
ARRAY_SIZE(hs_jack_gpios),
hs_jack_gpios);
snd_soc_unregister_card(card);
return 0;
}
