static int tse850_get_mux1(struct snd_kcontrol *kctrl,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
struct snd_soc_card *card = dapm->card;
struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
ucontrol->value.enumerated.item[0] = tse850->loop1_cache;
return 0;
}
static int tse850_put_mux1(struct snd_kcontrol *kctrl,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
struct snd_soc_card *card = dapm->card;
struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
struct soc_enum *e = (struct soc_enum *)kctrl->private_value;
unsigned int val = ucontrol->value.enumerated.item[0];
if (val >= e->items)
return -EINVAL;
gpiod_set_value_cansleep(tse850->loop1, val);
tse850->loop1_cache = val;
return snd_soc_dapm_put_enum_double(kctrl, ucontrol);
}
static int tse850_get_mux2(struct snd_kcontrol *kctrl,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
struct snd_soc_card *card = dapm->card;
struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
ucontrol->value.enumerated.item[0] = tse850->loop2_cache;
return 0;
}
static int tse850_put_mux2(struct snd_kcontrol *kctrl,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
struct snd_soc_card *card = dapm->card;
struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
struct soc_enum *e = (struct soc_enum *)kctrl->private_value;
unsigned int val = ucontrol->value.enumerated.item[0];
if (val >= e->items)
return -EINVAL;
gpiod_set_value_cansleep(tse850->loop2, val);
tse850->loop2_cache = val;
return snd_soc_dapm_put_enum_double(kctrl, ucontrol);
}
int tse850_get_mix(struct snd_kcontrol *kctrl,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
struct snd_soc_card *card = dapm->card;
struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
ucontrol->value.enumerated.item[0] = tse850->add_cache;
return 0;
}
int tse850_put_mix(struct snd_kcontrol *kctrl,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
struct snd_soc_card *card = dapm->card;
struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
int connect = !!ucontrol->value.integer.value[0];
if (tse850->add_cache == connect)
return 0;
gpiod_set_value_cansleep(tse850->add, connect);
tse850->add_cache = connect;
snd_soc_dapm_mixer_update_power(dapm, kctrl, connect, NULL);
return 1;
}
int tse850_get_ana(struct snd_kcontrol *kctrl,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
struct snd_soc_card *card = dapm->card;
struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
int ret;
ret = regulator_get_voltage(tse850->ana);
if (ret < 0)
return ret;
if (ret < 11000000)
ret = 11000000;
else if (ret > 20000000)
ret = 20000000;
ret -= 11000000;
ret = (ret + 500000) / 1000000;
ucontrol->value.enumerated.item[0] = ret;
return 0;
}
int tse850_put_ana(struct snd_kcontrol *kctrl,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_context *dapm = snd_soc_dapm_kcontrol_dapm(kctrl);
struct snd_soc_card *card = dapm->card;
struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
struct soc_enum *e = (struct soc_enum *)kctrl->private_value;
unsigned int uV = ucontrol->value.enumerated.item[0];
int ret;
if (uV >= e->items)
return -EINVAL;
if (uV)
uV = 11000000 + (1000000 * uV);
else
uV = 2000000;
ret = regulator_set_voltage(tse850->ana, uV, uV);
if (ret < 0)
return ret;
return snd_soc_dapm_put_enum_double(kctrl, ucontrol);
}
static int tse850_dt_init(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *codec_np, *cpu_np;
struct snd_soc_dai_link *dailink = &tse850_dailink;
if (!np) {
dev_err(&pdev->dev, "only device tree supported\n");
return -EINVAL;
}
cpu_np = of_parse_phandle(np, "axentia,cpu-dai", 0);
if (!cpu_np) {
dev_err(&pdev->dev, "failed to get cpu dai\n");
return -EINVAL;
}
dailink->cpu_of_node = cpu_np;
dailink->platform_of_node = cpu_np;
of_node_put(cpu_np);
codec_np = of_parse_phandle(np, "axentia,audio-codec", 0);
if (!codec_np) {
dev_err(&pdev->dev, "failed to get codec info\n");
return -EINVAL;
}
dailink->codec_of_node = codec_np;
of_node_put(codec_np);
return 0;
}
static int tse850_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &tse850_card;
struct device *dev = card->dev = &pdev->dev;
struct tse850_priv *tse850;
int ret;
tse850 = devm_kzalloc(dev, sizeof(*tse850), GFP_KERNEL);
if (!tse850)
return -ENOMEM;
snd_soc_card_set_drvdata(card, tse850);
ret = tse850_dt_init(pdev);
if (ret) {
dev_err(dev, "failed to init dt info\n");
return ret;
}
tse850->add = devm_gpiod_get(dev, "axentia,add", GPIOD_OUT_HIGH);
if (IS_ERR(tse850->add)) {
if (PTR_ERR(tse850->add) != -EPROBE_DEFER)
dev_err(dev, "failed to get 'add' gpio\n");
return PTR_ERR(tse850->add);
}
tse850->add_cache = 1;
tse850->loop1 = devm_gpiod_get(dev, "axentia,loop1", GPIOD_OUT_HIGH);
if (IS_ERR(tse850->loop1)) {
if (PTR_ERR(tse850->loop1) != -EPROBE_DEFER)
dev_err(dev, "failed to get 'loop1' gpio\n");
return PTR_ERR(tse850->loop1);
}
tse850->loop1_cache = 1;
tse850->loop2 = devm_gpiod_get(dev, "axentia,loop2", GPIOD_OUT_HIGH);
if (IS_ERR(tse850->loop2)) {
if (PTR_ERR(tse850->loop2) != -EPROBE_DEFER)
dev_err(dev, "failed to get 'loop2' gpio\n");
return PTR_ERR(tse850->loop2);
}
tse850->loop2_cache = 1;
tse850->ana = devm_regulator_get(dev, "axentia,ana");
if (IS_ERR(tse850->ana)) {
if (PTR_ERR(tse850->ana) != -EPROBE_DEFER)
dev_err(dev, "failed to get 'ana' regulator\n");
return PTR_ERR(tse850->ana);
}
ret = regulator_enable(tse850->ana);
if (ret < 0) {
dev_err(dev, "failed to enable the 'ana' regulator\n");
return ret;
}
ret = snd_soc_register_card(card);
if (ret) {
dev_err(dev, "snd_soc_register_card failed\n");
goto err_disable_ana;
}
return 0;
err_disable_ana:
regulator_disable(tse850->ana);
return ret;
}
static int tse850_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct tse850_priv *tse850 = snd_soc_card_get_drvdata(card);
snd_soc_unregister_card(card);
regulator_disable(tse850->ana);
return 0;
}
