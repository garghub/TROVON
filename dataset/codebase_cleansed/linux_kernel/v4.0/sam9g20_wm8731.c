static int at91sam9g20ek_set_bias_level(struct snd_soc_card *card,
struct snd_soc_dapm_context *dapm,
enum snd_soc_bias_level level)
{
static int mclk_on;
int ret = 0;
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
if (!mclk_on)
ret = clk_enable(mclk);
if (ret == 0)
mclk_on = 1;
break;
case SND_SOC_BIAS_OFF:
case SND_SOC_BIAS_STANDBY:
if (mclk_on)
clk_disable(mclk);
mclk_on = 0;
break;
}
return ret;
}
static int at91sam9g20ek_wm8731_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
printk(KERN_DEBUG
"at91sam9g20ek_wm8731 "
": at91sam9g20ek_wm8731_init() called\n");
ret = snd_soc_dai_set_sysclk(codec_dai, WM8731_SYSCLK_MCLK,
MCLK_RATE, SND_SOC_CLOCK_IN);
if (ret < 0) {
printk(KERN_ERR "Failed to set WM8731 SYSCLK: %d\n", ret);
return ret;
}
snd_soc_dapm_nc_pin(dapm, "RLINEIN");
snd_soc_dapm_nc_pin(dapm, "LLINEIN");
#ifndef ENABLE_MIC_INPUT
snd_soc_dapm_nc_pin(&rtd->card->dapm, "Int Mic");
#endif
return 0;
}
static int at91sam9g20ek_audio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *codec_np, *cpu_np;
struct clk *pllb;
struct snd_soc_card *card = &snd_soc_at91sam9g20ek;
int ret;
if (!np) {
return -ENODEV;
}
ret = atmel_ssc_set_audio(0);
if (ret) {
dev_err(&pdev->dev, "ssc channel is not valid\n");
return -EINVAL;
}
mclk = clk_get(NULL, "pck0");
if (IS_ERR(mclk)) {
printk(KERN_ERR "ASoC: Failed to get MCLK\n");
ret = PTR_ERR(mclk);
goto err;
}
pllb = clk_get(NULL, "pllb");
if (IS_ERR(pllb)) {
printk(KERN_ERR "ASoC: Failed to get PLLB\n");
ret = PTR_ERR(pllb);
goto err_mclk;
}
ret = clk_set_parent(mclk, pllb);
clk_put(pllb);
if (ret != 0) {
printk(KERN_ERR "ASoC: Failed to set MCLK parent\n");
goto err_mclk;
}
clk_set_rate(mclk, MCLK_RATE);
card->dev = &pdev->dev;
ret = snd_soc_of_parse_card_name(card, "atmel,model");
if (ret)
goto err;
ret = snd_soc_of_parse_audio_routing(card,
"atmel,audio-routing");
if (ret)
goto err;
at91sam9g20ek_dai.codec_name = NULL;
codec_np = of_parse_phandle(np, "atmel,audio-codec", 0);
if (!codec_np) {
dev_err(&pdev->dev, "codec info missing\n");
return -EINVAL;
}
at91sam9g20ek_dai.codec_of_node = codec_np;
at91sam9g20ek_dai.cpu_dai_name = NULL;
at91sam9g20ek_dai.platform_name = NULL;
cpu_np = of_parse_phandle(np, "atmel,ssc-controller", 0);
if (!cpu_np) {
dev_err(&pdev->dev, "dai and pcm info missing\n");
return -EINVAL;
}
at91sam9g20ek_dai.cpu_of_node = cpu_np;
at91sam9g20ek_dai.platform_of_node = cpu_np;
of_node_put(codec_np);
of_node_put(cpu_np);
ret = snd_soc_register_card(card);
if (ret) {
printk(KERN_ERR "ASoC: snd_soc_register_card() failed\n");
}
return ret;
err_mclk:
clk_put(mclk);
mclk = NULL;
err:
atmel_ssc_put_audio(0);
return ret;
}
static int at91sam9g20ek_audio_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
clk_disable(mclk);
mclk = NULL;
snd_soc_unregister_card(card);
atmel_ssc_put_audio(0);
return 0;
}
