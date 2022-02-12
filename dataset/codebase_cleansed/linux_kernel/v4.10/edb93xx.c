static int edb93xx_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int err;
unsigned int mclk_rate;
unsigned int rate = params_rate(params);
if (rate < 50000)
mclk_rate = rate * 64 * 4;
else
mclk_rate = rate * 64 * 2;
err = snd_soc_dai_set_sysclk(codec_dai, 0, mclk_rate,
SND_SOC_CLOCK_IN);
if (err)
return err;
return snd_soc_dai_set_sysclk(cpu_dai, 0, mclk_rate,
SND_SOC_CLOCK_OUT);
}
static int edb93xx_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &snd_soc_edb93xx;
int ret;
ret = ep93xx_i2s_acquire();
if (ret)
return ret;
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
ep93xx_i2s_release();
}
return ret;
}
static int edb93xx_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
ep93xx_i2s_release();
return 0;
}
