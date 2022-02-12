static int at91sam9g20ek_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret;
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
return 0;
}
static int at91sam9g20ek_set_bias_level(struct snd_soc_card *card,
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
snd_soc_dapm_new_controls(dapm, at91sam9g20ek_dapm_widgets,
ARRAY_SIZE(at91sam9g20ek_dapm_widgets));
snd_soc_dapm_add_routes(dapm, intercon, ARRAY_SIZE(intercon));
snd_soc_dapm_nc_pin(dapm, "RLINEIN");
snd_soc_dapm_nc_pin(dapm, "LLINEIN");
#ifdef ENABLE_MIC_INPUT
snd_soc_dapm_enable_pin(dapm, "Int Mic");
#else
snd_soc_dapm_nc_pin(dapm, "Int Mic");
#endif
snd_soc_dapm_enable_pin(dapm, "Ext Spk");
snd_soc_dapm_sync(dapm);
return 0;
}
static int __init at91sam9g20ek_init(void)
{
struct clk *pllb;
int ret;
if (!(machine_is_at91sam9g20ek() || machine_is_at91sam9g20ek_2mmc()))
return -ENODEV;
ret = atmel_ssc_set_audio(0);
if (ret != 0) {
pr_err("Failed to set SSC 0 for audio: %d\n", ret);
return ret;
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
at91sam9g20ek_snd_device = platform_device_alloc("soc-audio", -1);
if (!at91sam9g20ek_snd_device) {
printk(KERN_ERR "ASoC: Platform device allocation failed\n");
ret = -ENOMEM;
goto err_mclk;
}
platform_set_drvdata(at91sam9g20ek_snd_device,
&snd_soc_at91sam9g20ek);
ret = platform_device_add(at91sam9g20ek_snd_device);
if (ret) {
printk(KERN_ERR "ASoC: Platform device allocation failed\n");
goto err_device_add;
}
return ret;
err_device_add:
platform_device_put(at91sam9g20ek_snd_device);
err_mclk:
clk_put(mclk);
mclk = NULL;
err:
return ret;
}
static void __exit at91sam9g20ek_exit(void)
{
platform_device_unregister(at91sam9g20ek_snd_device);
at91sam9g20ek_snd_device = NULL;
clk_put(mclk);
mclk = NULL;
}
