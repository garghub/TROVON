static void vxpocket_release(struct pcmcia_device *link)
{
pcmcia_disable_device(link);
}
static int snd_vxpocket_dev_free(struct snd_device *device)
{
struct vx_core *chip = device->device_data;
snd_vx_free_firmware(chip);
kfree(chip);
return 0;
}
static int snd_vxpocket_new(struct snd_card *card, int ibl,
struct pcmcia_device *link,
struct snd_vxpocket **chip_ret)
{
struct vx_core *chip;
struct snd_vxpocket *vxp;
static struct snd_device_ops ops = {
.dev_free = snd_vxpocket_dev_free,
};
int err;
chip = snd_vx_create(card, &vxpocket_hw, &snd_vxpocket_ops,
sizeof(struct snd_vxpocket) - sizeof(struct vx_core));
if (!chip)
return -ENOMEM;
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err < 0) {
kfree(chip);
return err;
}
chip->ibl.size = ibl;
vxp = (struct snd_vxpocket *)chip;
vxp->p_dev = link;
link->priv = chip;
link->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
link->resource[0]->end = 16;
link->config_flags |= CONF_ENABLE_IRQ;
link->config_index = 1;
link->config_regs = PRESENT_OPTION;
*chip_ret = vxp;
return 0;
}
static int snd_vxpocket_assign_resources(struct vx_core *chip, int port, int irq)
{
int err;
struct snd_card *card = chip->card;
struct snd_vxpocket *vxp = (struct snd_vxpocket *)chip;
snd_printdd(KERN_DEBUG "vxpocket assign resources: port = 0x%x, irq = %d\n", port, irq);
vxp->port = port;
sprintf(card->shortname, "Digigram %s", card->driver);
sprintf(card->longname, "%s at 0x%x, irq %i",
card->shortname, port, irq);
chip->irq = irq;
if ((err = snd_vx_setup_firmware(chip)) < 0)
return err;
return 0;
}
static int vxpocket_config(struct pcmcia_device *link)
{
struct vx_core *chip = link->priv;
int ret;
snd_printdd(KERN_DEBUG "vxpocket_config called\n");
if (!strcmp(link->prod_id[1], "VX-POCKET")) {
snd_printdd("VX-pocket is detected\n");
} else {
snd_printdd("VX-pocket 440 is detected\n");
chip->hw = &vxp440_hw;
chip->type = vxp440_hw.type;
strcpy(chip->card->driver, vxp440_hw.name);
}
ret = pcmcia_request_io(link);
if (ret)
goto failed;
ret = pcmcia_request_irq(link, snd_vx_irq_handler);
if (ret)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
chip->dev = &link->dev;
snd_card_set_dev(chip->card, chip->dev);
if (snd_vxpocket_assign_resources(chip, link->resource[0]->start,
link->irq) < 0)
goto failed;
return 0;
failed:
pcmcia_disable_device(link);
return -ENODEV;
}
static int vxp_suspend(struct pcmcia_device *link)
{
struct vx_core *chip = link->priv;
snd_printdd(KERN_DEBUG "SUSPEND\n");
if (chip) {
snd_printdd(KERN_DEBUG "snd_vx_suspend calling\n");
snd_vx_suspend(chip);
}
return 0;
}
static int vxp_resume(struct pcmcia_device *link)
{
struct vx_core *chip = link->priv;
snd_printdd(KERN_DEBUG "RESUME\n");
if (pcmcia_dev_present(link)) {
if (chip) {
snd_printdd(KERN_DEBUG "calling snd_vx_resume\n");
snd_vx_resume(chip);
}
}
snd_printdd(KERN_DEBUG "resume done!\n");
return 0;
}
static int vxpocket_probe(struct pcmcia_device *p_dev)
{
struct snd_card *card;
struct snd_vxpocket *vxp;
int i, err;
for (i = 0; i < SNDRV_CARDS; i++) {
if (!(card_alloc & (1 << i)))
break;
}
if (i >= SNDRV_CARDS) {
snd_printk(KERN_ERR "vxpocket: too many cards found\n");
return -EINVAL;
}
if (! enable[i])
return -ENODEV;
err = snd_card_create(index[i], id[i], THIS_MODULE, 0, &card);
if (err < 0) {
snd_printk(KERN_ERR "vxpocket: cannot create a card instance\n");
return err;
}
err = snd_vxpocket_new(card, ibl[i], p_dev, &vxp);
if (err < 0) {
snd_card_free(card);
return err;
}
card->private_data = vxp;
vxp->index = i;
card_alloc |= 1 << i;
vxp->p_dev = p_dev;
return vxpocket_config(p_dev);
}
static void vxpocket_detach(struct pcmcia_device *link)
{
struct snd_vxpocket *vxp;
struct vx_core *chip;
if (! link)
return;
vxp = link->priv;
chip = (struct vx_core *)vxp;
card_alloc &= ~(1 << vxp->index);
chip->chip_status |= VX_STAT_IS_STALE;
snd_card_disconnect(chip->card);
vxpocket_release(link);
snd_card_free_when_closed(chip->card);
}
