static int ttc_pm860x_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_enable_pin(dapm, "Ext Speaker");
snd_soc_dapm_enable_pin(dapm, "Ext Mic 1");
snd_soc_dapm_enable_pin(dapm, "Ext Mic 3");
snd_soc_dapm_disable_pin(dapm, "Headset Mic 2");
snd_soc_dapm_disable_pin(dapm, "Headset Stereophone");
snd_soc_jack_new(codec, "Headphone Jack", SND_JACK_HEADPHONE
| SND_JACK_BTN_0 | SND_JACK_BTN_1 | SND_JACK_BTN_2,
&hs_jack);
snd_soc_jack_add_pins(&hs_jack, ARRAY_SIZE(hs_jack_pins),
hs_jack_pins);
snd_soc_jack_new(codec, "Microphone Jack", SND_JACK_MICROPHONE,
&mic_jack);
snd_soc_jack_add_pins(&mic_jack, ARRAY_SIZE(mic_jack_pins),
mic_jack_pins);
pm860x_hs_jack_detect(codec, &hs_jack, SND_JACK_HEADPHONE,
SND_JACK_BTN_0, SND_JACK_BTN_1, SND_JACK_BTN_2);
pm860x_mic_jack_detect(codec, &hs_jack, SND_JACK_MICROPHONE);
return 0;
}
static int ttc_dkb_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &ttc_dkb_card;
int ret;
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret)
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
return ret;
}
static int ttc_dkb_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
