static int mt2701_cs42448_i2sin1_mux_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
struct mt2701_cs42448_private *priv = snd_soc_card_get_drvdata(card);
ucontrol->value.integer.value[0] = priv->i2s1_in_mux;
return 0;
}
static int mt2701_cs42448_i2sin1_mux_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
struct mt2701_cs42448_private *priv = snd_soc_card_get_drvdata(card);
if (ucontrol->value.integer.value[0] == priv->i2s1_in_mux)
return 0;
switch (ucontrol->value.integer.value[0]) {
case 0:
gpio_set_value(priv->i2s1_in_mux_gpio_sel_1, 0);
gpio_set_value(priv->i2s1_in_mux_gpio_sel_2, 0);
break;
case 1:
gpio_set_value(priv->i2s1_in_mux_gpio_sel_1, 1);
gpio_set_value(priv->i2s1_in_mux_gpio_sel_2, 0);
break;
case 2:
gpio_set_value(priv->i2s1_in_mux_gpio_sel_1, 0);
gpio_set_value(priv->i2s1_in_mux_gpio_sel_2, 1);
break;
case 3:
gpio_set_value(priv->i2s1_in_mux_gpio_sel_1, 1);
gpio_set_value(priv->i2s1_in_mux_gpio_sel_2, 1);
break;
default:
dev_warn(card->dev, "%s invalid setting\n", __func__);
}
priv->i2s1_in_mux = ucontrol->value.integer.value[0];
return 0;
}
static int mt2701_cs42448_fe_ops_startup(struct snd_pcm_substream *substream)
{
int err;
err = snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&mt2701_cs42448_constraints_rates);
if (err < 0) {
dev_err(substream->pcm->card->dev,
"%s snd_pcm_hw_constraint_list failed: 0x%x\n",
__func__, err);
return err;
}
return 0;
}
static int mt2701_cs42448_be_ops_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
unsigned int mclk_rate;
unsigned int rate = params_rate(params);
unsigned int div_mclk_over_bck = rate > 192000 ? 2 : 4;
unsigned int div_bck_over_lrck = 64;
mclk_rate = rate * div_bck_over_lrck * div_mclk_over_bck;
snd_soc_dai_set_sysclk(cpu_dai, 0, mclk_rate, SND_SOC_CLOCK_OUT);
snd_soc_dai_set_sysclk(codec_dai, 0, mclk_rate, SND_SOC_CLOCK_IN);
return 0;
}
static int mt2701_cs42448_machine_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &mt2701_cs42448_soc_card;
int ret;
int i;
struct device_node *platform_node, *codec_node, *codec_node_bt_mrg;
struct mt2701_cs42448_private *priv =
devm_kzalloc(&pdev->dev, sizeof(struct mt2701_cs42448_private),
GFP_KERNEL);
struct device *dev = &pdev->dev;
if (!priv)
return -ENOMEM;
platform_node = of_parse_phandle(pdev->dev.of_node,
"mediatek,platform", 0);
if (!platform_node) {
dev_err(&pdev->dev, "Property 'platform' missing or invalid\n");
return -EINVAL;
}
for (i = 0; i < card->num_links; i++) {
if (mt2701_cs42448_dai_links[i].platform_name)
continue;
mt2701_cs42448_dai_links[i].platform_of_node = platform_node;
}
card->dev = dev;
codec_node = of_parse_phandle(pdev->dev.of_node,
"mediatek,audio-codec", 0);
if (!codec_node) {
dev_err(&pdev->dev,
"Property 'audio-codec' missing or invalid\n");
return -EINVAL;
}
for (i = 0; i < card->num_links; i++) {
if (mt2701_cs42448_dai_links[i].codec_name)
continue;
mt2701_cs42448_dai_links[i].codec_of_node = codec_node;
}
codec_node_bt_mrg = of_parse_phandle(pdev->dev.of_node,
"mediatek,audio-codec-bt-mrg", 0);
if (!codec_node_bt_mrg) {
dev_err(&pdev->dev,
"Property 'audio-codec-bt-mrg' missing or invalid\n");
return -EINVAL;
}
mt2701_cs42448_dai_links[DAI_LINK_BE_MRG_BT].codec_of_node
= codec_node_bt_mrg;
ret = snd_soc_of_parse_audio_routing(card, "audio-routing");
if (ret) {
dev_err(&pdev->dev, "failed to parse audio-routing: %d\n", ret);
return ret;
}
priv->i2s1_in_mux_gpio_sel_1 =
of_get_named_gpio(dev->of_node, "i2s1-in-sel-gpio1", 0);
if (gpio_is_valid(priv->i2s1_in_mux_gpio_sel_1)) {
ret = devm_gpio_request(dev, priv->i2s1_in_mux_gpio_sel_1,
"i2s1_in_mux_gpio_sel_1");
if (ret)
dev_warn(&pdev->dev, "%s devm_gpio_request fail %d\n",
__func__, ret);
gpio_direction_output(priv->i2s1_in_mux_gpio_sel_1, 0);
}
priv->i2s1_in_mux_gpio_sel_2 =
of_get_named_gpio(dev->of_node, "i2s1-in-sel-gpio2", 0);
if (gpio_is_valid(priv->i2s1_in_mux_gpio_sel_2)) {
ret = devm_gpio_request(dev, priv->i2s1_in_mux_gpio_sel_2,
"i2s1_in_mux_gpio_sel_2");
if (ret)
dev_warn(&pdev->dev, "%s devm_gpio_request fail2 %d\n",
__func__, ret);
gpio_direction_output(priv->i2s1_in_mux_gpio_sel_2, 0);
}
snd_soc_card_set_drvdata(card, priv);
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret)
dev_err(&pdev->dev, "%s snd_soc_register_card fail %d\n",
__func__, ret);
return ret;
}
