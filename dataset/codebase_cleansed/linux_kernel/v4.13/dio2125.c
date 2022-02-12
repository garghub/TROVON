static int drv_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *control, int event)
{
struct snd_soc_component *c = snd_soc_dapm_to_component(w->dapm);
struct dio2125 *priv = snd_soc_component_get_drvdata(c);
int val;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
val = 1;
break;
case SND_SOC_DAPM_PRE_PMD:
val = 0;
break;
default:
WARN(1, "Unexpected event");
return -EINVAL;
}
gpiod_set_value_cansleep(priv->gpiod_enable, val);
return 0;
}
static int dio2125_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct dio2125 *priv;
int err;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, priv);
priv->gpiod_enable = devm_gpiod_get(dev, "enable", GPIOD_OUT_LOW);
if (IS_ERR(priv->gpiod_enable)) {
err = PTR_ERR(priv->gpiod_enable);
if (err != -EPROBE_DEFER)
dev_err(dev, "Failed to get 'enable' gpio: %d", err);
return err;
}
return devm_snd_soc_register_component(dev, &dio2125_component_driver,
NULL, 0);
}
