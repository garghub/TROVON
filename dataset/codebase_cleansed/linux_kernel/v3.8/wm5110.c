static int wm5110_set_fll(struct snd_soc_codec *codec, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct wm5110_priv *wm5110 = snd_soc_codec_get_drvdata(codec);
switch (fll_id) {
case WM5110_FLL1:
return arizona_set_fll(&wm5110->fll[0], source, Fref, Fout);
case WM5110_FLL2:
return arizona_set_fll(&wm5110->fll[1], source, Fref, Fout);
default:
return -EINVAL;
}
}
static int wm5110_codec_probe(struct snd_soc_codec *codec)
{
struct wm5110_priv *priv = snd_soc_codec_get_drvdata(codec);
int ret;
codec->control_data = priv->core.arizona->regmap;
priv->core.arizona->dapm = &codec->dapm;
ret = snd_soc_codec_set_cache_io(codec, 32, 16, SND_SOC_REGMAP);
if (ret != 0)
return ret;
snd_soc_dapm_disable_pin(&codec->dapm, "HAPTICS");
priv->core.arizona->dapm = &codec->dapm;
return 0;
}
static int wm5110_codec_remove(struct snd_soc_codec *codec)
{
struct wm5110_priv *priv = snd_soc_codec_get_drvdata(codec);
priv->core.arizona->dapm = NULL;
return 0;
}
static int wm5110_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
struct wm5110_priv *wm5110;
int i;
wm5110 = devm_kzalloc(&pdev->dev, sizeof(struct wm5110_priv),
GFP_KERNEL);
if (wm5110 == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, wm5110);
wm5110->core.arizona = arizona;
for (i = 0; i < ARRAY_SIZE(wm5110->fll); i++)
wm5110->fll[i].vco_mult = 3;
arizona_init_fll(arizona, 1, ARIZONA_FLL1_CONTROL_1 - 1,
ARIZONA_IRQ_FLL1_LOCK, ARIZONA_IRQ_FLL1_CLOCK_OK,
&wm5110->fll[0]);
arizona_init_fll(arizona, 2, ARIZONA_FLL2_CONTROL_1 - 1,
ARIZONA_IRQ_FLL2_LOCK, ARIZONA_IRQ_FLL2_CLOCK_OK,
&wm5110->fll[1]);
for (i = 0; i < ARRAY_SIZE(wm5110_dai); i++)
arizona_init_dai(&wm5110->core, i);
for (i = 0; i < ARRAY_SIZE(wm5110_digital_vu); i++)
regmap_update_bits(arizona->regmap, wm5110_digital_vu[i],
WM5110_DIG_VU, WM5110_DIG_VU);
pm_runtime_enable(&pdev->dev);
pm_runtime_idle(&pdev->dev);
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_wm5110,
wm5110_dai, ARRAY_SIZE(wm5110_dai));
}
static int wm5110_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
