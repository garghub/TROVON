static int rsrc_card_startup(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct rsrc_card_priv *priv = snd_soc_card_get_drvdata(rtd->card);
struct asoc_simple_dai *dai_props =
rsrc_priv_to_props(priv, rtd->num);
return clk_prepare_enable(dai_props->clk);
}
static void rsrc_card_shutdown(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct rsrc_card_priv *priv = snd_soc_card_get_drvdata(rtd->card);
struct asoc_simple_dai *dai_props =
rsrc_priv_to_props(priv, rtd->num);
clk_disable_unprepare(dai_props->clk);
}
static int rsrc_card_dai_init(struct snd_soc_pcm_runtime *rtd)
{
struct rsrc_card_priv *priv = snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_dai *dai;
struct snd_soc_dai_link *dai_link;
struct asoc_simple_dai *dai_props;
int num = rtd->num;
int ret;
dai_link = rsrc_priv_to_link(priv, num);
dai_props = rsrc_priv_to_props(priv, num);
dai = dai_link->dynamic ?
rtd->cpu_dai :
rtd->codec_dai;
if (dai_props->sysclk) {
ret = snd_soc_dai_set_sysclk(dai, 0, dai_props->sysclk, 0);
if (ret && ret != -ENOTSUPP) {
dev_err(dai->dev, "set_sysclk error\n");
goto err;
}
}
if (dai_props->slots) {
ret = snd_soc_dai_set_tdm_slot(dai,
dai_props->tx_slot_mask,
dai_props->rx_slot_mask,
dai_props->slots,
dai_props->slot_width);
if (ret && ret != -ENOTSUPP) {
dev_err(dai->dev, "set_tdm_slot error\n");
goto err;
}
}
ret = 0;
err:
return ret;
}
static int rsrc_card_be_hw_params_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct rsrc_card_priv *priv = snd_soc_card_get_drvdata(rtd->card);
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
if (priv->convert_rate)
rate->min =
rate->max = priv->convert_rate;
if (priv->convert_channels)
channels->min =
channels->max = priv->convert_channels;
return 0;
}
static int rsrc_card_parse_links(struct device_node *np,
struct rsrc_card_priv *priv,
int idx, bool is_fe)
{
struct device *dev = rsrc_priv_to_dev(priv);
struct snd_soc_dai_link *dai_link = rsrc_priv_to_link(priv, idx);
struct asoc_simple_dai *dai_props = rsrc_priv_to_props(priv, idx);
struct of_phandle_args args;
int ret;
ret = of_parse_phandle_with_args(np, "sound-dai",
"#sound-dai-cells", 0, &args);
if (ret)
return ret;
ret = snd_soc_of_parse_tdm_slot(np,
&dai_props->tx_slot_mask,
&dai_props->rx_slot_mask,
&dai_props->slots,
&dai_props->slot_width);
if (ret)
return ret;
if (is_fe) {
dai_link->codec_of_node = NULL;
dai_link->codec_dai_name = "snd-soc-dummy-dai";
dai_link->codec_name = "snd-soc-dummy";
dai_link->dynamic = 1;
dai_link->dpcm_merged_format = 1;
dai_link->cpu_of_node = args.np;
ret = snd_soc_of_get_dai_name(np, &dai_link->cpu_dai_name);
if (ret < 0)
return ret;
ret = asoc_simple_card_set_dailink_name(dev, dai_link,
"fe.%s",
dai_link->cpu_dai_name);
if (ret < 0)
return ret;
if (!args.args_count)
dai_link->cpu_dai_name = NULL;
} else {
const struct rsrc_card_of_data *of_data;
of_data = of_device_get_match_data(dev);
dai_link->cpu_of_node = NULL;
dai_link->cpu_dai_name = "snd-soc-dummy-dai";
dai_link->cpu_name = "snd-soc-dummy";
dai_link->no_pcm = 1;
dai_link->be_hw_params_fixup = rsrc_card_be_hw_params_fixup;
dai_link->codec_of_node = args.np;
ret = snd_soc_of_get_dai_name(np, &dai_link->codec_dai_name);
if (ret < 0)
return ret;
ret = asoc_simple_card_set_dailink_name(dev, dai_link,
"be.%s",
dai_link->codec_dai_name);
if (ret < 0)
return ret;
if (of_data) {
priv->codec_conf.of_node = dai_link->codec_of_node;
priv->codec_conf.name_prefix = of_data->prefix;
} else {
snd_soc_of_parse_audio_prefix(&priv->snd_card,
&priv->codec_conf,
dai_link->codec_of_node,
"audio-prefix");
}
}
dai_link->platform_of_node = dai_link->cpu_of_node;
dai_link->dpcm_playback = 1;
dai_link->dpcm_capture = 1;
dai_link->ops = &rsrc_card_ops;
dai_link->init = rsrc_card_dai_init;
return 0;
}
static int rsrc_card_parse_clk(struct device_node *np,
struct rsrc_card_priv *priv,
int idx, bool is_fe)
{
struct snd_soc_dai_link *dai_link = rsrc_priv_to_link(priv, idx);
struct asoc_simple_dai *dai_props = rsrc_priv_to_props(priv, idx);
struct clk *clk;
struct device_node *of_np = is_fe ? dai_link->cpu_of_node :
dai_link->codec_of_node;
u32 val;
if (of_property_read_bool(np, "clocks")) {
clk = of_clk_get(np, 0);
if (IS_ERR(clk))
return PTR_ERR(clk);
dai_props->sysclk = clk_get_rate(clk);
dai_props->clk = clk;
} else if (!of_property_read_u32(np, "system-clock-frequency", &val)) {
dai_props->sysclk = val;
} else {
clk = of_clk_get(of_np, 0);
if (!IS_ERR(clk))
dai_props->sysclk = clk_get_rate(clk);
}
return 0;
}
static int rsrc_card_dai_sub_link_of(struct device_node *node,
struct device_node *np,
struct rsrc_card_priv *priv,
int idx, bool is_fe)
{
struct device *dev = rsrc_priv_to_dev(priv);
struct snd_soc_dai_link *dai_link = rsrc_priv_to_link(priv, idx);
struct asoc_simple_dai *dai_props = rsrc_priv_to_props(priv, idx);
int ret;
ret = rsrc_card_parse_links(np, priv, idx, is_fe);
if (ret < 0)
return ret;
ret = rsrc_card_parse_clk(np, priv, idx, is_fe);
if (ret < 0)
return ret;
dev_dbg(dev, "\t%s / %04x / %d\n",
dai_link->name,
dai_link->dai_fmt,
dai_props->sysclk);
return ret;
}
static int rsrc_card_dai_link_of(struct device_node *node,
struct rsrc_card_priv *priv)
{
struct device *dev = rsrc_priv_to_dev(priv);
struct snd_soc_dai_link *dai_link;
struct device_node *np;
unsigned int daifmt = 0;
int ret, i;
bool is_fe;
i = 0;
for_each_child_of_node(node, np) {
dai_link = rsrc_priv_to_link(priv, i);
if (strcmp(np->name, "codec") == 0) {
ret = asoc_simple_card_parse_daifmt(dev, node, np,
NULL, &daifmt);
if (ret < 0)
return ret;
break;
}
i++;
}
i = 0;
for_each_child_of_node(node, np) {
dai_link = rsrc_priv_to_link(priv, i);
dai_link->dai_fmt = daifmt;
is_fe = false;
if (strcmp(np->name, "cpu") == 0)
is_fe = true;
ret = rsrc_card_dai_sub_link_of(node, np, priv, i, is_fe);
if (ret < 0)
return ret;
i++;
}
return 0;
}
static int rsrc_card_parse_of(struct device_node *node,
struct rsrc_card_priv *priv,
struct device *dev)
{
const struct rsrc_card_of_data *of_data = of_device_get_match_data(dev);
struct asoc_simple_dai *props;
struct snd_soc_dai_link *links;
int ret;
int num;
if (!node)
return -EINVAL;
num = of_get_child_count(node);
props = devm_kzalloc(dev, sizeof(*props) * num, GFP_KERNEL);
links = devm_kzalloc(dev, sizeof(*links) * num, GFP_KERNEL);
if (!props || !links)
return -ENOMEM;
priv->dai_props = props;
priv->dai_link = links;
priv->snd_card.owner = THIS_MODULE;
priv->snd_card.dev = dev;
priv->snd_card.dai_link = priv->dai_link;
priv->snd_card.num_links = num;
priv->snd_card.codec_conf = &priv->codec_conf;
priv->snd_card.num_configs = 1;
if (of_data) {
priv->snd_card.of_dapm_routes = of_data->routes;
priv->snd_card.num_of_dapm_routes = of_data->num_routes;
} else {
snd_soc_of_parse_audio_routing(&priv->snd_card,
"audio-routing");
}
of_property_read_u32(node, "convert-rate", &priv->convert_rate);
of_property_read_u32(node, "convert-channels", &priv->convert_channels);
dev_dbg(dev, "New rsrc-audio-card: %s\n",
priv->snd_card.name ? priv->snd_card.name : "");
dev_dbg(dev, "SRC : convert_rate %d\n", priv->convert_rate);
dev_dbg(dev, "CTU : convert_channels %d\n", priv->convert_channels);
ret = rsrc_card_dai_link_of(node, priv);
if (ret < 0)
return ret;
ret = asoc_simple_card_parse_card_name(&priv->snd_card, "card-");
if (ret < 0)
return ret;
return 0;
}
static int rsrc_card_unref(struct snd_soc_card *card)
{
struct snd_soc_dai_link *dai_link;
int num_links;
for (num_links = 0, dai_link = card->dai_link;
num_links < card->num_links;
num_links++, dai_link++) {
of_node_put(dai_link->cpu_of_node);
of_node_put(dai_link->codec_of_node);
}
return 0;
}
static int rsrc_card_probe(struct platform_device *pdev)
{
struct rsrc_card_priv *priv;
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
ret = rsrc_card_parse_of(np, priv, dev);
if (ret < 0) {
if (ret != -EPROBE_DEFER)
dev_err(dev, "parse error %d\n", ret);
goto err;
}
snd_soc_card_set_drvdata(&priv->snd_card, priv);
ret = devm_snd_soc_register_card(&pdev->dev, &priv->snd_card);
if (ret >= 0)
return ret;
err:
rsrc_card_unref(&priv->snd_card);
return ret;
}
static int rsrc_card_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
return rsrc_card_unref(card);
}
