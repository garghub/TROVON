static int h1940_startup(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&hw_rates);
}
static int h1940_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int div;
int ret;
unsigned int rate = params_rate(params);
switch (rate) {
case 11025:
case 22050:
case 44100:
div = s3c24xx_i2s_get_clockrate() / (384 * rate);
if (s3c24xx_i2s_get_clockrate() % (384 * rate) > (192 * rate))
div++;
break;
default:
dev_err(rtd->dev, "%s: rate %d is not supported\n",
__func__, rate);
return -EINVAL;
}
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBS_CFS);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBS_CFS);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, S3C24XX_CLKSRC_PCLK, rate,
SND_SOC_CLOCK_OUT);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, S3C24XX_DIV_MCLK,
S3C2410_IISMOD_384FS);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, S3C24XX_DIV_BCLK,
S3C2410_IISMOD_32FS);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, S3C24XX_DIV_PRESCALER,
S3C24XX_PRESCALE(div, div));
if (ret < 0)
return ret;
return 0;
}
static int h1940_spk_power(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
if (SND_SOC_DAPM_EVENT_ON(event))
gpio_set_value(S3C_GPIO_END + 9, 1);
else
gpio_set_value(S3C_GPIO_END + 9, 0);
return 0;
}
static int h1940_uda1380_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_enable_pin(dapm, "Headphone Jack");
snd_soc_dapm_enable_pin(dapm, "Speaker");
snd_soc_dapm_enable_pin(dapm, "Mic Jack");
snd_soc_jack_new(codec, "Headphone Jack", SND_JACK_HEADPHONE,
&hp_jack);
snd_soc_jack_add_pins(&hp_jack, ARRAY_SIZE(hp_jack_pins),
hp_jack_pins);
snd_soc_jack_add_gpios(&hp_jack, ARRAY_SIZE(hp_jack_gpios),
hp_jack_gpios);
return 0;
}
static int __init h1940_init(void)
{
int ret;
if (!machine_is_h1940())
return -ENODEV;
ret = gpio_request(S3C_GPIO_END + 9, "speaker-power");
if (ret)
goto err_out;
ret = gpio_direction_output(S3C_GPIO_END + 9, 0);
if (ret)
goto err_gpio;
s3c24xx_snd_device = platform_device_alloc("soc-audio", -1);
if (!s3c24xx_snd_device) {
ret = -ENOMEM;
goto err_gpio;
}
platform_set_drvdata(s3c24xx_snd_device, &h1940_asoc);
ret = platform_device_add(s3c24xx_snd_device);
if (ret)
goto err_plat;
return 0;
err_plat:
platform_device_put(s3c24xx_snd_device);
err_gpio:
gpio_free(S3C_GPIO_END + 9);
err_out:
return ret;
}
static void __exit h1940_exit(void)
{
platform_device_unregister(s3c24xx_snd_device);
snd_soc_jack_free_gpios(&hp_jack, ARRAY_SIZE(hp_jack_gpios),
hp_jack_gpios);
gpio_free(S3C_GPIO_END + 9);
}
