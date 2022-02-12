static int z2_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int clk = 0;
int ret = 0;
switch (params_rate(params)) {
case 8000:
case 16000:
case 48000:
case 96000:
clk = 12288000;
break;
case 11025:
case 22050:
case 44100:
clk = 11289600;
break;
}
ret = snd_soc_dai_set_sysclk(codec_dai, WM8750_SYSCLK, clk,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, PXA2XX_I2S_SYSCLK, 0,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
return 0;
}
static int z2_wm8750_init(struct snd_soc_pcm_runtime *rtd)
{
int ret;
ret = snd_soc_card_jack_new(rtd->card, "Headset Jack", SND_JACK_HEADSET,
&hs_jack, hs_jack_pins,
ARRAY_SIZE(hs_jack_pins));
if (ret)
goto err;
ret = snd_soc_jack_add_gpios(&hs_jack, ARRAY_SIZE(hs_jack_gpios),
hs_jack_gpios);
if (ret)
goto err;
return 0;
err:
return ret;
}
static int __init z2_init(void)
{
int ret;
if (!machine_is_zipit2())
return -ENODEV;
z2_snd_device = platform_device_alloc("soc-audio", -1);
if (!z2_snd_device)
return -ENOMEM;
platform_set_drvdata(z2_snd_device, &snd_soc_z2);
ret = platform_device_add(z2_snd_device);
if (ret)
platform_device_put(z2_snd_device);
return ret;
}
static void __exit z2_exit(void)
{
platform_device_unregister(z2_snd_device);
}
