static int __devinit get_xonar_model(struct oxygen *chip,
const struct pci_device_id *id)
{
if (get_xonar_pcm179x_model(chip, id) >= 0)
return 0;
if (get_xonar_cs43xx_model(chip, id) >= 0)
return 0;
if (get_xonar_wm87x6_model(chip, id) >= 0)
return 0;
return -EINVAL;
}
static int __devinit xonar_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
++dev;
return -ENOENT;
}
err = oxygen_pci_probe(pci, index[dev], id[dev], THIS_MODULE,
xonar_ids, get_xonar_model);
if (err >= 0)
++dev;
return err;
}
