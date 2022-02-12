static int ttc_pm860x_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
snd_soc_card_jack_new(rtd->card, "Headphone Jack", SND_JACK_HEADPHONE |
SND_JACK_BTN_0 | SND_JACK_BTN_1 | SND_JACK_BTN_2,
&hs_jack, hs_jack_pins, ARRAY_SIZE(hs_jack_pins));
snd_soc_card_jack_new(rtd->card, "Microphone Jack", SND_JACK_MICROPHONE,
&mic_jack, mic_jack_pins,
ARRAY_SIZE(mic_jack_pins));
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
