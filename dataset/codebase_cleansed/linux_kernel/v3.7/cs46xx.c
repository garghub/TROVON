static int __devinit snd_card_cs46xx_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct snd_cs46xx *chip;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0)
return err;
if ((err = snd_cs46xx_create(card, pci,
external_amp[dev], thinkpad[dev],
&chip)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = chip;
chip->accept_valid = mmap_valid[dev];
if ((err = snd_cs46xx_pcm(chip, 0, NULL)) < 0) {
snd_card_free(card);
return err;
}
#ifdef CONFIG_SND_CS46XX_NEW_DSP
if ((err = snd_cs46xx_pcm_rear(chip,1, NULL)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_cs46xx_pcm_iec958(chip,2,NULL)) < 0) {
snd_card_free(card);
return err;
}
#endif
if ((err = snd_cs46xx_mixer(chip, 2)) < 0) {
snd_card_free(card);
return err;
}
#ifdef CONFIG_SND_CS46XX_NEW_DSP
if (chip->nr_ac97_codecs ==2) {
if ((err = snd_cs46xx_pcm_center_lfe(chip,3,NULL)) < 0) {
snd_card_free(card);
return err;
}
}
#endif
if ((err = snd_cs46xx_midi(chip, 0, NULL)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_cs46xx_start_dsp(chip)) < 0) {
snd_card_free(card);
return err;
}
snd_cs46xx_gameport(chip);
strcpy(card->driver, "CS46xx");
strcpy(card->shortname, "Sound Fusion CS46xx");
sprintf(card->longname, "%s at 0x%lx/0x%lx, irq %i",
card->shortname,
chip->ba0_addr,
chip->ba1_addr,
chip->irq);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void __devexit snd_card_cs46xx_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
