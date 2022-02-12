static void mop500_of_node_put(void)
{
int i;
for (i = 0; i < 2; i++) {
of_node_put(mop500_dai_links[i].cpu_of_node);
of_node_put(mop500_dai_links[i].codec_of_node);
}
}
static int mop500_of_probe(struct platform_device *pdev,
struct device_node *np)
{
struct device_node *codec_np, *msp_np[2];
int i;
msp_np[0] = of_parse_phandle(np, "stericsson,cpu-dai", 0);
msp_np[1] = of_parse_phandle(np, "stericsson,cpu-dai", 1);
codec_np = of_parse_phandle(np, "stericsson,audio-codec", 0);
if (!(msp_np[0] && msp_np[1] && codec_np)) {
dev_err(&pdev->dev, "Phandle missing or invalid\n");
mop500_of_node_put();
return -EINVAL;
}
for (i = 0; i < 2; i++) {
mop500_dai_links[i].cpu_of_node = msp_np[i];
mop500_dai_links[i].cpu_dai_name = NULL;
mop500_dai_links[i].platform_of_node = msp_np[i];
mop500_dai_links[i].platform_name = NULL;
mop500_dai_links[i].codec_of_node = codec_np;
mop500_dai_links[i].codec_name = NULL;
}
snd_soc_of_parse_card_name(&mop500_card, "stericsson,card-name");
return 0;
}
static int mop500_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
int ret;
dev_dbg(&pdev->dev, "%s: Enter.\n", __func__);
mop500_card.dev = &pdev->dev;
if (np) {
ret = mop500_of_probe(pdev, np);
if (ret)
return ret;
}
dev_dbg(&pdev->dev, "%s: Card %s: Set platform drvdata.\n",
__func__, mop500_card.name);
snd_soc_card_set_drvdata(&mop500_card, NULL);
dev_dbg(&pdev->dev, "%s: Card %s: num_links = %d\n",
__func__, mop500_card.name, mop500_card.num_links);
dev_dbg(&pdev->dev, "%s: Card %s: DAI-link 0: name = %s\n",
__func__, mop500_card.name, mop500_card.dai_link[0].name);
dev_dbg(&pdev->dev, "%s: Card %s: DAI-link 0: stream_name = %s\n",
__func__, mop500_card.name,
mop500_card.dai_link[0].stream_name);
ret = snd_soc_register_card(&mop500_card);
if (ret)
dev_err(&pdev->dev,
"Error: snd_soc_register_card failed (%d)!\n", ret);
return ret;
}
static int mop500_remove(struct platform_device *pdev)
{
struct snd_soc_card *mop500_card = platform_get_drvdata(pdev);
pr_debug("%s: Enter.\n", __func__);
snd_soc_unregister_card(mop500_card);
mop500_ab8500_remove(mop500_card);
mop500_of_node_put();
return 0;
}
