int asoc_simple_card_parse_daifmt(struct device *dev,
struct device_node *node,
struct device_node *codec,
char *prefix,
unsigned int *retfmt)
{
struct device_node *bitclkmaster = NULL;
struct device_node *framemaster = NULL;
int prefix_len = prefix ? strlen(prefix) : 0;
unsigned int daifmt;
daifmt = snd_soc_of_parse_daifmt(node, prefix,
&bitclkmaster, &framemaster);
daifmt &= ~SND_SOC_DAIFMT_MASTER_MASK;
if (prefix_len && !bitclkmaster && !framemaster) {
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
}
return ret;
}
int asoc_simple_card_parse_card_name(struct snd_soc_card *card,
char *prefix)
{
char prop[128];
int ret;
snprintf(prop, sizeof(prop), "%sname", prefix);
ret = snd_soc_of_parse_card_name(card, prop);
if (ret < 0)
return ret;
if (!card->name && card->dai_link)
card->name = card->dai_link->name;
return 0;
}
int asoc_simple_card_parse_clk(struct device_node *node,
struct device_node *dai_of_node,
struct asoc_simple_dai *simple_dai)
{
struct clk *clk;
u32 val;
clk = of_clk_get(node, 0);
if (!IS_ERR(clk)) {
simple_dai->sysclk = clk_get_rate(clk);
simple_dai->clk = clk;
} else if (!of_property_read_u32(node, "system-clock-frequency", &val)) {
simple_dai->sysclk = val;
} else {
clk = of_clk_get(dai_of_node, 0);
if (!IS_ERR(clk))
simple_dai->sysclk = clk_get_rate(clk);
}
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
