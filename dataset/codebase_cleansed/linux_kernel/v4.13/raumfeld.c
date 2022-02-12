static void set_max9485_clk(char clk)
{
i2c_master_send(max9486_client, &clk, 1);
}
static void raumfeld_enable_audio(bool en)
{
if (en) {
gpio_set_value(GPIO_MCLK_RESET, 1);
msleep(100);
gpio_set_value(GPIO_SPDIF_RESET, 1);
gpio_set_value(GPIO_CODEC_RESET, 1);
} else {
gpio_set_value(GPIO_MCLK_RESET, 0);
gpio_set_value(GPIO_SPDIF_RESET, 0);
gpio_set_value(GPIO_CODEC_RESET, 0);
}
}
static int raumfeld_cs4270_startup(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
return snd_soc_dai_set_sysclk(codec_dai, 0, 0, 0);
}
static void raumfeld_cs4270_shutdown(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
snd_soc_dai_set_sysclk(codec_dai, 0, 0, 0);
}
static int raumfeld_cs4270_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int clk = 0;
int ret = 0;
switch (params_rate(params)) {
case 44100:
set_max9485_clk(MAX9485_MCLK_FREQ_112896);
clk = 11289600;
break;
case 48000:
set_max9485_clk(MAX9485_MCLK_FREQ_122880);
clk = 12288000;
break;
case 88200:
set_max9485_clk(MAX9485_MCLK_FREQ_225792);
clk = 22579200;
break;
case 96000:
set_max9485_clk(MAX9485_MCLK_FREQ_245760);
clk = 24576000;
break;
default:
return -EINVAL;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0, clk, 0);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_pll(cpu_dai, 0, 0, 0, clk);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, PXA_SSP_DIV_SCR, 4);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, PXA_SSP_CLK_EXT, clk, 1);
if (ret < 0)
return ret;
return 0;
}
static int raumfeld_analog_suspend(struct snd_soc_card *card)
{
raumfeld_enable_audio(false);
return 0;
}
static int raumfeld_analog_resume(struct snd_soc_card *card)
{
raumfeld_enable_audio(true);
return 0;
}
static int raumfeld_ak4104_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret = 0, clk = 0;
switch (params_rate(params)) {
case 44100:
set_max9485_clk(MAX9485_MCLK_FREQ_112896);
clk = 11289600;
break;
case 48000:
set_max9485_clk(MAX9485_MCLK_FREQ_122880);
clk = 12288000;
break;
case 88200:
set_max9485_clk(MAX9485_MCLK_FREQ_225792);
clk = 22579200;
break;
case 96000:
set_max9485_clk(MAX9485_MCLK_FREQ_245760);
clk = 24576000;
break;
default:
return -EINVAL;
}
ret = snd_soc_dai_set_pll(cpu_dai, 0, 0, 0, clk);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, PXA_SSP_DIV_SCR, 4);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, PXA_SSP_CLK_EXT, clk, 1);
if (ret < 0)
return ret;
return 0;
}
static int __init raumfeld_audio_init(void)
{
int ret;
if (!machine_is_raumfeld_speaker() &&
!machine_is_raumfeld_connector())
return 0;
max9486_client = i2c_new_device(i2c_get_adapter(0),
&max9486_hwmon_info);
if (!max9486_client)
return -ENOMEM;
set_max9485_clk(MAX9485_MCLK_FREQ_122880);
raumfeld_audio_device = platform_device_alloc("soc-audio", 0);
if (!raumfeld_audio_device)
return -ENOMEM;
if (machine_is_raumfeld_speaker())
platform_set_drvdata(raumfeld_audio_device,
&snd_soc_raumfeld_speaker);
if (machine_is_raumfeld_connector())
platform_set_drvdata(raumfeld_audio_device,
&snd_soc_raumfeld_connector);
ret = platform_device_add(raumfeld_audio_device);
if (ret < 0) {
platform_device_put(raumfeld_audio_device);
return ret;
}
raumfeld_enable_audio(true);
return 0;
}
static void __exit raumfeld_audio_exit(void)
{
raumfeld_enable_audio(false);
platform_device_unregister(raumfeld_audio_device);
i2c_unregister_device(max9486_client);
gpio_free(GPIO_MCLK_RESET);
gpio_free(GPIO_CODEC_RESET);
gpio_free(GPIO_SPDIF_RESET);
}
