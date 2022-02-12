void asoc_simple_card_convert_fixup(struct asoc_simple_card_data *data,
struct snd_pcm_hw_params *params)
{
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
if (data->convert_rate)
rate->min =
rate->max = data->convert_rate;
if (data->convert_channels)
channels->min =
channels->max = data->convert_channels;
}
void asoc_simple_card_parse_convert(struct device *dev, char *prefix,
struct asoc_simple_card_data *data)
{
struct device_node *np = dev->of_node;
char prop[128];
if (!prefix)
prefix = "";
snprintf(prop, sizeof(prop), "%s%s", prefix, "convert-rate");
of_property_read_u32(np, prop, &data->convert_rate);
snprintf(prop, sizeof(prop), "%s%s", prefix, "convert-channels");
of_property_read_u32(np, prop, &data->convert_channels);
dev_dbg(dev, "convert_rate %d\n", data->convert_rate);
dev_dbg(dev, "convert_channels %d\n", data->convert_channels);
}
int asoc_simple_card_parse_daifmt(struct device *dev,
struct device_node *node,
struct device_node *codec,
char *prefix,
unsigned int *retfmt)
{
struct device_node *bitclkmaster = NULL;
struct device_node *framemaster = NULL;
unsigned int daifmt;
daifmt = snd_soc_of_parse_daifmt(node, prefix,
&bitclkmaster, &framemaster);
daifmt &= ~SND_SOC_DAIFMT_MASTER_MASK;
if (!bitclkmaster && !framemaster) {
dev_dbg(dev, "Revert to legacy daifmt parsing\n");
daifmt = snd_soc_of_parse_daifmt(codec, NULL, NULL, NULL) |
(daifmt & ~SND_SOC_DAIFMT_CLOCK_MASK);
} else {
if (codec == bitclkmaster)
daifmt |= (codec == framemaster) ?
SND_SOC_DAIFMT_CBM_CFM : SND_SOC_DAIFMT_CBM_CFS;
else
daifmt |= (codec == framemaster) ?
SND_SOC_DAIFMT_CBS_CFM : SND_SOC_DAIFMT_CBS_CFS;
}
of_node_put(bitclkmaster);
of_node_put(framemaster);
*retfmt = daifmt;
dev_dbg(dev, "format : %04x\n", daifmt);
return 0;
}
int asoc_simple_card_set_dailink_name(struct device *dev,
struct snd_soc_dai_link *dai_link,
const char *fmt, ...)
{
va_list ap;
char *name = NULL;
int ret = -ENOMEM;
va_start(ap, fmt);
name = devm_kvasprintf(dev, GFP_KERNEL, fmt, ap);
va_end(ap);
if (name) {
ret = 0;
dai_link->name = name;
dai_link->stream_name = name;
dev_dbg(dev, "name : %s\n", name);
}
return ret;
}
int asoc_simple_card_parse_card_name(struct snd_soc_card *card,
char *prefix)
{
int ret;
if (!prefix)
prefix = "";
ret = snd_soc_of_parse_card_name(card, "label");
if (ret < 0 || !card->name) {
char prop[128];
snprintf(prop, sizeof(prop), "%sname", prefix);
ret = snd_soc_of_parse_card_name(card, prop);
if (ret < 0)
return ret;
}
if (!card->name && card->dai_link)
card->name = card->dai_link->name;
dev_dbg(card->dev, "Card Name: %s\n", card->name ? card->name : "");
return 0;
}
static void asoc_simple_card_clk_register(struct asoc_simple_dai *dai,
struct clk *clk)
{
dai->clk = clk;
}
int asoc_simple_card_clk_enable(struct asoc_simple_dai *dai)
{
return clk_prepare_enable(dai->clk);
}
void asoc_simple_card_clk_disable(struct asoc_simple_dai *dai)
{
clk_disable_unprepare(dai->clk);
}
int asoc_simple_card_parse_clk(struct device *dev,
struct device_node *node,
struct device_node *dai_of_node,
struct asoc_simple_dai *simple_dai,
const char *name)
{
struct clk *clk;
u32 val;
clk = devm_get_clk_from_child(dev, node, NULL);
if (!IS_ERR(clk)) {
simple_dai->sysclk = clk_get_rate(clk);
asoc_simple_card_clk_register(simple_dai, clk);
} else if (!of_property_read_u32(node, "system-clock-frequency", &val)) {
simple_dai->sysclk = val;
} else {
clk = devm_get_clk_from_child(dev, dai_of_node, NULL);
if (!IS_ERR(clk))
simple_dai->sysclk = clk_get_rate(clk);
}
dev_dbg(dev, "%s : sysclk = %d\n", name, simple_dai->sysclk);
return 0;
}
int asoc_simple_card_parse_dai(struct device_node *node,
struct device_node **dai_of_node,
const char **dai_name,
const char *list_name,
const char *cells_name,
int *is_single_link)
{
struct of_phandle_args args;
int ret;
if (!node)
return 0;
ret = of_parse_phandle_with_args(node, list_name, cells_name, 0, &args);
if (ret)
return ret;
if (dai_name) {
ret = snd_soc_of_get_dai_name(node, dai_name);
if (ret < 0)
return ret;
}
*dai_of_node = args.np;
if (is_single_link)
*is_single_link = !args.args_count;
return 0;
}
static int asoc_simple_card_get_dai_id(struct device_node *ep)
{
struct device_node *node;
struct device_node *endpoint;
int i, id;
int ret;
ret = snd_soc_get_dai_id(ep);
if (ret != -ENOTSUPP)
return ret;
node = of_graph_get_port_parent(ep);
i = 0;
id = -1;
for_each_endpoint_of_node(node, endpoint) {
if (endpoint == ep)
id = i;
i++;
}
of_node_put(node);
if (id < 0)
return -ENODEV;
return id;
}
int asoc_simple_card_parse_graph_dai(struct device_node *ep,
struct device_node **dai_of_node,
const char **dai_name)
{
struct device_node *node;
struct of_phandle_args args;
int ret;
if (!ep)
return 0;
if (!dai_name)
return 0;
node = of_graph_get_port_parent(ep);
args.np = node;
args.args[0] = asoc_simple_card_get_dai_id(ep);
args.args_count = (of_graph_get_endpoint_count(node) > 1);
ret = snd_soc_get_dai_name(&args, dai_name);
if (ret < 0)
return ret;
*dai_of_node = node;
return 0;
}
int asoc_simple_card_init_dai(struct snd_soc_dai *dai,
struct asoc_simple_dai *simple_dai)
{
int ret;
if (simple_dai->sysclk) {
ret = snd_soc_dai_set_sysclk(dai, 0, simple_dai->sysclk, 0);
if (ret && ret != -ENOTSUPP) {
dev_err(dai->dev, "simple-card: set_sysclk error\n");
return ret;
}
}
if (simple_dai->slots) {
ret = snd_soc_dai_set_tdm_slot(dai,
simple_dai->tx_slot_mask,
simple_dai->rx_slot_mask,
simple_dai->slots,
simple_dai->slot_width);
if (ret && ret != -ENOTSUPP) {
dev_err(dai->dev, "simple-card: set_tdm_slot error\n");
return ret;
}
}
return 0;
}
int asoc_simple_card_canonicalize_dailink(struct snd_soc_dai_link *dai_link)
{
if (!dai_link->platform_of_node)
dai_link->platform_of_node = dai_link->cpu_of_node;
return 0;
}
void asoc_simple_card_canonicalize_cpu(struct snd_soc_dai_link *dai_link,
int is_single_links)
{
if (is_single_links)
dai_link->cpu_dai_name = NULL;
}
int asoc_simple_card_clean_reference(struct snd_soc_card *card)
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
int asoc_simple_card_of_parse_routing(struct snd_soc_card *card,
char *prefix,
int optional)
{
struct device_node *node = card->dev->of_node;
char prop[128];
if (!prefix)
prefix = "";
snprintf(prop, sizeof(prop), "%s%s", prefix, "routing");
if (!of_property_read_bool(node, prop)) {
if (optional)
return 0;
return -EINVAL;
}
return snd_soc_of_parse_audio_routing(card, prop);
}
int asoc_simple_card_of_parse_widgets(struct snd_soc_card *card,
char *prefix)
{
struct device_node *node = card->dev->of_node;
char prop[128];
if (!prefix)
prefix = "";
snprintf(prop, sizeof(prop), "%s%s", prefix, "widgets");
if (of_property_read_bool(node, prop))
return snd_soc_of_parse_audio_simple_widgets(card, prop);
return 0;
}
