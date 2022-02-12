static int snd_card_emu10k1_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct snd_emu10k1 *emu;
#ifdef ENABLE_SYNTH
struct snd_seq_device *wave = NULL;
#endif
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_new(&pci->dev, index[dev], id[dev], THIS_MODULE,
0, &card);
if (err < 0)
return err;
if (max_buffer_size[dev] < 32)
max_buffer_size[dev] = 32;
else if (max_buffer_size[dev] > 1024)
max_buffer_size[dev] = 1024;
if ((err = snd_emu10k1_create(card, pci, extin[dev], extout[dev],
(long)max_buffer_size[dev] * 1024 * 1024,
enable_ir[dev], subsystem[dev],
&emu)) < 0)
goto error;
card->private_data = emu;
emu->delay_pcm_irq = delay_pcm_irq[dev] & 0x1f;
if ((err = snd_emu10k1_pcm(emu, 0, NULL)) < 0)
goto error;
if ((err = snd_emu10k1_pcm_mic(emu, 1, NULL)) < 0)
goto error;
if ((err = snd_emu10k1_pcm_efx(emu, 2, NULL)) < 0)
goto error;
if (emu->card_capabilities->ca0151_chip) {
if ((err = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(pci),
1024, &emu->p16v_buffer)) < 0)
goto error;
}
if ((err = snd_emu10k1_mixer(emu, 0, 3)) < 0)
goto error;
if ((err = snd_emu10k1_timer(emu, 0)) < 0)
goto error;
if ((err = snd_emu10k1_pcm_multi(emu, 3, NULL)) < 0)
goto error;
if (emu->card_capabilities->ca0151_chip) {
if ((err = snd_p16v_pcm(emu, 4, NULL)) < 0)
goto error;
}
if (emu->audigy) {
if ((err = snd_emu10k1_audigy_midi(emu)) < 0)
goto error;
} else {
if ((err = snd_emu10k1_midi(emu)) < 0)
goto error;
}
if ((err = snd_emu10k1_fx8010_new(emu, 0, NULL)) < 0)
goto error;
#ifdef ENABLE_SYNTH
if (snd_seq_device_new(card, 1, SNDRV_SEQ_DEV_ID_EMU10K1_SYNTH,
sizeof(struct snd_emu10k1_synth_arg), &wave) < 0 ||
wave == NULL) {
dev_warn(emu->card->dev,
"can't initialize Emu10k1 wavetable synth\n");
} else {
struct snd_emu10k1_synth_arg *arg;
arg = SNDRV_SEQ_DEVICE_ARGPTR(wave);
strcpy(wave->name, "Emu-10k1 Synth");
arg->hwptr = emu;
arg->index = 1;
arg->seq_ports = seq_ports[dev];
arg->max_voices = max_synth_voices[dev];
}
#endif
strcpy(card->driver, emu->card_capabilities->driver);
strcpy(card->shortname, emu->card_capabilities->name);
snprintf(card->longname, sizeof(card->longname),
"%s (rev.%d, serial:0x%x) at 0x%lx, irq %i",
card->shortname, emu->revision, emu->serial, emu->port, emu->irq);
if ((err = snd_card_register(card)) < 0)
goto error;
pci_set_drvdata(pci, card);
dev++;
return 0;
error:
snd_card_free(card);
return err;
}
static void snd_card_emu10k1_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
static int snd_emu10k1_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct snd_emu10k1 *emu = card->private_data;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
emu->suspend = 1;
snd_pcm_suspend_all(emu->pcm);
snd_pcm_suspend_all(emu->pcm_mic);
snd_pcm_suspend_all(emu->pcm_efx);
snd_pcm_suspend_all(emu->pcm_multi);
snd_pcm_suspend_all(emu->pcm_p16v);
snd_ac97_suspend(emu->ac97);
snd_emu10k1_efx_suspend(emu);
snd_emu10k1_suspend_regs(emu);
if (emu->card_capabilities->ca0151_chip)
snd_p16v_suspend(emu);
snd_emu10k1_done(emu);
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, PCI_D3hot);
return 0;
}
static int snd_emu10k1_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct snd_emu10k1 *emu = card->private_data;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
dev_err(dev, "pci_enable_device failed, disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
snd_emu10k1_resume_init(emu);
snd_emu10k1_efx_resume(emu);
snd_ac97_resume(emu->ac97);
snd_emu10k1_resume_regs(emu);
if (emu->card_capabilities->ca0151_chip)
snd_p16v_resume(emu);
emu->suspend = 0;
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
