static int asoc_simple_card_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct simple_card_data *priv = snd_soc_card_get_drvdata(rtd->card);
unsigned int mclk;
int ret = 0;
if (priv->mclk_fs) {
mclk = params_rate(params) * priv->mclk_fs;
ret = snd_soc_dai_set_sysclk(codec_dai, 0, mclk,
SND_SOC_CLOCK_IN);
}
return ret;
}
static int __asoc_simple_card_dai_init(struct snd_soc_dai *dai,
struct asoc_simple_dai *set)
{
int ret;
if (set->fmt) {
ret = snd_soc_dai_set_fmt(dai, set->fmt);
if (ret && ret != -ENOTSUPP) {
dev_err(dai->dev, "simple-card: set_fmt error\n");
goto err;
}
}
if (set->sysclk) {
ret = snd_soc_dai_set_sysclk(dai, 0, set->sysclk, 0);
if (ret && ret != -ENOTSUPP) {
dev_err(dai->dev, "simple-card: set_sysclk error\n");
goto err;
}
}
if (set->slots) {
ret = snd_soc_dai_set_tdm_slot(dai, 0, 0,
set->slots,
set->slot_width);
if (ret && ret != -ENOTSUPP) {
dev_err(dai->dev, "simple-card: set_tdm_slot error\n");
goto err;
}
}
ret = 0;
err:
return ret;
}
static int asoc_simple_card_dai_init(struct snd_soc_pcm_runtime *rtd)
{
struct simple_card_data *priv = snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_dai *codec = rtd->codec_dai;
struct snd_soc_dai *cpu = rtd->cpu_dai;
struct simple_dai_props *dai_props;
int num, ret;
num = rtd - rtd->card->rtd;
dai_props = &priv->dai_props[num];
ret = __asoc_simple_card_dai_init(codec, &dai_props->codec_dai);
if (ret < 0)
return ret;
ret = __asoc_simple_card_dai_init(cpu, &dai_props->cpu_dai);
if (ret < 0)
return ret;
return 0;
}
static int
asoc_simple_card_sub_parse_of(struct device_node *np,
struct asoc_simple_dai *dai,
const struct device_node **p_node,
const char **name)
{
struct device_node *node;
struct clk *clk;
u32 val;
int ret;
node = of_parse_phandle(np, "sound-dai", 0);
if (!node)
return -ENODEV;
*p_node = node;
ret = snd_soc_of_get_dai_name(np, name);
if (ret < 0)
return ret;
ret = snd_soc_of_parse_tdm_slot(np, &dai->slots, &dai->slot_width);
if (ret)
return ret;
if (of_property_read_bool(np, "clocks")) {
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
return ret;
}
dai->sysclk = clk_get_rate(clk);
} else if (!of_property_read_u32(np, "system-clock-frequency", &val)) {
dai->sysclk = val;
} else {
clk = of_clk_get(node, 0);
if (!IS_ERR(clk))
dai->sysclk = clk_get_rate(clk);
}
return 0;
}
static int simple_card_dai_link_of(struct device_node *node,
struct device *dev,
struct snd_soc_dai_link *dai_link,
struct simple_dai_props *dai_props,
bool is_top_level_node)
{
struct device_node *np = NULL;
struct device_node *bitclkmaster = NULL;
struct device_node *framemaster = NULL;
unsigned int daifmt;
char *name;
char prop[128];
char *prefix = "";
int ret;
if (is_top_level_node)
prefix = "simple-audio-card,";
daifmt = snd_soc_of_parse_daifmt(node, prefix,
&bitclkmaster, &framemaster);
daifmt &= ~SND_SOC_DAIFMT_MASTER_MASK;
snprintf(prop, sizeof(prop), "%scpu", prefix);
np = of_get_child_by_name(node, prop);
if (!np) {
ret = -EINVAL;
dev_err(dev, "%s: Can't find %s DT node\n", __func__, prop);
goto dai_link_of_err;
}
ret = asoc_simple_card_sub_parse_of(np, &dai_props->cpu_dai,
&dai_link->cpu_of_node,
&dai_link->cpu_dai_name);
if (ret < 0)
goto dai_link_of_err;
dai_props->cpu_dai.fmt = daifmt;
switch (((np == bitclkmaster) << 4) | (np == framemaster)) {
case 0x11:
dai_props->cpu_dai.fmt |= SND_SOC_DAIFMT_CBS_CFS;
break;
case 0x10:
dai_props->cpu_dai.fmt |= SND_SOC_DAIFMT_CBS_CFM;
break;
case 0x01:
dai_props->cpu_dai.fmt |= SND_SOC_DAIFMT_CBM_CFS;
break;
default:
dai_props->cpu_dai.fmt |= SND_SOC_DAIFMT_CBM_CFM;
break;
}
of_node_put(np);
snprintf(prop, sizeof(prop), "%scodec", prefix);
np = of_get_child_by_name(node, prop);
if (!np) {
ret = -EINVAL;
dev_err(dev, "%s: Can't find %s DT node\n", __func__, prop);
goto dai_link_of_err;
}
ret = asoc_simple_card_sub_parse_of(np, &dai_props->codec_dai,
&dai_link->codec_of_node,
&dai_link->codec_dai_name);
if (ret < 0)
goto dai_link_of_err;
if (strlen(prefix) && !bitclkmaster && !framemaster) {
dev_dbg(dev, "%s: Revert to legacy daifmt parsing\n",
__func__);
dai_props->cpu_dai.fmt = dai_props->codec_dai.fmt =
snd_soc_of_parse_daifmt(np, NULL, NULL, NULL) |
(daifmt & ~SND_SOC_DAIFMT_CLOCK_MASK);
} else {
dai_props->codec_dai.fmt = daifmt;
switch (((np == bitclkmaster) << 4) | (np == framemaster)) {
case 0x11:
dai_props->codec_dai.fmt |= SND_SOC_DAIFMT_CBM_CFM;
break;
case 0x10:
dai_props->codec_dai.fmt |= SND_SOC_DAIFMT_CBM_CFS;
break;
case 0x01:
dai_props->codec_dai.fmt |= SND_SOC_DAIFMT_CBS_CFM;
break;
default:
dai_props->codec_dai.fmt |= SND_SOC_DAIFMT_CBS_CFS;
break;
}
}
if (!dai_link->cpu_dai_name || !dai_link->codec_dai_name) {
ret = -EINVAL;
goto dai_link_of_err;
}
dai_link->platform_of_node = dai_link->cpu_of_node;
name = devm_kzalloc(dev,
strlen(dai_link->cpu_dai_name) +
strlen(dai_link->codec_dai_name) + 2,
GFP_KERNEL);
sprintf(name, "%s-%s", dai_link->cpu_dai_name,
dai_link->codec_dai_name);
dai_link->name = dai_link->stream_name = name;
dai_link->ops = &asoc_simple_card_ops;
dev_dbg(dev, "\tname : %s\n", dai_link->stream_name);
dev_dbg(dev, "\tcpu : %s / %04x / %d\n",
dai_link->cpu_dai_name,
dai_props->cpu_dai.fmt,
dai_props->cpu_dai.sysclk);
dev_dbg(dev, "\tcodec : %s / %04x / %d\n",
dai_link->codec_dai_name,
dai_props->codec_dai.fmt,
dai_props->codec_dai.sysclk);
dai_link_of_err:
if (np)
of_node_put(np);
if (bitclkmaster)
of_node_put(bitclkmaster);
if (framemaster)
of_node_put(framemaster);
return ret;
}
static int asoc_simple_card_parse_of(struct device_node *node,
struct simple_card_data *priv,
struct device *dev,
int multi)
{
struct snd_soc_dai_link *dai_link = priv->snd_card.dai_link;
struct simple_dai_props *dai_props = priv->dai_props;
u32 val;
int ret;
snd_soc_of_parse_card_name(&priv->snd_card, "simple-audio-card,name");
if (of_property_read_bool(node, "simple-audio-card,widgets")) {
ret = snd_soc_of_parse_audio_simple_widgets(&priv->snd_card,
"simple-audio-card,widgets");
if (ret)
return ret;
}
if (of_property_read_bool(node, "simple-audio-card,routing")) {
ret = snd_soc_of_parse_audio_routing(&priv->snd_card,
"simple-audio-card,routing");
if (ret)
return ret;
}
ret = of_property_read_u32(node, "simple-audio-card,mclk-fs", &val);
if (ret == 0)
priv->mclk_fs = val;
dev_dbg(dev, "New simple-card: %s\n", priv->snd_card.name ?
priv->snd_card.name : "");
if (multi) {
struct device_node *np = NULL;
int i;
for (i = 0; (np = of_get_next_child(node, np)); i++) {
dev_dbg(dev, "\tlink %d:\n", i);
ret = simple_card_dai_link_of(np, dev, dai_link + i,
dai_props + i, false);
if (ret < 0) {
of_node_put(np);
return ret;
}
}
} else {
ret = simple_card_dai_link_of(node, dev, dai_link, dai_props,
true);
if (ret < 0)
return ret;
}
if (!priv->snd_card.name)
priv->snd_card.name = priv->snd_card.dai_link->name;
return 0;
}
static int asoc_simple_card_unref(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct snd_soc_dai_link *dai_link;
struct device_node *np;
int num_links;
for (num_links = 0, dai_link = card->dai_link;
num_links < card->num_links;
num_links++, dai_link++) {
np = (struct device_node *) dai_link->cpu_of_node;
if (np)
of_node_put(np);
np = (struct device_node *) dai_link->codec_of_node;
if (np)
of_node_put(np);
}
return 0;
}
static int asoc_simple_card_probe(struct platform_device *pdev)
{
struct simple_card_data *priv;
struct snd_soc_dai_link *dai_link;
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
int num_links, multi, ret;
if (np && of_get_child_by_name(np, "simple-audio-card,dai-link")) {
num_links = of_get_child_count(np);
multi = 1;
} else {
num_links = 1;
multi = 0;
}
priv = devm_kzalloc(dev,
sizeof(*priv) + sizeof(*dai_link) * num_links,
GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->snd_card.owner = THIS_MODULE;
priv->snd_card.dev = dev;
dai_link = priv->dai_link;
priv->snd_card.dai_link = dai_link;
priv->snd_card.num_links = num_links;
priv->dai_props = devm_kzalloc(dev,
sizeof(*priv->dai_props) * num_links,
GFP_KERNEL);
if (!priv->dai_props)
return -ENOMEM;
if (np && of_device_is_available(np)) {
ret = asoc_simple_card_parse_of(np, priv, dev, multi);
if (ret < 0) {
if (ret != -EPROBE_DEFER)
dev_err(dev, "parse error %d\n", ret);
goto err;
}
if (num_links == 1)
dai_link->cpu_dai_name = NULL;
} else {
struct asoc_simple_card_info *cinfo;
cinfo = dev->platform_data;
if (!cinfo) {
dev_err(dev, "no info for asoc-simple-card\n");
return -EINVAL;
}
if (!cinfo->name ||
!cinfo->codec_dai.name ||
!cinfo->codec ||
!cinfo->platform ||
!cinfo->cpu_dai.name) {
dev_err(dev, "insufficient asoc_simple_card_info settings\n");
return -EINVAL;
}
priv->snd_card.name = (cinfo->card) ? cinfo->card : cinfo->name;
dai_link->name = cinfo->name;
dai_link->stream_name = cinfo->name;
dai_link->platform_name = cinfo->platform;
dai_link->codec_name = cinfo->codec;
dai_link->cpu_dai_name = cinfo->cpu_dai.name;
dai_link->codec_dai_name = cinfo->codec_dai.name;
memcpy(&priv->dai_props->cpu_dai, &cinfo->cpu_dai,
sizeof(priv->dai_props->cpu_dai));
memcpy(&priv->dai_props->codec_dai, &cinfo->codec_dai,
sizeof(priv->dai_props->codec_dai));
priv->dai_props->cpu_dai.fmt |= cinfo->daifmt;
priv->dai_props->codec_dai.fmt |= cinfo->daifmt;
}
dai_link->init = asoc_simple_card_dai_init;
snd_soc_card_set_drvdata(&priv->snd_card, priv);
ret = devm_snd_soc_register_card(&pdev->dev, &priv->snd_card);
if (ret >= 0)
return ret;
err:
asoc_simple_card_unref(pdev);
return ret;
}
static int asoc_simple_card_remove(struct platform_device *pdev)
{
return asoc_simple_card_unref(pdev);
}
