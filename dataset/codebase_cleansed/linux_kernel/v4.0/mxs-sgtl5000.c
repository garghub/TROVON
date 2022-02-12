static int mxs_sgtl5000_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int rate = params_rate(params);
u32 mclk;
int ret;
switch (rate) {
case 96000:
mclk = 256 * rate;
break;
default:
mclk = 512 * rate;
break;
}
ret = snd_soc_dai_set_sysclk(codec_dai, SGTL5000_SYSCLK, mclk, 0);
if (ret) {
dev_err(codec_dai->dev, "Failed to set sysclk to %u.%03uMHz\n",
mclk / 1000000, mclk / 1000 % 1000);
return ret;
}
ret = snd_soc_dai_set_sysclk(cpu_dai, MXS_SAIF_MCLK, mclk, 0);
if (ret) {
dev_err(cpu_dai->dev, "Failed to set sysclk to %u.%03uMHz\n",
mclk / 1000000, mclk / 1000 % 1000);
return ret;
}
return 0;
}
static int mxs_sgtl5000_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &mxs_sgtl5000;
int ret, i;
struct device_node *np = pdev->dev.of_node;
struct device_node *saif_np[2], *codec_np;
saif_np[0] = of_parse_phandle(np, "saif-controllers", 0);
saif_np[1] = of_parse_phandle(np, "saif-controllers", 1);
codec_np = of_parse_phandle(np, "audio-codec", 0);
if (!saif_np[0] || !saif_np[1] || !codec_np) {
dev_err(&pdev->dev, "phandle missing or invalid\n");
return -EINVAL;
}
for (i = 0; i < 2; i++) {
mxs_sgtl5000_dai[i].codec_name = NULL;
mxs_sgtl5000_dai[i].codec_of_node = codec_np;
mxs_sgtl5000_dai[i].cpu_dai_name = NULL;
mxs_sgtl5000_dai[i].cpu_of_node = saif_np[i];
mxs_sgtl5000_dai[i].platform_name = NULL;
mxs_sgtl5000_dai[i].platform_of_node = saif_np[i];
}
of_node_put(codec_np);
of_node_put(saif_np[0]);
of_node_put(saif_np[1]);
ret = mxs_saif_get_mclk(0, 44100 * 256, 44100);
if (ret) {
dev_err(&pdev->dev, "failed to get mclk\n");
return ret;
}
card->dev = &pdev->dev;
platform_set_drvdata(pdev, card);
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n",
ret);
return ret;
}
return 0;
}
static int mxs_sgtl5000_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
mxs_saif_put_mclk(0);
snd_soc_unregister_card(card);
return 0;
}
