static int apq8016_sbc_dai_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_card *card = rtd->card;
struct apq8016_sbc_data *pdata = snd_soc_card_get_drvdata(card);
int rval = 0;
switch (cpu_dai->id) {
case MI2S_PRIMARY:
writel(readl(pdata->spkr_iomux) | SPKR_CTL_PRI_WS_SLAVE_SEL_11,
pdata->spkr_iomux);
break;
case MI2S_QUATERNARY:
writel(readl(pdata->mic_iomux) | MIC_CTRL_QUA_WS_SLAVE_SEL_10 |
MIC_CTRL_TLMM_SCLK_EN,
pdata->mic_iomux);
break;
case MI2S_TERTIARY:
writel(readl(pdata->mic_iomux) | MIC_CTRL_TER_WS_SLAVE_SEL |
MIC_CTRL_TLMM_SCLK_EN,
pdata->mic_iomux);
break;
default:
dev_err(card->dev, "unsupported cpu dai configuration\n");
rval = -EINVAL;
break;
}
return rval;
}
static struct apq8016_sbc_data *apq8016_sbc_parse_of(struct snd_soc_card *card)
{
struct device *dev = card->dev;
struct snd_soc_dai_link *link;
struct device_node *np, *codec, *cpu, *node = dev->of_node;
struct apq8016_sbc_data *data;
int ret, num_links;
ret = snd_soc_of_parse_card_name(card, "qcom,model");
if (ret) {
dev_err(dev, "Error parsing card name: %d\n", ret);
return ERR_PTR(ret);
}
if (of_property_read_bool(node, "qcom,audio-routing")) {
ret = snd_soc_of_parse_audio_routing(card,
"qcom,audio-routing");
if (ret)
return ERR_PTR(ret);
}
num_links = of_get_child_count(node);
data = devm_kzalloc(dev, sizeof(*data) + sizeof(*link) * num_links,
GFP_KERNEL);
if (!data)
return ERR_PTR(-ENOMEM);
card->dai_link = &data->dai_link[0];
card->num_links = num_links;
link = data->dai_link;
for_each_child_of_node(node, np) {
cpu = of_get_child_by_name(np, "cpu");
codec = of_get_child_by_name(np, "codec");
if (!cpu || !codec) {
dev_err(dev, "Can't find cpu/codec DT node\n");
return ERR_PTR(-EINVAL);
}
link->cpu_of_node = of_parse_phandle(cpu, "sound-dai", 0);
if (!link->cpu_of_node) {
dev_err(card->dev, "error getting cpu phandle\n");
return ERR_PTR(-EINVAL);
}
ret = snd_soc_of_get_dai_name(cpu, &link->cpu_dai_name);
if (ret) {
dev_err(card->dev, "error getting cpu dai name\n");
return ERR_PTR(ret);
}
ret = snd_soc_of_get_dai_link_codecs(dev, codec, link);
if (ret < 0) {
dev_err(card->dev, "error getting codec dai name\n");
return ERR_PTR(ret);
}
link->platform_of_node = link->cpu_of_node;
ret = of_property_read_string(np, "link-name", &link->name);
if (ret) {
dev_err(card->dev, "error getting codec dai_link name\n");
return ERR_PTR(ret);
}
link->stream_name = link->name;
link->init = apq8016_sbc_dai_init;
link++;
}
return data;
}
static int apq8016_sbc_platform_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct snd_soc_card *card;
struct apq8016_sbc_data *data;
struct resource *res;
card = devm_kzalloc(dev, sizeof(*card), GFP_KERNEL);
if (!card)
return -ENOMEM;
card->dev = dev;
card->dapm_widgets = apq8016_sbc_dapm_widgets;
card->num_dapm_widgets = ARRAY_SIZE(apq8016_sbc_dapm_widgets);
data = apq8016_sbc_parse_of(card);
if (IS_ERR(data)) {
dev_err(&pdev->dev, "Error resolving dai links: %ld\n",
PTR_ERR(data));
return PTR_ERR(data);
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "mic-iomux");
data->mic_iomux = devm_ioremap_resource(dev, res);
if (IS_ERR(data->mic_iomux))
return PTR_ERR(data->mic_iomux);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "spkr-iomux");
data->spkr_iomux = devm_ioremap_resource(dev, res);
if (IS_ERR(data->spkr_iomux))
return PTR_ERR(data->spkr_iomux);
platform_set_drvdata(pdev, data);
snd_soc_card_set_drvdata(card, data);
return devm_snd_soc_register_card(&pdev->dev, card);
}
