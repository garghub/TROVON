static int bf5xx_ad1836_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int channel_map[] = {0, 4, 1, 5, 2, 6, 3, 7};
int ret = 0;
ret = snd_soc_dai_set_channel_map(cpu_dai, ARRAY_SIZE(channel_map),
channel_map, ARRAY_SIZE(channel_map), channel_map);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_tdm_slot(cpu_dai, 0xFF, 0xFF, 8, 32);
if (ret < 0)
return ret;
return 0;
}
static int bf5xx_ad1836_driver_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &bf5xx_ad1836;
const char **link_name;
int ret;
link_name = pdev->dev.platform_data;
if (!link_name) {
dev_err(&pdev->dev, "No platform data supplied\n");
return -EINVAL;
}
bf5xx_ad1836_dai.cpu_dai_name = link_name[0];
bf5xx_ad1836_dai.codec_name = link_name[1];
card->dev = &pdev->dev;
platform_set_drvdata(pdev, card);
ret = snd_soc_register_card(card);
if (ret)
dev_err(&pdev->dev, "Failed to register card\n");
return ret;
}
static int bf5xx_ad1836_driver_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
