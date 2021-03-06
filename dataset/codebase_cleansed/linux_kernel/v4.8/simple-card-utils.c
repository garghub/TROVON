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
