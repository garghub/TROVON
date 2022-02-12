static int __devinit
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
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err)
return err;
if ((reference_rate != 48000) && (reference_rate != 44100)) {
printk(KERN_ERR "ctxfi: Invalid reference_rate value %u!!!\n",
reference_rate);
printk(KERN_ERR "ctxfi: The valid values for reference_rate "
"are 48000 and 44100, Value 48000 is assumed.\n");
reference_rate = 48000;
}
if ((multiple != 1) && (multiple != 2)) {
printk(KERN_ERR "ctxfi: Invalid multiple value %u!!!\n",
multiple);
printk(KERN_ERR "ctxfi: The valid values for multiple are "
"1 and 2, Value 2 is assumed.\n");
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
static void __devexit ct_card_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
static int ct_card_suspend(struct pci_dev *pci, pm_message_t state)
{
struct snd_card *card = pci_get_drvdata(pci);
struct ct_atc *atc = card->private_data;
return atc->suspend(atc, state);
}
static int ct_card_resume(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct ct_atc *atc = card->private_data;
return atc->resume(atc);
}
static int __init ct_card_init(void)
{
return pci_register_driver(&ct_driver);
}
static void __exit ct_card_exit(void)
{
pci_unregister_driver(&ct_driver);
}
