static int omap_abe_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_card *card = codec->card;
struct omap_abe_twl6040_data *pdata = dev_get_platdata(card->dev);
int clk_id, freq;
int ret;
clk_id = twl6040_get_clk_id(rtd->codec);
if (clk_id == TWL6040_SYSCLK_SEL_HPPLL)
freq = pdata->mclk_freq;
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
static inline void twl6040_disconnect_pin(struct snd_soc_dapm_context *dapm,
int connected, char *pin)
{
if (!connected)
snd_soc_dapm_disable_pin(dapm, pin);
}
static int omap_abe_twl6040_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_card *card = codec->card;
struct snd_soc_dapm_context *dapm = &codec->dapm;
struct omap_abe_twl6040_data *pdata = dev_get_platdata(card->dev);
int hs_trim;
int ret = 0;
twl6040_disconnect_pin(dapm, pdata->has_hs, "Headset Stereophone");
twl6040_disconnect_pin(dapm, pdata->has_hf, "Ext Spk");
twl6040_disconnect_pin(dapm, pdata->has_ep, "Earphone Spk");
twl6040_disconnect_pin(dapm, pdata->has_aux, "Line Out");
twl6040_disconnect_pin(dapm, pdata->has_vibra, "Vinrator");
twl6040_disconnect_pin(dapm, pdata->has_hsmic, "Headset Mic");
twl6040_disconnect_pin(dapm, pdata->has_mainmic, "Main Handset Mic");
twl6040_disconnect_pin(dapm, pdata->has_submic, "Sub Handset Mic");
twl6040_disconnect_pin(dapm, pdata->has_afm, "Line In");
hs_trim = twl6040_get_trim_value(codec, TWL6040_TRIM_HSOTRIM);
omap_mcpdm_configure_dn_offsets(rtd, TWL6040_HSF_TRIM_LEFT(hs_trim),
TWL6040_HSF_TRIM_RIGHT(hs_trim));
if (pdata->jack_detection) {
ret = snd_soc_jack_new(codec, "Headset Jack",
SND_JACK_HEADSET, &hs_jack);
if (ret)
return ret;
ret = snd_soc_jack_add_pins(&hs_jack, ARRAY_SIZE(hs_jack_pins),
hs_jack_pins);
twl6040_hs_jack_detect(codec, &hs_jack, SND_JACK_HEADSET);
}
return ret;
}
static int omap_abe_dmic_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
ret = snd_soc_dapm_new_controls(dapm, dmic_dapm_widgets,
ARRAY_SIZE(dmic_dapm_widgets));
if (ret)
return ret;
return snd_soc_dapm_add_routes(dapm, dmic_audio_map,
ARRAY_SIZE(dmic_audio_map));
}
static __devinit int omap_abe_probe(struct platform_device *pdev)
{
struct omap_abe_twl6040_data *pdata = dev_get_platdata(&pdev->dev);
struct snd_soc_card *card = &omap_abe_card;
int ret;
card->dev = &pdev->dev;
if (!pdata) {
dev_err(&pdev->dev, "Missing pdata\n");
return -ENODEV;
}
if (pdata->card_name) {
card->name = pdata->card_name;
} else {
dev_err(&pdev->dev, "Card name is not provided\n");
return -ENODEV;
}
if (!pdata->mclk_freq) {
dev_err(&pdev->dev, "MCLK frequency missing\n");
return -ENODEV;
}
if (pdata->has_dmic) {
card->dai_link = twl6040_dmic_dai;
card->num_links = ARRAY_SIZE(twl6040_dmic_dai);
} else {
card->dai_link = twl6040_only_dai;
card->num_links = ARRAY_SIZE(twl6040_only_dai);
}
ret = snd_soc_register_card(card);
if (ret)
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
return ret;
}
static int __devexit omap_abe_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
