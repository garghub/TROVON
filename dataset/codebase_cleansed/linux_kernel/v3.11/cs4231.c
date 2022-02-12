static int snd_cs4231_match(struct device *dev, unsigned int n)
{
if (!enable[n])
return 0;
if (port[n] == SNDRV_AUTO_PORT) {
dev_err(dev, "please specify port\n");
return 0;
}
if (irq[n] == SNDRV_AUTO_IRQ) {
dev_err(dev, "please specify irq\n");
return 0;
}
if (dma1[n] == SNDRV_AUTO_DMA) {
dev_err(dev, "please specify dma1\n");
return 0;
}
return 1;
}
static int snd_cs4231_probe(struct device *dev, unsigned int n)
{
struct snd_card *card;
struct snd_wss *chip;
struct snd_pcm *pcm;
int error;
error = snd_card_create(index[n], id[n], THIS_MODULE, 0, &card);
if (error < 0)
return error;
error = snd_wss_create(card, port[n], -1, irq[n], dma1[n], dma2[n],
WSS_HW_DETECT, 0, &chip);
if (error < 0)
goto out;
card->private_data = chip;
error = snd_wss_pcm(chip, 0, &pcm);
if (error < 0)
goto out;
strcpy(card->driver, "CS4231");
strcpy(card->shortname, pcm->name);
sprintf(card->longname, "%s at 0x%lx, irq %d, dma %d",
pcm->name, chip->port, irq[n], dma1[n]);
if (dma2[n] >= 0)
sprintf(card->longname + strlen(card->longname), "&%d", dma2[n]);
error = snd_wss_mixer(chip);
if (error < 0)
goto out;
error = snd_wss_timer(chip, 0, NULL);
if (error < 0)
goto out;
if (mpu_port[n] > 0 && mpu_port[n] != SNDRV_AUTO_PORT) {
if (mpu_irq[n] == SNDRV_AUTO_IRQ)
mpu_irq[n] = -1;
if (snd_mpu401_uart_new(card, 0, MPU401_HW_CS4232,
mpu_port[n], 0, mpu_irq[n],
NULL) < 0)
dev_warn(dev, "MPU401 not detected\n");
}
snd_card_set_dev(card, dev);
error = snd_card_register(card);
if (error < 0)
goto out;
dev_set_drvdata(dev, card);
return 0;
out: snd_card_free(card);
return error;
}
static int snd_cs4231_remove(struct device *dev, unsigned int n)
{
snd_card_free(dev_get_drvdata(dev));
return 0;
}
static int snd_cs4231_suspend(struct device *dev, unsigned int n, pm_message_t state)
{
struct snd_card *card = dev_get_drvdata(dev);
struct snd_wss *chip = card->private_data;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
chip->suspend(chip);
return 0;
}
static int snd_cs4231_resume(struct device *dev, unsigned int n)
{
struct snd_card *card = dev_get_drvdata(dev);
struct snd_wss *chip = card->private_data;
chip->resume(chip);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int __init alsa_card_cs4231_init(void)
{
return isa_register_driver(&snd_cs4231_driver, SNDRV_CARDS);
}
static void __exit alsa_card_cs4231_exit(void)
{
isa_unregister_driver(&snd_cs4231_driver);
}
