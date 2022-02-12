static int __devinit snd_trident_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct snd_trident *trident;
const char *str;
int err, pcm_dev = 0;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0)
return err;
if ((err = snd_trident_create(card, pci,
pcm_channels[dev],
((pci->vendor << 16) | pci->device) == TRIDENT_DEVICE_ID_SI7018 ? 1 : 2,
wavetable_size[dev],
&trident)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = trident;
switch (trident->device) {
case TRIDENT_DEVICE_ID_DX:
str = "TRID4DWAVEDX";
break;
case TRIDENT_DEVICE_ID_NX:
str = "TRID4DWAVENX";
break;
case TRIDENT_DEVICE_ID_SI7018:
str = "SI7018";
break;
default:
str = "Unknown";
}
strcpy(card->driver, str);
if (trident->device == TRIDENT_DEVICE_ID_SI7018) {
strcpy(card->shortname, "SiS ");
} else {
strcpy(card->shortname, "Trident ");
}
strcat(card->shortname, card->driver);
sprintf(card->longname, "%s PCI Audio at 0x%lx, irq %d",
card->shortname, trident->port, trident->irq);
if ((err = snd_trident_pcm(trident, pcm_dev++, NULL)) < 0) {
snd_card_free(card);
return err;
}
switch (trident->device) {
case TRIDENT_DEVICE_ID_DX:
case TRIDENT_DEVICE_ID_NX:
if ((err = snd_trident_foldback_pcm(trident, pcm_dev++, NULL)) < 0) {
snd_card_free(card);
return err;
}
break;
}
if (trident->device == TRIDENT_DEVICE_ID_NX || trident->device == TRIDENT_DEVICE_ID_SI7018) {
if ((err = snd_trident_spdif_pcm(trident, pcm_dev++, NULL)) < 0) {
snd_card_free(card);
return err;
}
}
if (trident->device != TRIDENT_DEVICE_ID_SI7018 &&
(err = snd_mpu401_uart_new(card, 0, MPU401_HW_TRID4DWAVE,
trident->midi_port,
MPU401_INFO_INTEGRATED |
MPU401_INFO_IRQ_HOOK,
-1, &trident->rmidi)) < 0) {
snd_card_free(card);
return err;
}
snd_trident_create_gameport(trident);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void __devexit snd_trident_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
static int __init alsa_card_trident_init(void)
{
return pci_register_driver(&driver);
}
static void __exit alsa_card_trident_exit(void)
{
pci_unregister_driver(&driver);
}
