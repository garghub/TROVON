static unsigned long siumckb_recalc(struct clk *clk)
{
return codec_freq;
}
static int migor_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
unsigned int rate = params_rate(params);
ret = snd_soc_dai_set_sysclk(codec_dai, WM8978_PLL, 13000000,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(codec_dai, WM8978_OPCLKRATE, rate * 512);
if (ret < 0)
return ret;
codec_freq = rate * 512;
clk_set_rate(&siumckb_clk, codec_freq);
dev_dbg(codec_dai->dev, "%s: configure %luHz\n", __func__, codec_freq);
ret = snd_soc_dai_set_sysclk(rtd->cpu_dai, SIU_CLKB_EXT,
codec_freq / 2, SND_SOC_CLOCK_IN);
if (!ret)
use_count++;
return ret;
}
static int migor_hw_free(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
if (use_count) {
use_count--;
if (!use_count)
snd_soc_dai_set_sysclk(codec_dai, WM8978_PLL, 0,
SND_SOC_CLOCK_IN);
} else {
dev_dbg(codec_dai->dev, "Unbalanced hw_free!\n");
}
return 0;
}
static int __init migor_init(void)
{
int ret;
ret = clk_register(&siumckb_clk);
if (ret < 0)
return ret;
siumckb_lookup = clkdev_alloc(&siumckb_clk, "siumckb_clk", NULL);
if (!siumckb_lookup) {
ret = -ENOMEM;
goto eclkdevalloc;
}
clkdev_add(siumckb_lookup);
migor_snd_device = platform_device_alloc("soc-audio", 1);
if (!migor_snd_device) {
ret = -ENOMEM;
goto epdevalloc;
}
platform_set_drvdata(migor_snd_device, &snd_soc_migor);
ret = platform_device_add(migor_snd_device);
if (ret)
goto epdevadd;
return 0;
epdevadd:
platform_device_put(migor_snd_device);
epdevalloc:
clkdev_drop(siumckb_lookup);
eclkdevalloc:
clk_unregister(&siumckb_clk);
return ret;
}
static void __exit migor_exit(void)
{
clkdev_drop(siumckb_lookup);
clk_unregister(&siumckb_clk);
platform_device_unregister(migor_snd_device);
}
