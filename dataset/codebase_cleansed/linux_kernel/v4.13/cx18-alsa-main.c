static inline
struct snd_cx18_card *to_snd_cx18_card(struct v4l2_device *v4l2_dev)
{
return to_cx18(v4l2_dev)->alsa;
}
static inline
struct snd_cx18_card *p_to_snd_cx18_card(struct v4l2_device **v4l2_dev)
{
return container_of(v4l2_dev, struct snd_cx18_card, v4l2_dev);
}
static void snd_cx18_card_free(struct snd_cx18_card *cxsc)
{
if (cxsc == NULL)
return;
if (cxsc->v4l2_dev != NULL)
to_cx18(cxsc->v4l2_dev)->alsa = NULL;
kfree(cxsc);
}
static void snd_cx18_card_private_free(struct snd_card *sc)
{
if (sc == NULL)
return;
snd_cx18_card_free(sc->private_data);
sc->private_data = NULL;
sc->private_free = NULL;
}
static int snd_cx18_card_create(struct v4l2_device *v4l2_dev,
struct snd_card *sc,
struct snd_cx18_card **cxsc)
{
*cxsc = kzalloc(sizeof(struct snd_cx18_card), GFP_KERNEL);
if (*cxsc == NULL)
return -ENOMEM;
(*cxsc)->v4l2_dev = v4l2_dev;
(*cxsc)->sc = sc;
sc->private_data = *cxsc;
sc->private_free = snd_cx18_card_private_free;
return 0;
}
static int snd_cx18_card_set_names(struct snd_cx18_card *cxsc)
{
struct cx18 *cx = to_cx18(cxsc->v4l2_dev);
struct snd_card *sc = cxsc->sc;
strlcpy(sc->driver, "CX23418", sizeof(sc->driver));
snprintf(sc->shortname, sizeof(sc->shortname), "CX18-%d",
cx->instance);
snprintf(sc->longname, sizeof(sc->longname),
"CX23418 #%d %s TV/FM Radio/Line-In Capture",
cx->instance, cx->card_name);
return 0;
}
static int snd_cx18_init(struct v4l2_device *v4l2_dev)
{
struct cx18 *cx = to_cx18(v4l2_dev);
struct snd_card *sc = NULL;
struct snd_cx18_card *cxsc;
int ret;
ret = snd_card_new(&cx->pci_dev->dev,
SNDRV_DEFAULT_IDX1,
SNDRV_DEFAULT_STR1,
THIS_MODULE, 0, &sc);
if (ret) {
CX18_ALSA_ERR("%s: snd_card_new() failed with err %d\n",
__func__, ret);
goto err_exit;
}
ret = snd_cx18_card_create(v4l2_dev, sc, &cxsc);
if (ret) {
CX18_ALSA_ERR("%s: snd_cx18_card_create() failed with err %d\n",
__func__, ret);
goto err_exit_free;
}
snd_cx18_card_set_names(cxsc);
ret = snd_cx18_pcm_create(cxsc);
if (ret) {
CX18_ALSA_ERR("%s: snd_cx18_pcm_create() failed with err %d\n",
__func__, ret);
goto err_exit_free;
}
cx->alsa = cxsc;
ret = snd_card_register(sc);
if (ret) {
cx->alsa = NULL;
CX18_ALSA_ERR("%s: snd_card_register() failed with err %d\n",
__func__, ret);
goto err_exit_free;
}
return 0;
err_exit_free:
if (sc != NULL)
snd_card_free(sc);
kfree(cxsc);
err_exit:
return ret;
}
static int cx18_alsa_load(struct cx18 *cx)
{
struct v4l2_device *v4l2_dev = &cx->v4l2_dev;
struct cx18_stream *s;
if (v4l2_dev == NULL) {
printk(KERN_ERR "cx18-alsa: %s: struct v4l2_device * is NULL\n",
__func__);
return 0;
}
cx = to_cx18(v4l2_dev);
if (cx == NULL) {
printk(KERN_ERR "cx18-alsa cx is NULL\n");
return 0;
}
s = &cx->streams[CX18_ENC_STREAM_TYPE_PCM];
if (s->video_dev.v4l2_dev == NULL) {
CX18_DEBUG_ALSA_INFO("%s: PCM stream for card is disabled - skipping\n",
__func__);
return 0;
}
if (cx->alsa != NULL) {
CX18_ALSA_ERR("%s: struct snd_cx18_card * already exists\n",
__func__);
return 0;
}
if (snd_cx18_init(v4l2_dev)) {
CX18_ALSA_ERR("%s: failed to create struct snd_cx18_card\n",
__func__);
} else {
CX18_DEBUG_ALSA_INFO("%s: created cx18 ALSA interface instance\n",
__func__);
}
return 0;
}
static int __init cx18_alsa_init(void)
{
printk(KERN_INFO "cx18-alsa: module loading...\n");
cx18_ext_init = &cx18_alsa_load;
return 0;
}
static void __exit snd_cx18_exit(struct snd_cx18_card *cxsc)
{
struct cx18 *cx = to_cx18(cxsc->v4l2_dev);
snd_card_free(cxsc->sc);
cx->alsa = NULL;
}
static int __exit cx18_alsa_exit_callback(struct device *dev, void *data)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(dev);
struct snd_cx18_card *cxsc;
if (v4l2_dev == NULL) {
printk(KERN_ERR "cx18-alsa: %s: struct v4l2_device * is NULL\n",
__func__);
return 0;
}
cxsc = to_snd_cx18_card(v4l2_dev);
if (cxsc == NULL) {
CX18_ALSA_WARN("%s: struct snd_cx18_card * is NULL\n",
__func__);
return 0;
}
snd_cx18_exit(cxsc);
return 0;
}
static void __exit cx18_alsa_exit(void)
{
struct device_driver *drv;
int ret;
printk(KERN_INFO "cx18-alsa: module unloading...\n");
drv = driver_find("cx18", &pci_bus_type);
ret = driver_for_each_device(drv, NULL, NULL, cx18_alsa_exit_callback);
(void)ret;
cx18_ext_init = NULL;
printk(KERN_INFO "cx18-alsa: module unload complete\n");
}
