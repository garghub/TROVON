static int asoc_graph_card_outdrv_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_dapm_context *dapm = w->dapm;
struct graph_card_data *priv = snd_soc_card_get_drvdata(dapm->card);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
gpiod_set_value_cansleep(priv->pa_gpio, 1);
break;
case SND_SOC_DAPM_PRE_PMD:
gpiod_set_value_cansleep(priv->pa_gpio, 0);
break;
default:
return -EINVAL;
}
return 0;
}
static int asoc_graph_card_startup(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct graph_card_data *priv = snd_soc_card_get_drvdata(rtd->card);
struct graph_dai_props *dai_props = graph_priv_to_props(priv, rtd->num);
int ret;
ret = asoc_simple_card_clk_enable(&dai_props->cpu_dai);
if (ret)
return ret;
ret = asoc_simple_card_clk_enable(&dai_props->codec_dai);
if (ret)
asoc_simple_card_clk_disable(&dai_props->cpu_dai);
return ret;
}
static void asoc_graph_card_shutdown(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct graph_card_data *priv = snd_soc_card_get_drvdata(rtd->card);
struct graph_dai_props *dai_props = graph_priv_to_props(priv, rtd->num);
asoc_simple_card_clk_disable(&dai_props->cpu_dai);
asoc_simple_card_clk_disable(&dai_props->codec_dai);
}
static int asoc_graph_card_dai_init(struct snd_soc_pcm_runtime *rtd)
{
struct graph_card_data *priv = snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_dai *codec = rtd->codec_dai;
struct snd_soc_dai *cpu = rtd->cpu_dai;
struct graph_dai_props *dai_props =
graph_priv_to_props(priv, rtd->num);
int ret;
ret = asoc_simple_card_init_dai(codec, &dai_props->codec_dai);
if (ret < 0)
return ret;
ret = asoc_simple_card_init_dai(cpu, &dai_props->cpu_dai);
if (ret < 0)
return ret;
return 0;
}
static int asoc_graph_card_dai_link_of(struct device_node *cpu_port,
struct graph_card_data *priv,
int idx)
{
struct device *dev = graph_priv_to_dev(priv);
struct snd_soc_dai_link *dai_link = graph_priv_to_link(priv, idx);
struct graph_dai_props *dai_props = graph_priv_to_props(priv, idx);
struct asoc_simple_dai *cpu_dai = &dai_props->cpu_dai;
struct asoc_simple_dai *codec_dai = &dai_props->codec_dai;
struct device_node *cpu_ep = of_get_next_child(cpu_port, NULL);
struct device_node *codec_ep = of_graph_get_remote_endpoint(cpu_ep);
struct device_node *rcpu_ep = of_graph_get_remote_endpoint(codec_ep);
int ret;
if (rcpu_ep != cpu_ep) {
dev_err(dev, "remote-endpoint mismatch (%s/%s/%s)\n",
cpu_ep->name, codec_ep->name, rcpu_ep->name);
ret = -EINVAL;
goto dai_link_of_err;
}
ret = asoc_simple_card_parse_daifmt(dev, cpu_ep, codec_ep,
NULL, &dai_link->dai_fmt);
if (ret < 0)
goto dai_link_of_err;
ret = asoc_simple_card_parse_graph_cpu(cpu_ep, dai_link);
if (ret < 0)
goto dai_link_of_err;
ret = asoc_simple_card_parse_graph_codec(codec_ep, dai_link);
if (ret < 0)
goto dai_link_of_err;
ret = asoc_simple_card_of_parse_tdm(cpu_ep, cpu_dai);
if (ret < 0)
goto dai_link_of_err;
ret = asoc_simple_card_of_parse_tdm(codec_ep, codec_dai);
if (ret < 0)
goto dai_link_of_err;
ret = asoc_simple_card_parse_clk_cpu(dev, cpu_ep, dai_link, cpu_dai);
if (ret < 0)
goto dai_link_of_err;
ret = asoc_simple_card_parse_clk_codec(dev, codec_ep, dai_link, codec_dai);
if (ret < 0)
goto dai_link_of_err;
ret = asoc_simple_card_canonicalize_dailink(dai_link);
if (ret < 0)
goto dai_link_of_err;
ret = asoc_simple_card_set_dailink_name(dev, dai_link,
"%s-%s",
dai_link->cpu_dai_name,
dai_link->codec_dai_name);
if (ret < 0)
goto dai_link_of_err;
dai_link->ops = &asoc_graph_card_ops;
dai_link->init = asoc_graph_card_dai_init;
asoc_simple_card_canonicalize_cpu(dai_link,
of_graph_get_endpoint_count(dai_link->cpu_of_node) == 1);
dai_link_of_err:
of_node_put(cpu_ep);
of_node_put(rcpu_ep);
of_node_put(codec_ep);
return ret;
}
static int asoc_graph_card_parse_of(struct graph_card_data *priv)
{
struct of_phandle_iterator it;
struct device *dev = graph_priv_to_dev(priv);
struct snd_soc_card *card = graph_priv_to_card(priv);
struct device_node *node = dev->of_node;
int rc, idx = 0;
int ret;
ret = asoc_simple_card_of_parse_widgets(card, NULL);
if (ret < 0)
return ret;
ret = asoc_simple_card_of_parse_routing(card, NULL, 1);
if (ret < 0)
return ret;
of_for_each_phandle(&it, rc, node, "dais", NULL, 0) {
ret = asoc_graph_card_dai_link_of(it.node, priv, idx++);
if (ret < 0) {
of_node_put(it.node);
return ret;
}
}
return asoc_simple_card_parse_card_name(card, NULL);
}
static int asoc_graph_get_dais_count(struct device *dev)
{
struct of_phandle_iterator it;
struct device_node *node = dev->of_node;
int count = 0;
int rc;
of_for_each_phandle(&it, rc, node, "dais", NULL, 0)
count++;
return count;
}
static int asoc_graph_card_probe(struct platform_device *pdev)
{
struct graph_card_data *priv;
struct snd_soc_dai_link *dai_link;
struct graph_dai_props *dai_props;
struct device *dev = &pdev->dev;
struct snd_soc_card *card;
int num, ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
num = asoc_graph_get_dais_count(dev);
if (num == 0)
return -EINVAL;
dai_props = devm_kzalloc(dev, sizeof(*dai_props) * num, GFP_KERNEL);
dai_link = devm_kzalloc(dev, sizeof(*dai_link) * num, GFP_KERNEL);
if (!dai_props || !dai_link)
return -ENOMEM;
priv->pa_gpio = devm_gpiod_get_optional(dev, "pa", GPIOD_OUT_LOW);
if (IS_ERR(priv->pa_gpio)) {
ret = PTR_ERR(priv->pa_gpio);
dev_err(dev, "failed to get amplifier gpio: %d\n", ret);
return ret;
}
priv->dai_props = dai_props;
priv->dai_link = dai_link;
card = graph_priv_to_card(priv);
card->owner = THIS_MODULE;
card->dev = dev;
card->dai_link = dai_link;
card->num_links = num;
card->dapm_widgets = asoc_graph_card_dapm_widgets;
card->num_dapm_widgets = ARRAY_SIZE(asoc_graph_card_dapm_widgets);
ret = asoc_graph_card_parse_of(priv);
if (ret < 0) {
if (ret != -EPROBE_DEFER)
dev_err(dev, "parse error %d\n", ret);
goto err;
}
snd_soc_card_set_drvdata(card, priv);
ret = devm_snd_soc_register_card(dev, card);
if (ret < 0)
goto err;
return 0;
err:
asoc_simple_card_clean_reference(card);
return ret;
}
static int asoc_graph_card_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
return asoc_simple_card_clean_reference(card);
}
