static int
ct_card_probe(struct pci_dev *pci, const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct ct_atc *atc;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_new(&pci->dev, index[dev], id[dev], THIS_MODULE,
0, &card);
if (err)
return err;
if ((reference_rate != 48000) && (reference_rate != 44100)) {
dev_err(card->dev,
"Invalid reference_rate value %u!!!\n",
reference_rate);
dev_err(card->dev,
"The valid values for reference_rate are 48000 and 44100, Value 48000 is assumed.\n");
reference_rate = 48000;
}
if ((multiple != 1) && (multiple != 2) && (multiple != 4)) {
dev_err(card->dev, "Invalid multiple value %u!!!\n",
multiple);
dev_err(card->dev,
"The valid values for multiple are 1, 2 and 4, Value 2 is assumed.\n");
multiple = 2;
}
err = ct_atc_create(card, pci, reference_rate, multiple,
pci_id->driver_data, subsystem[dev], &atc);
if (err < 0)
goto error;
card->private_data = atc;
err = ct_atc_create_alsa_devs(atc);
if (err < 0)
goto error;
strcpy(card->driver, "SB-XFi");
strcpy(card->shortname, "Creative X-Fi");
snprintf(card->longname, sizeof(card->longname), "%s %s %s",
card->shortname, atc->chip_name, atc->model_name);
err = snd_card_register(card);
if (err < 0)
goto error;
pci_set_drvdata(pci, card);
dev++;
return 0;
error:
snd_card_free(card);
return err;
}
static void ct_card_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
static int ct_card_suspend(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct ct_atc *atc = card->private_data;
return atc->suspend(atc);
}
static int ct_card_resume(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct ct_atc *atc = card->private_data;
return atc->resume(atc);
}
