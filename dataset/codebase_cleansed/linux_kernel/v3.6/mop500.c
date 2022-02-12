static int __devinit mop500_probe(struct platform_device *pdev)
{
int ret;
pr_debug("%s: Enter.\n", __func__);
dev_dbg(&pdev->dev, "%s: Enter.\n", __func__);
mop500_card.dev = &pdev->dev;
dev_dbg(&pdev->dev, "%s: Card %s: Set platform drvdata.\n",
__func__, mop500_card.name);
platform_set_drvdata(pdev, &mop500_card);
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
"Error: snd_soc_register_card failed (%d)!\n",
ret);
return ret;
}
static int __devexit mop500_remove(struct platform_device *pdev)
{
struct snd_soc_card *mop500_card = platform_get_drvdata(pdev);
pr_debug("%s: Enter.\n", __func__);
snd_soc_unregister_card(mop500_card);
mop500_ab8500_remove(mop500_card);
return 0;
}
