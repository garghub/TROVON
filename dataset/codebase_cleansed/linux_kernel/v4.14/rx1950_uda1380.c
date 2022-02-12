static int rx1950_startup(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&hw_rates);
}
static int rx1950_spk_power(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
if (SND_SOC_DAPM_EVENT_ON(event))
gpio_set_value(S3C2410_GPA(1), 1);
else
gpio_set_value(S3C2410_GPA(1), 0);
return 0;
}
static int rx1950_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int div;
int ret;
unsigned int rate = params_rate(params);
int clk_source, fs_mode;
switch (rate) {
case 16000:
case 48000:
clk_source = S3C24XX_CLKSRC_PCLK;
fs_mode = S3C2410_IISMOD_256FS;
div = s3c24xx_i2s_get_clockrate() / (256 * rate);
if (s3c24xx_i2s_get_clockrate() % (256 * rate) > (128 * rate))
div++;
break;
case 44100:
case 88200:
clk_source = S3C24XX_CLKSRC_MPLL;
fs_mode = S3C2410_IISMOD_384FS;
div = 1;
break;
default:
printk(KERN_ERR "%s: rate %d is not supported\n",
__func__, rate);
return -EINVAL;
}
ret = snd_soc_dai_set_sysclk(cpu_dai, clk_source, rate,
SND_SOC_CLOCK_OUT);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, S3C24XX_DIV_MCLK,
fs_mode);
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
static int rx1950_uda1380_init(struct snd_soc_pcm_runtime *rtd)
{
snd_soc_card_jack_new(rtd->card, "Headphone Jack", SND_JACK_HEADPHONE,
&hp_jack, hp_jack_pins, ARRAY_SIZE(hp_jack_pins));
snd_soc_jack_add_gpios(&hp_jack, ARRAY_SIZE(hp_jack_gpios),
hp_jack_gpios);
return 0;
}
static int __init rx1950_init(void)
{
int ret;
if (!machine_is_rx1950())
return -ENODEV;
ret = gpio_request(S3C2410_GPA(1), "speaker-power");
if (ret)
goto err_gpio;
ret = gpio_direction_output(S3C2410_GPA(1), 0);
if (ret)
goto err_gpio_conf;
s3c24xx_snd_device = platform_device_alloc("soc-audio", -1);
if (!s3c24xx_snd_device) {
ret = -ENOMEM;
goto err_plat_alloc;
}
platform_set_drvdata(s3c24xx_snd_device, &rx1950_asoc);
ret = platform_device_add(s3c24xx_snd_device);
if (ret) {
platform_device_put(s3c24xx_snd_device);
goto err_plat_add;
}
return 0;
err_plat_add:
err_plat_alloc:
err_gpio_conf:
gpio_free(S3C2410_GPA(1));
err_gpio:
return ret;
}
static void __exit rx1950_exit(void)
{
platform_device_unregister(s3c24xx_snd_device);
gpio_free(S3C2410_GPA(1));
}
