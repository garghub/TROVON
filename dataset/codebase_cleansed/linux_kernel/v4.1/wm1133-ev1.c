static int wm1133_ev1_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int i, found = 0;
snd_pcm_format_t format = params_format(params);
unsigned int rate = params_rate(params);
unsigned int channels = params_channels(params);
for (i = 0; i < ARRAY_SIZE(wm8350_audio); i++) {
if (rate == wm8350_audio[i].rate &&
format == wm8350_audio[i].format &&
channels == wm8350_audio[i].channels) {
found = 1;
break;
}
}
if (!found)
return -EINVAL;
snd_soc_dai_set_pll(codec_dai, 0, 0, 14750000, wm8350_audio[i].sysclk);
switch (channels) {
case 2:
snd_soc_dai_set_tdm_slot(cpu_dai, 0x3, 0x3, 2, 0);
break;
case 1:
snd_soc_dai_set_tdm_slot(cpu_dai, 0x1, 0x1, 1, 0);
break;
default:
return -EINVAL;
}
snd_soc_dai_set_sysclk(codec_dai, WM8350_MCLK_SEL_PLL_MCLK,
wm8350_audio[i].sysclk, SND_SOC_CLOCK_IN);
snd_soc_dai_set_clkdiv(codec_dai, WM8350_BCLK_CLKDIV,
wm8350_audio[i].bclkdiv);
snd_soc_dai_set_clkdiv(codec_dai,
WM8350_DACLR_CLKDIV, wm8350_audio[i].lr_rate);
snd_soc_dai_set_clkdiv(codec_dai,
WM8350_ADCLR_CLKDIV, wm8350_audio[i].lr_rate);
snd_soc_dai_set_clkdiv(codec_dai,
WM8350_DAC_CLKDIV, wm8350_audio[i].clkdiv);
snd_soc_dai_set_clkdiv(codec_dai,
WM8350_ADC_CLKDIV, wm8350_audio[i].clkdiv);
return 0;
}
static int wm1133_ev1_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
snd_soc_card_jack_new(rtd->card, "Headphone", SND_JACK_HEADPHONE,
&hp_jack, hp_jack_pins, ARRAY_SIZE(hp_jack_pins));
wm8350_hp_jack_detect(codec, WM8350_JDR, &hp_jack, SND_JACK_HEADPHONE);
snd_soc_card_jack_new(rtd->card, "Microphone",
SND_JACK_MICROPHONE | SND_JACK_BTN_0, &mic_jack,
mic_jack_pins, ARRAY_SIZE(mic_jack_pins));
wm8350_mic_jack_detect(codec, &mic_jack, SND_JACK_MICROPHONE,
SND_JACK_BTN_0);
snd_soc_dapm_force_enable_pin(&rtd->card->dapm, "Mic Bias");
return 0;
}
static int __init wm1133_ev1_audio_init(void)
{
int ret;
unsigned int ptcr, pdcr;
ptcr = IMX_AUDMUX_V2_PTCR_SYN |
IMX_AUDMUX_V2_PTCR_TFSDIR |
IMX_AUDMUX_V2_PTCR_TFSEL(MX31_AUDMUX_PORT5_SSI_PINS_5) |
IMX_AUDMUX_V2_PTCR_TCLKDIR |
IMX_AUDMUX_V2_PTCR_TCSEL(MX31_AUDMUX_PORT5_SSI_PINS_5);
pdcr = IMX_AUDMUX_V2_PDCR_RXDSEL(MX31_AUDMUX_PORT5_SSI_PINS_5);
imx_audmux_v2_configure_port(MX31_AUDMUX_PORT1_SSI0, ptcr, pdcr);
ptcr = IMX_AUDMUX_V2_PTCR_SYN;
pdcr = IMX_AUDMUX_V2_PDCR_RXDSEL(MX31_AUDMUX_PORT1_SSI0);
imx_audmux_v2_configure_port(MX31_AUDMUX_PORT5_SSI_PINS_5, ptcr, pdcr);
wm1133_ev1_snd_device = platform_device_alloc("soc-audio", -1);
if (!wm1133_ev1_snd_device)
return -ENOMEM;
platform_set_drvdata(wm1133_ev1_snd_device, &wm1133_ev1);
ret = platform_device_add(wm1133_ev1_snd_device);
if (ret)
platform_device_put(wm1133_ev1_snd_device);
return ret;
}
static void __exit wm1133_ev1_audio_exit(void)
{
platform_device_unregister(wm1133_ev1_snd_device);
}
