static void snd_cobalt_card_free(struct snd_cobalt_card *cobsc)
{
if (cobsc == NULL)
return;
cobsc->s->alsa = NULL;
kfree(cobsc);
}
static void snd_cobalt_card_private_free(struct snd_card *sc)
{
if (sc == NULL)
return;
snd_cobalt_card_free(sc->private_data);
sc->private_data = NULL;
sc->private_free = NULL;
}
static int snd_cobalt_card_create(struct cobalt_stream *s,
struct snd_card *sc,
struct snd_cobalt_card **cobsc)
{
*cobsc = kzalloc(sizeof(struct snd_cobalt_card), GFP_KERNEL);
if (*cobsc == NULL)
return -ENOMEM;
(*cobsc)->s = s;
(*cobsc)->sc = sc;
sc->private_data = *cobsc;
sc->private_free = snd_cobalt_card_private_free;
return 0;
}
static int snd_cobalt_card_set_names(struct snd_cobalt_card *cobsc)
{
struct cobalt_stream *s = cobsc->s;
struct cobalt *cobalt = s->cobalt;
struct snd_card *sc = cobsc->sc;
strlcpy(sc->driver, "cobalt", sizeof(sc->driver));
snprintf(sc->shortname, sizeof(sc->shortname), "cobalt-%d-%d",
cobalt->instance, s->video_channel);
snprintf(sc->longname, sizeof(sc->longname),
"Cobalt %d HDMI %d",
cobalt->instance, s->video_channel);
return 0;
}
int cobalt_alsa_init(struct cobalt_stream *s)
{
struct cobalt *cobalt = s->cobalt;
struct snd_card *sc = NULL;
struct snd_cobalt_card *cobsc;
int ret;
ret = snd_card_new(&cobalt->pci_dev->dev, SNDRV_DEFAULT_IDX1,
SNDRV_DEFAULT_STR1, THIS_MODULE, 0, &sc);
if (ret) {
cobalt_err("snd_card_new() failed with err %d\n", ret);
goto err_exit;
}
ret = snd_cobalt_card_create(s, sc, &cobsc);
if (ret) {
cobalt_err("snd_cobalt_card_create() failed with err %d\n",
ret);
goto err_exit_free;
}
snd_cobalt_card_set_names(cobsc);
ret = snd_cobalt_pcm_create(cobsc);
if (ret) {
cobalt_err("snd_cobalt_pcm_create() failed with err %d\n",
ret);
goto err_exit_free;
}
s->alsa = cobsc;
ret = snd_card_register(sc);
if (ret) {
s->alsa = NULL;
cobalt_err("snd_card_register() failed with err %d\n", ret);
goto err_exit_free;
}
return 0;
err_exit_free:
if (sc != NULL)
snd_card_free(sc);
kfree(cobsc);
err_exit:
return ret;
}
void cobalt_alsa_exit(struct cobalt_stream *s)
{
struct snd_cobalt_card *cobsc = s->alsa;
if (cobsc)
snd_card_free(cobsc->sc);
s->alsa = NULL;
}
