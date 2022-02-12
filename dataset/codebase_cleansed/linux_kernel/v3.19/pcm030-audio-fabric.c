static int pcm030_fabric_probe(struct platform_device *op)
{
struct device_node *np = op->dev.of_node;
struct device_node *platform_np;
struct snd_soc_card *card = &pcm030_card;
struct pcm030_audio_data *pdata;
int ret;
int i;
if (!of_machine_is_compatible("phytec,pcm030"))
return -ENODEV;
pdata = devm_kzalloc(&op->dev, sizeof(struct pcm030_audio_data),
GFP_KERNEL);
if (!pdata)
return -ENOMEM;
card->dev = &op->dev;
pdata->card = card;
platform_np = of_parse_phandle(np, "asoc-platform", 0);
if (!platform_np) {
dev_err(&op->dev, "ac97 not registered\n");
return -ENODEV;
}
for (i = 0; i < card->num_links; i++)
card->dai_link[i].platform_of_node = platform_np;
ret = request_module("snd-soc-wm9712");
if (ret)
dev_err(&op->dev, "request_module returned: %d\n", ret);
pdata->codec_device = platform_device_alloc("wm9712-codec", -1);
if (!pdata->codec_device)
dev_err(&op->dev, "platform_device_alloc() failed\n");
ret = platform_device_add(pdata->codec_device);
if (ret)
dev_err(&op->dev, "platform_device_add() failed: %d\n", ret);
ret = snd_soc_register_card(card);
if (ret)
dev_err(&op->dev, "snd_soc_register_card() failed: %d\n", ret);
platform_set_drvdata(op, pdata);
return ret;
}
static int pcm030_fabric_remove(struct platform_device *op)
{
struct pcm030_audio_data *pdata = platform_get_drvdata(op);
int ret;
ret = snd_soc_unregister_card(pdata->card);
platform_device_unregister(pdata->codec_device);
return ret;
}
