static void snd_cs5535audio_stop_hardware(struct cs5535audio *cs5535au)
{
cs_writel(cs5535au, ACC_CODEC_CNTL, ACC_CODEC_CNTL_LNK_SHUTDOWN);
}
int snd_cs5535audio_suspend(struct pci_dev *pci, pm_message_t state)
{
struct snd_card *card = pci_get_drvdata(pci);
struct cs5535audio *cs5535au = card->private_data;
int i;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(cs5535au->pcm);
snd_ac97_suspend(cs5535au->ac97);
for (i = 0; i < NUM_CS5535AUDIO_DMAS; i++) {
struct cs5535audio_dma *dma = &cs5535au->dmas[i];
if (dma && dma->substream)
dma->saved_prd = dma->ops->read_prd(cs5535au);
}
snd_cs5535audio_stop_hardware(cs5535au);
if (pci_save_state(pci)) {
printk(KERN_ERR "cs5535audio: pci_save_state failed!\n");
return -EIO;
}
pci_disable_device(pci);
pci_set_power_state(pci, pci_choose_state(pci, state));
return 0;
}
int snd_cs5535audio_resume(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct cs5535audio *cs5535au = card->private_data;
u32 tmp;
int timeout;
int i;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "cs5535audio: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
cs_writel(cs5535au, ACC_CODEC_CNTL, ACC_CODEC_CNTL_LNK_WRM_RST);
timeout = 50;
do {
tmp = cs_readl(cs5535au, ACC_CODEC_STATUS);
if (tmp & PRM_RDY_STS)
break;
udelay(1);
} while (--timeout);
if (!timeout)
snd_printk(KERN_ERR "Failure getting AC Link ready\n");
for (i = 0; i < NUM_CS5535AUDIO_DMAS; i++) {
struct cs5535audio_dma *dma = &cs5535au->dmas[i];
if (dma && dma->substream) {
dma->substream->ops->prepare(dma->substream);
dma->ops->setup_prd(cs5535au, dma->saved_prd);
}
}
snd_ac97_resume(cs5535au->ac97);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
