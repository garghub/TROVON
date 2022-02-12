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
int error;
error = snd_card_new(dev, index[n], id[n], THIS_MODULE, 0, &card);
if (error < 0)
return error;
error = snd_wss_create(card, port[n], -1, irq[n], dma1[n], dma2[n],
WSS_HW_DETECT, 0, &chip);
if (error < 0)
goto out;
card->private_data = chip;
error = snd_wss_pcm(chip, 0);
if (error < 0)
goto out;
strlcpy(card->driver, "CS4231", sizeof(card->driver));
strlcpy(card->shortname, chip->pcm->name, sizeof(card->shortname));
if (dma2[n] < 0)
snprintf(card->longname, sizeof(card->longname),
"%s at 0x%lx, irq %d, dma %d",
chip->pcm->name, chip->port, irq[n], dma1[n]);
else
snprintf(card->longname, sizeof(card->longname),
"%s at 0x%lx, irq %d, dma %d&%d",
chip->pcm->name, chip->port, irq[n], dma1[n], dma2[n]);
error = snd_wss_mixer(chip);
if (error < 0)
goto out;
error = snd_wss_timer(chip, 0);
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
