static int cs47l24_adsp_power_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
unsigned int v;
int ret;
ret = regmap_read(arizona->regmap, ARIZONA_SYSTEM_CLOCK_1, &v);
if (ret != 0) {
dev_err(codec->dev, "Failed to read SYSCLK state: %d\n", ret);
return ret;
}
v = (v & ARIZONA_SYSCLK_FREQ_MASK) >> ARIZONA_SYSCLK_FREQ_SHIFT;
return wm_adsp2_early_event(w, kcontrol, event, v);
}
static int cs47l24_set_fll(struct snd_soc_codec *codec, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct cs47l24_priv *cs47l24 = snd_soc_codec_get_drvdata(codec);
switch (fll_id) {
case CS47L24_FLL1:
return arizona_set_fll(&cs47l24->fll[0], source, Fref, Fout);
case CS47L24_FLL2:
return arizona_set_fll(&cs47l24->fll[1], source, Fref, Fout);
case CS47L24_FLL1_REFCLK:
return arizona_set_fll_refclk(&cs47l24->fll[0], source, Fref,
Fout);
case CS47L24_FLL2_REFCLK:
return arizona_set_fll_refclk(&cs47l24->fll[1], source, Fref,
Fout);
default:
return -EINVAL;
}
}
static int cs47l24_open(struct snd_compr_stream *stream)
{
struct snd_soc_pcm_runtime *rtd = stream->private_data;
struct cs47l24_priv *priv = snd_soc_codec_get_drvdata(rtd->codec);
struct arizona *arizona = priv->core.arizona;
int n_adsp;
if (strcmp(rtd->codec_dai->name, "cs47l24-dsp-voicectrl") == 0) {
n_adsp = 2;
} else if (strcmp(rtd->codec_dai->name, "cs47l24-dsp-trace") == 0) {
n_adsp = 1;
} else {
dev_err(arizona->dev,
"No suitable compressed stream for DAI '%s'\n",
rtd->codec_dai->name);
return -EINVAL;
}
return wm_adsp_compr_open(&priv->core.adsp[n_adsp], stream);
}
static irqreturn_t cs47l24_adsp2_irq(int irq, void *data)
{
struct cs47l24_priv *priv = data;
struct arizona *arizona = priv->core.arizona;
struct arizona_voice_trigger_info info;
int serviced = 0;
int i, ret;
for (i = 1; i <= 2; ++i) {
ret = wm_adsp_compr_handle_irq(&priv->core.adsp[i]);
if (ret != -ENODEV)
serviced++;
if (ret == WM_ADSP_COMPR_VOICE_TRIGGER) {
info.core = i;
arizona_call_notifiers(arizona,
ARIZONA_NOTIFY_VOICE_TRIGGER,
&info);
}
}
if (!serviced) {
dev_err(arizona->dev, "Spurious compressed data IRQ\n");
return IRQ_NONE;
}
return IRQ_HANDLED;
}
static int cs47l24_codec_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct cs47l24_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->core.arizona;
int ret;
priv->core.arizona->dapm = dapm;
arizona_init_spk(codec);
arizona_init_gpio(codec);
arizona_init_mono(codec);
arizona_init_notifiers(codec);
ret = arizona_request_irq(arizona, ARIZONA_IRQ_DSP_IRQ1,
"ADSP2 Compressed IRQ", cs47l24_adsp2_irq,
priv);
if (ret != 0) {
dev_err(codec->dev, "Failed to request DSP IRQ: %d\n", ret);
return ret;
}
ret = wm_adsp2_codec_probe(&priv->core.adsp[1], codec);
if (ret)
goto err_adsp2_codec_probe;
ret = wm_adsp2_codec_probe(&priv->core.adsp[2], codec);
if (ret)
goto err_adsp2_codec_probe;
ret = snd_soc_add_codec_controls(codec,
&arizona_adsp2_rate_controls[1], 2);
if (ret)
goto err_adsp2_codec_probe;
snd_soc_dapm_disable_pin(dapm, "HAPTICS");
return 0;
err_adsp2_codec_probe:
wm_adsp2_codec_remove(&priv->core.adsp[1], codec);
wm_adsp2_codec_remove(&priv->core.adsp[2], codec);
return ret;
}
static int cs47l24_codec_remove(struct snd_soc_codec *codec)
{
struct cs47l24_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->core.arizona;
wm_adsp2_codec_remove(&priv->core.adsp[1], codec);
wm_adsp2_codec_remove(&priv->core.adsp[2], codec);
priv->core.arizona->dapm = NULL;
arizona_free_irq(arizona, ARIZONA_IRQ_DSP_IRQ1, priv);
arizona_free_spk(codec);
return 0;
}
static struct regmap *cs47l24_get_regmap(struct device *dev)
{
struct cs47l24_priv *priv = dev_get_drvdata(dev);
return priv->core.arizona->regmap;
}
static int cs47l24_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
struct cs47l24_priv *cs47l24;
int i, ret;
BUILD_BUG_ON(ARRAY_SIZE(cs47l24_dai) > ARIZONA_MAX_DAI);
cs47l24 = devm_kzalloc(&pdev->dev, sizeof(struct cs47l24_priv),
GFP_KERNEL);
if (!cs47l24)
return -ENOMEM;
platform_set_drvdata(pdev, cs47l24);
cs47l24->core.arizona = arizona;
cs47l24->core.num_inputs = 4;
for (i = 1; i <= 2; i++) {
cs47l24->core.adsp[i].part = "cs47l24";
cs47l24->core.adsp[i].num = i + 1;
cs47l24->core.adsp[i].type = WMFW_ADSP2;
cs47l24->core.adsp[i].dev = arizona->dev;
cs47l24->core.adsp[i].regmap = arizona->regmap;
cs47l24->core.adsp[i].base = ARIZONA_DSP1_CONTROL_1 +
(0x100 * i);
cs47l24->core.adsp[i].mem = cs47l24_dsp_regions[i - 1];
cs47l24->core.adsp[i].num_mems =
ARRAY_SIZE(cs47l24_dsp2_regions);
ret = wm_adsp2_init(&cs47l24->core.adsp[i]);
if (ret != 0)
return ret;
}
for (i = 0; i < ARRAY_SIZE(cs47l24->fll); i++)
cs47l24->fll[i].vco_mult = 3;
arizona_init_fll(arizona, 1, ARIZONA_FLL1_CONTROL_1 - 1,
ARIZONA_IRQ_FLL1_LOCK, ARIZONA_IRQ_FLL1_CLOCK_OK,
&cs47l24->fll[0]);
arizona_init_fll(arizona, 2, ARIZONA_FLL2_CONTROL_1 - 1,
ARIZONA_IRQ_FLL2_LOCK, ARIZONA_IRQ_FLL2_CLOCK_OK,
&cs47l24->fll[1]);
regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_2,
ARIZONA_SAMPLE_RATE_2_MASK, 0x11);
regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_3,
ARIZONA_SAMPLE_RATE_3_MASK, 0x12);
for (i = 0; i < ARRAY_SIZE(cs47l24_dai); i++)
arizona_init_dai(&cs47l24->core, i);
for (i = 0; i < ARRAY_SIZE(cs47l24_digital_vu); i++)
regmap_update_bits(arizona->regmap, cs47l24_digital_vu[i],
CS47L24_DIG_VU, CS47L24_DIG_VU);
pm_runtime_enable(&pdev->dev);
pm_runtime_idle(&pdev->dev);
ret = snd_soc_register_platform(&pdev->dev, &cs47l24_compr_platform);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register platform: %d\n", ret);
return ret;
}
ret = snd_soc_register_codec(&pdev->dev, &soc_codec_dev_cs47l24,
cs47l24_dai, ARRAY_SIZE(cs47l24_dai));
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register codec: %d\n", ret);
snd_soc_unregister_platform(&pdev->dev);
}
return ret;
}
static int cs47l24_remove(struct platform_device *pdev)
{
struct cs47l24_priv *cs47l24 = platform_get_drvdata(pdev);
snd_soc_unregister_platform(&pdev->dev);
snd_soc_unregister_codec(&pdev->dev);
pm_runtime_disable(&pdev->dev);
wm_adsp2_remove(&cs47l24->core.adsp[1]);
wm_adsp2_remove(&cs47l24->core.adsp[2]);
return 0;
}
