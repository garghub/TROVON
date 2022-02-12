static int atmel_asoc_wm8904_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_pll(codec_dai, WM8904_FLL_MCLK, WM8904_FLL_MCLK,
32768, params_rate(params) * 256);
if (ret < 0) {
pr_err("%s - failed to set wm8904 codec PLL.", __func__);
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, WM8904_CLK_FLL,
0, SND_SOC_CLOCK_IN);
if (ret < 0) {
pr_err("%s -failed to set wm8904 SYSCLK\n", __func__);
return ret;
}
return 0;
}
static int atmel_asoc_wm8904_dt_init(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *codec_np, *cpu_np;
struct snd_soc_card *card = &atmel_asoc_wm8904_card;
struct snd_soc_dai_link *dailink = &atmel_asoc_wm8904_dailink;
int ret;
if (!np) {
dev_err(&pdev->dev, "only device tree supported\n");
return -EINVAL;
}
ret = snd_soc_of_parse_card_name(card, "atmel,model");
if (ret) {
dev_err(&pdev->dev, "failed to parse card name\n");
return ret;
}
ret = snd_soc_of_parse_audio_routing(card, "atmel,audio-routing");
if (ret) {
dev_err(&pdev->dev, "failed to parse audio routing\n");
return ret;
}
cpu_np = of_parse_phandle(np, "atmel,ssc-controller", 0);
if (!cpu_np) {
dev_err(&pdev->dev, "failed to get dai and pcm info\n");
ret = -EINVAL;
return ret;
}
dailink->cpu_of_node = cpu_np;
dailink->platform_of_node = cpu_np;
of_node_put(cpu_np);
codec_np = of_parse_phandle(np, "atmel,audio-codec", 0);
if (!codec_np) {
dev_err(&pdev->dev, "failed to get codec info\n");
ret = -EINVAL;
return ret;
}
dailink->codec_of_node = codec_np;
of_node_put(codec_np);
return 0;
}
static int atmel_asoc_wm8904_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &atmel_asoc_wm8904_card;
struct snd_soc_dai_link *dailink = &atmel_asoc_wm8904_dailink;
int id, ret;
card->dev = &pdev->dev;
ret = atmel_asoc_wm8904_dt_init(pdev);
if (ret) {
dev_err(&pdev->dev, "failed to init dt info\n");
return ret;
}
id = of_alias_get_id((struct device_node *)dailink->cpu_of_node, "ssc");
ret = atmel_ssc_set_audio(id);
if (ret != 0) {
dev_err(&pdev->dev, "failed to set SSC %d for audio\n", id);
return ret;
}
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed\n");
goto err_set_audio;
}
return 0;
err_set_audio:
atmel_ssc_put_audio(id);
return ret;
}
static int atmel_asoc_wm8904_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct snd_soc_dai_link *dailink = &atmel_asoc_wm8904_dailink;
int id;
id = of_alias_get_id((struct device_node *)dailink->cpu_of_node, "ssc");
snd_soc_unregister_card(card);
atmel_ssc_put_audio(id);
return 0;
}
