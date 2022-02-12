static int snd_vx222_free(struct vx_core *chip)
{
struct snd_vx222 *vx = to_vx222(chip);
if (chip->irq >= 0)
free_irq(chip->irq, (void*)chip);
if (vx->port[0])
pci_release_regions(vx->pci);
pci_disable_device(vx->pci);
kfree(chip);
return 0;
}
static int snd_vx222_dev_free(struct snd_device *device)
{
struct vx_core *chip = device->device_data;
return snd_vx222_free(chip);
}
static int snd_vx222_create(struct snd_card *card, struct pci_dev *pci,
struct snd_vx_hardware *hw,
struct snd_vx222 **rchip)
{
struct vx_core *chip;
struct snd_vx222 *vx;
int i, err;
static struct snd_device_ops ops = {
.dev_free = snd_vx222_dev_free,
};
struct snd_vx_ops *vx_ops;
if ((err = pci_enable_device(pci)) < 0)
return err;
pci_set_master(pci);
vx_ops = hw->type == VX_TYPE_BOARD ? &vx222_old_ops : &vx222_ops;
chip = snd_vx_create(card, hw, vx_ops,
sizeof(struct snd_vx222) - sizeof(struct vx_core));
if (! chip) {
pci_disable_device(pci);
return -ENOMEM;
}
vx = to_vx222(chip);
vx->pci = pci;
if ((err = pci_request_regions(pci, CARD_NAME)) < 0) {
snd_vx222_free(chip);
return err;
}
for (i = 0; i < 2; i++)
vx->port[i] = pci_resource_start(pci, i + 1);
if (request_threaded_irq(pci->irq, snd_vx_irq_handler,
snd_vx_threaded_irq_handler, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
dev_err(card->dev, "unable to grab IRQ %d\n", pci->irq);
snd_vx222_free(chip);
return -EBUSY;
}
chip->irq = pci->irq;
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_vx222_free(chip);
return err;
}
*rchip = vx;
return 0;
}
static int snd_vx222_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct snd_vx_hardware *hw;
struct snd_vx222 *vx;
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
switch ((int)pci_id->driver_data) {
case VX_PCI_VX222_OLD:
hw = &vx222_old_hw;
break;
case VX_PCI_VX222_NEW:
default:
if (mic[dev])
hw = &vx222_mic_hw;
else
hw = &vx222_v2_hw;
break;
}
if ((err = snd_vx222_create(card, pci, hw, &vx)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = vx;
vx->core.ibl.size = ibl[dev];
sprintf(card->longname, "%s at 0x%lx & 0x%lx, irq %i",
card->shortname, vx->port[0], vx->port[1], vx->core.irq);
dev_dbg(card->dev, "%s at 0x%lx & 0x%lx, irq %i\n",
card->shortname, vx->port[0], vx->port[1], vx->core.irq);
#ifdef SND_VX_FW_LOADER
vx->core.dev = &pci->dev;
#endif
if ((err = snd_vx_setup_firmware(&vx->core)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void snd_vx222_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
static int snd_vx222_suspend(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct snd_vx222 *vx = card->private_data;
return snd_vx_suspend(&vx->core);
}
static int snd_vx222_resume(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct snd_vx222 *vx = card->private_data;
return snd_vx_resume(&vx->core);
}
