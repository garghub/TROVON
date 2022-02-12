static int rsrc_card_startup(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct rsrc_card_priv *priv = snd_soc_card_get_drvdata(rtd->card);
struct rsrc_card_dai_props *dai_props =
&priv->dai_props[rtd - rtd->card->rtd];
int ret;
ret = clk_prepare_enable(dai_props->cpu_dai.clk);
if (ret)
return ret;
ret = clk_prepare_enable(dai_props->codec_dai.clk);
if (ret)
clk_disable_unprepare(dai_props->cpu_dai.clk);
return ret;
}
static void rsrc_card_shutdown(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct rsrc_card_priv *priv = snd_soc_card_get_drvdata(rtd->card);
struct rsrc_card_dai_props *dai_props =
&priv->dai_props[rtd - rtd->card->rtd];
clk_disable_unprepare(dai_props->cpu_dai.clk);
clk_disable_unprepare(dai_props->codec_dai.clk);
}
static int __rsrc_card_dai_init(struct snd_soc_dai *dai,
struct rsrc_card_dai *set)
{
int ret;
if (set->fmt) {
ret = snd_soc_dai_set_fmt(dai, set->fmt);
if (ret && ret != -ENOTSUPP) {
dev_err(dai->dev, "set_fmt error\n");
goto err;
}
}
if (set->sysclk) {
ret = snd_soc_dai_set_sysclk(dai, 0, set->sysclk, 0);
if (ret && ret != -ENOTSUPP) {
dev_err(dai->dev, "set_sysclk error\n");
goto err;
}
}
ret = 0;
err:
return ret;
}
static int rsrc_card_dai_init(struct snd_soc_pcm_runtime *rtd)
{
struct rsrc_card_priv *priv = snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_dai *codec = rtd->codec_dai;
struct snd_soc_dai *cpu = rtd->cpu_dai;
struct rsrc_card_dai_props *dai_props;
int num, ret;
num = rtd - rtd->card->rtd;
dai_props = &priv->dai_props[num];
ret = __rsrc_card_dai_init(codec, &dai_props->codec_dai);
if (ret < 0)
return ret;
ret = __rsrc_card_dai_init(cpu, &dai_props->cpu_dai);
if (ret < 0)
return ret;
return 0;
}
static int rsrc_card_be_hw_params_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct rsrc_card_priv *priv = snd_soc_card_get_drvdata(rtd->card);
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
if (!priv->convert_rate)
return 0;
rate->min = rate->max = priv->convert_rate;
return 0;
}
static int
rsrc_card_sub_parse_of(struct rsrc_card_priv *priv,
struct device_node *np,
struct rsrc_card_dai *dai,
struct snd_soc_dai_link *dai_link,
int *args_count)
{
struct device *dev = rsrc_priv_to_dev(priv);
const struct rsrc_card_of_data *of_data = rsrc_dev_to_of_data(dev);
struct of_phandle_args args;
struct device_node **p_node;
struct clk *clk;
const char **dai_name;
const char **name;
u32 val;
int ret;
if (args_count) {
p_node = &dai_link->cpu_of_node;
dai_name = &dai_link->cpu_dai_name;
name = &dai_link->cpu_name;
} else {
p_node = &dai_link->codec_of_node;
dai_name = &dai_link->codec_dai_name;
name = &dai_link->codec_name;
}
if (!np) {
*p_node = NULL;
*dai_name = "snd-soc-dummy-dai";
*name = "snd-soc-dummy";
return 0;
}
ret = of_parse_phandle_with_args(np, "sound-dai",
"#sound-dai-cells", 0, &args);
if (ret)
return ret;
*p_node = args.np;
ret = snd_soc_of_get_dai_name(np, dai_name);
if (ret < 0)
return ret;
dai_link->dpcm_playback = 1;
dai_link->dpcm_capture = 1;
if (args_count) {
*args_count = args.args_count;
dai_link->dynamic = 1;
} else {
dai_link->no_pcm = 1;
priv->codec_conf.of_node = (*p_node);
priv->codec_conf.name_prefix = of_data->prefix;
}
if (of_property_read_bool(np, "clocks")) {
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
return ret;
}
dai->sysclk = clk_get_rate(clk);
dai->clk = clk;
} else if (!of_property_read_u32(np, "system-clock-frequency", &val)) {
dai->sysclk = val;
} else {
clk = of_clk_get(args.np, 0);
if (!IS_ERR(clk))
dai->sysclk = clk_get_rate(clk);
}
return 0;
}
static int rsrc_card_parse_daifmt(struct device_node *node,
struct rsrc_card_priv *priv,
struct device_node *codec,
int idx)
{
struct device_node *bitclkmaster = NULL;
struct device_node *framemaster = NULL;
struct rsrc_card_dai_props *dai_props = rsrc_priv_to_props(priv, idx);
struct rsrc_card_dai *cpu_dai = &dai_props->cpu_dai;
struct rsrc_card_dai *codec_dai = &dai_props->codec_dai;
unsigned int daifmt;
daifmt = snd_soc_of_parse_daifmt(node, NULL,
&bitclkmaster, &framemaster);
daifmt &= ~SND_SOC_DAIFMT_MASTER_MASK;
if (!bitclkmaster && !framemaster)
return -EINVAL;
if (codec == bitclkmaster)
daifmt |= (codec == framemaster) ?
SND_SOC_DAIFMT_CBM_CFM : SND_SOC_DAIFMT_CBM_CFS;
else
daifmt |= (codec == framemaster) ?
SND_SOC_DAIFMT_CBS_CFM : SND_SOC_DAIFMT_CBS_CFS;
cpu_dai->fmt = daifmt;
codec_dai->fmt = daifmt;
of_node_put(bitclkmaster);
of_node_put(framemaster);
return 0;
}
static int rsrc_card_dai_link_of(struct device_node *node,
struct rsrc_card_priv *priv,
int idx)
{
struct device *dev = rsrc_priv_to_dev(priv);
struct snd_soc_dai_link *dai_link = rsrc_priv_to_link(priv, idx);
struct rsrc_card_dai_props *dai_props = rsrc_priv_to_props(priv, idx);
struct device_node *cpu = NULL;
struct device_node *codec = NULL;
char *name;
char prop[128];
int ret, cpu_args;
cpu = of_get_child_by_name(node, "cpu");
codec = of_get_child_by_name(node, "codec");
if (!cpu || !codec) {
ret = -EINVAL;
dev_err(dev, "%s: Can't find %s DT node\n", __func__, prop);
goto dai_link_of_err;
}
ret = rsrc_card_parse_daifmt(node, priv, codec, idx);
if (ret < 0)
goto dai_link_of_err;
ret = rsrc_card_sub_parse_of(priv, (idx == IDX_CPU) ? cpu : NULL,
&dai_props->cpu_dai,
dai_link,
&cpu_args);
if (ret < 0)
goto dai_link_of_err;
ret = rsrc_card_sub_parse_of(priv, (idx == IDX_CODEC) ? codec : NULL,
&dai_props->codec_dai,
dai_link,
NULL);
if (ret < 0)
goto dai_link_of_err;
if (!dai_link->cpu_dai_name || !dai_link->codec_dai_name) {
ret = -EINVAL;
goto dai_link_of_err;
}
dai_link->platform_of_node = dai_link->cpu_of_node;
name = devm_kzalloc(dev,
strlen(dai_link->cpu_dai_name) +
strlen(dai_link->codec_dai_name) + 2,
GFP_KERNEL);
if (!name) {
ret = -ENOMEM;
goto dai_link_of_err;
}
sprintf(name, "%s-%s", dai_link->cpu_dai_name,
dai_link->codec_dai_name);
dai_link->name = dai_link->stream_name = name;
dai_link->ops = &rsrc_card_ops;
dai_link->init = rsrc_card_dai_init;
if (idx == IDX_CODEC)
dai_link->be_hw_params_fixup = rsrc_card_be_hw_params_fixup;
dev_dbg(dev, "\tname : %s\n", dai_link->stream_name);
dev_dbg(dev, "\tcpu : %s / %04x / %d\n",
dai_link->cpu_dai_name,
dai_props->cpu_dai.fmt,
dai_props->cpu_dai.sysclk);
dev_dbg(dev, "\tcodec : %s / %04x / %d\n",
dai_link->codec_dai_name,
dai_props->codec_dai.fmt,
dai_props->codec_dai.sysclk);
if (!cpu_args)
dai_link->cpu_dai_name = NULL;
dai_link_of_err:
of_node_put(cpu);
of_node_put(codec);
return ret;
}
static int rsrc_card_parse_of(struct device_node *node,
struct rsrc_card_priv *priv)
{
struct device *dev = rsrc_priv_to_dev(priv);
const struct rsrc_card_of_data *of_data = rsrc_dev_to_of_data(dev);
int ret;
int i;
if (!node)
return -EINVAL;
snd_soc_of_parse_card_name(&priv->snd_card, "card-name");
priv->snd_card.of_dapm_routes = of_data->routes;
priv->snd_card.num_of_dapm_routes = of_data->num_routes;
of_property_read_u32(node, "convert-rate", &priv->convert_rate);
dev_dbg(dev, "New rsrc-audio-card: %s (%d)\n",
priv->snd_card.name ? priv->snd_card.name : "",
priv->convert_rate);
for (i = 0; i < RSRC_FB_NUM; i++) {
ret = rsrc_card_dai_link_of(node, priv, i);
if (ret < 0)
return ret;
}
if (!priv->snd_card.name)
priv->snd_card.name = priv->snd_card.dai_link->name;
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
struct snd_soc_dai_link *dai_link;
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->snd_card.owner = THIS_MODULE;
priv->snd_card.dev = dev;
dai_link = priv->dai_link;
priv->snd_card.dai_link = dai_link;
priv->snd_card.num_links = RSRC_FB_NUM;
priv->snd_card.codec_conf = &priv->codec_conf;
priv->snd_card.num_configs = 1;
ret = rsrc_card_parse_of(np, priv);
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
