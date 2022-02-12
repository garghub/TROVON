static int wm8997_sysclk_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
struct regmap *regmap = arizona->regmap;
const struct reg_default *patch = NULL;
int i, patch_size;
switch (arizona->rev) {
case 0:
patch = wm8997_sysclk_reva_patch;
patch_size = ARRAY_SIZE(wm8997_sysclk_reva_patch);
break;
default:
break;
}
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (patch)
for (i = 0; i < patch_size; i++)
regmap_write_async(regmap, patch[i].reg,
patch[i].def);
break;
case SND_SOC_DAPM_PRE_PMD:
break;
case SND_SOC_DAPM_PRE_PMU:
case SND_SOC_DAPM_POST_PMD:
return arizona_clk_ev(w, kcontrol, event);
default:
return 0;
}
return arizona_dvfs_sysclk_ev(w, kcontrol, event);
}
static int wm8997_set_fll(struct snd_soc_codec *codec, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct wm8997_priv *wm8997 = snd_soc_codec_get_drvdata(codec);
switch (fll_id) {
case WM8997_FLL1:
return arizona_set_fll(&wm8997->fll[0], source, Fref, Fout);
case WM8997_FLL2:
return arizona_set_fll(&wm8997->fll[1], source, Fref, Fout);
case WM8997_FLL1_REFCLK:
return arizona_set_fll_refclk(&wm8997->fll[0], source, Fref,
Fout);
case WM8997_FLL2_REFCLK:
return arizona_set_fll_refclk(&wm8997->fll[1], source, Fref,
Fout);
default:
return -EINVAL;
}
}
static int wm8997_codec_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct snd_soc_component *component = snd_soc_dapm_to_component(dapm);
struct wm8997_priv *priv = snd_soc_codec_get_drvdata(codec);
int ret;
ret = arizona_init_spk(codec);
if (ret < 0)
return ret;
arizona_init_notifiers(codec);
snd_soc_component_disable_pin(component, "HAPTICS");
priv->core.arizona->dapm = dapm;
return 0;
}
static int wm8997_codec_remove(struct snd_soc_codec *codec)
{
struct wm8997_priv *priv = snd_soc_codec_get_drvdata(codec);
priv->core.arizona->dapm = NULL;
return 0;
}
static struct regmap *wm8997_get_regmap(struct device *dev)
{
struct wm8997_priv *priv = dev_get_drvdata(dev);
return priv->core.arizona->regmap;
}
static int wm8997_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
struct wm8997_priv *wm8997;
int i, ret;
wm8997 = devm_kzalloc(&pdev->dev, sizeof(struct wm8997_priv),
GFP_KERNEL);
if (wm8997 == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, wm8997);
wm8997->core.arizona = arizona;
wm8997->core.num_inputs = 4;
arizona_init_dvfs(&wm8997->core);
for (i = 0; i < ARRAY_SIZE(wm8997->fll); i++)
wm8997->fll[i].vco_mult = 1;
arizona_init_fll(arizona, 1, ARIZONA_FLL1_CONTROL_1 - 1,
ARIZONA_IRQ_FLL1_LOCK, ARIZONA_IRQ_FLL1_CLOCK_OK,
&wm8997->fll[0]);
arizona_init_fll(arizona, 2, ARIZONA_FLL2_CONTROL_1 - 1,
ARIZONA_IRQ_FLL2_LOCK, ARIZONA_IRQ_FLL2_CLOCK_OK,
&wm8997->fll[1]);
regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_2,
ARIZONA_SAMPLE_RATE_2_MASK, 0x11);
regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_3,
ARIZONA_SAMPLE_RATE_3_MASK, 0x12);
for (i = 0; i < ARRAY_SIZE(wm8997_dai); i++)
arizona_init_dai(&wm8997->core, i);
for (i = 0; i < ARRAY_SIZE(wm8997_digital_vu); i++)
regmap_update_bits(arizona->regmap, wm8997_digital_vu[i],
WM8997_DIG_VU, WM8997_DIG_VU);
pm_runtime_enable(&pdev->dev);
pm_runtime_idle(&pdev->dev);
ret = arizona_init_spk_irqs(arizona);
if (ret < 0)
return ret;
ret = snd_soc_register_codec(&pdev->dev, &soc_codec_dev_wm8997,
wm8997_dai, ARRAY_SIZE(wm8997_dai));
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register codec: %d\n", ret);
goto err_spk_irqs;
}
err_spk_irqs:
arizona_free_spk_irqs(arizona);
return ret;
}
static int wm8997_remove(struct platform_device *pdev)
{
struct wm8997_priv *wm8997 = platform_get_drvdata(pdev);
struct arizona *arizona = wm8997->core.arizona;
snd_soc_unregister_codec(&pdev->dev);
pm_runtime_disable(&pdev->dev);
arizona_free_spk_irqs(arizona);
return 0;
}
