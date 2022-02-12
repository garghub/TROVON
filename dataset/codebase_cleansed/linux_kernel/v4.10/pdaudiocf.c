static void pdacf_release(struct pcmcia_device *link)
{
free_irq(link->irq, link->priv);
pcmcia_disable_device(link);
}
static int snd_pdacf_free(struct snd_pdacf *pdacf)
{
struct pcmcia_device *link = pdacf->p_dev;
pdacf_release(link);
card_list[pdacf->index] = NULL;
pdacf->card = NULL;
kfree(pdacf);
return 0;
}
static int snd_pdacf_dev_free(struct snd_device *device)
{
struct snd_pdacf *chip = device->device_data;
return snd_pdacf_free(chip);
}
static int snd_pdacf_probe(struct pcmcia_device *link)
{
int i, err;
struct snd_pdacf *pdacf;
struct snd_card *card;
static struct snd_device_ops ops = {
.dev_free = snd_pdacf_dev_free,
};
snd_printdd(KERN_DEBUG "pdacf_attach called\n");
for (i = 0; i < SNDRV_CARDS; i++) {
if (! card_list[i])
break;
}
if (i >= SNDRV_CARDS) {
snd_printk(KERN_ERR "pdacf: too many cards found\n");
return -EINVAL;
}
if (! enable[i])
return -ENODEV;
err = snd_card_new(&link->dev, index[i], id[i], THIS_MODULE,
0, &card);
if (err < 0) {
snd_printk(KERN_ERR "pdacf: cannot create a card instance\n");
return err;
}
pdacf = snd_pdacf_create(card);
if (!pdacf) {
snd_card_free(card);
return -ENOMEM;
}
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, pdacf, &ops);
if (err < 0) {
kfree(pdacf);
snd_card_free(card);
return err;
}
pdacf->index = i;
card_list[i] = card;
pdacf->p_dev = link;
link->priv = pdacf;
link->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
link->resource[0]->end = 16;
link->config_flags = CONF_ENABLE_IRQ | CONF_ENABLE_PULSE_IRQ;
link->config_index = 1;
link->config_regs = PRESENT_OPTION;
return pdacf_config(link);
}
static int snd_pdacf_assign_resources(struct snd_pdacf *pdacf, int port, int irq)
{
int err;
struct snd_card *card = pdacf->card;
snd_printdd(KERN_DEBUG "pdacf assign resources: port = 0x%x, irq = %d\n", port, irq);
pdacf->port = port;
pdacf->irq = irq;
pdacf->chip_status |= PDAUDIOCF_STAT_IS_CONFIGURED;
err = snd_pdacf_ak4117_create(pdacf);
if (err < 0)
return err;
strcpy(card->driver, "PDAudio-CF");
sprintf(card->shortname, "Core Sound %s", card->driver);
sprintf(card->longname, "%s at 0x%x, irq %i",
card->shortname, port, irq);
err = snd_pdacf_pcm_new(pdacf);
if (err < 0)
return err;
if ((err = snd_card_register(card)) < 0)
return err;
return 0;
}
static void snd_pdacf_detach(struct pcmcia_device *link)
{
struct snd_pdacf *chip = link->priv;
snd_printdd(KERN_DEBUG "pdacf_detach called\n");
if (chip->chip_status & PDAUDIOCF_STAT_IS_CONFIGURED)
snd_pdacf_powerdown(chip);
chip->chip_status |= PDAUDIOCF_STAT_IS_STALE;
snd_card_disconnect(chip->card);
snd_card_free_when_closed(chip->card);
}
static int pdacf_config(struct pcmcia_device *link)
{
struct snd_pdacf *pdacf = link->priv;
int ret;
snd_printdd(KERN_DEBUG "pdacf_config called\n");
link->config_index = 0x5;
link->config_flags |= CONF_ENABLE_IRQ | CONF_ENABLE_PULSE_IRQ;
ret = pcmcia_request_io(link);
if (ret)
goto failed_preirq;
ret = request_threaded_irq(link->irq, pdacf_interrupt,
pdacf_threaded_irq,
IRQF_SHARED, link->devname, link->priv);
if (ret)
goto failed_preirq;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
if (snd_pdacf_assign_resources(pdacf, link->resource[0]->start,
link->irq) < 0)
goto failed;
return 0;
failed:
free_irq(link->irq, link->priv);
failed_preirq:
pcmcia_disable_device(link);
return -ENODEV;
}
static int pdacf_suspend(struct pcmcia_device *link)
{
struct snd_pdacf *chip = link->priv;
snd_printdd(KERN_DEBUG "SUSPEND\n");
if (chip) {
snd_printdd(KERN_DEBUG "snd_pdacf_suspend calling\n");
snd_pdacf_suspend(chip);
}
return 0;
}
static int pdacf_resume(struct pcmcia_device *link)
{
struct snd_pdacf *chip = link->priv;
snd_printdd(KERN_DEBUG "RESUME\n");
if (pcmcia_dev_present(link)) {
if (chip) {
snd_printdd(KERN_DEBUG "calling snd_pdacf_resume\n");
snd_pdacf_resume(chip);
}
}
snd_printdd(KERN_DEBUG "resume done!\n");
return 0;
}
