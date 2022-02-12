static int snd_adlib_match(struct device *dev, unsigned int n)
{
if (!enable[n])
return 0;
if (port[n] == SNDRV_AUTO_PORT) {
dev_err(dev, "please specify port\n");
return 0;
}
return 1;
}
static void snd_adlib_free(struct snd_card *card)
{
release_and_free_resource(card->private_data);
}
static int snd_adlib_probe(struct device *dev, unsigned int n)
{
struct snd_card *card;
struct snd_opl3 *opl3;
int error;
error = snd_card_new(dev, index[n], id[n], THIS_MODULE, 0, &card);
if (error < 0) {
dev_err(dev, "could not create card\n");
return error;
}
card->private_data = request_region(port[n], 4, CRD_NAME);
if (!card->private_data) {
dev_err(dev, "could not grab ports\n");
error = -EBUSY;
goto out;
}
card->private_free = snd_adlib_free;
strcpy(card->driver, DEV_NAME);
strcpy(card->shortname, CRD_NAME);
sprintf(card->longname, CRD_NAME " at %#lx", port[n]);
error = snd_opl3_create(card, port[n], port[n] + 2, OPL3_HW_AUTO, 1, &opl3);
if (error < 0) {
dev_err(dev, "could not create OPL\n");
goto out;
}
error = snd_opl3_hwdep_new(opl3, 0, 0, NULL);
if (error < 0) {
dev_err(dev, "could not create FM\n");
goto out;
}
error = snd_card_register(card);
if (error < 0) {
dev_err(dev, "could not register card\n");
goto out;
}
dev_set_drvdata(dev, card);
return 0;
out: snd_card_free(card);
return error;
}
static int snd_adlib_remove(struct device *dev, unsigned int n)
{
snd_card_free(dev_get_drvdata(dev));
return 0;
}
